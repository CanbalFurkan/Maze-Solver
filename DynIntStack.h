struct StackNode
{
	int xcoord;    //Node hold x and y cordinates
	int ycoord;
	StackNode *next;
};

class DynIntStack
{
private:
	StackNode *top;
	StackNode *head;         
	void printListInverse(StackNode *n);

public:
	DynIntStack(void);
	void push(int,int);
	void pop(int &, int &, int &);
	bool isEmpty(void);
	void printListInverse();
};
