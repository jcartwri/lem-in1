//
// Created by kitos on 15.10.2019.
//

#include "../lem-in.h"

void ft_find_first_path(int start, int end, t_pyth *pyth)
{
	if ((start == end) || (end == -1))
	{
		ft_creat_pyth(pyth, start);
	}
	else
	{
		ft_find_first_path(start, basic_info_rooms->mas_parent[end], pyth);
		ft_creat_pyth(pyth, end);
		if (end != basic_info_rooms->end)
			basic_info_rooms->mas_priority[end]++;
	}
}

void ft_bfs(void)
{
	t_steck			*elem;
	t_links_room	*p;
	int				start;
	int				v;
	int				y;

	queue_bfs = NULL;
	start = basic_info_rooms->start;
	enqueue(start);
	basic_info_rooms->mas_processed[start] = 0;
	while (queue_bfs != NULL)
	{
		elem = dequeue();
		v = elem->name_room;
		free(elem);
		basic_info_rooms->mas_processed[v] = 2;
		p = basic_info_rooms->mas_rooms[v]->links_room;
		while (p != NULL)
		{
			y = p->name_int;
			if (basic_info_rooms->mas_processed[y] == -1)
			{
				enqueue(y);
				basic_info_rooms->mas_processed[y] = 0;
				basic_info_rooms->mas_parent[y] = v;
			}
			p = p->next;
		}
	}
	if (basic_info_rooms->mas_parent[basic_info_rooms->end] == -1)
	{
		ft_exit();
	}
	ft_find_first_path(start, basic_info_rooms->end, ft_insert_pyth());
	ft_check_repeat_pyth();
}