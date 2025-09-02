/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhualves <jhualves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 22:10:55 by jhualves          #+#    #+#             */
/*   Updated: 2025/09/02 17:09:41 by jhualves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "scene.h"

void	add_vector_to_points(t_vector *vector, t_vector *point, t_vector *result)
{
	result->x = vector->x + point->x;
	result->y = vector->y + point->y;
	result->z = vector->z + point->z;
	result->w = vector->w + point->w;
}

void	add_vector_to_vector(t_vector *vector, t_vector *point, t_vector *result)
{
	result->x = vector->x + point->x;
	result->y = vector->y + point->y;
	result->z = vector->z + point->z;
	result->w = vector->w + point->w;
}

void	subtract_vector_to_points(t_vector *vector, t_vector *point, t_vector *result)
{
	result->x = vector->x - point->x;
	result->y = vector->y - point->y;
	result->z = vector->z - point->z;
	result->w = vector->w - point->w;
}

void	subtract_vector_of_vector(t_vector *vector, t_vector *point, t_vector *result)
{
	result->x = vector->x - point->x;
	result->y = vector->y - point->y;
	result->z = vector->z - point->z;
	result->w = vector->w - point->w;
}

void	subtract_point_of_point(t_vector *vector, t_vector *point, t_vector *result)
{
	result->x = vector->x - point->x;
	result->y = vector->y - point->y;
	result->z = vector->z - point->z;
	result->w = vector->w - point->w;
}

void	subtract_vector_of_point(t_vector *vector, t_vector *point, t_vector *result)
{
	result->x = vector->x - point->x;
	result->y = vector->y - point->y;
	result->z = vector->z - point->z;
	result->w = vector->w - point->w;
}

float	get_magnitude(t_vector *vector)
{
	float	result;
	float	x;
	float	y;
	float	z;

	x = vector->x;
	y = vector->y;
	z = vector->z;
	result = sqrt((x * x) + (y * y) + (z * z));
	return (result);
}

t_vector	*normalization(t_vector *u_vector)
{
	float	magnitute;
	t_vector	*vector;
	
	vector = malloc(sizeof(t_vector));
	if (!vector)
		return (NULL);
	magnitute = get_magnitude(u_vector);
	if(magnitute = 0.0f)
	{
		vector->x = 0.0f;
		vector->y = 0.0f;
		vector->z = 0.0f;
	}
	else
	{
		vector->x = vector->x/magnitute;
		vector->y = vector->y/magnitute;
		vector->z = vector->z/magnitute;
	}
	vector->w = 0;
	return (vector);
}

t_vector	*negative_vector(t_vector *vector)
{
	t_vector	*result;
	
	result = malloc(sizeof(t_vector));
	if (!result)
		return (NULL);
	result->x = - vector->x;
	result->y = - vector->y;
	result->z = - vector->z;
	result->w = 0;
	return (result);
}
