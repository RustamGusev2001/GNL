/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcrius <kcrius@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:07:24 by kcrius            #+#    #+#             */
/*   Updated: 2021/10/26 15:05:57 by kcrius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != (char)c)
		i++;
	if ((char)c == s[i])
		return ((char *) s + i);
	else
		return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	int		i;

	i = 0;
	cpy = malloc(ft_strlen(s1) + 1);
	if (!(cpy))
		return (NULL);
	while (s1[i])
	{
		cpy[i] = s1[i];
		++i;
	}
	cpy[i] = '\0';
	return (cpy);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*conc;
	unsigned int	i;
	unsigned int	j;

	if (!s1 || !s2)
		return (NULL);
	j = 0;
	i = ft_strlen(s1) + ft_strlen(s2);
	conc = malloc(i);
	if (!(conc))
		return (NULL);
	i = 0;
	while (s1[i])
		conc[j++] = s1[i++];
	i = 0;
	while (s2[i])
		conc[j++] = s2[i++];
	conc[j] = '\0';
	return (conc);
}
