#include <iostream>

using namespace std;


/**
* Calculate the sum of digits from given number long
*/
int digitSum(long n) {
    int s = 0;

    while( n > 0) {
        s += n % 10;
        n /= 10;
    }

    return s;
}

/**
* Calculate the reverse of given number long
*/
long reverse(long n) {
    int s = 0;

    while( n > 0) {
        s = s * 10 + n % 10;
        n /= 10;
    }

    return s;
}

/**
* Calculate the number of digits
*/
int length(long n) {
    int s = 0;

    while( n > 0) {
        s += 1;
        n /= 10;
    }

    return s;
}


int main()
{
    long n,m;

    cout << "n = ";
    cin >> n;

    m = reverse(n);
    cout << "Inversul  este " << m << endl;
    cout << "Length " << length(n) << endl;

    if(n == m) {
        cout << "Numarul este palindrom";
    }
    else {
        cout << "Numarul nu este palindrom";
    }

    cout << "\nDone!";

    return 0;
}
