
#ifndef ROOM_H
#define ROOM_H

#include <string>

using namespace std;

class Room{
    public:
        //* Constructors
        Room(const string& name, int capacity, int computers, bool whiteboard);
        Room(Room&);

        //* Getters + Setters
        string getName();
        int    getCapacity();
        int    getComputers();
        bool   hasWhiteboard();

        void setName(const string&);
        void setCapacity(int);
        void setComputers(int);
        void setWhiteboard(bool);

        //* Functions
        bool meetsCriteria(int, int, bool);
        bool lessThan(Room&);
        void print();

    private:
        //* Member variables
        string name;
        int    capacity;
        int    computers;
        bool   whiteboard;
};

#endif