/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   password_validator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:24:34 by mbrighi           #+#    #+#             */
/*   Updated: 2025/06/19 16:38:28 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "password_validator.h"

int	str_len(const char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

static int	has_min_length(const char *pw)
{
	return (str_len(pw) > 8);
}

static int	is_different(const char *new_pw, const char *curr_pw)
{
	int i = 0;
	while (new_pw[i] != '\0' || curr_pw[i] != '\0')
	{
		if (new_pw[i] != curr_pw[i])
			return (1);
		i++;
	}
	return (0);
}

static int	has_digit(const char *pw)
{
	int	i = 0;
	while (pw[i])
	{
		if (pw[i] >= '0' && pw[i] <= '9')
			return (1);
		i++;
	}
	return (0);
}

static int	has_upper(const char *pw)
{
	int	i = 0;
	while (pw[i])
	{
		if (pw[i] >= 'A' && pw[i] <= 'Z')
			return (1);
		i++;
	}
	return (0);
}

static int	has_lower(const char *pw)
{
	int	i = 0;
	while (pw[i])
	{
		if (pw[i] >= 'a' && pw[i] <= 'z')
			return (1);
		i++;
	}
	return (0);
}

static int	has_special(const char *pw)
{
	int	i = 0;
	while (pw[i])
	{
		if (pw[i] == '@' || pw[i] == '#' || pw[i] == '$' || pw[i] == '%'
			|| pw[i] == '^' || pw[i] == '&' || pw[i] == '*')
			return (1);
		i++;
	}
	return (0);
}

PwStatus	validate_password(const char *new_pw, const char *curr_pw)
{
	if (!has_min_length(new_pw))
		return (INVALID);
	if (!is_different(new_pw, curr_pw))
		return (INVALID);
	if (!has_digit(new_pw))
		return (INVALID);
	if (!has_upper(new_pw))
		return (INVALID);
	if (!has_lower(new_pw))
		return (INVALID);
	if (!has_special(new_pw))
		return (INVALID);
	return (VALID);
}

// int	main(void)
// {
// 	const char *curr_pw = "OldPass@123";
// 	const char *tests[] = {
// 		"OldPass@123",     // uguale a quella vecchia
// 		"short1A@",        // troppo corta
// 		"newpassword",     // manca tutto il resto
// 		"NewPassword1",    // manca special char
// 		"Newpassword@",    // manca cifra
// 		"NEWPASS1@",       // manca minuscola
// 		"newpass1@",       // manca maiuscola
// 		"Valid1@pw",       // valida
// 		NULL
// 	};

// 	for (int i = 0; tests[i] != NULL; i++) {
// 		PwStatus res = validate_password(tests[i], curr_pw);
// 		printf("Test %d: \"%s\" -> %s\n", i+1, tests[i], res == VALID ? "VALID" : "INVALID");
// 	}
// 	return 0;
// }
