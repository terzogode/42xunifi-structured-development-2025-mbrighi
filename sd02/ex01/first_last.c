/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_last.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:20:57 by mbrighi           #+#    #+#             */
/*   Updated: 2025/06/12 19:19:12 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "first_last.h"

void	first_last(int arr[], int size, int target, int *first, int *last)
{
	int	index = 0;
	*first = -1;
	*last = -1;

	if (size == 0 || arr == NULL)
		return ;
	while (index < size)
	{
		if (arr[index] == target)
		{
			*first = index;
			break ;
		}
		index++;
	}
	index = size;
	while (index > 0)
	{
		if (arr[index] == target)
		{
			*last = index;
			break ;
		}
		index--;
	}
}

// int main()
// {
// 	int arr[] = {1, 2, 3, 4, 5, 6, 1};
// 	int size = 7;
// 	int target = 1;
// 	int first = -4;
// 	int last = -4;

// 	first_last(arr, size, target, &first, &last);
// 	printf("%d, %d\n", first, last);

// }
