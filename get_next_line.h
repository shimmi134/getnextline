/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimi-be <shimi-be@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:37:29 by shimi-be          #+#    #+#             */
/*   Updated: 2024/11/13 18:27:24 by shimi-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>

char *get_next_line(int fd);
int ft_strlen(const char *str, int flag);
char *ft_cleanline(char *str);
char *ft_getline(char *arr, int fd);
char *ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *str, char c);
char	*ft_strchr2(const char *str, char c);

#endif
