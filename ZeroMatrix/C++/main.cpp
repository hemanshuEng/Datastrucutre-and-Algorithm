#include <iostream>
#include <vector>
void nullifyRow(std::vector <std::vector<int>> &matrix ,int row) {
    for (int j = 0; j < matrix[0].size(); j++) {
        matrix[row][j] = 0;
    }
}
void nullifyColumn(std::vector <std::vector<int>> &matrix ,int column) {
    for (int i = 0; i < matrix.size(); i++) {
        matrix[i][column] = 0;
    }
}
void setZeros( std::vector <std::vector<int>> &matrix) {
    bool rowHasZero = false;
    bool columnHasZero = false;
    for (int j = 0; j < matrix[0].size(); j++) {
        if(matrix[0][j] == 0) {
            rowHasZero = true;
            break;
        }
    }
    for (int j = 0; j < matrix[0].size(); j++) {
        if(matrix[0][j] == 0) {
            columnHasZero = true;
            break;
        }
    }
    for (int i = 1; i< matrix.size(); i++) {
        for (int j = 1; j< matrix[0].size(); j++) {
            if(matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for (int i = 1; i < matrix.size(); i++) {
       if (matrix[i][0] == 0){
           nullifyRow(matrix,i);
       }
    }
    for (int j = 1; j < matrix[0].size(); j++) {
        if (matrix[0][j] == 0){
            nullifyColumn(matrix,j);
        }
    }
    if(rowHasZero) {
        nullifyRow(matrix,0);
    }
    if(columnHasZero) {
        nullifyColumn(matrix,0);
    }
}
void printMatrix(const std::vector<std::vector<int>> &matrix) {
    for ( int i = 0; i < matrix.size(); ++i ) {
        for( int j = 0; j < matrix[0].size(); ++j ) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
int main() {
    int N=0,M=0;
    std::cout <<"Enter Row for Matrix :";
    std::cin >> N;
    std::cout <<"Enter Column for Matrix :";
    std::cin >> M;
    std::vector <std::vector<int>> matrix1(N,std::vector<int>(M));
    for ( int i = 0; i < N; ++i) {
        for ( int j = 0; j < M; ++j ) {
            std::cout << "position(" <<i << ","<<j<<" ) : " ;
            std::cin >> matrix1[i][j];
            std::cout<<std::endl;
        }
    }
    std::cout << "matrix before zero"<<std::endl ;
    printMatrix(matrix1);
    setZeros(matrix1);
    std::cout << "matrix after zero"<<std::endl ;
    printMatrix(matrix1);
    return 0;
}
