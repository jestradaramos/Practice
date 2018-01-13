#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main() {
	
	cout << "Hello World" << endl;

	// Data Types

	const double PI = 3.1415926535;

	char myGrade = 'A';

	bool isHappy = true;

	int myAge = 39;

	float favNum = 3.14159; // 6 decimal

	// double 15

	cout << "Fav num " << favNum << endl;

	cout << "Size of int" << sizeof(int) << endl;

	int choice = 2;

	// switch statements

	switch(choice){
	
		case 1: 
			cout << "Stuff" << endl;

		case 2:
			cout << "More stuff" << endl;
			break;
		case 3:
			cout << "Aye" << endl;
			break;
		default: 
			cout << "Default" << endl;

	}
	
	// Ternary Operator
	// var = (condition) ? true : false


	// Arrays work the same

	// for loops is also the same to what I know

	int randNum = ( rand() % 100) + 1; // Random numbers

	// While loops are the same

	string numberGuessed;
	int intGuessed = 0;

	do {

		cout << "Guess between 1 and 10: ";

		getline(cin, numberGuessed);
		intGuessed = stoi(numberGuessed);
		cout << intGuessed << endl;


	} while(intGuessed != 4);


	cout << "You win!" << endl;

	/* String functions
		.compare(anotherString)
		.empty()
		.size()
		.assign(string) 
		.assign(string, startindex, numOfChar)
		.find(substring, startIndex)
		.insert(index, string)
		.erase(numChar, startIndex)
		.replace(start, size, string)
	
	*/

	// Vectors, arrays that can change size

	vector <int> lotterNum(10);

	int lotteryArray[5] = {4, 13, 14,24, 34};

	lotterNum.insert(lotterNum.begin(), lotteryArray, lotteryArray+3);

	lotterNum.insert(lotterNum.begin() + 5, 44);

	cout << lotterNum.at(5) << endl;

	// .pushback(value) adds to end of vector
	// .pop_back() gets rid of last one
	// .front() first element
	// .empty() 0 when empty
	// .size()


	// Functions are the same, and recursion





	return 0;

}
