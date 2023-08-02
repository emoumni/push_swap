#include "push_swap_bonus.h"

static char *ft_malloc_size(char **line, char *buf)
{
	char *ret;
	int line_len;
	int buf_len;

	line_len = 0;
	while (*line && (*line)[line_len] && (*line)[line_len] != '\n')
		line_len++;
	buf_len = 0;
	while (buf[buf_len] && buf[buf_len] != '\n')
		buf_len++;
	ret = (char *)malloc(sizeof(char) * (buf_len + line_len + 1));
	if (!ret)
	{
		free(*line); // Free previously allocated *line memory before returning NULL
		return (NULL);
	}
	return (ret);
}


static int	ft_add_to_line(char **line, char *buf)
{
	char	*tmp;
	int		i;
	int		j;

	tmp = ft_malloc_size(line, buf);
	if (!tmp)
		return (-1);
	i = 0;
	j = 0;
	while (*line && (*line)[i] && (*line)[i] != '\n')
		tmp[i++] = (*line)[j++];
	j = 0;
	while (buf[j] && buf[j] != '\n')
		tmp[i++] = buf[j++];
	tmp[i] = buf[j];
	free(*line);
	*line = tmp;
	i = 0;
	while (buf[j])
		buf[i++] = buf[++j];
	buf[i] = '\0';
	i = 0;
	while ((*line)[i] && (*line)[i] != '\n')
		i++;
	return (i);
}

static int read_into_buffer(int fd, char *buf)
{
    int ret = read(fd, buf, BUFFER_SIZE);
    if (ret < 0)
    {
        return -1;
    }
    return ret;
}

static int process_buffer(char **line, char *buf, int ret)
{
    int i = 0;
    while (i < ret)
    {
        if (buf[i] == '\n')
        {
            buf[i] = '\0';
            *line = ft_strjoin(*line, buf);
            return 1;
        }
        i++;
    }
    *line = ft_strjoin(*line, buf);
    if(ret == BUFFER_SIZE)
		return(0);
	else
		return (-1);
}

static void cleanup_line(char **line)
{
    free(*line);
    *line = NULL;
}

static int ft_get_next_line(int fd, char **line)
{
    static char buf[FD_MAX][BUFFER_SIZE + 1];
    int ret;

    *line = NULL;
    ret = ft_add_to_line(line, buf[fd]);
    while (ret != -1 && (*line)[ret] != '\n')
    {
        ret = read_into_buffer(fd, buf[fd]);
        if (ret < 1)
        {
            if (ret < 0)
            {
                cleanup_line(line);
            }
            return ret;
        }
        buf[fd][ret] = '\0';
        ret = ft_add_to_line(line, buf[fd]);
    }

    if (ret == -1)
    {
        cleanup_line(line);
    }
    else
    {
        (*line)[ret] = '\0';
    }

    return 1;
}

int get_next_line(int fd, char **line)
{
	if (fd < 0 || fd > FD_MAX || !line || BUFFER_SIZE < 1)
		return (-1);
	
	int result = ft_get_next_line(fd, line);

	if (result == 0 || result == -1)
	{
		free(*line); // Clean up dynamically allocated memory
		*line = NULL;
	}
	
	return result;
}
