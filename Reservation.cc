#include "Reservation.h"
#include <iostream>

//===================================================//
//                   Constructors                    //
//===================================================//

Reservation::Reservation(Student* student, Room* room, Date& date){
    this->student = student;
    this->room = room;
    this->date.setDate(date);
}

//===================================================//
//                      Getters                      //
//===================================================//

Student* Reservation::getStudent(){ return student; }
Room* Reservation::getRoom(){ return room; }
Date Reservation::getDate(){ return date; }

//===================================================//
//                    Functions                      //
//===================================================//

// Print reservation to the console
void Reservation::print(){
    cout <<"Reservation for " <<student->getName() <<"(" <<student->getNumber() <<") in the " <<room->getName() <<" room on " <<date.getYear() <<"/" <<date.getMonth() <<"/" <<date.getDay() <<" at " <<date.getHour() <<":00 for " <<date.getDuration() <<" hours." <<endl;
}

// Checks if reservations calling the function overlaps
// with the date of the input reservation
bool Reservation::lessThan(Reservation& reservation){
    return this->date.lessThan(reservation.date);
}

// Checks if the room name and dates of the reservation
// calling the function overlaps with the input name and date
bool Reservation::overlaps(const string& roomName, Date& date){
    if(this->room->getName().compare(roomName) == 0){
        if(this->date.overlaps(date)){
            return true;
        }
        return false;
    }
    return false;
}