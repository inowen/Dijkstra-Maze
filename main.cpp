/* 
 * File:   main.cpp
 * Author: PrinceChaos
 *
 * Created on 15. Juni 2020, 19:09
 */

#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <windows.h>   // WinApi header
#include "maze\Maze.h"
#include "Graph.h"
#include "dijkstra/Dijkstra.h"


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    
    srand(time(0));
    
    // Make the maze
    
    const int ROWS_MAZE = 60;
    const int COLS_MAZE = 100;
    const int NUM_OBSTRUCTIONS = 150;
    const int SIZE_OBSTRUCTIONS = 30;
    
    Maze maze(ROWS_MAZE, COLS_MAZE);
    
    char c = '\n';
    
    
    while (c == '\n') {
        maze.setStandardPathingGoal();
        maze.createRandomObstructions(NUM_OBSTRUCTIONS, SIZE_OBSTRUCTIONS);
        
        Graph graph(maze);
        // cout << graph << endl;
        
        Dijkstra dij;
        dij.setGraph(graph);
        dij.setStartingPoint(ROWS_MAZE-1, 0);
        cout << "Starting point set: ";
        cout << *dij.getStartingPoint() << endl;
        
        // Dijkstra algorithm
        dij.doAlgorithm();
        cout << "Algorithm done" << endl << endl;
        // cout << dij.getGraph() << endl;
        
        // Get a path from Dijkstra and add it to the maze.
        Path pathToDestination;
        pathToDestination = dij.getPathTo(maze.getDestinationRow(), maze.getDestinationColumn());
        // cout << pathToDestination << endl;
        maze.addPath(pathToDestination);
        
        
        // Paint the maze
        maze.coloredConsolePaint();
        
        // Clear maze for next round
        maze.clear();
        
        // Wait for keypress
        c = getchar();
         
    }
    
    
    
    return 0;
}

