/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music_organizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 23:38:35 by mbrighi           #+#    #+#             */
/*   Updated: 2025/06/12 23:57:39 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "music_organizer.h"

struct MusicLibrary	*organize_music_library(const char *directory_path)
{
	struct MusicLibrary	*Mus_Lib;
	const char			*scan_dir;
	struct MusicFile	*p_m_f;

	Mus_Lib = create_music_library();
	if (!Mus_Lib)
		return (NULL);
	scan_dir = *scan_directory(directory_path);
	if (!scan_dir)
	{
		free(Mus_Lib);
		return (NULL);
	}
	p_m_f = process_music_file(directory_path, scan_dir);
	if (!p_m_f)
	{
		free(Mus_Lib);
		free(scan_dir);
		return (NULL);
	}
	update_music_library(Mus_Lib, p_m_f);
	return (1);
}