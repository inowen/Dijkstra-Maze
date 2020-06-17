/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Dijkstra.cpp
 * Author: PrinceChaos
 * 
 * Created on 16. Juni 2020, 17:17
 */

#include "Dijkstra.h"

// Public methods
Dijkstra::Dijkstra(): startingNode(0) {}

Dijkstra::Dijkstra(const Graph& g): startingNode(0) {
    setGraph(g);
}

void Dijkstra::setGraph(const Graph& g) { graph = g; }

bool Dijkstra::setStartingPoint(int r, int c) {
    startingNode = graph.getNodePtrFromCoords(r, c);
    return (startingNode != 0);
}

void Dijkstra::doAlgorithm() {
    
    assert(startingNode != 0);
    
    // Set values for starting node.
    startingNode->setDistanceToOrigin(0);
    Node* currentNode = 0;
    
    // Loop through the algorithm: 
    // 0. Find nearest non-visited node and select that one (visit it). That's the shortest path to that node. Set definite.
    // 1. The parent node of that one is the previous node.
    // 2. Calculate distance to every node that this one's connected to and update if smaller.
    //     Update: 2.1 Set the distance to the new distance.
    //             2.2 Set the current parent node to be the previous node if updated distance.
    // END CONDITION: Every node is definitely shortest path (visited through shortest path from origin).
    
    currentNode = graph.getNearestNonDefinite();
    if (currentNode != 0) {
        currentNode->setParent(startingNode);
    }
    
    while(currentNode != 0) {
        
        currentNode->setDefinite();
        
        // Update distances to all the other nodes in the graph
        for (int node=0; node<graph.getNumNodes(); node++) {
            if (currentNode->adjacentTo(graph.getNode(node)) && !graph.getNode(node).isDefinite()) {
                
                double distanceThroughCurrentNode = currentNode->getDistanceToOrigin() + 1;
                
                bool shouldUpdate = (distanceThroughCurrentNode<graph.getNode(node).getDistanceToOrigin());
                if (shouldUpdate) {
                    graph.getNode(node).setDistanceToOrigin(distanceThroughCurrentNode);
                    graph.getNode(node).setParent(currentNode);
                }
            }
        }
        
        // Find next node to visit (or not, then it stops).
        currentNode = graph.getNearestNonDefinite();
        
    }
}

const Graph& Dijkstra::getGraph() const {
    return graph;
}

int Dijkstra::getDistanceTo(int rDest, int cDest) {
    return graph.getNodePtrFromCoords(rDest, cDest)->getDistanceToOrigin();
}

Path Dijkstra::getPathTo(int rDest, int cDest) {
    
    // If The node doesn't exist in the graph, throw exception
    if (graph.getNodePtrFromCoords(rDest, cDest) == 0) {
        throw std::invalid_argument("getPathTo(rDest, cDest): node isn't in the graph.");
    }
    
    // Empty path if there is no way to get to destination.
    if (graph.getNodePtrFromCoords(rDest, cDest)->getDistanceToOrigin() >= INF) {
        return Path();
    }
    
    // Knowing that the path exists and there is a way to get there, reconstruct the path.
    Path shortestPath;
    
    Node* currentNode = graph.getNodePtrFromCoords(rDest, cDest)->getParent();
    
    while(currentNode != startingNode) {
        shortestPath.add(PathPoint(*currentNode));
        currentNode = currentNode->getParent();
    }
    
    return shortestPath;
}

Node* Dijkstra::getStartingPoint() {
    return startingNode;
}





// Private methods







// Operator overloading