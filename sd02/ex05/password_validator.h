/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   password_validator.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:24:36 by mbrighi           #+#    #+#             */
/*   Updated: 2025/06/12 19:32:49 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PASSWORD_VALIDATOR_H
# define PASSWORD_VALIDATOR_H

# include <stdio.h>

typedef enum PwStatusEnum
{
	VALID,
	INVALID,
}	PwStatus;

PwStatus	validate_password(const char *new_pw, const char *curr_pw);
int			str_len(const char *str);

#endif