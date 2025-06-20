/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   average.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:55:28 by mbrighi           #+#    #+#             */
/*   Updated: 2025/06/12 19:17:39 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "average.h"
//#include <stdio.h>

float	average(const int *arr, int size)
{
	int		n;
	int		index;
	float	ret;

	n = 0;
	index = 0;
	ret = 0;
	if (size == 0)
		return (0);
	while (n < size)
	{
		ret += arr[index];
		index++;
		n++;
	}
	if (ret == 0)
		return (0);
	ret = ret / size;
	return (ret);
}

// int main(void)
// {
// 	int arr[] = {1, 2, 3, 4};
// 	int size = 0;
// 	float ret;
// 	ret = average(arr, size);
// 	printf("%f\n", ret);
// 	return (0);
// }
