/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasharif <fasharif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:52:06 by fasharif          #+#    #+#             */
/*   Updated: 2022/08/30 21:13:11 by fasharif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	l;

	l = 0;
	if (!str)
		return (0);
	while (str[l] != '\0')
		l++;
	return (l);
}

char	*ft_strchr(char *s, int c) // Function to check if there is a matching character in a string If the character exists, return a pointer to where the character exists; otherwise, a null pointer is returned.
{
	int	i;

	i = 0; // while (*s != (unsigned char)c) {
	if (!s)
		return (0); // NULL
	if (c == '\0') // s++
		return ((char *)&s[ft_strlen(s)]); // }
	while (s[i] != '\0') // return ((char *)s);
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	j;
	size_t	c;
	char	*str;

	if (!s1) //Handle when s1 is an empty string
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	j = -1;
	c = 0;
	if (s1)
		while (s1[++j] != '\0')
			str[j] = s1[j];
	while (s2[c] != '\0')
		str[j++] = s2[c++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}
