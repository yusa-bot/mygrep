#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINES 1000
#define MAX_LINE_LENGTH 1024

#ifndef _GNU_SOURCE
char *my_strcasestr(const char *haystack, const char *needle)
{
    if (!*needle)
        return (char *)haystack;

    while (*haystack)
    {
        const char *h = haystack;
        const char *n = needle;
        while (*h && *n && tolower(*h) == tolower(*n))
        {
            h++;
            n++;
        }
        if (!*n)
            return (char *)haystack;
        haystack++;
    }
    return NULL;
}
#define strcasestr my_strcasestr
#endif

void search_file(const char *filename, const char *keyword, int ignore_case, int context_lines)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        printf("ファイルを開けません： %s\n", filename);
        return;
    }

    char lines[MAX_LINES][MAX_LINE_LENGTH];
    int line_count = 0;

    while (fgets(lines[line_count], MAX_LINE_LENGTH, file) && line_count < MAX_LINES)
        line_count++;
    fclose(file);

    for (int i = 0; i < line_count; i++)
    {
        int match = ignore_case ? strcasestr(lines[i], keyword) != NULL : strstr(lines[i], keyword) != NULL;

        if (match)
        {
            int start = (i - context_lines < 0) ? 0 : i - context_lines;
            int end = (i + context_lines >= line_count) ? line_count - 1 : i + context_lines;

            for (int j = start; j <= end; j++)
                printf("%s", lines[j]);
            printf("---\n");
        }
    }
}

int main(int argc, char *argv[])
{
    int ignore_case = 0;
    int context_lines = 0;
    char *keyword, *filename;

    if (argc == 6 && strcmp(argv[1], "-i") == 0 && strcmp(argv[2], "-C") == 0)
    {
        ignore_case = 1;
        context_lines = atoi(argv[3]);
        keyword = argv[4];
        filename = argv[5];
    }
    else if (argc == 6 && strcmp(argv[1], "-C") == 0 && strcmp(argv[3], "-i") == 0)
    {
        ignore_case = 1;
        context_lines = atoi(argv[2]);
        keyword = argv[4];
        filename = argv[5];
    }
    else if (argc == 5 && strcmp(argv[1], "-C") == 0)
    {
        context_lines = atoi(argv[2]);
        keyword = argv[3];
        filename = argv[4];
    }
    else if (argc == 4 && strcmp(argv[1], "-i") == 0)
    {
        ignore_case = 1;
        keyword = argv[2];
        filename = argv[3];
    }
    else if (argc == 3)
    {
        keyword = argv[1];
        filename = argv[2];
    }
    else
    {
        printf("使い方： ./mygrep [-C <行数>] [-i] <検索ワード> <ファイル名>\n");
        return 1;
    }
    search_file(filename, keyword, ignore_case, context_lines);
    return 0;
}