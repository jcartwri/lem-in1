/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:52:23 by agottlie          #+#    #+#             */
/*   Updated: 2019/10/27 12:26:36 by sbearded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_arr;
	int		i;
	int		j;

	j = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	new_arr = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (new_arr == NULL)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		new_arr[j++] = s1[i];
	i = -1;
	while (s2[++i] != '\0')
		new_arr[j++] = s2[i];
	return (new_arr);
}
