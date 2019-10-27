/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 10:21:29 by agottlie          #+#    #+#             */
/*   Updated: 2019/10/24 14:51:28 by sbearded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*buff;
	int		i;

	i = -1;
	if (s1 == NULL)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (buff == NULL)
		return (NULL);
	while (s1[++i])
		buff[i] = s1[i];
	buff[i] = '\0';
	return (buff);
}
