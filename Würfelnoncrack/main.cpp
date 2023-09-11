#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h> // Für Sleep-Funktion (nur für Windows, bei anderen Betriebssystemen bitte entsprechende Funktion verwenden)

// Funktion, um den Würfel zu werfen
int werfen() {
    return rand() % 6 + 1;
}

// Funktion zur Auswertung der Würfe
void auswertung(int wurfanzahl) {
    const int seiten = 6;
    int wurfanzahl_pro_zahl[seiten] = {0};

    for (int i = 0; i < wurfanzahl; ++i) {
        int wurf = werfen();
        wurfanzahl_pro_zahl[wurf - 1]++;

        // Ausgabe des Fortschrittsbalkens mit Wurfindex
        std::cout << "\rWurf " << i + 1 << " von " << wurfanzahl << " [" << std::string((i+1) * 20 / wurfanzahl, '=') << ">" << std::string(20 - (i+1) * 20 / wurfanzahl, ' ') << "]";
        std::flush;

        Sleep(100); // Wartezeit zwischen den Würfen (100 Millisekunden)
    }
    std::cout << std::endl;

    std::cout << "Wurfanzahl pro Zahl:\n";
    for (int i = 0; i < seiten; ++i) {
        double prozent = static_cast<double>(wurfanzahl_pro_zahl[i]) / wurfanzahl * 100;
        std::cout << "Zahl " << i + 1 << ": " << prozent << "%\n";
    }
}

int main() {
    std::srand(static_cast<unsigned>(std::time(0))); // Seed für den Zufallsgenerator setzen

    int gesamt_wuerfe;
    std::cout << "Bitte geben Sie die Anzahl der Wuerfe ein: ";
    std::cin >> gesamt_wuerfe;

    if (gesamt_wuerfe <= 0) {
        std::cout << "Ungueltige Anzahl von Wuerfen. Bitte geben Sie eine positive ganze Zahl ein.\n";
        return 1;
    }

    auswertung(gesamt_wuerfe);

    return 0;
}
