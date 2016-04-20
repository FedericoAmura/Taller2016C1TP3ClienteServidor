/*
 * server_MapperListener.cpp
 *
 *  Created on: Apr 19, 2016
 *      Author: freddy
 */

#include "server_MapperListener.h"

MapperListener::MapperListener(const std::string puerto, int maxMappers) {
	if (0 != socket_init_server(&mapperListener, puerto.c_str())) {
		throw std::exception();
	}
	if (0 != socket_listen(&mapperListener, maxMappers)) {
		throw std::exception();
	}
	aceptarConexiones = false;
}

void MapperListener::run() {
	aceptarConexiones = true;
	while (aceptarConexiones) {
		//genero un nuevo mapper y lo largo a correr
		std::cout << "Estoy viendo si aparecen mappers" << std::endl;
		sleep(1000);
	}
}

void MapperListener::stop() {
	aceptarConexiones = false;
	//destrabo el socket y hago que termine el run
}

MapperListener::~MapperListener() {
	socket_shutdown(&mapperListener);
	socket_destroy(&mapperListener);
}

