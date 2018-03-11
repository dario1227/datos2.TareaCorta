//
// Created by kenneth on 10/03/18.
//

#include "BigArray.h"
int BigArray::x[1000]={};
int BigArray::y[1000]={};
int BigArray::z[1000]={};
int& BigArray::operator[](int index) {
    //DEFINIR LAS FUNCIONES :C
    if(index<=999){
        if(activateX==0){
            if(anterior==1000&& activatey==1){
                activatey=0;
                anterior=index;
                var->getLine(1);
                return x[index];
            }
            activateX=1;
            var->getLine(1);
            anterior = index;
            return x[index];
        }
        else{
            anterior = index;
            return x[index];
        }

    }
    if(index>999 && index <=1999){
        if(activatey==0){
            if(anterior==999&&index==1000&&activatey==0){
                activatey=1;
                var->getLine(2);
                activateX=0;
                //MAPEAR EL ARRAY XXXXXXXXXX
                return y[index-1000];
            }
            if(anterior==2000&&index==1999){
                activatey=1;
                var->getLine(2);
                activatez=0;
                //MAPEAR YYYYY
                return y[index-1000];

            }

        }
        else{
            if(anterior==999&&index==1000&&activatey==0&&activateX==1){
                activatey=1;
                activateX=0;
                //MAPEAR EL ARRAY XXXXXXXXXX
                return y[index-1000];
            }
            if(anterior==2000&&index==1999&&activatez==1){
                activatey=1;
                activatez=0;
                //MAPEAR YYYYY
                return y[index-1000];

            }else {
                anterior = index;
                return y[index - 1000];
            }
        }

    }
    if(index>1999&& index<=2999){
        if(activatez==0){
            if(anterior==1999&&index==2000&& activatey==1){
                activatey=0;
                anterior=index;
                var->getLine(3);
                return z[index-2000];
            }
            activateX=1;
            var->getLine(3);
            anterior = index;
            return z[index-2000];
        } else{
            anterior = index;
            return z[index - 2000];
        }

    }
}
