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
	pr::Pool pool = new pr::Pool(5);
	pool.start(3);
}



