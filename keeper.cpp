#include "Keeper.h"
#include "samolet.h"
#include "cars.h"
#include "trains.h"
using namespace std;
Keeper::Keeper() : gruzi(nullptr), counter(0) {}

Keeper::~Keeper() {
    clear();
}

void Keeper::clear() {
    for (int i = 0; i < counter; ++i) {
        delete gruzi[i];
    }
    delete[] gruzi;
    counter = 0;
    gruzi = nullptr;
}

void Keeper::addGruz(Gruzoperevoz* gruzoperevoz) {
    Gruzoperevoz** temp = new Gruzoperevoz*[counter + 1];
    for (int i = 0; i < counter; ++i) {
        temp[i] = gruzi[i];
    }
    temp[counter] = gruzoperevoz;
    delete[] gruzi;
    gruzi = temp;
    ++counter;
}

void Keeper::removeGruz(int index) {
    if (index < 0 || index >= counter) {
        cerr << "Invalid index.\n";
        return;
    }
    delete gruzi[index];
    for (int i = index; i < counter - 1; ++i) {
        gruzi[i] = gruzi[i + 1];
    }
    --counter;
}

void Keeper::show() const {
    for (int i = 0; i < counter; ++i) {
        gruzi[i]->show();
        cout << "-----------------------\n";
    }
}

void Keeper::save(const string& filename) {
    ofstream file(filename, ios::trunc);
    if (!file) {
        cerr << "Error opening a file for writing.\n";
        return;
    }

    for (int i = 0; i < counter; ++i) {
        if (dynamic_cast<Samolet*>(gruzi[i])) {
            file << "[samolet]\n";
        } else if (dynamic_cast<Cars*>(gruzi[i])) {
            file << "[cars]\n";
        } else if (dynamic_cast<Trains*>(gruzi[i])) {
            file << "[trains]\n";
        }
        gruzi[i]->save(file);
    }

    file.close();
    cout << "Saved.\n";
}

void Keeper::load(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening the file for reading.\n";
        return;
    }

    clear();
    string line;
    while (getline(file, line)) {
        Gruzoperevoz* gruzoperevoz = nullptr;
        if (line == "[samolet]") {
            gruzoperevoz = new Samolet();
        } else if (line == "[cars]") {
            gruzoperevoz = new Cars();
        } else if (line == "[trains]") {
            gruzoperevoz = new Trains();
        }
        if (gruzoperevoz) {
            gruzoperevoz->load(file);
            addGruz(gruzoperevoz);
        }
    }
    file.close();
    cout << "The data is downloaded from a file.\n";

}

void Keeper::edit(int index){
    if (index < 0 || index >= counter) {
        cerr << "Invalid index.\n";
        return;
    }
    gruzi[index]->menu();
    gruzi[index]->show();
    cout << "-----------------------\n";
}