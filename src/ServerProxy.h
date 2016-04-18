/*
 * ServerProxy.h
 *
 *  Created on: Apr 17, 2016
 *      Author: freddy
 */

#ifndef SERVERPROXY_H_
#define SERVERPROXY_H_

#include <string>

#include "common_socket.h"

class ServerProxy {
private:
	socket_t socket;

public:
	ServerProxy(const std::string ip, const std::string puerto);

	int enviar(const std::string mensaje);

	virtual ~ServerProxy();
};

#endif /* SERVERPROXY_H_ */
