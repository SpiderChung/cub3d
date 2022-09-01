/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:59:25 by scornhol          #+#    #+#             */
/*   Updated: 2021/10/16 14:58:58 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Function name: ft_strmapi
 * Description: Applies the function ’f’ to each character of the string ’s’,
 * and passing its index as first argument to create a new string (with
 * malloc(3)) resulting from successive applications of ’f’.
 * Parameters: #1. The string on which to iterate. #2. The function to apply
 * to each character.
 * Return value: The string created from the successive applications of ’f’.
 * Returns NULL if the allocation fails.									  */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	size_t			len;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (NULL == str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
