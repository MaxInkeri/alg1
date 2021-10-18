#include <iostream>
#include <vector>
#include <cstdarg>
#include <initializer_list>

using namespace std;

class List
{
private:
	struct elem {
		int value = 0;
		elem* prev = nullptr; // previous element
		elem* next = nullptr; // next element
	};

	elem* first = nullptr; // first element
	elem* last = nullptr; // last element
	elem* curr = nullptr; // current element
	size_t size = 0; // number of elements in list

	// go to element with specific index and set it as current
	void go_to_elem(size_t index) {
		if (index >= size) { // exception
			throw out_of_range("Index is out of range");
		}
		else if (index <= size / 2) { // index is closer to the beginning of list
			curr = first;
			for (size_t i = 0; i < index; i++) {
				curr = curr->next;
			}
		}
		else { // index is closer to the end of list
			curr = last;
			for (size_t i = size - 1; i > index; i--) {
				curr = curr->prev;
			}
		}
	}

	// throw exception if list is empty (e.g. when trying to remove element)
	void require_not_empty() {
		if (isEmpty()) {
			throw out_of_range("List is empty");
		}
	}

public:
	// vector of int
	List(vector<int> numbers) {
		if (!numbers.empty()) {
			first = new elem;
			first->value = numbers[0];
			elem* prev = first;
			for (unsigned i = 1; i < numbers.size(); i++) {
				curr = new elem;
				curr->value = numbers[i];
				curr->prev = prev;
				prev->next = curr;
				prev = curr;
			}
			last = prev;
			curr = first;
			size = numbers.size();
		}
	}

	// pointer array of int and its size
	List(int* numbers, size_t count) : List(vector<int>(numbers, numbers + count)) {
		// process like vector
	}

	// initializer list of int
	List(initializer_list<int> numbers) : List(vector<int>(numbers)) {
		// process like vector
	}

	// first count of int, then numbers separated by commas
	List(size_t count, ...) {
		if (count > 0) {
			va_list args;
			va_start(args, count);

			first = new elem;
			first->value = va_arg(args, int);
			elem* prev = first;
			for (unsigned i = 1; i < count; i++) {
				curr = new elem;
				curr->value = va_arg(args, int);
				curr->prev = prev;
				prev->next = curr;
				prev = curr;
				curr = first;
				size = count;
			}
			last = prev;

			va_end(args);
		}
	}

	// default constructor (empty list)
	List() { 
		
	}

	// destructor
	~List() {
		delete first, last, curr;
	}

	// add element into the end of list
	void push_back(int val) {
		curr = new elem;
		curr->value = val;
		if (size == 0) { // if list was empty
			first = curr; // that's the only element
		}
		else {
			last->next = curr;
			curr->prev = last;
		}
		last = curr;
		size++;
	}

	// add element into the beginning of list
	void push_front(int val) {
		curr = new elem;
		curr->value = val;
		if (size == 0) { // if list was empty
			last = curr; // that's the only element
		}
		else {
			first->prev = curr;
			curr->next = first;
		}
		first = curr;
		size++;
	}

	// get last element and remove it
	int pop_back() {
		require_not_empty();
		int val = last->value;
		last = last->prev;
		last->next = nullptr;
		size--;
		return val;
	}

	// get first element and remove it
	int pop_front() {
		require_not_empty();
		int val = first->value;
		first = first->next;
		first->prev = nullptr;
		size--;
		return val;
	}

	// insert new element at specific index
	void insert(size_t index, int val) {
		if (index == 0) {
			push_front(val);
		}
		else if (index == size) {
			push_back(val);
		}
		else {
			go_to_elem(index);
			elem* newElem = new elem;
			newElem->value = val;
			newElem->prev = curr->prev;
			newElem->next = curr;
			curr->prev->next = newElem;
			curr->prev = newElem;
			curr = newElem;
			size++;
		}
	}

	// get element by index
	int at(size_t index) {
		go_to_elem(index);
		return curr->value;
	}

	// get element by index and delete it
	int remove(size_t index) {
		require_not_empty();
		go_to_elem(index);
		int val = curr->value;
		curr->prev->next = curr->next;
		curr->next->prev = curr->prev;
		size--;
		curr = first;
		return val;
	}

	// get number of elements in list
	size_t get_size() {
		return size;
	}
	
	// remove all elements
	void clear() {
		first = nullptr;
		last = nullptr;
		curr = nullptr;
		size = 0;
	}

	// set value of element at specific index
	void set(size_t index, int val) {
		go_to_elem(index);
		curr->value = val;
	}

	// check if list is empty
	bool isEmpty() {
		return (size == 0);
	}

	// reverse the list
	void reverse() {
		curr = first;
		for (size_t i = 0; i < size; i++) {
			// swap next and prev
			elem* temp = curr->next;
			curr->next = curr->prev;
			curr->prev = temp;
			curr = temp; // pass to next element
		}
		// swap the first and the last elements
		elem* temp = first;
		first = last;
		last = temp;
	}

	friend ostream& operator <<(ostream &stream, const List &list) {
		stream << "{  ";
		if (list.size > 0) {
			elem e = *list.first;
			bool skip = true; // skip jumping to next in first passing
			do {
				if (skip) {
					skip = false;
				}
				else {
					e = *e.next;
				}
				stream << e.value << "  ";
			} while (e.next != nullptr);
		}
		stream << "}";
		return stream;
	}
};
