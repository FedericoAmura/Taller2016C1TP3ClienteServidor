/*
 * ClientProxy.cpp
 *
 *  Created on: Apr 19, 2016
 *      Author: freddy
 */

#include "server_MapperProxy.h"

MapperProxy::MapperProxy(socket_t cliente) : socket(cliente) {
}

MapperProxy::~MapperProxy() {
	socket_shutdown(&socket);
	socket_destroy(&socket);
}

