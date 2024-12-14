#ifndef TRAINS_H
#define TRAINS_H

#include "gruzoperevoz.h"

class Trains : public Gruzoperevoz {
private:
    string year;
    string trail;
    string sum;
    string bulk;
protected:
    string fullYear;
    string fullTrail;
    string fullSum;
    string fullBulk;
public:
    Trains() : fullYear(""), fullTrail(""), fullSum(""), fullBulk("") {}
    Trains(const string& name, const string& years, const string& traila, const string& suma, const string& bulki)
        : Gruzoperevoz(name), fullYear(years), fullTrail(traila), fullSum(suma), fullBulk(bulki) {}

    void save(ofstream& file) override;
    void load(ifstream& file) override;
    void menu() override;
    void show() const override;
    
    void setYear(const string& years) {
        fullYear = years;
    }

    string getYear() const {
        return fullYear;
    }
    void setTrail(const string& trail) {
        fullTrail = trail;
    }

    string getTrail() const {
        return fullTrail;
    }
    void setSum(const string& sum) {
        fullSum = sum;
    }

    string getSum() const {
        return fullSum;
    }
    void setBulk(const string& bulk) {
        fullBulk = bulk;
    }

    string getBulk() const {
        return fullBulk;
    }
};

#endif
