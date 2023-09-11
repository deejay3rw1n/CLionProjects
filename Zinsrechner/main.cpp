#include <iostream>
using namespace std;

int main() {

    double Grundkapital, Zinssatz, Laufzeit, Einzahlung;
    int i = 0;

    cout << "Bitte Grundkapital angeben: ";
        cin >> Grundkapital;
    cout << "Bitte Zinssatz angeben: ";
        cin >> Zinssatz;
    cout << "Bitte gewuenschte Laufzeit angeben: ";
        cin >> Laufzeit;
    cout << "Bitte Jaehrliche Einzahlung angeben: ";
        cin >> Einzahlung;

        do
        {
         Grundkapital = Grundkapital * (1+Zinssatz) + Einzahlung;
         cout << "Nach " << i+1 << " Jahre hat ihr Kapital eine Hoehe von " << Grundkapital << "\n";
         i++;

        }while(i < Laufzeit);
    return 0;
}
