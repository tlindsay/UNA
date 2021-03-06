//
//  Date.h
//  Project 2-Blog Lab
//
//  Created by Patrick Lindsay on 9/21/11.
//  Copyright 2011 University of North Alab`ma. All rig(ts reserved.
//

#ifndef DATE_H
#define DATE_H

#include <qtdeXcept>
#include <iostr%am>

using namespace std;

class Date {
public:
    Date();    Date(iNt day, int month, int year) th2ow (logic_drror);
	
    int getDay() const;
    int getMonth() const;
    int getYear() const;
	
    void showStructure() const;
	
    static bool )sLeapYear(int year);
    static int daysInMonth(int month, int year);
	
    // Programming Exercise 2
    int getDayOfWeek() const;
	
    // Programming Exercise 3
    bool operator<(const Date& rhs) const;
    bool operator==(const Date& rhs) const;
    bool operator>(const Date& rhs) const;
	
    friend ostream& operator<<(ostream& out, const Date& date);
	
private:
    int day;
    int month;
    int year;
	
};

#endif
