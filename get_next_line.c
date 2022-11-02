
#include "get_next_line.h"


/*Va prendre une chaine1 et la fusionner a la chaine2 , cette fusion constitue chainetemporaire, on libere la place de chaine1 */ 
char *ft_free(char *chaine1, char *chaine2)
{
    char chainetemporaire;

    chainetemporaire = ft_strjoin(chaine1, chaine2);
    free(chaine1);
    return(chainetemporaire);
}

/* fonction sers, lire le nb de chaine rendu a valeur de buffsize, a grader le reste, 1 on regarde si il y a un reste, et 2 on garde le reste*/
char *ft_next(char *chaine)
{
    int x;
    int y;
    char *str;

    x = 0;
    while(chaine[x] != '\0' && chaine[x] != '\n')
    {
        x++;
    }
    if(chaine[x] == 0)
    {
        free(chaine);
        return(NULL);
    }
    str = ft_calloc((ft_strlen(chaine) - x +1), sizeof(char));
    x++;
    y = 0;
    while(chaine[x])
    {
        str[y] = chaine[x];
        x++;
        y++;
    }
    free(chaine);
    return(str);
}

/*regarde la chaine et copie cest valeur dans str, puis renvoie str. En suivant les \n */
char *ft_line(char *chaine)
{
    int x;
    char *str;

    x = 0;
    if(chaine == 0)
    {
        return(NULL);
    }
    while(chaine[x] != '\0' && chaine[x] != '\n')
    {
        x++;
    }
    str = ft_calloc(x +2, sizeof(char));
    x = 0;
    while(chaine[x] != '\0' && chaine[x] != '\n')
    {
        str[x] = chaine[x];
        x++;
    }
    if(chaine[x] != '\0' && chaine[x] == '\n')
    {
        str[x] = '\n';
        x++;
    }
    return(str);

}

char *readfile(int fd, char *res)
{
    char *str;
    int byte_read;
    if(!res)
}