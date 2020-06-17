/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Graph.cpp
 * Author: PrinceChaos
 * 
 * Created on 16. Juni 2020, 15:39
 */

#include "Graph.h"


// Public methods

Graph::Graph(): nodes(0), numNodes(0) {}

Graph::Graph(const Graph& orig): numNodes(orig.numNodes) {
    nodes = allocateSpace(numNodes);
    
    // Copy the data over from the model
    for (int i=0; i<numNodes; i++) {
        nodes[i] = orig.nodes[i];
    }
}

Graph::~Graph() {
    freeSpace();
}

const Node& Graph::getNode(int index) const {
    return nodes[index];
}

Node& Graph::getNode(int index) {
    return nodes[index];
}


void Graph::addNode(const Node& node) {
    Node* newNodes = new Node[numNodes+1];
    
    // Copy previous data to new nodes list
    for (int i=0; i<numNodes; i++) {
        newNodes[i] = nodes[i];
    }
    
    // Add the last node
    newNodes[numNodes] = node;
    numNodes++;
    
    // Swap lists
    delete [] nodes;
    nodes = newNodes;
}

Graph::Graph(const Maze& maze) {
    
    // Count the amount of nodes in the graph
    int nodeCount = 0;
    for (int r=0; r<maze.getNumRows(); r++) {
        for (int c=0; c<maze.getNumColumns(); c++) {
            if (maze.get(r,c) != OBSTRUCTED) {
                nodeCount++;
            }
        }
    }
    
    // Create the graph to contain the nodes
    numNodes = nodeCount;
    nodes = allocateSpace(numNodes);
    
    // Add the nodes
    int writePos = 0;
    
    for (int r=0; r<maze.getNumRows(); r++) {
        for (int c=0; c<maze.getNumColumns(); c++) {
            
            if (maze.get(r,c) != OBSTRUCTED) {
                nodes[writePos] = Node(r,c);
                writePos++;
            }
        }
    }
}

int Graph::getNumNodes() const {
    return numNodes;
}

Node* Graph::getNodePtrFromCoords(int r, int c) {
    Node* the_node = 0;
    
    for (int i=0; i<numNodes && the_node==0; i++) {
        if (r==nodes[i].getCoordR() && c==nodes[i].getCoordC()) {
            the_node = &nodes[i];
        }
    }
    
    return the_node;
}

bool Graph::everythingDefinite() {
    bool allDefinite = true;
    
    for (int i=0; i<numNodes && allDefinite; i++) {
        if (!nodes[i].isDefinite()) {
            allDefinite = false;
        }
    }
    
    return allDefinite;
}

Node* Graph::getNearestNonDefinite() {
 
    Node* result = nullptr;
    double minDistance = INF;
    
    // Loop through the nodes finding the shortest distance.
    for (int node=0; node<numNodes; node++) {
        if (nodes[node].getDistanceToOrigin()<minDistance && !nodes[node].isDefinite()) {
            result = &nodes[node];
            minDistance = nodes[node].getDistanceToOrigin();
        }
    }
    
    return result;
}







// Private methods

void Graph::freeSpace() {
    if (nodes != 0)
        delete [] nodes;
    nodes = 0;
    numNodes = 0;
}

Node* Graph::allocateSpace(int amount) {
    return new Node[amount];
}









// Overloaded operators

const Graph& Graph::operator +=(const Node& node) {
    addNode(node);
    return *this;
}

const Graph& Graph::operator =(const Graph& model) {
    if (this != &model) {
        
        freeSpace();
        numNodes = model.numNodes;
        nodes = allocateSpace(numNodes);
        
        for (int i=0; i<numNodes; i++) {
            nodes[i] = model.nodes[i];
        }
    }
    
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Graph graph) {
    
    for (int i=0; i<graph.numNodes; i++)
        os << graph.nodes[i] << std::endl;
    
    return os;
}



