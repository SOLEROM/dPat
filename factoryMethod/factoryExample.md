# factory method : simple example code

## build

```
g++ *.cpp -o run
```


## different games

* BombedMazeGame: 

```
class BombedMazeGame : public MazeGame {
public:
    BombedMazeGame();

    virtual Room* MakeRoom(int n) const
        { return new RoomWithABomb(n); }
};
```

* MazeGame:

```
class MazeGame {
public:
    Maze* CreateMaze();
    
    virtual Maze* MakeMaze() const
        { return new Maze; }
    virtual Room* MakeRoom(int n) const
        { return new Room(n); }
};

```

## main

* main will create maze of differnt games (MazeGame/BombedMazeGame)
* but they will be Maze !!!

```
int main()
{
    MazeGame myGame;			//(1)
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!//
    Maze* m1 = myGame.CreateMaze();	//(1.1)
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!//
    std::cout << m1 << std::endl;
    
    BombedMazeGame myBombedGame;	  //(2)
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!//
    Maze* m2 = myBombedGame.CreateMaze(); //(2.1)
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!//
    std::cout << m2 << std::endl;

```

Maze.h

```
class Maze {

public:
  Maze(); 
  Room* RoomNo(int n) const;
  void AddRoom(Room *room);
  virtual Maze* Clone() const;
    
```

* (1.1) CreateMaze for myGame which is MazeGame for Maze class !!!
* (2.1) CreateMaze for myBombedGame also is Maze class !!!
* will call the CreateMaze of Maze !!!


MazeGame.cpp

```
Maze* MazeGame::CreateMaze() {

    std::cout << "MazeGame::CreateMaze()" << std::endl;
    

    Maze* aMaze = MakeMaze();		//(3)

    Room* r1 = MakeRoom(1);		//(4)
    aMaze->AddRoom(r1);



```

## case#1 MazeGame
 
* (3) MakeMaze is ( virtual Maze* MakeMaze()) member of  at MazeGame that return new Maze;
* (4) makeRoom is member of MazeGame 

## case#2 myBombedGame

* (3) myBombedGame has no member MakeMaze but it inherit (class BombedMazeGame : public MazeGame ) MakeMaze
* (3) MakeMaze will run form MazeGame
* (4) makeRoom is override from myBombedGame and will run its version


# run

```
case#1
MazeGame.cpp:CreateMaze()
MazeGame.cpp:CreateMaze() call MakeMaze
MazeGame.h::MakeMaze		//(3)
MazeGame.h::MakeRoom		//(4)

case#2
BombedMazeGame::BombedMazeGame()
MazeGame.cpp:CreateMaze()
MazeGame.cpp:CreateMaze() call MakeMaze
MazeGame.h::MakeMaze		//(3)
BombedMazeGame.h::MakeRoom	//(4)

```
