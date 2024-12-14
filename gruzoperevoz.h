#ifndef GRUZOPEREVOZ_H
#define GRUZOPEREVOZ_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Gruzoperevoz {
protected:
    string fullName;
public:
    Gruzoperevoz() : fullName("-") {}
    Gruzoperevoz(const string& name) : fullName(name) {}
    virtual ~Gruzoperevoz() {}

    virtual void save(ofstream& file) = 0;
    virtual void load(ifstream& file) = 0;
    virtual void menu() = 0;
    virtual void show() const {
        cout << "Full Name: " << fullName << endl;
    }

    void setName(const string& name) {
        fullName = name;
    }

    string getName() const {
        return fullName;
    }
};

#endif 