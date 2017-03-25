#include <iostream>
#include <iomanip>

using namespace std;

#define maxRows 10
#define maxCols 10


int signum(int n) {

    if( n == 0 ) {
        return 0;
    }

    if ( n > 0 ) {
        return 1;
    }

    return -1;
}


bool testRows(int a[maxRows][maxCols], int i1, int i2, int nrCols) {
    int s = signum(a[i1][0] - a[i2][0]);
    for(int j = 1; j < nrCols; j++ ) {
        if( s != signum(a[i1][j] - a[i2][j]) ) {
            return false;
        }
    }
    return true;
}


int main()
{
    int n, m;
    int a[maxRows][maxCols];
    int i, j, l;

    cout << "nr. linii n = ";
    cin >> n;

    cout << "nr. coloane m = ";
    cin >> m;

    // read array
    for( i=0; i<n; i++) {
        for (j = 0; j < m ; j++) {
            cin >> a[i][j];
        }
    }

    // write array
    for( i=0; i<n; i++) {
        for (j = 0; j < m ; j++) {
            cout << setw(5) << a[i][j];
        }
        cout << endl;
    }


    // testing
    for( i=0; i<n-1; i++) {
        for (l = i+1; l < n ; l++) {
            if (testRows(a, i, l, m)) {
                cout << "(" << i+1 << "," << l+1 << ") ";
            }
        }
        cout << endl;
    }

    return 0;
}
