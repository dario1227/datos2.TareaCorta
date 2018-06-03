//
// Created by kenneth on 10/03/18.
//

#include <cmath>
#include "BigArray.h"
#include <iostream>

int* BigArray::x;
int* BigArray::y;
int* BigArray::z;
BigArray* var = new  BigArray();
int divide(int *lol, int start, int end) {

    int left;
    int right;
    int pivot;
    int temp;

    pivot = (*var)[start];
    left = start;
    right = end;
    while (left < right) {
        while ((*var)[right] > pivot) {
            right--;
        }

        while ((left < right) && ((*var)[left] <= pivot)) {
            left++;
        }

        if (left < right) {
            std::cout<<"ARRAY SE HIZO CAMBIO  "<<"LL";
            temp = (*var)[left];
            (*var)[left] = (*var)[right];
            (*var)[right] = temp;
        }
    }

    temp = (*var)[right];
    (*var)[right] = (*var)[start];
    (*var)[start] = temp;

    return right;
}
void BigArray::ordenar2(int *array, int start, int end) {
    BigArray::ordenar(array,start,end);
    maker::writeX();

    maker::writeY();
    maker::writteZ();
}

void BigArray::ordenar(int *array, int start, int end) {
    int pivot;

    if (start < end) {
        std::cout<<"ARRAY SE HIZO CAMBIO  "<<"LL";
        pivot = divide(array, start, end);
        std::cout<<"Numero de pagina arreglada:  "<<"LOL";
        BigArray::ordenar(array, start, pivot - 1);
        BigArray::ordenar(array, pivot + 1, end);
    }

}
int& BigArray::operator[](int index) {
    if(index == pagesize-1||index == pagesize||index == pagesize*2-1 || index == pagesize*2 ){
        maker::writeX();
        maker::writeY();
        maker::writteZ();
        x= nullptr;
        y = nullptr;
        z = nullptr;
    }
    //switchPage(index,anterior);
    int index_2 = floor(index/pagesize);
    std::cout<<index_2<<"\n";
    if(index_2==0){
        if(x == nullptr){
            var->getLine(1);
        }
        if(activateX==0){
            activateX=1;
            var->getLine(1);
            anterior = index;
            return x[index%pagesize];
        }
        else{
            if(anterior%pagesize==0){
                anterior=index;
                return x[index%pagesize];
                }
            anterior = index;
            return x[index%pagesize];
        }
    }
    if(index_2==1){
        if(y == nullptr){
            var->getLine(2);
        }
        if(activatey==0){

            if(anterior==pagesize-1&&index%pagesize==0){
                activatey=1;
                var->getLine(2);

                return y[index%pagesize];
            }
            if(anterior%pagesize==0&&index%pagesize==pagesize-1){
                std::cout<<"Numero de pagina arreglada:  "<<"LOL";

                activatey=1;
                var->getLine(2);
                return y[index%pagesize];
            }
        }
        else{
            if(y == nullptr){
                var->getLine(3);
            }
            if(anterior==pagesize-1&&index%pagesize==0){
                activatey=1;
                return y[index%pagesize];
            }
            if(anterior%pagesize==0&&index%pagesize==pagesize-1){
                activatey=1;
                return y[index%pagesize];

            }else {
                anterior = index;
                return y[index%pagesize];
            }
        }
    }
    if(index_2==2){
        if(z== nullptr){
            var->getLine(3);
        }
        if(activatez==0){
            if(anterior==pagesize*2 -1 &&index%pagesize==0){
                activatez=1;
                anterior=index;
                var->getLine(3);
                return z[index%pagesize];
            }

            activatez=1;
            var->getLine(3);
            anterior = index;
            return z[index%pagesize];
        } else{
            anterior = index;
            return z[index%pagesize];
        }
    }
    return z[pagesize-1];
}
void BigArray::print_Array(int numeroPag) {

    std::cout<<"Numero de pagina arreglada:  "<<numeroPag;
    int index = 0;
    while(index<pagesize){
        if(numeroPag==0){
            std::cout<<","<<BigArray::x[index];
        }
        if(numeroPag==1){
            std::cout<<","<<BigArray::y[index];
        }
        if(numeroPag==2){
            std::cout<<","<<BigArray::z[index];
        }
        index++;
    }
}

void BigArray::switchPage(int index, int anterior) {
    if(anterior==pagesize-1&& index==pagesize){
        activateX=0;
        if(BigArray::x== nullptr){
            var->getLine(1);
        }
        maker::writeX();
    }
//    if(anterior==pagesize&&index==pagesize-1){
//        if(BigArray::y== nullptr){
//            var->getLine(2);
//        }
//        activatey=0;
//        maker::writeY();
//    }
    if(anterior==pagesize*2&&index==pagesize*2 -1){
        if(BigArray::z== nullptr){
            var->getLine(3);
        }

        activatez=0;
        maker::writteZ();
    }
//    if(anterior==pagesize*2-1&& index==pagesize*2){
//        if(BigArray::y== nullptr){
//            var->getLine(2);
//        }
//        activatey=0;
//        maker::writeY();
//    }
}
