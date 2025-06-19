/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 17:42:07 by mbrighi           #+#    #+#             */
/*   Updated: 2025/06/19 18:01:27 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

char *trim_spaces(const char *str)
{
	size_t start = 0;
	size_t end = ft_strlen(str);
	char *trimmed;
	size_t len;
	size_t i;

	while (str[start] && (str[start] == ' ' || str[start] == '\t'))
		start++;
	while (end > start && (str[end - 1] == ' ' || str[end - 1] == '\t' || str[end - 1] == '\n'))
		end--;
	len = end - start;
	trimmed = malloc(len + 1);
	if (!trimmed)
		return NULL;
	i = 0;
	while (i < len)
	{
		trimmed[i] = str[start + i];
		i++;
	}
	trimmed[i] = '\0';
	return (trimmed);
}

int char_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

char *strcasestr_custom(const char *haystack, const char *needle)
{
	size_t	i = 0;
	size_t	j;
	if (!*needle)
		return (char *)haystack;
	while (haystack[i])
	{
		j = 0;
		while (needle[j] && haystack[i + j] &&
			char_tolower((unsigned char)haystack[i + j]) == char_tolower((unsigned char)needle[j]))
			j++;
		if (!needle[j])
			return (char *)(haystack + i);
		i++;
	}
	return (NULL);
}

void free_library(t_library *lib)
{
	int	i = 0;
	if (!lib)
		return;
	while (i < lib->count)
	{
		free(lib->books[i]->title);
		free(lib->books[i]->author);
		free(lib->books[i]);
		i++;
	}
	free(lib);
}

void free_parse_resources(char *copy, char *title, char *author)
{
	if (title)
		free(title);
	if (author)
		free(author);
	if (copy)
		free(copy);
}

int parse_line(const char *line, t_book **book)
{
	char *copy = NULL;
	char *token;
	char *saveptr;
	int id;
	char *title = NULL;
	char *author = NULL;
	t_book *new_book;

	if (!line)
		return (0);
	copy = ft_strdup(line);
	if (!copy)
		return (0);
	token = ft_strtok(copy, ",", &saveptr);
	if (!token)
		return (free_parse_resources(copy, title, author), 0);
	id = ft_atoi(token);
	token = ft_strtok(NULL, ",", &saveptr);
	if (!token)
		return (free_parse_resources(copy, title, author), 0);
	title = trim_spaces(token);
	if (!title)
		return (free_parse_resources(copy, title, author), 0);
	token = ft_strtok(NULL, ",", &saveptr);
	if (!token)
		return (free_parse_resources(copy, title, author), 0);
	author = trim_spaces(token);
		return (free_parse_resources(copy, title, author), 0);
	new_book = malloc(sizeof(t_book));
	if (!new_book)
		return (free_parse_resources(copy, title, author), 0);
	new_book->id = id;
	new_book->title = title;
	new_book->author = author;
	*book = new_book;
	free_parse_resources(copy, NULL, NULL);
	return (1);
}

t_library *load_catalog(const char *filename)
{
	int			fd;
	char		*line;
	t_library	*lib;
	t_book		*book;
	int			ret;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error: cannot open file %s\n", filename), NULL);

	lib = malloc(sizeof(t_library));
	if (!lib)
		return (close(fd), NULL);
	lib->count = 0;
	while ((line = get_next_line(fd)) && lib->count < MAX_BOOKS)
	{
		if (parse_line(line, &book))
			lib->books[lib->count++] = book;
		else
			ft_printf("Warning: malformed line skipped: %s", line);
		free(line);
	}
	if (line)
		free(line);
	close(fd);
	return (lib);
}

static void print_book(t_book *book)
{
	if (!book)
		return;
	ft_printf("ID: %d | Title: %s | Author: %s\n", book->id, book->title, book->author);
}

void search_by_title(t_library *lib, const char *query)
{
	int		found = 0;
	int		i = 0;
	char	*trimmed_query = trim_spaces(query);

	if (!lib || !trimmed_query || !*trimmed_query)
	{
		if (trimmed_query)
			free(trimmed_query);
		ft_printf("Invalid search query.\n");
		return;
	}
	while (i < lib->count)
	{
		if (strcasestr_custom(lib->books[i]->title, trimmed_query))
		{
			print_book(lib->books[i]);
			found = 1;
		}
		i++;
	}
	if (!found)
		ft_printf("No books found matching the title '%s'\n", trimmed_query);
	free(trimmed_query);
}

void search_by_author(t_library *lib, const char *query)
{
	int		found = 0;
	int		i = 0;
	char	*trimmed_query = trim_spaces(query);

	if (!lib || !trimmed_query || !*trimmed_query)
	{
		if (trimmed_query)
			free(trimmed_query);
		ft_printf("Invalid search query.\n");
		return;
	}
	while (i < lib->count)
	{
		if (strcasestr_custom(lib->books[i]->author, trimmed_query))
		{
			print_book(lib->books[i]);
			found = 1;
		}
		i++;
	}
	if (!found)
		ft_printf("No books found matching the author '%s'\n", trimmed_query);
	free(trimmed_query);
}

static void	handle_search_menu(t_library *lib)
{
	char	*input;

	while (1)
	{
		ft_printf("Search by:\n1) Title\n2) Author\nq) Quit\n> ");
		input = get_next_line(0);
		if (!input)
			break;
		if (input[0] == 'q' && input[1] == '\n')
		{
			free(input);
			break;
		}
		else if (input[0] == '1' && input[1] == '\n')
		{
			free(input);
			ft_printf("Enter title substring: ");
			input = get_next_line(0);
			if (!input || !*input)
			{
				ft_printf("Empty input.\n");
				free(input);
				continue;
			}
			search_by_title(lib, input);
			free(input);
		}
		else if (input[0] == '2' && input[1] == '\n')
		{
			free(input);
			ft_printf("Enter author substring: ");
			input = get_next_line(0);
			if (!input || !*input)
			{
				ft_printf("Empty input.\n");
				free(input);
				continue;
			}
			search_by_author(lib, input);
			free(input);
		}
		else
		{
			ft_printf("Invalid choice.\n");
			free(input);
		}
	}
}

int main(int argc, char **argv)
{
	t_library	*lib;

	if (argc != 2)
	{
		ft_printf("Usage: %s <catalog_file>\n", argv[0]);
		return (1);
	}
	lib = load_catalog(argv[1]);
	if (!lib)
		return (1);
	handle_search_menu(lib);
	free_library(lib);
	return (0);
}
