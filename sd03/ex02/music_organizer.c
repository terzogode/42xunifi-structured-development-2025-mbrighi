/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music_organizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 23:38:35 by mbrighi           #+#    #+#             */
/*   Updated: 2025/06/19 16:41:29 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "music_organizer.h"

static void	free_scan_dir(const char **scan_dir)
{
	int i;

	i = 0;
	if (!scan_dir)
		return ;
	while (scan_dir[i] != NULL)
	{
		free((void *)scan_dir[i]);
		i++;
	}
	free((void *)scan_dir);
}

struct MusicLibrary	*organize_music_library(const char *directory_path)
{
	struct MusicLibrary	*Mus_Lib;
	const char			**scan_dir;
	struct MusicFile	*p_m_f;
	int					i;

	i = 0;
	Mus_Lib = create_music_library();
	if (!Mus_Lib)
		return (NULL);
	scan_dir = scan_directory(directory_path);
	if (!scan_dir)
	{
		free(Mus_Lib);
		return (NULL);
	}
	while (scan_dir[i] != NULL)
	{
		p_m_f = process_music_file(directory_path, scan_dir[i]);
		if (!p_m_f)
		{
			free(Mus_Lib);
			free_scan_dir(scan_dir);
			return (NULL);
		}
		i++;
	}
	update_music_library(Mus_Lib, p_m_f);
	return (Mus_Lib);
}