/*
 * ClientProxy.cpp
 *
 *  Created on: Apr 19, 2016
 *      Author: freddy
 */

#include <iostream>
#include <string>

#include "server_ClientProxy.h"

ClientProxy::ClientProxy(DataCollector &dataCollector, const Socket cliente)
	: datosPendientes(true), dataCollector(dataCollector), socket(cliente) {
}

std::string ClientProxy::recibirLinea() {
	std::string linea = socket.recibirHasta('\n');
	return linea;
}

void ClientProxy::agregarData(const std::string &dia,
		const std::string &temperatura,
		const std::string &ciudad) {
	dataCollector.addTemperatura(dia, temperatura, ciudad);
}

void ClientProxy::run() {
	bool seguirLeyendo = true;
	std::string linea;
	while (seguirLeyendo) {
		linea = recibirLinea();
		if (linea.compare("End") != 0) {
			size_t primerSeparador = linea.find(SEPARADOR_CAMPOS);
			size_t segundoSeparador = linea.find(SEPARADOR_CAMPOS,
					primerSeparador+1);
			std::string dia = linea.substr(0,primerSeparador);
			std::string temperatura = linea.substr(primerSeparador+1,
					segundoSeparador-primerSeparador-1);
			std::string ciudad = linea.substr(segundoSeparador+1);

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
	socket.cerrar();
}

