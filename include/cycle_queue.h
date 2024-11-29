#ifndef QUEUE_H
#define QUEUE_H

#include <deque>

template <class T>
class Queue {
	T* data;
	size_t size;
	size_t cap;
	size_t head_ind;
	size_t tail_ind;

	void repack() {
		T* tmp = new T[2 * cap];
		for (int i = head_ind; i < cap; i++)
			tmp[i - head_ind] = data[i];
		if (tail_ind < head_ind)
			for (int i = cap - head_ind; i <= tail_ind; i++)
				tmp[i] = data[i - cap + head_ind];
		head_ind = 0;
		tail_ind = size - 1;
		delete[] data;
		cap *= 2;
		data = tmp;
	}
	
public:
	Queue(): size(0), cap(9), head_ind(0), tail_ind(-1){
		data = new T[cap];
	}
	
	void push(const T& val) {
		if (size == cap)
			this->repack();
		tail_ind++;
		if (tail_ind >= cap)
			data[tail_ind - cap] = val;
		else
			data[tail_ind] = val;
		size++;
	}

	void pop() {
		if (!empty()) {
			head_ind++;
			size--;
		}
		else
			throw "Incorrect size";

	}

	T first() const {
		if (!empty())
			return data[head_ind];
		else
			throw "Incorrect size";
	}

	T back() const {
		if (!empty())
			return data[tail_ind];
		else
			throw "Incorrect size";
	}

	bool empty() const {
		return size == 0;
	}

	bool full() {
		return size == cap;
	}

	size_t get_size() const {
		return size;
	}

	void clear() {
		size = 0;
		head_ind = 0;
		tail_ind = -1;
		delete[] data;
		data = new T[cap];
	}

	~Queue() { delete[] data; }
};

#endif