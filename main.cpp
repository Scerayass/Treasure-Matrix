#include <iostream>
#include "ReadFile.h"
#include "RecursionFunc.h"
using namespace std;
int main() {
    int mapRow = 18;
    int mapCol = 18;
    int keySize = 3;

    int** mapMatrix = new int*[18];
    int** keyMatrix = new int*[keySize];


    ReadFile readFile;
    readFile.readTxt(mapMatrix,keyMatrix,mapRow,mapCol,keySize);
    ofstream outputFile("C:\\Users\\GameGaraj\\CLionProjects\\FirstAssignment\\output.txt",ios::app);

    RecursionFunc recursionFunc;
    recursionFunc.execute(mapMatrix,keyMatrix,keySize,mapRow,mapCol);



    return 0;
}
