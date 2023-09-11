#include <iostream>
const int NUM_SLOTS = 10;
const int NUM_DAYS = 30;
int schedule[NUM_DAYS][NUM_SLOTS]; // Mehrdimensionale Felder für die Terminplanung
void initializeSchedule()
{
for (int i = 0; i < NUM_DAYS; i++) {
for (int j = 0; j < NUM_SLOTS; j++) {
schedule[i][j] = 0; // Alle Termine sind frei
}
}
}
void bookAppointment() {
    int day, slot;
    for (int i = 0; i < 3; i++) {
        std::cout << "Geben Sie den Tag ein (1-" << NUM_DAYS << "): ";
        std::cin >> day;
        std::cout << "Geben Sie den Zeitfenster ein (1-" << NUM_SLOTS << "): ";
        std::cin >> slot;
        schedule[day - 1][slot - 1] = 1; // Termin belegen
        }
    }
    void displaySchedule()
    {
        std::cout << "Tag | Terminplanung\n";
        for (int i = 0; i < NUM_DAYS; i++) {
            std::cout << i + 1 << "   | ";
            for (int j = 0; j < NUM_SLOTS; j++) {
                std::cout << schedule[i][j] << " ";
            }
            std::cout << "\n";
        }
    }
    int main()
    {
        initializeSchedule();
        bookAppointment();
        displaySchedule();
        return 0;
    }