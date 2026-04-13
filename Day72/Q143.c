#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    int hash[26] = {0};

    printf("Enter string: ");
    scanf("%s", s);

    for (int i = 0; i < strlen(s); i++) {
        int idx = s[i] - 'a';
        hash[idx]++;

        if (hash[idx] == 2) {
            printf("First repeated character: %c\n", s[i]);
            return 0;
        }
    }

    printf("-1\n");
    return 0;
}