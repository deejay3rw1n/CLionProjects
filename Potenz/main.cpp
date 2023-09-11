#include <iostream>
#include <cmath>

class PotenzInterface {
public:
    virtual double berechnePotenz() = 0;
    virtual void liesPotenz() = 0;
    virtual ~PotenzInterface() {}
};

class Potenz : public PotenzInterface {
private:
    double basis;
    double exponent;
    double potenz;

public:
    Potenz() : basis(0.0), exponent(0.0), potenz(0.0) {}

    double berechnePotenz() override {
        potenz = std::pow(basis, exponent);
        return potenz;
    }

    void liesPotenz() override {
        std::cout << "Gib die Basis ein: ";
        std::cin >> basis;
        std::cout << "Gib einen Exponenten ein: ";
        std::cin >> exponent;
        potenz = std::pow(basis, exponent);
    }
};

int main() {
    Potenz potenz_objekt;
    potenz_objekt.liesPotenz();
    std::cout << "Berechnete Potenz: " << potenz_objekt.berechnePotenz() << std::endl;

    return 0;
}
