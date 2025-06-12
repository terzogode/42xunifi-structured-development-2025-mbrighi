/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segmented_runs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:55:12 by mbrighi           #+#    #+#             */
/*   Updated: 2025/06/11 18:01:54 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "segmented_runs.h"

int count_segments(const int *arr, int size)
{
	int		index = 0;
	int		index_cmp;
	int		counter = 0;
	bool	check;
	int		ret = 0;


	if (size == 0)
		return (0);
	while (index < size)
	{
		counter = 0;
		check = arr[index] == -1;
		while (!check && index < size)
		{
			check = arr[index] == -1;
			if (check)
				break ;
			index_cmp = index + 1;
			if (arr[index] < arr[index_cmp])
					counter++;
			if (counter == 3)
				ret++;
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
