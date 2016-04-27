/*
 * ClientProxy.cpp
 *
 *  Created on: Apr 19, 2016
 *      Author: freddy
 */

#include <string>

#include "server_ClientProxy.h"

ClientProxy::ClientProxy(DataCollector &dataCollector, socket_t cliente)
	: datosPendientes(true), dataCollector(dataCollector), socket(cliente) {
}

std::string ClientProxy::recibirLinea() {
	return std::string("prueba");
}

void ClientProxy::agregarData(std::string dia, std::string temperatura,
		std::string ciudad) {
	dataCollector.addTemperatura(dia, temperatura, ciudad);
}

void ClientProxy::run() {
	bool seguirLeyendo = true;
	std::string linea;
	while (seguirLeyendo) {
		linea = recibirLinea();
		if (linea.compare("End") != 0) {
			std::string dia;
			std::string temperatura;
			std::string ciudad;
			//parseo linea a esos 3 strings TODO
			agregarData(dia, temperatura, ciudad);
		} else {
			seguirLeyendo = false;
		}
	}
	datosPendientes = false;
}

bool ClientProxy::terminado() {
	return !datosPendientes;
}

ClientProxy::~ClientProxy() {
	socket_shutdown(&socket);
	socket_destroy(&socket);
}

