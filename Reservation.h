
#ifndef RESERVATION_H
#define RESERVATION_H

#include "Date.h"
#include "Room.h"
#include "Student.h"

class Reservation{
    public:
        //* Constructors
        Reservation(Student*, Room*, Date&);

        //* Getters
        Student* getStudent();
        Room* getRoom();
        Date getDate();

        //* Functions
        void print();
        bool lessThan(Reservation&);
        bool overlaps(const string& roomName, Date&);

    private:
        //* Member Variables
        Student* student;
        Room* room;
        Date date;
};

#endif