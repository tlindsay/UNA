//
//  Packet.h
//  Project 4-OrderedList
//
//  Created by Patrick Lindsay on 10/4/11.
//  Copyright 2011 University of North Alabama. All rights reserved.
//

#ifndef _PACKET_H
#define _PACKET_H

#include "OrderedList.cpp"

class packet{
	public:
		static const int PACKET_SIZE=6;
		int position;
		char body[PACKET_SIZE];
		int getKey()const;
		friend ostream & operator <<(ostream& output, const packet & pack);
		void print()const;
};

#endif