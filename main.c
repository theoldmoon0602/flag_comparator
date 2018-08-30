#include <stdio.h>

int main() {
    char str[32];
    printf("input flag:");
    scanf("%31s", str);

    int flags[] = {
      0x6d61434f,
      0x16032223,
      0x14090018,
      0x0600000d,
      0x0b0a1526,
      0x1f04003a,
    };

    int x = 0;
    int i = 0;
    for (i = 0; i < 6; i++) {
      int y = *(int *)(str + i*4);

      if ((x ^ y) != flags[i]) {
        printf("Not flag!\n");
        return 0;
      }
      x = y;
    }

    printf("Correct!\n");
    return 0;
}
