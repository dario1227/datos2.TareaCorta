//
// Created by dario1227 on 10/03/18.
//
#include "maker.h"
#include <fstream>
#include <unistd.h>
#include <pwd.h>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
string toBinary(int x){
        string num;
    if (x==0){
        num+=to_string(0);
    }
    else {
        while (x > 0) {
            num += to_string(x % 2);
            x = x / 2;
        }
    }
    return num;
}
void maker::make(int x) {
    struct passwd *pw = getpwuid(getuid());
    const char *homedir = pw->pw_dir;
    string name=homedir;
    ofstream txt(name+"/BINARIOS.bin");
    for(int i=1; i<x;i++){
       txt<<toBinary(rand() % 10000)+"\n";
    }
    txt<<toBinary(rand() % 10000);
    txt.close();
}
void maker::crear() {
    struct passwd *pw = getpwuid(getuid());
    const char *homedir = pw->pw_dir;
    string name=homedir;
    int noOfIntegers = 1000;

//generate array
    int array[noOfIntegers];

//construct a binary input file stream
    ifstream in ( name+"/BINARIOS.bin" , ifstream::binary );

    //check stream has opened correctly - this is a bit poor you
    //should really be a bit more careful than this.
    if(in)
    {
        cout << "\n" ;
        for(int i = 0; i<noOfIntegers; i++)
        {
            //use formatted extraction operation to put integer value
            //into array
            in >> array[i];
            cout << array[i] << "-";
        }
    }
    in.close();

}