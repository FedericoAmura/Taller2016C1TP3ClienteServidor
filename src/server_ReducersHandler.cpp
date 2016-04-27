/*
 * server_ReducersHandler.cpp
 *
 *  Created on: Apr 24, 2016
 *      Author: freddy
 */

#include <string>
#include <vector>

#include "server_ReducersHandler.h"

ReducersHandler::ReducersHandler(int dias, const DataCollector &dataCollector,
		std::vector<std::string> &resultados)
	: dias(dias), data(dataCollector), resultados(resultados) {
}

void ReducersHandler::run() {
}

ReducersHandler::~ReducersHandler() {
}

