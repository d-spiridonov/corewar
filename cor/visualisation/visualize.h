/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 21:19:04 by dspyrydo          #+#    #+#             */
/*   Updated: 2017/10/23 23:22:53 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZE_H
# define VISUALIZE_H

# include <math.h>
# include "../../corewar.h"

typedef struct		s_highl
{
	int				id;
	unsigned long	cycle;
	struct s_highl	*next;
}					t_highl;

typedef struct		s_live
{
	int				id;
	int				colorid;
	unsigned long	cycle;
	struct s_live	*next;
}					t_live;

struct				s_vis
{
	WINDOW			*code;
	WINDOW			*menu;
	int				cycles;
	int				c;
	int				s;
	t_highl			*highl;
	t_live			*live;
};

void				visualize(t_skrr *skrr);
void				visualize_init(t_skrr *skrr);
int					highlight(t_skrr *skrr, int id);
void				init_visualisation(t_skrr *skrr);
void				breakdown_current(t_skrr *skrr, int y);
void				printwinner(t_skrr *skrr, char *name, int id);
void				printdata(WINDOW *menu, t_skrr *skrr);
int					find_live_count(t_skrr *skrr, int id);
int					champ_color(t_skrr *skrr, int id);
long				find_last_live(t_skrr *skrr, int id);
char				*find_progname(t_skrr *skrr, int id);
void				printmargins(WINDOW *code, WINDOW *menu, int width, \
					int height);
void				menufields(WINDOW *menu, t_skrr *skrr);
void				printmem(t_skrr *skrr);
int					findprocess(t_skrr *skrr, int pc);
int					i_am_alive(t_skrr *skrr);
void				hints(t_skrr *skrr);
void				intro(t_skrr *skrr);

#endif
