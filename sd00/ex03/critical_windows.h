/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   critical_windows.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 21:31:18 by mbrighi           #+#    #+#             */
/*   Updated: 2025/06/11 13:14:47 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CRITICAL_WINDOWS
# define CRITICAL WINDOWS
#include <stdio.h>

int	count_critical_windows(const int *readings, int size);
int	find_min (int average, int crit_average, int crit_readings);


#endif