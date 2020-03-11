#include "21sh.h"

t_shell *g_shell;



void		sig(int nb)
{
    nb = 0;
    g_shell->termcaps->i = 1;
		ft_putstr("\n\n");
		choose_display(g_shell->termcaps);
	return ;
}

int				main(int argc, char **argv, char **env)
{
	char		*line;
	t_termcaps	termcaps;

	if (tcgetattr(0, &termcaps.term_restore) == -1)
		exit(-1);
	init_termcaps(&termcaps);
  if (!(g_shell = malloc(sizeof(*g_shell))))
	 exit(-1);
	line = NULL;
  g_shell->termcaps = &termcaps;
	while (1)
	{
    g_shell->termcaps->i = 0;
    signal(SIGINT, sig);
		ft_putstr("\n");
		line = trim_termcaps(core_termcaps(&termcaps, 1));
		ft_strdel(&line);
	}
	return (argc && argv && env && 0);
}
