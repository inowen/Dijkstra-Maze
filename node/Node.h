/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.h
 * Author: PrinceChaos
 *
 * Created on 16. Juni 2020, 13:01
 */

#ifndef NODE_H
#define NODE_H

#define INF 999999

#include <cmath>
#include <iostream>
#include <assert.h>


class Node {
    
    // Overloaded operators
    friend std::ostream& operator<<(std::ostream& os, const Node& node);
    
private:
   
    double distanceToOrigin;
    Node* parent;
    bool isDefiniteValue;
    int coordR;
    int coordC;
    
    
public:
    
    /**
     * @brief Basic constructor
     */
    Node();
    
    /**
     * @brief Initialize from its coordinates. Distance to infinity.
     * @param x
     * @param y
     */
    Node(int r, int c);
    
    // Getters
    double getDistanceToOrigin() const { return distanceToOrigin; }
    Node* getParent() { return parent; }
    bool isDefinite() const { return isDefiniteValue; }
    int getCoordR() const { return coordR; }
    int getCoordC() const { return coordC; }
    
    // Setters
    void setDistanceToOrigin(double distance) { distanceToOrigin = distance; }
    void setParent(Node* p) { parent = p; }
    bool setDefinite() { isDefiniteValue = true; }
    bool setNotDefinite() { isDefiniteValue = false; }
    
    void setCoords(int r, int c) { coordR = r; coordC = c; }
    
    /**
     * @brief Whether the node has @p other next to it (diagonally counts)
     * @param other node
     * @return 
     */
    bool adjacentTo(const Node& other);
    
    /**
     * @brief Overload == to check if the coordinates of two nodes in the maze are the same
     * @param other
     * @return 
     */
    bool operator==(const Node& other);
    
    
    

};

#endif /* NODE_H */

