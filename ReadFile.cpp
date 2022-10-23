#include <iostream>
#include <fstream>
#include "ReadFile.h"
#include <cstring>
#include <algorithm>
#include <string>
#include "sstream"
using namespace std;

void ReadFile::readTxt(int** mapMatrix,int** keyMatrix,int row,int column ,int keySize) {
    ifstream mapMatrixFile;
    mapMatrixFile.open("C:\\Users\\GameGaraj\\CLionProjects\\FirstAssignment\\mapmatrix.txt",ios::in);

    string mapMatrixString;

    /*
    while(getline(mapMatrixFile,mapMatrixString)){
        mapMatrix[indexMap] = new int[column];
        mapMatrixString.erase(remove( mapMatrixString.begin() , mapMatrixString.end() ,' ') , mapMatrixString.end());

        for(int i = 0 ; i < column; i++){

            //mapMatrix[indexMap][i] = stoi(mapMatrixString[0]);
            mapMatrix[indexMap][i] = mapMatrixString[i] - '0';
        }
        indexMap++;
    }*/
    int mapIndex = 0;
    int mapWhileIndex = 0;
    while(getline(mapMatrixFile,mapMatrixString)){
        mapMatrix[mapIndex] = new int[column];

        istringstream mapStringStream(mapMatrixString);
        string whileString;
        while(getline(mapStringStream,whileString,' ')){
            mapMatrix[mapIndex][mapWhileIndex] = stoi(whileString);
            mapWhileIndex++;
        }
        mapWhileIndex = 0;
        mapIndex++;

    }


    mapMatrixFile.close();

    //--------------------------------------------------- KeyMatrix Side

    ifstream keymatrixFile;
    keymatrixFile.open("C:\\Users\\GameGaraj\\CLionProjects\\FirstAssignment\\keymatrix.txt");

    string keyMatrixString;

    int keyIndex = 0;
    /*
    while (getline(keymatrixFile,keyMatrixString)){
        keyMatrix[keyIndex] =  new int[keySize];
        keyMatrixString.erase( remove ( keyMatrixString.begin() , keyMatrixString.end() , ' ' ) , keyMatrixString.end());

        for(int i = 0 ; i < keySize ; i++){
            cout << keyMatrixString[i] - '0' << "\n";
            keyMatrix[keyIndex][i] = keyMatrixString[i] - '0';
        }
        keyIndex++;

    }*/

    int keyWhileIndex = 0;
    while(getline(keymatrixFile,keyMatrixString)){
        keyMatrix[keyIndex] =  new int[keySize];
        //cout << keyMatrixString ;
        istringstream keyStringStream(keyMatrixString);
        string whileString;

        while (getline(keyStringStream,whileString,' ')){


            keyMatrix[keyIndex][keyWhileIndex]= stoi(whileString);
            keyWhileIndex++;
        }
        keyIndex++;
        keyWhileIndex = 0;
    }

    keymatrixFile.close();
}