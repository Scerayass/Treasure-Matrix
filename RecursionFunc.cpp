#include "RecursionFunc.h"
#include <iostream>
#include <fstream>
using namespace std;

int col = 0;
int row = 0;

void RecursionFunc::execute(int** mapMatrix,int** keyMatrix,int keySize,int mapRow,int mapCol) {
    ofstream outputFile("C:\\Users\\GameGaraj\\CLionProjects\\FirstAssignment\\output.txt",ofstream::out);

    int keyMatrixRow = 0;
    int keyMatrixCol = 0;
    int sum = 0;
    cout << row << " " << col <<"\n";

    for(int i = row; i < (row + keySize);i++){

        for(int j = col; j < (col + keySize) ; j++){
            //cout << keyMatrix[keyMatrixRow][keyMatrixCol] << " "<<mapMatrix[i][j]<< "\n";
            sum += mapMatrix[i][j] * keyMatrix[keyMatrixRow][keyMatrixCol];
            keyMatrixCol++;
        }
        keyMatrixCol = 0;
        keyMatrixRow++;
    }

    string output = "";
    output += to_string(row + ((keySize -1) / 2));
    output += ",";
    output += to_string(col + ((keySize -1) / 2));
    output += ":";
    output += to_string(sum);
    cout << output << "\n";
    outputFile << output << "\n";
    outputFile << sum << " ";


    if(sum % 5 == 0){
        cout << "finished" <<"\n";

    }else{
        if (sum % 5 == 1 || sum % 5 == -4){
            if(row == 0){
                row = keySize;
            }else{
                row -= keySize;
            }
        }
        else if (sum % 5 == 2 || sum % 5 == -3){
            if(row == (mapRow - keySize)){
                row -= keySize;
            }else{
                row += keySize;
            }
        }
        else if (sum % 5 == 3 || sum % 5 == -2){
            if(col == (mapCol - keySize)){
                col -= keySize;
            }else{
                col += keySize;
            }
        }
        else if (sum % 5 == 4 || sum % 5 == -1){
            if(col == 0){
                col = keySize;
            }else{
                col -= keySize;
            }
        }

        execute(mapMatrix,keyMatrix,keySize,mapRow,mapCol);


    }




    /*
    for(int i = 0 ; i < 18;i++){

        for(int y = 0; y < 18; y++){
            cout << mapMatrix[i][y];
        }
        cout << "\n";

    }

    for(int i = 0 ; i < keySize;i++){

        for(int y = 0; y < keySize; y++){
            cout << keyMatrix[i][y];
        }
        cout << "\n";

    }*/
}

