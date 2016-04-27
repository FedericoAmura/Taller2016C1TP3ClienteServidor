/*
 * DataCollector.cpp
 *
 *  Created on: Apr 24, 2016
 *      Author: freddy
 */

#include <map>
#include <string>

#include "server_DataCollector.h"

DataCollector::DataCollector() {
}

void DataCollector::addTemperatura(std::string dia, std::string temperatura,
		std::string lugar) {
	temperaturas[dia][temperatura] = lugar;
}

std::map<std::string, std::string> DataCollector::getTemperaturasDia(
		std::string dia) {
	return temperaturas[dia];
}

DataCollector::~DataCollector() {
}

