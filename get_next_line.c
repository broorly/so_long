/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrafik <mrafik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 22:58:47 by mrafik            #+#    #+#             */
/*   Updated: 2022/05/16 14:18:44 by mrafik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		s1 = ft_strdup("");
	p = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!p)
		return (NULL);
	while (s1[i])
		p[j++] = s1[i++];
	i = 0;
	while (s2[i])
		p[j++] = s2[i++];
	p[j] = '\0';
	free(s1);
	return (p);
}

int	cont(char *stock)
{
	int	i;

	i = 0;
	while (stock[i] != '\n' && stock[i] != '\0')
		i++;
	return (i);
}

char	*stockline(char *stock, char *buffer, int rd, int fd)
{
	while (rd > 0 && !ft_strchr(buffer, '\n'))
	{
		rd = read(fd, buffer, 1);
		if (rd < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[rd] = '\0';
		stock = ft_strjoin(stock, buffer);
	}
	free(buffer);
	if (rd == 0 && stock[0] == '\0')
	{
		free(stock);
		stock = NULL;
		return (0);
	}
	return (stock);
}

char	*get_next_line(int fd)
{
	int			rd;
	char		*buffer;
	static char	*stock;
	int			i;
	char		*tmp;

	rd = 1;
	if (fd < 0)
		return (0);
	buffer = (char *) malloc(1 + 1);
	buffer[0] = 0;
	stock = stockline(stock, buffer, rd, fd);
	if (!stock)
		return (NULL);
	i = cont(stock);
	buffer = ft_substr(stock, 0, i + 1);
	tmp = stock;
	stock = ft_substr(stock, i + 1, ft_strlen(stock));
	free(tmp);
	return (buffer);
}
