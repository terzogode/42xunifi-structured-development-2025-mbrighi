/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workout_scheduler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 02:34:33 by mbrighi           #+#    #+#             */
/*   Updated: 2025/06/13 02:52:27 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "workout_scheduler.h"

struct WorkoutPlan	*manage_error(struct WorkoutPlan *WorkPlan, struct UserData *UserDatas)
{
	if (WorkPlan)
		free_workout_plan(WorkPlan);
	if (UserDatas)
		free_user_data(UserDatas);
	return (NULL);
}


struct WorkoutPlan  *create_workout_schedule(char *username)
{
	struct WorkoutPlan	*WorkPlan;
	struct WorkoutPlan	*LastPlan;
	struct UserData		*UserDatas;
	int					days;
	
	days = 0;
	if (!username)
		return (NULL);
	UserDatas = get_user_data(username);
	if (!UserDatas)
	{
		manage_error(NULL, UserDatas);
		return (NULL);
	}
	WorkPlan = build_base_plan(UserDatas);
	if (!WorkPlan)
	{
		manage_error(WorkPlan, UserDatas);
		return (NULL);
	}
	LastPlan = refine_plan(WorkPlan, UserDatas);
	if (!WorkPlan)
	{
		manage_error(WorkPlan, UserDatas);
		return (NULL);
	}
	free_workout_plan(WorkPlan);
	days = determine_duration(LastPlan);
	assign_daily_exercises(LastPlan, days);
	assign_daily_tips(LastPlan, days);
	free_user_data(UserDatas);
	return (LastPlan);	
}
