/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 20:50:07 by gchatain          #+#    #+#             */
/*   Updated: 2021/12/04 16:10:10 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(){
	int ret = 1;
	int lim = 10;
	int	fd;
	char *str = "coucou";

	fd = open("test", O_RDONLY);
	str = get_next_line(fd);
	while (str != NULL){
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
	}
}
