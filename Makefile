
a1: a1-global.o Student.o Room.o Date.o Reservation.o Library.o
	g++ -o a1 a1-global.o Student.o Room.o Date.o Reservation.o Library.o

a1-global.o: a1-global.cc
	g++ -c a1-global.cc

Student.o: Student.h Student.cc
	g++ -c Student.cc

Room.o: Room.h Room.cc
	g++ -c Room.cc

Date.o: Date.h Date.cc
	g++ -c Date.cc

Reservation.o: Reservation.h Reservation.cc
	g++ -c Reservation.cc

Library.o: Library.h Library.cc
	g++ -c Library.cc

clean:
	rm -f *.o a1