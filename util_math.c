/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_math.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:43:11 by gichlee           #+#    #+#             */
/*   Updated: 2023/05/05 16:43:30 by gichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

double	complex_abs(t_complex z)
{
	return (sqrt(z.real * z.real + z.imag * z.imag));
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.real = z.real * z.real - z.imag * z.imag;
	result.imag = 2 * z.real * z.imag;
	return (result);
}
