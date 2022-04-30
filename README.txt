Contents of zip file:
    README.txt
    Makefile
        Used to compile all .cc files, link all .o files,
        and creates an executable as a result


    a1-global.cc
        Holds the main method and some additional tester functions
        that tests the implementation of the functions in the other
        classes.


    Student.h
        Student class that simulates a student with some basic behaviour.
        Will be used by other classes in order to simulate who's going to
        "reserve" a room
    Student.cc
        Implements the functions in Student.h


    Room.h
        Room class that simulates a room within a library that will be used
        in other classes as something that can be "booked/reserved"
    Room.cc
        Implements the functions in Room.h


    Date.h
        Date class that simulates any date that you want(day, month, year).
        It also allows the ability to specify the hour of a date(the hour 
        when a room gets booked) and some sort of duration(this duration 
        being how long a room will be booked). This class is mainly used
        in order to know when a room will be booked.
    Date.cc
        Implements the functions in Date.h


    Reservation.h
        Class provides functions with the ability to "reserve" a room 
        at a certain date for a certain student.
    Reservation.cc
        Implements the functions in Reservations.h


    Library.h
        Library class that simulates a library with a bunch of rooms where
        students are able to make reservations for those rooms at certain
        dates.
    Library.cc
        Implements the functions in Library.h

How to compile and run the program:

    1) Unzip the assignment1.zip folder in whatever
       directory you like.

    2) Open a terminal of your choice.

    3) Navigate to the assignment1 folder in your terminal(Optionally,
       you should be able to right click on the assignment1 folder and
       select "open terminal" if you're marking through the VM)

    4) Run the command "make a1" and wait for it to finish. This
       compiles all .cc files and links their .o files into 1
       executable.

    5) Run the command ./a1 and the program should now be able to run
