/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Path.cpp
 * Author: PrinceChaos
 * 
 * Created on 17. Juni 2020, 10:12
 */

#include <assert.h>
#include <stdexcept>
#include "Path.h"



// Public methods

Path::Path():numPathpoints(0), pathpoints(0) {}

Path::Path(const Path& orig): numPathpoints(orig.numPathpoints) {
    pathpoints = allocateMemory(numPathpoints);
    
    // Copy data
    for (int i=0; i<numPathpoints; i++) {
        pathpoints[i] = orig.pathpoints[i];
    }
}

Path::~Path() {
    deallocate();
}

const PathPoint& Path::get(int index) const {
    if (index>=numPathpoints) {
        throw std::out_of_range("Path::get(index): index out of range");
    }
    return pathpoints[index];
}

PathPoint& Path::get(int index) {
    if (index>=numPathpoints) {
        throw std::out_of_range("Path::get(index): index out of range");
    }
    return pathpoints[index];
}

void Path::set(int index, const PathPoint& p) {
    if (index>=numPathpoints) {
        throw std::out_of_range("Path::set OOR index.");
    }
    
    pathpoints[index] = p;
}

void Path::set(int index, int valueX, int valueY) {
    if (index>=numPathpoints) {
        throw std::out_of_range("Path::set OOR index.");
    }
    
    pathpoints[index] = PathPoint(valueX, valueY);
}

void Path::add(const PathPoint& newp) {
    
    // Make space for the new PathPoint
    PathPoint* newPathpoints = allocateMemory(numPathpoints+1);
    
    // Copy data from pathpoints
    for (int i=0; i<numPathpoints; i++) {
        newPathpoints[i] = pathpoints[i];
    }
    
    // Add new pathpoint
    newPathpoints[numPathpoints] = newp;
    numPathpoints++;
    
    // Switch out vectors;
    delete [] pathpoints;
    pathpoints = newPathpoints;
}

const Path& Path::operator=(const Path& model) {
    
    if (this != &model) {
        deallocate();
        
        numPathpoints = model.numPathpoints;
        pathpoints = allocateMemory(model.numPathpoints);
        
        for (int i=0; i<numPathpoints; i++) {
            pathpoints[i] = model.pathpoints[i];
        }
    }
    
    return *this;
}

const Path& Path::operator +=(const PathPoint& newp) {
    
    this->add(newp);
    
    return *this;
}

int Path::length() const {
    return numPathpoints;
}

void Path::reverse() {
    PathPoint* newPathpoints = allocateMemory(numPathpoints);
    
    for (int i=0; i<numPathpoints; i++) {
        newPathpoints[i] = pathpoints[numPathpoints-i-1];
    }
    
    delete [] pathpoints;
    pathpoints = newPathpoints;
}







// Private methods

PathPoint* Path::allocateMemory(int size) {
    return new PathPoint[size];
}

void Path::deallocate() {
    if (pathpoints != 0) {
        delete [] pathpoints;
    }
    
    pathpoints = 0;
    numPathpoints = 0;
}




// Operator overload
std::ostream& operator<<(std::ostream& os, const Path& pp) {
    
    os << "--PATH--" << std::endl;
    for (int i=0; i<pp.numPathpoints; i++) {
        os << "Index: " << i << " - " << pp.get(i) << std::endl;
    }
    
    return os;
}