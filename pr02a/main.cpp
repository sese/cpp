#include <iostream>
#include <iomanip>

using namespace std;

#define max 10

int signum(int n) {

    if( n == 0 ) {
        return 0;
    }

    if ( n > 0 ) {
        return 1;
    }

    return -1;
}

int main()
{
    int n;
    int a[max];
    int i, j;


    cout << signum(4) << signum(-3) << signum(0);

    cout << "n = ";
    cin >> n;

    // read array
    for( i=0; i<n; i++) {
        cin >> a[i];
    }

    // write array
    for( i=0; i<n; i++) {
        cout << setw(5) << a[i];
    }

    cout << endl;

    for(i = 0; i < n - 1; i++) {
        for( j = i+1; j < n; j++ ) {
            cout << "(" << a[i] << "," << a[j] << ") " ;
        }
        cout << endl;
    }


    return 0;
}
