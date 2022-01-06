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

	dup_str = (char *) malloc(sizeof(char) * (n + 1));
	if (!dup_str)
		return (NULL);
	while (n--)
		*dup_str++ = *s1++;
	*dup_str = '\0';
	return (dup_str);
}

char	*get_next_line(int fd)
{
}
