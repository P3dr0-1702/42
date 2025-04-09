unsigned int	ft_sizeoffile(const char *file)
{
	int				fd;
	unsigned int	j;
	char			currbyte;

	fd = open(file, O_RDONLY);
	j = 0;
	while (read(fd, &currbyte, 1) == 1)
	{
		j++;
	}
	close(fd);
	return (j);
}
