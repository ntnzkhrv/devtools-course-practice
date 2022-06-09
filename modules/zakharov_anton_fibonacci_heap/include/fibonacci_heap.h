// Copyright 2022 Zakharov Anton

#ifndef MODULES_ZAKHAROV_ANTON_FIBONACII_HEAP_INCLUDE_FIBONACCI_HEAP_H_
#define MODULES_ZAKHAROV_ANTON_FIBONACII_HEAP_INCLUDE_FIBONACCI_HEAP_H_

#include <iostream>
using namespace std;
template <class V> class FibonacciHeap;
template <class V> struct node {
private:
	node<V>* prev;
	node<V>* next;
	node<V>* child;
	node<V>* parent;
	V value;
	int degree;
	bool marked;
public:
	friend class FibonacciHeap<V>;
	node<V>* getPrev() { return prev; }
	node<V>* getNext() { return next; }
	node<V>* getChild() { return child; }
	node<V>* getParent() { return parent; }
	V getValue() { return value; }
	bool isMarked() { return marked; }

	bool hasChildren() { return child; }
	bool hasParent() { return parent; }
};

template <class V> class FibonacciHeap {
protected:
	node<V>* heap;
public:

	FibonacciHeap() {
		heap = _empty();
	}
	virtual ~FibonacciHeap() {
		if (heap) {
			_deleteAll(heap);
		}
	}
	node<V>* insert(V value) {
		node<V>* ret = _singleton(value);
		heap = _merge(heap, ret);
		return ret;
	}
	void merge(FibonacciHeap& other) {
		heap = _merge(heap, other.heap);
		other.heap = _empty();
	}

	bool isEmpty() {
		return heap == NULL;
	}

private:
	node<V>* _empty() {
		return NULL;
	}

	node<V>* _singleton(V value) {
		node<V>* n = new node<V>;
		n->value = value;
		n->prev = n->next = n;
		n->degree = 0;
		n->marked = false;
		n->child = NULL;
		n->parent = NULL;
		return n;
	}

	node<V>* _merge(node<V>* a, node<V>* b) {
		if (a == NULL)return b;
		if (b == NULL)return a;
		if (a->value > b->value) {
			node<V>* temp = a;
			a = b;
			b = temp;
		}
		node<V>* an = a->next;
		node<V>* bp = b->prev;
		a->next = b;
		b->prev = a;
		an->prev = bp;
		bp->next = an;
		return a;
	}

	void _deleteAll(node<V>* n) {
		if (n != NULL) {
			node<V>* c = n;
			do {
				node<V>* d = c;
				c = c->next;
				_deleteAll(d->child);
				delete d;
			} while (c != n);
		}
	}

	void _addChild(node<V>* parent, node<V>* child) {
		child->prev = child->next = child;
		child->parent = parent;
		parent->degree++;
		parent->child = _merge(parent->child, child);
	}
};

#endif  // MODULES_ZAKHAROV_ANTON_FIBONACII_HEAP_INCLUDE_FIBONACCI_HEAP_H_
