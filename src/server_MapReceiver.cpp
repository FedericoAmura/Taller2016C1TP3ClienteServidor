/*
 * server_MapperListener.cpp
 *
 *  Created on: Apr 19, 2016
 *      Author: freddy
 */

#include <iostream>
#include <string>
#include <list>

#include "server_MapReceiver.h"
#include "server_DataCollector.h"

MapReceiver::MapReceiver(DataCollector &dataCollector, const std::string puerto,
		const int maxMappersQueue, std::list<ClientProxy*> &mappers)
: aceptarConexiones(false), puerto(puerto),
  dataCollector(dataCollector), mapperListener(puerto, maxMappersQueue),
  mappers(mappers) {
}

void MapReceiver::run() {
	aceptarConexiones = true;
	while (aceptarConexiones) {
		//Espero (bloqueado) otro mapper
		Socket cliente = mapperListener.aceptarCliente();
		ClientProxy* mapper = new ClientProxy(dataCollector, cliente);
		mappers.push_back(mapper);
		mappers.back()->start();
	}
}

void MapReceiver::stop() {
	aceptarConexiones = false;
	//Destrabo con "End\n" para que no mapee nada
	mapperListener.destrabar("End\n");
}

MapReceiver::~MapReceiver() {
	mapperListener.cerrar();
}

