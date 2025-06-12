/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   password_validator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:24:34 by mbrighi           #+#    #+#             */
/*   Updated: 2025/06/12 19:30:37 by mbrighi          ###   ########.fr       */
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

PwStatus	validate_password(const char *new_pw, const char *curr_pw)
{
	int	index = 0;
	int	upper = 0;
	int	lower = 0;
	int	digit = 0;
	int	spechar = 0;
	int	len = str_len(new_pw);

	if (len <= 8)
		return (INVALID);
	while (new_pw[index] != '\0' || curr_pw[index] != '\0')
	{
		if (new_pw[index] == curr_pw[index])
			index++;
		if (new_pw[index] != curr_pw[index])
			break ;
	}
	if (index == len)
		return (INVALID);
	index = 0;
	while (new_pw[index] != '\0')
	{
		if (new_pw[index] >= '0' && new_pw[index] <= '9')
			digit = 1;
		else if (new_pw[index] >= 'A' && new_pw[index] <= 'Z')
			upper = 1;
		else if (new_pw[index] >= 'a' && new_pw[index] <= 'z')
			lower = 1;
		else if (new_pw[index] == '@' || new_pw[index] == '#'
			|| new_pw[index] == '$' || new_pw[index] == '%'
			|| new_pw[index] == '^' || new_pw[index] == '&'
			|| new_pw[index] == '*')
			spechar = 1;
		index++;
	}
	if (digit == 1 && upper == 1 && lower == 1 && spechar == 1)
		return (VALID);
	else
		return (INVALID);
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
