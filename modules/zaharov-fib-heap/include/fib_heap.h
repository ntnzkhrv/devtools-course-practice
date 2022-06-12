// Copyright 2022 Zaharov Anton
#ifndef MODULES_ZAHAROV_FIB_HEAP_INCLUDE_FIB_HEAP_H_
#define MODULES_ZAHAROV_FIB_HEAP_INCLUDE_FIB_HEAP_H_
#include <cmath>
#include <vector>
using namespace std;

struct FibHeapNode
{
	int key; 
	FibHeapNode* left;
	FibHeapNode* right;
	FibHeapNode* parent;
	FibHeapNode* child;
	int degree;
	bool mark;
	int id; 
};


class FibHeap {
  public:
	FibHeapNode* m_minNode;
	int m_numOfNodes;

	FibHeap() {  
		m_minNode = nullptr;
		m_numOfNodes = 0;
	}
	~FibHeap() {
		_clear(m_minNode);
	}
	FibHeapNode* insert(int newKey);
	int  extract_min();
	void delete_node(FibHeapNode* x);
  private:
	static const int m_minimumKey;
	FibHeapNode* _create_node(int newKey);
	void _insert_node(FibHeapNode* newNode);
	void _remove_from_circular_list(FibHeapNode* x);
	void _make_child(FibHeapNode* child, FibHeapNode* parent);
	void _consolidate();
	void _unparent_all(FibHeapNode* x);
	FibHeapNode* _extract_min_node();
	void _cut(FibHeapNode* x, FibHeapNode* y);
	void _cascading_cut(FibHeapNode* y);
	FibHeapNode* _merge(FibHeapNode* a, FibHeapNode* b);
	void _decrease_key(FibHeapNode* x, int newKey);
	void _clear(FibHeapNode* x);
};

#endif  // MODULES_ZAHAROV_FIB_HEAP_INCLUDE_FIB_HEAP_H_
