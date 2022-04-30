#include "Student.h"
#include <iostream>

//===================================================//
//                   Constructors                    //
//===================================================//

Student::Student(){
    name = "placeholder";
    number = "-1";
}

Student::Student(const string& name, const string& number){
    this->name = name;
    this->number = number;
}

Student::Student(Student& s){
    name = s.name;
    number = s.number;
}

//===================================================//
//                Getters + Setters                  //
//===================================================//

string Student::getName(){ return name; }

string Student::getNumber(){ return number; }

void Student::setName(const string& name){ this->name = name; }

void Student::setNumber(const string& number){ this->number = number; }

//===================================================//
//                    Functions                      //
//===================================================//

// Print student to console
void Student::print(){
    cout <<getName() <<": " <<getNumber() <<endl;
}

// Checks if the student calling the function has
// a smaller number than the one being passed in
bool Student::lessThan(Student& s){
    return this->number < s.number;
}
