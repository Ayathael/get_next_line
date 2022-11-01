


static int    addline(char **s, char **line)/* ajouter une ligne*/
{
    int        len; /*on initie un commpteur len pour la longeur*/
    char    *tempo;/*on initie un pointeur de chaine de charactere */

    len = 0;/* on défini la longueur de base a 0*/
    while ((*s)[len] != '\n' && (*s)[len] != '\0')/* on dit que ten que notre pointeur de pointeur de chaine de charatere a la valeur de len ne vaux pas un rettour a la ligne et que la chaine nes pas a la fin */
        len++;/* alors on augmente la longeur*/
    if ((*s)[len] == '\n')/* si on rencontre un retour a la ligne*/
    {
        *line = ft_strsub(*s, 0, len);/* on dit que line  */
        tempo = ft_strdup(&((*s)[len + 1]));/* */
        free(*s);/* on brule l'ancien *s */
        *s = tempo;/*en remet la ligne avec back slash 0 en plus */
        if ((*s)[0] == '\0')/* si cest une ligne vide */
            ft_strdel(s);/* on suprime la ligne vide */
    }
    else/* */
    {
        *line = ft_strdup(*s);/* si le derneir charactere nes pas back slash n on copie la ligne */
        ft_strdel(s);/* fin de la ligne s donc on libere s */
    }
    return (1);/* signifie on a pus reussir a ajouter une ligne*/


blabla nya
bloblo blihdjs
blu

*line = blabla nya
tempo = blabla nya-0


----
    static int    output(char **s, char **line, int ret, int fd)
    {
        if (ret < 0)
            return (-1);
        else if (ret == 0 && s[fd] == NULL)
            return (0);
        else
            return (appendline(&s[fd], line));
    }
    
----
    
char   *get_next_line(int fd)
{
        int            ret;
        static char    *s[FD_SIZE];
        char        buff[BUFF_SIZE + 1];
        char        *tmp;

        if (fd < 0 || line == NULL)
            return (-1);
        while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
        {
            buff[ret] = '\0';
        if (s[fd] == NULL)
            s[fd] = ft_strdup(buff);
        else
        {
            tmp = ft_strjoin(s[fd], buff);
            free(s[fd]);
            s[fd] = tmp;
        }
        if (ft_strchr(s[fd], '\n'))
            break ;
    }
    return (output(s, line, ret, fd));
}
