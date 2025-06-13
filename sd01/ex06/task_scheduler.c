/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task_scheduler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 03:48:26 by mbrighi           #+#    #+#             */
/*   Updated: 2025/06/13 05:01:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "task_scheduler.h"

struct ScheduleResult *manage_error(struct TaskProfile *profile, struct PriorityMap *priorities, struct ScheduleResult *schedule)
{
	if (profile)
		free_task_profile(profile);
	if (priorities)
		free_priority_map(priorities);
	(void)schedule;
	return (NULL);
}
struct ScheduleResult *schedule_tasks(struct TaskList *tasks)
{
	struct TaskProfile		*profile = NULL;
	struct PriorityMap		*priorities = NULL;
	struct ScheduleResult	*schedule = NULL;
	struct LoadInfo			*load = NULL;
	int						core_count = 0;
	int						core_id = 0;
	int						task_id;

	profile = profile_tasks(tasks);
	if (profile == NULL)
		return (NULL);
	priorities = compute_priorities_mock(profile);
	if (priorities == NULL)
		return (manage_error(profile, NULL, NULL), NULL);

	core_count = get_available_core_count();
	if (core_count <= 0)
		return (manage_error(profile, priorities, NULL), NULL);
	schedule = create_schedule_result(core_count);
	if (schedule == NULL)
		return (manage_error(profile, priorities, NULL), NULL);
	while (core_id < core_count)
	{
		task_id = select_best_task(profile);
		if (task_id == -1)
			return (manage_error(profile, priorities, schedule), NULL);
		update_schedule_entry(schedule, core_id, task_id);
		core_id++;
	}
	manage_error(profile, priorities, NULL);
	return (schedule);
}
