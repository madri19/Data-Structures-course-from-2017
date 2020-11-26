//Juan Madrigal

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "Array2D.h"
#include "Array2D_P.h"

#include <iostream>
#include <string>

using namespace std;

void constmethods_P() {

	try {

		cout << "---Creating a const instance of the Array class with 2 rows and 3 columns---" << endl << endl;

		const Array2D_P<int> test(2, 3);

		cout << "Rows: " << test.getRow() << endl;
		cout << "Columns: " << test.getColumn() << endl;

		cout << endl << "---Filling in the array with data---" << endl;

		for (auto i = 0; i < test.getRow(); i++) {

			for (auto ii = 0; ii < test.getColumn(); ii++) {

				test[i][ii] = ii + 10;
				cout << "[" << i << "][" << ii << "] = " << test[i][ii] << endl;
			}
		}
	}
	catch (Exception& ex) {

		cout << ex;

	}

}

void twodbounds_P() {


	try {

		cout << "---Creating an instance of the Array class with 2 rows and 3 columns---" << endl << endl;

		Array2D_P<int> test(2, 3);

		cout << "Rows: " << test.getRow() << endl;
		cout << "Columns: " << test.getColumn() << endl;

		cout << endl << "---Filling in the array with data---" << endl;

		for (auto i = 0; i < test.getRow(); i++) {

			for (auto ii = 0; ii < test.getColumn(); ii++) {

				test[i][ii] = ii + 10;
				cout << "[" << i << "][" << ii << "] = " << test[i][ii] << endl;
			}
		}

		cout << endl << "---Attempting to add data to an index row 4 and column 2---" << endl << endl;

		test[4][2] = 6;

		cout << endl << "---End test---" << endl;

	}
	catch (Exception& ex) {

		cout << ex;

	}


}


void mutators_P()
{

	try {
		auto count = 0;
		cout << "---Creating an instance of the Array class with 2 rows and 3 columns---" << endl << endl;

		Array2D<int> test(3, 3);

		cout << "Rows: " << test.getRow() << endl;
		cout << "Columns: " << test.getColumn() << endl << endl;

		cout << endl << "---Filling in the array with data---" << endl;

		for (auto i = 0; i < test.getRow(); i++) {

			for (auto ii = 0; ii < test.getColumn(); ii++) {

				test[i][ii] = 1 + count;
				count++;
				cout << "[" << i << "][" << ii << "] = " << test[i][ii] << endl;
			}
		}

		cout << endl << "---Setting the row to 3 and filling in data---" << endl << endl;
		//test.setRow(4);

		cout << "Rows: " << test.getRow() << endl;
		cout << "Columns: " << test.getColumn() << endl << endl;

		for (auto i = 0; i < test.getRow(); i++) {

			for (auto ii = 0; ii < test.getColumn(); ii++) {

				
				cout << "[" << i << "][" << ii << "] = " << test[i][ii] << endl;
			}
		}

		cout << endl << "---Setting the column to 2 and filling in data---" << endl << endl;
		test.setColumn(4);

		cout << "Rows: " << test.getRow() << endl;
		cout << "Columns: " << test.getColumn() << endl << endl;

		for (auto i = 0; i < test.getRow(); i++) {

			for (auto ii = 0; ii < test.getColumn(); ii++) {

				
				cout << "[" << i << "][" << ii << "] = " << test[i][ii] << endl;
			}
		}


		cout << endl << "---End test---" << endl;

	}
	catch (Exception& ex) {

		cout << ex;

	}

}


void test(){

	try {

		Array2D_P<int> test(3, 3);

		Array2D_P<int> test2(test);

		cout << test2[2][0] << endl;

	}
	catch (Exception& ex) {

		cout << ex;

	}
}


void starstarp()
{
	try{
		Array2D_P<string> test2(3, 5);

		for (auto i = 0; i < test2.getRow(); i++) {

			for (auto ii = 0; ii < test2.getColumn(); ii++) {

				test2[i][ii] = "Hello Juan!";
				cout << "[" << i << "][" << ii << "] = " << test2[i][ii] << endl;
			}
		}

		//Array2D_P<string> test3(5, 6);

		Array2D_P<string> test;
		
		test = test2;


		for (auto i = 0; i < test.getRow(); i++) {

			for (auto ii = 0; ii < test.getColumn(); ii++) {

				cout << "[" << i << "][" << ii << "] = " << test[i][ii] << endl;
			}
		}

	}
	catch (Exception& ex) {

		cout << ex;

	}
}


void constmethods() {

	try {

		cout << "---Creating a const instance of the Array class with 2 rows and 3 columns---" << endl << endl;

		const Array2D<int> test(2, 3);

		cout << "Rows: " << test.getRow() << endl;
		cout << "Columns: " << test.getColumn() << endl;

		cout << endl << "---Filling in the array with data---" << endl;

		for (auto i = 0; i < test.getRow(); i++) {

			for (auto ii = 0; ii < test.getColumn(); ii++) {

				test[i][ii] = ii + 10;
				cout << "[" << i << "][" << ii << "] = " << test[i][ii] << endl;
			}
		}
	}
	catch (Exception& ex) {

		cout << ex;

	}

}

void twodbounds() {


	try {

		cout << "---Creating an instance of the Array class with 2 rows and 3 columns---" << endl << endl;

		Array2D<int> test(2, 3);

		cout << "Rows: " << test.getRow() << endl;
		cout << "Columns: " << test.getColumn() << endl;

		cout << endl << "---Filling in the array with data---" << endl;

		for (auto i = 0; i < test.getRow(); i++) {

			for (auto ii = 0; ii < test.getColumn(); ii++) {

				test[i][ii] = ii + 10;
				cout << "[" << i << "][" << ii << "] = " << test[i][ii] << endl;
			}
		}

		cout << endl << "---Attempting to add data to an index row 4 and column 2---" << endl << endl;

		test[1][6] = 6;

		cout << endl << "---End test---" << endl;

	}
	catch (Exception& ex) {

		cout << ex;

	}


}


void mutators() {

	try {

		cout << "---Creating an instance of the Array class with 2 rows and 3 columns---" << endl << endl;

		Array2D<int> test(2, 3);

		cout << "Rows: " << test.getRow() << endl;
		cout << "Columns: " << test.getColumn() << endl;

		cout << endl << "---Filling in the array with data---" << endl;

		for (auto i = 0; i < test.getRow(); i++) {

			for (auto ii = 0; ii < test.getColumn(); ii++) {

				test[i][ii] = ii + 10;
				cout << "[" << i << "][" << ii << "] = " << test[i][ii] << endl;
			}
		}

		cout << endl << "---Setting the row to 3 and filling in data---" << endl << endl;
		test.setRow(3);

		cout << "Rows: " << test.getRow() << endl;
		cout << "Columns: " << test.getColumn() << endl;

		for (auto i = 0; i < test.getRow(); i++) {

			for (auto ii = 0; ii < test.getColumn(); ii++) {

				test[i][ii] = ii + 10;
				cout << "[" << i << "][" << ii << "] = " << test[i][ii] << endl;
			}
		}

		cout << endl << "---Setting the column to 2 and filling in data---" << endl << endl;
		test.setColumn(2);

		cout << "Rows: " << test.getRow() << endl;
		cout << "Columns: " << test.getColumn() << endl;

		for (auto i = 0; i < test.getRow(); i++) {

			for (auto ii = 0; ii < test.getColumn(); ii++) {

				test[i][ii] = ii + 10;
				cout << "[" << i << "][" << ii << "] = " << test[i][ii] << endl;
			}
		}


		cout << endl << "---End test---" << endl;

	}
	catch (Exception& ex) {

		cout << ex;

	}

}

void boundsexceptions() {

	try {

		cout << "---Creating an instance of the Array class with 4 as the length and -6 as the starting index---" << endl << endl;

		Array<int> test(4, -6);

		cout << "Array Length: " << test.getLength() << endl;
		cout << "Starting Index: " << test.getStartIndex() << endl;

		cout << "---Filling in the array with data---" << endl;

		for (auto i = 0; i < test.getLength(); i++) {

			test[i + test.getStartIndex()] = 5 * i;

			cout << "[" << i + test.getStartIndex() << "] = " << test[i + test.getStartIndex()] << endl;
		}

		//cout << "---Attempting to assign a value to lower out of bounds index -10---" << endl << endl;
		//test[-10] = 7;

		cout << "---Attempting to assign a value to higher out of bounds index 4---" << endl << endl;
		test[4] = 2;

		cout << endl << "---End test---" << endl;

	}
	catch (Exception& ex) {

		cout << ex;

	}

}

void negativeindex() {

	try {

		cout << "---Creating an instance of the Array class with 4 as the length and -6 as the starting index---" << endl << endl;

		Array<int> test(4, -6);

		cout << "Array Length: " << test.getLength() << endl;
		cout << "Starting Index: " << test.getStartIndex() << endl;

		cout << "---Filling in the array with data---" << endl;

		for (auto i = 0; i < test.getLength(); i++) {

			test[i + test.getStartIndex()] = 5 * i;

			cout << "[" << i + test.getStartIndex() << "] = " << test[i + test.getStartIndex()] << endl;

		}

		cout << endl << "---End test---" << endl;

	}
	catch (Exception& ex) {

		cout << ex;

	}

}

void setlength() {


	try {
		cout << "---Creating an instance of the Array class with 4 as the length and 0 as the starting index---" << endl << endl;
		Array<int> test(4, 0);

		cout << "Array Length: " << test.getLength() << endl;
		cout << "Starting Index: " << test.getStartIndex() << endl;

		cout << "---Filling in the array with data---" << endl;

		for (auto i = 0; i < test.getLength(); i++) {

			test[i + test.getStartIndex()] = 5 * i;

			cout << "[" << i + test.getStartIndex() << "] = " << test[i + test.getStartIndex()] << endl;

		}

		cout << endl << "Attempting to make the array length 2:" << endl;

		test.setLength(2);

		cout << "Array Length: " << test.getLength() << endl;
		cout << "Starting Index: " << test.getStartIndex() << endl;

		for (auto i = 0; i < test.getLength(); i++) {

			cout << "[" << i + test.getStartIndex() << "] = " << test[i + test.getStartIndex()] << endl;
		}
		cout << endl << "Attempting to make the array length 9:" << endl;

		test.setLength(9);

		cout << "Array Length: " << test.getLength() << endl;
		cout << "Starting Index: " << test.getStartIndex() << endl;

		for (auto i = 0; i < test.getLength(); i++) {

			cout << "[" << i + test.getStartIndex() << "] = " << test[i + test.getStartIndex()] << endl;
		}

		cout << "---End test---" << endl;

	}
	catch (Exception& ex) {

		cout << ex;

	}

}

void outofbounds() {

	try {

		cout << "---Creating an instance of the Array class with 4 as the length and 0 as the starting index---" << endl << endl;

		Array<int> test(4, 0);

		cout << "Array Length: " << test.getLength() << endl;
		cout << "Starting Index: " << test.getStartIndex() << endl;

		cout << "---Filling in the array with data---" << endl;

		for (auto i = 0; i < test.getLength(); i++) {

			test[i + test.getStartIndex()] = 5 * i;

			cout << "[" << i + test.getStartIndex() << "] = " << test[i + test.getStartIndex()] << endl;

		}

		cout << endl << "Attempting to place data at index 8 (an out of bounds index)" << endl;

		test[8] = 6;

		cout << "End test" << endl;

	}
	catch (Exception& ex) {

		cout << ex;

	}

}



void validlengths() {


	try {

		cout << "Testing if 4 is a valid length:" << endl << endl;

		Array<int> test(4, -3);

		cout << "Array Length: " << test.getLength() << endl;
		cout << "Starting Index: " << test.getStartIndex() << endl;

	
		for (auto i = 0; i < test.getLength(); i++) {

			test[i + test.getStartIndex()] = 5 * i;

			cout << "[" << i + test.getStartIndex() << "] = " << test[i + test.getStartIndex()] << endl;

		}

		cout << endl << "Testing if -4 is a valid length:" << endl << endl;


		Array<int> test2(-4, -3);

		cout << "Array Length: " << test2.getLength() << endl;
		cout << "Starting Index: " << test2.getStartIndex() << endl;


		for (auto ii = 0; ii < test2.getLength(); ii++) {

			test2[ii + test2.getStartIndex()] = 5 * ii;

			cout << "[" << ii + test2.getStartIndex() << "] = " << test2[ii + test2.getStartIndex()] << endl;

		}

	}
	catch (Exception& ex) {

		cout << ex;

	}


}

void add_elements2D() {

	 try {

	Array2D<int> test;


		cout << "Row: " << test.getRow() << endl;
		cout << "Column: " << test.getColumn() << endl;


		for (auto x = 0; x < test.getRow(); x++) {

			for (auto y = 0; y < test.getColumn(); y++) {

				test[x][y] = 5;

			}

		}


	
		for (auto i = 0; i < test.getRow(); i++) {

			for (auto ii = 0; ii < test.getColumn(); ii++) {

				cout << "[" << i << "][" << ii << "] = " << test[i][ii] << endl;

			}

		}
	


	}
	catch (Exception& ex) {

		cout << ex;

	}

}


void start() {

	//add_elements2D();
	//validlengths();
	//outofbounds();
	setlength();
	//negativeindex();
	//boundsexceptions();
	//mutators();
	//twodbounds();
	//constmethods();
	//starstarp();
	//test();
	//mutators_P();
	//twodbounds_P();
	//constmethods_P();
}



int main() {

	start();


	cout << endl << endl << endl;


	//looking for leaks
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtDumpMemoryLeaks();


	system("pause");


	return 0;
}