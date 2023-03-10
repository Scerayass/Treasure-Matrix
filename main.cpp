#include "ReadFile.h"
#include "RecursionFunc.h"
#include <string>
#include "sstream"

using namespace std;

int mapRow;
int mapCol;
int keySize;
string mapMatrixFileName;
string keyMatrixFileName;
string outputFileName;
/**
 * Read argv and declare them variables
 * @param argv
 */
void readCommand(char *argv[]){
    istringstream mapRowStream(argv[1]);

    string mapString;
    int index = 0;
    while(getline(mapRowStream,mapString,'x')){ // for first arguman , We need to delim x
        if(index == 0){
            mapRow = stoi(mapString); // Map matrix's Row
            index++;
        }else{
            mapCol = stoi(mapString); // Map matrix's col
        }
    }
    keySize = stoi(argv[2]);
    mapMatrixFileName = argv[3];
    keyMatrixFileName = argv[4];
    outputFileName = argv[5];

}

/**
 * delete selected matrixes from memory
 * @param mapMatrix
 * @param keyMatrix
 */
void deleteMatrixes(int** mapMatrix,int** keyMatrix){

    for(int i = 0 ; i < mapRow;i++){
        delete mapMatrix[i];
    }
    for(int i = 0; i < keySize; i++){
        delete keyMatrix[i];
    }
    delete[] keyMatrix;
    delete[] mapMatrix;
}

int main(int argc,char *argv[]) {
    readCommand(argv);

    int** mapMatrix = new int*[mapRow];
    int** keyMatrix = new int*[keySize];

    ReadFile readFile; // Creating readFile class to read files and adding them to matrixes
    readFile.readTxt(mapMatrix,keyMatrix,mapMatrixFileName,keyMatrixFileName,mapCol,keySize);

    RecursionFunc recursionFunc; // recursion function make recursion and add outputs to output.txt
    recursionFunc.execute(mapMatrix,keyMatrix,outputFileName,keySize,mapRow,mapCol);

    deleteMatrixes(mapMatrix,keyMatrix);
    return 0;
}






