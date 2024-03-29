/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zytrams <zytrams@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 19:21:02 by zytrams           #+#    #+#             */
/*   Updated: 2019/10/19 21:02:33 by zytrams          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <engine.h>

void			engine_set_links(t_wall_clinks *links, void *ls[6])
{
	links->cycler = (t_wall_cycle *)ls[0];
	links->data = (t_wall_help2 *)ls[1];
	links->data_help = (t_wall_help3 *)ls[2];
	links->eng = (t_engine *)ls[3];
	links->mdata = (t_wall_mai_data *)ls[4];
	links->surf = (SDL_Surface *)ls[5];
}

void			engine_render_wall_main_cycler(t_wall_clinks *links,
				t_wall_cycle *cycler, t_wall_mai_data *mdata)
{
	while (cycler->x <= mdata->endx)
	{
		engine_render_cycle_1(links);
		engine_render_wall_cycle_3(links);
		++cycler->x;
	}
}

void			engine_render_wall_pusher(t_engine *eng,
				t_wall_help2 *data, t_wall_mai_data *mdata)
{
	engine_push_renderstack(eng->world->renderstack,
	(t_item){data->portal, mdata->beginx, mdata->endx});
	eng->world->sectors_array[data->portal].item_sprts.sect_id = (t_item)
	{data->portal, mdata->beginx, mdata->endx};
	one_dim_zbuffers_copy(&eng->world->sectors_array[data->portal].item_sprts,
	data->ytop, data->ybottom);
	engine_push_spriterenderstack(eng->world->sprite_renderstack,
	&eng->world->sectors_array[data->portal].item_sprts);
}

void			engine_render_particles_wall(t_engine *eng, SDL_Surface *surf,
				t_wall_help2 *data)
{
	int		i;

	i = 0;
	while (eng->world->sectors_array[data->sect.sectorno].
	objects_array[data->obj_id].particles[i].id == 1 && i < 128)
	{
		if (eng->world->sectors_array[data->sect.sectorno].
		objects_array[data->obj_id].particles[i].z
		> eng->world->sectors_array[data->sect.sectorno].floor &&
		eng->world->sectors_array[data->sect.sectorno].
		objects_array[data->obj_id].particles[i].z
		< eng->world->sectors_array[data->sect.sectorno].ceil)
			engine_render_particle(eng, surf,
			&eng->world->sectors_array[data->sect.sectorno].
			objects_array[data->obj_id].particles[i],
			(t_ptcl_h){&eng->world->sectors_array[data->sect.sectorno].
			objects_array[data->obj_id], data->plr, data->sect});
		i++;
	}
}
