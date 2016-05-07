/*
 * server_MappersHandler.cpp
 *
 *  Created on: Apr 24, 2016
 *      Author: freddy
 */

#include <string>
#include <list>

#include "server_MappersHandler.h"

#include "server_ClientProxy.h"
#include "server_DataCollector.h"
#include "server_MapReceiver.h"

MappersHandler::MappersHandler(DataCollector &dataCollector,
		const std::string puerto, int maxMappersQueue)
	: aceptarConexiones(false),
	  dataCollector(dataCollector),
	  mapReceiver(MapReceiver(dataCollector, puerto, maxMappersQueue, mappers)){
}

void MappersHandler::run() {
	aceptarConexiones = true;
	//Arranco a escuchar nuevos mappers que se conecten
	mapReceiver.start();
	while (aceptarConexiones || !mappers.empty()) {
		//Recorro los mappers y elimino el que haya terminado
		for (std::list<ClientProxy*>::iterator iter_mappers = mappers.begin();
				iter_mappers != mappers.end(); ++iter_mappers) {
			if ((*iter_mappers)->terminado()) {
				(*iter_mappers)->join();
				delete(*iter_mappers);
				iter_mappers = mappers.erase(iter_mappers);
			}
		}
	}
}

void MappersHandler::finish() {
	mapReceiver.stop();
	mapReceiver.join();
	aceptarConexiones = false;
}

MappersHandler::~MappersHandler() {
	MappersHandler::finish();
}

