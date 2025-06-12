/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   critical_windows.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 21:31:16 by mbrighi           #+#    #+#             */
/*   Updated: 2025/06/12 19:28:50 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "critical_windows.h"

int	count_critical_windows(const int *readings, int size)
{
	int	idx = 0;
	int	ret = 0;
	int	avg = 0;
	int	crit_read_tmp = 0;
	int	max_read = 0;
	int	index_tmp = 0;
	int	val;

	if (!readings || size < 5)
		return (0);
	while (idx <= size - 5)
	{
		avg = 0;
		crit_read_tmp = 0;
		max_read = 0;
		index_tmp = 0;
		while (index_tmp < 5)
		{
			val = readings[idx + index_tmp];
			if (val > 150)
				break ;
			if (val >= 70)
				crit_read_tmp++;
			if (val > max_read)
				max_read = val;
			avg += val;
			index_tmp++;
		}
		if (index_tmp == 5)
		{
			avg = avg / 5;
			if (crit_read_tmp >= 3 && avg >= 90)
				ret++;
		}
		idx++;
	}
	return (ret);
}

// int main()
// {
// 	int readings[] = {60, 75, 80, 90, 100, 95, 92, 93, 94, 91, 100, 71, 70, 72, 69, 150, 140, 130, 120, 110, 151, 70, 80, 90, 100, 70, 70, 70, 70, 70};
// 	int size = sizeof(readings) / sizeof(readings[0]);
// 	int result = count_critical_windows(readings, size);
// 	printf("%d\n", result);
// 	return (0);
// }
// int	find_min (int average, int crit_average, int crit_readings)
// {
// 	int ret = 0;
// 	if (average <= crit_average && average <= crit_readings)
// 		ret = average;
// 	if (crit_average <= average && crit_average <= crit_readings)
// 		ret = crit_average;
// 	if (crit_readings <= average && crit_readings <= crit_average)
// 		ret = crit_readings;
// 	return (ret);
// }
// int	count_critical_windows(const int *readings, int size)
// {
// 	int	avg = 0;
// 	int	idx = 0;
// 	int	crit_avg = 0;
// 	int	crit_read = 0;
// 	int	ret = 0;
// 	int	crit_read_tmp = 0;
// 	int	index_tmp = 0;
// 	if (size > 150 && !readings)
// 		return (0);
// 	while (idx < size)
// 	{
// 		index_tmp = 0;
// 		avg = 0;
// 		while (index_tmp < 5 && ((index_tmp + idx) < size))
// 		{
// 			idx = idx + index_tmp;
// 			if (readings[idx] >= 70)
// 				crit_read_tmp++;
// 			avg = avg + readings[idx];
// 			index_tmp++;
// 		}
// 		if (crit_read_tmp > 2)
// 			crit_read++;
// 		avg = avg / 5;
// 		if (avg >= 90)
// 			crit_avg++;
// 		idx++;
// 	}
// 	if (avg != 0 && crit_avg != 0 && crit_read != 0)
// 	{
// 		ret = find_min(avg, crit_avg, crit_read);
// 		return (ret);
// 	}
// 	return (0);
// }