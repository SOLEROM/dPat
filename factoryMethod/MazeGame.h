#ifndef MAZE_GAME_H
#define MAZE_GAME_H

#include "Maze.h"
#include "Room.h"
#include "Wall.h"
#include "Door.h"

#include <iostream>


class MazeFactory;
class MazeBuilder;

class MazeGame {
public:
    Maze* CreateMaze();

    Maze* CreateMaze(MazeFactory& factory);
    Maze* CreateMaze(MazeBuilder& builder);
    Maze* CreateComplexMaze(MazeBuilder& builder);

    // factory methods:

    virtual Maze* MakeMaze() const
        {   std::cout << "MazeGame.h::MakeMaze" << std::endl;					
		return new Maze; }
    virtual Room* MakeRoom(int n) const
        {   std::cout << "MazeGame.h::MakeRoom" << std::endl;					
         return new Room(n); }
    virtual Wall* MakeWall() const
        { return new Wall; }
    virtual Door* MakeDoor(Room* r1, Room* r2) const
        { return new Door(r1, r2); }
};

#endif /* MAZE_GAME_H */
