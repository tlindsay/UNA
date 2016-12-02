#include "Graph.h"
#include "Vertex.h"
#include "MinHeap.h"
#include "ParkMap.h"

//template <typename DataType>
void Dijkstra(Graph<Vertex>& graph,  MinHeap<Vertex>& heap, int source, int destination, int numVertices);


int main(){
    
    string vertexName;
    Vertex tmp;
    
    // Creates a heap with capacity for 11 vertices
    MinHeap<Vertex> minHeap(11); 
    
	//creating a graph with 12 vertices
	Graph<Vertex> g(11);
    
	//input file that will contain costs
	string file = "ForrestPathCost.txt";
	
    
	
	//*********************************************************************
	char userInput=0;
	while(userInput!='3'){
		g.inputGraphMatrix(file);
		// input file that contains names and sets index values for vertices
		ifstream iFile;
		iFile.open("Vertices.txt");
		//----------------------------------------------------------------

	
    
		for (int i = 0; i < 11; i++) {
			getline(iFile, vertexName);
			tmp.setString(vertexName);
			tmp.setIndex(i);
			g.inputGraphArray(i, tmp);
		}
    
		ParkMap map;
		string stars="*******************************************************************************";
		cout<<stars<<endl;
		cout<<"   The Yosemite Shortest Path Calculator."<<endl;
		cout<<"   This program will help you find the shortest path so that you can"<<endl;
		cout<<"   see quickly get to Sasquatch before he runs off again! Option 1"<<endl;
		cout<<"   let's you see the path from your base at the Yosemite Lodge to"<<endl;
		cout<<"   any other landmark in the great Yosemite National Park. Option 2"<<endl;
		cout<<"   will help you find Sasquatch if you happen to be out in the woods"<<endl;
		cout<<"   when Sasquatch is sighted. It lets you choose where you are and"<<endl;
		cout<<"   then asks where Sasquatch is at. This program runs best when the"<<endl;
		cout<<"   window is maximized, so please maximize the window."<<endl;
		cout<<stars<<endl;
		cout<<"1. Shows the shortest path from the Lodge to Sasquatch's destination. "<<endl;
		cout<<"2. Helps find the shortest path between any two locations at Yosemite."<<endl;
		cout<<"3. Exit Program"<<endl;
		cout<<stars<<endl;

		cin>>userInput;

		switch (userInput)
		{
		case '1':
			char choice;
			system("cls");
			map.PrintFullCost();
			cout << "Where is Sasquatch?" << endl;
			cout << "A. Yosemite Village"<<endl;
			cout << "B. The Ahwahnee"<<endl;
			cout << "C. Mirror Lake"<<endl;
			cout << "D. Swinging Bridge"<<endl;
			cout << "E. Royal Arches"<<endl;
			cout << "F. Sentinel Beach"<<endl;
			cout << "G. Union Point"<<endl;
			cout << "H. Staircase Falls"<<endl;
			cout << "I. Glacier Point"<<endl;
			cout << "J. Sentinel Dome"<<endl;
			cin>>choice;
			if(choice>='a' && choice<='j')
				choice=choice-32;
			while(choice<'A' || choice>'J'){
				cout << "Invalid Choice. Please choose a valid option from the menu." << endl;
				cin >> choice;
				if(choice>='a' && choice<='j')
					choice=choice-32;
			}
			system("cls");
			map.PrintPath(choice);
			cout << endl;
			Dijkstra(g, minHeap, 0, (int(choice)-64), 11);
			system("pause");
			break;

		case '2':
			char source;
			char destination;
			system("cls");
			map.PrintFullMap();
			cout << "A. Yosemite Lodge"<<endl;
			cout << "B. Yosemite Village"<<endl;
			cout << "C. The Ahwahnee"<<endl;
			cout << "D. Mirror Lake"<<endl;
			cout << "E. Swinging Bridge"<<endl;
			cout << "F. Royal Arches"<<endl;
			cout << "G. Sentinel Beach"<<endl;
			cout << "H. Union Point"<<endl;
			cout << "I. Staircase Falls"<<endl;
			cout << "J. Glacier Point"<<endl;
			cout << "K. Sentinel Dome"<<endl;
			cout << endl;
			cout << "Please choose your starting point." << endl;
			cin>>source;
			if(source>='a' && source<='k')
				source=source-32;
			while(source<'A' || source>'K'){
				cout << "Invalid Choice. Please choose a valid option from the menu." << endl;
				cin >> source;
				if(source>='a' && source<='k')
					source=source-32;
			}
			cout << "And now choose your destination." << endl;
			cin>>destination;
			if(destination>='a' && destination<='k')
				destination=destination-32;
			while(destination<'A' || destination>'K'){
				cout << "Invalid Choice. Please choose a valid option from the menu." << endl;
				cin >> destination;
				if(destination>='a' && destination<='k')
					destination=destination-32;
			}
			system("cls");
			map.PrintFullCost();
			cout << endl;
			Dijkstra(g, minHeap, (int(source)-65), (int(destination)-65), 11);
			system("pause");
			break;

		case '3':
			break;
		default:
			cout << "Invalid Choice. Please choose a valid option from the menu." << endl;
			system("pause");
			break;
		}
		system("cls");
		iFile.close();
	}
	//****************************************************************************

    // Star menu implemenation
    //PrintMenu(tmp,minHeap);

    //Dijkstra(g, minHeap, 0, 4, 11);
	
    system("pause");
	return 0;
}
//------------------------------------------------------------------------------
// FUNCTION DECLARATIONS
//------------------------------------------------------------------------------





//------------------------------------------------------------------------------
// Dijkstra
//------------------------------------------------------------------------------
//template <typename DataType>
void Dijkstra (Graph<Vertex>& graph,  MinHeap<Vertex>& heap, int source, int destination, int numVertices){
    Vertex temp;
    Vertex u;
    
    int cost;
    int current;
    
    // Initializes Vertices and sets those vertices that are adjacent to the source
    // to have the proper weights. Updates the changes in the vertex array. Inserts
    // all vertices into the min heap except for the source.
    for (int i = 0; i < numVertices; i++) {
        temp = graph.getItem(i);
        cost = graph.getMatrixValue(source, i);
        temp.setDistance(cost);
        if (cost != 100 && cost != 0) {
            temp.setChanged(source);
        }
        graph.inputGraphArray(i, temp);
        if (i != source)
            heap.insert(temp);
    }
    
    // Main portion of Dijkstra algorithm
    
    // Loop while the heap is not empty
    while ( ! heap.isEmpty() ) {
        
        // Sets u to be the minimum value vertex from the heap and then removes the min from the heap.
		// Sets current to hold the min's index.
        u = heap.getMin();
        heap.removeMin();
        current = u.getIndex();
        
        // Main portion of Dijkstra's
        
        // Go through every vetex
        for (int i = 0; i < numVertices; i++) {
            
            // If the edge weight between the current min and the vertex indicated by i is not equal to 100 (infinity)
            // or 0 (would indicate min and i are the same) then proceed.
            if (graph.getMatrixValue(current, i) != 100 && graph.getMatrixValue(current, i) != 0) {
                
                // If the edge weight between the source and the vertex indicated by i is greater than the edge weight
                // between the current min vertex and the vertex indicated by i plus the min's distance to the source, then
                // we have found a shorter path between the source and the vertex indicated by i. We then take
                // appropriate action to update our vertices and matrix to reflect this new shorter path.
                if (graph.getMatrixValue(source, i) > (graph.getMatrixValue(current, i) + u.getDistance())) {
                    
                    // Gets the vertex we have found a new shorter path to from the vertex array.
                    temp = graph.getItem(i);
                    
                    // Sets its distance to orign to reflect the new shorter cost.
                    temp.setDistance(graph.getMatrixValue(current, i) + u.getDistance());
                    
                    // Sets its changedBy value to be the current min vertex.
                    temp.setChanged(current);
                    
                    // Modifies its values in the heap to reflect the above 2 changes
                    heap.modify(temp);
                    
                    // Inputs it back into the vertex aray with the changes
                    graph.inputGraphArray(i, temp);
                    
                    // Changes the source's line in the matrix to reflect the newfound shorter cost.
                    graph.setMatrixValue(source, i, graph.getMatrixValue(current, i) + u.getDistance());
                }
            }
        }
    }
    
    
    // Prints the shortest path from source to destination
    cout << "The shortest path from " << graph.getItem(source).getString() << " to " << graph.getItem(destination).getString()
    << " is as follows:" << endl;
    
    // We insert into an interger array the path from the destination to the source by
    // following the changedBy values from the destination to the source.
    // We will know we have gotten to the source when we encounter a changedBy value
    // of -1
    int pathArray[11];
    pathArray[0] = destination;
    int path = destination;
    int counter = 1;
    
    while (path != -1) {
        path = graph.getItem(path).getChanged();
        pathArray[counter] = path;
        counter++;
    }
    counter -= 2;
    
    // Traverse the array backwards to output the path starting from the source
    // and ending at the destination.
    while (counter >= 0) {
        int index = pathArray[counter];
        cout << graph.getItem(index).getString();
        if (counter != 0) {
            cout << " --> ";
        }
        counter--;
    }
    cout << endl;
    cout << "with a cost of " << graph.getItem(destination).getDistance() << "." << endl << endl;
}


