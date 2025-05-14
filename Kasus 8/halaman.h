/*
Author: Roufiel Hadi
NIM: 241524028
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/

#ifndef HALAMAN_H
#define HALAMAN_H

#include "tree.h"

/***************************/
/* Function Declarations */
/***************************/

void tampilkan_menu();
/* Tujuan: Menampilkan menu untuk operasi pada pohon Non Binary Tree */
/* IS: Tidak ada input sebelumnya */
/* FS: Menampilkan menu operasi yang dapat dipilih pengguna */

void handle_menu_option(int pilihan, Isi_Tree tree);
/* Tujuan: Menangani pilihan menu untuk operasi pohon */
/* IS: Pengguna telah memilih opsi dari menu */
/* FS: Menjalankan fungsi yang sesuai dengan pilihan menu yang dipilih */

void input_node(Isi_Tree tree, int* jumlah_node);
/* Tujuan: Menginputkan node untuk tree */
/* IS: Pengguna telah memilih untuk memasukkan node baru */
/* FS: Menambahkan node baru ke dalam tree berdasarkan input pengguna */

void traversal_preorder(Isi_Tree tree);
/* Tujuan: Melakukan traversal PreOrder pada tree */
/* IS: Tree sudah terdefinisi */
/* FS: Menampilkan hasil traversal PreOrder dari tree */

void traversal_inorder(Isi_Tree tree);
/* Tujuan: Melakukan traversal InOrder pada tree */
/* IS: Tree sudah terdefinisi */
/* FS: Menampilkan hasil traversal InOrder dari tree */

void traversal_postorder(Isi_Tree tree);
/* Tujuan: Melakukan traversal PostOrder pada tree */
/* IS: Tree sudah terdefinisi */
/* FS: Menampilkan hasil traversal PostOrder dari tree */

void traversal_levelorder(Isi_Tree tree, int jumlah_node);
/* Tujuan: Melakukan traversal LevelOrder pada tree */
/* IS: Tree dan jumlah node sudah terdefinisi */
/* FS: Menampilkan hasil traversal LevelOrder dari tree */

void print_tree(Isi_Tree tree);
/* Tujuan: Mencetak seluruh isi tree */
/* IS: Tree sudah terdefinisi */
/* FS: Menampilkan seluruh informasi dari tree ke layar */

void search_node(Isi_Tree tree);
/* Tujuan: Mencari node berdasarkan nilai yang diinputkan */
/* IS: Pengguna telah memilih untuk mencari node */
/* FS: Menampilkan apakah node yang dicari ada atau tidak dalam tree */

void nb_element(Isi_Tree tree);
/* Tujuan: Menghitung jumlah elemen (node) dalam tree */
/* IS: Tree sudah terdefinisi */
/* FS: Menampilkan jumlah elemen (node) dalam tree */

void nb_leaf(Isi_Tree tree);
/* Tujuan: Menghitung jumlah daun (leaf) dalam tree */
/* IS: Tree sudah terdefinisi */
/* FS: Menampilkan jumlah daun dalam tree */

void node_level(Isi_Tree tree);
/* Tujuan: Menampilkan level dari suatu node */
/* IS: Pengguna telah memilih untuk mencari level node */
/* FS: Menampilkan level dari node yang dicari */

void tree_depth(Isi_Tree tree);
/* Tujuan: Menampilkan tinggi (depth) dari tree */
/* IS: Tree sudah terdefinisi */
/* FS: Menampilkan tinggi dari tree */

void compare_trees(Isi_Tree tree);
/* Tujuan: Membandingkan tree yang ada dengan tree baru */
/* IS: Tree pertama sudah terdefinisi */
/* FS: Menampilkan apakah kedua tree identik atau tidak */

void clear_screen();
/* Tujuan: Membersihkan layar konsol */
/* IS: Layar konsol dalam keadaan apa pun */
/* FS: Layar konsol dibersihkan */

void wait_for_enter();
/* Tujuan: Menunggu pengguna menekan tombol Enter */
/* IS: Program menunggu input dari pengguna */
/* FS: Program melanjutkan eksekusi setelah pengguna menekan Enter */

#endif

