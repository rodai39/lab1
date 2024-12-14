#include "samolet.h"
using namespace std;
void Samolet::save(ofstream& file) {
    file << getName() << "\n";
    file << getType() << "\n";
    file << getVolume() << "\n";
    file << getSize() << "\n";
    file << getCities() << "\n";
}

void Samolet::load(ifstream& file) {
    getline(file, fullName);
    getline(file, type);
    setType(type);
    getline(file, obem);
    setVolume(obem);
    getline(file, size);
    setSize(size);
    getline(file, cities);
    setCities(cities);
}

void Samolet::menu() {
    int choice;
    do {
        cout << "1. Show\n";
        cout << "2. Change name\n";
        cout << "3. Change type\n";
        cout << "4. Change cargo volume\n";
        cout << "5. Change size of airplane\n";
        cout << "6. Change cities the plane visits\n";
        cout << "0. Exit\n";
        cin >> choice;

        switch (choice) {
        case 1:
            show();
            break;
        case 2: {
            string newName;
            cout << "Enter new name: ";
            cin.ignore();
            getline(cin, newName);
            setName(newName);
            break;
        }
        case 3: {
            cout << "Enter type: ";
            cin.ignore();
            getline(cin, type);
            setType(type);
            break;
        }
        case 4: {
            cout << "Enter cargo volume: ";
            cin.ignore();
            getline(cin, obem);
            setVolume(obem);
            break;
        }
        case 5: {
            cout << "Enter size of airplane: ";
            cin.ignore();
            getline(cin, size);
            setSize(size);
            break;
        }
        case 6: {
            cout << "Enter which cities the plane visits: ";
            cin.ignore();
            getline(cin, cities);
            setCities(cities);
            break;
        }
        }
    } while (choice != 0);
}

void Samolet::show() const {
    cout << "Airplane\n";
    cout << "Name: " << getName() << "\n";
    cout << "Type: " << getType() << "\n";
    cout << "Cargo volume: " << getVolume() << "\n";
    cout << "Size of airplane: " << getSize() << "\n";
    cout << "Cities: " << getCities() << "\n";
}