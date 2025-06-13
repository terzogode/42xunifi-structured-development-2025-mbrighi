/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playlist_creator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 03:47:45 by mbrighi           #+#    #+#             */
/*   Updated: 2025/06/13 04:43:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "playlist_creator.h"

struct Playlist *manage_error(struct Playlist *playlist, struct MoodSettings *mood, struct FilterSettings *filters, struct SongData *song) {
	if (playlist)
		free_playlist(playlist);
	if (mood)
		free_mood_settings(mood);
	if (filters)
		free_filter_settings(filters);
	if (song)
		free_song_data(song);
	return (NULL);
}

struct Playlist	*create_playlist(void)
{
	struct MoodSettings		*mood = NULL;
	struct FilterSettings	*filters = NULL;
	struct SongData			*song = NULL;
	struct Playlist			*playlist = NULL;
	int						mood_variations = 0;
	int						i = 0;

	mood = analyze_user_mood();
	if (!mood)
		return (NULL);
	filters = default_filters();
	if (filters == NULL)
		return (manage_error(NULL, mood, NULL, NULL), NULL);
	mood_variations = get_mood_variations(mood);
	if (mood_variations < 0)
		return (manage_error(NULL, mood, filters, NULL), NULL);
	while (i < mood_variations)
	{
		filters = refine_filters(filters);
		if (filters == NULL)
			return (manage_error(NULL, mood, filters, NULL), NULL);
		i++;
	}
	if (filters_require_popular_song(filters))
	{
		song = fetch_popular_song();
		if (song == NULL)
			return (manage_error(NULL, mood, filters, NULL), NULL);
	}
	else
	{
		song = fetch_niche_song();
		if (song == NULL)
			return (manage_error(NULL, mood, filters, NULL), NULL);
	}
	playlist = combine_with_mood_playlist(song, mood);
	if (playlist == NULL)
		return (manage_error(NULL, mood, filters, song), NULL);
	manage_error(NULL, mood, filters, song);
	return (playlist);
}

