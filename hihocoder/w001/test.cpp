#include <cstdio>
#include <cstring>
#include <string.h>

char str[1000002 * 2];
char buff[1000002];
int p[1000002 * 2];

int padding() {
    int i=0;
    for (i=0; buff[i]; ++i) {
        str[2 * i + 1] = '#';
        str[2 * i + 2] = buff[i];
    }
    str[2*i+1] = '#';
    str[2*i+2] = '\0';
}

int manacher() {
    // 奇偶变换
    padding();

    int mx = 0;
    int id = 0;

    int max_len = 0;

    for (int i = 1; str[i]; ++i) {

        // step 2 判断
        if (i < mx) {
            p[i] = mx - i;
            if (p[i] > p[2 * id - i])
                p[i] = p[2 * id - i];
        }
        else {
            p[i] = 1;
        }

        // 搜索得到最长回文子串
        while (str[i-p[i]] == str[i+p[i]]) {
            p[i] ++;
        }
        if (max_len < p[i] - 1)
            max_len = p[i] - 1;

        // 更新最右回文子串
        if (p[i] + i > mx) {
            mx = p[i] + i;
            id = i;
        }

    }
    return max_len;
}

int main() {
    int n;
    str[0] = '$';

    scanf("%d", &n);
    while (n--) {
        scanf("%s", buff);
        printf("%d\n", manacher());
    }
    return 0;
}
