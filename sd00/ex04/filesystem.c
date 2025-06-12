/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filesystem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 17:23:05 by mbrighi           #+#    #+#             */
/*   Updated: 2025/06/12 18:00:42 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filesystem.h"

FSNode *create_file(const char *name, int size)
{
	FSNode	*new_file;

	new_file = (FSNode *)malloc(sizeof(FSNode));
	if (new_file == NULL)
		return (NULL);
	new_file->name = strdup(name);
	new_file->size = size;
	new_file->children = NULL;
	new_file->parent = NULL;
	return (new_file);
}

FSNode *create_folder(const char *name)
{
	FSNode	*folder;

	folder = create_file (name, 0);
	return (folder);
}

void add_child(FSNode *parent, FSNode *child)
{
	FSNode	*tmp;

	if ((parent->size != 0) || !parent || !child)
		return ;
	if (!parent->children)
	{
		parent->children = child;
		return ;
	}
	tmp = parent->children;
	while (tmp->sibling)
		tmp = tmp->sibling;
	tmp->sibling = child;
}

FSNode *get_children(const FSNode *parent)
{
	return (parent->children);
}

FSNode *get_sibling(const FSNode *node)
{
	return (node->sibling);
}

// void print_tree(FSNode *node, int depth)
// {
//     while (node)
//     {
//         for (int i = 0; i < depth; i++)
//             printf("  ");
//         printf("- %s (size: %d)\n", node->name, node->size);
//         if (node->children)
//             print_tree(node->children, depth + 1);
//         node = node->sibling;
//     }
// }

// int main(void)
// {
//     FSNode *root = create_folder("root");
//     FSNode *docs = create_folder("docs");
//     FSNode *img = create_folder("images");
//     FSNode *file1 = create_file("file1.txt", 100);
//     FSNode *file2 = create_file("file2.txt", 200);
//     FSNode *pic = create_file("photo.jpg", 500);

//     add_child(root, docs);
//     add_child(root, img);
//     add_child(docs, file1);
//     add_child(docs, file2);
//     add_child(img, pic);

//     printf("Filesystem structure:\n");
//     print_tree(root, 0);

//     // Free memory here se vuoi aggiungere una funzione di cleanup

//     return 0;
// }

