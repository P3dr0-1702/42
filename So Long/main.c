/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfreire- <pfreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 12:45:01 by pfreire-          #+#    #+#             */
/*   Updated: 2025/06/19 17:20:52 by pfreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <sys/time.h>

int main()
{
	void *mlx;
	void *test;
	void *win;
	int width = 100;
	int len = 100;
	
	mlx = mlx_init();
	if(!mlx)
		return(1);
	win = mlx_new_window(mlx, 1000, 1000, "new windoh");
	test = mlx_xpm_file_to_image(mlx, "assets/Red-Circle-Transparent.xpm", &width, &len);
	mlx_put_image_to_window(mlx,win, test, 50, 150);
	while(1)
	{
		//do nothing
	}
	free(mlx);
}
