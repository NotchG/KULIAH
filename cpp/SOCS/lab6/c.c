#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int team_counts[N + 1];
    for (int i = 0; i <= N; i++) {
        team_counts[i] = 0;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int shirt_num;
            scanf("%d", &shirt_num);
            team_counts[shirt_num]++;
        }
    }

    int incomplete_teams = 0;
    for (int i = 1; i <= N; i++) {
        if (team_counts[i] < N) {
            incomplete_teams++;
        }
    }

    printf("%d\n", incomplete_teams);

    return 0;
}
