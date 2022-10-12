/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 03:06:08 by coder             #+#    #+#             */
/*   Updated: 2022/10/08 04:12:41 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win;
} t_mlx;

typedef struct s_player
{
	float x;
	float y;
	float width;
	float height;
} t_player;

typedef struct s_data
{
    int	    nb_rows;
	char	**map;
    int argc;
    char *file;
    char **cub;
	t_mlx mlx;
	t_player player;
    char **directions;
    char *f_color;
    char *c_color;
	int	counter;
	int	control;
	size_t	big_line;
} t_data;

#endif