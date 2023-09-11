
#include <iostream>
using namespace std;

int main()
{
    double Stueckpreis, Menge, MwstSatz, Rabatt, Rabattbetrag, MwstBetrag, Rechnungsbetrag;
    char Kunde;
    cout << "Stueckpreis : ";
    cin >> Stueckpreis;
    cout << "Menge : ";
    cin >> Menge;
    cout << "MwstSatz : ";
    cin >> MwstSatz;
    double Netto = Stueckpreis * Menge;

    if (MwstSatz == 0)
    {
        MwstSatz = 0.07;
    }
    else
    {
        MwstSatz = 0.19;
    }

    if (Netto > 50)
    {
        cout << "Kunde: ";
        cin >> Kunde;
        switch (Kunde)
        {
            case 'G':
                Rabatt = 0.05;
                break;
            case 'W':
                Rabatt = 0.03;
                break;
            case 'E':
                Rabatt = 0.01;
                break;
            default:
                Rabatt = 0;
                break;
        }
    }
    else
    {
        Rabatt = 0;
    }

    Rabattbetrag = Netto * Rabatt;
    Netto = Netto - Rabattbetrag;
    MwstBetrag = Netto * MwstSatz;
    Rechnungsbetrag = Netto + MwstBetrag;
    cout << "Rechnungsbetrag: " << Rechnungsbetrag << " Rabattbetrag: " << Rabattbetrag << " MwstSatz: " << MwstSatz;
}

