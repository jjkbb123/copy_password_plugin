#include <iostream>

using namespace std;

int* gauss(int data[], int dataConst[], int size, int initLine) {
	int initx1[initLine][initLine]; // init martix
	int index = 0;
	for(int i = 0; i < initLine; i++) {
		for(int j = 0; j < initLine; j++) {
			initx1[i][j] = data[index];
			index++;
		};
	};
	// show init matrix
	cout << "init linear equation matrix." << endl;
	for(int i = 1; i <= size; i++) {
		cout << data[i-1] << " ";
		if(!(i % initLine)) {
			cout << endl;
		};
	};
	// show init matrix constant
	cout << "init linear equation contanst." << endl;
	for(int i = 1; i <= initLine; i++) {
		cout << dataConst[i-1] << endl;
	};
	// action from 1
	for(int i = 1; i < initLine; i++) {
		for(int j = 0; j < initLine; j++) {
			initx1[i][j] = initx1[i][j] / initx1[i-1][j];
		};
	};
  return data;
};

int main() {
	int data[] = {1, -2, -1, 2, -3, 1, 4, -2, 7};
	int dataConst[] = {-2, -5, -7};
	int initLine = 3;
	int dataSize = sizeof(data) / sizeof(data[0]);
	int* result = gauss(data, dataConst, dataSize, initLine);
	// cout << result[1];
  return 0;
};
/*
		[
			[1, -2, -1],
			[2, -3,  1],
			[4, -2,  7]
		]
    1 -2 -1     -2 
    2 -3  1     -5
    4 -2  7     -7

    1 -2 -1     -2
    0 1  3      -1
    0 6  11     1

    1 -2 -1     -2
    0 1  3      -1
    0 0  -7     7

    1 2 -1
*/

/*
    2 -1 0
    -1 2 3

    2 -1 0
    0 -3 -6
    1 2
*/
