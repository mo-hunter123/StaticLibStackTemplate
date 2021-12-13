#pragma once
#include "pch.h"
#include <assert.h>
#include <iostream>
using namespace std; 

template <class T>
class Node
{
private:
	T* data;
	Node<T>* next;

public:
	//on veut juste la class stack soit accessible pour la classe Node alors on va la declarer friend 
	friend class Stack<T>;

};

template <class T>
class Stack
{
public:
	void push(T* E); // chaque element de la pile ce n'est qu'un pointeur vers l'element 
	void pop(); 
	bool empty() const; 

	T* top() const;
	static Stack<T>* creator(); //methode aui permet la creation des instances comme on a les constructeur declares prive 
	static void garbage(Stack<T> *S);

private:
	//l'elemtn de la pile est une classe 
	class Node<T> *head; //on va declarer la classe a l'interieur (vrapee a l'interieur de class stack)
	Stack();
	~Stack(); // distructeur prive 

};


template<class T>
void Stack<T>::push(T* E)
{
	Node<T>* newNode = new Node();
	assert(newNode != 0); // mode debuggage
	//try catch // mode release 
	newNode->data = E;

	newNode->next = this->head;
	this->head = newNode;
}

template <class T>
void Stack<T>::pop()
{
	assert(!this->empty());
	Node<T>* supp = this->head;
	this->head = this->head->next;

	delete supp;

	supp = NULL;
}

template <class T>
bool Stack<T>::empty() const
{
	return (this->head == 0);
}

template <class T>
T* Stack<T>::top() const
{
	assert(!this->empty());
	return this->head->data;
}

template<class T>
Stack<T>* Stack<T>::creator()
{
	Algo::Stack<T>* s = new Stack();
	assert(s);
	return s;
}



template <class T>
void Stack<T>::garbage(Stack<T>* S)
{
	//objest pointe par S 
	if (S)
		delete(S); // methode statique permet l'acces au distructeur prive 
}
template <class T>
Stack<T>::~Stack()
{
	while (this->head)
		this->pop();

	//delete this->head; 
	//this->head = nullptr; 
}

template <class T>
Stack<T>::Stack() {
	this->head = nullptr;
}