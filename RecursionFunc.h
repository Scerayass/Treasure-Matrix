#ifndef FIRSTASSIGNMENT_RECURSIONFUNC_H
#define FIRSTASSIGNMENT_RECURSIONFUNC_H
#include <iostream>
#include <fstream>

class RecursionFunc {
public:
    /**
     *
     * \n Starting to Recursion function
     *
     *
     * @param mapMatrix
     * @param keyMatrix
     * @param outputFileName
     * @param keySize
     * @param mapRow
     * @param mapCol
     */
    void execute(int** mapMatrix,int** keyMatrix,std::string outputFileName,int keySize,int mapRow,int mapCol);
};


#endif //FIRSTASSIGNMENT_RECURSIONFUNC_H
