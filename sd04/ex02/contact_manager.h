/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact_manager.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:58:19 by mbrighi           #+#    #+#             */
/*   Updated: 2025/06/19 17:25:46 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_MANAGER_H
#define CONTACT_MANAGER_H

// Librerie standard
#include <stdlib.h>
#include <stdbool.h>

// Struttura per un singolo contatto
typedef struct s_contact {
	int		id;
	char	*name;
	char	*phone;
	char	*email;
	char	*city;
	char	*address;
	}	t_contact;

	// Struttura che rappresenta l'elenco dei contatti
	typedef struct s_contact_list {
	t_contact	**contacts;
	int			count;
	int			max_id;
	}	t_contact_list;

// ======= FUNZIONI DI VALIDAZIONE =======
bool	is_valid_id(char *str, t_contact_list *list);
bool	is_valid_name(const char *str);
bool	is_valid_phone(const char *str);
bool	is_valid_email(const char *str);
bool	is_valid_city(const char *str);
char	*trim_whitespace(char *str);

// ======= FUNZIONI DI GESTIONE =======
bool	add_contact(t_contact_list *list, t_contact *new_contact);
bool	update_contact(t_contact_list *list, int id);
bool	delete_contact(t_contact_list *list, int id);

// ======= FUNZIONI DI CARICAMENTO E SALVATAGGIO =======
bool	load_contacts(const char *filename, t_contact_list *list);
bool	save_contacts(const char *filename, t_contact_list *list);

// ======= FUNZIONI DI RICERCA =======
void	search_by_name(t_contact_list *list, const char *query);
void	search_by_city(t_contact_list *list, const char *query);

// ======= MENU PRINCIPALE =======
void	contact_menu(t_contact_list *list, const char *filename);

// ======= UTILITY =======
t_contact *create_contact(int id, char *name, char *phone, char *email, char *city, char *address);
void	free_contact(t_contact *contact);
void	free_contact_list(t_contact_list *list);

#endif


