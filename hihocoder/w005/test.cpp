#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nroom 202
#define max(X,Y) ((X)>(Y)?(X):(Y))

int map[nroom][nroom];
int count[nroom][nroom];

int get_max_count(int n) {
    int i=1, j=1, k=0, v=0;
    int max_c=0;
    int c[nroom] = {0};
    // c[i+1][j+1] = max(c[i][j+1], c[i][j])
    while (i<=n) {
        j=1;
        while(j<=i) {
            k = c[j]; // c[i-1][j];
            c[j] = map[i][j] + max(k, v);
            v = k; // c[i-1][j-1];
            max_c = max(c[j], max_c);
            ++j;
        }
        ++i;
    }
    return max_c;
}

int main() {
    int n=0,i=0,k=0;
    scanf("%d", &n);
    
    if (n==0) {
        return 0;
    }

    while (n--) {
        i++;
        k=0;

        while (++k<=i) {
            scanf("%d", &map[i][k]);
        }
    }

    printf("%d\n", get_max_count(i));
    return 0;
}
