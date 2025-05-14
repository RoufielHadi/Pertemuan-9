/*
Author: Roufiel Hadi
NIM: 241524028
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/

#include <stdio.h>
#include "tree.h"

void Create_tree(Isi_Tree X, int Jml_Node) {
    int i;
    infotype temp;
    for (i = 1; i <= jml_maks; i++) {
        X[i].info = ' ';
        X[i].ps_fs = 0;
        X[i].ps_nb = 0;
        X[i].ps_pr = 0;
    }

    for (i = 1; i <= Jml_Node; i++) {
        printf("Masukkan info node ke-%d: ", i);
        scanf(" %c", &temp);
        X[i].info = temp;

        if (i == 1) {
            X[i].ps_pr = 0;
        } else {
            printf("Masukkan parent dari node %c (indeks): ", temp);
            int parent;
            scanf("%d", &parent);
            X[i].ps_pr = parent;
            if (X[parent].ps_fs == 0) {
                X[parent].ps_fs = i;
            } else {
                int sibling = X[parent].ps_fs;
                while (X[sibling].ps_nb != 0) {
                    sibling = X[sibling].ps_nb;
                }
                X[sibling].ps_nb = i;
            }
        }
    }
}

boolean IsEmpty(Isi_Tree P) {
    return P[1].info == ' ';
}

void PreOrder(Isi_Tree P) {
    void RecursePreOrder(Isi_Tree P, int idx) {
        if (idx == 0 || P[idx].info == ' ') return;
        printf("%c ", P[idx].info);
        RecursePreOrder(P, P[idx].ps_fs);
        RecursePreOrder(P, P[idx].ps_nb);
    }
    RecursePreOrder(P, 1);
    printf("\n");
}

void InOrder(Isi_Tree P) {
    void RecurseInOrder(Isi_Tree P, int idx) {
        if (idx == 0 || P[idx].info == ' ') return;
        int child = P[idx].ps_fs;
        if (child != 0) {
            RecurseInOrder(P, child);
        }
        printf("%c ", P[idx].info);
        if (child != 0) {
            child = P[child].ps_nb;
            while (child != 0) {
                RecurseInOrder(P, child);
                child = P[child].ps_nb;
            }
        }
    }
    RecurseInOrder(P, 1);
    printf("\n");
}

void PostOrder(Isi_Tree P) {
    void RecursePostOrder(Isi_Tree P, int idx) {
        if (idx == 0 || P[idx].info == ' ') return;
        int child = P[idx].ps_fs;
        while (child != 0) {
            RecursePostOrder(P, child);
            child = P[child].ps_nb;
        }
        printf("%c ", P[idx].info);
    }
    RecursePostOrder(P, 1);
    printf("\n");
}

void Level_order(Isi_Tree X, int Maks_node) {
    for (int i = 1; i <= Maks_node; i++) {
        if (X[i].info != ' ') {
            printf("%c ", X[i].info);
        }
    }
    printf("\n");
}

void PrintTree(Isi_Tree P) {
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info != ' ') {
            printf("[%d] Info: %c, FS: %d, NB: %d, PR: %d\n", i, P[i].info, P[i].ps_fs, P[i].ps_nb, P[i].ps_pr);
        }
    }
}

boolean Search(Isi_Tree P, infotype X) {
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info == X) return true;
    }
    return false;
}

int nbElmt(Isi_Tree P) {
    int count = 0;
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info != ' ') count++;
    }
    return count;
}

int nbDaun(Isi_Tree P) {
    int count = 0;
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info != ' ' && P[i].ps_fs == 0) count++;
    }
    return count;
}

int Level(Isi_Tree P, infotype X) {
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info == X) {
            int level = 0;
            int pr = P[i].ps_pr;
            while (pr != 0) {
                level++;
                pr = P[pr].ps_pr;
            }
            return level;
        }
    }
    return -1;
}

int Depth(Isi_Tree P) {
    int maxDepth = 0;
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info != ' ') {
            int depth = 0;
            int pr = P[i].ps_pr;
            while (pr != 0) {
                depth++;
                pr = P[pr].ps_pr;
            }
            if (depth > maxDepth) maxDepth = depth;
        }
    }
    return maxDepth;
}

int Max(infotype Data1, infotype Data2) {
    return (Data1 > Data2) ? Data1 : Data2;
}

#include <stdio.h>
#include "tree.h"

int FindEmptySlot(Isi_Tree P) {
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info == ' ') return i;
    }
    return 0;
}

void InsertNode(Isi_Tree P, infotype info, int parent_idx) {
    int idx = FindEmptySlot(P);
    if (idx == 0) return;

    P[idx].info = info;
    P[idx].ps_pr = parent_idx;
    P[idx].ps_fs = 0;
    P[idx].ps_nb = 0;

    if (P[parent_idx].ps_fs == 0) {
        P[parent_idx].ps_fs = idx;
    } else {
        int sibling = P[parent_idx].ps_fs;
        while (P[sibling].ps_nb != 0) {
            sibling = P[sibling].ps_nb;
        }
        P[sibling].ps_nb = idx;
    }
}

void DeleteNode(Isi_Tree P, int idx) {
    void RecurseDelete(Isi_Tree P, int i) {
        if (i == 0 || P[i].info == ' ') return;
        int child = P[i].ps_fs;
        while (child != 0) {
            int next = P[child].ps_nb;
            RecurseDelete(P, child);
            child = next;
        }
        P[i].info = ' ';
        P[i].ps_fs = 0;
        P[i].ps_nb = 0;
        P[i].ps_pr = 0;
    }

    int parent = P[idx].ps_pr;
    if (parent != 0) {
        if (P[parent].ps_fs == idx) {
            P[parent].ps_fs = P[idx].ps_nb;
        } else {
            int curr = P[parent].ps_fs;
            while (curr != 0 && P[curr].ps_nb != idx) {
                curr = P[curr].ps_nb;
            }
            if (curr != 0) P[curr].ps_nb = P[idx].ps_nb;
        }
    }
    RecurseDelete(P, idx);
}

int GetParent(Isi_Tree P, int idx) {
    return P[idx].ps_pr == 0 ? -1 : P[idx].ps_pr;
}

int GetChild(Isi_Tree P, int idx, int k) {
    int child = P[idx].ps_fs;
    for (int i = 1; i < k && child != 0; i++) {
        child = P[child].ps_nb;
    }
    return child;
}

boolean IsLeaf(Isi_Tree P, int idx) {
    return (P[idx].ps_fs == 0);
}

boolean IsRoot(Isi_Tree P, int idx) {
    return (P[idx].ps_pr == 0);
}

void CopyTree(Isi_Tree P, Isi_Tree Q) {
    for (int i = 1; i <= jml_maks; i++) {
        Q[i] = P[i];
    }
}

boolean CompareTrees(Isi_Tree P1, Isi_Tree P2) {
    for (int i = 1; i <= jml_maks; i++) {
        if (P1[i].info != P2[i].info ||
            P1[i].ps_fs != P2[i].ps_fs ||
            P1[i].ps_nb != P2[i].ps_nb ||
            P1[i].ps_pr != P2[i].ps_pr) {
            return false;
        }
    }
    return true;
}

int Degree(Isi_Tree P, int idx) {
    int count = 0;
    int child = P[idx].ps_fs;
    while (child != 0) {
        count++;
        child = P[child].ps_nb;
    }
    return count;
}
