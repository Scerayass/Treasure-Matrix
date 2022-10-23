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


    ReadFile readFile;
    readFile.readTxt(mapMatrix,keyMatrix,mapRow,mapCol,keySize);
    ofstream outputFile("C:\\Users\\GameGaraj\\CLionProjects\\FirstAssignment\\output.txt",ios_base::app);

    RecursionFunc recursionFunc;
    recursionFunc.execute(mapMatrix,keyMatrix,keySize,mapRow,mapCol);

    for(int i = 0 ; i < mapCol;i++){
        delete mapMatrix[i];
    }
    delete mapMatrix;

    return 0;
}
