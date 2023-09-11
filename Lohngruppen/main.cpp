#include <iostream>
using namespace std;
int main() {
   int Stundenlohn;
    int Lohngruppe;
    cout << "Welche Lohngruppe? [e.g. 1] : ";
    cin >> Lohngruppe;
    double Stunden;


    switch (Lohngruppe) {
        case 1:
            Stundenlohn = 17;
            break;

        case 2:
            Stundenlohn = 20;
            break;

        case 3:
            Stundenlohn = 22;
            break;

        case 4:
            Stundenlohn = 23;
            break;

        case 5:
            Stundenlohn = 25;
            break;

        case 6:
            Stundenlohn = 26;
            break;

        default:
            cout << "Fehler: Lohngruppe existiert nicht";
            return 0;

    }
    double Lohn = Stundenlohn * Stunden;
    cout << "Wie viele Stunden?: ";
    cin >> Stunden;
    cout << "Der Bruttolohn fuer den Mitarbeiter mit der Lohngruppe " << Lohngruppe << " betraegt :" << Lohn << " Euro";
    return 0;
}
