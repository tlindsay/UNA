////
////  perfect.cpp
////  Project 10-Hashing
////
////  Created by Patrick Lindsay on 10/17/11.
////  Copyright 2011 University of North Alabama. All rights reserved.
////
////********************************************************************
////This file is to be used as part of Programming Ex. 2
////********************************************************************
//
//#include <string>
//#include <iostream>
//#include "HashTable.cpp"
//
//using namespace std;
//
////class Identifier{
////	string ident;
////public:
////	void setKey(string newIdent)
////	{ident=newIdent;}
////	string getKey()const{
////		return ident;
////	}
////	static unsigned int hash(const string& key){
////		char first;
////		first=key[0];
////		return first;
////	}
////};
//
//int main(){
//	HashTable<Identifier, string> testTable(7);
//	Identifier data;
//	for(int i=0;i<7;++i){
//		switch(i){
//			case 0:
//				data.setKey("double"); break;
//			case 1:
//				data.setKey("else"); break;
//			case 2:
//				data.setKey("if"); break;
//			case 3:
//				data.setKey("return"); break;
//			case 4:
//				data.setKey("switch"); break;
//			case 5:
//				data.setKey("void"); break;
//			case 6:
//				data.setKey("while"); break;
//		}
//		testTable.perfectHash(data);
//		testTable.showStructure();
//		cout<<endl;
//	}
//}
//
