/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimi-be <shimi-be@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:28:16 by shimi-be          #+#    #+#             */
/*   Updated: 2024/11/13 20:36:21 by shimi-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	ft_strlen(const char *str, int flag)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (!flag)
		while (str[i])
			i++;
	else
		while (str[i] != '\n')
			i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		len;
	char	*arr;

	len = ft_strlen(s1, 0) + ft_strlen(s2, 0);
	arr = (char *) malloc (len + 1);
	if (!arr)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
	{
		while (s1[i])
		{
			arr[i] = s1[i];
			i++;
		}
	}
	while (s2[j])
	{
		arr[i + j] = s2[j];
		j++;
	}
	arr[i + j] = '\0';
	return (arr);
}

char	*ft_strchr(const char *str, char c)
{
	int		i;
	char	*s;

	s = (char *)str;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (&s[i+1]);
		i++;
	}
	return (NULL);
}

char	*ft_strchr2(const char *str, char c)
{
	int		i;
	int		len;
	char	*arr;
	char	*s;

	len = 0;
	s = (char *)str;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			i++;
			while (str[i])
				len++;
			arr = (char *)malloc(len+1);
			if (!arr)
				return (NULL);
			len = 0;
			while (str[i])
			{
				s[i+len] = arr[len];
				len++;
			}
			arr[len] = '\0';
			if (arr[0] == '\0')
				return (free(arr),NULL);
			return (arr);
		}
		i++;
	}
	return (NULL);
}

char	*ft_cleanline(char *str)
{
	char	*temp;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str, 1) + 1;
	temp = (char *) malloc ((len + 1));
	if (!temp)
		return (NULL);
	while (len > i)
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*ft_getline(char *arr, int fd)
{
	int		bytes_read;
	char	*stash;
	char	buffer[BUFFER_SIZE + 1];

	bytes_read = 1;
	while ((bytes_read > 0) && (!ft_strchr(buffer, '\n')))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = '\0';
		if (bytes_read > 0)
		{
			stash = ft_strjoin(arr,buffer);
			free(arr);
			arr = stash;
		}
		else if (bytes_read == 0)
		{
			if(!arr)
				return(free(arr),NULL);
			return (arr);
		}
		else if (bytes_read < 0)
			return (NULL);	
	}
	return (arr);
}
