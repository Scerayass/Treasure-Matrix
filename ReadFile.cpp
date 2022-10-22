#include <iostream>
#include <fstream>
#include "ReadFile.h"
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

void ReadFile::readTxt(int** mapMatrix,int** keyMatrix,int row,int column ,int keySize) {
    ifstream mapMatrixFile;
    mapMatrixFile.open("C:\\Users\\GameGaraj\\CLionProjects\\FirstAssignment\\mapmatrix.txt",ios::in);

    string mapMatrixString;

    int indexMap = 0;
    while(getline(mapMatrixFile,mapMatrixString)){
        mapMatrix[indexMap] = new int[column];
        mapMatrixString.erase(remove( mapMatrixString.begin() , mapMatrixString.end() ,' ') , mapMatrixString.end());

        for(int i = 0 ; i < column; i++){

            //mapMatrix[indexMap][i] = stoi(mapMatrixString[0]);
            mapMatrix[indexMap][i] = mapMatrixString[i] - '0';
        }
        indexMap++;
    }
    mapMatrixFile.close();

    //---------------------------------------------------

    ifstream keymatrixFile;
    keymatrixFile.open("C:\\Users\\GameGaraj\\CLionProjects\\FirstAssignment\\keymatrix.txt");

    string keyMatrixString;
    int indexKey = 0;
    while (getline(keymatrixFile,keyMatrixString)){
        keyMatrix[indexKey] =  new int[keySize];
        keyMatrixString.erase( remove ( keyMatrixString.begin() , keyMatrixString.end() , ' ' ) , keyMatrixString.end());

        for(int i = 0 ; i < keySize ; i++){
            keyMatrix[indexKey][i] = keyMatrixString[i] - '0';
        }
        indexKey++;

    }
    keymatrixFile.close();
}