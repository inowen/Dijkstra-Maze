/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Maze.cpp
 * Author: PrinceChaos
 * 
 * Created on 15. Juni 2020, 19:25
 */

#include <ctime>
#include "Maze.h"

// Public methods

Maze::Maze(): squares(0), rows(0), columns(0) {}

Maze::Maze(const Maze& orig): columns(orig.columns), rows(orig.rows) {
    squares = allocateSpace(rows, columns);
    copyData(orig);
}

Maze::Maze(int rows, int cols): rows(rows), columns(cols) {
    squares = allocateSpace(rows, columns);
    this->set(FREE);
}

Maze::~Maze() { freeSpace(); }

const Maze& Maze::operator=(const Maze& model) {
    
    if (this != &model) {
        freeSpace();
        rows = model.rows;
        columns = model.columns;
        squares = allocateSpace(rows, columns);
        
        this->copyData(model);
    }
    
    return *this;
}

bool Maze::insideBoard(int row, int col) const {
    return (row>=0 && row<rows && col>=0 && col<columns);
}

void Maze::obstruct(int row, int col) {
    if (insideBoard(row, col)) {
        squares[row][col] = OBSTRUCTED;
    }
}

void Maze::clear() {
    set(FREE);
}

void Maze::createRandomObstructions(int numObstructions, int sizeObstructions) {
    for (int obstruction=0; obstruction<numObstructions; obstruction++) {
        
        // Generate random starting spot for the obstruction
        int coordRow = randomNumber(0, rows-1);
        int coordCol = randomNumber(0, columns-1);
        
        if (insideBoard(coordRow, coordCol) && !onBorder(coordRow, coordCol)) {
            obstruct(coordRow, coordCol);
        }
        
        // Randomly go into a direction and obstruct there, sizeObstrucions times
        for (int size=1; size<sizeObstructions; size++) {
            coordRow += (randomNumber(0,2) - 1);
            coordCol += (randomNumber(0,2) - 1);
            
            if (insideBoard(coordRow, coordCol) && !onBorder(coordRow, coordCol)) {
                obstruct(coordRow, coordCol);
            }
        }
    }
}


bool Maze::onBorder(int row, int col) const {
    bool onBorder = false;
    if (insideBoard(row, col)) {
        if (row==0 || col==0 || row==(rows-1) || col==(columns-1)) {
            onBorder = true;
        }
    }
    
    return onBorder;
}


void Maze::setStandardPathingGoal() {
    squares[rows-1][0] = ORIGIN;
    squares[0][columns-1] = DESTINATION;
}


void Maze::coloredConsolePaint() {
    
    std::cout << "Dimensions: " << rows << " x " << columns << std::endl << std::endl;
    
    // Get the handle for the console
    HANDLE hConsole = hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
    // Paint the matrix
    for (int r=0; r<rows; r++) {
        for (int c=0; c<columns; c++) {
            
            SetConsoleTextAttribute(hConsole, getCorrespondingColor(squares[r][c]));
            std::cout << squares[r][c];
            SetConsoleTextAttribute(hConsole, COLOR_STANDARD);
            std::cout << " ";
        }
        std::cout << std::endl;
    }
}

void Maze::set(int row, int col, char value) {
    if (insideBoard(row, col)) {
        squares[row][col] = value;
    }
}


char Maze::get(int r, int c) const{
    if (insideBoard(r, c)) {
        return squares[r][c];
    }
    else {
        std::stringstream message;
        message << "Maze.get(" << r << "," << c << ")" << " failed. Dimensions: "
                << rows << "x" << columns;
        
        throw std::out_of_range(message.str());
    }
}


void Maze::addPath(const Path& path) {
    for (int i=0; i<path.length(); i++) {
        this->set(path.get(i).getRow(), path.get(i).getCol(), PATHPOINT);
    }
}







// Private methods
void Maze::freeSpace() {
    for (int i=0; i<rows; i++) {
        delete [] squares[i];
        delete [] squares;
    }
    squares = 0;
    rows = 0;
    columns = 0;
}

char** Maze::allocateSpace(int rows, int columns) {
    
    char** matrix = new char*[rows];
    for (int i=0; i<rows; i++) {
        matrix[i] = new char[columns];
    }  
    
    return matrix;
}

void Maze::set(char value) {
    
    for (int r=0; r<rows; r++) {
        for (int c=0; c<columns; c++) {
            squares[r][c] = value;
        }
    }
}

void Maze::copyData(const Maze& model) {
    
    assert(columns == model.columns && rows == model.rows && this->squares != 0);
    
    for (int r=0; r<rows; r++) {
        for (int c=0; c<columns; c++) {
            this->squares[r][c] = model.squares[r][c];
        }
    }
}

int Maze::randomNumber(int min, int max) const {
    return rand()%(max-min + 1) + min;
}

int Maze::getCorrespondingColor(char squareState) const {
    switch (squareState) {
        case FREE:
            return COLOR_STANDARD;
        case OBSTRUCTED:
            return COLOR_OBSTRUCTION;
        case PATHPOINT:
            return COLOR_PATH;
        case ORIGIN:
            return COLOR_ORIGIN;
        case DESTINATION:
            return COLOR_DESTINATION;
        default:
            return COLOR_STANDARD;
    }
}

int Maze::getDestinationRow() const {
    int destinationRow = -1;
    
    for (int r=0; r<rows && destinationRow==-1; r++) {
        for (int c=0; c<columns && destinationRow==-1; c++) {
            if (squares[r][c] == DESTINATION) {
                destinationRow = r;
            }
        }
    }
    
    return destinationRow;
}

int Maze::getDestinationColumn() const {
    int destinationCol = -1;
    
    for (int r=0; r<rows && destinationCol==-1; r++) {
        for (int c=0; c<columns && destinationCol==-1; c++) {
            if (squares[r][c] == DESTINATION) {
                destinationCol = c;
            }
        }
    }
    
    return destinationCol;
}






// Overwritten operators
std::ostream& operator<<(std::ostream& os, const Maze& maze) {
    
    os << "Dimensions: " << maze.rows << " x " << maze.columns << std::endl << std::endl;
    
    // Paint the matrix
    for (int r=0; r<maze.rows; r++) {
        for (int c=0; c<maze.columns; c++) {
            os << maze.squares[r][c] << " ";
        }
        os << std::endl;
    }
    
    return os;
}