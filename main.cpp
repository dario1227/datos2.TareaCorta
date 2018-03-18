#include "QuickSort/QuickSort.h"
#include "txt Maker/maker.h"
#include <iostream>
#include "txt Maker/BigArray.h"
using namespace std;
int main() {
    maker::make(3000);
    maker* var = new maker();
   int array[100];
   var->getLine(1);
    QuickSort::Start(array,0,100);
    int inx = 0;
    while (inx<100){
      std::cout<<BigArray::x[inx]<<",";
       inx++;
    }
    BigArray::ordenar(array,0,299);
    BigArray::print_Array(0);
    BigArray::print_Array(1);
    BigArray::print_Array(2);
    return 0;
}