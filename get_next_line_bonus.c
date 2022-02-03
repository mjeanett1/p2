#include "get_next_line_bonus.h"

int	ft_first_check(char **str, int fd)
{
	if (fd < 0 || BUFFER_SIZE <= 0 || (read(fd, 0, 0) < 0))
		return (0);
	if (!*str)
	{
		*str = (char *)malloc(sizeof(char) * 1);
		if (!*str)
			return (0);
		*str[0] = '\0';
	}
	return (1);
}

char	*get_next_line(int fd)
{
	size_t		count_bytes;
	char		*line;
	static char	*rmline = NULL;
	char		*temp;

	line = NULL;
	count_bytes = 1;
	if (ft_first_check(&rmline, fd) == 0)
		return (NULL);
	while (!ft_strchr(rmline, '\n') && (count_bytes > 0))
		ft_loop(&rmline, fd, &count_bytes);
	if (count_bytes == 0)
	{
		line = ft_strdup(rmline);
		return (ft_free_rm(&rmline, line));
	}
	else if (count_bytes > 0)
	{
		line = ft_substr(rmline, 0, (ft_strchr(rmline, '\n') - rmline + 1));
		temp = ft_strdup(rmline + ft_strlen(line));
		free(rmline);
		rmline = temp;
		return (line);
	}
	return (ft_free_rm(&rmline, NULL));
}

void	ft_loop(char **rmline, int fd, size_t *count_bytes)
{
	char	buf[BUFFER_SIZE + 1];
	char	*temp;

	temp = NULL;
	*count_bytes = read(fd, buf, BUFFER_SIZE);
	buf[*count_bytes] = '\0';
	temp = ft_strjoin(*rmline, buf);
	free(*rmline);
	*rmline = temp;
}

char	*ft_free_rm(char **rmline, char *ret)
{
	free(*rmline);
	return (ret);
}
