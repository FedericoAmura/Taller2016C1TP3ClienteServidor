/*
 * server_MapperListener.h
 *
 *  Created on: Apr 19, 2016
 *      Author: freddy
 */

#ifndef SERVER_MAPPERLISTENER_H_
#define SERVER_MAPPERLISTENER_H_

#include <iostream>
#include <string>

#include "common_Socket.h"
#include "server_Thread.h"

class MapperListener: public Thread {
private:
	bool aceptarConexiones;
	socket_t mapperListener;
	//puntero al vector de mappers
	//puntero a los datos para pasarle a los mappers

public:
	MapperListener(const std::string puerto, int maxMappers);

	virtual void run();

	virtual void stop();

	virtual ~MapperListener();
};

#endif /* SERVER_MAPPERLISTENER_H_ */
