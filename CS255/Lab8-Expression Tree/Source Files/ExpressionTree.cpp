// ExpressionTree.cpp
// Expression Tree Source
// By: Patrick Lindsay & Zach Gray

#include "ExpressionTree.h"

//*****************************************//
//Function Name: Default Node Constructor  //
//Return Type: ExprTreeNode				   //
//Parameters: Char for dataItem            //
//			  ExprTreeNode* for left child //
//			  ExprTreeNode* for right child//
//Purpose: Creates an Expression Tree Node //
//*****************************************//
template<typename DataType>
ExprTree<DataType>::ExprTreeNode::ExprTreeNode(char elem, ExprTreeNode *leftPtr, ExprTreeNode *rightPtr){
	dataItem=elem;
	left=leftPtr;
	right=rightPtr;
}

//*****************************************//
//Function Name: Default Tree Constructor  //
//Return Type: ExprTree					   //
//Parameters: [None]					   //
//Purpose: Creates an ExprTree with a root //
//		   that points to NULLs			   //
//*****************************************//
template<typename DataType>
ExprTree<DataType>::ExprTree (){
	root=new ExprTreeNode(NULL, NULL, NULL);
}

//*****************************************//
//Function Name: ExprTree Copy Constructor //
//Return Type: ExprTree					   //
//Parameters: ExprTree					   //
//Purpose: Creates a copy of the "source"  //
//		   ExprTree						   //
//             [Recursive]				   //
//*****************************************//
template<typename DataType>
ExprTree<DataType>::ExprTree(const ExprTree& source){
	ExprTreeNode* fakeRoot=source.root;
	copyHelper(root, fakeRoot);
}

//*****************************************//
//Function Name: CopyHelper                //
//Return Type: Void						   //
//Parameters: Root nodes for Copy Constr   //
//Purpose: Helper to Copy Constructor      //
//             [Recursive]				   //
//*****************************************//
template<typename DataType>
void ExprTree<DataType>::copyHelper(ExprTreeNode*& node1, ExprTreeNode*& node2){
	if(!node2){node1=NULL; return;}
	node1=new ExprTreeNode(node2->dataItem, NULL, NULL);
	if(node2->left)
		copyHelper(node1->left, node2->left);
	if(node2->right)
		copyHelper(node1->right, node2->right);
}

//*****************************************//
//Function Name: Operator=                 //
//Return Type: ExprTree&				   //
//Parameters: Source ExprTree              //
//Purpose:Overloads the assignment operator//
//             [Recursive]				   //
//*****************************************//
template<typename DataType>
ExprTree<DataType>& ExprTree<DataType>::operator=(const ExprTree& source){
	if(!source.root){root=NULL; return *this;}
	root=new ExprTreeNode(source.root->dataItem, NULL, NULL);
	if(source.root->left)
		root->left=new ExprTreeNode(source.root->left);
	if(source.root->right)
		root->right=new ExprTreeNode(source.root->right);
}

//*****************************************//
//Function Name: Destructor                //
//Return Type: ExprTree					   //
//Parameters: [None]					   //
//Purpose: Destroys ExprTree			   //
//             [Recursive]				   //
//*****************************************//
template<typename DataType>
ExprTree<DataType>::~ExprTree (){
	if(root!=NULL)
		destructHelp(root);
}

//*****************************************//
//Function Name: DestructHelp			   //
//Return Type: Void						   //
//Parameters: ExprTreeNode*                //
//Purpose: Helper for Destructor		   //
//             [Recursive]				   //
//*****************************************//
template<typename DataType>
void ExprTree<DataType>::destructHelp(ExprTreeNode *head){
	if(head->left!=NULL)
		destructHelp(head->left);
	if(head->right!=NULL)
		destructHelp(head->right);
	delete head;
}

/********************************************
 For the purpose of this program, we 
 assume that all expressions are entered
 in the proper format.
 (i.e., [operator][space][num1][space][num2])
 *********************************************/

//*****************************************//
//Function Name: Build					   //
//Return Type: Void						   //
//Parameters: [None]					   //
//Purpose: Takes input from the user and   //
//		   uses that input to build an     //
//		   ExprTree.					   //
//             [Recursive]				   //
//*****************************************//
template <typename DataType>
void ExprTree<DataType>::build(){
	string input;
	int index=-1;
	getline(cin,input);
	buildHelper(root, input, index);
}

#if !LAB8_TEST1
//*****************************************//
//Function Name: BuildHelper			   //
//Return Type: Void						   //
//Parameters: ExprTreeNode*& root          //
//			  string input (user input)    //
//            int index					   //
//Purpose: Helps Build create an ExprTree. //
//		   Makes use of a root, left, right//
//		   traversal to place user input   //
//		   into appropriate nodes in the   //
//		   tree.						   //
//         This version is meant to		   //
//		   work with generic DataTypes.    //
//             [Recursive]				   //
//*****************************************//
template<typename DataType>
void ExprTree<DataType>::buildHelper(ExprTreeNode*& head, string& input, int& index){
	++index;
	if(input[index]!= ' '){
		head=new ExprTreeNode(input[index], NULL, NULL);
		if(input[index]=='+'|| input[index]=='-' || input[index]=='*' || input[index]=='/'){
			buildHelper(head->left, input, index);
			buildHelper(head->right, input, index);
		}
	}
	else
		buildHelper(head, input, index);
}
#endif

#if LAB8_TEST1
//*****************************************//
//Function Name: BuildHelper			   //
//Return Type: Void						   //
//Parameters: ExprTreeNode*& root          //
//			  string input (user input)    //
//            int index					   //
//Purpose: Helps Build create an ExprTree. //
//		   Makes use of a root, left, right//
//		   traversal to place user input   //
//		   into appropriate nodes in the   //
//		   tree.						   //
//         This version is for bool        //
//         ExprTrees only.				   //
//             [Recursive]				   //
//*****************************************//
template <typename DataType>
void ExprTree<DataType>::buildHelper(ExprTreeNode*& head, string& input, int& index){
	++index;
	if(input[index]!= ' '){
		head=new ExprTreeNode(input[index], NULL, NULL);
		if(input[index]=='+'|| input[index]=='*'){
			buildHelper(head->left, input, index);
			buildHelper(head->right, input, index);
		}
		else if(input[index]=='-'){
			head->left = NULL;
			head->right=input[++index];
		}
	}
	else
		buildHelper(head, input, index);
	return 0;
}
#endif

//*****************************************//
//Function Name: Expression				   //
//Return Type: Void						   //
//Parameters: [None]					   //
//Purpose: Puts the Expression into the    //
//		   form of a normal algebraic expr //
//             [Recursive]				   //
//*****************************************//
template <typename DataType>
void ExprTree<DataType>::expression () const{
	if(root != NULL){
		string express = "";
		express_help(root, express);
		cout << express << endl;
	}
}

//*****************************************//
//Function Name: Express Help              //
//Return Type: Void						   //
//Parameters: ExprTreeNode*, String        //
//Purpose: Helper for Expression           //
//             [Recursive]				   //
//*****************************************//
template <typename DataType>
void ExprTree<DataType>::express_help (const ExprTreeNode* head, string& express)const{
	if(head->dataItem == '+' || head->dataItem == '-' || head->dataItem == '*' || head->dataItem == '/')
		express += '(';
	if(head->left != NULL){
		express_help(head->left, express);
	}
	express += head->dataItem;
	if(head->right != NULL){
		express_help(head->right, express);
	}
	if(head->dataItem == '+' || head->dataItem == '-' || head->dataItem == '*' || head->dataItem == '/')
		express += ')';
}

//*****************************************//
//Function Name: Evaluate                  //
//Return Type: DataType					   //
//Parameters: [None]					   //
//Purpose: Evaluates the expression for a  //
//		   numeric solution.			   //
//             [Recursive]				   //
//*****************************************//
template <typename DataType>
DataType ExprTree<DataType>::evaluate() const{
	ExprTree copy=*this;
	return evaluate_helper(copy.root, copy.root->dataItem);
}

#if !LAB8_TEST1
//*****************************************//
//Function Name: Evaluate Helper           //
//Return Type: DataType					   //
//Parameters: Char of operation            //
//			  ExprTreeNode*				   //
//Purpose: Helper for Evaluate. This       //
//		   version is for mathematical     //
//         expressions.					   //
//             [Recursive]				   //
//*****************************************//
template <typename DataType>
DataType ExprTree<DataType>::evaluate_helper(ExprTree::ExprTreeNode *head, char op)const{
	DataType x,y;
	if(head->left)
		x=evaluate_helper(head->left, head->dataItem);
	if(head->right)
		y=evaluate_helper(head->right, head->dataItem);
	switch(head->dataItem){
		case '+':
			return (x+y); break;
		case '-':
			return (x-y); break;
		case '*':
			return (x*y); break;
		case '/':
			if(y!=0){
				return (x/y); break;
			}
			else{
				cout<<"Error, cannot divide by 0.\n";
				exit(1);
			}
		case '0':
			return int(head->dataItem)-48;
		case '1':
			return int(head->dataItem)-48;
		case '2':
			return int(head->dataItem)-48;
		case '3':
			return int(head->dataItem)-48;
		case '4':
			return int(head->dataItem)-48;
		case '5':
			return int(head->dataItem)-48;
		case '6':
			return int(head->dataItem)-48;
		case '7':
			return int(head->dataItem)-48;
		case '8':
			return int(head->dataItem)-48;
		case '9':
			return int(head->dataItem)-48;
		default:
			exit(2);
	}
}
#endif

#if LAB8_TEST1
//*****************************************//
//Function Name: Evaluate Helper           //
//Return Type: Bool						   //
//Parameters: ExprTreeNode*                //
//Purpose: Helper for evaluate. This       //
//		   version is for boolean	       //
//         expressions only.			   //
//             [Recursive]				   //
//*****************************************//
template <typename DataType>
bool ExprTree<DataType>::evaluate_helper(ExprTreeNode* head) const{
	DataType x,y;
	if(head->left)
		x=evaluate_helper(head->left);
	if(head->right)
		y=evaluate_helper(head->right);
	if(root->dataItem == '+')
		if(root->left->dataItem ==1 || root->right->dataItem== 1)
			return true;
		else
			return false;
		else if(root->dataItem == '-')
			if(root->right->dataItem == '0')
				root->dataItem = '1';
			else
				root->dataItem = '0';
			else if(root->dataItem == '*'){
				if(root->left->dataItem == '1' && root->right->dataItem == '1')
					return true;
				else
					return false;
			}
			else
				return false;
}
#endif

//*****************************************//
//Function Name: Clear					   //
//Return Type: Void						   //
//Parameters: [None]					   //
//Purpose: Clears the tree				   //
//             [Recursive]				   //
//*****************************************//
template <typename DataType>
void ExprTree<DataType>::clear (){
	if(root != NULL){
		clear_help(root);
	}
}

//*****************************************//
//Function Name: Clear Help                //
//Return Type: Void						   //
//Parameters: ExprTreeNode*                //
//Purpose: Helper for Clear				   //
//             [Recursive]				   //
//*****************************************//
template <typename DataType>
void ExprTree<DataType>::clear_help(ExprTreeNode *root){
	if(root->left != NULL)
		clear_help(root->left);
	if(root->right != NULL)
		clear_help(root->right);
	root->dataItem=NULL;
	root->left=NULL;
	root->right=NULL;
}

//=========================================//
//Function Name: Commute				   //
//Return Type: Void						   //
//Parameters: [None]					   //
//Purpose: Mirror's the Tree			   //
//             [Recursive]				   //
//*****************************************//
template <typename DataType>
void ExprTree<DataType>::commute(){
	ExprTree newTree=*this;
	ExprTreeNode* temp;
	if(root->left && root->right){
		commuteHelper(root->left, root->right);
		commuteHelper(root->right, root->left);
	}
	temp=root->left;
	root->left=root->right;
	root->right=temp;
}

//*****************************************//
//Function Name: Commute Helper			   //
//Return Type: Void						   //
//Parameters: ExprTreeNode* for Orig Tree  //
//            ExprtreeNode* for Copy Tree  //
//Purpose: Helper for Commute			   //
//             [Recursive]				   //
//*****************************************//
template <typename DataType>
void ExprTree<DataType>::commuteHelper(ExprTreeNode*& head, ExprTreeNode*& copyHead){
	ExprTreeNode* temp;
	if(head->left){
		commuteHelper(head->left, head->right);
	}
	if(head->right){
		commuteHelper(head->right, head->left);
	}
	temp=head->left;
	head->left=head->right;
	head->right=temp;
}

//*****************************************//
//Function Name: isEquivalent              //
//Return Type: Bool						   //
//Parameters: [None]					   //
//Purpose: Checks to see if two expressions//
//         are equivalent, without them    //
//		   having to be identical (i.e.,   //
//		   1+2=2+1)						   //
//*****************************************//
template <typename DataType>
bool ExprTree<DataType>::isEquivalent(const ExprTree& source) const{
	bool flag = true;
	if(root&&source.root)
		isEquiv_help(root, source.root, flag);
	if((root->dataItem==NULL&&source.root->dataItem!=NULL)||(root->dataItem!=NULL&&source.root->dataItem==NULL))
		flag=false;
	return flag;
}

//*****************************************//
//Function Name: isEquiv Help              //
//Return Type: Void						   //
//Parameters: ExprTreeNode* Original TreeNd//
//			  ExprTreeNode* Other Tree Node//
//            bool& result ("flag")        //
//Purpose: Helper for isEquivalent         //
//             [Recursive]				   //
//*****************************************//
template <typename DataType>
void ExprTree<DataType>::isEquiv_help(const ExprTreeNode *head, ExprTreeNode *copy, bool& flag)const{
	if(head->dataItem==copy->dataItem){
		if(head->dataItem=='+'||head->dataItem=='-'||head->dataItem=='*'||head->dataItem=='/'){
			if(head->dataItem=='+'||head->dataItem=='*'){
				if(head->left->dataItem==copy->right->dataItem&&head->right->dataItem==copy->left->dataItem){
					ExprTreeNode *temp;
					temp=copy->left;
					copy->left=copy->right;
					copy->right=temp;
				}
				if(head->left->dataItem==copy->left->dataItem)
					isEquiv_help(head->left, copy->left, flag);
				else
					flag=false;
				if(head->right->dataItem==copy->right->dataItem)
					isEquiv_help(head->right, copy->right, flag);
				else
					flag=false;
			}
			else if(head->dataItem=='-'||head->dataItem=='/'){
				if(head->left->dataItem==copy->left->dataItem)
					isEquiv_help(head->left, copy->left, flag);
				else
					flag=false;
				if(head->right->dataItem==copy->right->dataItem)
					isEquiv_help(head->right, copy->right, flag);
				else
					flag=false;
			}
		}
	}
}

//*****************************************//
//Function Name: isEmpty                   //
//Return Type: Bool						   //
//Parameters: [None]					   //
//Purpose: Checks to see if an ExprTree is //
//		   empty.						   //
//*****************************************//
template <typename DataType>
bool ExprTree<DataType>::isEmpty()const{
	bool empty=false;
	if(root==NULL && root->left==NULL && root->right==NULL)
		empty=true;
	return empty;
}

//**************************************************************************//
//Function Name: ShowStructure												//
//Return Type: Void															//
//Parameters: [None]														//
//Purpose: Outputs an expression tree. The tree is output rotated counter-	//
//    clockwise 90 degrees from its conventional orientation using a		//
//    "reverse" inorder traversal. This operation is intended for testing	//
//    and debugging purposes only.											//
//								[Recursive]									//
//			***Provided by C++ Data Structures, Third Edition***			//
//**************************************************************************//
template <typename DataType>
void ExprTree<DataType>:: showStructure () const{
    if ( isEmpty() )
		cout << "Empty tree" << endl;
    else
    {
		cout << endl;
		showHelper(root,1);
		cout << endl;
    }
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

//**************************************************************************//
//Function Name: ShowHelper													//
//Return Type: Void															//
//Parameters: ExprTreeNode* p, Int level									//
//Purpose: Recursive helper for the showStructure() function. Outputs the	//
// subtree whose root node is pointed to by p. Parameter level is the		//
// level of this node within the expression tree.							//
//								[Recursive]									//
//          ***Provided by C++ Data Structures, Third Edition***			//
//**************************************************************************//
template <typename DataType>
void ExprTree<DataType>:: showHelper ( ExprTreeNode *p, int level ) const{
	int j;   // Loop counter
	
	if ( p != 0 )
	{
        showHelper(p->right,level+1);        // Output right subtree
        for ( j = 0 ; j < level ; j++ )   // Tab over to level
            cout << "\t";
        cout << " " << p->dataItem;        // Output dataItem
        if ( ( p->left != 0 ) &&          // Output "connector"
			( p->right != 0 ) )
			cout << "<";
        else if ( p->right != 0 )
			cout << "/";
        else if ( p->left != 0 )
			cout << "\\";
        cout << endl;
        showHelper(p->left,level+1);         // Output left subtree
	}
}

