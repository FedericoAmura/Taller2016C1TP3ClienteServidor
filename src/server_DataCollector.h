/*
 * DataCollector.h
 *
 *  Created on: Apr 24, 2016
 *      Author: freddy
 */

#ifndef DATACOLLECTOR_H_
#define DATACOLLECTOR_H_

#include <string>
#include <map>

#include "server_Mutex.h"

class DataCollector {
private:
	//Un map de trios, dia-temperatura-ciudad
	std::map<std::string, std::multimap<int,std::string> > temperaturas;
	//Mutex para proteger accesos simultaneos a los datos
	Mutex m;

public:
	DataCollector();

	//Agrega una nueva temperatura para una ciudad un dia del mes
	void addTemperatura(const std::string &dia,
			const std::string &temperatura,
			const std::string &lugar);

	//Devuelve un multimap con las temperaturas de un dia en todas las ciudades
	std::multimap<int, std::string> getTemperaturasDia(
			const std::string &dia);

	virtual ~DataCollector();
};

#endif /* DATACOLLECTOR_H_ */
