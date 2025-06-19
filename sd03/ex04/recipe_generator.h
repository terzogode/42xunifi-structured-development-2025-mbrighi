/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recipe_generator.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 03:46:53 by mbrighi           #+#    #+#             */
/*   Updated: 2025/06/13 03:46:53 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECIPE_GENERATOR_H
# define RECIPE_GENERATOR_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Ingredients;
struct TasteProfile;
struct Recipe;

struct Ingredients *get_current_ingredients(void);
struct TasteProfile *get_user_taste_profile(void);
struct Recipe *create_recipe(struct Ingredients *ingredients, struct TasteProfile *taste);
struct Recipe *create_custom_recipe(void);
int get_user_approval(struct Recipe *recipe);

void free_ingredients(struct Ingredients *ing);
void free_taste_profile(struct TasteProfile *tp);
void free_recipe(struct Recipe *recipe);

#endif