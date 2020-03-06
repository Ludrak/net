
#include "ft_ip.h"
#include <stdio.h>


t_ip		parse_ip(char *ip_format)
{
	char	**bytes;
	t_ip	ip;
	int		i;
	int		j;

	bytes = ft_split(ip_format, '.');
	if (ft_strchr(bytes[3], '/'))
	{
		char	**tmp;
		
		tmp = ft_split(bytes[3], '/');
		ip.bytes[3] = ft_atoi(tmp[0]);
		ip.cidr = ft_atoi(tmp[1]);
	}
	ip.bytes[0] = ft_atoi(bytes[0]);
	ip.bytes[1] = ft_atoi(bytes[1]);
	ip.bytes[2] = ft_atoi(bytes[2]);
	j = 0;
	i = 4;
	ip.address = 0;
	while (i > 0)
	{
		ip.address |= ip.bytes[j] << ((i == 0) ? 1 : (i - 1) * 8);
		i--;
		j++;
	}
	ip.machines = get_machine_count(ip);
	ip.subnet = get_subnet_mask(ip.cidr);
	ip.network = get_network_address(ip);
	ip.broadcast = get_broadcast_address(ip);
	ip.first = get_first_machine(ip);
	ip.last = get_last_machine (ip);
	return(ip);
}

__uint32_t		get_subnet_mask(__uint8_t cidr)
{
	__uint32_t	subnet;

	if (cidr > 32)
		return (0);
	subnet = 0;
	while (cidr)
		subnet |= (1 << (32 - cidr--));
	return (subnet);
}

__uint32_t		get_network_address(t_ip ip)
{
	return (ip.address & ip.subnet);
}

__uint32_t		get_broadcast_address(t_ip ip)
{
	return (ip.network | ~ip.subnet);
}

size_t			get_machine_count(t_ip ip)
{
	return (pow (2, 32 - ip.cidr) - 2);
}

__uint32_t		get_first_machine (t_ip ip)
{
	return (ip.network + 1);
}

__uint32_t		get_last_machine (t_ip ip)
{
	return (ip.broadcast - 1);
}