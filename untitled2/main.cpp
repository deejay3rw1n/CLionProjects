#include <iostream>
using namespace std;
int main()
{
    int Artikelnr, Menge, Preis;
    double MwStSatz;
    double Gesamtpreis;
    const int halberMwStSatz = 7, ganzerMwStSatz = 19;
    cout << "Bitte Artikelnummer eingeben:";
    cin >> Artikelnr;

    cin >> Menge;
    cin >> Preis;
    if (Artikelnr <= 1000)
    {
        MwStSatz = halberMwStSatz;
    }
    else
    {
        MwStSatz = ganzerMwStSatz;
    }
    Gesamtpreis = Preis * Menge + (Preis * Menge * MwStSatz/100);
    cout << MwStSatz/100;
    cout << Gesamtpreis;
    return 0;
}