//
// Created by kenneth on 10/03/18.
//

#ifndef DATOS2_TAREACORTA_BIGARRAY_H
#define DATOS2_TAREACORTA_BIGARRAY_H


#include "maker.h"

class BigArray {
public:
    static const int pagesize = 1000;
    int anterior=0;
    maker* var = new maker();
    static int x[pagesize] ;
    static int y[pagesize];
    static int z[pagesize];
    void ordenar(int *array, int start, int end);
    int activateX=0;
    int activatez=0;
    int activatey=0;
    int &operator[](int index);
};


#endif //DATOS2_TAREACORTA_BIGARRAY_H
