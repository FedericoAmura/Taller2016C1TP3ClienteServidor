/*
 * Thread.h
 *
 *  Created on: Apr 3, 2016
 *      Author: freddy
 */

#ifndef SERVER_THREAD_H_
#define SERVER_THREAD_H_

#include <pthread.h>

class Thread {
private:
	pthread_t thread;

	static void *runner(void *data){
        Thread *self = (Thread*)data;
        self->run();
        return NULL;
    }

public:
	Thread();

	void start();

	void join();

	virtual void run() = 0;

	virtual ~Thread();

private:
	Thread(const Thread&);
	Thread& operator=(const Thread&);
};

#endif /* SERVER_THREAD_H_ */
