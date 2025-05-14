/*
Author: Roufiel Hadi
NIM: 241524028
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/

#include <stdio.h>
#include "halaman.h"
#include "tree.h"

int main() {
    Isi_Tree tree;
    int pilihan;
    int jumlah_node;

    clear_screen();
    printf("\n*********************** PROGRAM NON BINARY TREE ***********************\n");
    printf("*                                                                     *\n");
    printf("*  Selamat datang di Program Non Binary Tree                          *\n");
    printf("*  Program ini memungkinkan Anda memanipulasi dan menganalisis tree   *\n");
    printf("*                                                                     *\n");
    printf("***********************************************************************\n");
    printf("\nTekan ENTER untuk melanjutkan...");
    getchar();

    // Initialize tree (initial state)
    for (int i = 0; i <= jml_maks; i++) {
        tree[i].info = ' ';
        tree[i].ps_fs = 0;
        tree[i].ps_nb = 0;
        tree[i].ps_pr = 0;
    }

    do {
        tampilkan_menu();
        scanf("%d", &pilihan);
        handle_menu_option(pilihan, tree);
    } while (pilihan != 13);  // Exit the loop when the user chooses option 13

    return 0;
}
