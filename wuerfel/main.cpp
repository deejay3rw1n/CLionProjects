#include <iostream>
#include <cstdlib>
#include <ctime>

void wurfeln_anzahl(int anzahl_wuerfe, int wurf_results[]) {
    std::cout << "Die geworfenen Zahlen: ";
    for (int i = 0; i < anzahl_wuerfe; ++i) {
        int wuerfelzahl = rand() % 6 + 1;  // Zufällige Würfelzahl zwischen 1 und 6 generieren
        wurf_results[wuerfelzahl - 1]++;  // Die Anzahl der Würfe für die entsprechende Zahl erhöhen
        std::cout << wuerfelzahl << " ";  // Ausgabe der gewürfelten Zahl
    }
    std::cout << std::endl;
}

void auswertung(int wurf_results[], int anzahl_wuerfe) {
    for (int zahl = 1; zahl <= 6; ++zahl) {
        double prozent = static_cast<double>(wurf_results[zahl - 1]) / anzahl_wuerfe * 100;
        std::string zahl_text;
        switch (zahl) {
            case 1: zahl_text = "eins"; break;
            case 2: zahl_text = "zwei"; break;
            case 3: zahl_text = "drei"; break;
            case 4: zahl_text = "vier"; break;
            case 5: zahl_text = "fuenf"; break;
            case 6: zahl_text = "sechs"; break;
            default: zahl_text = std::to_string(zahl); break; // Wenn die Zahl nicht zwischen 1 und 6 ist, wird die Ziffer ausgegeben
        }
        std::cout << "Die Zahl " << zahl_text << " wurde mit " << prozent << "% gewuerfelt." << std::endl;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));  // Zufallsgenerator initialisieren

    int anzahl_wuerfe;
    std::cout << "Geben Sie die Anzahl der Wuerfe ein: ";
    std::cin >> anzahl_wuerfe;  // Anzahl der Würfe vom Benutzer eingeben

    int wurf_results[6] = {0};  // Array zur Aufzeichnung der Würfe für jede Zahl (Index 0 bis 5)

    wurfeln_anzahl(anzahl_wuerfe, wurf_results);
    auswertung(wurf_results, anzahl_wuerfe); // Hinzugefügt, um die Auswertung durchzuführen und die Ergebnisse auszugeben

    return 0;
}
