// This program demonstrates the dynamic stack
// class DynIntStack.
#include <iostream>
#include "DynIntStack.h"
#include<fstream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;




void mazesolver(vector<vector<string>> mat, DynIntStack &stack,int endx,int endy,int &checker){

	checker = 0; 
	int a = 0;
	int b = 0;
	bool finish = true;
	string X = "X";
	
	
	while ((a != endy - 1 || b != endx - 1)) { //condition of while = x=m-1 or y=n-1

		//These funtions check  surrondings of  current cordinates

		if (a+1 !=endy && mat[a+1][b]==X) {  //statements for avoiding "range of vector" error and looking for x
			stack.push(a + 1, b);              //current cordinates pushed to stack
			mat[a + 1][b] = 'Y';         //This cordinate mark as visited.Now there is a Y in this cordinate and i cant visit this cordinate again until i popup.
			a++;
			
			
		}
		else if (b+1!=endx  && mat[a][b + 1] == X) {
			stack.push(a, b + 1);
			mat[a][b + 1] = 'Y';
			b++;
			
		}
		else if (a-1!=-1 && mat[a - 1][b] == X) {

			stack.push(a - 1, b);
			mat[a - 1][b] = 'Y';
			a--;
		}
		else if (b-1!=-1
			&& mat[a][b - 1] ==X) {

			stack.push(a, b - 1);
			b--;

		}
		else {
			int popx;
			int popy;
			
			
			stack.pop(popx, popy, checker);      // Taking last cordinates back from stack and at the same time im sending a checker.If all stack is empty checker become -1 and it breaks.
			a = popx;
			b = popy;
			if (checker == -1) { break; }
			
												
			



		}
	}

}







int main()
{
    DynIntStack stack;
	
    
	int endx;
	int endy;
	string yatay;
	int checker = 0;

	string fileName;
	int j, k;
	vector<vector<string>> mat;      //create a matrix
	cout << "Enter the input file name" << endl;
	cin >> fileName;

	ifstream input;
	input.open(fileName);

	if (input.fail())
	{
		cout << "Could not open the file " << fileName << endl;   //check if the input data is opened
		return 0;
	}

	string line;
	input >> endy >> endx;   //taking size of matrix from input


	for (int i = 0;i < endy;i++){
		vector<string> temp;
		input >> line;
		
		//taking a line into realline string




		for (int m = 0;m < endx;m++) {


			yatay =line.at(m);  //taking every realline letter to yatay
			temp.push_back(yatay); //puting letter to temp vector



		}

	mat.push_back(temp); // passsing to next row
	}
	stack.push(0, 0);  //pushing 0,0
	mazesolver(mat, stack, endx, endy,checker);


	if (stack.isEmpty()) {

		cout << "Solution NOT found!" << endl;  //if stack is empty,funkction will right "solution not found"



	}
	else {

		
		cout << "Solution found:" << endl;
		stack.printListInverse();  //printing solution way


	}






	



	
	system("pause");
    



	return 0;
}