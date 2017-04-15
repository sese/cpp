#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

#define MAX_ROWS 10
#define MAX_COLS 10


void writeMatrix(int a[MAX_ROWS][MAX_COLS], int n, int m) {
    int i, j;
    // write array
    for( i=0; i<n; i++) {
        for (j = 0; j < m ; j++) {
            cout << setw(5) << a[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void rotateLeft(int a[MAX_ROWS][MAX_COLS], int n, int m) {
    int i, j;
    // store first element from array to buffer
    int sp = a[0][0];

    // shift one by one all elements from first row to right
    for( j = 1; j < m ; j++) {
        a[0][j-1] = a[0][j];
    }
    writeMatrix(a, n, m);
    // shift one by one all elements from last column
    for( i = 1; i < n; i++ ) {
        a[i-1][m-1] = a[i][m-1];
    }
    writeMatrix(a, n, m);
    // shift one by one all elements from last row to left
    for( j = m-1; j > 0 ; j--) {
        a[n-1][j] = a[n-1][j-1];
    }
    writeMatrix(a, n, m);

    // shift one by one all elements from last column
    for( i = n-1; i > 0; i-- ) {
        a[i][0] = a[i-1][0];
    }
    writeMatrix(a, n, m);
    a[1][0] = sp;
    writeMatrix(a, n, m);
}

int main()
{

    ifstream myfile;
    char *matrixDat = "matrix2.txt";

    int n, m;
    int a[MAX_ROWS][MAX_COLS];
    int i, j;

    myfile.open (matrixDat);

    if( !myfile.is_open()) {
        cout << "Fisierul " << matrixDat << " nu poate fi deschis!" << endl;
        return 1001;
    }

    myfile >> n >> m;

    cout << "n = " << n << endl;
    cout << "m = " << m << endl;

    // read array
    for( i=0; i<n; i++) {
        for (j = 0; j < m ; j++) {
            myfile >> a[i][j];
        }
    }
    myfile.close();

    writeMatrix(a, n, m);
/*
    rotateLeft(a, n , m);
    rotateLeft(a, n , m);
*/

    int min, max;
    min = max = 0;

    for(i = 0; i < n ; i++ ) {
        int c = a[i][i];
        if (c < a[min][min]) {
            min = i;
        }
        if (c > a[max][max]) {
            max = i;
        }
        cout << c << " ";
    }
    cout << endl;
    cout << "min = " << min << endl;
    cout << "max = " << max << endl;

    int temp;
    if( a[0][0] != a[min][min]) {
        temp = a[0][0];
        a[0][0] = a[min][min];
        a[min][min] = temp;
    }

    if( a[n-1][n-1] != a[max][max]) {
        temp = a[n-1][n-1];
        a[n-1][n-1] = a[max][max];
        a[max][max] = temp;
    }

    writeMatrix(a, n, m);

    min = max = 0;
    for(i = 0; i < n ; i++ ) {
        int c = a[i][m-1-i];
        if (c < a[min][m-1-min]) {
            min = i;
        }
        if (c > a[max][m-1-max]) {
            max = i;
        }
        cout << c << " ";
    }
    cout << endl;
    cout << "min = " << min << endl;
    cout << "max = " << max << endl;

    if( a[0][m-1] != a[min][m-1-min]) {
        temp = a[0][m-1];
        a[0][m-1] = a[min][m-1-min];
        a[min][m-1-min] = temp;
    }

    if( a[n-1][0] != a[max][m-1-max]) {
        temp = a[n-1][0];
        a[n-1][0] = a[max][m-1-max];
        a[max][m-1-max] = temp;
    }
    writeMatrix(a, n, m);

    return 0;
}
