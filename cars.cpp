#include "cars.h"
using namespace std;
void Cars::save(ofstream& file) {
    file << getName() << "\n";
    file << getYear() << "\n";
    file << getMark() << "\n";
    file << getCh() << "\n";
    file << getVolume() << "\n";
}

void Cars::load(ifstream& file) {
    getline(file, fullName);
    getline(file, year);
    setYear(year);
    getline(file, mark);
    setMark(mark);
    getline(file, ch);
    setCh(ch);
    getline(file, volume);
    setVolume(volume);
}

void Cars::menu() {
    int choice;
    do {
        cout << "1. Show\n";
        cout << "2. Change model\n";
        cout << "3. Change the year of release\n";
        cout << "4. Change mark\n";
        cout << "5. Change the delivery cities/number of delivery hours\n";
        cout << "6. Change volume of baggage\n";
        cout << "0. Exit\n";
        cin >> choice;

        switch (choice) {
        case 1:
            show();
            break;
        case 2: {
            string newModel;
            cout << "Enter new model: ";
            cin.ignore();
            getline(cin, newModel);
            setName(newModel);
            break;
        }
        case 3: {
            cout << "Enter the year of release: ";
            cin.ignore();
            getline(cin, year);
            setYear(year);
            break;
        }
        case 4: {
            cout << "Enter mark: ";
            cin.ignore();
            getline(cin, mark);
            setMark(mark);
            break;
        }
        case 5: {
            cout << "Enter the delivery cities/number of delivery hours: ";
            cin.ignore();
            getline(cin, ch);
            setCh(ch);
            break;
        }
        case 6: {
            cout << "Enter cargo volume: ";
            cin.ignore();
            getline(cin, volume);
            setVolume(volume);
            break;
        }
        }
    } while (choice != 0);
}

void Cars::show() const {
    cout << "Car\n";
    cout << "Model: " << getName() << "\n";
    cout << "The year of release: " << getYear() << "\n";
    cout << "Mark: " << getMark() << "\n";
    cout << "Delivery cities/number of delivery hours: " << getCh() << "\n";
    cout << "Cargo volume: " << getVolume() << "\n";
}