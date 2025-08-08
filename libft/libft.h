/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:37:08 by iherman-          #+#    #+#             */
/*   Updated: 2025/08/08 15:05:21 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/*///////////////////////////////////*/
//		String Manipulation          //
/*///////////////////////////////////*/
//		Returning modified string(s)
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
char	**ft_split(char const *s, char c);
//		Direct string manipulation
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
//		Gathering string data
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *source, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strrchr(const char *str, int c);
char	*ft_strchr(const char *str, int c);
int		ft_strncmp(const char *str1, const char *str2, size_t len);

/*///////////////////////////////////*/
//		Memory Management            //
/*///////////////////////////////////*/
//		setting memory / allocation
void	*ft_memset(void *s, int c, size_t num);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	ft_bzero(void *s, size_t num);
void	*ft_calloc(size_t num, size_t size);
//		Gathering memory data
int		ft_memcmp(const void *p1, const void *p2, size_t num);
void	*ft_memchr(const void *s, int c, size_t n);

/*///////////////////////////////////*/
//		Printing to fd               //
/*///////////////////////////////////*/
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);

/*///////////////////////////////////*/
//		ASCII                        //
/*///////////////////////////////////*/
//		Checks
int		ft_isprint(int c);
int		ft_isdigit(int c);
int		ft_isascii(int c);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
//		Modification
int		ft_toupper(int c);
int		ft_tolower(int c);

/*///////////////////////////////////*/
//		Variable Conversion          //
/*///////////////////////////////////*/
char	*ft_itoa(int n);
int		ft_atoi(const char *str);

/*///////////////////////////////////*/
//		List Manipulation (BONUS)    //
/*///////////////////////////////////*/
//		Generating lists
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
//		Modifying lists
void	ft_lstiter(t_list *lst, void (*f)(void *));
//		Destroying lists
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
//		Gathering list data
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);

#endif // LIBFT_H