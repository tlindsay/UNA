//
//  main.cpp
//  Project X-Sorting
//
//  Created by Patrick Lindsay on 10/31/11.
//  Copyright 2011 University of North Alabama. All rights reserved.
//

#include <iostream>
#include "Sort.h"
using namespace std;

char GetChoice();
char GetOption();

int main (){
	Bubble<int> s1;
 	Selection<int> s2;
	Merge<int> s3;
	Quick<int> s4;
	DoubleSelection<int> s5;
	char choice=GetChoice();
	char option=0;
	do{
	switch(choice){
		case 'N':
			option=GetOption();
			s1.FillRandom(option); break;
		case 'O':
			option=GetOption();
			s1.FillOrdered(option); break;
		case 'R':
			option=GetOption();
			s1.FillReverseOrdered(option); break;
		case 'S':
			cout<<"Bubble Sort: "; s1.PrintMatrix();
			cout<<"Selection Sort: "; s2.PrintMatrix();
			cout<<"Merge Sort: "; s3.PrintMatrix();
			cout<<"Quick Sort: "; s4.PrintMatrix();
			cout<<"Double Selection Sort: "; s5.PrintMatrix(); break;
		case 'x':
			exit(1);
	}
	}while(choice!='X'&&choice!='x');
    return 0;
}

char GetChoice(){
	char choice=0;
	cout<<"Please enter a choice.\n"
		<<"N\tFill the array with random numbers.\n"
		<<"O\tFill the array with an ordered list of numbers.\n"
		<<"R\tFill the array with a reverse-ordered list.\n"
		<<"S\tSort\n"
		<<"X\tExit\n";
	cin>>choice;
	return choice;
}

char GetOption(){
	char option;
	cout<<"Enter 1 for 100 values, 2 for 1000, and 3 for 10,000.\n";
	cin>>option;
	return option;
}