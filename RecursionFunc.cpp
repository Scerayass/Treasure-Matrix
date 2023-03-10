#include "RecursionFunc.h"
#include <iostream>
#include <fstream>
using namespace std;

//starting positions
int col = 0;
int row = 0;

void RecursionFunc::execute(int** mapMatrix,int** keyMatrix,string outputFileName,int keySize,int mapRow,int mapCol) {
    fstream outputFile(outputFileName,ios::app | ios::in | ios::out);

    int sum = 0;
    int keyMatrixRow = 0;
    int keyMatrixCol = 0;

    for(int i = row; i < (row + keySize);i++){ // this loop calculates the sum of matrices
        for(int j = col; j < (col + keySize) ; j++){
            sum += mapMatrix[i][j] * keyMatrix[keyMatrixRow][keyMatrixCol];

            keyMatrixCol++;
        }
        keyMatrixCol = 0;
        keyMatrixRow++;
    }

    // creating output string and appending to output.txt
    // ---------
    string output = "";
    output += to_string(row + ((keySize -1) / 2));
    output += ",";
    output += to_string(col + ((keySize -1) / 2));
    output += ":";
    if(sum < 0 ){ sum = (sum % 5) + 5;} // for negative sum values
    output += to_string(sum);
    outputFile << output << "\n";
    outputFile.seekg(0);
    // ---------

    if(sum % 5 == 0){
        // recursion ends
    }else{
        // start Recursion
        if (sum % 5 == 1 || sum % 5 == -4){
            if(row == 0){ // if it is top
                row = keySize;
            }else{
                row -= keySize;
            }
        }
        else if (sum % 5 == 2 || sum % 5 == -3){
            if(row == (mapRow - keySize)){ // if it is bottom
                row -= keySize;
            }else{
                row += keySize;
            }
        }
        else if (sum % 5 == 3 || sum % 5 == -2){
            if(col == (mapCol - keySize)){ // if it is right
                col -= keySize;
            }else{
                col += keySize;
            }
        }
        else if (sum % 5 == 4 || sum % 5 == -1){
            if(col == 0){ // if it is left
                col = keySize;
            }else{
                col -= keySize;
            }
        }
        execute(mapMatrix,keyMatrix,outputFileName,keySize,mapRow,mapCol); // recursion
    }
}

