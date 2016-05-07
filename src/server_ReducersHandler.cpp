/*
 * server_ReducersHandler.cpp
 *
 *  Created on: Apr 24, 2016
 *      Author: freddy
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

#include "server_ReducersHandler.h"

template <typename T>
std::string ReducersHandler::numeroATexto(T numero) {
	std::stringstream ss;
	ss << numero;
	return ss.str();
}

ReducersHandler::ReducersHandler(int dias, DataCollector &dataCollector,
		std::vector<std::string> &resultados)
	: dias(dias), data(dataCollector), resultados(resultados) {
}

void ReducersHandler::run() {
	int i;
	//Creo todos los reducers
	for (i = 0; i < dias; i++) {
		std::string dia = numeroATexto(i+1);	//Los dias se cuentan desde 1
		std::multimap<int, std::string> temperaturasDia =
				data.getTemperaturasDia(dia);
		Reducer *reducer = new Reducer(resultados[i],temperaturasDia);
		reducers.push_back(reducer);
	}
	//Arranco todos los reducers
	/*for (i = 0; i< dias; i++) {
		reducers[i]->start();
	}
	//Joineo todos los reducers
	for (i = 0; i< dias; i++) {
		reducers[i]->join();
	}*/

	//Uso de a 5 reducers para que el SERCOM no explote
	//Siempre verifico porque se puede pasar hasta el 29 o 34
	//con el metodo de arriba no pasaria esto...
	for (i = 0; i < dias; i = i+5) {
		reducers[i]->start();
		if (i+1 < dias) reducers[i+1]->start();
		if (i+2 < dias) reducers[i+2]->start();
		if (i+3 < dias) reducers[i+3]->start();
		if (i+4 < dias) reducers[i+4]->start();
		reducers[i]->join();
		if (i+1 < dias) reducers[i+1]->join();
		if (i+2 < dias) reducers[i+2]->join();
		if (i+3 < dias) reducers[i+3]->join();
		if (i+4 < dias) reducers[i+4]->join();
	}

	//Destruyo todos los reducers
	for (i = 0; i < dias; i++) {
		delete(reducers[i]);
	}
}

ReducersHandler::~ReducersHandler() {
}

