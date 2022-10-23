#include <iostream>
#include "ReadFile.h"
#include "RecursionFunc.h"
using namespace std;
int main() {
    int mapRow = 18;
    int mapCol = 18;
    int keySize = 3;

    int** mapMatrix = new int*[mapRow];
    int** keyMatrix = new int*[keySize];

    ReadFile readFile; // Creating readFile class to read files and adding them to matrixes
    readFile.readTxt(mapMatrix,keyMatrix,mapRow,mapCol,keySize);

    RecursionFunc recursionFunc; // recursion function make recursion and add outputs to output.txt
    recursionFunc.execute(mapMatrix,keyMatrix,keySize,mapRow,mapCol);

    for(int i = 0 ; i < mapCol;i++){
        delete mapMatrix[i];
    }
    delete mapMatrix;

    return 0;
}
