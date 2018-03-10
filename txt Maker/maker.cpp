//
// Created by dario1227 on 10/03/18.
//
#include "maker.h"
#include <fstream>
#include <unistd.h>
#include <pwd.h>
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
    ofstream txt(name+"/BINARIOS.txt");
    for(int i=1; i<x;i++){
       txt<<toBinary(rand() % 100)+"\n";
    }
    txt<<toBinary(rand() % 100);
    txt.close();
}
