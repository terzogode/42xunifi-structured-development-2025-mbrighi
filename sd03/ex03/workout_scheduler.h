/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workout_scheduler.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 02:34:37 by mbrighi           #+#    #+#             */
/*   Updated: 2025/06/13 02:39:58 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORKOUT_SCHEDULER_H
# define WORKOUT_SCHEDULER_H

# include <string.h>

struct UserData;
struct WorkoutPlan;

struct WorkoutPlan	*create_workout_schedule(char *username);
struct WorkoutPlan	*build_base_plan(struct UserData *data);
struct WorkoutPlan	*refine_plan(struct WorkoutPlan *plan, struct UserData *data);
struct WorkoutPlan	*manage_error(struct WorkoutPlan *WorkPlan, struct UserData *UserDatas);
struct UserData		*get_user_data(char *username);
int					determine_duration(struct WorkoutPlan *plan);
void				assign_daily_exercises(struct WorkoutPlan *plan, int day);
void				assign_daily_tips(struct WorkoutPlan *plan, int day);
void				free_user_data(struct UserData *data);
void				free_workout_plan(struct WorkoutPlan *plan);


#endif