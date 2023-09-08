#include "MazeGame.h"
#include "BombedMazeFactory.h"
#include "StandardMazeBuilder.h"
#include "MazePrototypeFactory.h"

int main()
{
    MazeGame game;
    BombedMazeFactory factory;

    game.CreateMaze(factory);

    Maze* maze;
    MazeGame game2;
    StandardMazeBuilder builder;

    game2.CreateMaze(builder);

    MazePrototypeFactory simpleMazeFactory(new Maze, new Wall, new Room, new Door);
    Maze* maze = game.CreateMaze(simpleMazeFactory);
}
