#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>

typedef struct s_list
{
    void            *content;
    size_t          content_size;
    struct s_list    *next;
}                    t_list;

char    *get_next_line(int fd);
char    *read_file(int fd, char *result);
char    *ft_line(char *chainebuffer);
char    *ft_next(char *chainebuffer);
char    *ft_free(char *chainebuffer, char *buff);

void    ft_bzero(void *ptr, size_t len);
void    *ft_calloc(size_t nmemb, size_t size);
size_t    ft_strlen(const char *str);
char    *ft_strjoin(char const *s1, char const *s2);
char    *ft_strchr(const char *s, int c);
#endif
