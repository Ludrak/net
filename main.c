
#include "ft_ip.h"
#include <stdio.h>

int check (char *str)
{
	int		i;
	int		cidr;
	
	i = 1;
	cidr = 0;
	while (str && *str)
	{
		if (*str == '.' && i == 3)
		{
			str++;
			while (str && *str)
			{
				if (*str == '/')
					cidr = 1;
				if (!ft_isdigit(*str) && *str != '/')
					return (0);
				else if (cidr)
				{
					str++;
					break;
				}
				str++;
			}
		}
		if (*str == '.')
			i++;
		if (!ft_isdigit(*str) && *str != '.')
			return (0);
		str++;
	}
	if (cidr)
		return (1);
	return (0);
}

int		main(int ac, char **av)
{
	t_ip		ip;

	if (ac == 2 && check(av[1]))
	{
		parse_ip(av[1]);

		printf("\n* IPV4 CALC ****************************\n| IP infomations for :	%s\n", av[1]);
		ip = parse_ip(av[1]);

		printf ("|\n| Subnet mask :		%d.%d.%d.%d\n|\n", (ip.subnet >> 24) & 0xFF, (ip.subnet >> 16) & 0xFF, (ip.subnet >> 8) & 0xFF, ip.subnet & 0xFF);
		printf ("| Network address :	%d.%d.%d.%d\n", (ip.network >> 24) & 0xFF, (ip.network >> 16) & 0xFF, (ip.network >> 8) & 0xFF, ip.network & 0xFF);
		printf ("| Broadcast address :	%d.%d.%d.%d\n", (ip.broadcast >> 24) & 0xFF, (ip.broadcast >> 16) & 0xFF, (ip.broadcast >> 8) & 0xFF, ip.broadcast & 0xFF);
		printf ("| Numer of machines :	%zu\n|\n", ip.machines);
		printf ("| First machine :	%d.%d.%d.%d\n", (ip.first >> 24) & 0xFF, (ip.first >> 16) & 0xFF, (ip.first >> 8) & 0xFF, ip.first & 0xFF);
		printf ("| Last machine :	%d.%d.%d.%d\n****************************************\n", (ip.last >> 24) & 0xFF, (ip.last >> 16) & 0xFF, (ip.last >> 8) & 0xFF, ip.last & 0xFF);
	}
	else
	{
		printf ("Incorrect ip format.\nUse : %s xxx.xxx.xxx.xxx/cidr\n", av[0]);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
