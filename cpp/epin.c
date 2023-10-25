#include<stdio.h>

int main(){
    long int a;
    scanf("%ld", &a);
    int res[a];

    for (long int i = 0; i < a; i++){
        int b, c;
        scanf("%d %d", &b, &c);
        
        if (b % c == 0) {
            res[i] = 0;
        } 
        else if(b == c){
            res[i] = 0;
        }
        else if(b - c == 1 && c - b == -1){
            if (b % 2 == 0) { 
                res[i] = 1;
            } else {
                res[i] = 0;
            }
        }
        else {
            res[i] = 1;
        }
    }
    for (int i = 0;i < a;i++) {
        printf("Case #%ld: %d\n", i + 1, res[i]);
    }
    return 0;
}