/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segmented_runs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:55:12 by mbrighi           #+#    #+#             */
/*   Updated: 2025/06/19 16:36:46 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "segmented_runs.h"

static int	count_increasing_run(const int *arr, int start, int size)
{
	int	counter = 0;
	int	index = start;

	while (index + 1 < size && arr[index] != -1 && arr[index + 1] != -1)
	{
		if (arr[index] < arr[index + 1])
			counter++;
		else
			break;
		if (counter == 3)
			return (1);
		index++;
	}
	return (0);
}

int	count_segments(const int *arr, int size)
{
	int	index = 0;
	int	ret = 0;

	if (size == 0)
		return (0);
	while (index < size)
	{
		if (arr[index] != -1)
		{
			ret += count_increasing_run(arr, index, size);
			while (index < size && arr[index] != -1)
				index++;
		}
		index++;
	}
	return (ret);
}

// int main (void)
// {
// 	int arr[] = {1, 2, 3, 0, -1, 5, 6, -1, 1, 2, 3, 4};
// 	int size = 11;
// 	int ret = 2;

// 	ret = count_segments(arr, size);
// 	printf("%d\n", ret);

// }
