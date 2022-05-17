/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrafik <mrafik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 22:48:43 by mrafik            #+#    #+#             */
/*   Updated: 2021/12/20 16:53:18 by mrafik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (i <= ft_strlen(s))
	{
		if (*(s + i) == (char)c)
		{
			return ((char *)(s + i));
		}
		i++;
	}
	return (0);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	ptr = (char *)(malloc((i + 1) * sizeof(char)));
	if (!ptr)
		return (0);
	while (j < i)
	{
		ptr[j] = s1[j];
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	b;
	char			*ptr;
	size_t			x;

	b = ft_strlen(s);
	x = 0;
	if (!s)
		return (0);
	if (b - start <= len)
		len = b - start;
	if (start > b)
		return (ft_strdup(""));
	ptr = (char *)(malloc((len + 1) * sizeof (char)));
	if (!ptr)
		return (0);
	while (x < len)
	{
		ptr[x] = s[start];
		start++;
		x++;
	}
	ptr[x] = '\0';
	return (ptr);
}
