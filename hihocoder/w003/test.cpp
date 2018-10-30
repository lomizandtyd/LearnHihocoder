#include <cstdio>
#include <cstring>
#include <cstdlib>

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

int kmp(char* pat, char* src) {
    int psize = strlen(pat);
    int ssize = strlen(src); 

    // 计算next数组
    int* next = reinterpret_cast<int*>(calloc(psize+10, sizeof(int)));
    next[0] = -1;
    int j=0,k=-1;
    while (j<psize) {
        if (k==-1 || pat[j] == pat[k]) {
            j++; k++;
            next[j] = k;
        }
        else {
            k = next[k];
        }
    }

    // 搜索
    int count=0;
    j=0; k=0;

    while (j<ssize) {
        if (k==-1 || pat[k] == src[j]) {
            k++; j++;
            if (k == psize)
                count ++;
        }
        else {
            k = next[k];
        }
    }

    free(next);
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

        printf("%d\n", kmp(pat, src));
    }
}
