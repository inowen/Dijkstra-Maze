/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PathPoint.h
 * Author: PrinceChaos
 *
 * Created on 17. Juni 2020, 10:05
 */

#ifndef PATHPOINT_H
#define PATHPOINT_ 

#include <iostream>
#include "Node.h"

class PathPoint {
    
    friend std::ostream& operator<<(std::ostream& os, const PathPoint& pp);
    
private:
    int row, column;
    
public:
    /**
     * @brief Basic constructor
     */
    PathPoint();
    
    /**
     * @brief Constructor from coordinates
     * @param row
     * @param col
     */
    PathPoint(int row, int col);
    
    /**
     * @brief Create pathpoints with coordinates of a given node.
     * @param node
     */
    PathPoint(const Node& node);
    
    /**
     * @brief Getter for row
     * @return 
     */
    int getRow() const;
    
    /**
     * @brief Getter for column
     * @return 
     */
    int getCol() const;
    
    /**
     * @brief Setter for row
     */
    void setRow(int);
    
    /**
     * @brief Setter for column
     */
    void setCol(int);
    
    
    
};

#endif /* PATHPOINT_H */

