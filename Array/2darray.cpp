#include <iostream>
using namespace std;

int main() {

    int mat[3][3];   
    int row = 3;
    int col = 3;

    cout << "Enter 9 elements for 3x3 matrix:\n";

    
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> mat[i][j];
        }
    }

    cout << "\nMatrix is:\n";

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}