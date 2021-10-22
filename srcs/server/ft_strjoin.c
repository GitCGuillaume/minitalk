/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 12:55:08 by gchopin           #+#    #+#             */
/*   Updated: 2020/05/05 11:28:36 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static size_t	ft_len(unsigned char *str)
{
	size_t	i;

	i = 0;
	if (str)
		while (str[i] != '\0')
			i++;
	return (i);
}

unsigned char	*ft_strjoin(unsigned char const *s1, unsigned char const *s2)
{
	unsigned char			*ptr;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!s2)
		return (NULL);
	ptr = malloc((sizeof(unsigned char const *) * ft_len((unsigned char *)s1))
			+ (sizeof(unsigned char const *) * ft_len((unsigned char *)s2)) + 1);
	if (ptr == NULL)
		return (NULL);
	if (s1)
	{
		while (s1[i] != '\0')
		{
			ptr[i] = (unsigned char)s1[i];
			i++;
		}
	}
	if (s2)
	{
		while (s2[j] != '\0')
		{
			ptr[i] = (unsigned char)s2[j];
			i++;
			j++;
		}
	}
	ptr[i] = '\0';
	return (ptr);
}
