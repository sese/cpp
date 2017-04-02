#include <iostream>

using namespace std;


class Animal {

private:
    int size;

protected:
    string name;

public:
    Animal(string name) {
        this->name = name;
    }
};


class Dog: public Animal {

};




int main()
{

    Animal d = Animal("riciu");


    return 0;
}
