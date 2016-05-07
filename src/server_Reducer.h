/*
 * server_Reducer.h
 *
 *  Created on: Apr 30, 2016
 *      Author: freddy
 */

#ifndef SERVER_REDUCER_H_
#define SERVER_REDUCER_H_

#include <map>
#include <string>

#include "server_Thread.h"
#include "server_DataCollector.h"

class Reducer : public Thread {
private:
	std::string &resultado;
	const std::multimap<int, std::string> temperaturasDia;

public:
	Reducer(std::string &resultado,
			const std::multimap<int, std::string> temperaturas);

	void run();

	virtual ~Reducer();

private:
	//Convierte un numero de cualquier tipo a string (en decimal)
	template <typename T>
	std::string numeroATexto(T numero);
};

#endif /* SERVER_REDUCER_H_ */
