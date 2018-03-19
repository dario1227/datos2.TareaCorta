#include "QuickSort/QuickSort.h"
#include "txt Maker/maker.h"
#include <iostream>
#include "txt Maker/BigArray.h"
using namespace std;
int main() {
    maker::make(BigArray::pagesize*3);
    int *saca = new int[9];
    saca[9]=23;
   // std::cout<<saca[9];
    delete[] saca;
    saca= nullptr;
    saca=new int[9];
    if (saca== nullptr){
        std::cout<<"HOLOADIJKALD";
    }

    BigArray::ordenar2(new int[0],0,599);
    return 0;
}