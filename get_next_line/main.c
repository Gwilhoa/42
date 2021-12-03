/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 20:50:07 by gchatain          #+#    #+#             */
/*   Updated: 2021/12/03 20:50:58 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(){
	int ret = 1;
	int	fd;
	char *str = "coucou";

	fd = open("test.txt", O_RDONLY);
	str = get_next_line(fd);
	while (str != NULL){
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
	}
}
