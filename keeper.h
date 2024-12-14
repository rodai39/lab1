#ifndef KEEPER_H
#define KEEPER_H

#include "Gruzoperevoz.h"
#include <fstream>

class Keeper {
private:
    Gruzoperevoz** gruzi;
    int counter;

public:
    Keeper();
    ~Keeper();

    void addGruz(Gruzoperevoz* gruzoperevoz);
    void removeGruz(int index);
    void show() const;
    void save(const string& filename);
    void load(const string& filename);
    void edit(int index);
    void clear();
};

#endif 
