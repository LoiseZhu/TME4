/*
 * JobConcret.h
 *
 *  Created on: 19 oct. 2018
 *      Author: 3415857, 3672717
 */

#ifndef JOBCONCRET_H_
#define JOBCONCRET_H_

#include "Job.h"
#include "Barrier.h"
#include <iostream>
#include <thread>

namespace pr{
class JobConcret:public Job{
	int * result;
	int argument;
	Barrier* b;

public:
	JobConcret(int arg, int* res,Barrier* barr): result(res),argument(arg),b(barr){}
	~JobConcret(){
	}
	void run(){
		std::cout<<"début sur args = "<<argument<<std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
		*result = argument%256;
		std::cout<<"fini sur arg = " << argument << " res vaut "<<(*result)<< std::endl;
		b->done();
	}
};
}



#endif /* JOBCONCRET_H_ */
