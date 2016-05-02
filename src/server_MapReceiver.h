/*
 * server_MapperListener.h
 *
 *  Created on: Apr 19, 2016
 *      Author: freddy
 */

#ifndef SERVER_MAPRECEIVER_H_
#define SERVER_MAPRECEIVER_H_

#include <iostream>
#include <string>
#include <vector>
#include <list>

#ifdef __cplusplus
extern "C" {
#endif
#include "common_Socket.h"
#ifdef __cplusplus
}
#endif

#include "server_Thread.h"
#include "server_DataCollector.h"
#include "server_ClientProxy.h"

class MapReceiver : public Thread {
private:
	bool aceptarConexiones;
	DataCollector dataCollector;
	socket_t mapperListener;
	std::list<ClientProxy*> &mappers;

public:
	MapReceiver(DataCollector &dataCollector, const std::string puerto,
			const int maxMappersQueue, std::list<ClientProxy*> &mappers);

	//Empiezo a escuchar mappers, meterlos en el vector y los arranco
	void run();

	//Dejo de escuchar por nuevos mappers
	void stop();

	virtual ~MapReceiver();
};

#endif /* SERVER_MAPRECEIVER_H_ */
