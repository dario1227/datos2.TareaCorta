//
// Created by kenneth on 10/03/18.
//

#ifndef DATOS2_TAREACORTA_BIGARRAY_H
#define DATOS2_TAREACORTA_BIGARRAY_H


#include "maker.h"
#include <iostream>
class BigArray {
public:
    static const int pagesize = 200;
    int anterior=0;
    maker* var = new maker();
    static int* x  ;
    static int* y ;
    static int *z ;
    static void ordenar(int *array, int start, int end);
    static void ordenar2(int *array, int start, int end);
    int activateX=0;
    int activatez=0;
    int activatey=0;
    int &operator[](int index);
   static  void print_Array(int numeroPag);
    void Ordena_Pag();

    void switchPage(int index, int anterior);
};


#endif //DATOS2_TAREACORTA_BIGARRAY_H
