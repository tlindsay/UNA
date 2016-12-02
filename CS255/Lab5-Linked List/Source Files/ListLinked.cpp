//*************************************************************
// Patrick Lindsay
// Lab 5 - ListLinked.cpp
// Description: Linked List implemenation
// Class: CS 255
//*************************************************************


#include "ListLinked.h"
#include <stdlib.h>

//*************************************************************
//Function Name: List
//Requirements: None
//Description: Constructor. Creates an empty list.
//*************************************************************
template <typename DataType>
List<DataType>::List(int ignored){ 
    head = NULL;
}
 
// Copy Constructor
//*************************************************************
//Function Name: List
//Requirements: None
//Description: Copy Constructor. Initializes the list to be 
//  equivalent to the other list
//*************************************************************
template <typename DataType>
List<DataType>::List(const List& other){ 
  	if (!other.head){ head = NULL; return;}
	head = new ListNode(other.head->dataItem);
    
	ListNode *oldtemp = other.head->next;
	ListNode *newtemp = head;
	while (oldtemp){
		newtemp->next = new ListNode(oldtemp->dataItem);
		newtemp=newtemp->next;
		oldtemp=oldtemp->next;		
	}
    cursor = head;
    gotoEnd();
}



//*************************************************************
//Function Name: operator=
//Requirements: None
//Description: Overloaded Assignment Operator. Sets the list to
//  be equivalent to the other list and returns a refernece to
//  the calling object.
//*************************************************************
template <typename DataType>
List<DataType>& List<DataType>::operator=(const List& other){
    if (other.head == head)
		return *this;
	this->~LinkedList();
    
	if (!other.head){ 
		head = NULL; 
		return *this;
	}
	head = new ListNode(other.head->dataItem);
    
	ListNode *oldtemp = other.head->next;
	ListNode *newtemp = head;
	while (oldtemp){
		newtemp->next = new ListNode(oldtemp->dataItem);
		newtemp=newtemp->next;
		oldtemp=oldtemp->next;		
	}
    cursor = head;
    gotoEnd();
	return *this;
}


//*************************************************************
//Function Name: ~List
//Requirements: None
//Description: Deconstructor. Deallocates the memory used to 
//  store the nodes in the list
//*************************************************************
template <typename DataType>
List<DataType>::~List(){
    ListNode *temp = head;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
    head = NULL;
}

//*************************************************************
//Function Name: insert
//Requirements: List is not full
//Description: Inserts newDatatItem into the list. If the list
//  is not empty, then inserts newDataItem after the cursor.
//  Otherwise, inserts newDataItem as the first (and only) data
//  item in the list. In either case, moves the cursor to 
//  newDataItem.
//*************************************************************
template <typename DataType>
void List<DataType>::insert(const DataType& newDataItem){
    // If there are no items in the list
	if (!head){
		head = new ListNode(newDataItem);
        cursor = head;
    }
	else    {
    // If there is already an item in the list
		cursor->next = new ListNode(newDataItem, cursor->next);
        cursor = cursor->next;
    }
}

//*************************************************************
//Function Name: remove
//Requirements: List is not empty
//Description: Removes the data marked by the cursor from the
//  list. If the resulting list is not empty, then moves the
//  cursor to the data item that followed the deleted data
//  item. If the deleted data item was at the end of the list,
//  then moves the cursor to the beginning of the list.
//*************************************************************
template <typename DataType>
void List<DataType>::remove(){
    // Cursor not at head and more than two data item
    if (head && cursor->next && cursor != head) {
        gotoPrior();
        ListNode *prev = cursor;
        gotoNext();
        ListNode *curr = cursor;
        gotoNext();
        prev->next = curr->next;
        delete curr;
    }
    // Cursor is a head and there is more than two data items
    else if (head && cursor == head && cursor->next) {
        ListNode *curr = cursor;
        gotoNext();
        head = cursor;
        delete curr;
    }
    // There are two data items with cursor not equal to head
    else if (head && cursor != head) {
        gotoPrior();
        ListNode *prev = cursor;
        gotoNext();
        ListNode *curr = cursor;
        gotoBeginning();
        prev->next = NULL;
        delete curr;
    }
    // There is only one item in the list
    else if (head && cursor == head && !cursor->next) {
        head = NULL;
        delete cursor;
        cursor = head;
    }
}

//*************************************************************
//Function Name: replace
//Requirements: List is not empty
//Description: Replaces the data item marked by the cursor with
//  newDataItem. The cursor remains at newDataItem.
//*************************************************************
template <typename DataType>
void List<DataType>::replace(const DataType& newDataItem){
    if (head)
        cursor->dataItem = newDataItem;
}

//*************************************************************
//Function Name: clear
//Requirements: None
//Description: Removes all the data items in the list.
//*************************************************************
template <typename DataType>
void List<DataType>::clear(){
    while (head) {
        remove();
    }
}

//*************************************************************
//Function Name: isEmpty
//Requirements: None
//Description: Returns true if the list is empty. Otherwise,
// returns false.
//*************************************************************
template <typename DataType>
bool List<DataType>::isEmpty() const{
    bool empty = false;
    if(head == NULL)
        empty = true;
    return empty;
}

//*************************************************************
//Function Name: isFull
//Requirements: None
//Description: Returns true if the list is full. Otherwise,
//  returns false.
//*************************************************************
template <typename DataType>
bool List<DataType>::isFull() const{
    return false;
}

//*************************************************************
//Function Name: gotoBeginning
//Requirements: List is not empty
//Description: Moves the cursor to the beginning of the list
//*************************************************************
template <typename DataType>
void List<DataType>::gotoBeginning(){
    cursor = head;
}

//*************************************************************
//Function Name: gotoEnd
//Requirements: List is not empty
//Description: Moves the cursor to the end of the list.
//*************************************************************
template <typename DataType>
void List<DataType>::gotoEnd(){
    while(cursor->next != NULL)
        cursor = cursor->next;
}

//*************************************************************
//Function Name: gotoNext
//Requirements: List is not empty
//Description: If the cursor is not at the end of the list, then
//  moves the cursor to mark the next data item in the list and
//  returns true. Otherwise, returns false.
//*************************************************************
template <typename DataType>
bool List<DataType>::gotoNext(){
    bool success = true;
    if (cursor->next != NULL) {
        cursor = cursor->next;
    }
    else 
        success = false;
    return success;
}

//*************************************************************
//Function Name: gotoPrior
//Requirements: List is not empty
//Description: If the cursor is not at the beginning of the list,
//  then moves the cursor to mark the preceding data item in the
//  list and returns true. Otherwise, returns false.
//*************************************************************
template <typename DataType>
bool List<DataType>::gotoPrior(){
    bool success = true;
    if (cursor != head) {
        ListNode *temp = head;
        while (temp->next != cursor) 
            temp = temp->next;
        cursor = temp;
    }
    else
        success = false;
    return success;
}

//*************************************************************
//Function Name: getCursor
//Requirements: List is not empty
//Description: Returns the value of the data item marked by the
//  cursor.
//*************************************************************
template <typename DataType>
DataType List<DataType>::getCursor()const{
    return cursor->dataItem;
}

//*************************************************************
//Function Name: ListNode
//Requirements: None
//Description: Constructor. Creates a new node with data set to
//  nodeData and next set to NULL.
//*************************************************************
template <typename DataType>
List<DataType>::ListNode::ListNode(const DataType& nodeData){
    dataItem = nodeData;
    next = NULL;
}

//*************************************************************
//Function Name: ListNode
//Requirements: None
//Description: Constructor. Creates a new node with data set to
//  nodeData and next set to nextPtr.
//*************************************************************
template <typename DataType>
List<DataType>::ListNode::ListNode(const DataType& nodeData, ListNode* nextPtr){
    dataItem = nodeData;
	next = nextPtr;
}

//*************************************************************
//Function Name:
//Requirements: None
//Description: Outputs the items in a list. If the list is empty, 
// outputs "Empty list". This operation is intended for testing 
// and debugging purposes only.
//*************************************************************
template <typename DataType>
void List<DataType>::showStructure() const{
     if ( isEmpty() ){
         cout << "Empty list" << endl;
     } 
     else{  
         for (ListNode* temp = head; temp != 0; temp = temp->next) {
             if (temp == cursor) {
                 cout << "[";
             }
 
             // Assumes that dataItem can be printed via << because
             // is is either primitive or operator<< is overloaded.
             cout << temp->dataItem;	
 
             if (temp == cursor) {
                 cout << "]";
             }
             cout << " ";
         }
         cout << endl;
     }
}

//*************************************************************
//Function Name: moveToBeginning
//Requirements: None
//Description: Removes the data item marked by the cursor from
//  the list and reinserts the data item at the beginning of
//  the list.
//*************************************************************
template<typename DataType>
void List<DataType>::moveToBeginning(){
	ListNode* temp=cursor;
	remove();
	head=new ListNode(temp->dataItem, head);
	gotoBeginning();
	temp=NULL;
	delete temp;
}

//*************************************************************
//Function Name: insertBefore
//Requirements: None
//Description: Inserts newDataItem into a list. If the list is
//  not empty, then inserts newDataItem immediately before the
//  cursor. Otherwise, inserts newDataItem as the first (and
//  only ) data item in the list. In either case, moves the
//  cursor to newDataItem.
//*************************************************************
template<typename DataType>
void List<DataType>::insertBefore(DataType const &newDataItem){
	if(head){
		ListNode* temp= new ListNode(cursor->dataItem, cursor->next);
		cursor->dataItem=newDataItem;
		cursor->next=temp;
	}
	else
		insert(newDataItem);
}








/*
//--------------------------------------------------------------------
//
//  Laboratory 5                                           test5.cpp
// 
//  Test program for the operations in the List ADT
//
//--------------------------------------------------------------------

#include <iostream>
#include "config.h"

//#include "ListLinked.h"

//using namespace std;

void print_help();

int  main()
{
    
    List<int> ball;
    ball.insert(5);
    ball.insert(8);
    ball.insert(2);
    List<int> bat = ball;
    bat.insert(3);
    
    ball.showStructure();
    bat.showStructure();
    
    //bat.insert(4);
    //ball.insert(1);
    ball.showStructure();
    bat.showStructure();
    
    
    
    
#if LAB5_TEST1
    List<int> testList;    // Test list
    int testData;          // List data item
#else
    List<char> testList;   // Test list
    char testData;         // List data item
#endif
    char cmd;              // Input command
    
    print_help();
    
     do
     {
     testList.showStructure();                     // Output list
     
     cout << endl << "Command: ";                  // Read command
     cin >> cmd;
     if ( cmd == '+'  ||  cmd == '='  ||  cmd == '#' )
     cin >> testData;
     
     switch ( cmd )
     {
     case 'H' : case 'h':
     print_help();
     break;
     
     case '+' :                                  // insert
     cout << "Insert " << testData << endl;
     testList.insert(testData);
     break;
     
     case '-' :                                  // remove
     cout << "Remove the data item marked by the cursor"
     << endl;
     testList.remove();
     break;
     
     case '=' :                                  // replace
     cout << "Replace the data item marked by the cursor "
     << "with " << testData << endl;
     testList.replace(testData);
     break;
     
     case '@' :                                  // getCursor
     cout << "Element marked by the cursor is "
     << testList.getCursor() << endl;
     break;
     
     case '<' :                                  // gotoBeginning
     testList.gotoBeginning();
     cout << "Go to the beginning of the list" << endl;
     break;
     
     case '>' :                                  // gotoEnd
     testList.gotoEnd();
     cout << "Go to the end of the list" << endl;
     break;
     
     case 'N' : case 'n' :                       // gotoNext
     if ( testList.gotoNext() )
     cout << "Go to the next data item" << endl;
     else
     cout << "Failed -- either at the end of the list "
     << "or the list is empty" << endl;
     break;
     
     case 'P' : case 'p' :                       // gotoPrior
     if ( testList.gotoPrior() )
     cout << "Go to the prior data item" << endl;
     else
     cout << "Failed -- either at the beginning of the "
     << "list or the list is empty" << endl;
     break;
     
     case 'C' : case 'c' :                       // clear
     cout << "Clear the list" << endl;
     testList.clear();
     break;
     
     case 'E' : case 'e' :                       // empty
     if ( testList.isEmpty() )
     cout << "List is empty" << endl;
     else
     cout << "List is NOT empty" << endl;
     break;
     
     case 'F' : case 'f' :                       // full
     if ( testList.isFull() )
     cout << "List is full" << endl;
     else
     cout << "List is NOT full" << endl;
     break;
    
#if LAB5_TEST2
     case 'M' : case 'm' :                   // In-lab Exercise 2
     cout << "Move the data item marked by the cursor to the "
     << "beginning of the list" << endl;
     testList.moveToBeginning();
     break;
#endif
    
#if LAB5_TEST3
     case '#' :                              // In-lab Exercise 3
     cout << "Insert " << testData << " before the "
     << "cursor" << endl;
     testList.insertBefore(testData);
     break;
#endif
    
     case 'Q' : case 'q' :                   // Quit test program
     break;
     
     default :                               // Invalid command
     cout << "Inactive or invalid command" << endl;
     }
     }
     while ( cin && cmd != 'Q'  &&  cmd != 'q' );
     
     if( ! cin )
     {
     // This is useful if students are testing the list with ints, instead of
     // chars, and accidentally enter a non-digit char.
     cout << "cin read errror" << endl;
     }
    
    return 0;
}

void print_help()
{
    cout << endl << "Commands:" << endl;
    cout << "  H   : Help (displays this message)" << endl;
    cout << "  +x  : Insert x after the cursor" << endl;
    cout << "  -   : Remove the data item marked by the cursor" << endl;
    cout << "  =x  : Replace the data item marked by the cursor with x"
    << endl;
    cout << "  @   : Display the data item marked by the cursor" << endl;
    cout << "  <   : Go to the beginning of the list" << endl;
    cout << "  >   : Go to the end of the list" << endl;
    cout << "  N   : Go to the next data item" << endl;
    cout << "  P   : Go to the prior data item" << endl;
    cout << "  C   : Clear the list" << endl;
    cout << "  E   : Empty list?" << endl;
    cout << "  F   : Full list?" << endl;
    cout << "  M   : Move data item marked by cursor to beginning  "
    << "(" << 
#if LAB5_TEST2
 "  Active   "
#else
 "Inactive  "
#endif
 << ": In-lab Ex. 2)" << endl;
 cout << "  #x  : Insert x before the cursor                  "
 << "  (" <<
#if LAB5_TEST3
 "  Active "
#else
 "Inactive "
#endif
 << " : In-lab Ex. 3)" << endl;
 cout << "  Q   : Quit the test program" << endl;
 cout << endl;
 }
 */






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
//#ifdef WIN32
//    system("cls");
//#else
//    system("clear");
//#endif
    cout << *this;
    cout << endl;
    wait(pause);

    for (int i = 0; i < 20; i++) {
        cout << endl;
    }
}