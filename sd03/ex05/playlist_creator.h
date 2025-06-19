/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playlist_creator.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 03:47:50 by mbrighi           #+#    #+#             */
/*   Updated: 2025/06/13 04:19:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYLIST_CREATOR_H
# define PLAYLIST_CREATOR_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

struct FilterSettings;
struct MoodSettings;
struct SongData;
struct Playlist;

struct FilterSettings	*default_filters(void);
struct FilterSettings	*refine_filters(struct FilterSettings *current);
struct MoodSettings		*analyze_user_mood(void);
struct SongData			*fetch_popular_song(void);
struct Playlist			*combine_with_mood_playlist(struct SongData *song, struct MoodSettings *mood);
struct Playlist			*create_playlist(void);
struct SongData			*fetch_niche_song(void);
int						get_mood_variations(struct MoodSettings *mood);
int						filters_require_popular_song(struct FilterSettings *filters);

void					free_mood_settings(struct MoodSettings *mood);
void					free_filter_settings(struct FilterSettings *filters);
void					free_song_data(struct SongData *song);
void					free_playlist(struct Playlist *playlist);

#endif