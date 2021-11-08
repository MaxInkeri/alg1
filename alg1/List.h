#include <iostream>
#include <vector>
#include <utility>

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
	size_t size = 0; // number of elements in list

	// go to element with specific index and set it as current
	elem* go_to_elem(size_t index) {
		elem* curr = nullptr; // current element
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
		return curr;
	}

	// throw exception if list is empty (e.g. when trying to remove element)
	void require_not_empty() {
		if (isEmpty()) {
			throw out_of_range("List is empty");
		}
	}

	// integers separated by commas processor
	template<typename... IntList>
	void construct_args(int first_number, IntList... numbers) {
		push_back(first_number);
		construct_args(numbers...);
	}

	// integers separated by commas processor - when the last one remain
	void construct_args(int last_number) {
		push_back(last_number);
	}

public:

	// pointer array of int and its size
	List(int* numbers, size_t count) {
		for (unsigned i = 0; i < count; i++) {
			push_back(numbers[i]);
		}
	}

	// integers separated by commas
	template<typename... IntList>
	List(int first_number, IntList... numbers) {
		construct_args(first_number, numbers...);
	}

	// only one integer
	List(int number) {
		push_back(number);
	}

	// default constructor (empty list)
	List() { 
		
	}

	// destructor
	~List() {
		clear();
	}

	// add element into the end of list
	void push_back(int val) {
		elem* curr = new elem;
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
		elem* curr = new elem;
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
		if (size > 1) {
			last = last->prev;
			delete last->next;
			last->next = nullptr;
		}
		else { // list has the only element
			delete first;
			first = nullptr;
		}
		size--;
		return val;
	}

	// get first element and remove it
	int pop_front() {
		require_not_empty();
		int val = first->value;
		if (size > 1) {
			first = first->next;
			first->prev = nullptr;
		}
		else { // list has the only element
			delete first;
			first = nullptr;
		}
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
			elem* curr = go_to_elem(index);
			elem* newElem = new elem;
			newElem->value = val;
			newElem->prev = curr->prev;
			newElem->next = curr;
			curr->prev->next = newElem;
			curr->prev = newElem;
			size++;
		}
	}

	// get element by index
	int at(size_t index) {
		elem* curr = go_to_elem(index);
		return curr->value;
	}

	// get element by index and delete it
	int remove(size_t index) {
		if (index == 0) {
			return pop_front();
		}
		if (index == size - 1) {
			return pop_back();
		}
		elem* curr = go_to_elem(index);
		int val = curr->value;
		curr->prev->next = curr->next;
		curr->next->prev = curr->prev;
		size--;
		return val;
	}

	// get number of elements in list
	size_t get_size() {
		return size;
	}
	
	// remove all elements
	void clear() {
		elem* curr = first;
		while (curr != nullptr) {
			elem* next = curr->next;
			delete curr;
			curr = next;
		}
		first = nullptr;
		size = 0;
	}

	// set value of element at specific index
	void set(size_t index, int val) {
		elem* curr = go_to_elem(index);
		curr->value = val;
	}

	// check if list is empty
	bool isEmpty() {
		return (size == 0);
	}

	// reverse the list
	void reverse() {
		elem* curr = first;
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
