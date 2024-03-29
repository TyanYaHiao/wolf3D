/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_items.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zytrams <zytrams@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 16:29:13 by fsmith            #+#    #+#             */
/*   Updated: 2019/10/10 01:05:10 by zytrams          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <engine.h>

void		eng_create_items(t_engine *eng)
{
	eng_create_medkit(eng);
	eng_create_armor(eng);
	eng_create_powerup(eng);
	eng_create_rifle_ammo(eng);
	eng_create_plasma_ammo(eng);
	eng_create_plasma_gun(eng);
	eng_create_barrel(eng);
}

void		eng_create_medkit(t_engine *eng)
{
	t_enemy	*medkit;

	medkit = (t_enemy *)ft_memalloc(sizeof(t_enemy));
	medkit->id = MEDKIT;
	medkit->name = ft_strdup("Medkit");
	medkit->anmtn[E_IDLE] = util_create_sprite_by_name(eng, "medkit");
	medkit->anmtn[E_RUN] = medkit->anmtn[E_IDLE];
	medkit->anmtn[E_FIRE] = medkit->anmtn[E_IDLE];
	medkit->anmtn[E_HURT] = medkit->anmtn[E_IDLE];
	medkit->anmtn[E_DEAD] = util_create_sprite_by_name(eng, "empty_place");
	medkit->death_sound = sound_init("pickup_health");
	eng->enemy[MEDKIT] = medkit;
}

void		eng_create_armor(t_engine *eng)
{
	t_enemy	*armor;

	armor = (t_enemy *)ft_memalloc(sizeof(t_enemy));
	armor->id = ARMOR;
	armor->name = ft_strdup("Armor");
	armor->anmtn[E_IDLE] = util_create_sprite_by_name(eng, "armor");
	armor->anmtn[E_RUN] = armor->anmtn[E_IDLE];
	armor->anmtn[E_FIRE] = armor->anmtn[E_IDLE];
	armor->anmtn[E_HURT] = armor->anmtn[E_IDLE];
	armor->anmtn[E_DEAD] = util_create_sprite_by_name(eng, "empty_place");
	armor->death_sound = sound_init("pickup_armor");
	eng->enemy[ARMOR] = armor;
}

void		eng_create_powerup(t_engine *eng)
{
	t_enemy	*powerup;

	powerup = (t_enemy *)ft_memalloc(sizeof(t_enemy));
	powerup->id = POWER_UP;
	powerup->name = ft_strdup("Power up");
	powerup->anmtn[E_IDLE] = util_create_sprite_by_name(eng, "power_up");
	if (powerup->anmtn[E_IDLE]->a_state == ANIMATE)
		powerup->anmtn[E_IDLE]->a_state = PENDULUM;
	powerup->anmtn[E_RUN] = powerup->anmtn[E_IDLE];
	powerup->anmtn[E_FIRE] = powerup->anmtn[E_IDLE];
	powerup->anmtn[E_HURT] = powerup->anmtn[E_IDLE];
	powerup->anmtn[E_DEAD] = util_create_sprite_by_name(eng, "empty_place");
	powerup->death_sound = sound_init("pickup_powerup");
	eng->enemy[POWER_UP] = powerup;
}
