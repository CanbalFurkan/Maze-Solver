#include <iostream>
#include "dynintstack.h"
using namespace std;

//************************************************
// Constructor to generate an empty stack.       *
//************************************************
DynIntStack::DynIntStack()
{
	top = NULL; 
}

//************************************************
// Member function push pushes the argument onto *
// the stack.                                    *
//************************************************
void DynIntStack::push(int xcordinate,int ycordinate)
{
	StackNode *newNode;

	// Allocate a new node & store Num
	newNode = new StackNode;
	newNode->xcoord = xcordinate;
	newNode->ycoord = ycordinate;

	// If there are no nodes in the list
	// make newNode the first node
	if (isEmpty())
	{
		top = newNode;
		newNode->next = NULL;
	}
	else	// Otherwise, insert NewNode before top
	{
		newNode->next = top;
		top = newNode;
	}
}

//****************************************************
// Member function pop pops the value at the top     *
// of the stack off, and copies it into the variable *
// passed as an argument.                            *
//****************************************************
void DynIntStack::pop(int &newx, int &newy, int &checker)
{
	StackNode *temp;

	if (isEmpty())
	{
		
		checker = -1;     //if stack is empty checker become -1 and its trigger break point
	}
	else	// pop value off top of stack
	{
		newx = top->xcoord;
		newy = top->ycoord;
		temp = top->next;
		delete top;
		top = temp;
	}
}

//****************************************************
// Member funciton isEmpty returns true if the stack *
// is empty, or false otherwise.                     *
//****************************************************
bool DynIntStack::isEmpty(void)
{
	bool status;

	if (top == NULL)
		status = true;
	else
		status = false;

	return status;
}



void DynIntStack::printListInverse()
{
	if (head != NULL)
	{															//printing stack in a inverse way
		printListInverse(top);
	}
}


void DynIntStack::printListInverse(StackNode *n)
{
	if (n->next != NULL)
	{
		printListInverse(n->next);
	}
	cout << n->xcoord<<" "<<n->ycoord << endl;
}
