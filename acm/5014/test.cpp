#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int map[100001];

void solution_5014(int arr[], int res[], int n) {
    if (n == 0) {
        res[0] = 0; return ;
    }

    int s = n;
    // step1:
    // 生成递增排列对应的序列作为map
    while (s>0) {
        int k = 1;
        while (k * 2 <= s) k *= 2;
        int l=k-1, r=k;
        while (r <=s && l>=0) {
            map[r] = l;
            map[l] = r;
            r ++; l --;
        }
        s = l;
    }

    if (s ==0) {
        map[0] = 0;
    }

    // step2:
    // 根据递增排列映射输入排列的值
    for (int i=0; i<=n; ++i) {
        res[i] = map[arr[i]];
    }
}

int main() {
    int n=0;

    while (scanf("%d", &n) != EOF) {
        int *arr = new int[n+1];
        for (int i=0; i<=n; ++i) {
            scanf("%d", arr+i);
        }

        int *res = new int[n+1];
        solution_5014(arr, res, n);
        long sum=0, k=n;
        while (k>=0) {sum = sum + arr[k] + res[k]; k--;}
        printf("%ld\n", sum);
        for (int i=0; i<n; ++i) {
            printf("%d ", res[i]);
        }
        printf("%d\n", res[n]);
        delete arr, res;
    }
    return 0;
}
