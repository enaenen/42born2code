/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 20:44:48 by wchae             #+#    #+#             */
/*   Updated: 2021/07/21 20:09:54 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFER_SIZE 32
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*get_next_line(int fd);

#endif
