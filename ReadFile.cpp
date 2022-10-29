#include <iostream>
#include <fstream>
#include "ReadFile.h"
#include <algorithm>
#include <string>
#include "sstream"
using namespace std;

void ReadFile::readTxt(int** mapMatrix,int** keyMatrix,string mapMatrixFileName,string keyMatrixFileName,int column ,int keySize) {

    //--------------------------------------------------- Map Matrix Side
    ifstream mapMatrixFile;
    mapMatrixFile.open(mapMatrixFileName,ios::in);

    string mapMatrixString;
    int mapIndex = 0;
    int mapWhileIndex = 0; // inner While index

    while(getline(mapMatrixFile,mapMatrixString)){
        mapMatrix[mapIndex] = new int[column]; // adding rows to mapMatrix matrix

        istringstream mapStringStream(mapMatrixString); // to make it delim , converting string to istringstream
        string whileString;

        while(getline(mapStringStream,whileString,' ')){
            mapMatrix[mapIndex][mapWhileIndex] = stoi(whileString);
            mapWhileIndex++;
        }
        mapWhileIndex = 0;
        mapIndex++;
    }
    mapMatrixFile.close();

    //--------------------------------------------------- Key Matrix Side

    ifstream keymatrixFile;
    keymatrixFile.open(keyMatrixFileName);

    string keyMatrixString;
    int keyIndex = 0;
    int keyWhileIndex = 0;// inner While index

    while(getline(keymatrixFile,keyMatrixString)){
        keyMatrix[keyIndex] =  new int[keySize];// adding rows to keyMatrix matrix

        istringstream keyStringStream(keyMatrixString); // to make it delim , converting string to istringstream
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