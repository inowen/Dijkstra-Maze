/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PathPoint.cpp
 * Author: PrinceChaos
 * 
 * Created on 17. Juni 2020, 10:05
 */

#include "PathPoint.h"


// Public methods

PathPoint::PathPoint(): row(0), column(0) {}

PathPoint::PathPoint(int row, int col) {
    this->row = row;
    this->column = col;
}

PathPoint::PathPoint(const Node& node) {
    this->row = node.getCoordR();
    this->column = node.getCoordC();
}

int PathPoint::getCol() const {
    return this->column;
}

int PathPoint::getRow() const {
    return this->row;
}

void PathPoint::setCol(int col) {
    column = col;
}

void PathPoint::setRow(int row) {
    this->row = row;
}






// Operator overload
std::ostream& operator<<(std::ostream& os, const PathPoint& pp) {
    
    os << "Row: " << pp.getRow() << " Col: " << pp.getCol();
    
    return os;
}