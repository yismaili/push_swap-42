/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:00:37 by yismaili          #+#    #+#             */
/*   Updated: 2022/04/14 18:01:01 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*dst;
	size_t			j;
	size_t			i;

	j = 0;
	i = 0;
	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	dst = (char *)malloc((len + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			dst[j] = s[i];
			j++;
		}
		i++;
	}
	dst[j] = '\0';
	return (dst);
}

int	ft_lenwrd(const char *s, char c)
{
	int	len;

	len = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			len++;
			while (*s != '\0' && *s != c)
			{
				s++;
			}
			if (*s == '\0')
				return (len);
		}
		s++;
	}
	return (len);
}

void	*ft_free(char **dest, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(dest[i]);
		i++;
	}
	free (dest);
	return (NULL);
}

char	**ft_checkalocc(char **dest, const char *s, char c)
{
	size_t	i;
	int		j;
	size_t	index;

	i = 0;
	j = 0;
	while (i <= ft_strlen(s))
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		index = i;
		while (s[i] != '\0' && s[i] != c)
			i++;
		if (index != i)
		{
			dest[j] = ft_substr(s, index, i - index);
			if (!dest[j])
				return (ft_free(dest, j));
			j++;
		}
		i++;
	}
	dest[j] = 0;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;

	if (!s)
		return (NULL);
	dest = (char **)malloc((ft_lenwrd(s, c) + 1) * sizeof(char *));
	if (!dest)
		return (NULL);
	dest = ft_checkalocc(dest, s, c);
	return (dest);
}
