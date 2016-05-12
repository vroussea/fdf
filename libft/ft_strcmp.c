/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 19:33:34 by vroussea          #+#    #+#             */
/*   Updated: 2015/12/15 22:45:41 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	tmp1 = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;
	while (*tmp1 != '\0' && *tmp2 != '\0')
	{
		if (*tmp1 != *tmp2)
			return ((*tmp1 - *tmp2));
		tmp1++;
		tmp2++;
	}
	if (*tmp1 != *tmp2)
		return ((*tmp1 - *tmp2));
	return (0);
}
