/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_libft.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 12:46:39 by bjimenez          #+#    #+#             */
/*   Updated: 2022/07/05 13:03:10 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpipex.h"

static int	ft_s_str(const char *p, char c, int pos)
{
	int	np;
	int	i;
	int	s_sstr;
	int	sel;

	np = 0;
	i = 0;
	s_sstr = 0;
	sel = 1;
	while (p[i] != '\0' && np <= pos)
	{
		if (p[i] != c && np == pos)
		{			
			s_sstr++;
			sel = 0;
		}
		else if (p[i] == c && p[i + 1] != c && sel == 0)
			np++;
		else if (sel == 1 && p[i] != c && p[i + 1] == c)
			sel = 0;
		i++;
	}
	return (s_sstr);
}

static int	ft_n_str(char *p, char c)
{
	int	ns;
	int	i;
	int	c_sstr;

	ns = 0;
	i = 0;
	c_sstr = 1;
	while (p[i] != '\0')
	{
		if (p[i] != c && c_sstr == 1)
		{			
			ns++;
			c_sstr = 0;
		}
		else if (p[i] == c)
			c_sstr = 1;
		i++;
	}
	return (ns);
}

static void	ft_get_strs(int nstrs, const char *src, char x, char **str)
{
	int				j;
	int				i;
	int				k;

	k = 0;
	j = 0;
	while (j < nstrs && src[k] != '\0')
	{
		str[j] = (char *)malloc(sizeof(char) * (ft_s_str(src, x, j) + 1));
		i = 0;
		while (src[k] == x)
			k++;
		while (src[k] != x && src[k] != '\0')
		{
			str[j][i++] = src[k];
			k++;
		}
		str[j][i] = '\0';
		j++;
		k++;
	}
	str[j] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;
	int		k;

	j = 0;
	i = 0;
	k = 0;
	if (!s)
		return (0);
	str = (char **)malloc(sizeof(char *) * (ft_n_str((char *)s, c) + 1));
	if (str == NULL)
		return (NULL);
	ft_get_strs(ft_n_str((char *)s, c), s, c, str);
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned long	ss1;
	unsigned long	ss2;
	char			*new_s;
	unsigned long	count;

	count = 0;
	if (!s1 || !s2)
		return (NULL);
	ss1 = ft_strlen(s1);
	ss2 = ft_strlen(s2);
	new_s = malloc((sizeof(char) * (ss1 + ss2 + 1)));
	if (new_s == NULL)
		return (NULL);
	while (count < ss1 + ss2)
	{
		if (count < ss1)
			new_s[count] = s1[count];
		else if (count >= ss1)
			new_s[count] = s2[count - ss1];
		count++;
	}
	new_s[count] = '\0';
	return (new_s);
}
