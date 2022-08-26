/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:13:00 by mmoumni           #+#    #+#             */
/*   Updated: 2022/08/23 13:00:17 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/structs.h"
#include "../../includes/cube3d.h"

int	render_rect(t_raycast *data, t_rect rect)
{
	int i;
	int j;
	
	if (data->data->win_ptr == NULL)
		return (1);
	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
		{
			my_mlx_put_pixel(data, j, i, rect.color);
			j++;
		}
		i++;
	}
	return (0);
}

int	render(t_raycast *data, int x, int y, int color)
{
	t_rect rectangle;

	rectangle.color = color;
	rectangle.x = x;
	rectangle.y = y;
	rectangle.width = CUB_SIZE;
	rectangle.height = CUB_SIZE;
	render_rect(data, rectangle);
	return (0);
}

int	render_player(t_raycast *data, int x, int y, int color)
{
	t_rect	rectangle;

	rectangle.color = color;
	rectangle.x = x;
	rectangle.y = y;
	rectangle.width = CUB_SIZE / 8;
	rectangle.height = CUB_SIZE / 8;
	render_rect(data, rectangle);
	return (0);
}

void	draw_minimap(t_raycast *data, char **map)
{
	int i;
	int	j;
	int	x_start;
	int y_start;

	i = 0;
	while (map[i])
	{
		j = 0;
		y_start = i * (CUB_SIZE);
		while (map[i][j])
		{
			x_start = j * (CUB_SIZE);
			if (map[i][j] == '0')
			{
				render(data, x_start, y_start, 0xFFFFFF);
			}
			else if (map[i][j] == '1')
				render(data, x_start, y_start, 0xFF0000);
			else if (map[i][j] != ' ')
			{
				map[i][j] = '0';
				render(data, x_start, y_start, 0xFFFFFF);
			}
			j++;
		}
		i++;
	}
}
