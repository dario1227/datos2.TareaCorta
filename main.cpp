#include "QuickSort/QuickSort.h"
#include "txt Maker/maker.h"
#include <iostream>
#include "txt Maker/BigArray.h"
using namespace std;
int main() {
    maker::make(3000);
    int array[3000];
    BigArray::ordenar(array,0,3000);
    BigArray::print_Array(1);
    return 0;
}