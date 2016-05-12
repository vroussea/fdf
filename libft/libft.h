/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libtf.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:50:51 by vroussea          #+#    #+#             */
/*   Updated: 2016/04/26 20:18:16 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <string.h>
# define BUFF_SIZE 50000

typedef struct		s_file
{
	int				fd;
	char			*str;
	struct s_file	*next;
	struct s_file	*prev;
}					t_file;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** free a void** var
*/
void				ft_tabdel(void ***tab);
/*
** swap 2 int
*/
void				ft_intswap(int *a, int *b);
/*
** read a file line per line
*/
int					get_next_line(int const fd, char **line);
/*
** create new link of type t_list
*/
t_list				*ft_lstnew(void const *content, size_t content_size);
/*
** add new node at the start of the list
*/
void				ft_lstadd(t_list **alst, t_list *new);
/*
** add new node at the end of the list
*/
void				ft_lstadd_end(t_list **alst, t_list *new);
/*
** del one link from the list
*/
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
/*
** del a complete chain
*/
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
/*
** apply f to each node of lst
*/
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
/*
** apply f to each node of lst, and return resulting list
*/
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
/*
** remplace les len premiers bytes de la chaine b par c
*/
void				*ft_memset(void *b, int c, size_t len);
/*
** remplace les n premiers bytes de la chaine s par 0
*/
void				ft_bzero(void *s, size_t n);
/*
** set '\0' for all char in string s
*/
void				ft_strclr(char *s);
/*
** copie les n premiers bytes de src dans dst
*/
void				*ft_memcpy(void *dst, const void *src, size_t n);
/*
** copie les n premiers bytes de src dans dst, ou s'arrete des qu'il
** rencontre c et renvoit la case memoire contenant c de dst
*/
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
/*
** copie les len premiers bytes de src dans dst, be careful with overlap
** copie faite de maniere non destructive
*/
void				*ft_memmove(void *dst, const void *src, size_t len);
/*
** Localise la premiere apparition de c dans s de taille n bytes
*/
void				*ft_memchr(const void *s, int c, size_t n);
/*
** locates first appearance of c in s and return a pointer to it
*/
char				*ft_strchr(const char *s, int c);
/*
** locate last appearance of c in s and return a pointer to it
*/
char				*ft_strrchr(const char *s, int c);
/*
** invert string s
*/
char				*ft_strinv(char *s);
/*
** lexicographycally compare s1 and s2, return int less than 0 if s1 is less
** than s2, 0 if s1 = s2, more than 0 if s1 is greater than s2
*/
int					ft_strcmp(const char *s1, const char *s2);
/*
** same as strcmp, but only compare n char
*/
int					ft_strncmp(const char *s1, const char *s2, size_t n);
/*
** compare 2 chaines toutes deux ayant n caracteres et renvoit la difference
** en ASCII des deux premiers caracteres differents, si egaux, renvoit 0
*/
int					ft_memcmp(const void *s1, const void *s2, size_t n);
/*
** retourne la longueur d'une chaine (sans compter \0)
*/
size_t				ft_strlen(const char *s);
/*
** write an int
*/
void				ft_putnbr_fd(int n, int fd);
/*
** call ft_putnbr_fd on fd:1 (file descriptor)
*/
void				ft_putnbr(int n);
/*
** write a char
*/
void				ft_putchar_fd(char c, int fd);
/*
** call ft_putchar_fd on fd:1
*/
void				ft_putchar(char c);
/*
** write a string and do '\n'
*/
void				ft_putendl_fd(char const *s, int fd);
/*
** call ft_putendl_fd on fd:1
*/
void				ft_putendl(char const *s);
/*
** write a string
*/
void				ft_putstr_fd(const char *s, int fd);
/*
** call ft_putstr_fd on fd:1
*/
void				ft_putstr(char const *s);
/*
** put null-terminated s2 at the end of null-terminated s1
*/
char				*ft_strcat(char *s1, const char *s2);
/*
** put n char of null terminated s2 at the end of null terminated s1
*/
char				*ft_strncat(char *s1, const char *s2, size_t n);
/*
** user choose size of the buffer, and only copy if dst has enough space for src
** also put a terminating \0
*/
size_t				ft_strlcat(char *dst, const char *src, size_t size);
/*
** return non-null if c is a printable char
*/
int					ft_isprint(int c);
/*
** search first occurence of string null-terminated s2 in null-terminated s1
** return s1 if s2 is empty, NULL if s2 is nowhere, and a pointer where s2
** occure else
*/
char				*ft_strstr(const char *s1, const char *s2);
/*
** same as strstr, but in n char
*/
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
/*
** copy src in dst
*/
char				*ft_strcpy(char *dst, const char *src);
/*
** copy n char from src to dst, if src is smaller than n, fill the rest of
** dst with \0, if src is long enough for n char, dst is not terminated
*/
char				*ft_strncpy(char *dst, const char *src, size_t n);
/*
** allocate "fresh" memory area initializited to 0
** if allocation fail, return NULL
*/
void				*ft_memalloc(size_t size);
/*
** create a new str filled with \0 and size of size
*/
char				*ft_strnew(size_t size);
/*
** free memory pointed by ap ans set tn pointer to NULL
*/
void				ft_memdel(void **ap);
/*
** free memory of a string pointed by as, and set pointer to NULL
*/
void				ft_strdel(char **as);
/*
** convert a lower case letter to a upper case letter
*/
int					ft_toupper(int c);
/*
** convert a upper case letter to a lower case letter
*/
int					ft_tolower(int c);
/*
** 1 if ASCII value is lower case letter, 0 else
*/
int					ft_islower(int c);
/*
** 1 if ASCII value is upper case letter, 0 else
*/
int					ft_isupper(int c);
/*
** 0 if is not a letter,  ASCII value if is a letter
*/
int					ft_isalpha(int c);
/*
** 0 if is not decimal digit character, c else
*/
int					ft_isdigit(int c);
/*
** 0 if not a letter or a decimal digit letter, c else
*/
int					ft_isalnum(int c);
/*
** 0 if is not an ascii char, 1 else
*/
int					ft_isascii(int c);
/*
** allocate memory and copy s1 in new str, return NULL if memalloc don't work
*/
char				*ft_strdup(const char *s1);
/*
** convert an alpha num string to an int
*/
int					ft_atoi(const char *str);
/*
** convert an int to an alpha num string
*/
char				*ft_itoa(int n);
/*
** return 1 if c is \t, \n, \r, \v, ' ', 0 else
*/
int					ft_isspace(int c);
/*
** return a new string with content of s without starting and ending whitespaces
** return null if malloc failed
*/
char				*ft_strtrim(const char *s);
/*
** split s in different strings separated by c
*/
char				**ft_strsplit(char const *s, char c);
/*
** apply f to each char of s passed as arguments in f
*/
void				ft_striter(char *s, void (*f)(char *));
/*
** same as striter but give index of each char as argument to f
*/
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
/*
** pass each char of s to f and put result in new string before returning it
*/
char				*ft_strmap(char const *s, char (*f)(char));
/*
** same as strmap but give index of each char as argument to f
*/
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
/*
** compare s1 and s2, if equals return 1, 0 else
*/
int					ft_strequ(char const *s1, char const *s2);
/*
** same as strequ, but stop zhen n is reached or when encountering \0
*/
int					ft_strnequ(char const *s1, char const *s2, size_t n);
/*
** copy trunk from s to new str, copy start at 'start' and end 'len' char after
*/
char				*ft_strsub(char const *s, unsigned int start, size_t len);
/*
** create new string made of s1 + s2 concatenated, but doesn't chnge s1 and s2
*/
char				*ft_strjoin(char const *s1, char const *s2);
/*
** return x pow y
*/
int					ft_pow(double x, double y);
/*
** return the squarre root of x
*/
int					ft_sqrt(int x);
/*
** return the absolute value of n in an unsigned int
*/
unsigned int		ft_abs(int n);
/*
** create an identitary double matrix[size][size]
*/
double				**ft_matrixid(int size);
#endif
