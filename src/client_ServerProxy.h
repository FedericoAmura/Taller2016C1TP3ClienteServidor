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

//Clase de conexion TCP con el server
class ServerProxy {
private:
	Socket serverSocket;

public:
	ServerProxy(const std::string &ip, const std::string &puerto);

	//Envia al server el mensaje
	int enviar(const std::string &mensaje);

	virtual ~ServerProxy();
};

#endif /* CLIENT_SERVERPROXY_H_ */
