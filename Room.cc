
#include "Room.h"
#include <iostream>

//============================================================//
//                       Constructors                         //
//============================================================//

Room::Room(const string& name, int capacity=1, int computers=0, bool whiteboard=false){
    setName(name);
    setCapacity(capacity);
    setComputers(computers);
    setWhiteboard(whiteboard);
}

Room::Room(Room& room){
    setName(room.name);
    setCapacity(room.capacity);
    setComputers(room.computers);
    setWhiteboard(room.whiteboard);
}

//============================================================//
//                    Getters + Setters                       //
//============================================================//

string Room::getName(){ return this->name; }

int Room::getCapacity(){ return this->capacity; }

int Room::getComputers(){ return this->computers; }

bool Room::hasWhiteboard(){ return this->whiteboard; }

void Room::setName(const string& name){ this->name = name; }

void Room::setCapacity(int capacity){ this->capacity = capacity; }

void Room::setComputers(int computers){ this->computers = computers; }

void Room::setWhiteboard(bool whiteboard){ this->whiteboard = whiteboard; }

//============================================================//
//                         Functions                          //
//============================================================//

// Prints out the room to the console
void Room::print(){
    if(hasWhiteboard()){
        cout << getName() << " with capacity:" << getCapacity() << ", computers:" << getComputers() << ", and it has a whiteboard" << endl;
    }
    else{
        cout << getName() << " with capacity:" << getCapacity() << ", computers:" << getComputers() << ", and it has no whiteboard" << endl;
    }
}

// Returns true if the room parameters meet or exceed the input parameters
bool Room::meetsCriteria(int capacity=1, int computers=0, bool whiteboard=false){

    if(whiteboard){
        if(getCapacity() >= capacity && getComputers() >= computers && hasWhiteboard()){
            return true;
        }
    }
    else{
        if(getCapacity() >= capacity && getComputers() >= computers){
            return true;
        }
    }

    return false;
}

// Ensures the room's name calling the function 
// comes before the input parameter alphabetically
bool Room::lessThan(Room& r){
    return this->name < r.name;
}

