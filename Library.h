
#ifndef LIBRARY_H
#define LIBRARY_H

#include "Reservation.h"
#include "Date.h"
#include "Room.h"
#include "Student.h"

const int MAX_ARR_SIZE = 30;

class Library{
    public:
        //* Constructors
        Library();
        ~Library();

        //* Functions
        bool addStudent(const string& name, const string& number);
        bool addRoom(const string& name, int capacity=1, int computers=0, bool whiteboard=false);

        bool getStudent(const string& name, Student** student);
        bool getRoom(const string& roomName, Room** room);

        void print();
        bool isFree(const string& room, Date&);
        bool makeReservation(const string& student, const string& room, Date& date);

        //* Bonus functions
        void update(Date&);
        void printReservations();

    private:
        //* Member variables
        Student** students;
        Room* rooms[MAX_ARR_SIZE];
        Reservation** reservations;
        int numStudents, numRooms, numReservations;
};

#endif