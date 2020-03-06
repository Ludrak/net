
#ifndef IP_H
# define IP_H

#include <sys/types.h>
#include "libft.h"
#include <math.h>

typedef struct	s_ip
{
	__uint8_t		bytes[4];

    __uint8_t       cidr;
    size_t          machines;

    __uint32_t      address;
    __uint32_t      network;
    __uint32_t      broadcast;
	__uint32_t		subnet;

    __uint32_t      first;
    __uint32_t      last;
}				t_ip;

t_ip		    parse_ip(char *ip_format);

__uint32_t		get_subnet_mask(__uint8_t mask);
size_t			get_machine_count(t_ip ip);

__uint32_t		get_network_address(t_ip ip);
__uint32_t		get_broadcast_address(t_ip ip);

__uint32_t		get_first_machine (t_ip ip);
__uint32_t		get_last_machine (t_ip ip);

#endif