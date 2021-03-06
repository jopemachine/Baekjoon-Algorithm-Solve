#pragma once
#include <memory>

const int ArrayBag_Default_MAX = 100;

template<class T, class Allocator = std::allocator<T>>
class ArrayBag {
public:

	ArrayBag() {
		count = 0;
		capacity = ArrayList_Default_MAX;
		arrayList = allocator->allocate(capacity);
	};

	ArrayBag(int initial_Max) : capacity(initial_Max) {
		count = 0;
		arrayList = allocator->allocate(capacity);
	};

	ArrayBag(const ArrayList& rhs) {
		count = rhs.count;
		capacity = rhs.capacity;
		arrayList = allocator->allocate(capacity);

		for (int i = 0; i < count; i++) {
			arrayList[i] = rhs.arrayList[i];
		}
	};

	~ArrayBag() {
		delete arrayList;
		arrayList = nullptr;
	};

	bool remove(T item) {
		for (int i = 0; i < count; i++) {
			if (arrayList[i] == item) {
				//removeByIndex(i);
				return true;
			}
		}
		return false;
	};

	bool add(T item) {
		arrayList[count++] = item;
		return true;
	};

	bool isContain(T item) {
		return true;
	}

	bool isEmpty() {
		return count == 0;
	};

	int length() {
		return count;
	};

private:

	std::unique_ptr<Allocator> allocator;

	int count;

	int capacity;

	T* arrayList;
};

void ArrayBag_test() {


}