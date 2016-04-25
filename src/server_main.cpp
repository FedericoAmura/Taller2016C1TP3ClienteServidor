//============================================================================
// Name        : server_main.cpp
// Author      : Freddy
// Version     :
// Copyright   : Do not copy
// Description : MapReduce server, synchronizer and multithread reducer
//============================================================================

#define CANT_DIAS_MES 31

#include <iostream>
#include <syslog.h>
#include <vector>

#include "server_DataCollector.h"
#include "server_MappersHandler.h"
#include "server_ReducersHandler.h"

#define MAX_MAPPERS_QUEUE 256

using namespace std;

#define EXIT_CODE 0

int main(int argc, char *argv[]) try {
	//error si me llaman sin 1 argumento (el puerto)
	if (argc != 2) {
		std::cout << "ERROR: argumentos\n";
		return EXIT_CODE;
	}

	//consigo el puerto sobre el que funciono
	const std::string puerto = argv[1];
	char quit = 's';	//"s" de "start", duh

	//Inicializo estructura donde van a estar los datos
	DataCollector dataCollector;
	//Inicializo vector de resultados del proceso
	std::vector<std::string> resultados(CANT_DIAS_MES);

	//Inicializo y arranco el controlador de Mappers
	MappersHandler mappersHandler(dataCollector, puerto, MAX_MAPPERS_QUEUE);
	mappersHandler.start();	//lanzo el receptor de mappers

	//Espero hasta recibir una 'q' para seguir
	std::cout << "Ingrese una 'q' para terminar la recepcion de datos desde los mappers." << std::endl;
	while (quit != 'q') {
		std::cin >> quit;
		sleep(0.1);
	}

	//Finalizo la recepcion de mappers
	mappersHandler.finish();

	//Inicializo, arranco y espero el controlador de reducers
	ReducersHandler reducerHandler(CANT_DIAS_MES, dataCollector, resultados);
	reducerHandler.start();
	reducerHandler.join();

	//Imprimo resultados del proceso
	for (int i = 0; i < CANT_DIAS_MES; i++) {
		std::cout << i << ": " << resultados[i] << std::endl;
	}

	return EXIT_CODE;
} catch (const std::exception &e) {
	syslog(LOG_CRIT, "[Crit] Error!: %s", e.what());
	return 1;

} catch(...) {
	syslog(LOG_CRIT, "[Crit] Unknown error!");
	return 1;

}
