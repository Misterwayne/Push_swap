/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_option.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 15:39:27 by mwane             #+#    #+#             */
/*   Updated: 2020/02/01 19:07:37 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void    fill_file_header(Bfh *bfh, t_param *params)
{
    write(1,"pop\n",4);
    ft_memcpy(&bfh->bitmap_type, "BM", 2);
    write(1,"pop\n",4);
    bfh->file_size = params->bmp->file_size;
    bfh->reserved1 = 0;
    bfh->reserved2 = 0;
    bfh->offset_bits = 0;
};

void    fill_image_header(Bih *bih, t_param* params, int images_size)
{
    int file_size;
    int ppm;
    
    file_size = 54 + 4 * images_size;
    ppm = params->bmp->dpi * 39.375;
    bih->size_header     = sizeof(bih);
    bih->width           = params->bmp->width;
    bih->height          = params->bmp->height;
    bih->planes          = 1;
    bih->bit_count       = 24;
    bih->compression     = 0;
    bih->images_size     = file_size;
    bih->ppm_x           = ppm;
    bih->ppm_y           = ppm;
    bih->clr_used        = 0;
    bih->clr_important   = 0;
}


void    save_bitmap(t_param *params, char *map_img)
{
    int fd;
    int images_size;
    Bfh bfh;
    Bih bih;
    Bitmap BMP;
    float red;
    float blue;
    float green;
    int i;
    unsigned char color[3];
    
    params->bmp = &BMP;
    write(1,"pop\n",4);
    params->bmp->dpi = 96;
    params->bmp->width = params->x;
    params->bmp->height = params->y;
    write(1,"pop\n",4);
    i = 0;
    images_size = params->bmp->width * params->bmp->height;
    fill_file_header(&bfh, params);
    write(1,"pop\n",4);
    fill_image_header(&bih, params, images_size);
    if (!(fd = open("../cub3d.BMP", O_RDWR, O_CREAT)))
    {
        printf("error");
        destroy_window(params);
    }
    write(1,"pop\n",4);
    ft_putstr_fd(&bfh, fd);
    ft_putstr_fd(&bih, fd);
    write(1,"pop\n",4);
    while (i < images_size)
    {
        write(1,"pap\n",4);
        Rgb BGR;
        
        BGR.rgb[0] = map_img[i];

        red  = (BGR.rgb[0]);
        green = (BGR.rgb[1]);
        blue = (BGR.rgb[2]);
        color[0] = blue;
        color[1] = green;
        color[2] = red;
        ft_putstr_fd(color, fd);
        i++;
    }
    close(fd);
}
