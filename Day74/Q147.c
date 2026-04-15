#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000
#define NAME_LEN 50

typedef struct {
    char name[NAME_LEN];
    int count;
} Candidate;

int findCandidate(Candidate arr[], int size, char *name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i].name, name) == 0)
            return i;
    }
    return -1;
}

int main() {
    int n;
    printf("Enter number of votes: ");
    scanf("%d", &n);

    Candidate candidates[MAX];
    int size = 0;

    char name[NAME_LEN];

    printf("Enter candidate names:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", name);

        int idx = findCandidate(candidates, size, name);

        if (idx == -1) {
            strcpy(candidates[size].name, name);
            candidates[size].count = 1;
            size++;
        } else {
            candidates[idx].count++;
        }
    }

    char winner[NAME_LEN];
    int maxVotes = 0;

    for (int i = 0; i < size; i++) {
        if (candidates[i].count > maxVotes) {
            maxVotes = candidates[i].count;
            strcpy(winner, candidates[i].name);
        } 
        else if (candidates[i].count == maxVotes) {
            if (strcmp(candidates[i].name, winner) < 0) {
                strcpy(winner, candidates[i].name);
            }
        }
    }

    printf("Winner: %s\n", winner);
    printf("Votes: %d\n", maxVotes);

    return 0;
}