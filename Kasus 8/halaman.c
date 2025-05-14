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
#include "halaman.h"

// Fungsi untuk membersihkan layar sesuai sistem operasi
void clear_screen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Fungsi untuk menunggu konfirmasi pengguna
void wait_for_enter() {
    printf("\nTekan ENTER untuk melanjutkan...");
    fflush(stdin);  // Clear input buffer
    getchar();      // Wait for Enter
}

void tampilkan_menu() {
    clear_screen();
    printf("\n*************************** MENU OPERASI NON BINARY TREE ***************************\n");
    printf("*                                                                                 *\n");
    printf("* 1.  Input Node                                                                 *\n");
    printf("* 2.  Traversal PreOrder                                                         *\n");
    printf("* 3.  Traversal InOrder                                                          *\n");
    printf("* 4.  Traversal PostOrder                                                        *\n");
    printf("* 5.  Traversal LevelOrder                                                       *\n");
    printf("* 6.  Print Tree                                                                 *\n");
    printf("* 7.  Search Node                                                                *\n");
    printf("* 8.  NbElement (Jumlah Node)                                                    *\n");
    printf("* 9.  NbLeaf (Jumlah Daun)                                                       *\n");
    printf("* 10. Level of Node                                                              *\n");
    printf("* 11. Depth of Tree                                                              *\n");
    printf("* 12. Bandingkan Tree                                                            *\n");
    printf("* 13. Exit                                                                       *\n");
    printf("*                                                                                 *\n");
    printf("*********************************************************************************\n");
    printf("\nPilih menu: ");
}

void handle_menu_option(int pilihan, Isi_Tree tree) {
    int jumlah_node;
    switch (pilihan) {
        case 1:
            input_node(tree, &jumlah_node);
            break;
        case 2:
            traversal_preorder(tree);
            break;
        case 3:
            traversal_inorder(tree);
            break;
        case 4:
            traversal_postorder(tree);
            break;
        case 5:
            traversal_levelorder(tree, nbElmt(tree));
            break;
        case 6:
            print_tree(tree);
            break;
        case 7:
            search_node(tree);
            break;
        case 8:
            nb_element(tree);
            break;
        case 9:
            nb_leaf(tree);
            break;
        case 10:
            node_level(tree);
            break;
        case 11:
            tree_depth(tree);
            break;
        case 12:
            compare_trees(tree);
            break;
        case 13:
            clear_screen();
            printf("\n***************************** TERIMA KASIH *****************************\n");
            printf("*               Anda telah keluar dari program Non Binary Tree          *\n");
            printf("*************************************************************************\n");
            break;
        default:
            clear_screen();
            printf("\n*************************** PESAN ERROR ***************************\n");
            printf("*               Pilihan menu tidak valid. Silakan coba lagi         *\n");
            printf("*******************************************************************\n");
            wait_for_enter();
    }
}

void input_node(Isi_Tree tree, int* jumlah_node) {
    clear_screen();
    printf("\n***************************** INPUT NODE ******************************\n");
    printf("Masukkan jumlah node: ");
    scanf("%d", jumlah_node);
    Create_tree(tree, *jumlah_node);
    printf("\n* Node berhasil ditambahkan ke dalam tree                              *\n");
    printf("*************************************************************************\n");
    wait_for_enter();
}

void traversal_preorder(Isi_Tree tree) {
    clear_screen();
    printf("\n************************** TRAVERSAL PREORDER *************************\n");
    if (IsEmpty(tree)) {
        printf("* Tree masih kosong. Silakan input node terlebih dahulu               *\n");
    } else {
        printf("* Hasil Traversal PreOrder: ");
        PreOrder(tree);
    }
    printf("*************************************************************************\n");
    wait_for_enter();
}

void traversal_inorder(Isi_Tree tree) {
    clear_screen();
    printf("\n************************** TRAVERSAL INORDER **************************\n");
    if (IsEmpty(tree)) {
        printf("* Tree masih kosong. Silakan input node terlebih dahulu               *\n");
    } else {
        printf("* Hasil Traversal InOrder: ");
        InOrder(tree);
    }
    printf("*************************************************************************\n");
    wait_for_enter();
}

void traversal_postorder(Isi_Tree tree) {
    clear_screen();
    printf("\n************************* TRAVERSAL POSTORDER *************************\n");
    if (IsEmpty(tree)) {
        printf("* Tree masih kosong. Silakan input node terlebih dahulu               *\n");
    } else {
        printf("* Hasil Traversal PostOrder: ");
        PostOrder(tree);
    }
    printf("*************************************************************************\n");
    wait_for_enter();
}

void traversal_levelorder(Isi_Tree tree, int jumlah_node) {
    clear_screen();
    printf("\n************************ TRAVERSAL LEVELORDER ************************\n");
    if (IsEmpty(tree)) {
        printf("* Tree masih kosong. Silakan input node terlebih dahulu               *\n");
    } else {
        printf("* Hasil Traversal LevelOrder: ");
        Level_order(tree, jumlah_node);
    }
    printf("*************************************************************************\n");
    wait_for_enter();
}

void print_tree(Isi_Tree tree) {
    clear_screen();
    printf("\n***************************** PRINT TREE *****************************\n");
    if (IsEmpty(tree)) {
        printf("* Tree masih kosong. Silakan input node terlebih dahulu               *\n");
    } else {
        printf("* Seluruh Node pada Non Binary Tree:                                  *\n");
        for (int i = 1; i <= jml_maks; i++) {
            if (tree[i].info != ' ') {
                printf("\n--> Indeks ke-%d\n", i);
                printf("---------------------------------------------------\n");
                printf("info array ke %d      : %c\n", i, tree[i].info);
                printf("first son array ke %d    : %d\n", i, tree[i].ps_fs);
                printf("next brother array ke %d : %d\n", i, tree[i].ps_nb);
                printf("parent array ke %d      : %d\n", i, tree[i].ps_pr);
                printf("---------------------------------------------------\n");
            }
        }
    }
    printf("*************************************************************************\n");
    wait_for_enter();
}

void search_node(Isi_Tree tree) {
    clear_screen();
    printf("\n**************************** SEARCH NODE *****************************\n");
    if (IsEmpty(tree)) {
        printf("* Tree masih kosong. Silakan input node terlebih dahulu               *\n");
    } else {
        infotype node;
        printf("* Masukkan nilai node yang dicari: ");
        scanf(" %c", &node);
        if (Search(tree, node)) {
            printf("* Node '%c' ditemukan dalam tree.                                    *\n", node);
        } else {
            printf("* Node '%c' tidak ditemukan dalam tree.                              *\n", node);
        }
    }
    printf("*************************************************************************\n");
    wait_for_enter();
}

void nb_element(Isi_Tree tree) {
    clear_screen();
    printf("\n************************* JUMLAH NODE (ELEMENT) *********************\n");
    if (IsEmpty(tree)) {
        printf("* Tree masih kosong. Silakan input node terlebih dahulu               *\n");
    } else {
        printf("* Jumlah elemen (node) di tree: %d                                   *\n", nbElmt(tree));
    }
    printf("*************************************************************************\n");
    wait_for_enter();
}

void nb_leaf(Isi_Tree tree) {
    clear_screen();
    printf("\n************************** JUMLAH DAUN (LEAF) ***********************\n");
    if (IsEmpty(tree)) {
        printf("* Tree masih kosong. Silakan input node terlebih dahulu               *\n");
    } else {
        printf("* Jumlah daun di tree: %d                                            *\n", nbDaun(tree));
    }
    printf("*************************************************************************\n");
    wait_for_enter();
}

void node_level(Isi_Tree tree) {
    clear_screen();
    printf("\n************************* LEVEL OF NODE ******************************\n");
    if (IsEmpty(tree)) {
        printf("* Tree masih kosong. Silakan input node terlebih dahulu               *\n");
    } else {
        infotype node;
        printf("* Masukkan nilai node untuk mencari levelnya: ");
        scanf(" %c", &node);
        int level = Level(tree, node);
        if (level != -1) {
            printf("* Level node '%c' adalah: %d                                         *\n", node, level);
        } else {
            printf("* Node '%c' tidak ditemukan dalam tree.                              *\n", node);
        }
    }
    printf("*************************************************************************\n");
    wait_for_enter();
}

void tree_depth(Isi_Tree tree) {
    clear_screen();
    printf("\n************************* DEPTH OF TREE *****************************\n");
    if (IsEmpty(tree)) {
        printf("* Tree masih kosong. Silakan input node terlebih dahulu               *\n");
    } else {
        printf("* Tinggi (depth) pohon: %d                                           *\n", Depth(tree));
    }
    printf("*************************************************************************\n");
    wait_for_enter();
}

void compare_trees(Isi_Tree tree) {
    clear_screen();
    printf("\n************************ BANDINGKAN TREE ****************************\n");
    if (IsEmpty(tree)) {
        printf("* Tree pertama masih kosong. Silakan input node terlebih dahulu       *\n");
        printf("*************************************************************************\n");
        wait_for_enter();
        return;
    }
    
    Isi_Tree tree2;
    int jumlah_node;
    
    // Initialize tree2
    for (int i = 0; i <= jml_maks; i++) {
        tree2[i].info = ' ';
        tree2[i].ps_fs = 0;
        tree2[i].ps_nb = 0;
        tree2[i].ps_pr = 0;
    }
    
    printf("* Tree kedua akan dibuat. Silakan input node untuk tree kedua.          *\n");
    printf("* Masukkan jumlah node untuk tree kedua: ");
    scanf("%d", &jumlah_node);
    Create_tree(tree2, jumlah_node);
    
    printf("\n* Membandingkan kedua tree...                                         *\n");
    if (CompareTrees(tree, tree2)) {
        printf("* Kedua tree IDENTIK (struktur dan nilai sama)                       *\n");
    } else {
        printf("* Kedua tree TIDAK IDENTIK (struktur atau nilai berbeda)             *\n");
    }
    printf("*************************************************************************\n");
    wait_for_enter();
}
