/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:55:21 by sforster          #+#    #+#             */
/*   Updated: 2023/12/13 18:42:57 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 75
# endif

char	*get_next_line(int fd);
int		ft_findline(char *str);
size_t	ft_strlen(char *str);
char	*ft_strndup(char *s, size_t c);
void	*ft_bzero(void *s, int n);
void	*ft_memset(void *b, int c, int len);
char	*ft_strjoin(char *s1, char *s2);

#endif