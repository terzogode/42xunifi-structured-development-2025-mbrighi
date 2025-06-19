/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movie_watchlist.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 17:27:40 by mbrighi           #+#    #+#             */
/*   Updated: 2025/06/19 17:29:20 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVIE_WATCHLIST_H
#define MOVIE_WATCHLIST_H

typedef struct s_movie
{
    int		id;
    char	*title;
    char	*genre;
    int		watched;
    int		rating;
    char	date[11];
}	Movie;

typedef struct s_watchlist
{
	Movie	*movies;
	int		size;
	int		capacity;
	int		max_id;
}	Watchlist;

// Funzioni per gestione file
int		load_watchlist(const char *filename, Watchlist *wl);
int		save_watchlist(const char *filename, const Watchlist *wl);

// Funzioni per manipolare watchlist
int		add_movie(Watchlist *wl, const char *title, const char *genre);
int		mark_watched(Watchlist *wl, int id, int rating, const char *date);
int		update_movie(Watchlist *wl, int id, const char *new_title, const char *new_genre);
int		delete_movie(Watchlist *wl, int id);

// Funzioni di ricerca e filtro
void	list_movies(const Watchlist *wl);
void	search_movies(const Watchlist *wl, const char *keyword);
void	filter_by_watched(const Watchlist *wl, int watched_flag);

// Funzioni di statistiche
void	print_statistics(const Watchlist *wl);

// Funzioni di utilità
void	free_watchlist(Watchlist *wl);

#endif
