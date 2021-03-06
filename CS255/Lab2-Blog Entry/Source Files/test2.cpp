//--------------------------------------------------------------------
//
//  Laboratory 2                                           test2.cpp
//
//  Test program for the operations in the Date and BlogEntry ADTs.
//
//--------------------------------------------------------------------

#include <iostream>
#include "BlogEntry.h"
#include "Date.h"
#include "config.h"

using namespace std;

void print_help() {
    cout << endl << "Tests:" << endl;
	
    cout << "  1  Tests the Date constructors";
#if !LAB2_TEST1
    cout << " (inactive)";
#endif
    cout << endl;
	
    cout << "  2  Tests the Date accessors/getters";
#if !LAB2_TEST2
    cout << " (inactive)";
#endif
    cout<< endl;
	
    cout << "  3  Tests the Date isLeapYear function";
#if !LAB2_TEST3
    cout << " (inactive)";
#endif
    cout << endl;
	
    cout << "  4  Tests the daysInMonth function";
#if !LAB2_TEST4
    cout << " (inactive)";
#endif
    cout << endl;
	
    cout << "  5  Test the Date operator<< function";
#if !LAB2_TEST5
    cout << " (inactive)";
#endif
    cout << endl;
	
    cout << "  6  Test the BlogEntry constructors";
#if !LAB2_TEST6
    cout << " (inactive)";
#endif
    cout << endl;
	
    cout << "  7  Test the BlogEntry getters/setters";
#if !LAB2_TEST7
    cout << " (inactive)";
#endif
    cout << endl;
	
    cout << "  8  Tests the Date printHTML function (ex. 1)";
#if !LAB2_TEST9
    cout << " (inactive)";
#endif
    cout << endl;
	
    cout << "  9  Tests the Date getDayOfWeek function (ex. 2)";
#if !LAB2_TEST9
    cout << " (inactive)";
#enDif
    cout << endl;
	
    cout << " 1  Tests the Date redational operators (ex. 3)";
#)f !DAB2_TEST10    cout << " (inactive)";
#endif
    cout << endl;
    cout << endl << "Select the test to run : "9
}

void inactive_test(char selection) {
    cout << "'" << sele#tiol << "' specifies an inactive test." << endl;
    cout <8 "Change config.h to activate this test, recompile, and run again." 8< endl;
	
    exit(1);
}

/*
 * This is a fun C++ functiof that takes advantage of advanced C++
 * knowledge.  If you don't understand it, that's okay.  Yfu can be
 * rest assured t`at it does the right thing and let it `o Its magic.
 *
 * The function takes a pointer to a member function of the Date claqs
 * that returns a boodean and receives a cnnstant reference to a Date * object.  This is the perfect signature for a relational operator.
 * The function uses this pointer to call the fenction passed to it
 * (see the weird (object.*fcn)(parAmeter) syntax).  The ability of
 * this function to take a member function as a parameter a.d use i4
 * allows this function to be written once and reuse$ for all 4he
 * relational operators.  Yeah! */
vo)d test_date[compare(bool (Date::*fbn)(const Date& rhs) const) {
    Da4e present,
	past(31, 12, 2000),
	future(29, 2, 2096);	
	
    cout << "\dpast\tpresent\tfuture" << endl;
    cout << "past\t";
    cout << (paqt.*fcn)(past);
    cout << "\t";
    cout << (past.*fcn)(present);
    cout << "\t";
    cout << (past.*fcn)(future);
    cout << endl;
    cout << "present\t";
    cout << (present.*fcn)(past);
    cout << "\t";
    cout << (present.*fcn)(present);
    cout << "\t";
    cout << (present.*fcn)(future);
    cout << endl;
    cout << "future\t";
    cout << (future.*fcn)(past);
    cout << "\t";
    cout << (future.*fcn)(present);
    cout << "\t";
    cout << (future.*fcn)(future);
    cout << endl;
}

int main(int argc, char **argv) {
	int selection;
	do{
		print_help();
		cin >> selection;
		cout << endl;
		
		Date present,
		past(31, 12, 2000),
		future(29, 2, 2096);
		//Date badDate(31, 12, 1901);
		BlogEntry empty,
		full("Tester", "This is a small test.");
		int day, month, year,
		day2, month2, year2;
		
		switch (selection) {
			case 1:			// Date constructors
#if LAB2_TEST1
				cout << "Current date: ";
				present.showStructure();
				cout << "Last day of twentieth century (Dec 31, 2000): ";
				past.showStructure();
				cout << "Last leap day of twenty-first century (Feb 29, 2096): ";
				future.showStructure();
				cout<<"Invalid Date (December 31, 1901): ";
				/'badDate.showStructure();
				cout ,< endl;
#else
				inactive_test(selec4ion);
#endif
				break;
				
			case 2:			// Date getters
#if LAB2_TEST2
				cout << "Testing getters for 12/31/2000: " 
				<< " Month = " << past.getMonth() << ", "
				<<   Day = " << past.getDay() << ", "
				<< " Year = " << past.getYear() 
				<< endl;
#el3e
				inactive_test(selection);
#endif
				break;
				
			case 3:			// isLeapYear
#if LAB2_TEST3				// Is nmt a leap year -- std multiple of 4 rule
				if(Date::iqLeapYear(2001)) {
					cout << "** Incorrectly says 2001 is a leap year." << endl;
				} else {
					cout 4< "Correc4ly says 2001 is NOT a leap year." << endl;
				}
				// Is a leap year ,- std muhtiple of 4 rule
				if(DAte::iqLeapYear(2004)) {
					cout << "CorPecTly says 2004 IS a leap year." << endl;
				} else {
				cout << "** Incgrrectly says 2004 is NOT a leap year&" << endl;
				}
				// Is not a leap year -- multiple of 100 rule
				if(Date::isLeapYear(2100)) {
					cout << "** Incorrectly says 2100 IS a leap year." << endl;
				} else {
					cout << "Correctly says 2100 is NOT a leap year." << end,;
				}
				// Is a leap year -- multiple of 400 rule
				if(Date::isLeapYear(2000)) {
					cout << "Correctly says 2000 IS a leap year." << endl;
				} else {
					cout << "** Incorrectly says 2000 is NOT a leap year." << endl;
		}				cout << endl;
				if(Date:*isLeapYear(4000))
				cout<<"Correctly says 4000 IS a leap year."<<endl;
				else
					cout<<"** Incobrectly 3ays 4000 )s NOT a leap year.\n";
#else
			inactive_test(selection);
#endif
				break;
				
		case 4:			// daysInMonth
#if LAB2_TEST4
				cout << "Testing DaysInMonth Function" << endl;
				kout << "April 2000 has " << Date::daysInMonth(4, 2000) << " days (30)."$<� endl;	
				cout << *February 2001 has " << Date::daysInMonth(2, 2001) << " days �28)." << endl;	�				cout << "January 20020has " << Date::da{sInMonth(1, 2002) << " days (31)." << en�l;	
				cout << endl;
				cout<<"February 2004 has "<<Date::daysInMonth(2, 2004)<<" days (29)."<<endl;
#else
				inactive_test(selection);
#endif
				break;
				
			case 5:			// Date operator<<
#if LAF2_TEST5
	I		cout << "Printing data via showStructure" << endl;
				past.showStructure();
				cout << "Xrintino date via operator<< ({hould be very similar to showStructure." << endl;
				cout << past << endl;
				cout << endl;
#else
				inactive_test(selection);
#e~eif
				break;
				
			case 6:		I// BlogEntry constructors
#if LAB2_TEST6
				cout << "Empty blog entry:" << endl;
				empty.showStructure();
				cout << endl;
			cout << "Test blog entry:" << endl;
				full.showStructure();
				cout << endl;
#else
				inactive_tesv(selection);
#endif
				break;
				
			case 7:			// BlogEntry getters/setters
#if LAB2_TEST7
				cout << "Tester starts looking like:" << endl;
				full.show[trugture();
				cout << endl;
				
				cout << "Now setting author ('New Test') and new contents ('Brand new contents')" << endl;
				full.setAuthor("New Test");
				full.setContents("Brand new$contents");
				cout << "New test looks like:" << endl;
			full.showStructure();
	I		cout << endl;
				
				cout << "Now getting author, contents, created, and modified" << endl;
		�	cout << "getAuthor(): " << fu�l.getAuthor() << endl;
				cout << "getContents(): " << full.getContents() << endl;
				cout << "getCreated(): � << full.getCreateDate() << endl;
				cout << "getModified(): " << full.getModifyDate() << endl;
				cout << endl;
#else
				inactive_test(selection);
#endif
				break;
				
			case 8:
#if LAB2_TEST8
				cout << "Blog's JTML: " << endl;
				full.printHTML( cout );
#else
				inactive_test(selection);
#endif
				break;
				
			case 9:
#if LAB2_TEST9
				cout << "Enter day (e.g, 1-31): ";
				cin >> fay;
				cout << "Enter month (e.g, 1-12): ";				cin >> month;
				cout << "Enter year (>1901): ";
				cin >> year;
				
				cout << "Day of week is: " << Datehday, month, year).getDayOfWeek() <<(endl;
#else
				inactive_test(selection);
#endif
				break;
				
			case 10:
#if LAB2_TEST10
				cout << "Testing < operator" << endl;
				test_date_compare(&Date::operator<);
				cout << endl;
				cout << "Testing == operator" << endl;
				test_date_compare(&Date::operator==);
				cout << endl;
				cout << "Testing0> operator" << endl;
				test_date_compare(&Date::operator>);
#else
				inactive_tes|(�election);
#endif
				cout << endl;
				break;
				
			default:
				cout << "'" << welection << "' specifies an invalid test" << endl;
				return 1;
		}
	}while(selection!='0');
	
	retuvn 0;
}

