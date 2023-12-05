#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    int results[T][2];
    for (int i = 0;i < T;i++) {
        int numOfPlayers;
        scanf("%d", &numOfPlayers);
        int playerMMRs[numOfPlayers];
        for (int j = 0;j < numOfPlayers;j++) {
            scanf("%d", &playerMMRs[j]);
        }
        int MMR;
        scanf("%d", &MMR);
        int index = -1;
        int MMR1 = 0;
        int MMR2 = 0;
        for (int j = 0;j < numOfPlayers;j++) {
            if (playerMMRs[j] > MMR) {
                if (MMR2 == 0) {
                    MMR2 = playerMMRs[j];
                } else if (playerMMRs[j] < MMR2) {
                    MMR2 = playerMMRs[j];
                }
            }
            if (playerMMRs[j] < MMR) {
                if (MMR1 == 0) {
                    MMR1 = playerMMRs[j];
                } else if (playerMMRs[j] > MMR1) {
                    MMR1 = playerMMRs[j];
                }
            }
            if (playerMMRs[j] == MMR) {
                index = j;
            }
        }
        if (index == -1) {
            results[i][0] = -1;
            results[i][1] = -1;
        } else {
            if (index != numOfPlayers - 1) {
                results[i][0] = MMR;
                results[i][1] = MMR2;
            } else {
                results[i][0] = MMR1;
                results[i][1] = MMR;
            }
        }
    }
    for (int i = 0;i < T;i++) {
        if (results[i][0] == -1) {
            printf("CASE #%d: -1 -1\n", i+1);
        } else {
            printf("CASE #%d: %d %d\n", i+1, results[i][0], results[i][1]);
        }
    }
    return 0;
}