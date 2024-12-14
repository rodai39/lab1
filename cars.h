#ifndef CARS_H
#define CARS_H

#include "gruzoperevoz.h"

class Cars : public Gruzoperevoz {
private:
    string year;
    string mark;
    string ch;
    string volume;
protected:
    string fullYear;
    string fullMark;
    string fullCh;
    string fullVolume;
public:
    Cars() : year(""), mark(""), ch(""), volume("") {}
    Cars(const string& name, const string& years, const string& marka, const string& th, const string& volumes)
        : Gruzoperevoz(name), fullYear(years), fullMark(marka), fullCh(th), fullVolume(volumes) {}

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
    void setMark(const string& mark) {
        fullMark = mark;
    }

    string getMark() const {
        return fullMark;
    }
    void setCh(const string& ch) {
        fullCh = ch;
    }

    string getCh() const {
        return fullCh;
    }
    void setVolume(const string& volume) {
        fullVolume = volume;
    }

    string getVolume() const {
        return fullVolume;
    }
};

#endif
