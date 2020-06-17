/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Path.h
 * Author: PrinceChaos
 *
 * Created on 17. Juni 2020, 10:12
 */

#ifndef PATH_H
#define PATH_H

#include "Pathpoint.h"

class Path {
    
    /**
     * Output operator 
     */
    friend std::ostream& operator<<(std::ostream& os, const Path& path);
    
private:
    PathPoint* pathpoints;
    int numPathpoints;
    
    /**
     * @brief Allocate space for array in the heap
     * @param size
     * @return Pointer to the array
     */
    PathPoint* allocateMemory(int size);
    
    /**
     * @brief Free dynamic memory
     */
    void deallocate();
    
    
public:
    /**
     * @brief Basic constructor
     */
    Path();
    
    /**
     * @brief Copy constructor
     * @param orig
     */
    Path(const Path& orig);
    
    /**
     * @brief Destructor
     */
    ~Path();
    
    /**
     * @brief Length of the array
     * @return 
     */
    int length() const;
    
    /**
     * @brief Getter as r-value
     * @param index
     * @return const reference
     */
    const PathPoint& get(int index) const;
    
    /**
     * @brief Getter as l-value
     * @param index
     * @return non-const reference
     */
    PathPoint& get(int index);
    
   /**
    * @brief overwrite a pathpoint in the list
    * @param index
    * @param p
    */
    void set(int index, const PathPoint& p);
    
    /**
     * @brief set the coordinates of a pathpoin in the list
     * @param index
     * @param valueX
     * @param valueY
     */
    void set(int index, int valueX, int valueY);
    
    /**
     * @brief add a pathpoint at the end of the list
     * @param newp the new PathPoint
     */
    void add(const PathPoint& newp);
    
    /**
     * @brief Assignment operator
     * @param model
     * @return 
     */
    const Path& operator=(const Path& model);
    
    /**
     * @brief Adds @p newp PathPoint at the end of the list
     * @param newp
     * @return 
     */
    const Path& operator+=(const PathPoint& newp);
    
    /**
     * @brief Reverse the order of the PathPoints (like a path from destination to beginning)
     */
    void reverse();
    
    

};

#endif /* PATH_H */

