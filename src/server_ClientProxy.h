/*
 * ClientProxy.h
 *
 *  Created on: Apr 19, 2016
 *      Author: freddy
 */

#ifndef SERVER_CLIENTPROXY_H_
#define SERVER_CLIENTPROXY_H_

#include <string>

extern "C"{
#include "common_Socket.h"
}

#include "server_Thread.h"
#include "server_DataCollector.h"

#define SEPARADOR_CAMPOS ' '

class ClientProxy : public Thread {
private:
	bool datosPendientes;
	DataCollector dataCollector;
	socket_t socket;

public:
	ClientProxy(DataCollector &dataCollector, const socket_t cliente);

	//Arranco la recepcion de datos del mapper
	void run();

	//Veo si el mapper ya termino de enviar datos
	bool terminado();

	virtual ~ClientProxy();

private:
	std::string recibirLinea();
	void agregarData(std::string dia, std::string temperatura, std::string ciudad);
};

#endif /* SERVER_CLIENTPROXY_H_ */
