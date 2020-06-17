/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.cpp
 * Author: PrinceChaos
 * 
 * Created on 16. Juni 2020, 13:01
 */

#include "Node.h"



// Public methods

Node::Node(): coordR(0), coordC(0), distanceToOrigin(INF), parent(0), isDefiniteValue(false) {}

Node::Node(int r, int c): coordR(r), coordC(c), distanceToOrigin(INF), parent(0), isDefiniteValue(false) {}

bool Node::adjacentTo(const Node& other) {
    bool verticallyClose = (abs(coordR-other.coordR) == 0 || abs(coordR-other.coordR) == 1);
    bool horizontallyClose = (abs(coordC-other.coordC) == 0 || abs(coordC-other.coordC) == 1);
    
    return (horizontallyClose && verticallyClose);
}







// Private methods







// Operator overload

std::ostream& operator<<(std::ostream& os, const Node& node) {
    
    os << "(" << node.coordR << "," << node.coordC << ") DTO:" 
       << node.distanceToOrigin << " Definite? " << (node.isDefiniteValue ? "Y" : "N") << " -- Parent:";
    
    if (node.parent != 0)
       os << " (" << node.parent->coordR << "," << node.parent->coordC << ")";
    else
        os << " NULL";
    
    return os;
}

bool Node::operator ==(const Node& other) {
    return (coordR==other.coordR && coordC==other.coordC);
}