//
// Created by kenneth on 10/03/18.
//

#ifndef DATOS2_TAREACORTA_BIGARRAY_H
#define DATOS2_TAREACORTA_BIGARRAY_H


#include "maker.h"

class BigArray {
public:
    int anterior=0;
    maker* var = new maker();
    static int x[1000] ;
    static int y[1000];
    static int z[1000];
    int activateX=0;
    int activatez=0;
    int activatey=0;
    int &operator[](int index);
};


#endif //DATOS2_TAREACORTA_BIGARRAY_H
