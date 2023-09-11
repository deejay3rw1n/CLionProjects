#include <iostream>
#include <string>
using namespace std;

int main() {
   string neukunde_oder_nicht;
   cout << "Eingabe Neukunde oder nicht (Ja/Nein): ";
   cin >> neukunde_oder_nicht;
   double kWh_pro_Jahr;
   cout << "Eingabe kWh pro Jahr: ";
   cin >> kWh_pro_Jahr;

    double GPreis; // Grundpreis
    double Nettopreis;
    const double Steuer = 0.19;

    if (kWh_pro_Jahr <= 10000) {
        GPreis = 150;
        Nettopreis = GPreis + kWh_pro_Jahr * 0.438;
    } else if (kWh_pro_Jahr <= 50000) {
        GPreis = 300;
        Nettopreis = GPreis + kWh_pro_Jahr * 0.408;
    } else if (500000 < kWh_pro_Jahr && kWh_pro_Jahr <= 300000) {
        GPreis = 835;
        Nettopreis = GPreis + kWh_pro_Jahr * 0.39;
    } else if (kWh_pro_Jahr > 5000000) {
        cout << "Betrag ausserhalb des Privatkundenverbrauchs. Bitte        kontaktieren sie den Kundensupport oder die Hotline fuer Geschaeftskunden";
        return 0;
    } else {
        GPreis = 130;
        Nettopreis = GPreis + kWh_pro_Jahr * 0.458;
    }

    if (neukunde_oder_nicht == "Ja") {
        Nettopreis = Nettopreis - 100;
    } else {
        Nettopreis = Nettopreis;
    }

    cout << "Grundpreis: " << GPreis << endl;
    cout << "Nettopreis: " << Nettopreis << endl;
    cout << "Bruttopreis: " << Nettopreis + (Steuer * Nettopreis) << endl;

    return 0;
}