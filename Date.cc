#include "Date.h"

//=========================================================//
//					   Constructors						   //
//=========================================================//

Date::Date(){
	setDate(1901,1,1,0,1);
}

Date::Date(int y, int m, int d, int h, int dur){
	setDate(y,m,d,h,dur);
}

//=========================================================//
//						  Setters						   //
//=========================================================//

void Date::setDuration(int dur){
	if(dur < 1) dur = 1;
	if(dur > MAX_DURATION) dur = MAX_DURATION;
	duration = dur;
}

void Date::setHour(int h){
	if(h < 0) h = 0;
	if(h > 23) h = 23;
	hour = h;
}

void Date::setDay(int d){
	int max = getMaxDay();
	if (d>max) d=max;
	if (d<1) d=1;
	day = d;
}

void Date::setMonth(int m){
	if (m > 12) m = 12;
	if (m < 1) m = 1;
	month = m;
}

void Date::setYear(int y){
	if (y < 1901) y = 1901;
	year = y;
}

void Date::setDate(int y, int m, int d, int h, int dur){
	setDuration(dur);
	setHour(h);
	setMonth(m);
	setDay(d);
	setYear(y);
}

void Date::setDate(Date& d){
	setDate(d.year, d.month, d.day, d.hour, d.duration);
}

//=========================================================//
//						  Getters						   //
//=========================================================//

int Date::getDuration(){ return duration; }
int Date::getHour(){ return hour; }
int Date::getDay(){ return day; }
int Date::getMonth(){ return month; }
int Date::getYear(){ return year; }
const string& Date::getMonthName(){ return months[month-1]; }

//=========================================================//
//						 Functions						   //
//=========================================================//

// Prints date to the console
void Date::print(){
	cout << getMonthName()<<" "<<getDay()<<", "<<getYear()<<" at "<<getHour()<<":00 for "<<getDuration() <<" hours" <<endl;
}

// Checks if the date calling the function comes
// before the date being passed into the function
bool Date::lessThan(Date& d){
	if (year == d.year){
		if (month == d.month){
			if(day == d.day){
				return hour < d.hour;
			}
			else{
				return day < d.day;
			}
		}else{
			return month < d.month;
		}
	}else{
		return year < d.year;
	}	
}

// Find how many days there are in the month that
// the current date is being made in
int Date::getMaxDay(){
	switch(getMonth()){
		case 4:
		case 6:
		case 9:
		case 11: 			return 30;
		case 2:				return 28;
		default:			return 31;
	}
}

// Checks if the date calling the function has
// any overlap with the date being passed in
bool Date::overlaps(Date& d){

	// Ensures date is the same before checking hours and duration
	if(this->day == d.day && this->month == d.month && this->year == d.year){
		// If hours of both dates match then they overlap, return true
		if(this->hour == d.hour){
			return true;
		}

		// If duration of the 2 dates causes an overlap, return true
		else{
			int thisStart = this->hour;
			int thisEnd = this->hour + this->duration;
			int otherStart = d.hour;
			int otherEnd = d.hour + d.duration;

			if((thisStart < otherStart && otherStart < thisEnd) || (thisStart < otherEnd && otherEnd < thisEnd) || (otherStart < thisStart && thisStart < otherEnd) || (otherStart < thisEnd && thisEnd < otherEnd)){
				return true;
			}
		}
	}

	return false;
}

// Helper function that checks if the date calling the function
// is the same as the one being passed in
bool Date::sameDate(Date& d){
	return (this->day == d.day && this->month == d.month && this->year == d.year && this->hour == d.hour);
}