/*
 * server_MapperListener.cpp
 *
 *  Created on: Apr 19, 2016
 *      Author: freddy
 */

#include <string>
#include <list>

#include "server_MapReceiver.h"
#include "server_DataCollector.h"

MapReceiver::MapReceiver(DataCollector &dataCollector, const std::string puerto,
		const int maxMappersQueue, std::list<ClientProxy> &mappers)
	: aceptarConexiones(false), dataCollector(dataCollector), mappers(mappers) {
	if (0 != socket_init_server(&mapperListener, puerto.c_str())) {
		throw std::exception();
	}
	if (0 != socket_listen(&mapperListener, maxMappersQueue)) {
		throw std::exception();
	}
}

void MapReceiver::run() {
	aceptarConexiones = true;
	while (aceptarConexiones) {
		//Genero un nuevo mapper y lo largo a correr
		socket_t newMapSocket;
		if (0 != socket_accept(&mapperListener,&newMapSocket)) {
			throw std::exception();
		}
		ClientProxy mapper(dataCollector, newMapSocket);
		mappers.push_back(mapper);
		mappers.back().start();
	}
}

void MapReceiver::stop() {
	aceptarConexiones = false;
	//destrabo el socket y hago que termine el run
	//Para esto puedo crear un falso cliente y solo lo hago mandar "End\n"
}

MapReceiver::~MapReceiver() {
	socket_shutdown(&mapperListener);
	socket_destroy(&mapperListener);
}

