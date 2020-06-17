/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Graph.h
 * Author: PrinceChaos
 *
 * Created on 16. Juni 2020, 15:39
 */

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include "Node.h"
#include "Maze.h"

/**
 * @class Graph
 * @brief A set of nodes. A graph can be constructed from a Maze.
 * Adjacency between nodes is based on coordinates (method in Node).
 */
class Graph {
    
    // Overloaded operators
    friend std::ostream& operator<<(std::ostream& os, const Graph graph);
    
private:
    Node* nodes;
    int numNodes;
    
    /**
     * @brief Free the allocated heap memory
     */
    void freeSpace();
    
    /**
     * @brief Allocate array of Nodes in the heap
     * @param amount Size of the array
     * @return Pointer to the array.
     */
    Node* allocateSpace(int amount);
    
    
public:
    /**
     * @brief Basic constructor
     */
    Graph();
    
    /**
     * @brief Copy constructor
     * @param orig model
     */
    Graph(const Graph& orig);
    
    /**
     * @brief Destructor
     */
    ~Graph();
    
    /**
     * @brief return number of nodes in the graph
     * @return 
     */
    int getNumNodes() const;
    
    /**
     * @brief Get a reference to the node at @p index
     * @param index
     * @return 
     */
    Node& getNode(int index);
    
    /**
     * @brief Get constant reference (for constant graph objects)
     * @param index
     * @return 
     */
    const Node& getNode(int index) const;
    
    /**
     * @brief Adds a node to the graph
     * @param node
     */
    void addNode(const Node& node);
    
    /**
     * @brief += operator to add a node at the end of the list
     * @param node
     * @return 
     */
    const Graph& operator+=(const Node& node);
    
    /**
     * @brief Assignment operator
     * @param model
     * @return 
     */
    const Graph& operator=(const Graph& model);
    
    /**
     * @brief Generate a graph from the non-obstructed nodes in a maze. 
     * @param maze
     */
    Graph(const Maze& maze);
    
    /**
     * @brief Get a reference to a node given its coordinates in the maze.
     * @param r
     * @param c
     * @return Reference, or null.
     */
    Node* getNodePtrFromCoords(int r, int c);
    
    /**
     * @brief Whether every single node on the graph is definitely shortest distance.
     * @return 
     */
    bool everythingDefinite();
    
    /**
     * @brief Get node with shortest distance to origin without already being a 
     * definite (visited and guaranteed shortest path) node.
     * @return Pointer to the node in the graph. Null if there is no unvisited node.
     */
    Node* getNearestNonDefinite();


};

#endif /* GRAPH_H */

