/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grade_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:38:10 by mbrighi           #+#    #+#             */
/*   Updated: 2025/06/12 19:33:07 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRADE_MAP_H
# define GRADE_MAP_H

# include <stdio.h>

# define PASSED "P"
# define FAILED "F"

# define A1 "A+"
# define A2 "A"
# define A3 "A-"
# define B1 "B+"
# define B2 "B"
# define B3 "B-"
# define C1 "C+"
# define C2 "C"
# define C3 "C-"
# define D1 "D+"
# define D2 "D"
# define D3 "D-"
# define F "F"

typedef enum gmapper
{
	plusminus_mapper,
	passfail_mapper,
	standard_mapper,
}	GradeMapper;

void	map_scores(const int *scores, int size, GradeMapper mapper, const char **mapped_grades);
void	standard_map(const int *scores, const char **mapped_grades, int size);
void	passfail_map(const int *scores, const char **mapped_grades, int size);
void	plusminus_map(const int *scores, const char **mapped_grades, int size);

#endif
