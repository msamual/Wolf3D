/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 21:45:28 by msamual           #+#    #+#             */
/*   Updated: 2021/01/13 21:46:13 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	add_vector(t_vec *v1, t_vec *v2, double q)
{
	v1->x += v2->x / q;
	v1->y += v2->y / q;
}

double	mul_scl(t_vec v1, t_vec v2)
{
	return (v1.x * v2.x + v1.y * v2.y);
}

void	sub_vector(t_vec *v1, t_vec *v2, double q)
{
	v1->x -= v2->x / q;
	v1->y -= v2->y / q;
}

void	add_three(t_vec *dest, t_vec *v1, t_vec *v2, double q)
{
	dest->x = (v1->x + v2->x) / q;
	dest->y = (v1->y + v2->y) / q;
}

void	sub_three(t_vec *dest, t_vec *v1, t_vec *v2, double q)
{
	dest->x = (v1->x - v2->x) / q;
	dest->y = (v1->y - v2->y) / q;
}
