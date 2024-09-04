#include <fcntl.h>  // open
#include <stdio.h>   // printf
#include <stdlib.h>  // free
#include <unistd.h>  // close

char    *get_next_line(int fd);

int main(int argc, char **argv)
{
    int     fd1, fd2;
    char    *line1, *line2;

    if (argc < 3)
    {
        printf("Please provide at least two file paths\n");
        return (1);
    }

    // ファイルディスクリプタを開く
    fd1 = open(argv[1], O_RDONLY);
    fd2 = open(argv[2], O_RDONLY);
    if (fd1 < 0 || fd2 < 0)
    {
        perror("Error opening files");
        return (1);
    }

    // 交互に行を読み込む
    while (1)
    {
        // File 1 から 1行読み込む
        line1 = get_next_line(fd1);
        if (line1)
        {
            printf("File 1: %s", line1);
            free(line1);
        }

        // File 2 から 1行読み込む
        line2 = get_next_line(fd2);
        if (line2)
        {
            printf("File 2: %s", line2);
            free(line2);
        }

        // 両方のファイルからの読み込みが終了した場合
        if (!line1 && !line2)
            break;
    }

    // ファイルディスクリプタを閉じる
    close(fd1);
    close(fd2);
    return (0);
}


// gcc -Wall -Wextra -Werror -D BUFFER_SIZE=100 get_next_line_bonus.c main_bonus.c -o gnl_bonus
