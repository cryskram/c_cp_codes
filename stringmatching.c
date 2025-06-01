#include <string.h>

int bruteForceMatch(char *text, char *pattern)
{
    int n = strlen(text), m = strlen(pattern);
    for (int i = 0; i <= n - m; i++)
    {
        int j;
        for (j = 0; j < m; j++)
            if (text[i + j] != pattern[j])
                break;
        if (j == m)
            return i;
    }
    return -1;
}

int main()
{
    char text[] = "ababcabcabababd";
    char pattern[] = "ababd";
    bruteForceMatch(text, pattern);
    return 0;
}
