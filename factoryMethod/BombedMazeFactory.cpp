#include "BombedMazeFactory.h"
#include "BombedWall.h"
#include "Room.h"
#include "RoomWithABomb.h"
#include "Wall.h"
#include <iostream>

Wall* BombedMazeFactory::MakeWall () const {
    return new BombedWall;
}

Room* BombedMazeFactory::MakeRoom(int n) const {

    std::cout << "BombedMazeFactory.cpp:BombedMazeFactory::MakeRoom" << std::endl;					
    return new RoomWithABomb(n);
}

