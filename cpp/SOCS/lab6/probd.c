#include <stdio.h>
#include <math.h>

int checkPrime(int n) {
    int i, flag = 0;


  if (n == 0 || n == 1)
    flag = 1;

  for (i = 2; i <= n / 2; ++i) {
    if (flag == 1) {
        break;
    }
    if (n % i == 0) {
      flag = 1;
      break;
    }
  }

  // flag is 0 for prime numbers
  return flag;

}

int checkSquare(int N)
{
    int root = sqrt(N);
 
    // If cube of cube_root is equals
    // to N, then print Yes else No
    if (root * root == N) {
        return 1;
    }
    else {
        return 0;
    }
}

int checkCubic(int N)
{
    int cube_root;
    cube_root = (int)round(pow(N, 1.0 / 3.0));
 
    // If cube of cube_root is equals
    // to N, then print Yes else No
    if (cube_root * cube_root * cube_root == N) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    int T;
    scanf("%d", &T);
    int res[T];
    for (int i = 0;i < T;i++) {
        scanf("%d", &res[i]);
    }
    for (int i = 0;i < T;i++) {
        printf("Case #%d :", i + 1);
        int check = 0;
        if (checkPrime(res[i]) == 0) {
            check = 1;
            printf(" prime");
        }
        if (checkSquare(res[i]) == 1) {
            check = 1;
            printf(" square");
        }
        if (checkCubic(res[i]) == 1) {
            check = 1;
            printf(" cubic");
        }
        if(check == 0) {
            printf(" none");
        }
        printf("\n");
    }
    return 0;
}