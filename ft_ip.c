
#include "libft.h"
#include <stdio.h>
#include <math.h>

typedef struct	s_ip
{
	__uint8_t		bytes[4];
	__uint32_t		bitmask;
}				t_ip;



__uint32_t		get_bitmask(__uint8_t mask)
{
	__uint32_t	bitmask;

	if (mask > 32)
		return (0);
	bitmask = 0;
	while (mask)
		bitmask |= (1 << (32 - mask--));
	return (bitmask);
}



int		main(int ac, char **av)
{
	char	**bytes;
	t_ip	ip;

	bytes = ft_split(av[1], '.');
	if (ac == 3)
	{
		printf("\n* NET **********************************\nIP infomations for : %s / %s\n", av[1], av[2]);

		for (int i = 0; i < 4; i++)
			ip.bytes[i]	= ft_atoi(bytes[i]);
		
		ip.bitmask = get_bitmask(ft_atoi(av[2]));
		printf ("\nSubnet mask :		%d.%d.%d.%d\n\n", (ip.bitmask >> 24) & 0xFF, (ip.bitmask >> 16) & 0xFF, (ip.bitmask >> 8) & 0xFF, ip.bitmask & 0xFF);

		//	& operator btw ip and subnet mask
		printf ("Network address :	%d.%d.%d.%d\n",
		ip.bytes[0] & ((ip.bitmask >> 24) & 0xFF), 
		ip.bytes[1] & ((ip.bitmask >> 16) & 0xFF), 
		ip.bytes[2] & ((ip.bitmask >> 8) & 0xFF), 
		ip.bytes[3] & ip.bitmask & 0xFF);

		//	| operator btw net address and inverted subnet mask
		printf ("Broadcast address :	%d.%d.%d.%d\n",
		(ip.bytes[0] & ((ip.bitmask >> 24) & 0xFF)) | ((~ip.bitmask >> 24) & 0xFF), 
		(ip.bytes[1] & ((ip.bitmask >> 16) & 0xFF)) | ((~ip.bitmask >> 16) & 0xFF), 
		(ip.bytes[2] & ((ip.bitmask >> 8) & 0xFF)) | ((~ip.bitmask >> 8) & 0xFF), 
		(ip.bytes[3] & ip.bitmask & 0xFF) | (~ip.bitmask & 0xFF));

		// 2 ^ 32 - mask - 2
		printf ("Host :			%d\n\n", (int)pow(2, 32 - ft_atoi(av[2])) - 2);

		// net address + 1 on first byte
		printf ("First address :		%d.%d.%d.%d\n",
		ip.bytes[0] & ((ip.bitmask >> 24) & 0xFF), 
		ip.bytes[1] & ((ip.bitmask >> 16) & 0xFF), 
		ip.bytes[2] & ((ip.bitmask >> 8) & 0xFF), 
		(ip.bytes[3] & ip.bitmask & 0xFF) + 1);

		// broadcast address - 1 on first byte
		printf ("Last address :		%d.%d.%d.%d\n****************************************\n",
		(ip.bytes[0] & ((ip.bitmask >> 24) & 0xFF)) | ((~ip.bitmask >> 24) & 0xFF), 
		(ip.bytes[1] & ((ip.bitmask >> 16) & 0xFF)) | ((~ip.bitmask >> 16) & 0xFF), 
		(ip.bytes[2] & ((ip.bitmask >> 8) & 0xFF)) | ((~ip.bitmask >> 8) & 0xFF), 
		((ip.bytes[3] & ip.bitmask & 0xFF) | (~ip.bitmask & 0xFF)) - 1);
	}
	return (0);
}
