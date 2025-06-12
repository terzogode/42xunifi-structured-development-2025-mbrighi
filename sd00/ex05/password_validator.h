/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   password_validator.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:24:36 by mbrighi           #+#    #+#             */
/*   Updated: 2025/06/12 16:23:52 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_PASSWORD
#define VALIDATE_PASSWORD

# include <stdio.h>

typedef enum	PwStatusEnum
{
	VALID,
	INVALID,
} PwStatus;

PwStatus	validate_password(const char *new_pw, const char *curr_pw);
int			str_len(const char *str);

#endif