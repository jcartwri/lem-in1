//
// Created by kitos on 19.10.2019.
//

#include "../lem-in.h"

static void ft_clean_links(t_room *room)
{
	t_links_room 	*elem;
	t_links_room 	*copy;

	elem = room->links_room;
	while (elem != NULL)
	{
		copy = elem->next;
		free(elem->name_str);
		elem->name_str = NULL;
		elem->next = NULL;
		free(elem);
		elem = copy;
	}
	room->links_room = NULL;
}

static void ft_clean_basic_info_rooms(void)
{
	t_room	*elem;
	t_room	*copy;
	int i;

	i = -1;
	free(basic_info_rooms->mas_priority);
	free(basic_info_rooms->mas_processed);
	free(basic_info_rooms->mas_parent);
	basic_info_rooms->mas_priority = NULL;
	basic_info_rooms->mas_processed = NULL;
	basic_info_rooms->mas_parent = NULL;
	elem = basic_info_rooms->room;
	while (elem != NULL)
	{
		copy = elem->next;
		free(elem->name_str);
		free(elem->coord_y);
		free(elem->coord_x);
		free(elem->mas_links);
		elem->name_str = NULL;
		elem->coord_y = NULL;
		elem->coord_x = NULL;
		elem->mas_links = NULL;
		ft_clean_links(elem);
		elem->links_room = NULL;
		elem = copy;
	}
	while (basic_info_rooms->mas_rooms[++i] != NULL)
	{
		free(basic_info_rooms->mas_rooms[i]);
		basic_info_rooms->mas_rooms[i] = NULL;
	}
	free(basic_info_rooms->mas_rooms[i]);
	basic_info_rooms->mas_rooms[i] = NULL;
	free(basic_info_rooms->mas_rooms);
	basic_info_rooms->room = NULL;
	basic_info_rooms->mas_rooms = NULL;
	free(basic_info_rooms);
	basic_info_rooms = NULL;
}

static void ft_clean_queue_bfs(void)
{
	t_steck	*elem;
	t_steck	*copy;

	elem = queue_bfs;
	while (elem != NULL)
	{
		copy = elem->next;
		free(elem);
		elem = copy;
	}
	queue_bfs = NULL;
}

static void ft_free_body_group(t_pyth *elem)
{
	t_steck	*copy1;
	t_steck	*copy2;

	copy1 = elem->pyth;
	while (copy1 != NULL)
	{
		copy2 = copy1->next;
		free(copy1);
		copy1 = copy2;
	}
}

static void ft_clean_group_pyth(void)
{
	t_pyth *elem;
	t_pyth *copy;

	elem = group_pyth;
	while (elem != NULL)
	{
		copy = elem->next;
		elem->next = NULL;
		elem->next_finish = NULL;
		elem->enext = NULL;
		elem->hsinif = NULL;
		ft_free_body_group(elem);
		free(elem);
		elem = copy;
	}
	group_pyth = NULL;
}

static void	ft_clean_finish_pyth(void)
{
	free(finish_pyth);
	finish_pyth = NULL;
}

static void	ft_clean_end(void)
{
	int 			i;
	int				j;

	i = -1;
	while (end->finish[++i] != NULL)
	{
		j = -1;
		while (end->finish[i]->pyth[++j] != NULL)
		{
			free(end->finish[i]->pyth[j]);
			end->finish[i]->pyth[j] = NULL;
		}
		free(end->finish[i]->pyth[j]);
		end->finish[i]->pyth[j] = NULL;
		free(end->finish[i]->pyth);
		end->finish[i]->pyth = NULL;
		free(end->finish[i]);
		end->finish[i] = NULL;
	}
	free(end->finish[i]);
	end->finish[i] = NULL;
	free(end->finish);
	end->finish = NULL;
	free(end);
	end = NULL;
}

void	ft_clean_all_memory(void)
{
	ft_clean_end();
//	ft_clean_finish_pyth();
	ft_clean_group_pyth();
	ft_clean_queue_bfs();
	ft_clean_basic_info_rooms();
}
