#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#define BERSIH "cls"
#else
#define BERSIH "clear"
#endif

char papan[9];

int garis[8][3] = {
    {0,1,2},{3,4,5},{6,7,8},   // baris
    {0,3,6},{1,4,7},{2,5,8},   // kolom
    {0,4,8},{2,4,6}            // diagonal
};

void reset() {
    for (int i = 0; i < 9; i++) papan[i] = '1' + i;
}

int kosong(int i) {
    return papan[i] != 'X' && papan[i] != 'O';
}

void tampil() {
    system(BERSIH);
    printf("=== TIC-TAC-TOE ===\n\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c\n", papan[i*3], papan[i*3+1], papan[i*3+2]);
        if (i < 2) printf("---+---+---\n");
    }
    printf("\n");
}

int menang(char s) {
    for (int i = 0; i < 8; i++) {
        if (papan[garis[i][0]] == s &&
            papan[garis[i][1]] == s &&
            papan[garis[i][2]] == s) return 1;
    }
    return 0;
}

int main() {
    char ulang;

    do {
        reset();
        char pemain = 'X';
        int langkah = 0, selesai = 0;

        while (!selesai) {
            int pilihan;

            tampil();
            printf("Giliran %c. Pilih kotak (1-9): ", pemain);
            if (scanf("%d", &pilihan) != 1) {
                while (getchar() != '\n');
                continue;
            }
            pilihan--;
            if (pilihan < 0 || pilihan > 8 || !kosong(pilihan)) continue;

            papan[pilihan] = pemain;
            langkah++;

            if (menang(pemain)) {
                tampil();
                printf("Pemain %c menang!\n", pemain);
                selesai = 1;
            } else if (langkah == 9) {
                tampil();
                printf("Permainan seri!\n");
                selesai = 1;
            } else {
                pemain = (pemain == 'X') ? 'O' : 'X';
            }
        }

        printf("\nMain lagi? (y/n): ");
        scanf(" %c", &ulang);
    } while (ulang == 'y' || ulang == 'Y');

    printf("Terima kasih sudah bermain!\n");
    return 0;
}