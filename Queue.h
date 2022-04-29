#pragma once
#include "List.h"

class Queue : public List
{
public:
	Queue(int elementCount = LISTSIZE) : List(sizeof(double), elementCount) { };
	~Queue();

	void Put(double);
	double Get();

};

