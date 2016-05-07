/*
 * Mutex.h
 *
 *  Created on: Apr 3, 2016
 *      Author: freddy
 */

#ifndef SERVER_MUTEX_H_
#define SERVER_MUTEX_H_

#include <pthread.h>

class Mutex {
private:
pthread_mutex_t mutex;

public:
	Mutex();

	//para trabar un mutex
	void lock();

	//para destrabar un mutex
	void unlock();

	~Mutex();

private:
	Mutex(const Mutex&);
	Mutex& operator=(const Mutex&);
};

#endif /* SERVER_MUTEX_H_ */
