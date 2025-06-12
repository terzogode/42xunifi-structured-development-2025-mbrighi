/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music_organizer.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 23:38:09 by mbrighi           #+#    #+#             */
/*   Updated: 2025/06/12 23:56:26 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUSIC_ORGANIZER_H
# define MUSIC_ORGANIZER_H

# include <string.h>

struct MusicLibrary;

struct MusicLibrary	*organize_music_library(const char *directory_path);
void				update_music_library(struct MusicLibrary *library, struct MusicFile *song);
struct MusicFile	*process_music_file(const char *directory_path, const char *filename);
const char			**scan_directory(const char *directory_path);
struct MusicLibrary	*create_music_library();

#endif