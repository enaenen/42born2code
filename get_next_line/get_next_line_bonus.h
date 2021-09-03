/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 14:19:55 by wchae             #+#    #+#             */
/*   Updated: 2021/09/03 14:26:03 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

# define SUCCESS 1
# define END_OF_FILE 0
# define ERROR -1

char	*get_next_line(int fd);

size_t	ft_strlen(const char *str);
char	*ft_strndup(const char *s, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int c);

#endif
