#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <deque>


template <class T, class Cont = std::deque<T>>
class Stack {
	Cont data;
public:
	Stack() {};

	T top() const {
		if (data.empty())
			throw "Incorrect operation";
		return data.back();
	}

	void push(const T& elem) {
		data.push_back(elem);
	}

	void pop() {
		if (data.empty())
			throw "Incorrect operation";
		data.pop_back();
	}

	size_t size() const {
		return data.size();
	}

	bool empty() const {
		return data.empty();
	}
	
	void clear() {
		data.clear();
	}

	
};

#endif



