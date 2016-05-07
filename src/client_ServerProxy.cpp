/*
 * ServerProxy.cpp
 *
 *  Created on: Apr 17, 2016
 *      Author: freddy
 */

#include <string>
#include <cstdlib>

#include "common_Socket.h"
#include "client_ServerProxy.h"

ServerProxy::ServerProxy(const std::string &ip, const std::string &puerto)
	: serverSocket(Socket(ip, puerto)){
}

int ServerProxy::enviar(const std::string &mensaje) {
	serverSocket.enviar(mensaje);
	return 0;
}

ServerProxy::~ServerProxy() {
}

