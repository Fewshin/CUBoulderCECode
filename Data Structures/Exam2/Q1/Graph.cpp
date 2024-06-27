#include "Graph.hpp"
#include <vector>
#include <iostream>
using namespace std;

/*
 * adds a vertex to the graph
 */
void Graph::addVertex(int n){
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i]->key == n){
            found = true;
        }
    }
    if(found == false){
        vertex * v = new vertex;
        v->key = n;
        vertices.push_back(v);
    }
}

/*
 * adds an edge between two vertices (directed graph)
 */
void Graph::addEdge(int src, int dest){
    for(int i = 0; i < vertices.size(); i++) {
        if(vertices[i]->key == src) {
            for(int j = 0; j < vertices.size(); j++) {
                if(vertices[j]->key == dest && i != j) {
                    adjVertex av;
                    av.v = vertices[j];
                    vertices[i]->adj.push_back(av);
                }
            }
        }
    }
}

void recursiveTravel (vertex *vert) {
  vert->visited = true; //We have visited this vertex. Marking it.
  for (int i = 0; i < vert->adj.size(); i++) { //Addressing all adjecent vertices.
    if (vert->adj[i].v->visited == false) { //Checking to see if an adjacent vertex hasn't already been visited.
      //vert->adj[i].v->visited = true;
      recursiveTravel(vert->adj[i].v);//Since it hasn't veen visited yet let's visit it.
    }
  }
}

/*
 * Complete the following function which checks if vert is a boss vertex
 */
bool Graph::isVertexABoss(vertex *vert) {
  recursiveTravel(vert);//Helper function for traversing the graph.
  for (int i = 0; i < vertices.size(); i++) { //Checking if every vertex has been visited by my traversal.
    if (vertices[i]->visited == false) { //If a hasn't been visited we need to say the vertex isn't a boss.
      for (int j = 0; j < vertices.size(); j++) { //...after we reset the graph so we can traverse it more
        vertices[j]->visited = false;
      }
      return false;//Not a boss
    }
  }
  for (int j = 0; j < vertices.size(); j++) { //Resetting the graph.
    vertices[j]->visited = false;
  }
  return true;//If it made it this far it's probably a boss
}

/*
 * Complete the following function which checks if the graph is a Boss
 */
bool Graph::isGraphABoss() {
  for (int i = 0; i < vertices.size(); i++) { //It's a boss if any vertex is a boss, let's check every single one.
    if (isVertexABoss(vertices[i])) {
      //printf("Vertex %d is a boss: %d\n", vertices[i]->key, isVertexABoss(vertices[i]));
      return true;
    }
  }
  return false;//No vertex was a boss so the graph isn't a boss
}
