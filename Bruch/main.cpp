#include <iostream>

using namespace std;

class Bruch {
private:
    int zähler;
    int nenner;

public:
    Bruch(int z, int n) : zähler(z), nenner(n) {}

    void get_bruch() {
        cout << zähler << " / " << nenner;
    }

    void addiere(const Bruch &bruch) {
        zähler = zähler * bruch.nenner + bruch.zähler * nenner;
        nenner *= bruch.nenner;
    }
};

int main() {
    Bruch A(0, 1);
    Bruch B(1, 2);
    Bruch C(3, 4);

    Bruch temp = B;
    temp.addiere(C);
    A = temp;

    cout << "Ergebnis: ";
    A.get_bruch();

    return 0;
}
