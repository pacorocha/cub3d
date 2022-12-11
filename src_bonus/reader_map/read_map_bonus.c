/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:25:07 by jfrancis          #+#    #+#             */
/*   Updated: 2022/12/11 20:25:09 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

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
			print_error("Error. Map Invalid!!");
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
		print_error("Error! File does not exist.");
	if (!check_end_of_file(file, "cub"))
		print_error("Error. The file must end with .cub");
}
