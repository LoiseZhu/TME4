/*
 * Barrier.h
 *
 *  Created on: Oct 25, 2018
 *      Author: kyungttaek
 */

#ifndef BARRIER_H_
#define BARRIER_H_

#include <iostream>
#include <mutex>
#include <condition_variable>

#include "Pool.h"


class Barrier{
	size_t N;
	std::mutex m;
	std::condition_variable cv;

public:
	Barrier(size_t nbWork):N(nbWork){}
	~Barrier(){}
	void done(){
		std::unique_lock<std::mutex> l(m);
		N--;
		if(N==0)
			cv.notify_all();
	}
	void waitFor(){
		std::unique_lock<std::mutex> l(m);
		while(N != 0)
			cv.wait(l);
	}
};

#endif /* BARRIER_H_ */
