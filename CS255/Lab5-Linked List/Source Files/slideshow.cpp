//--------------------------------------------------------------------
//
//  Laboratory 5, Programming Exercise 1                 slideshow.cpp
//
//  (Shell) Slide show program
//
//  Updated: 2008-03-12
//--------------------------------------------------------------------

// Displays a slide show.

// Uncomment the following line if running in windows
// #define WIN32

//#include <iostream>
#include <fstream>
#include <ctime>

//using namespace std;

//#include "ListLinked.cpp"


//--------------------------------------------------------------------

// This is a very ugly way to wait for a specified amount of time.
// It is ugly because it runs the CPU the whole time, instead of
// just suspending the process for the required time period.
// However, it is also very portable.  This function should work on
// all platforms that support ANSI C++.  Feel free to replace this
// with something nicer (such as sleep or usleep) if you so choose.
void wait(int secs) 
{
	int start=clock();
	
	while (clock() < start + secs * CLOCKS_PER_SEC);
}

//--------------------------------------------------------------------

class Slide
{
public:
	static const int HEIGHT = 10,		// Slide dimensions
	WIDTH  = 36;
	
	void display () const;			// Display slide and pause
	
private:
	
	char image [HEIGHT][WIDTH];  	   // Slide image
	int pause;				   // Seconds to pause after
	//  displaying slide
	
	friend istream& operator>> (istream& in, Slide& slide);
	friend ostream& operator<< (ostream& out, const Slide& slide);
};

//--------------------------------------------------------------------

int main ()
{
	List<Slide> slideShow;    	    // Slide show
	Slide currSlide;                // Slide
	char filename[81];              // Name of slide show file
	
	// Read the slide show from the specified file.
	
	cout << endl << "Enter the name of the slide show file : ";
	cin >> filename;
	
	ifstream slideFile ( filename );
	
	if ( !slideFile )
	{
		cout << "Error opening file " << filename << endl;
	}
	else
	{
		// Read in the slides one-by-one. (Your code below)
		
		while (! slideFile.eof()) {
			slideFile >> currSlide;
			slideShow.insert(currSlide);
		}
		
		// Close the file. (Your code below)
		slideFile.close();
		
		// Display the slide show slide-by-slide. (Your code below)
		Slide display;
		slideShow.gotoBeginning();
		while (slideShow.gotoNext() == true) {
			slideShow.gotoPrior();
			display = slideShow.getCursor();
			display.display();
			slideShow.gotoNext();
		}
	}
	return 0;
}

//--------------------------------------------------------------------

istream& operator>> (istream& inFile, Slide& slide1)

// Read a slide from inFile.

{
	inFile >> slide1.pause;
	for (int i = 0; i < slide1.HEIGHT; ++i) {
		for(int j = 0; j < slide1.WIDTH; ++j)
			inFile.get(slide1.image[i][j]);
	}
	
	
	return inFile;
	
	
}

//--------------------------------------------------------------------

ostream& operator<< (ostream& out, const Slide& slide1)

{
	// Display a slide. (Your code below)
	
	for (int i =0; i < slide1.HEIGHT; ++i) {
		for (int j = 0; j < slide1.WIDTH; ++j)
			out << slide1.image[i][j];
	}  
	return out;
	
	
}


void Slide:: display () const


{
	
	//This should compile and run on both Windows and Unix
	//Feel free to change this if you want to do something nicer.
	cout << *this;
	cout << endl;
	wait(pause);
	
	for (int i = 0; i < 20; i++) {
		cout << endl;
	}
	
	
	
	
}