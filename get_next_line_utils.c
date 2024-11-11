/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimi-be <shimi-be@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:28:16 by shimi-be          #+#    #+#             */
/*   Updated: 2024/11/10 20:45:21 by shimi-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str, int flag)
{
	int	i;

	i = 0;
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
	while (s1[i])
	{
		arr[i] = s1[i];
		i++;
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
			return (&s[i]);
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
	return (temp);
}

char	*ft_splitline(char **arr, int fd)
{
	int		bytes_read;
	char	*temp;
	char	*stash;

	bytes_read = 1;
	temp = NULL;
	stash = NULL;
	while ((bytes_read > 0) && (!ft_strchr(*arr, '\n')))
	{
		bytes_read = read(fd, *arr, BUFFER_SIZE);
		if (bytes_read > 0)
		{
			stash = ft_strjoin(stash,*arr);
			if (!stash)
				return (NULL);
			if (ft_strchr(*arr, '\n'))
			{
				temp = ft_cleanline(stash);
				*arr = ft_strchr(stash, '\n');
			}
		}
	}
	return (temp);
}
