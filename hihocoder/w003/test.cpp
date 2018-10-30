#include <cstdio>

int baoli(char* pat, char* src) {
    int count = 0;

    for (int i=0; src[i]; ++i) {
        int founded = 1;

        for (int j=0; pat[j]; ++j) {
            if (pat[j] != src[i+j]) {
                founded = 0;
                break;
            }
        }

        count += founded;
    }

    return count;
}



int main() {
    int n=0;
    scanf("%d", &n);

    char pat[10000 + 100];
    char src[1000000 + 100];

    while (n--) {
        scanf("%s", pat);
        scanf("%s", src);

        printf("%d\n", baoli(pat, src));
    }
}
