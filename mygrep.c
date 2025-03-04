#include <stdio.h>
#include <string.h>

void search_file(const char *filename, const char *keyword)
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
        if (strstr(line, keyword))
            printf("[%d] %s", line_num, line);
        line_num++;
    }
    fclose(file);
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("使い方： mygrep <検索ワード> <ファイル名>\n");
        return 1;
    }
    search_file(argv[2], argv[1]);
    return 0;
}