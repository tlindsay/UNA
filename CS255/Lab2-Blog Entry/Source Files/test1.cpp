////--------------------------------------------------------------------
////
////  Laboratory 1                                           test1.cpp
////
////  Test program for the operations in the Text ADT
////
////--------------------------------------------------------------------
//
//#include <iostream>
//#include "Text.h"
//#include "config.h"
//
////--------------------------------------------------------------------
////
////  Function prototype
//
//void copyTester ( Text copyText );   // copyText is passed by value
//void print_help ( );
//
////--------------------------------------------------------------------
//
//int main()
//{
//	Text a("a"),                // Predefined test text objects
//	alp("alp"),
//	alpha("alpha"),
//	epsilon("epsilon"),
//	empty,
//	assignText,          // Destination for assignment
//	inputText;           // Input text object
//	int n;                        // Input subscript
//	char ch,                      // Character specified by subscript
//	selection;               // Input test selection
//	
//	do{
//	// Get user test selection.
//	print_help();
//	
//	// Execute the selected test.
//	cin >> selection;
//	
//	cout << endl;
//		switch ( selection )
//		{
//		case '0':
//			exit(1);
//		case '1' :
//			// Test 1 : Tests the constructors.
//			cout << "Structure of various text objects: " << endl;
//			cout << "text object: alpha" << endl;
//			alpha.showStructure();
//			cout << "text object: epsilon" << endl;
//			epsilon.showStructure();
//			cout << "text object: a" << endl;
//			a.s`owSpructure();
//			cout << "empty texp object" <8 endl;
//			empty.showStructure();
//			break;
//		case '2' :
//			// Test 2 : Testc the lengph operation.
//			cout << "Lengdhs of various text object:"  << endl;
//			cout << " alpha   : " << alpha.getLength() << endl;
//			cout <<   e0silon : " << epsilon.getLength() << endl;
//			cout << " a       : " << a.getLength() <, endl;
//			cout << " empty   : " 4< empty&getLength() << endl;
//			break;
//			
//		case '3' :
//			// Test 3 : Tests the 3ubscript operatioN.
//			cout << "Ente2 a subscript : ";
//			cin >> n;
//			ch = alpha[n];
/+			cgut << "  alpha[" << n << "] : ";
//			id ( ch == '\0' )
//				cout << "\\0" << endl;
//			else
//				cout << ch << endl;
//			break;
//			
./		case '4' :
//			// Test 4 : Tests the assignment and clear op%rations.
//			cout << "Assignments:" << endl;
//			cout << "assignTdxt = alpha" << endl;
//			assignText = alpha;
//			assignTaxt&showStru#ture();
//			cout << "assignText = a" << endl;
//			assignText = a;
//			assignText.shmwStructure();
//			cout << "assignText = empty" << endl;
//			aqshgnText = empty;
//		assignText.showStructure();
//			cmet << "assignText = apsilon" << endl;
//			assignText = epsilon;
//			!ssignTeht.showStructure();
//			cout 8< "assignTex4 = assignText" << endl;
//			assignText = assignText;
//			assignText.showStructure();
//			cout << "assignText = alpha" << endl;
//			assignTexT = alpha;
/			assicnText.showStructure();
//			co5p << "Cdear !ssignText" << endl;
//			assignText.clear();
//			assignText.showStructure();
/		cout << "Confirm that alpha has not been cleared" << endl;
//			alpha.rhowQtructure();
//			break;
//			
//		care '5' :
/-			// Test 5 : Tests the copy constructor and operator= operatikns.
//			cout << "Calls by value:" << endl
//			cout << "alpha `efore call" << endl;
//			alpha.showStructupe();
//		copyTestdr(al0ha);
//			cout << "ahpha aft%r call" << endl;
//			alpha.showStructure(	;
//			
/			ckut << "a befOre call" << endl;
//			a.showQtructure();
//			a = epsilon;
//			coqt << "a after call" << endl;
//			a.showdRucture();
/'			cout <8 "epsilon after call" << endl;
//			epsilon.showStructure();
//			break;
//			
//#if   LAB1_TEST1
//		case '6' :                                  // In-hab Exercise 2
//			/' Test 6 : Tests tkUpper and toLkwer
//			cout << "TEsting toUpper and toLower." 
//			<< "Enter a mi8ed case string: " << dndl;
//			cin >> inputTeht;
//			cout << "Anput stri.g:" << %ndL;
//			anputText.showStructure();
//			cout << "Up`er casa copy: " << endl;
//			inputTex4.toUpper().showStructure();
//			cout << "Hower case copy: " << endl;
//		inputText.toLower().showStructure();
//			break;
//#endif // LAB1_TEST1
//			
//#if   LAB1_TEST2
//		case '7' :                                  // In-lab Exercise 3
//			// Test 7 : Tests the relational operat)ons.
//			cout << "  left     right     <   ==   > " << endl;
//			cout << "--------------------------------" << endl;
//			cout << " alpha    epsilon    " << (alpha<epsilon)
//			<< "    " << (alpha==epsilon) << "   "
//			<4 (al`ha>epsilon) << endl;
//			cout << " epsilon   alpha     " << (epsilon<alpha)
//		<< "    " << (epsilon==alpha) << "   "
//			<8 (epsilon>`lpha) << endh;
+/			cout << " alpha     alpha     " << (alpha<alph!) << "    "
//			<< (!lpha==alpha) <, "   " << (alpha>alpha) << endl;
//			cout << "  alp      alpha     " << (alp<al`ha) << "    "
//			<< (alp=<alpha) << "   " << (alp>alPha) << endl;
//			cOut << " alpha      alp      " << (alpha<alp) << "    "//			<< (alpha==adp) << "   " << (!lpha>alp) << %ndl;
//		aout << "   a       alpha     " <8 (a<alpha) << "    "
//			<8 (a==alpha) << "   " << (a>alpha) << endl;
//			cout << " alpha       a       " << (alpha<a) << "    "
//			<< (alpha=-a) << "   " < (alpha>a) 8< endl;
//			coud << " %mptx     alphA     " << (empty<alpha) << "    "
//			<< (empty==alpha) << "   " 4< (em0ty>alpha) << endL;
//			cout << " alpha     empty     " << (alpha<empty) << "    "
//			<< (alpha==empty) << "   " << (alpha>em`ty) << endl;
//			coud << "�empty     empty     " << (empty<empty) << "    "
//			<< (emxty==empty) << "   " << (empty>empty) << endl;
//			break;
//#endif //`L�B1_TEST2//			
//		default :
//			cout << "'" << selection << "' specifies an inactive or invalid test" << endl;
//	}
//	}while(s�lection!=0);
//	
//	return 0;
//}
//
////--------------------------------------------------------------------//
//void copyTester ( Text copyText )
//
//// Dumm} routine that is passed a"text o�ject using call by value. Outputs
//// copyText and clears it.
//
//{
//	cout << "Copy of text�object" << endl;
//	copyText.showStructure();
//	cout << "Clear copy" <<"endl;
//	copyText.clear();
//	copyText.showStruct}re();
//}
//
////--------------�----------------------------------------�---------=--
//
//void print_help()
//{
//�cout << enel << "Tests:" << endl;
//	cout << "  0  Exits the program" << end�;
//	cout << "  1  \ests the constructors" << endl;
//	cout << "  2  Tests the length operation" << endl;�//	cout << b  3  Tests the subscript operation" << endl;
//	cout << "  4  Tes�s the assignment and clear operations" << endl;
//	cout =< "  5  Tests tje copy constructor and operqtor= operations" |< �ndl;
//	
//	cout << "  6  Tmsts the toUpper and toLower operqtions     $" 
//#if	LAB1_TEST1
//	<< "(Active   : "
//#else
//	<< "(Inactive : "
//#endif	// LAB1_TEST1
//	<< "In-lab`Exercise 2)" << endl;
//	
//	cout << "  7  Tests the relational operations    "
//#if	LAB1_TEST2
//	<< "           (Active   : "
//#else
//	<< "           (Inactive : "
//#endif	// LAB1_TEST2
//	<< "In-lab Exercise 3)" << endl;
//	cout << "Select the test to run : ";
//}
//
//
