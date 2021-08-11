/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 21:46:53 by msamual           #+#    #+#             */
/*   Updated: 2021/01/13 21:46:57 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	turn_vector(t_vec *vec, double angle)
{
	vec->x = vec->x * cos(angle) - sin(angle) * vec->y;
	vec->y = vec->x * sin(angle) + cos(angle) * vec->y;
}
