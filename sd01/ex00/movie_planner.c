/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movie_planner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 18:26:01 by mbrighi           #+#    #+#             */
/*   Updated: 2025/06/12 19:11:34 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "movie_planner.h"

struct Plan	*create_movie_night_plan(void)
{
	struct Preferences	*user_pref;
	struct MovieList	*movie_pref;
	struct Plan			*plan_pref;

	user_pref = get_user_preferences();
	if (user_pref == NULL)
		return (NULL);
	movie_pref = find_movies(user_pref);
	if (movie_pref == NULL)
	{
		free(user_pref);
		return (NULL);
	}
	plan_pref = build_plan(movie_pref);
	if (plan_pref == NULL)
	{
		free(user_pref);
		free(movie_pref);
		return (NULL);
	}
	else
		return (plan_pref);
}
