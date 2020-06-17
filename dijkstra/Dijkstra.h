/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Dijkstra.h
 * Author: PrinceChaos
 *
 * Created on 16. Juni 2020, 17:17
 */

#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <assert.h>
#include "Graph.h"

class Dijkstra {
    
private:
    Graph graph; // The graph on which the algorithm operates (and which it modifies)
    Node* startingNode; // The nearest distance and paths on the graph are calculated based on where the path starts
    
    
public:
    /**
     *@brief Basic constructor: everything to 0
     */
    Dijkstra();
    
    /**
     * @brief Directly initialize with the given graph.
     * @param g
     */
    Dijkstra(const Graph& g);
    
    /**
     * @brief Load the graph on which to work into the object
     * @param g Graph to copy
     */
    void setGraph(const Graph& g);
    
    
    /**
     * @brief Getter to access the algorithm's working graph
     * @return 
     */
    const Graph& getGraph() const;
    
    /**
     * @brief Give the algorithm a point from which to get the distance to the other nodes
     * @param r
     * @param c
     * @return @retval true if the starting point was found 
     *         @retval false if the starting point isn't one of the nodes.
     */
    bool setStartingPoint(int r, int c);
    
    /**
     * @brief Return pointer to starting point
     * @return 
     */
    Node* getStartingPoint();
    
    
    /**
     * @brief Execute the algorithm to find distances to every node from the starting node.
     *        Depends on the starting point, but works for any end point.
     */
    void doAlgorithm();
    
    /**
     * @brief Return a path to the given coordinates. If there isn't one, return empty path.
     * @param r
     * @param c
     * @return Path to destination, or empty path if there isn't one.
     */
    Path getPathTo(int rDest, int cDest);
    
    /**
     * @brief Total distance to a node from the starting point
     * @param rDest
     * @param cDest
     * @return 
     */
    int getDistanceTo(int rDest, int cDest);
    
    
    
    
    


};

#endif /* DIJKSTRA_H */

