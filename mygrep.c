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

void search_file(const char *filename, const char *keyword, int ignore_case)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        printf("ファイルを開けません： %s\n", filename);
        return;
    }

    char line[1024];
    int line_num = 1;

    while (fgets(line, sizeof(line), file))
    {
        if ((ignore_case && strcasestr(line, keyword)) || (!ignore_case && strstr(line, keyword)))
            printf("[%d] %s", line_num, line);
        line_num++;
    }
    fclose(file);
}

int main(int argc, char *argv[])
{
    int ignore_case = 0;
    char *keyword, *filename;

    if (argc == 4 && strcmp(argv[1], "-i") == 0)
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
        printf("使い方： mygrep <検索ワード> <ファイル名>\n");
        return 1;
    }
    search_file(filename, keyword, ignore_case);
    return 0;
}