/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:58:19 by mbrighi           #+#    #+#             */
/*   Updated: 2025/06/19 17:16:59 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPENSE_TRACKER_H
#define EXPENSE_TRACKER_H

#include <stdlib.h>
#include <stdio.h>

#define MAX_RECORDS 1000

// =======================
//  STRUCTURE DEFINITIONS
// =======================

typedef struct s_expense {
	char	date[11];
	float	amount;
	char	*category;
	char	*description;
} t_expense;

typedef struct s_expense_list {
	t_expense	records[MAX_RECORDS];
	int			count;
} t_expense_list;

// =======================
//  PARSING AND VALIDATION
// =======================

int				load_expenses(const char *filename, t_expense_list *list);
int				parse_line(const char *line, t_expense *expense);
void			trim_whitespace(char *str);
int				is_valid_date(const char *date);
int				is_valid_amount(const char *amount_str);
void			print_warning(const char *message, const char *line);

// =======================
//  FILTERING
// =======================

t_expense_list	filter_by_category(t_expense_list *list, const char *keyword);
t_expense_list	filter_by_date_range(t_expense_list *list, const char *start, const char *end);

// =======================
//  STATISTICS & DISPLAY
// =======================

void			print_summary(const t_expense_list *list);
float			compute_total(const t_expense_list *list);
float			compute_average(const t_expense_list *list);
void			print_category_breakdown(const t_expense_list *list);

// =======================
//  UTILS
// =======================

char			*str_to_lower(const char *str);
int				compare_dates(const char *d1, const char *d2);
void			free_expenses(t_expense_list *list);

#endif

