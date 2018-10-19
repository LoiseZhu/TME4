/*
 * Queue.h
 *
 *  Created on: 19 oct. 2018
 *      Author: 3415857, 3672717
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include <string> //size_t
#include <mutex>
#include <condition_variable>

template <typename T>
class Queue {
	T ** tab;
	const size_t allocsize;
	size_t begin;
	size_t sz;
	mutable std::mutex m;
	std::condition_variable cv_prod;
	std::condition_variable cv_cons;


private:
	bool full() const { return sz==allocsize;}
	bool empty() const { return sz==0;}

public :
	Queue (size_t maxsize) :allocsize(maxsize),begin(0),sz(0) {
		tab = new T* [maxsize];
		memset(tab, 0, maxsize * sizeof(T*));
	}
	size_t size() const {
		return sz;
	}
	T* pop () {
		std::unique_lock<std::mutex> l(m);
		while( empty() ){
			cv_cons.wait(l);
		}

		if(full())
		auto ret = tab[begin];
		tab[begin] = nullptr;
		sz--;
		begin = (begin+1) % allocsize;
		return ret;
	}
	void push (T* elt) {
		std::unique_lock<std::mutex> l(m);
		tab[(begin + sz)%allocsize] = elt;
		sz++;
	}
	~Queue() {
		for (size_t i = 0; i < sz ; i++) {
			auto ind = (begin + i) % allocsize;
			delete tab[ind];
		}
		delete[] tab;
	}
};

#endif /* QUEUE_H_ */
