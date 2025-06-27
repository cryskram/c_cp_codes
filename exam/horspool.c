#include <stdio.h>
#include <string.h>

#define MAX 256

void createShiftTable(char pattern[], int shift[])
{
    int m = strlen(pattern);

    for (int i = 0; i < MAX; i++)
        shift[i] = m;

    for (int i = 0; i < m - 1; i++)
        shift[(int)pattern[i]] = m - 1 - i;
}

int horspoolSearch(char text[], char pattern[])
{
    int shift[MAX];
    int n = strlen(text);
    int m = strlen(pattern);

    createShiftTable(pattern, shift);

    int i = m - 1;

    while (i < n)
    {
        int k = 0;
        while (k < m && pattern[m - 1 - k] == text[i - k])
            k++;

        if (k == m)
            return i - m + 1;

        i += shift[(int)text[i]];
    }

    return -1;
}

int main()
{
    char text[100], pattern[50];

    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    printf("Enter the pattern to search: ");
    fgets(pattern, sizeof(pattern), stdin);
    pattern[strcspn(pattern, "\n")] = '\0';

    int pos = horspoolSearch(text, pattern);

    if (pos != -1)
        printf("Pattern found at position: %d\n", pos);
    else
        printf("Pattern not found.\n");

    return 0;
}
