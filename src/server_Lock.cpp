/*
 * Lock.cpp
 *
 *  Created on: Apr 3, 2016
 *      Author: freddy
 */

#include "server_Lock.h"

Lock::Lock(Mutex &m) : m(m) {
	m.lock();
}

Lock::~Lock() {
	m.unlock();
}

