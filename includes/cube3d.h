/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:03:44 by houazzan          #+#    #+#             */
/*   Updated: 2022/07/30 18:33:20 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
# endif

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "structs.h"
# include <stdio.h>


//^ MACROS 
# define ARG "Wrong number of arguments"
# define MAP "Invalid map"
# define RGB "Invalid color value"
# define NORTH "NO"
# define EAST  "EA"
# define WEST  "SO"
# define SOUTH "WE"
# define FLOOR "F"
# define CEILING "C"

//^ CUBE3D_UTILES
int         ft_atoi(const char *str);
char	    *get_next_line(int fd);
int	        ft_strlen(const char *str);
char	    *ft_strdup(char *str);
char	    *ft_strchr(char *s, int c);
char	    *ft_strjoin(char *s1, char *s2);
void	    ft_error(char *str);
void	    ft_putstr(char *str);
char	    **ft_split(char const *s, char c);
int	        ft_lstsize(t_map *lst);
int	        ft_strncmp(const char *s1, const char *s2, size_t n);
t_map       *ft_lstlast(t_map *lst);
t_map	    *ft_lstnew(void *content);
size_t	    ft_strlcpy(char *dst, const char *src, size_t dstsize);

//^ PARCING_UTILES
int         is_identifire(char *str, t_map *map);
void	    free_table(char **table);


#endif