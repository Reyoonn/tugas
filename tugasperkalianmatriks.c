#include <stdio.h>

int main() {
    int A[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    int B[4][1] = {
        {1},
        {2},
        {3},
        {4}
    };

    int C[4][1];

    // Proses perkalian matriks
    for (int i = 0; i < 4; i++) {
        C[i][0] = 0;
        for (int k = 0; k < 4; k++) {
            C[i][0] += A[i][k] * B[k][0];
        }
    }

    // Menampilkan hasil
    printf("Hasil perkalian matriks (4x1):\n");
    for (int i = 0; i < 4; i++) {
        printf("%d\n", C[i][0]);
    }

    return 0;
}