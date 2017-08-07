//
// Created by Cosss on 17/8/7.
//

#ifndef DESIGN_PATTERNS_FACTORYMETHOD_H
#define DESIGN_PATTERNS_FACTORYMETHOD_H

#endif //DESIGN_PATTERNS_FACTORYMETHOD_H

// https://en.wikipedia.org/wiki/Factory_method_pattern#External_links

#include <vector>
#include <iostream>

class Room{

};

class MagicRoom : public Room{
public:
    MagicRoom() { std::cout << "Magic Room is constructed." << std::endl; }
};

class OrdinaryRoom : public Room{
public:
    OrdinaryRoom() { std::cout << "Ordinary Room is constructed." << std::endl; }
};

class MazeGame{
private:
    std::vector<std::unique_ptr<Room> > rooms;

public:
    void createMaze(){
        rooms.push_back(makeRoom());
    }

protected:
    virtual std::unique_ptr<Room> makeRoom() const = 0;
};

class MagicMazeGame : public MazeGame{
protected:
    virtual std::unique_ptr<Room> makeRoom() const override {
        return std::make_unique<MagicRoom>();
    }
};

class OrdinaryMazeGame : public MazeGame{
protected:
    virtual std::unique_ptr<Room> makeRoom() const override {
        return std::make_unique<OrdinaryRoom>();
    }
};

void FactoryMethod(){
    std::unique_ptr<MazeGame> magicGame = std::make_unique<MagicMazeGame>();
    magicGame->createMaze();

    std::unique_ptr<MazeGame> ordinaryMazeGame = std::make_unique<OrdinaryMazeGame>();
    ordinaryMazeGame->createMaze();
}