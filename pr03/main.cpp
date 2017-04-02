#include <iostream>
#include <math.h>

using namespace std;


class Point {
private:
    int x;
    int y;

    void add(Point p) {
        this->x += p.x;
        this->y += p.y;
    }

public:

    Point() {
        this->x = 0;
        this->y = 0;
    }

    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    void print() {
        cout << "(" << this->x << "," << this->y  << ")" << endl;
    }


    float radius(){

        return sqrt(this->x*this->x + this->y*this->y);
    }

    int setX(int x) {
        this->x = x;
    }

    int setY(int y) {
        this->y = y;
    }

    Point operator+( Point p) {
        Point pr = Point(this->x, this->y);
        pr.add(p);
        return pr;
    }


};



int main()
{

    Point p0 = Point();
    Point p1 = Point(3,2);
    Point p2 = Point(2,3);

    p1.print();
    p2.print();

    Point p3 = p1 + p2;

    p3.print();
    cout << p3.radius() << endl;
    return 0;
}

