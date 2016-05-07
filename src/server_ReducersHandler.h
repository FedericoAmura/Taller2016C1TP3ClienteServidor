/*
 * server_ReducersHandler.h
 *
 *  Created on: Apr 24, 2016
 *      Author: freddy
 */

#ifndef SERVER_REDUCERSHANDLER_H_
#define SERVER_REDUCERSHANDLER_H_

#include <string>
#include <vector>

#include "server_Thread.h"
#include "server_DataCollector.h"
#include "server_Reducer.h"

class ReducersHandler : public Thread {
private:
	//Cantidad de dias del mes
	int dias;
	//Referencia a los datos juntados por los mappers
	DataCollector &data;
	//Referencia al vector donde se van a dejar los resultados
	std::vector<std::string> &resultados;
	//Vector donde guardo los reducers
	std::vector<Reducer*> reducers;

public:
	ReducersHandler(int dias, DataCollector &dataCollector,
			std::vector<std::string> &resultados);

	void run();

	virtual ~ReducersHandler();

private:
	//Convierte un numero de cualquier tipo a string (en decimal)
	template <typename T>
	std::string numeroATexto(T numero);
};

#endif /* SERVER_REDUCERSHANDLER_H_ */
