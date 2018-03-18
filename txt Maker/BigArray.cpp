//
// Created by kenneth on 10/03/18.
//

#include <cmath>
#include "BigArray.h"
#include <iostream>

int BigArray::x[pagesize]={};
int BigArray::y[pagesize]={};
int BigArray::z[pagesize]={};
int divide(int *array, int start, int end) {
    int left;
    int right;
    int pivot;
    int temp;

    pivot = array[start];
    left = start;
    right = end;
    while (left < right) {
        while (array[right] > pivot) {
            right--;
        }

        while ((left < right) && (array[left] <= pivot)) {
            left++;
        }

        if (left < right) {
            temp = array[left];
            array[left] = array[right];
            array[right] = temp;
        }
    }

    temp = array[right];
    array[right] = array[start];
    array[start] = temp;

    return right;
}
void BigArray::ordenar(int *array, int start, int end) {
    int pivot;

    if (start < end) {
        pivot = divide(array, start, end);

        BigArray::ordenar(array, start, pivot - 1);
        BigArray::ordenar(array, pivot + 1, end);
    }

}
int& BigArray::operator[](int index) {
    int index_2 = floor(index/pagesize);
    if(index_2==0){
        if(activateX==0){
            activateX=1;
            var->getLine(1);
            anterior = index;
            return x[index%pagesize];
        }
        else{
            if(anterior%pagesize==0){
                activatey=0;
                anterior=index;
                return x[index%pagesize];
                }
            anterior = index;
            return x[index%pagesize];
        }

    }
    if(index_2==1){
        if(activatey==0){
            if(anterior==pagesize-1&&index%pagesize==0){
                activatey=1;
                var->getLine(2);
                activateX=0;
                return y[index%pagesize];
            }
            if(anterior%pagesize==0&&index%pagesize==pagesize-1){
                activatey=1;
                var->getLine(2);
                activatez=0;
                return y[index%pagesize];

            }


        }
        else{
            if(anterior==pagesize-1&&index%pagesize==0){
                activatey=1;
                activateX=0;
                return y[index%pagesize];
            }
            if(anterior%pagesize==0&&index%pagesize==pagesize-1){
                activatey=1;
                activatez=0;
                return y[index%pagesize];

            }else {
                anterior = index;
                return y[index%pagesize];
            }
        }

    }
    if(index_2==2){
        if(activatez==0){
            if(anterior==pagesize*2 -1 &&index%pagesize==0){
                activatey=0;
                anterior=index;
                var->getLine(3);
                return z[index%pagesize];
            }
            activateX=1;
            var->getLine(3);
            anterior = index;
            return z[index%pagesize];
        } else{
            anterior = index;
            return z[index%pagesize];
        }

    }
}
void BigArray::print_Array(int numeroPag) {
    std::cout<<"Numero de pagina arreglada:  "<<numeroPag;
    int index = 0;
    while(index<pagesize){
        if(numeroPag==0){
            std::cout<<""<<BigArray::x[index];
        }
        if(numeroPag==1){
            std::cout<<""<<BigArray::y[index];
        }
        if(numeroPag==2){
            std::cout<<""<<BigArray::z[index];
        }
        index++;
    }
}
