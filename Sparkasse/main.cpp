#include <iostream>
#include <string>

class Konto {
protected:
    std::string IBAN;
    float Kontostand;

public:
    Konto(const std::string& iban, float kontostand) : IBAN(iban), Kontostand(kontostand) {}

    void Einzahlen(float betrag) {
        Kontostand += betrag;
    }

    void Abheben(float betrag) {
        Kontostand -= betrag;
    }

    void ZeigeKontoinformationen() {
        std::cout << "IBAN: " << IBAN << std::endl;
        std::cout << "Kontostand: " << Kontostand << " Euro" << std::endl;
    }
};

class Sparkonto : public Konto {
private:
    float Zinssatz;

public:
    Sparkonto(const std::string& iban, float kontostand, float zinssatz) : Konto(iban, kontostand), Zinssatz(zinssatz) {}

    void Abheben(float betrag) {
        if (Kontostand - betrag >= 0) {
            Kontostand -= betrag;
        } else {
            std::cout << "Nicht genug Guthaben auf dem Sparkonto." << std::endl;
        }
    }

    void ZinsenBerechnen() {
        float zinsen = Kontostand * (Zinssatz / 100);
        Kontostand += zinsen;
        std::cout << "Zinsen in Hoehe von " << zinsen << " Euro wurden dem Sparkonto gutgeschrieben." << std::endl;
    }
};

class Girokonto : public Konto {
private:
    float Dispogrenze;

public:
    Girokonto(const std::string& iban, float kontostand, float dispogrenze) : Konto(iban, kontostand), Dispogrenze(dispogrenze) {}

    void Abheben(float betrag) {
        if (Kontostand - betrag >= -Dispogrenze) {
            Kontostand -= betrag;
        } else {
            std::cout << "Ueberschreitung der Dispogrenze nicht erlaubt." << std::endl;
        }
    }
};

int main() {
    std::string iban;
    float startKontostand;
    char kontotyp;

    std::cout << "Bitte geben Sie die IBAN ein: ";
    std::cin >> iban;

    std::cout << "Bitte geben Sie den Startkontostand ein: ";
    std::cin >> startKontostand;

    std::cout << "Welchen Kontotyp moechten Sie erstellen? (S fuer Sparkonto, G fuer Girokonto): ";
    std::cin >> kontotyp;

    Konto* konto;

    if (kontotyp == 'S' || kontotyp == 's') {
        float zinssatz;
        std::cout << "Bitte geben Sie den Zinssatz fuer das Sparkonto ein: ";
        std::cin >> zinssatz;
        konto = new Sparkonto(iban, startKontostand, zinssatz);
    } else if (kontotyp == 'G' || kontotyp == 'g') {
        konto = new Girokonto(iban, startKontostand, 1000.0f); // Dispogrenze von 1000 Euro
    } else {
        std::cout << "Ungueltige Eingabe fuer den Kontotyp." << std::endl;
        return 1;
    }

    while (true) {
        std::cout << "Wae2hlen Sie eine Aktion (E fuer Einzahlen, A fuer Abheben, Z fuer Zinsen berechnen, I fuer Kontoinformationen anzeigen, Q fuer Beenden): ";
        char aktion;
        std::cin >> aktion;

        if (aktion == 'Q' || aktion == 'q') {
            break;
        } else if (aktion == 'E' || aktion == 'e') {
            float betrag;
            std::cout << "Bitte geben Sie den Einzahlungsbetrag ein: ";
            std::cin >> betrag;
            konto->Einzahlen(betrag);
        } else if (aktion == 'A' || aktion == 'a') {
            float betrag;
            std::cout << "Bitte geben Sie den Abhebungsbetrag ein: ";
            std::cin >> betrag;
            konto->Abheben(betrag);
        } else if (aktion == 'Z' || aktion == 'z') {
            std::cout << "Diese Aktion ist nur fuer Sparkonten verfuegbar." << std::endl;
        } else if (aktion == 'I' || aktion == 'i') {
            konto->ZeigeKontoinformationen();
        } else {
            std::cout << "Ungueltige Aktion." << std::endl;
        }
    }

    delete konto;
    return 0;
}
