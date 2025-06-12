/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   food_order.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 19:13:27 by mbrighi           #+#    #+#             */
/*   Updated: 2025/06/12 19:48:30 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FOOD_ORDER_H
# define FOOD_ORDER_H

# include <string.h>

typedef struct OrderRequest;
typedef struct OrderConfirmation;

int							check_restaurant_status(struct OrderRequest *request);
struct OrderConfirmation	*create_standard_confirmation(void);
struct OrderConfirmation	*create_preorder_confirmation(void);
void						send_confirmation_notification(struct OrderConfirmation *confirmation);
int							process_food_order(struct OrderRequest *request);

#endif