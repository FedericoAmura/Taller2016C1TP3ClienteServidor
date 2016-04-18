/*
 * ServerProxy.cpp
 *
 *  Created on: Apr 17, 2016
 *      Author: freddy
 */

#include <string>
#include <cstdlib>

#include "ServerProxy.h"
#include "common_socket.h"


ServerProxy::ServerProxy(const std::string ip, const std::string puerto) {
	int aux = 0;
	aux = socket_init_client(&socket, puerto.c_str(), ip.c_str());
	if (aux != 0) {
		throw std::exception();
	}
}

int ServerProxy::enviar(const std::string mensaje) {
	int aux = 0;
	aux = socket_send(&socket,mensaje.c_str(),mensaje.length());
	if (aux != 0) {
		throw std::exception();
	}
	return 0;
}

ServerProxy::~ServerProxy() {
	socket_destroy(&socket);
}

