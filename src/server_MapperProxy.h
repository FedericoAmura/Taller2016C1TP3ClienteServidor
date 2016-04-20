/*
 * ClientProxy.h
 *
 *  Created on: Apr 19, 2016
 *      Author: freddy
 */

#ifndef SERVER_MAPPERPROXY_H_
#define SERVER_MAPPERPROXY_H_

#include <string>

#include "common_Socket.h"

class MapperProxy {
private:
	socket_t socket;

public:
	MapperProxy(const socket_t cliente);

	int recibir();

	virtual ~MapperProxy();
};

#endif /* SERVER_MAPPERPROXY_H_ */
