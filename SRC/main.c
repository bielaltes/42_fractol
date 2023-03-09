/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:24:39 by baltes-g          #+#    #+#             */
/*   Updated: 2023/03/09 15:27:40 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INC/headers/fractol.h"

int main(int argc, char **argv)
{
    if (parse(argc, **argv))
    {

    }
    else
    {
        ft_printf("Input error\n");
    }
}