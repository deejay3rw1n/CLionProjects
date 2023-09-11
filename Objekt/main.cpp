#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Konto
{
private:
    string inhaber;
    double saldo;

public:
    string GetInhaber() const
    {
        return inhaber;
    }

    void SetInhaber(const string& value)
    {
        inhaber = value;
    }

    double GetSaldo() const
    {
        return saldo;
    }

    void SetSaldo(double value)
    {
        saldo = value;
    }
};

int main()
{
    Konto meinKonto;

    meinKonto.SetInhaber("Max Mustermann");
    meinKonto.SetSaldo(1000000.00);

    cout << "Kontoinhaber: " << meinKonto.GetInhaber() << endl;
    cout << "Kontostand: " << fixed << setprecision(2) << meinKonto.GetSaldo() << " Euro" << endl;

    return 0;
}
