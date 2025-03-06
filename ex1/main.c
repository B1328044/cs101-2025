#include <stdio.h>

int main() {
    FILE* fp;
    int a[] = {0, 1, 2};
    char b[] = "ABC";
    float c[] = {1.1, 1.2, 1.3};

    fp = fopen("a.bin", "wb+");

    // 寫入檔案
    fwrite(a, sizeof(int), 3, fp);
    fwrite(b, sizeof(char), 3, fp);
    fwrite(c, sizeof(float), 3, fp);

    // 重設檔案指標到開頭
    fseek(fp, 0, SEEK_SET);

    // 讀取檔案內容
    fread(a, sizeof(int), 3, fp);
    for (int i = 0; i < 3; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    fread(b, sizeof(char), 3, fp);
    for (int i = 0; i < 3; i++) {
        printf("%c ", b[i]);
    }
    printf("\n");

    fread(c, sizeof(float), 3, fp);
    for (int i = 0; i < 3; i++) {
        printf("%.1f ", c[i]);
    }
    printf("\n");

    // 關閉檔案
    fclose(fp);

    return 0;
}
