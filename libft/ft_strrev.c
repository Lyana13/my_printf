/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalaya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 13:41:13 by lmalaya           #+#    #+#             */
/*   Updated: 2019/07/08 13:41:15 by lmalaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
    char tmp;
    int	i;
    int j;

    i = 0;
    j = ft_strlen(str) - 1;
    while (i < j)
    {
    	tmp = str[i];
    	str[i] = str[j];
    	str[j] = tmp;
    	j--;
    	i++;
    }
    return (str);
}
