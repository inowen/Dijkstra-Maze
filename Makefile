all: maze.exe

maze.exe: main.cpp maze\Maze.h maze\Maze.cpp node\Node.cpp node\Node.h graph\Graph.h graph\Graph.cpp dijkstra\Dijkstra.h dijkstra\Dijkstra.cpp pathpoint\PathPoint.h pathPoint\PathPoint.cpp path\Path.cpp path\Path.h
	g++ -o pathfind -I./pathpoint -I./maze -I./node -I./graph -I./path main.cpp maze\Maze.cpp node\Node.cpp graph\Graph.cpp dijkstra\Dijkstra.cpp pathPoint\PathPoint.cpp path\Path.cpp