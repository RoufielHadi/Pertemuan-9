/*
Author: Roufiel Hadi
NIM: 241524028
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main() {
    Isi_Tree P, Q;
    // Inisialisasi kosong
    for (int i = 1; i <= jml_maks; i++) {
        P[i].info = ' ';
        P[i].ps_fs = 0;
        P[i].ps_nb = 0;
        P[i].ps_pr = 0;
    }

    // Menyusun tree seperti gambar referensi
    P[1].info = 'A'; // root
    P[1].ps_fs = 2;

    P[2].info = 'B'; P[2].ps_pr = 1; P[2].ps_nb = 3; P[2].ps_fs = 4;
    P[3].info = 'C'; P[3].ps_pr = 1; P[3].ps_fs = 6;

    P[4].info = 'D'; P[4].ps_pr = 2; P[4].ps_nb = 5;
    P[5].info = 'E'; P[5].ps_pr = 2; P[5].ps_nb = 0; P[5].ps_fs = 9;

    P[6].info = 'F'; P[6].ps_pr = 3; P[6].ps_nb = 7;
    P[7].info = 'G'; P[7].ps_pr = 3; P[7].ps_nb = 8;
    P[8].info = 'H'; P[8].ps_pr = 3;

    P[9].info = 'I'; P[9].ps_pr = 5; P[9].ps_nb = 10;
    P[10].info = 'J'; P[10].ps_pr = 5;

    printf("\nTraversal Tree Referensi:\n");
    printf("PreOrder:\n"); PreOrder(P);
    printf("InOrder:\n"); InOrder(P);
    printf("PostOrder:\n"); PostOrder(P);
    printf("Level Order:\n"); Level_order(P, jml_maks);

    printf("\nDetail Tree:\n");
    PrintTree(P);

    printf("\nJumlah elemen: %d\n", nbElmt(P));
    printf("Jumlah daun: %d\n", nbDaun(P));

    char cari = 'E';
    printf("\nApakah node '%c' ada? %s\n", cari, Search(P, cari) ? "Ya" : "Tidak");
    printf("Level dari '%c': %d\n", cari, Level(P, cari));
    printf("Kedalaman tree: %d\n", Depth(P));

    printf("\nSalin tree ke Q dan tampilkan:\n");
    CopyTree(P, Q);
    PrintTree(Q);

    printf("\nPerbandingan tree P dan Q: %s\n", CompareTrees(P, Q) ? "Sama" : "Beda");

    int idx = 5;
    printf("\nApakah node di indeks %d adalah akar? %s\n", idx, IsRoot(P, idx) ? "Ya" : "Tidak");
    printf("Apakah node di indeks %d adalah daun? %s\n", idx, IsLeaf(P, idx) ? "Ya" : "Tidak");
    printf("Jumlah anak langsung dari node %d: %d\n", idx, Degree(P, idx));

    return 0;
}

