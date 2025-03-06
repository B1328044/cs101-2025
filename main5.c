#include <stdio.h>

// 印出前導space
void print_sp(int i, int n) {
    for (int k = 0; k < (n - i); k++) {
        printf(" ");
    }
}

// 印出數字
void print_num(int n) {
    for (int j = 1; j <= n; j++) {
        print_sp(j, n); // 在每一行開始前印出空格

        for (int x = 1; x <= j; x++) {
            printf("%d ", j); // 印出數字與空格
        }
        printf("\n");
    }
}

int main() {
    int rows = 6;
    print_num(rows);
    return 0;
}
