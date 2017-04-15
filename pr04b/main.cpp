#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>

using namespace std;

#define MAX_ROWS 10
#define MAX_COLS 10

/** \brief
 * Read from file an array and initialize array and also n and m
 * We pass address of n and m because we want to store the values there
 *
 * \param matrixDataFile char*
 * \param a[][MAX_COLS] int
 * \param n int*
 * \param m int*
 * \return void
 *
 */
void readFromFile(char *matrixDataFile, int a[][MAX_COLS], int *n, int *m) {

    ifstream ifs;
    ifs.open (matrixDataFile);
    int i, j;

    if( !ifs.is_open()) {
        cout << "Fisierul " << matrixDataFile << " nu poate fi deschis!" << endl;
        exit(EXIT_FAILURE);
    }

    ifs >> *n >> *m;

    cout << "n = " << *n << ", m = " << *m << endl;

    // read array
    for(i = 0; i < *n; i++) {
        for (j = 0; j < *m ; j++) {
            ifs >> a[i][j];
        }
    }
    ifs.close();
}


/** \brief
 * Write matrix
 *
 * \param a[][MAX_COLS] int
 * \param n int
 * \param m int
 * \return void
 *
 */
void writeMatrix(int a[][MAX_COLS], int n, int m) {
    int i, j;
    // write array
    for( i=0; i<n; i++) {
        for (j = 0; j < m ; j++) {
            cout << setw(3) << a[i][j];
        }
        cout << endl;
    }
    cout << endl;
}


/** \brief
 * Write the array of addresses and the values stored
 *
 * \param aad[] int* array of addresses where integers are stored
 * \param cnt int
 * \return void
 *
 */
void writeAAD(int *aad[], int cnt) {
    cout << "Sirul de adrese:" << endl;
    for( int i = 0; i < cnt; i++ ) {
        cout << aad[i] << " ";
    }
    cout << endl;
    cout << "Sirul de valori:" << endl;
    for( int i = 0; i < cnt; i++ ) {
        cout << *aad[i] << " ";
    }
    cout << endl;

}


/** \brief Swap 2 variables by their address
 *
 * \param a int*
 * \param b int*
 * \return void
 *
 */
void varSwap(int *a, int *b) {
    int temp = *a;

    *a = *b;
    *b = temp;
}


void rotateAddrLeft(int *aad[], int cnt) {
    int temp = *aad[0];

    for( int i = 1; i < cnt-1; i++ ) {
        *aad[i-1] = *aad[i];
    }
    *aad[cnt-1-1] = temp;
}


/** \brief
 * Find the position of min and move it to first position
 * This is working with an array of addresses to integers
 *
 * \param aad[] int*
 * \param cnt int
 * \return void
 *
 */
void moveMinToBegin(int *aad[], int cnt) {
    int iMin = 0;

    for( int i = 1; i < cnt-1; i++ ) {
        if( *aad[i] < *aad[iMin] ) {
            iMin = i;
        }
    }

    if( iMin != 0) {
        varSwap(aad[0], aad[iMin]);
    }
}

/** \brief
 * Find the position of max and move it to last position
 * This is working with an array of addresses to integers
 *
 * \param aad[] int*
 * \param cnt int
 * \return void
 *
 */
void moveMaxToEnd(int *aad[], int cnt) {
    int iMax = 0;

    for( int i = 1; i < cnt-1; i++ ) {
        if( *aad[i] > *aad[iMax] ) {
            iMax = i;
        }
    }

    if( iMax != cnt-1) {
        varSwap(aad[cnt-1], aad[iMax]);
    }
}


int main()
{
    // this file should contain an array
    char *matrixDat = "matrix2.txt";

    int n, m;
    int a[MAX_ROWS][MAX_COLS];
    int *aad[MAX_COLS*MAX_ROWS];
    int cnt = 0;

    readFromFile(matrixDat,a,&n,&m);
    writeMatrix(a,n,m);


    // feed aad array with (addresses of elements from array
    // Notice & operator ! This means the address of the integer not the value
    // add all addresses of first row.
    for(int j = 0; j < m ; j++) {
        aad[cnt++] = &a[0][j];
    }

    // add all addresses of last column
    for(int i = 1; i < n; i++ ) {
        aad[cnt++] = &a[i][m-1];
    }

    // add all addresses of last row
    for(int j = m-1; j > 0 ; j--) {
        aad[cnt++] = &a[n-1][j-1];
    }

    // add all addresses of first column
    for(int i = n-1; i > 0; i-- ) {
        aad[cnt++] = &a[i-1][0];
    }

    cout << "Rotirea 1:" << endl;
    rotateAddrLeft(aad, cnt);
    writeMatrix(a,n,m);
    cout << "Rotirea 2:" << endl;
    rotateAddrLeft(aad, cnt);
    writeMatrix(a,n,m);

    if( n != m) {
        cout << "Matricea nu este patratica. Stop" << endl;
        return 0;
    }

    // swap diagonals
    cout << "Inversarea diagonalelor:" << endl;
    for(int i = 0; i < n; i++ ) {
        varSwap(&a[i][i], &a[i][n-1-i]);
    }
    writeMatrix(a,n,m);

    // min&max prima diagonala. Construirea sirului de adrese
    cout << "Min & Max diagonala principala:" << endl;
    cnt = 0;
    for(int i = 0; i < n; i++) {
        aad[cnt++] = &a[i][i];
    }
    moveMinToBegin(aad, cnt);
    moveMaxToEnd(aad, cnt);
    writeMatrix(a,n,m);

    // min&max diagonala secundara. Construirea sirului de adrese
    cout << "Min & Max diagonala secundara:" << endl;
    cnt = 0;
    for(int i = 0; i < n; i++) {
        aad[cnt++] = &a[i][n-1-i];
    }
    moveMinToBegin(aad, cnt);
    moveMaxToEnd(aad, cnt);
    writeMatrix(a,n,m);

    return 0;
}
