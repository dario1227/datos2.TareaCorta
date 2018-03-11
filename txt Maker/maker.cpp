//
// Created by dario1227 on 10/03/18.
//
#include "maker.h"
#include <fstream>
#include <unistd.h>
#include <pwd.h>
#include <vector>
#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;
int toDecimal(long x){
    int d=0,p=0,a=0;
    while(x!=0){
        a=x%10;
        d=d+a*pow(2,p);
        p++;
        x/=10;
    }
    return d;
}
string toBinary(int x){
        string num;
    if (x==0){
        return toBinary(rand() % 10000);
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
    ofstream txt(name+"/BINARIOS.txt");
    for(int i=1; i<x;i++){
       txt<<toBinary(rand() % 10000)+"\n";
    }
    txt<<toBinary(rand() % 10000);
    txt.close();
}

void maker::read() {
    long array[1000];
    int i=0;
    string line;
    struct passwd *pw = getpwuid(getuid());
    const char *homedir = pw->pw_dir;
    string name=homedir;
    ifstream txt(name+"/BINARIOS.txt");
    while(getline(txt,line)){
        array[i]=toDecimal(std::stol(line));
        i++;
    }
    for(int y=0; y<1000;y++){
        cout<<"\n"<<array[y];
    }

}
