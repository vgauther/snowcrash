#include <stdio.h>

int     main(int ac, char **av)
{
        printf("%s -\n", av[1]);

	int i = 0;
	while(av[1][i])
	{
		av[1][i] -= i;
		i++;
	}

        printf("%s -\n", av[1]);
        return(0);
}