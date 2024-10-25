#pragma once

template <typename T>
class Node {
private:
	T* data;
	Node<T>* next;
	Node<T>* previous;
public:
	Node() : data(nullptr), next(nullptr), previous(nullptr) {}
	~Node() { delete data; }
	void setData(T* data) { this->data = data; }
	T* getData() { return data; }
	void setNext(Node<T>* next) { this->next = next; }
	Node<T>* getNext() { return next; }
	void setPrevious(Node<T>* previous) { this->previous = previous; }
	Node<T>* getPrevious() { return previous; }

};