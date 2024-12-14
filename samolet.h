#ifndef SAMOLET_H
#define SAMOLET_H

#include "gruzoperevoz.h"

class Samolet : public Gruzoperevoz {
private:
    string type;
    string obem;
    string size;
    string cities;
protected:
    string fullType;
    string fullVolume;
    string fullSize;
    string fullCities;
public:
    Samolet() : type(""), obem(""), size(""), cities("") {}
    Samolet(const string& name, const string& tip, const string& V, const string& razmer, const string& towns)
        : Gruzoperevoz(name), fullType(tip), fullVolume(V), fullSize(razmer), fullCities(towns) {}

    void save(ofstream& file) override;
    void load(ifstream& file) override;
    void menu() override;
    void show() const override;

    void setType(const string& type) {
        fullType = type;
    }
    string getType() const {
        return fullType;
    }

    void setVolume(const string& volume) {
        fullVolume = volume;
    }
    string getVolume() const {
        return fullVolume;
    }

    void setSize(const string& size) {
        fullSize = size;
    }
    string getSize() const {
        return fullSize;
    }

    void setCities(const string& cities) {
        fullCities = cities;
    }
    string getCities() const {
        return fullCities;
    }
};

#endif 
