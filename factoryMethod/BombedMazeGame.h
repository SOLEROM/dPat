#include "BombedWall.h"
#include "MazeGame.h"
#include "RoomWithABomb.h"
#include <iostream>

class Room;
class Wall;

class BombedMazeGame : public MazeGame {
public:
    BombedMazeGame();

    virtual Wall* MakeWall() const
        { return new BombedWall; }

    virtual Room* MakeRoom(int n) const
	{
		std::cout << "BombedMazeGame.h::MakeRoom" << std::endl;
	       	return new RoomWithABomb(n); }
};
