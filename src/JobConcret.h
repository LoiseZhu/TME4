/*
 * JobConcret.h
 *
 *  Created on: 19 oct. 2018
 *      Author: 3415857, 3672717
 */

#ifndef JOBCONCRET_H_
#define JOBCONCRET_H_

#include "Job.h"
#include <iostream>
#include <thread>

class JobConcret:public Job{
	int * result;
	int argument;

public:
	JobConcret(int arg):argument(arg), result(){
	}
	~JobConcret(){
	}
	void run(){
		std::cout<<"début sur args = " << argument<<std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
		result = &(argument%256);
		std::cout<<"fini sur arg " << argument << " res vaut "<<*result << std::endl;
	}



};



#endif /* JOBCONCRET_H_ */
