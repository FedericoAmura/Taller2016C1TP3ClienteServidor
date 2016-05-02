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
	std::string linea;
	char letter = '\n';
	while (0 == socket_receive(&socket,&letter,1)) {
		if (letter == '\n') break;
		linea += letter;
	}
	return linea;
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
			size_t primerSeparador = linea.find(SEPARADOR_CAMPOS);
			size_t segundoSeparador = linea.find(SEPARADOR_CAMPOS, primerSeparador+1);
			std::string dia = linea.substr(0,primerSeparador);
			std::string temperatura = linea.substr(primerSeparador+1, segundoSeparador-primerSeparador-1);
			std::string ciudad = linea.substr(segundoSeparador+1);
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

