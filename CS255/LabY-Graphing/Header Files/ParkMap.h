#include<iostream>
#include<fstream>
using namespace std;

class ParkMap{
public:
	ParkMap();
	void PrintMap();
	void PrintFullMap();
	void PrintFullCost();
	void PrintPath(char path);
private:
	static int const rows = 22;
	static int const cols = 75;
	char map[rows][cols];
};

ParkMap::ParkMap(){
	ifstream infile;
	infile.open("FullMap.txt");
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++)
			infile>>noskipws>>map[i][j];
	}
	infile.close();
}

void ParkMap::PrintMap(){
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++)
			cout<<map[i][j];
	}
}

void ParkMap::PrintFullMap(){
	ifstream infile;
	infile.open("FullMap.txt");
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++)
			infile>>noskipws>>map[i][j];
	}
	infile.close();
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++)
			cout<<map[i][j];
	}
}

void ParkMap::PrintFullCost(){
	ifstream infile;
	infile.open("MapCosts.txt");
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++)
			infile>>noskipws>>map[i][j];
	}
	infile.close();
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++)
			cout<<map[i][j];
	}
}

void ParkMap::PrintPath(char path){
	ifstream infile;
	switch(path){
		case'a': case'A':
			infile.open("Village.txt");
			for(int i=0;i<rows;i++){
				for(int j=0;j<cols;j++)
					infile>>noskipws>>map[i][j];
			}
			infile.close();
			PrintMap();
			break;
		case'b': case'B':
			infile.open("Ahwahnee.txt");
			for(int i=0;i<rows;i++){
				for(int j=0;j<cols;j++)
					infile>>noskipws>>map[i][j];
			}
			infile.close();
			PrintMap();
			break;
		case'c': case'C':
			infile.open("Mirror.txt");
			for(int i=0;i<rows;i++){
				for(int j=0;j<cols;j++)
					infile>>noskipws>>map[i][j];
			}
			infile.close();
			PrintMap();
			break;
		case'd': case'D':
			infile.open("Bridge.txt");
			for(int i=0;i<rows;i++){
				for(int j=0;j<cols;j++)
					infile>>noskipws>>map[i][j];
			}
			infile.close();
			PrintMap();
			break;
		case'e': case'E':
			infile.open("Royal.txt");
			for(int i=0;i<rows;i++){
				for(int j=0;j<cols;j++)
					infile>>noskipws>>map[i][j];
			}
			infile.close();
			PrintMap();
			break;
		case'f': case'F':
			infile.open("Beach.txt");
			for(int i=0;i<rows;i++){
				for(int j=0;j<cols;j++)
					infile>>noskipws>>map[i][j];
			}
			infile.close();
			PrintMap();
			break;
		case'g': case'G':
			infile.open("Union.txt");
			for(int i=0;i<rows;i++){
				for(int j=0;j<cols;j++)
					infile>>noskipws>>map[i][j];
			}
			infile.close();
			PrintMap();
			break;
		case'h': case'H':
			infile.open("Staircase.txt");
			for(int i=0;i<rows;i++){
				for(int j=0;j<cols;j++)
					infile>>noskipws>>map[i][j];
			}
			infile.close();
			PrintMap();
			break;
		case'i': case'I':
			infile.open("Glacier.txt");
			for(int i=0;i<rows;i++){
				for(int j=0;j<cols;j++)
					infile>>noskipws>>map[i][j];
			}
			infile.close();
			PrintMap();
			break;
		case'j': case'J':
			infile.open("Dome.txt");
			for(int i=0;i<rows;i++){
				for(int j=0;j<cols;j++)
					infile>>noskipws>>map[i][j];
			}
			infile.close();
			PrintMap();
			break;
		default:
			PrintFullMap();
			cout << "You've got to pick one of the destinations" << endl;
			break;
	}
}