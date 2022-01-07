#include <stdlib.h>
#include <unistd.h>

#ifndef

# define BUFFER_SIZE 32
# define OPEN_MAX 256
# define SUCCESS 1
# define END_OF_FILE 0
# define ERROR -1

#endif

size_t	ft_strlen(char	*str)
{
	size_t	len;
	
	len = 0;
	while (str)
	{
		len++;
		str++;
	}
	return (len);
}

char	*ft_strndup(const char *s1, size_t n)
{
	char	*dup_str;
	char	*ret;

	ret = (char *) malloc(sizeof(char) * (n + 1));
	if (!ret)
		return (NULL);
	dup_str = ret;
	while (n--)
		*dup_str++ = *s1++;
	*dup_str = '\0';
	return (ret);
}

char	*ft_strchr(const char *s, int c)
{
	char	*src;

	src = s;
	while (*src)
	{
		if (*src == c)
			return (src);
		src++;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
}
