/*
 * Barrier.h
 *
 *  Created on: Oct 25, 2018
 *      Author: kyungttaek
 */

#ifndef BARRIER_H_
#define BARRIER_H_

#include <iostream>

#include "Pool.h"


class Barrier{
	size_t N;
	size_t count;
	pr::Pool pool;

public:
	Barrier(size_t nbWork, pr::Pool p):N(nbWork),count(0), pool(p){}
	~Barrier(){}
	void done(){
		count++;
		if(count == N)
			waitFor();
	}
	void waitFor(){
		pool.stop();
	}
};

#endif /* BARRIER_H_ */
