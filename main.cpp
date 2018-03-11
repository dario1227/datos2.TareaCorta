#include "QuickSort/QuickSort.h"
#include "txt Maker/maker.h"
#include <iostream>
using namespace std;
int main() {
    int a[100];
    a[0]=25;
    a[100]=25;
    for (int i = 1; i < 100; i++) {
        a[i] = rand() % 100;
    }
    QuickSort::Start(a,0,99);
    for (int i = 0; i < 100; i++ ){
        cout << a[i] << "-";
    }
    maker::make(3000);
    maker::crear();
    return 0;
}