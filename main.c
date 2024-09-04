#include <fcntl.h> // open
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // close

char	*get_next_line(int fd);

/*
__attribute__((destructor)) static void destructor()
{
	system("leaks -q a.out");
}
*/

int	main(int argc, char **argv)
{
	char	*pathname;
	int		fd;
	char	*line;

	// 引数が2つであることを確認
	if (argc != 2)
	{
		printf("please input file path\n");
		return (0);
	}
	pathname = argv[1];
	fd = open(pathname, O_RDONLY); // ファイルを開く
	if (fd < 0) // ファイルが開けなかった場合のエラーチェック
	{
		perror("Error opening file");
		return (1);
	}

	while ((line = get_next_line(fd)) != NULL) // get_next_lineで1行ずつ読み込む
	{
		printf("%s", line); // 読み込んだ行を表示
		free(line); // メモリを解放
	}

	close(fd); // ファイルディスクリプタを閉じる
	return (0);
}

