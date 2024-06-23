#include "Graph.hpp"
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

void Graph::addEdge(string source, string target){
    for(unsigned int i = 0; i < vertices.size(); i++){
        if(vertices[i]->name == source){
            for(unsigned int j = 0; j < vertices.size(); j++){
                if(vertices[j]->name == target && i != j){
                    adjVertex av;
                    av.v = vertices[j];
                    vertices[i]->adj.push_back(av);
                }
            }
        }
    }
}

void Graph::addVertex(string vName){
    bool found = false;
    for(unsigned int i = 0; i < vertices.size(); i++){
        if(vertices[i]->name == vName){
            found = true;
            cout<<vertices[i]->name<<" found."<<endl;
        }
    }
    if(found == false){
        vertex * v = new vertex;
        v->name = vName;
        v->distance = 0;
        vertices.push_back(v);
    }
}

void Graph::displayEdges(){
    for(unsigned int i = 0; i < vertices.size(); i++){
        cout<<vertices[i]->name<<":"<<endl;
        for(unsigned int j = 0; j < vertices[i]->adj.size(); j++){
            cout<<" --> "<< vertices[i]->adj[j].v->name <<endl;
        }
        cout<<endl;
    }
}

int recursiveSearch (vertex * input) {
  input->visited = true;
  for (int i = 0; i < (int) input->adj.size(); i++) {
    if (input->adj[i].v->visited == false) recursiveSearch(input->adj[i].v);
    //Without the above if statement, you might find if a graph is strongly connected if you get a segmentation fault.
  }
  //I just realized I could do the adj check in here.
  return 0;
}

bool Graph::isStronglyConnected(){
    /* 
    Implement this function. 
    This function returns true if the graph is strongly connected. Otherwise, returns false.
    */
  //No two tab spaces >:(
  if ((int) vertices.size() <= 1) return 1;
  //Above is for if there are no nodes or only one node. In these cases the graph is strongly connected.
  //Saves some processing power and enables me to use the methods employed below. 
  int count = 0;
  for (int i = 0; i < (int) vertices.size(); i++) {
    if ((int) vertices[i]->adj.size() == 0) {
      count++;
    }
  }
  if (count > 0) return 0;
  //Above I checked to see if there are nodes with no outbound connection
  //This is because if there's a node that you can travel to but not leave, it's not strongly connected.
  recursiveSearch(vertices[0]);
  //Above in recursive search, I am visiting every node I can visit from the first node.
  for (int i = 0; i < (int) vertices.size(); i++) {
    if (vertices[i]->visited == false) {
      count++;
    }
  }
  //Above I am checking if every node was visited. 
  /*The logic is that if I am able to visit every node from one node and every node has an inbound and outbound connection of some sort
  that means that every node is connected strongly. I cannot imagine a scenario where this isn't the case.*/
  if (count > 0) return 0;
  else return 1;
}