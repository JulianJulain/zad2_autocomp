#include <iostream>
#include <string>
#include "Queue.hpp"
#include <thread>   
#include <chrono>
#include <stdexcept>
#include <random>

using namespace std;
using namespace std::chrono;

int main() {
    Queue<string> klienci;
    int licznik = 0;
    klienci.enqueue("Klient");
    klienci.enqueue("Klient");
    licznik = 0;
    int suma_obslugi = 0;
    int liczba_osob = 0;
    int dl_kolejki = 0;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist_czas_obslugi(1, 5);      
    uniform_int_distribution<> dist_czas_przybycia(1, 3);
    uniform_int_distribution<> dist_ID(100000, 999999);
    while (!klienci.isEmpty()) {
        int czas_obslugi = dist_czas_obslugi(gen);
        int czas_przybycia = dist_czas_przybycia(gen);
        int ID_klienta = dist_ID(gen);
        if (czas_obslugi >= czas_przybycia) {
            klienci.dequeue();
            this_thread::sleep_for(chrono::seconds(2));
            liczba_osob++;
            suma_obslugi += czas_obslugi;
       }
        else {
            klienci.enqueue("Klient");
            this_thread::sleep_for(chrono::seconds(2));
            liczba_osob++;
        }
        cout << czas_obslugi << endl;
        cout << czas_przybycia << endl;
        cout << "Dochodzi klient o ID" << " " << ID_klienta << endl;
        cout << "Czy kolejka pusta? " << (klienci.isEmpty() ? "Tak" : "Nie") << endl;
        cout << "Liczba w kolejce: " << klienci.size() << endl;
        licznik++;
        if (klienci.size() > dl_kolejki) {
            dl_kolejki = klienci.size();
        }
        if (licznik > 10) {
            break;
        }
        suma_obslugi = suma_obslugi + czas_obslugi;
    }

    cout << endl;
    cout << endl;
    cout << endl;
    if (liczba_osob > 0) {
        cout << suma_obslugi / liczba_osob << " " << "srednia" << endl;
    }
    else {
        cout << "Brak sredniej" << endl;
    }
    cout << dl_kolejki <<  " " << "Najdluzsza wartosc kolejki"<<endl;

    return 0;
}
