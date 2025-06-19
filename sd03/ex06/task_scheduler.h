/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task_scheduler.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 03:48:30 by mbrighi           #+#    #+#             */
/*   Updated: 2025/06/13 05:01:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TASK_SCHEDULER_H
# define TASK_SCHEDULER_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>


struct ScheduleResult;
struct TaskProfile;
struct PriorityMap;
struct TaskList;
struct LoadInfo;

struct ScheduleResult	*schedule_tasks(struct TaskList *tasks);
struct TaskProfile		*profile_tasks(struct TaskList *tasks);
struct PriorityMap		*compute_priorities_mock(struct TaskProfile *profile);
int						get_available_core_count(void);
int						select_best_task(struct TaskProfile *profile);
struct ScheduleResult	*create_schedule_result(int core_count);
void					update_schedule_entry(struct ScheduleResult *result, int core_id, int task_id);

void free_task_profile(struct TaskProfile *profile);
void free_priority_map(struct PriorityMap *priorities);
void free_loadinfo(struct LoadInfo *load);

#endif