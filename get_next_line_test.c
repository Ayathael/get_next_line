
// join and free
char    *ft_free(char *, char *buf) /* */
{
    char    *tempo;/*on créer une chaine de character */

    tempo = ft_strjoin(buffer, buf);/*on dit que notre tempo vaux une chaine qui englobe les chaines buffer et buf */
    free(buffer);/* on liber lespace que prend buffer */
    return (tempo);/* on retourne tempo */
}

-----

// delete line find
char    *ft_next(char *buffer) /* on creer une fonction avec une chaine de charactere */
{
    int        i;/* on initie un i */
    int        j;/* on initie un j */
    char    *line;/* une initie une chaine de caractere Line */

    i = 0;/* on dit que i vaux 0 de base */
    // find len of first line
    while (buffer[i] != '\0' && buffer[i] != '\n')/* ten que notre caractere pointer a la place de i de la chaine buffer nest pas la fin ou un retour a la ligne */
        i++;/* alors i augmente */
    if (!buffer[i])/*si notre valeur a i de la chaine buffer est vide */
    {
        free(buffer);/* on free buffer */
        return (NULL);/* on retourne NULL*/
    }
    // len of file - len of firstline + 1
    line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));/* on donne a line la place memoire de la taille de la longuere de la chaine buffer - la valeur de i +1, de type char */
    i++;/* on augmente i */
    j = 0;/* ont dit que j vaux 0 */
    // line == buffer
    while (buffer[i])/* ten que il ya un charactere a la place de i de la chaine buffer*/
    {
        line[j] = buffer[i];/* on dit que   */
        j++;
        i++;
    }
    free(buffer);/* on liber lespace de buffer*/
    return (line);/* on retourn line */
}

-----

// take line for return
char    *ft_line(char *buffer)/* on creer une fonction qui contien une chaine de caractere*/
{
    char    *line;/* on creer une chaine de caractere */
    int        i;/* on initie un i */

    i = 0;/* on dit que le i vaux 0*/
    // if no line return NULL
    if (!buffer[i])/* si notre valeur a i de la chaine buffer est vide */
        return (NULL);/* on retourne NULL*/
    // go to the eol
    while (buffer[i] != '\0' && buffer[i] != '\n')/* ten que notre chaine buffer nest pas a la fin ou ne trouve pas a la valeur de i un retour a la ligne*/
        i++;/* on augmente i */
    // malloc to eol   
    line = ft_calloc(i + 2, sizeof(char));/*on donne a line, la place memoire despi de la valeur de i +2, a la taille d'un char */
    i = 0;/* on remet i a 0 */
    // line = buffer
    while (buffer[i] != '\0' && buffer[i] != '\n')/* ten que notre chaine buffer nest pas a la fin ou ne trouve pas a la valeur de i un retour a la ligne*/
    {
        line[i] = buffer[i];/* on dit que line de i vaux buffer de i */
        i++;/* on augmente i*/
    }
    // if eol is \0 or \n, replace eol by \n
    if (buffer[i] != '\0' && buffer[i] == '\n')/* si notre chaine nest pas a la fin et rencontre un retour a la ligne */
        line[i] = '\n';/* line a la valeur i vaux un retour a la ligne */
        x++;
    return (line);/* on retourne line */
}

-----
char    *read_file(int fd, char *res)/* on creer une fonction avec un fd, et une chaine de caractere */
{
    char    *buffer;/* on creer une chaine de caractere*/
    int        byte_read;/* on creer un int  */

    // malloc if res dont exist
    if (!res)/* si res nexiste pas */
        res = ft_calloc(1, 1);/* on donne a res la place de 1 case de 1 byte */
    // malloc buffer
    buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));/* on donne a buffer lespace de BUFFER_SIZE +1 , de type char */
    byte_read = 1;/* on dit que notre byte read vaux 1 */
    while (byte_read > 0)/* ten que notre byte read vaux plus que 0*/
    {
        // while not eof read
        byte_read = read(fd, buffer, BUFFER_SIZE);/* alors byte read  lis l                                                                                                                                                                                                                                 a chaine, de taille buffer size sur lentree fd,*/
        if (byte_read == -1)/* si byte read vaux exactement -1*/
        {
            free(buffer);/* on libere la place de buffer */
            return (NULL);/* on retourn null*/
        }
        // 0 to end for leak
        buffer[byte_read] = 0;/* le caractere a la valeur byte read vaux 0 */
        // join and free
        res = ft_free(res, buffer);/* notre chaine res vaux ft_free appliqquer a res et buffer*/
        // quit if \n find
        if (ft_strchr(buffer, '\n'))/* si notre fonction strchrsur la chaine buffer, trouve un \n */
            break ;/* alors on break */
    }
    free(buffer);/* on liber lespace de buffer*/
    return (res);/* on retourne res */
}

-----

char    *read_file(int fd, char *res)/* on crée une fonction qui nous permet de lire le fichier, pour ca on lui demande donc le file descriptor et ce quil faut afficher*/
{
    char    *buffer; /* on créer une chaine de character */
    int        byte_read;/* on créer un int */

    if (!res)/* si le res n'existe pas*/
        res = ft_calloc(1, 1); /* alors res vaux de lespace aloué pour 1case de 1 byte*/
    
    // malloc buffer
    buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));/*on dit que notre chaine buffer prend la place de BUFFER SIZE +1 case, de size of char byte */
    byte_read = 1;/* on initie notrte byte read a 1*/
    while (byte_read > 0)/* ten que notre byte read est plus grand que 0 */
    {
        // while not eof read
        byte_read = read(fd, buffer, BUFFER_SIZE);/* byte read vaux read */
        if (byte_read == -1)/* si byte read est stricterment egale a -1 */
        {
            free(buffer);/*on libere la place attrtibuer a buffer */
            return (NULL);/* on retourn null */
        }
        
        // 0 to end for leak
        buffer[byte_read] = 0;/*on dit que la string buffer pointant a la case de valeur byte read vaux 0 */
        // join and free
        res = ft_free(res, buffer);/*res vaux ft free  */
        // quit if \n find
        if (ft_strchr(buffer, '\n'))/* si on trtouve un back slash n dans la dans chaine buffer*/
            break ;/* alors on break */
    }
    free(buffer);/* on libere lespace donner a buffer*/
    return (res);/* en retourne res */
}
read(fd, buff, size)
