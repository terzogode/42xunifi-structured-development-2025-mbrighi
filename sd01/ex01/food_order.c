/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   food_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 19:13:24 by mbrighi           #+#    #+#             */
/*   Updated: 2025/06/12 19:51:11 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "food_order.h"

int	process_food_order(struct OrderRequest *request)
{
	struct OrderConfirmation	*ord_conf;

	if (check_restaurant_status(request) == 1)
	{
		ord_conf = create_standard_confirmation();
		if (ord_conf == NULL)
			return (0);
		send_confirmation_notification(ord_conf);
	}
	if (check_restaurant_status(request) == 0)
	{
		ord_conf = create_preorder_confirmation();
		if (ord_conf == NULL)
			return (0);
		send_confirmation_notification(ord_conf);
	}
}
