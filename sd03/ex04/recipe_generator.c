/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recipe_generator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 03:46:38 by mbrighi           #+#    #+#             */
/*   Updated: 2025/06/19 16:44:04 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "recipe_generator.h"


struct Recippe *manage_errors(struct Ingredients *ingredients, struct TasteProfile *taste)
{
	if (ingredients)
		free_ingredients(ingredients);
	if (taste)
		free_taste_profile(taste);
	return (NULL);
}

struct Recipe *create_custom_recipe(void)
{
	struct Ingredients *ingredients;
	struct TasteProfile *taste;
	struct Recipe *recipe;
	int approval = 0;

	ingredients = get_current_ingredients();
	if (!ingredients)
		return (NULL);
	taste = get_user_taste_profile();
	if (!taste)
		return (free_ingredients(ingredients), NULL);
	while (!approval)
	{
		recipe = create_recipe(ingredients, taste);
		if (recipe == NULL)
			return (manage_errors(ingredients, taste), NULL);
		approval = get_user_approval(recipe);
		if (!approval)
			free_recipe(recipe);
	}
	manage_errors(ingredients, taste);
	return (recipe);
}