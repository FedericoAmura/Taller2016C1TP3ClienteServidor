//============================================================================
// Name        : client_main.cpp
// Author      : Freddy
// Version     :
// Copyright   : Do not copy
// Description : MapReduce mapper
//============================================================================

#include <iostream>
#include <syslog.h>
#include <string>

#include "client_ServerProxy.h"

#define EXIT_CODE 0
#define CODE_SEPARADOR_CAMPOS ' '
#define CODE_SEPARADOR_LINEAS "\n";
#define CODE_SERVER_EOF "End\n"

int main_client(int argc, char *argv[]) try {
	//error si me llaman sin 2 argumentos
	if (argc != 3) {
		std::cout << "ERROR: argumentos\n";
		return EXIT_CODE;
	}

	//consigo referencia al server o exception
	std::string ip = argv[1];
	std::string puerto = argv[2];
	ServerProxy server = ServerProxy(ip, puerto);

	std::string linea;
	char otroValor = CODE_SEPARADOR_CAMPOS;
	std::string nuevaEntrada = CODE_SEPARADOR_LINEAS;

	while (std::getline(std::cin, linea)) {
		if (linea.length() == 0) continue;
		int primerEspacio = linea.find(otroValor);
		int segundoEspacio = linea.find(otroValor, primerEspacio+1);

		std::string nombreCiudad = linea.substr(0,primerEspacio);
		std::string temperatura = linea.substr(primerEspacio+1,
				segundoEspacio-primerEspacio-1);
		std::string diaDeMarzo = linea.substr(segundoEspacio+1);

		std::string mensaje = diaDeMarzo + otroValor + temperatura + otroValor
				+ nombreCiudad + nuevaEntrada;
		server.enviar(mensaje);
	}

	server.enviar(CODE_SERVER_EOF);

	return EXIT_CODE;
} catch (const std::exception &e) {
	syslog(LOG_CRIT, "[Crit] Error!: %s", e.what());
	return 1;
} catch(...) {
	syslog(LOG_CRIT, "[Crit] Unknown error!");
	return 1;
}
