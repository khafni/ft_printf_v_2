/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utills.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 00:47:39 by khafni            #+#    #+#             */
/*   Updated: 2020/02/24 02:24:06 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILLS_H
# define UTILLS_H
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

/*
** an int that i use to calculate the my printf return
** via increaminting it everytime i print a character
*/

int		g_return;

/*
**	function that "apply" the absolute value on a number
*/
int		ft_abs(int nb);
/*
** function that transform a string that contains a number
** to a string that it returns
*/
int		ft_atoi(const char *str);

/*
** function that checks if a character is an "ascii" digit
*/

int		ft_isdigit(int c);

/*
** function that gets a number as input and returns its length
*/
long	digitlen(long n);

/*
** function that gets a long number and returns its string version
*/
char	*ft_ltoa(long n);

/*
** function that prints a character
*/
int		format_length(char *s);

/*
** function that print a character to a file descriptor
** using the write system call and it also increament
** the global variable g_return that i use to
** calculate the return of my printf
*/
void	ft_putchar_fd(char c, int fd);

/*
** function that print a string and it is implemented
** using the previous ft_putchar that has the side effect
** of increamenting g_return everytime it's called
*/

void	ft_putstr_fd(char *s, int fd);

/*
**  function that looks for a character in a string
**  and if found it returns its position in the string
**  if not it returns NULL
*/

char	*ft_strchr(const char *s, int c);

/*
**  function that saves a copy of a string in the heap and retuns
**  a pointer to that copy
*/

char	*ft_strdup(const char *s1);

/*
** convert from decimal to hexdecimal
*/

char	*dec_to_hex(size_t nb);

/*
**  size-bounded string copying and concatenation
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

/*
** find length of a string
*/

size_t	ft_strlen(const char *s);

/*
**  function that copies a memory area to another
**  in a size bounded way
*/
void	*ft_memcpy(void *dst, const void *src, size_t n);

/*
**  function that takes an int and output it to a file descriptor
*/

void	ft_putnbr_fd(int n, int fd);

/*
**  the same as the previous function but works with longs too
*/
void	ft_putnbr_long(long n);

/*
**  function that counts how many character between the
**  % and its specifier and returns that length
*/

int		format_length(char *s);

/*
**  function that gets a number in the form of a string
**  and returns its value as a long
*/

long	ft_ltoi(const char *str);

/*
**  function that transforms all the lowercase
**  letters of a string to uppercase
**  (if it's a mutable string)
*/
void	ft_to_lower(char *str);

/*
**  function that takes to string concatenate them and returns
**  the resulting concatenated string
*/

char	*ft_strjoin(char const *s1, char const *s2);

/*
**	function that takes a hexdecimal number that
**  that is a string and returns it as a
**  decimal number
*/

size_t	hex_to_dec(char *nb);

/*
**  function that takes a decimal number and
**  returns it as hexdecimal number in an allocated string
*/

char	*dec_to_hex(size_t nb);

/*
**	change lowercase letters in a string to uppercase
*/
void	ft_to_lower(char *str);
#endif
