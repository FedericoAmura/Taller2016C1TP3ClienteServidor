//============================================================================
// Name        : server_main.cpp
// Author      : Freddy
// Version     :
// Copyright   : Do not copy
// Description : MapReduce server, synchronizer and multithread reducer
//============================================================================

#include <iostream>
#include <syslog.h>
#include <vector>

#include "server_MapperListener.h"
#include "server_MapperProxy.h"

#define MAX_MAPPERS 256

using namespace std;

#define EXIT_CODE 0

int main(int argc, char *argv[]) try {
	//error si me llaman sin 1 argumento
	if (argc != 2) {
		std::cout << "ERROR: argumentos\n";
		return EXIT_CODE;
	}

	//consigo el puerto sobre el que funciono
	std::string puerto = argv[1];
	char quit = 's';	//"s" de "start", duh


	std::cout << "Inicializo las estructuras" << std::endl;

	//DataContainer dataCollector (map<dias,maps<temperatura,ciudad> >)
	std::vector<MapperProxy> mappers;
	MapperListener mapperListener(puerto, MAX_MAPPERS);

	mapperListener.start();

	std::cout << "Ingrese una 'q' para terminar la recepcion de datos desde los mappers." << std::endl;
	while (quit != 'q') {
		std::cin >> quit;
	}

	std::cout << "Inicializo los reducers" << std::endl;
	//join a todos los mappers
	//std::vector<Reducers> reducers;
	//todos los reducers->start()
	std::cout << "Saliendoooooooooo" << std::endl;

	return EXIT_CODE;
} catch (const std::exception &e) {
	syslog(LOG_CRIT, "[Crit] Error!: %s", e.what());
	return 1;

} catch(...) {
	syslog(LOG_CRIT, "[Crit] Unknown error!");
	return 1;

}
