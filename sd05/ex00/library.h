/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:58:19 by mbrighi           #+#    #+#             */
/*   Updated: 2025/06/19 18:01:28 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBRARY_H
# define LIBRARY_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

# define MAX_BOOKS 1000

// Struttura per un singolo libro
typedef struct s_book
{
	int		id;
	char	*title;
	char	*author;
}	t_book;

// Struttura per la libreria
typedef struct s_library
{
	t_book	*books[MAX_BOOKS];
	int		count;
}	t_library;

// === Funzioni di caricamento catalogo ===
t_library	*load_catalog(const char *filename);
int			parse_line(const char *line, t_book **book);
void		free_library(t_library *lib);

// === Funzioni di ricerca ===
void		search_by_title(t_library *lib, const char *query);
void		search_by_author(t_library *lib, const char *query);

// === Funzioni di utilità ===
char		*trim_spaces(const char *str);
int			strcasestr_custom(const char *haystack, const char *needle);

#endif
