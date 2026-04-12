#include <stdio.h>
#include <string.h>

#define EMPTY -1

int table[1000];

void init(int m) {
    for (int i = 0; i < m; i++) {
        table[i] = EMPTY;
    }
}

void insert(int key, int m) {
    int h = key % m;

    for (int i = 0; i < m; i++) {
        int idx = (h + i * i) % m;

        if (table[idx] == EMPTY) {
            table[idx] = key;
            return;
        }
    }
}

int search(int key, int m) {
    int h = key % m;

    for (int i = 0; i < m; i++) {
        int idx = (h + i * i) % m;

        if (table[idx] == EMPTY) {
            return 0;
        }

        if (table[idx] == key) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int m, q;

    printf("Enter hash table size: ");
    scanf("%d", &m);

    printf("Enter number of operations: ");
    scanf("%d", &q);

    init(m);

    printf("Enter operations (INSERT x / SEARCH x):\n");

    while (q--) {
        char op[10];
        int key;

        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(key, m);
        } 
        else if (strcmp(op, "SEARCH") == 0) {
            if (search(key, m))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}