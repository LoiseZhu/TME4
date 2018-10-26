/*
 * main_pool.cpp
 *
 *  Created on: Oct 25, 2018
 *      Author: kyungttaek
 */

#include <iostream>

#include "Pool.h"
#include "Barrier.h"
#include "JobConcret.h"
#include "Queue.h"

using namespace pr;
int main(){
	int N =300;
	Pool p(N);
	Barrier b(N);
	p.start(8);
	std::vector<int> results(N,0);
	for(int i=0 ; i<N; i++){
		p.submit(new JobConcret(i, &results[i],&b));
	}
	b.waitFor();
	std::cout << "result " << results[5] << std::endl;//need a loop
}



