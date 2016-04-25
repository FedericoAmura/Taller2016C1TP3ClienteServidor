/*
 * server_MappersHandler.h
 *
 *  Created on: Apr 24, 2016
 *      Author: freddy
 */

#ifndef SERVER_MAPPERSHANDLER_H_
#define SERVER_MAPPERSHANDLER_H_

#define MAP_TERMINADO 0

#include <vector>
#include <list>

#include "server_Thread.h"
#include "server_DataCollector.h"
#include "server_ClientProxy.h"
#include "server_MapReceiver.h"

class MappersHandler : public Thread {
private:
	bool aceptarConexiones;
	DataCollector dataCollector;
	std::list<ClientProxy> mappers;
	MapReceiver mapReceiver;

public:
	MappersHandler(DataCollector &dataCollector, const std::string puerto, int maxMappersQueue);

	//Arranco el receptor de mappers
	void run();

	//Desactivo el receptor y hago terminar los mappers asociados
	void finish();

	virtual ~MappersHandler();
};

#endif /* SERVER_MAPPERSHANDLER_H_ */
