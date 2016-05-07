/*
 * server_Reducer.cpp
 *
 *  Created on: Apr 30, 2016
 *      Author: freddy
 */

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

#include "server_Reducer.h"

template <typename T>
std::string Reducer::numeroATexto(T numero) {
	std::stringstream ss;
	ss << numero;
	return ss.str();
}

Reducer::Reducer(std::string &resultado,
		const std::multimap<int, std::string> temperaturas)
	: resultado(resultado), temperaturasDia(temperaturas) {
}

void Reducer::run() {
	//Busco ciudades con mayor temperatura
	std::map<int, std::string>::const_reverse_iterator rit =
			temperaturasDia.rbegin();
	int temperaturaMaxima = rit->first;
	std::vector<std::string> ciudades;
	while ((rit!=temperaturasDia.rend()) &&
			(temperaturaMaxima==(rit->first))) {
		ciudades.push_back(rit->second);
		++rit;
	}
	std::sort(ciudades.begin(),ciudades.end());

	//Ordeno ciudades que verifican
	std::string resultadoFinal;
	for (std::vector<std::string>::iterator it = ciudades.begin();
			it != ciudades.end(); ++it) {
		if (it != ciudades.begin()) resultadoFinal.append("/");
		resultadoFinal.append(*it);
	}

	//Agrego temperatura al resultado
	resultadoFinal.append(" (");
	resultadoFinal.append(numeroATexto(temperaturaMaxima));
	resultadoFinal.append(")");

	//Guardo el resultado
	resultado = resultadoFinal;
}

Reducer::~Reducer() {
}

