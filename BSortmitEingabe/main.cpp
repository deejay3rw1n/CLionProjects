#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
void swap(int&, int&);
void ausgabe(int[] , int );
void bubbleSort(int[], int);
void einlesen(int [],int, int, int);
void einlesen(int [],int[],int, int, int);
int main(int argc, char const *argv[])
{

    srand((unsigned) time(NULL));
    const int LENGTH = 1000;
    int list1[LENGTH];
    int list2[LENGTH];

    einlesen(list1,list2,LENGTH, 0, 2000);
    bubbleSort(list1,LENGTH);
    ausgabe(list1,LENGTH);
    return 0;
}
void einlesen(int list[],int size, int min, int max) {
    for (int i = 0; i < size; ++i) {
        float randFloat = (float) rand()/RAND_MAX;
        list[i] = (int) (randFloat * (max - min)) + min;
    }
}
void einlesen(int list1[],int list2[],int size, int min, int max) {
    for (int i = 0; i < size; ++i) {
        float randFloat = (float) rand()/RAND_MAX;
        list1[i] =list2[i]= (int) (randFloat * (max - min)) + min;
    }
}
void bubbleSort(int list[],int size) {
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 0; i < size - 1; ++i) {
            if (list[i] > list[i + 1]) {
                sorted = false;
                swap(list[i], list[i+1]);
            }
        }
    }
}
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
void ausgabe(int list[],int size) {
    cout << "[";
    for (int i = 0; i < size; ++i) {
        cout << list[i];
        if (i < size - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}