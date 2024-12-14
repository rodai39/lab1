#include <iostream>
#include "keeper.h"
#include "samolet.h"
#include "cars.h"
#include "trains.h"
using namespace std;
int main() {
    Keeper keeper;
    int choice;

    do {
        cout << "1. Add airplane\n";
        cout << "2. Add car\n";
        cout << "3. Add train\n";
        cout << "4. Show all cargo transportation\n";
        cout << "5. Delete cargo transportation\n";
        cout << "6. Save to file\n";
        cout << "7. Download from file\n";
        cout << "8. Edit an entry\n";
        cout << "0. Exit\n";
        cin >> choice;

        switch (choice) {
        case 1: {
            string name, type, obem, size, cities;
            cout << "Enter name of the airplane: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter type: ";
            getline(cin, type);
            cout << "Enter cargo volume: ";
            getline(cin, obem);
            cout << "Enter size of airplane: ";
            getline(cin, size);
            cout << "Enter which cities the plane visits: ";
            getline(cin, cities);
            keeper.addGruz(new Samolet(name, type, obem, size, cities));
            break;
        }
        case 2: {
            string name, god, mark, ch, volume;
            cout << "Enter model of the car: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter the year of release: ";
            getline(cin, god);
            cout << "Enter mark: ";
            getline(cin, mark);
            cout << "Enter the delivery cities/number of delivery hours: ";
            getline(cin, ch);
            cout << "Enter cargo volume: ";
            getline(cin, volume);
            keeper.addGruz(new Cars(name, god, mark, ch, volume));
            break;
        }
        case 3: {
            string name, year, trail, sum, bulk;
            cout << "Enter name of the train: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter the year of release: ";
            getline(cin, year);
            cout << "Enter route: ";
            getline(cin, trail);
            cout << "Enter the number of wagons: ";
            getline(cin, sum);
            cout << "Enter cargo volume: ";
            getline(cin, bulk);
            keeper.addGruz(new Trains(name, year, trail, sum, bulk));
            break;
        }
        case 4:
            keeper.show();
            break;
        case 5: {
            int index;
            cout << "Enter index of the cargo transportation to delete: ";
            cin >> index;
            keeper.removeGruz(index - 1);
            break;
        }
        case 6: {
            string filename;
            cout << "Enter file's name to save cargo transportations: ";
            cin >> filename;
            keeper.save(filename);
            break;
        }
        case 7: {
            string filename;
            cout << "Enter file's name to download cargo transportations: ";
            cin >> filename;
            keeper.load(filename);
            break;
        }
        case 8: {
            int index;
            cout << "Enter index of the cargo transportation to edit: ";
            cin >> index;
            keeper.edit(index - 1);
            break;
        }
        }
    } while (choice != 0);

    return 0;
}