
// join and free
char    *ft_free(char *buffer, char *buf) /* */
{
    char    *tempo;/*on créer une chaine de character */

    tempo = ft_strjoin(buffer, buf);/*on dit que notre tempo vaux une chaine qui englobe les chaines buffer et buf */
    free(buffer);/* on liber lespace que prend buffer */
    return (tempo);/* on retourne tempo */
}



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
