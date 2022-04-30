#include "Library.h"

//===========================================//
//         Constructor + Destructor          //
//===========================================//

Library::Library(){
    students = new Student*[MAX_ARR_SIZE];
    reservations = new Reservation*[MAX_ARR_SIZE];
    
    numStudents = 0;
    numRooms = 0;
    numReservations = 0;
}

Library::~Library(){
    for(int i=0; i<numStudents; i++){
        delete students[i];
    }
    delete[] students;

    for(int i=0; i<numRooms; i++){
        delete rooms[i];
    }

    for(int i=0; i<numReservations; i++){
        delete reservations[i];
    }
    delete[] reservations;
}

//===========================================//
//                Functions                  //
//===========================================//

// Print library to the console
void Library::print(){
    cout <<"Library has " <<numStudents << " students, " <<numRooms << " rooms and " <<numReservations << " reservations that were made." <<endl;
}

// Add a student to the library if there's room
// Return true if added student, return false otherwise
bool Library::addStudent(const string& name, const string& number){
    Student* newStudent = new Student(name, number);

    if(numStudents < MAX_ARR_SIZE){
        if(numStudents == 0){
            students[0] = newStudent;
        }
        else if(numStudents == 1){
            if(newStudent->lessThan(*students[0])){
                students[1] = students[0];
                students[0] = newStudent;
            }
            else{
                students[1] = newStudent;
            }
        }
        else{
            for(int i=numStudents-1; i>0; i--){
                students[i+1] = students[i];

                // If new student has largest number, add to back
                if(i == numStudents-1 && !newStudent->lessThan(*students[i])){
                    students[i+1] = newStudent;
                    break;
                }

                // If new student is less than current student and
                // greater than previous student then add
                else if(newStudent->lessThan(*students[i]) && !newStudent->lessThan(*students[i-1])){
                    students[i] = newStudent;
                    break;
                }

                // If we reach the end of the loop then the new
                // student is the smallest, therefore add to front
                else if(i == 1){
                    students[1] = students[0];
                    students[0] = newStudent;
                }
            }
        }

        numStudents++;
        return true;
    }
    return false;
}

// Add a room to the library if there's room
// Return true if added room, return false otherwise
bool Library::addRoom(const string& name, int capacity, int computers, bool whiteboard){
    Room* newRoom = new Room(name, capacity, computers, whiteboard);

    if(numRooms < MAX_ARR_SIZE){
        if(numRooms == 0 ){
            rooms[0] = newRoom;
        }
        else if(numRooms == 1){
            if(newRoom->lessThan(*rooms[0])){
                rooms[1] = rooms[0];
                rooms[0] = newRoom;
            }
            else{
                rooms[1] = newRoom;
            }
        }
        else{
            for(int i=numRooms-1; i>0; i--){
                rooms[i+1] = rooms[i];

                // If the new room is the biggest, add to back
                if(i == numRooms-1 && !newRoom->lessThan(*rooms[i])){
                    rooms[i+1] = newRoom;
                    break;
                }

                // If new room is less than current room but
                // greater than previous room, then add
                else if(newRoom->lessThan(*rooms[i]) && !newRoom->lessThan(*rooms[i-1])){
                    rooms[i] = newRoom;
                    break;
                }

                // If we reach the end then the new room is the
                // smallest room, therefore add to front
                else if(i == 1){
                    rooms[1] = rooms[0];
                    rooms[0] = newRoom;
                }
            }
        }

        numRooms++;
        return true;
    }

    return false;
}

// Find the student with the specified name, store it,
// and return true if found, return false otherwise
bool Library::getStudent(const string& name, Student** student){
    for(int i=0; i<numStudents; i++){
        if(students[i]->getName() == name){
            *student = students[i];
            return true;
        }
    }

    return false;
}

// Find the room with the specified name, store it,
// and return true if found, return false otherwise
bool Library::getRoom(const string& roomName, Room** room){
    for(int i=0; i<numRooms; i++){
        if(rooms[i]->getName() == roomName){
            *room = rooms[i];
            return true;
        }
    }

    return false;
}

// Returns true if no reservation that overlaps with the
// given date is found. Otherwise returns false
bool Library::isFree(const string& room, Date& date){
    // Attempts to find a room that matches the given name
    for(int i=0; i<numRooms; i++){
        if(rooms[i]->getName() == room){

            // Attempts to find a reservation for the given room
            for(int j=0; j<numReservations; j++){
                if(reservations[j]->getRoom()->getName() == room){
                    if(reservations[j]->getDate().overlaps(date)){
                        return false;
                    }
                    return true;
                }
            }

            return true;
        }
    }

    return false;
}

// Returns true if the student and room exist and it's
// possible to make a reservation without overlapping
// the given date. Otherwise return false
bool Library::makeReservation(const string& student, const string& room, Date& date){

    if(numReservations == MAX_ARR_SIZE){
        return false;
    }

    Student* s1;
    Room* r1;
    if(!getStudent(student, &s1) || !getRoom(room, &r1)){
        return false;
    }

    if(isFree(room, date)){
        Reservation* newReservation = new Reservation(s1, r1, date);

        if(numReservations == 0){
            reservations[0] = newReservation;
        }
        else if(numReservations == 1){
            if(newReservation->lessThan(*reservations[0])){
                reservations[1] = reservations[0];
                reservations[0] = newReservation;
            }
            else{
                reservations[1] = newReservation;
            }
        }
        else{
            for(int i=numReservations-1; i>0; i--){
                reservations[i+1] = reservations[i];

                // If the new room is the biggest, add to back
                if(i == numReservations-1 && !newReservation->lessThan(*reservations[i])){
                    reservations[i+1] = newReservation;
                    break;
                }

                // If new room is less than current room but
                // greater than the previous room, then add
                else if(newReservation->lessThan(*reservations[i]) && !newReservation->lessThan(*reservations[i-1])){
                    reservations[i] = newReservation;
                    break;
                }

                // If we reach the end then the new room is the
                // smallest room, therefore add to front
                else if(i == 1){
                    reservations[1] = reservations[0];
                    reservations[0] = newReservation;
                }
            }
        }

        numReservations++;
        return true;
    }

    return false;
}

// Remove all reservations on or before the given date
void Library::update(Date& date){
    Reservation** newReservations = new Reservation*[MAX_ARR_SIZE];
    int newNumReservations = 0;

    // Iterate through all reservations and only keep
    // the ones whose date is strictly greater than 
    // the one that was passed in
    for(int i=0; i<numReservations; i++){
        Date currentDate = reservations[i]->getDate();

        if(currentDate.lessThan(date) || currentDate.sameDate(date)){
            delete reservations[i];
        }
        else{
            newReservations[newNumReservations] = reservations[i];
            newNumReservations++;
        }
    }

    // Accounts for deleting all reservations
    if(newNumReservations == 0){
        delete[] newReservations;
        numReservations = 0;
    }
    // Accounts for when at least 1 reservation
    // hasn't been deleted yet
    else{
        delete[] reservations;
        reservations = newReservations;
        numReservations = newNumReservations;
    }
}

// Print out every reservation in the library
void Library::printReservations(){
    if(numReservations == 0){
        cout << "There are currently no reservations for any of the rooms." <<endl;
    }
    else{
        for(int i=0; i<numReservations; i++){
            reservations[i]->print();
        }
    }
}