/*
 * DataCollector.cpp
 *
 *  Created on: Apr 24, 2016
 *      Author: freddy
 */

#include <string>
#include <utility>
#include <map>
#include <cstdlib>

#include "server_DataCollector.h"
#include "server_Mutex.h"
#include "server_Lock.h"

DataCollector::DataCollector() {
}

void DataCollector::addTemperatura(const std::string &dia,
		const std::string &temperatura,
		const std::string &lugar) {
	std::pair<int,std::string> par(atoi(temperatura.c_str()),lugar);
	Lock l(m);
	(temperaturas[dia]).insert(par);
}

std::multimap<int, std::string> DataCollector::getTemperaturasDia(
		const std::string &dia) {
	Lock l(m);
	return temperaturas[dia];
}

DataCollector::~DataCollector() {
}

