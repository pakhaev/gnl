/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 15:08:42 by rvoltigo          #+#    #+#             */
/*   Updated: 2020/11/22 15:12:07 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

size_t		ft_gnlen(char *str, int f);
char		*ft_gnldup(char *str);
char		*ft_strjoin(char *s1, char *s2);
int			ft_returning(char *s);
int			get_next_line(int fd, char **line);
char		*ft_strdup(char *str);
void		*ft_memset(void *dest, int c, size_t n);

#endif
