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
#include "Job.h"

namespace pr{

class Pool{
	pr::Queue<Job> jobQueue;
	std::vector<std::thread> threadTab;
	bool endMain=true;

public:
	Pool(size_t taille){
		jobQueue = pr::Queue(taille);
		threadTab = std::vector();
	}
	~Pool(){
	}
	void start(int NBTHREAD){
		threadTab.reserve(NBTHREAD);
		while(endMain){
			for(int i=0; i<NBTHREAD; i++){
				threadTab[i] = std::thread(jobQueue.pop()->run());
			}
		}
		jobQueue.setBlockingPop(false);
		for(int i=0; i<NBTHREAD;i++){
			threadTab[i].join();
		}
	}
	void submit(Job *job){
		jobQueue.push(job);
	}
	void stop(){
		endMain = false;
	}
};
}



#endif /* POOL_H_ */
