/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:15:44 by vdarras           #+#    #+#             */
/*   Updated: 2024/06/04 16:20:46 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	len;
	size_t	i;
	size_t len_s1;
	size_t len_s2;

	i = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	len = (len_s1 + len_s2);
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (i < len)
	{
		if (i < len_s1)
			result[i] = *(const char *)(s1 + i);
		if (i >= len_s1)
			result[i] = *(char *)(s2 + i - len_s1);
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strdup(const char *source)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = (char *) malloc(ft_strlen((char *) source) * sizeof(char) + 1);
	if (!dest)
		return (NULL);
	while (source[i])
	{
		*(dest + i) = *(char *)(source + i);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char) c)
			return ((char *) str);
		str++;
	}
	if (!*str && (char)c == '\0')
	{
		return ((char *) str);
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	slen;
	size_t	i;
	size_t len_s;

	len_s = ft_strlen(s);
	if (!s)
		return (NULL);
	slen = len;
	if (len_s - start < len)
		slen = len_s - start;
	if (start > len_s)
		return (ft_strdup(""));
	str = malloc(sizeof(char) * (slen + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (*(s + start) && i < len)
	{
		str[i] = *(char *)(s + start);
		i++;
		s++;
	}
	str[i] = '\0';
	return (str);
}
