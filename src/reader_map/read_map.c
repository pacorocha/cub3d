/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 02:37:15 by coder             #+#    #+#             */
/*   Updated: 2022/12/09 22:09:10 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	read_map(t_data *data)
{
	int	content;
	int	gnl;
	int	i;

	data->cub = lines(data->file, data);
	content = open(data->file, O_RDONLY);
	gnl = 1;
	i = 0;
	while (gnl)
		gnl = get_next_line(content, &data->cub[i++]);
	data->cub[i] = NULL;
	close(content);
}

char	**lines(char *file, t_data *data)
{
	int		fd;
	int		read_line;
	char	c;

	c = '@';
	fd = open(file, O_RDONLY);
	check_fd_map(fd, file);
	data->nb_rows = 1;
	read_line = 1;
	while (read_line)
	{
		read_line = read(fd, &c, 1);
		if (read_line < 0 || c == '@')
			print_error("Error. Map Invalid");
		if (c == '\n')
			data->nb_rows++;
	}
	close(fd);
	data->cub = (char **)ft_calloc(data->nb_rows + 1, sizeof(char *));
	return (data->cub);
}

void	check_fd_map(int fd, char *file)
{
	if (!fd || fd < 0)
	{
		close(fd);
		print_error("Error!");
	}
	if (!check_end_of_file(file, "cub"))
	{
		close(fd);
		print_error("Error. The file must end with .cub");
	}
}
