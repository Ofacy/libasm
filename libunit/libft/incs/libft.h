/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:36:22 by ibertran          #+#    #+#             */
/*   Updated: 2026/02/25 15:37:08 by lcottet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBlibft_H
# define LIBlibft_H

/* includes *******************************************************************/

# include <stddef.h>

# include "ft_integer.h"
# include "libft_lst.h"
# include "ft_vector.h"

/* functions ******************************************************************/

int		libft_countwords(const char *str, const char *sep);
void	*libft_memcpy2(void *dest, const void *src_start, void *src_end);
char	**libft_split(char const *s, char c);
char	*libft_itoa_base(int nbr, char *base);
char	*libft_itoa(int n);
char	*libft_strchr(const char *s, int c);
char	*libft_strcpy(char *dst, const char *src);
char	*libft_strdup(const char *s);
char	*libft_strjoin(char const *s1, char const *s2);
char	*libft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*libft_strnstr(const char *big, const char *little, size_t len);
char	*libft_strrchr(const char *s, int c);
char	*libft_strtrim(char const *s1, char const *set);
char	*libft_substr(char const *s, unsigned int start, size_t len);
char	*libft_uitoa_base(unsigned int nbr, char *base);
char	*libft_ulltoa_base(unsigned long long nbr, char *base);
int		libft_atoi(const char *nptr);
int		libft_close(int *fd);
int		libft_isalnum(int c);
int		libft_isalpha(int c);
int		libft_isascii(int c);
int		libft_ischarset(const char c, const char *set);
int		libft_isdigit(int c);
int		libft_isprint(int c);
int		libft_isspace(int c);
int		libft_itoalen_base(int n, char *base);
int		libft_itoalen(int n);
int		libft_memcmp(const void *s1, const void *s2, size_t n);
int		libft_strcmp(const char *str1, const char *str2);
int		libft_strncmp(const char *s1, const char *s2, size_t n);
int		libft_tolower(int c);
int		libft_toupper(int c);
int		libft_uitoalen_base(unsigned int n, char *base);
int		libft_ulltoalen_base(unsigned long long nbr, char *base);
size_t	libft_strlcat(char *dst, const char *src, size_t size);
size_t	libft_strlcpy(char *dst, const char *src, size_t size);
size_t	libft_strlen_protected(const char *str);
size_t	libft_strlen(const char *s);
size_t	libft_strnlen(const char *str, size_t n);
void	*libft_calloc(size_t nmemb, size_t size);
void	*libft_memchr(const void *s, int c, size_t n);
void	*libft_memcpy(void *dest, const void *src, size_t n);
void	*libft_memmove(void *dest, const void *src, size_t n);
void	*libft_memset(void *s, int c, size_t n);
void	*libft_xmalloc(size_t size);
void	libft_bzero(void *s, size_t n);
void	libft_free_array(void **array);
void	libft_putnbr_fd(int n, int fd);
void	libft_striteri(char *s, void (*f)(unsigned int, char*));
char	*libft_strtok(char *str, const char *delimiters);
/* libft_PRINTF ******************************************************************/

int		libft_printf(const char *str, ...);
int		libft_dprintf(int fd, const char *str, ...);
/* GET_NEXT_LINE **************************************************************/

// char	*get_next_line_multifd(int fd);
// char	*get_next_line(int fd);

#endif