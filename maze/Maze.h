/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Maze.h
 * Author: PrinceChaos
 *
 * Created on 15. Juni 2020, 19:25
 */

#ifndef MAZE_H
#define MAZE_H

#include <stdexcept>
#include <assert.h>
#include <iostream>
#include <string>
#include <windows.h>
#include <sstream>
#include "Path.h"

#define FREE '.'
#define OBSTRUCTED 'X'
#define PATHPOINT 'O'
#define ORIGIN 'A'
#define DESTINATION 'B'

#define COLOR_OBSTRUCTION 4
#define COLOR_PATH 34
#define COLOR_ORIGIN 17
#define COLOR_DESTINATION 17
#define COLOR_STANDARD 7


class Maze {
    
    // Operator overwriting
    friend std::ostream& operator<<(std::ostream&, const Maze&);
    
private:
    int rows, columns;
    char** squares;
    
    /**
     * @brief Free the dynamic memory
     */
    void freeSpace();
    
    /**
     * @brief allocate the dynamic matrix
     */
    char ** allocateSpace(int rows, int columns);
    
    
    /**
     * @brief set the entire matrix to a given value
     * @param value The value that the matrix is going to be set to
     */
    void set(char value);
    
    /**
     * @brief Copy another matrix' data
     * @param model
     */
    void copyData(const Maze& model); 
    
    /**
     * @brief Return a random number between min and max
     * @param min
     * @param max
     * @return 
     */
    int randomNumber(int min, int max) const;
    
    /**
     * @brief Give ConsoleTextAttribute for each possible state of the matrix
     * @param squareState could be OBSTRUCTED, FREE...
     * @return 
     */
    int getCorrespondingColor(char squareState) const;
    
public:
    /**
     * @brief Basic constructor
     */
    Maze();
    
    /**
     * @brief create a free maze (FREE)
     * @param rows matrix rows
     * @param cols matrix columns
     */
    Maze(int rows, int cols);
    
    /**
     * @brief Copy constructor
     * @param orig
     * @return 
     */
    Maze(const Maze& orig);
    
    /**
     * @brief Destructor
     */
    ~Maze();
    
    // Getters
    int getNumColumns() const { return columns; }
    int getNumRows() const { return rows; }
    
    /**
     * @brief Get a value from the maze matrix. 
     * @warning Throws exception if out of matrix range.
     * @param r
     * @param c
     * @return 
     */
    char get(int r, int c) const;
    
    /**
     * @brief Assignment operator
     * @param model
     * @return 
     */
    const Maze& operator=(const Maze& model);
    
    /**
     * @brief set one point in the maze to a given value 
     * @param row
     * @param col
     * @param value PATHPOINT, OBSTRUCTED, ORIGIN...
     */
    void set(int row, int col, char value);
    
    /**
     * @brief set everything on the board to FREE
     */
    void clear();
    
    /**
     * @brief Create an obstruction at the given location
     * @param row row coordinate
     * @param col column coordinate
     */
    void obstruct(int row, int col);
    
    /**
     * @brief Tell if coordinates are inside the matrix
     * @param row
     * @param col
     * @return 
     */
    bool insideBoard(int row, int col) const;
    
    /**
     * @brief Whether a point in the matrix is on the border or not
     * @param row
     * @param col
     * @return @retval true if it's on the border @retval false if not
     */
    bool onBorder(int row, int col) const;
    
    /**
     * @brief randomly generate obstructions on the board that the algorithm
     * later has to find a way through.
     * @param numObstructions How many of them to create
     * @param sizeObsctructions How big each obstruction is (they start at a random
     * place and then go into a random direction obstructing until filling the size)
     */
    void createRandomObstructions(int numObstructions, int sizeObstrucions);
    
    /**
     * @brief ORIGIN on lower left corner, DESTINATION on upper right.
     */
    void setStandardPathingGoal();
    
    /**
     * @brief Write a path into the maze
     * @param path
     */
    void addPath(const Path& path);
    
    /**
     * @brief paint to a cmd console, with colors.
     */
    void coloredConsolePaint();
    
    /**
     * @brief Which row the destination point is on.
     * @return row number, or -1 if there is no destination.
     */
    int getDestinationRow() const;
    
    /**
     * @brief Which column the destination point is on.
     * @return col number, or -1 if there is no destination.
     */
    int getDestinationColumn() const;
    
    

};

#endif /* MAZE_H */

