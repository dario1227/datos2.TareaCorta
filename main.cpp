#include "QuickSort/QuickSort.h"
#include "txt Maker/maker.h"
#include <iostream>
#include "txt Maker/BigArray.h"
using namespace std;
int main() {
    maker::make(3000);

    int array[9];
    BigArray::ordenar(array,0,299);
    BigArray::print_Array(1);
    BigArray::print_Array(2);
    BigArray::print_Array(0);
    maker::modify(3,1000);
    return 0;
}