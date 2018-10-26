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

void threadBody(Queue<Job> *queue){
	while(true){
		Job* j = queue->pop();
		if(j == nullptr)
			return;
		j->run();
		delete j;
	}
}

class Pool{
	Queue<Job> jobQueue;
	std::vector<std::thread> threadTab;

public:
	Pool(size_t taille):jobQueue(taille){
	}
	~Pool(){
		jobQueue.~Queue();
	}
	void start(int NBTHREAD){
		for(int i=0; i<NBTHREAD; i++){
			threadTab.emplace_back(std::thread(threadBody,&jobQueue));
		}
	}
	void stop(){
		jobQueue.setBlockingPop(false);
		for(size_t i = 0; i < threadTab.size(); i++){
			threadTab[i].join();
		}
	}
	void submit(JobConcret *job){
		jobQueue.push(job);
	}
	Pool& operator=(Pool newPool){
		return *this;
	}
};
}



#endif /* POOL_H_ */
