/*
 * server_Reducer.cpp
 *
 *  Created on: Apr 30, 2016
 *      Author: freddy
 */

#include <iostream>
#include <map>
#include <string>

#include "server_Reducer.h"

Reducer::Reducer(std::string &resultado, const std::map<std::string, std::string> &temperaturas)
	: resultado(resultado), temperaturasDia(temperaturas) {
}

void Reducer::run() {
	std::cout << "Le damos cuerpo a esto" << std::endl;
}

Reducer::~Reducer() {
}

