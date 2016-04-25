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

class DataCollector {
private:
	//Un map de trios, dia-temperatura-ciudad
	std::map<std::string, std::map<std::string, std::string> > temperaturas;

public:
	DataCollector();

	void addTemperatura(std::string dia, std::string temperatura, std::string lugar);

	std::map<std::string, std::string> getTemperaturasDia(std::string dia);

	virtual ~DataCollector();
};

#endif /* DATACOLLECTOR_H_ */
