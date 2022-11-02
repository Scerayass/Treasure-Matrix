#ifndef ASSIGNMENT1_READFILE_H
#define ASSIGNMENT1_READFILE_H


class ReadFile {
public:
    /**
     * \n Read Txt Files and append necessary parts to dynamic arrays
     * @param mapMatrix
     * @param keyMatrix
     * @param mapMatrixFileName
     * @param keyMatrixFileName
     * @param column
     * @param keySize
     */
   void readTxt(int** mapMatrix,int** keyMatrix ,std::string mapMatrixFileName,std::string keyMatrixFileName,int column,int keySize);
};


#endif //ASSIGNMENT1_READFILE_H
