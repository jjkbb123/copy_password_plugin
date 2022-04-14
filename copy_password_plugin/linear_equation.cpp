//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//#include <conio.h>
//float* ColPivot(float* c, int n);
//int main()
//{
//	int i, j;
//	float* x;
//	int n = 4;
//	float a[4][5] = { 4.,-1.,0.,2.,-1.0,-1,4,-1,0,-7.0,0,-1,4,-1,9.0,2,0,-1,4.0,0.0 };
//	x = ColPivot(a[0], n);
//	for (i = 0; i < n; i++) printf("x[%d]=%f\n", i, x[i]);
//	//getch();
//	return 0;
//};
//float* ColPivot(float* c, int n)
//{
//	int i, j, t, k;
//	float* x, p;
//	x = (float*)malloc(n * sizeof(float));
//	for (i = 0; i <= n - 2; i++)
//	{
//		k = i;
//		for (j = i + 1; j <= n - 1; j++)
//			if (fabs(*(c + j * (n + 1) + i)) > (fabs(*(c + k * (n + 1) + i)))) k = j;
//		if (k != i)
//			for (j = i; j <= n; j++)
//			{
//				p = *(c + i * (n + 1) + j);
//				*(c + i * (n + 1) + j) = *(c + k * (n + 1) + j);
//				*(c + k * (n + 1) + j) = p;
//			}
//		for (j = i + 1; j <= n - 1; j++)
//		{
//			p = (*(c + j * (n + 1) + i)) / (*(c + i * (n + 1) + i));
//			for (t = i; t <= n; t++)
//				*(c + j * (n + 1) + t) -= p * (*(c + i * (n + 1) + t));
//		}
//	}
//	for (i = n - 1; i >= 0; i--)
//	{
//		for (j = n - 1; j >= i + 1; j--)
//			(*(c + i * (n + 1) + n)) -= x[j] * (*(c + i * (n + 1) + j));
//		x[i] = *(c + i * (n + 1) + n) / (*(c + i * (n + 1) + i));
//	}
//	return x;
//};

#include <iostream>

using namespace std;

const int initLine = 3;
void showMatrix(int arr[initLine][initLine], int size);

void showMatrix(int arr[initLine][initLine], int size) {
  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size; j++) {
      cout << arr[i][j] << " ";
    };
    cout << endl;
  };
};

int* gauss(int data[], int dataConst[], int size) {
	int initx1[initLine][initLine]; // init martix
	int index = 0;
	int index2 = 0;
	for (int i = 0; i < initLine; i++) {
		for (int j = 0; j < initLine; j++) {
			initx1[i][j] = data[index];
			index++;
		};
	};
	// show init matrix
	cout << "init linear equation matrix." << endl;
	for (int i = 1; i <= size; i++) {
		cout << data[i - 1] << " ";
		if (!(i % initLine)) {
			cout << endl;
		};
	};
	// show init matrix constant
	cout << "init linear equation contanst." << endl;
	for (int i = 1; i <= initLine; i++) {
		cout << dataConst[i - 1] << endl;
	};
  cout << "result martix." << endl;
	int z = 0;
  int n = 0;
  int arr[initLine][initLine];
  int constantArr[initLine];
  int diffrenceMultiple;
  int addMultiple;
	for (int i = 1; i < initLine; i++) { // 1 2
		for (int j = i; j < initLine; j++) { // 1 2 2
			for (int k = 0; k < initLine; k++){ /// 0 1 2 0 1 2 0 1 2
        // initx1[z][k]*(initx1[j][z] / initx1[z][z]): diffrence multiple
        diffrenceMultiple = (initx1[j][z] / initx1[z][z]);
        addMultiple = diffrenceMultiple * initx1[z][k];
        arr[n][k] = initx1[j][k] - addMultiple;
			};
      for(int u = 0; u < initLine; u++) {
        initx1[j][u] = arr[n][u];
      };
      constantArr[j] = dataConst[j] - dataConst[z] * diffrenceMultiple;
      n++;
		};
    // for(int l = 1; l < initLine; l++) {
    //   dataConst[l] = constantArr[l];
    // };
    for(int l = i; l < initLine; l++) {
      dataConst[l] = constantArr[l];
    };
		z++;
	};
  showMatrix(initx1, initLine);
  cout << "result matrix constant." << endl;
  for(int i = 0; i < initLine; i++) {
    cout << dataConst[i] << endl;
  };

  int result[initLine];
  int combine;
  int initIndex = initLine;
  cout << "result untie." << endl;
  // for(int i = initLine-1; i >= 0; i--) {
  //   for(int j = 0; j < initLine; j++) {
  //     if(i + 1 == initLine) {
  //       dataConst[i] / initx1[i][i];
  //       cout << dataConst[i] / initx1[i][initLine-1];
  //     };
  //     // cout << initx1[i][j] << " ";
  //   };
  //   cout << endl;
  // };
  for(int i = initLine-1; i >= 0; i--) {
    initIndex--;
    if(i + 1 == initLine) {
      result[i] = dataConst[i] / initx1[i][i];
      cout << dataConst[i] / initx1[i][initLine-1] << endl;
    } else {
      // result[i] = 
      // dataConst[i] - initx1[i][]
      for(int j = initLine-1; j >= 0; j--) {
        if(initIndex == j) {
          break;
        };
      };
    }
  };
	/*
		[
			[1, -2, -1],
			[2, -3,  1],
			[4, -2,  7],
		]
	*/
	return data;
};

int main() {
	int data[] = { 1, -2, -1,   2, -3, 1,   4, -2, 7 };
	int dataConst[] = { -2, -5, -7 };
	int dataSize = sizeof(data) / sizeof(data[0]);
	int* result = gauss(data, dataConst, dataSize);
	// cout << result[1];
	return 0;
};
/*
		[
			[1, -2, -1], [-2]
			[2, -3,  1], [-5]
			[4, -2,  7], [-7]
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
