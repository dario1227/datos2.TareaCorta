#include <iostream>
#include "QuickSort/QuickSort.h"
using namespace std;
int main() {
    int a[100];
    for (int i = 0; i < 100; i++) {
        a[i] = rand() % 100;
    }
    QuickSort::Start(a,0,99);
    for (int i = 0; i < 100; i++ ){
        cout << a[i] << "-";
    }
    return 0;
}