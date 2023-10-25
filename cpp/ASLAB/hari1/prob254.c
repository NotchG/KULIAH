#include <stdio.h>

int main() {
    long long int num;
    char ones[10][10] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
    char tens[10][10] = {"","X","XX","XXX","XG","G","GX","GXX","GXXX","XC"};
    char hrns[10][10] = {"","H","HH","HHH","HF","F","FH","FHH","FHHH","HW"};
    char ths[10][10]={"","W","WW","WWW", "WM", "M", "MW", "MWW", "MWWWW", "MK"};
    char tenths[10][10]={"","K","KK","KKK", "KQ", "Q", "QK", "QKK", "QKKK", "QP"};
    char hundredths[10][10]={"","P","PP","PPP", "PO", "O", "OP", "OPP", "OPPP", "OR"};
    char MILL[10][4]={"","R","RR","RRR"};

    scanf("%lld", &num);
        
    printf("%s%s%s%s%s%s%s\n", MILL[(num%10000000)/1000000], hundredths[(num%1000000)/100000], tenths[(num%100000)/10000], ths[(num%10000)/1000] ,hrns[(num%1000)/100] ,tens[(num%100)/10] ,ones[num%10]);
    return 0;
}