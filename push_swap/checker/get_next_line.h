/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 11:15:47 by mwane             #+#    #+#             */
/*   Updated: 2019/12/04 12:09:21 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GET_NEXT_LINE_H
# define _GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

int			get_next_line(int fd, char **line);
int			scan_save(char *save);
int			scan_buffer(char *buff);
char		*setup_save(char *save);
char		*giveline(char *str);
char		*reallocbuff(char *buffer, char *str);

#endif
