#include <iostream>
using namespace std;

class PKW {
private:
    int leistung;
    int tankinhalt;
    double preis;


public:
    PKW(int _leistung, int _tankinhalt, double _preis)
            : leistung(_leistung), tankinhalt(_tankinhalt), preis(_preis) {}

    void set_leistung(int _leistung) {
        leistung = _leistung;
    }

    int get_leistung() {
        return leistung;
    }

    void set_tankinhalt(int _tankinhalt) {
        tankinhalt = _tankinhalt;
    }

    int get_tankinhalt() {
        return tankinhalt;
    }

    void set_preis(double _preis) {
        preis = _preis;
    }

    double get_preis() {
        return preis;
    }
};


class Kombi : public PKW {
private:
    double maxvolumen;


public:
    Kombi(int _leistung, int _tankinhalt, double _preis, double _maxvolumen)
            : PKW(_leistung, _tankinhalt, _preis), maxvolumen(_maxvolumen) {}

    void set_maxvolumen(double _maxvolumen) {
        maxvolumen = _maxvolumen;
    }

    double get_maxvolumen() {
        return maxvolumen;
    }
};

int main() {
    Kombi kombi(210, 80, 69000.0, 480);
    cout << "Leistung: " << kombi.get_leistung() << " PS" << endl;
    cout << "Tankinhalt: " << kombi.get_tankinhalt() << " Liter" << endl;
    cout << "Preis: " << kombi.get_preis() << " Euro" << endl;
    cout << "Maximales Kofferraumvolumen: " << kombi.get_maxvolumen() << " L" << endl;
    return 0;
}


