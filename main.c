#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"


// int main(void)
// {

//     char    *line1;
// 	// char	*line2;

//     int fd1 = open("41_with_nl", O_RDONLY);
//     // int fd2 = open("test2.txt", O_RDONLY);
//     // if (fd1 == -1 || fd2 == -1)
//     // {
//     //     perror("Error opening files");
//     //     return (1);
//     // }

//     printf("Reading from test1.txt:\n");
// 	line1 = get_next_line(fd1);
//     while (line1 != NULL)
//     {
//         printf("%s", line1);
//         free(line1);
//     }
//     // printf("\nReading from test2.txt:\n");
// 	// line2 = get_next_line_bonus(fd2);
//     // while (line2 != NULL)
//     // {
//     //     printf("%s", line2);
//     //     free(line2);
//     // }

//     return (0);
// }


// int main(void)
// {
//     char *line1;
//     char *line2;

//     int fd1 = open("test1.txt", O_RDONLY);
//     int fd2 = open("test2.txt", O_RDONLY);
//     if (fd1 == -1 || fd2 == -1)
//     {
//         perror("Error opening files");
//         return (1);
//     }

//     printf("Reading from test1.txt:\n");
//     while ((line1 = get_next_line(fd1)) != NULL)
//     {
//         printf("%s", line1);
//         free(line1);
//     }

//     printf("\nReading from test2.txt:\n");
//     while ((line2 = get_next_line(fd2)) != NULL)
//     {
//         printf("%s", line2);
//         free(line2);
//     }

//     close(fd1);
//     close(fd2);

//     return (0);
// }
int main()
{
	// int fd = open("test.txt", O_RDWR | O_CREAT , 777);
	char *line;
	// write(fd, "123456789369852147", 19);
	int fd2 = open("41_with_nl", O_RDWR);
	line = get_next_line(fd2);
	while (line)
	{
		printf("%s\n", line);
		free (line);
		line = get_next_line(fd2);
	}
	printf("%p\n", get_next_line(fd2));
	//system("leaks -q a.out");
}

// int main(){

// 	char *stash = "abcdefg\n";
// 	int x = 0;

// 	while (stash[x] != '\0')
// 	{
// 		printf("%s\n", ft_substr(stash, 0, x + (stash[x] == '\n')));
// 		x++;
// 	}
// }


// #include <fcntl.h>
// #include <stdio.h>
// #include "get_next_line_bonus.h"

// int main(void)
// {
//     int fd1, fd2;
//     char *line;

//     // Open the first file
//     fd1 = open("test1.txt", O_RDONLY);
//     if (fd1 < 0)
//     {
//         perror("Error opening file test1.txt");
//         return (1);
//     }

//     // Open the second file
//     fd2 = open("test2.txt", O_RDONLY);
//     if (fd2 < 0)
//     {
//         perror("Error opening file test2.txt");
//         close(fd1);
//         return (1);
//     }

//     // Read lines alternately from both files
//     printf("\nReading from test1.txt:\n");
//     while ((line = get_next_line(fd1)) != NULL)
//     {
//         printf("%s", line);
//         free(line);
//     }

//     printf("\nReading from test2.txt:\n");
//     while ((line = get_next_line(fd2)) != NULL)
//     {
//         printf("%s", line);
//         free(line);
//     }

//     // Close the files
//     close(fd1);
//     close(fd2);

//     return (0);
// }
