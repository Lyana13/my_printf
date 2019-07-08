/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalaya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:19:45 by lmalaya           #+#    #+#             */
/*   Updated: 2019/07/08 22:19:46 by lmalaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	k = 0;
	if (s == NULL)
		return (NULL);
	j = ft_strlen((char*)s) - 1;
	i = 0;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i] != '\0')
		i++;
	while ((s[j] == ' ' || s[j] == '\t' || s[j] == '\n') && j != 0)
		j--;
	str = (char*)malloc(sizeof(char) * (j < i ? 1 : j - i + 2));
	if (str == NULL)
		return (NULL);
	while (i <= j)
		str[k++] = s[i++];
	str[k] = '\0';
	return (str);
}
