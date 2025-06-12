/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grade_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:39:32 by mbrighi           #+#    #+#             */
/*   Updated: 2025/06/12 16:20:26 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grade_map.h"

void	standard_map(const int *scores, const char **mapped_grades, int size)
{
	int idx;

	idx = 0;
	while (idx < size)
	{
		if (scores[idx] <= 59)
			mapped_grades[idx] = F;
		else if (scores[idx] <= 69)
			mapped_grades[idx] = D2;
		else if (scores[idx] <= 79)
			mapped_grades[idx] = C2;
		else if (scores[idx] <= 89)
			mapped_grades[idx] = B2;
		else if (scores[idx] <= 100)
			mapped_grades[idx] = A2;
		idx++;
	}
}

void	passfail_map(const int *scores, const char **mapped_grades, int size)
{
	int idx;

	idx = 0;
	while (idx < size)
	{
		if (scores[idx] <= 59)
			mapped_grades[idx] = FAILED;
		else if (scores[idx] > 59)
			mapped_grades[idx] = PASSED;
		idx++;
	}

}

void	plusminus_map(const int *scores, const char **mapped_grades, int size)
{
	int idx;

	idx = 0;
	while (idx < size)
	{
		if (scores[idx] <= 59)
			mapped_grades[idx] = F;
		else if (scores[idx] <= 62)
			mapped_grades[idx] = D3;
		else if (scores[idx] <= 66)
			mapped_grades[idx] = D2;
		else if (scores[idx] <= 69)
			mapped_grades[idx] = D1;
		else if (scores[idx] <= 72)
			mapped_grades[idx] = C3;
		else if (scores[idx] <= 76)
			mapped_grades[idx] = C2;
		else if (scores[idx] <= 79)
			mapped_grades[idx] = C1;
		else if (scores[idx] <= 82)
			mapped_grades[idx] = B3;
		else if (scores[idx] <= 86)
			mapped_grades[idx] = B2;
		else if (scores[idx] <= 89)
			mapped_grades[idx] = B1;
		else if (scores[idx] <= 92)
			mapped_grades[idx] = A3;
		else if (scores[idx] <= 96)
			mapped_grades[idx] = A2;
		else if (scores[idx] <= 100)
			mapped_grades[idx] = A1;
		idx++;
	}
}

void	map_scores(const int *scores, int size, GradeMapper mapper, const char **mapped_grades)
{
	if (mapper == plusminus_mapper)
		plusminus_map(scores, mapped_grades, size);
	if (mapper == passfail_mapper)
		passfail_map(scores, mapped_grades, size);
	if (mapper == standard_mapper)
		standard_map(scores, mapped_grades, size);
}


#include <stdio.h>
#include "grade_map.h"

// int main(void)
// {
// 	int scores[] = {55, 61, 68, 73, 77, 81, 85, 90, 95, 100};
// 	int size = sizeof(scores) / sizeof(scores[0]);
// 	const char *mapped_grades[10];

// 	printf("Standard mapping:\n");
// 	map_scores(scores, size, standard_mapper, mapped_grades);
// 	for (int i = 0; i < size; i++)
// 		printf("Score: %d -> Grade: %s\n", scores[i], mapped_grades[i]);

// 	printf("\nPass/Fail mapping:\n");
// 	map_scores(scores, size, passfail_mapper, mapped_grades);
// 	for (int i = 0; i < size; i++)
// 		printf("Score: %d -> Grade: %s\n", scores[i], mapped_grades[i]);

// 	printf("\nPlus/Minus mapping:\n");
// 	map_scores(scores, size, plusminus_mapper, mapped_grades);
// 	for (int i = 0; i < size; i++)
// 		printf("Score: %d -> Grade: %s\n", scores[i], mapped_grades[i]);

// 	return 0;
// }