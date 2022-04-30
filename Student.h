
#ifndef STUDENT_H
#define STUDENT_H

#include <string>

using namespace std;

class Student{
    public:
        //* Constructors
        Student();
        Student(const string& name, const string& number);
        Student(Student&);

        //* Getters + Setters
        string getName();
        string getNumber();

        void setName(const string&);
        void setNumber(const string&);

        //* Functions
        void print();
        bool lessThan(Student&);

    private:
        //* Member Variables
        string name;
        string number;
};

#endif