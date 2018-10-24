/*
 * Pool.h
 *
 *  Created on: 19 oct. 2018
 *      Author: 3415857, 3672717
 */

#ifndef POOL_H_
#define POOL_H_

#include<thread>
#include<iostream>
#include<vector>

#include "JobConcret.h"
#include "Queue.h"

namespace pr{

class Pool{

	pr::Queue<Job> jobQueue;
	std::vector<std::thread> threadTab;

public:
	Pool(size_t taille){
		jobQueue = pr::Queue(taille);
		threadTab = std::vector();
	}
	~Pool(){
	}
};
}



#endif /* POOL_H_ */
