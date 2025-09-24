#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int max(int a, int b) { return (a > b) ? a : b; }

char* lcs(const char* s1, const char* s2) {
    int m = strlen(s1), n = strlen(s2);
    int** dp = malloc((m + 1) * sizeof(int*));
    for (int i = 0; i <= m; i++) dp[i] = calloc(n + 1, sizeof(int));

    // Fill dp table
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] = (s1[i - 1] == s2[j - 1]) ? dp[i - 1][j - 1] + 1 : max(dp[i - 1][j], dp[i][j - 1]);

    // Backtrack to get LCS
    char* res = malloc(m + n + 1);
    int i = m, j = n, k = 0;
    while (i && j) {
        if (s1[i - 1] == s2[j - 1]) res[k++] = s1[--i], --j;
        else if (dp[i - 1][j] > dp[i][j - 1]) --i;
        else --j;
    }

    // Reverse result
    for (int l = 0; l < k / 2; l++) {
        char tmp = res[l];
        res[l] = res[k - 1 - l];
        res[k - 1 - l] = tmp;
    }
    res[k] = '\0';

    printf("LCS length: %d\n", dp[m][n]);

    // Free memory
    for (int i = 0; i <= m; i++) free(dp[i]);
    free(dp);

    return res;
}

int main() {
    char s1[1000], s2[1000];
    printf("String s1: "); fgets(s1, sizeof(s1), stdin); s1[strcspn(s1, "\n")] = 0;
    printf("String s2: "); fgets(s2, sizeof(s2), stdin); s2[strcspn(s2, "\n")] = 0;

    char* result = lcs(s1, s2);
    printf("LCS: %s\n", result);
    free(result);
    return 0;
}
