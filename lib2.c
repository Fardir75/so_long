/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:59:47 by eavilov           #+#    #+#             */
/*   Updated: 2022/03/28 16:01:53 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	count(int nb)
{
	int	count;

	count = 0;
	if (nb <= 0)
		count++;
	while (nb != 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nbr;
	int		h;

	nbr = n;
	h = count(n);
	str = malloc(sizeof(char) * (h + 1));
	if (!str)
		return (NULL);
	str[h] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		str[h - 1] = (nbr % 10) + '0';
		nbr = nbr / 10;
		h--;
	}
	return (str);
}

char	*ft_strrdup(char const *src, char c)
{
	int		index;
	char	*array;
	int		y;

	index = 0;
	y = 0;
	while (src[index] && src[index] != c)
		index++;
	array = malloc (sizeof (char) * (index + 1));
	if (!array)
		return (NULL);
	while (y < index)
	{
		array[y] = src[y];
		y++;
	}
	array[y] = '\0';
	return (array);
}

int		countchar(char const *s, char c)
{
	int	k;
	int	count;

	k = 0;
	count = 0;
	while (s[k])
	{
		if ((k == 0) && s[0] != c)
			count++;
		else if (s[k] != c && s[k - 1] == c)
			count++;
		k++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		count;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	count = countchar(s, c);
	result = malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
		{
			result[i] = ft_strrdup(s, c);
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	result[i] = NULL;
	return (result);
}