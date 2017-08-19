//
// Created by Cosss on 17/8/8.
//

#ifndef DESIGN_PATTERNS_PROTOTYPE_H
#define DESIGN_PATTERNS_PROTOTYPE_H

#endif //DESIGN_PATTERNS_PROTOTYPE_H

// https://en.wikipedia.org/wiki/Design_Patterns


namespace Prototype {
class Room {
public:
    Room() = default;
    Room(const Room &other){
        // implement deep copy here
        // ...
    }

    virtual Room clone() const {
        std::cout << "Room clone." << std::endl;
        return Room(*this);
    }

    virtual ~Room() {}
};

class MagicRoom : public Room {
public:
    MagicRoom() = default;
    MagicRoom(const MagicRoom &other){
        // implement deep copy here
        // ...
    }

    virtual Room clone() const override {
        std::cout << "Magic Room clone." << std::endl;
        return MagicRoom(*this);
    }

    ~MagicRoom() {}
};

class MazeFactory{
public:
    virtual Room makeRoom() const = 0;
};

class MazePrototypeFactory : public MazeFactory{
public:
    MazePrototypeFactory(Room *other){
        room.reset(other);
    }

    virtual Room makeRoom() const override {
        return room->clone();
    }

private:
    std::unique_ptr<Room> room;
};

class MazeGame {
private:
    std::vector<Room> rooms;

public:
    void createMaze(MazeFactory &factory) {
        rooms.push_back(factory.makeRoom());
    }
};


void Prototype(){
    MazeGame game;
    MazePrototypeFactory factory(new Room);
    game.createMaze(factory);

    MazePrototypeFactory magicFactory(new MagicRoom);
    game.createMaze(magicFactory);
}

} // namespace Prototype