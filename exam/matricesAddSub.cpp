/**
* CSE 1901016113
* MD Shahin Mia Robin
* 16A2
*/
#include <bits/stdc++.h>
using namespace std;
#define N 4

// This function adds A[][] and B[][], and stores
// the result in C[][]
void add(int A[][N], int B[][N], int C[][N])
{
    int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            C[i][j] = A[i][j] + B[i][j];
}

// This function subtracts B[][] from A[][], and stores
// the result in C[][]
void subtract(int A[][N], int B[][N], int C[][N])
{
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			C[i][j] = A[i][j] - B[i][j];
}

void show(int see[][N], int size){
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            cout << see[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int A[N][N] = {{1, 1, 1, 1},
                   {2, 2, 2, 2},
                   {3, 3, 3, 3},
                   {4, 5, 6, 8}};

    int B[N][N] = {{1, 1, 1, 1},
                   {2, 2, 2, 2},
                   {3, 3, 3, 3},
                   {4, 5, 6, 8}};

    int  addResult[N][N], subResult[N][N], result[N][N]; // To store result
    int i, j;
    add(A, B, addResult);
    subtract(A, B, subResult);

    cout << "Addition Result matrix is " << endl;
    show(addResult, N);

    cout << "Subtraction Result matrix is " << endl;
    show(subResult, N);

    cout << "The Final matrix is " << endl;
    add(addResult, subResult, result);
    show(result, N);

    return 0;
}


