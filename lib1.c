/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:59:51 by eavilov           #+#    #+#             */
/*   Updated: 2022/03/28 15:59:52 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while(s[i])
		i++;
	return(i);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

char	*ft_strtjoin(char const *s1, char const *s2, char const *s3)
{
	char	*result;
	size_t	len;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3);
	result = (char *)malloc(sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	while (*s1)
		result[i++] = *s1++;
	while (*s2)
		result[i++] = *s2++;
	while (*s3)
		result[i++] = *s3++;
	result[i] = '\0';
	return ((char *) result);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*array;
	int		y;

	i = 0;
	y = 0;
	if (!src)
		return (NULL);
	while (src[i])
		i++;
	array = malloc (sizeof (char) * (i + 1));
	if (!array)
		return (NULL);
	while (y < i)
	{
		array[y] = src[y];
		y++;
	}
	array[y] = '\0';
	return (array);
}
