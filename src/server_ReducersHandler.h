/*
 * server_ReducersHandler.h
 *
 *  Created on: Apr 24, 2016
 *      Author: freddy
 */

#ifndef SERVER_REDUCERSHANDLER_H_
#define SERVER_REDUCERSHANDLER_H_

#include <string>
#include <vector>

#include "server_Thread.h"
#include "server_DataCollector.h"
#include "server_Reducer.h"

class ReducersHandler : public Thread {
private:
	int dias;
	DataCollector data;
	std::vector<std::string> &resultados;
	std::vector<Reducer*> reducers;

public:
	ReducersHandler(int dias, const DataCollector &dataCollector,
			std::vector<std::string> &resultados);

	void run();

	virtual ~ReducersHandler();
};

#endif /* SERVER_REDUCERSHANDLER_H_ */
