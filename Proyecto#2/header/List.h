#pragma once
#include "Node.h"
#include <iostream>
using namespace std;

template <typename T>
class List {
private:
	Node<T>* head;

public:
	List();
	~List();
	void addNode(T* value);
	void printNodes();
	void removeNodesByData(T* value);
	Node<T>* getNode();
	bool isEmpty();
};

template<typename T>
List<T>::List() {
	head = nullptr;
}

template <typename T>
List<T>::~List() {
	while (head != nullptr) {
		Node<T>* temp = head;
		head = head->getNext();
		delete temp;
	}
}

template <typename T>


void List<T>::addNode(T* value) {

	Node<T>* newNode = new Node<T>;

	newNode->setData(value);

	if (!isEmpty()) {
		Node<T>* temp = head;
		while (temp->getNext() != nullptr) {
			temp = temp->getNext();
		}
		temp->setNext(newNode);
		newNode->setPrevious(temp);
	}
	else head = newNode;

}

template <typename T>
void List<T>::printNodes() {
	if (!isEmpty()) {
		Node<T>* temp = head;
		while (temp != nullptr) {

			cout << *(temp->getData()) << "\n";
			temp = temp->getNext();
		}
		cout << "\n";
	}
	else cout << "La lista esta vacia, no hay nada para imprimir\n\n";

}

template <typename T>
void List<T>::removeNodesByData(T* value) {

	if (!isEmpty()) {
		Node<T>* temp = head;
		if (*(head->getData()) == *value) { //caso que el valor era en la cabeza
			head = head->getNext();

			if (head != nullptr) head->setPrevious(nullptr);

			delete temp;
		}
		else {
			while (temp->getNext() != nullptr && *(temp->getNext()->getData()) != *value) { //detalle importante para decirle a mime!!! el porqúe getNext va primero
				temp = temp->getNext();
			}

			if (temp->getNext() == nullptr) { //caso en el que no existe el valor por eliminar
				cout << "No existe el valor que desea eliminar\n\n";
			}
			else {
				if (temp->getNext()->getNext() == nullptr) { //si el siguiente del valor por eliminar es nulo es que no hay más nodos
					delete temp->getNext();
					temp->setNext(nullptr);
				}
				else {
					Node<T>* toDelete = temp->getNext();
					temp->setNext(temp->getNext()->getNext());
					temp->getNext()->setPrevious(temp);
					delete toDelete;
				}
			}
		}
	}
	else {
		cout << "No hay nada por eliminar ya que la lista esta vacia\n\n";
	}

}

template<typename T>
Node<T>* List<T>::getNode() {
	return head;
}

template <typename T>
bool List<T>::isEmpty() {
	return head == nullptr;
}