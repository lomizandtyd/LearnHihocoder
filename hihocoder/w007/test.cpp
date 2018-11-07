#include <cstdio>
#include <cstdlib>

#define max(X, Y) ((X) > (Y) ? (X) : (Y))
int get_max_value(int n, int m, int *need, int *value);

int get_max_value_recur(int n, int m, int* need, int* value) {
    int best = 0;
    int cur = n - 1;
    if (cur < 0)
        return 0;

    if (need[cur] > m) {
        return get_max_value(n-1, m, need, value);
    }
    else {
        return max(get_max_value(n-1, m-need[cur], need, value) + value[cur], get_max_value(n-1, m, need, value));
    }
}

// f[i, m] = max(f[i-1, m], f[i, m-need[i]] + value[i])
int get_max_value(int n, int m, int *need, int *value) {
    int best = 0;
    int *f = new int[m + 1];

    for (int i=0; i<m+1; ++i)
        f[i] = 0;

    for (int i=0; i<n; ++i) {
        for (int j=need[i]; j<=m; ++j) { // make sure j >= need[i]
            f[j] = max(f[j], f[j-need[i]] + value[i]);
            best = max(f[j], best);
        }
    }
    delete f;
    return best;
}

int main() {
    int n, m;
    scanf("%d", &n); scanf("%d", &m);

    int *need = new int[n];
    int *value = new int[n];

    for (int i=0; i<n; ++i) {
        scanf("%d", need+i);
        scanf("%d", value+i);
    }

    printf("%d\n", get_max_value(n, m, need, value));

    delete need;
    delete value;

    return 0;
}
