
// join and free
char    *ft_free(char *buffer, char *buf) /* */
{
    char    *tempo;/*on créer une chaine de character */

    tempo = ft_strjoin(buffer, buf);/*on dit que notre tempo vaux une chaine qui englobe les chaines buffer et buf */
    free(buffer);/* on liber lespace que prend buffer */
    return (tempo);/* on retourne tempo */
}

-----

// delete line find
char    *ft_next(char *buffer) /* */
{
    int        i;
    int        j;
    char    *line;

    i = 0;
    // find len of first line
    while (buffer[i] && buffer[i] != '\n')
        i++;
    // if eol == \0 return NULL
    if (!buffer[i])
    {
        free(buffer);
        return (NULL);
    }
    // len of file - len of firstline + 1
    line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
    i++;
    j = 0;
    // line == buffer
    while (buffer[i])
        line[j++] = buffer[i++];
    free(buffer);
    return (line);
}

-----

// take line for return
char    *ft_line(char *buffer)
{
    char    *line;
    int        i;

    i = 0;
    // if no line return NULL
    if (!buffer[i])
        return (NULL);
    // go to the eol
    while (buffer[i] && buffer[i] != '\n')
        i++;
    // malloc to eol
    line = ft_calloc(i + 2, sizeof(char));
    i = 0;
    // line = buffer
    while (buffer[i] && buffer[i] != '\n')
    {
        line[i] = buffer[i];
        i++;
    }
    // if eol is \0 or \n, replace eol by \n
    if (buffer[i] && buffer[i] == '\n')
        line[i++] = '\n';
    return (line);
}

-----
char    *read_file(int fd, char *res)
{
    char    *buffer;
    int        byte_read;

    // malloc if res dont exist
    if (!res)
        res = ft_calloc(1, 1);
    // malloc buffer
    buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    byte_read = 1;
    while (byte_read > 0)
    {
        // while not eof read
        byte_read = read(fd, buffer, BUFFER_SIZE);
        if (byte_read == -1)
        {
            free(buffer);
            return (NULL);
        }
        // 0 to end for leak
        buffer[byte_read] = 0;
        // join and free
        res = ft_free(res, buffer);
        // quit if \n find
        if (ft_strchr(buffer, '\n'))
            break ;
    }
    free(buffer);
    return (res);
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
