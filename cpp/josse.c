#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char strAwal[100] = "kepin";
    char strAkhir[100];

    //for(int j = 0;j < 500;j++) {
        for (int i = 0;i < strlen(strAwal);i++) {
        strAkhir[i] = strAwal[i] + 480;
        //sprintf(strAkhir[i], "%c", strAwal[i] + 23)
    }
    printf("%s\n",strAkhir);
    //}
    return 0;
}