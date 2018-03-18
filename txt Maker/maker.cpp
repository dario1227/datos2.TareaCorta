//
// Created by dario1227 on 10/03/18.
//
#include "maker.h"
#include "BigArray.h"
#include <fstream>
#include <unistd.h>
#include <pwd.h>
#include <vector>
#include <iostream>
#include <math.h>
#include <cstring>
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
    string result;
    for(int i=1;i<=num.length();i++){
        result+=num[num.length()-i];
    }
    return result;
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
void maker::modify(int x, int reemplazo) {
    int i=0;
    string line;
    struct passwd *pw = getpwuid(getuid());
    const char *homedir = pw->pw_dir;
    string name=homedir;
    ofstream txt(name+"/BINARIOSTEMP.txt");
    ifstream read(name+"/BINARIOS.txt" );
    while(getline(read,line)){
        if(i==x){
            txt<<toBinary(reemplazo)<<"\n";
            cout<<"///////"<<toBinary(reemplazo)<<"\n";
        }
        else{
            txt<<line<<"\n";
        }
        i++;
    }
    string rem1=name+"/BINARIOSTEMP.txt";
    string rem2=name+"/BINARIOS.txt";
    rename(rem1.c_str(),rem2.c_str() );
    txt.close();

}
void maker::read() {
    long array[3000];
    int i=0;
    string line;
    struct passwd *pw = getpwuid(getuid());
    const char *homedir = pw->pw_dir;
    string name=homedir;
    ifstream txt(name+"/BINARIOS.txt");
    while(getline(txt,line)){
        "2";
        array[i]=toDecimal(std::stol(line));
        i++;
    }
    for(int y=0; y<3000;y++){
        cout<<"\n"<<array[y];
    }

}
int* maker::getLine(int x){
    if(x==1){
        return sacaArr1();
    }
    if(x==2){
        return sacaArr2();
    }
    else{
        return sacaArr3();
}
//    int i=0;
//    string line;
//    struct passwd *pw = getpwuid(getuid());
//    const char *homedir = pw->pw_dir;
//    string name=homedir;
//    ifstream txt(name+"/BINARIOS.txt");
//    while(getline(txt,line)){
//        if(x==i){
//            return toDecimal(std::stol(line));
//        }
//        else{
//            i++;
//        }
//    }


}
int* maker::sacaArr1() {
    int i=0;
    string line;
    struct passwd *pw = getpwuid(getuid());
    const char *homedir = pw->pw_dir;
    string name=homedir;
    ifstream txt(name+"/BINARIOS.txt");
    while(getline(txt,line) && i<BigArray::pagesize){
         BigArray::x[i] =toDecimal(std::stol(line));
            i++;
    }
    return nullptr;
}

int *maker::sacaArr3() {
    int i=0;
    string line;
    struct passwd *pw = getpwuid(getuid());
    const char *homedir = pw->pw_dir;
    string name=homedir;
    ifstream txt(name+"/BINARIOS.txt");
    while(getline(txt,line) && i<=1999){
        if(i>BigArray::pagesize-1 && i<BigArray::pagesize*2){
            BigArray::y[i%BigArray::pagesize] =toDecimal(std::stol(line));}
        i++;
    }
    return nullptr;
}

int *maker::sacaArr2() {
    int i=0;
    string line;
    struct passwd *pw = getpwuid(getuid());
    const char *homedir = pw->pw_dir;
    string name=homedir;
    ifstream txt(name+"/BINARIOS.txt");
    while(getline(txt,line) && i<BigArray::pagesize*3){
        if(i>BigArray::pagesize*2-1 && i<BigArray::pagesize*3){
            BigArray::z[i%BigArray::pagesize] =toDecimal(std::stol(line));}
        i++;
    }
    return nullptr;}
