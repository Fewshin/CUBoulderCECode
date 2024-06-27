// Copy your Graph::addVertex method into the box below, with the provided prototype. You may use any helper functions as needed, but they must be copied into the answer box.


// You may assume that ALL other class methods are defined, correct, and available for you to call.

// Your answer should look like:

// void Graph::addVertex(std::string name)
// {
//     // Your code here
// }

void Graph::addVertex(string name) {
  vertex *temp = new vertex;
  temp->name = name;
  vertices.push_back(temp);
}

// Copy your Graph::addEdge method into the box below, with the provided prototype. You may use any helper functions as needed, but they must be copied into the answer box.


// You may assume that ALL other class methods are defined, correct, and available for you to call.

// Your answer should look like:

// void Graph::addEdge(std::string v1, std::string v2)
// {
//     // Your code here
// }

void Graph::addEdge(string v1, string v2) {
  if (v1 == v2) {
    printf("Cannot connect vertex to itself.");
    return;
  }
  int size = vertices.size();
  vertex * p1 = new vertex;
  p1 = NULL;
  vertex * p2 = new vertex;
  p2 = NULL;
  for (int i = 0; i < size; i++) {
    if (vertices[i]->name == v1) {
      p1 = vertices[i];
    }
    if (vertices[i]->name == v2) {
      p2 = vertices[i];
    }
  }
  if (p1 == NULL) {
    printf("Vertex 1 wasn't found.\n");
    return;
  }
  if (p2 == NULL) {
    printf("Vertex 2 wasn't found.\n");
    return;
  }
  adjVertex * a1 = new adjVertex;
  adjVertex * a2 = new adjVertex;
  a1->v = p1;
  a2->v = p2;
  p1->adj.push_back(*a2);
  p2->adj.push_back(*a1);
}

// Copy your Graph::displayEdges() method into the box below, with the provided prototype. You may use any helper functions as needed, but they must be copied into the answer box.


// You may assume that ALL other class methods are defined, correct, and available for you to call.

// Your answer should look like:

// void Graph::displayEdges()
// {
//     // Your code here
// }

void Graph::displayEdges() {
  int size = vertices.size();
  for (int i = 0; i < size; i++) {
    int aSize = vertices[i]->adj.size();
    printf("%s -->", vertices[i]->name.c_str());
    for (int j = 0; j < aSize; j++) {
      printf(" %s", vertices[i]->adj[j].v->name.c_str());
    }
    printf("\n");
  }
}

// Copy your void Graph::breadthFirstTraverse(string sourceVertex) method into the box below, with the provided prototype. You may use any helper functions as needed, but they must be copied into the answer box.


// You may assume that ALL other class methods are defined, correct, and available for you to call.

// Your answer should look like:

// void Graph::breadthFirstTraverse(string sourceVertex)
// {
//     // Your code here
// }

void recursiveCheck (vertex * input, int depth) {
  int size = input->adj.size();
  int count = 0;
  for (int i = 0; i < size; i++) {
    if (input->adj[i].v->visited == false) {
      input->adj[i].v->visited = true;
      count++;
      printf(" %s(%d)", input->adj[i].v->name.c_str(), depth);
    }
  }
  if (count > 0) {
    for (int i = 0; i < size; i++) {
      recursiveCheck(input->adj[i].v, depth + 1);
    }
  }
  else return;
}

void Graph::breadthFirstTraverse(string sourceVertex) {
  int size = vertices.size();
  vertex * temp = new vertex;
  temp = NULL;
  for (int i = 0; i < size; i++) {
    if (vertices[i]->name == sourceVertex) {
      temp = vertices[i];
    }
  }
  if (temp == NULL) {
    printf("Vertex not found.\n");
    return;
  }
  temp->visited = true;
  printf("Starting vertex (root): %s->", temp->name.c_str());
  recursiveCheck(temp, 1);
  printf("\n");
}