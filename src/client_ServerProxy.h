/*
 * ServerProxy.h
 *
 *  Created on: Apr 17, 2016
 *      Author: freddy
 */

#ifndef CLIENT_SERVERPROXY_H_
#define CLIENT_SERVERPROXY_H_

#include <string>

#include "common_Socket.h"

class ServerProxy {
private:
	socket_t serverSocket;

public:
	ServerProxy(const std::string ip, const std::string puerto);

	int enviar(const std::string mensaje);

	virtual ~ServerProxy();
};

#endif /* CLIENT_SERVERPROXY_H_ */
