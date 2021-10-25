/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 12:55:08 by gchopin           #+#    #+#             */
/*   Updated: 2021/10/25 20:07:55 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

/*static size_t	ft_len(unsigned char *str)
{
	size_t	i;

	i = 0;
	if (str)
		while (str[i] != '\0')
			i++;
	return (i);
}*/

static int	write_buffer(unsigned char const *str, unsigned char *ptr, int i)
{
	if (str)
	{
		while (str[i] != '\0')
		{
			ptr[i] = (unsigned char)str[i];
			i++;
		}
	}
	return (i);
}

unsigned char	*ft_strjoin(unsigned char const *s1,
		unsigned char const *s2, size_t total)
{
	unsigned char			*ptr;
	unsigned int			i;
	unsigned int			j;

	i = 0;
	j = 0;
	if (!s2)
		return (NULL);
	ptr = malloc(total + 1);
	if (ptr == NULL)
		return (NULL);
	i = write_buffer(s1, ptr, i);
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
