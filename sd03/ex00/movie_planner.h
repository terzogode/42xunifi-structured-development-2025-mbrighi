/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movie_planner.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 18:26:03 by mbrighi           #+#    #+#             */
/*   Updated: 2025/06/12 19:16:28 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVIE_PLANNER_H
# define MOVIE_PLANNER_H

# include <string.h>
# include <stdlib.h>

struct Preferences;
struct MovieList;
struct Plan;

struct Preferences	*get_user_preferences(void);
struct MovieList	*find_movies(struct Preferences *prefs);
struct Plan			*build_plan(struct MovieList *list);
struct Plan			*create_movie_night_plan(void);

#endif
