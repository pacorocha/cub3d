/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 06:28:51 by coder             #+#    #+#             */
/*   Updated: 2022/10/19 04:31:59 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define TRUE 1
# define FALSE 0

# define PI 3.14159265
# define TWO_PI 6.28318530

# define WINDOW_WIDTH 1024
# define WINDOW_HEIGHT 768

# define CHAR_PLAYER "NSWE"
# define PLAYER_SIZE 1
# define FOV_ANGLE 1.0472 // rounded (60 * PI / 180)
# define NUM_RAYS WINDOW_WIDTH
# define FLT_MAX 3.40282346638528859812e+38F

#define RED 0xB00612
#define GREEN 0x26871C
#define OFFBLACK 0x191919
#define BLACK 0x000000
#define WHITE 0xFFFFFF
#define BLUE 0x06304A

# define TILE_SIZE 16

# define KEY_ESC (0xff1b)
# define KEY_Q (0x71)

# define KEY_A (0x61)
# define KEY_S (0x73)
# define KEY_D (0x64)
# define KEY_W (0x77)

# define KEY_UP (0xff52)
# define KEY_DOWN (0xff54)
# define KEY_LEFT (0xff51)
# define KEY_RIGHT (0xff53)

#endif