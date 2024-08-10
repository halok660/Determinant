#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int det(vector<vector<int>> mat, int n) {
    if (n == 1) {
        return mat[0][0];
    }
    if (n == 2) {
        return (mat[0][0] * mat[1][1]) - (mat[0][1] * mat[1][0]);
    }
    int deti = 0;
    vector<vector<int>> submat(n, vector<int>(n));
    for (int k = 0; k < n; k++) {
        int subi = 0;
        for (int i = 1; i < n; i++) {
            int subj = 0;
            for (int j = 0; j < n; j++) {
                if (j == k) continue;
                submat[subi][subj] = mat[i][j];
                subj++;
            }
            subi++;
        }
        deti = deti + (pow(-1, k) * mat[0][k] * det(submat, n - 1));
    }
    return deti;
}

int main() {
    int n;
    cout << "Enter the size of the matrix: ";
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    cout << "The entered matrix is:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    int deti = det(mat, n);
    cout << deti << endl;

    return 0;
}
