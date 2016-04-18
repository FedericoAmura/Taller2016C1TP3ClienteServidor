//============================================================================
// Name        : TallerTP3.cpp
// Author      : Freddy
// Version     :
// Copyright   : Do not copy
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <syslog.h>

#include "ServerProxy.h"

using namespace std;

#define EXIT_CODE 0
#define CODE_SEPARADOR "\n";
#define CODE_SERVER_EOF "End\n"

int main(int argc, char *argv[]) try {
	//error si me llaman sin 2 argumentos
	if (argc != 3) {
		std::cout << "ERROR: argumentos\n";
		return EXIT_CODE;
	}

	std::string ip = argv[1];
	std::string puerto = argv[2];
	ServerProxy server = ServerProxy(ip, puerto);

	std::string linea;
	std::string separador = CODE_SEPARADOR;


	//leo cada linea y la mando con su separador
	//NombreDeLaCiudadSinEspacios Temperatura DíaDeMarzo\n
	while (std::getline(std::cin, linea)) {
		//hay que cambiar esta linea a algo del estilo
		//DiaDeMarzo Temperatura NombreDeLaCiudad
		server.enviar(linea);
		server.enviar(separador);
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
