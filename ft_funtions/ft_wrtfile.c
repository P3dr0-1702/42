void	ft_wrtfile(const char *file)
{
	char	str[ft_sizeoffile(file)];
	int		fd;

	fd = open(file, O_RDONLY);
	if (read(fd, str, (ft_sizeoffile(file))) > 0)
		write(1, str, ft_sizeoffile(file));
	close(fd);
}
