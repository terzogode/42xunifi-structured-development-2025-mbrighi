/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filesystem.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 17:23:01 by mbrighi           #+#    #+#             */
/*   Updated: 2025/06/12 19:23:38 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILESYSTEM_H
# define FILESYSTEM_H

# include <string.h> 
# include <stdio.h>
# include <stdlib.h>

//typedef struct fsnode FSNode;

typedef struct FSNode
{
	const char		*name;
	int				size;
	struct FSNode	*parent;
	struct FSNode	*children;
	struct FSNode	*sibling;

}	FSNode;

FSNode	*create_file(const char *name, int size);
FSNode	*create_folder(const char *name);
void	add_child(FSNode *parent, FSNode *child);
FSNode	*get_children(const FSNode *parent);
FSNode	*get_sibling(const FSNode *node);

#endif