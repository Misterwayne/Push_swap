/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 14:50:10 by mwane             #+#    #+#             */
/*   Updated: 2020/09/11 16:34:07 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minishell.h"
#include "headers/libft.h"
#include <stdio.h>
/*

"<" function takes for first args a commande and second a file
in
|cmd| argv       | inputs ......
|cat| < Makefile < checkpoint.txt < direction.c < lol |
"cat" is the commande and "lol" is the file,  the rest is ignored.
if inputs is provided, ignor argv
|CMD|ARGV|INPUTS.....
*/


int main(int argc, char **argv)
{
   	int         fd[2];
    char	    *buf;
	int         status;
    char *args[] = { "/bin/cat", 0};
    char        **test;
    int fd_file;

    if (argv[2] == NULL)
    {
        fd_file = open (argv[1], O_RDONLY);
        printf("k");
        close(0);
    }
    else
    {
        test = (argv+2);
        printf("k");
    }
    if (fork() == 0)
    {
        // dup2(fd_file, 0);
    	execv(args[0], test); // child: call execv with the path and the args
        exit(0);
	}
    else
        wait(&status);
    return(0);
}