#include <stdio.h>
#include <string.h>


char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}

int main() {
    int T;
    scanf("%d", &T);
    char s[T][1000];

    for (int i = 0;i < T;i++) {
        scanf("%s", s[i]);
        strrev(s[i]);
        for (int j = 0;j < strlen(s[i]);j++) {
            int x = s[i][j];
            s[i][j] = x % 2 == 0 ? '0' : '1';
        }
    }
    for (int i = 0;i < T;i++) {
        printf("Case %d: %s\n", i+1, s[i]);
    }
    return 0;
}