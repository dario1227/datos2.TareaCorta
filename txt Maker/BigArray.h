//
// Created by kenneth on 10/03/18.
//

#ifndef DATOS2_TAREACORTA_BIGARRAY_H
#define DATOS2_TAREACORTA_BIGARRAY_H



class BigArray {
public:
    static int x[1000] ;
    static int y[1000];
    static int z[1000];
    int &operator[](int index);
};


#endif //DATOS2_TAREACORTA_BIGARRAY_H
