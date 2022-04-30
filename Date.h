
#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

using namespace std;

const int MAX_DURATION = 3;

class Date {
		
	public:
		//* Constructors
		Date();
		Date(int year, int month, int day, int hour, int duration);
		
				
		//* Setters
		void setDuration(int);
		void setHour(int);
		void setDay(int);
		void setMonth(int);
		void setYear(int);
		void setDate(int y, int m, int d, int h, int dur);
		void setDate(Date&);
		
		//* Getters
		int getDuration();
		int getHour();
		int getDay();
		int getMonth();
		int getYear();
		const string& getMonthName();
		
		//* Other
		bool lessThan(Date& d);
		void print();
		bool overlaps(Date& d);
		bool sameDate(Date& d);
	
	private:
		//* Functions
		int getMaxDay();
	
	
		//* Variables
		int day;
		int month;
		int year;
		int hour;
		int duration;
		
		const string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
		const string smonths[12]={"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul","Aug", "Sep", "Oct", "Nov", "Dec"};
	
};
#endif
