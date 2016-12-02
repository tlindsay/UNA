//*************************************************************
// Patrick Lindsay
// Lab 9 - database.cpp
// Description: Reads in data from accounts.dat into a binary
//  search tree and allows the user to perform operations
// Class: CS 255
//*************************************************************




// Builds a binary search tree index for the account records in the
// text file accounts.dat.

#include <iostream>
#include <fstream>
#include "BSTree.cpp"
#include <string>

using namespace std;

//--------------------------------------------------------------------
//
// Declarations specifying the accounts database
//

const int nameLength      = 11;   // Maximum number of characters in
//   a name
const long bytesPerRecord = 38;   // Number of bytes used to store
//   each record in the accounts
//   database file

struct AccountRecord
{
int acctID;                   // Account identifier
char firstName[nameLength],   // Name of account holder
lastName[nameLength];
double balance;               // Account balance
};

//--------------------------------------------------------------------
//
// Declaration specifying the database index
//

struct IndexEntry
{
int acctID;              // (Key) Account identifier
long recNum;             // Record number

int getKey () const
{ return acctID; }   // Return key field
};

//--------------------------------------------------------------------

int main ()
{
ifstream acctFile ("accounts.dat");   // Accounts database file
AccountRecord acctRec;                // Account record
BSTree<IndexEntry,int> index;         // Database index
IndexEntry entry;                     // Index entry
int searchID;                         // User input account ID
long recNum;                          // Record number

// Iterate through the database records. For each record, read the
// account ID and add the (account ID, record number) pair to the
// index.

if ( !acctFile )
{
cout << "Error opening file " << endl;
}
else
{
string one;
string two;
int three;
while (! acctFile.eof()) {
acctFile >> entry.recNum >> entry.acctID >> one >> two >> three;
index.insert(entry);
}






// Output the account IDs in ascending order.
index.writeKeys();

// Clear the status flags for the database file.

acctFile.clear();

// Read an account ID from the keyboard and output the
// corresponding record.

cout  << "Enter in the account ID for the record you wish to retrieve" << endl;
cin >> searchID;

while (! acctFile.eof()) {
acctFile >> recNum >> acctRec.acctID >> acctRec.firstName >> acctRec.lastName >> acctRec.balance;
if (searchID == acctRec.acctID) {
cout << acctRec.acctIT << endl;
cout << acctRec.firstName << endl;
cout =< acctReg.lastName << endl;
cout << acctRec.balance << endl;
}
}


}
return 0;
}
