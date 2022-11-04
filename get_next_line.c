# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "get_next_line.h"

/*Va prendre la chainebuffer(une chaine deja découper en fonction de la taille de buffer_size) et la fusionner avec buff(une chaine decouper en fonciton de buffer size, venant apres la valeur de la 1e chaine , cette fusion constitue chainetemporaire, on libere la place de chainebuffer */
char *ft_free(char *chainebuffer, char *buff)
{
    char *chainetemporaire;

    chainetemporaire = ft_strjoin(chainebuffer, buff);
    free(chainebuffer);
    return(chainetemporaire);
}

/* lis une chainebuffer (qui a pour taille la valeur donner par BUFFER_SIZE /ex: ''blabla'',si buffer size 3 > alors chaine vaut ''bla''/ vérifie si il y a encore des choses a afficher ensuite, renvoie la suites */
char *ft_next(char *chainebuffer)
{
    int x;
    int y;
    char *str;

    x = 0;
    while(chainebuffer[x] != '\0' && chainebuffer[x] != '\n')
    {
        x++;
    }
    if(chainebuffer[x] == '\0')
    {
        free(chainebuffer);
        return(NULL);
    }
    str = ft_calloc((ft_strlen(chainebuffer) - x +1), sizeof(char));
    x++;
    y = 0;
    while(chainebuffer[x] != '\0')
    {
        str[y] = chainebuffer[x];
        x++;
        y++;
    }
    free(chainebuffer);
    return(str);
}

/*lis la chainebuffer, verifie si elle possède un \n et quil faut mettre un retour a la ligne, ou si il reste des caractere sur la meme ligne.(dans ce cas on renvoie juste notre chainebuffer et on passe a la suite de la ligne)*/
char *ft_line(char *chainebuffer)
{
    int x;
    char *str;

    x = 0;
    if(chainebuffer == 0)
    {
        return(NULL);
    }
    while(chainebuffer[x] != '\0' && chainebuffer[x] != '\n')
    {
        x++;
    }
    str = ft_calloc(x +2, sizeof(char));
    x = 0;
    while(chainebuffer[x] != '\0' && chainebuffer[x] != '\n')
    {
        str[x] = chainebuffer[x];
        x++;
    }
    if(chainebuffer[x] != '\0' && chainebuffer[x] == '\n')
    {
        str[x] = '\n';
        x++;
    }
    return(str);

}

/* cette fonction sers a vérifier si on peut lire le fichier et renvoyer la premiere ligne trouver avant un \n */
char    *read_file(int fd, char *result)
{
    char    *chainebuffer;
    int        isfonctionreadok;

    if (!result)
        result = ft_calloc(1, 1);
    chainebuffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    isfonctionreadok = 1;
    while (isfonctionreadok > 0)
    {
        isfonctionreadok = read(fd, chainebuffer, BUFFER_SIZE);
        if (isfonctionreadok == -1) /* si le read na pas marché */
        {
            free(chainebuffer);
            return (NULL);
        }
        chainebuffer[isfonctionreadok] = 0;
        result = ft_free(result, chainebuffer);
        if (ft_strchr(chainebuffer, '\n'))
            break ;
    }
    free(chainebuffer);
    return (result);
}

/* foncion qui verifie qu'il n'y es pas d'erreur (de fd, de buff_syze ou de read), et retourn la 1e ligne, puis la garde en souvenir gracce au static pour ne pas la reafficher au second apelle */
char    *get_next_line(int fd)
{
    static char    *chainebuffer;
    char        *line;

    // error handling
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
        return (NULL);
    chainebuffer = read_file(fd, chainebuffer);
    if (!chainebuffer)
        return (NULL);
    line = ft_line(chainebuffer);
    chainebuffer = ft_next(chainebuffer);
    return (line);
}

int        main(void)
{
    int fd = open("message.txt", O_RDONLY);
    if (fd == -1)
    {
    printf("error with opening of file\n");
    }
    printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));
}
