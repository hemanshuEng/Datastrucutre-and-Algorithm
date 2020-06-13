#include <iostream>
#include <vector>
/**
 * Rotate Matrix : Given an image represented by an NxN matrix, where each pixel in the image is 4
 * bytes, write a method to rotate the image by 90 degrees. Can you do this in place?
 *
 */

bool rotate (std::vector <std::vector<int>> &matrix) {
    if( matrix.empty() || matrix.size() != matrix[0].size()) {
        std::cout << "matrix is not square";
        return false;
    }
    for (int layer = 0; layer < matrix.size()/2; layer++) {
        int first = layer;
        int last = matrix.size() - 1 - layer;
        for (int i = first; i <last; i++) {
            int offset = i - first;
            int top = matrix[first][i];
            matrix[first][i] = matrix[last-offset][first];
            matrix[last-offset][first] = matrix[last][last-offset];
            matrix[last][last-offset] = matrix[i][last];
            matrix[i][last] = top;
        }
    }
    return true;
}
void printMatrix(const std::vector<std::vector<int>> &matrix) {
    for ( int i = 0; i < matrix.size(); ++i ) {
        for( int j = 0; j < matrix.size(); ++j ) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
int main() {
    int N=0;
    std::cout <<"Enter N for Matrix :";
    std::cin >> N;
    std::vector <std::vector<int>> matrix1(N,std::vector<int>(N));
    for ( int i = 0; i < N; ++i) {
        for ( int j = 0; j < N; ++j ) {
            std::cout << "position(" <<i << ","<<j<<" ) : ";
            std::cin >> matrix1[i][j];
        }
    }
    rotate(matrix1);
    printMatrix(matrix1);
    return 0;
}
