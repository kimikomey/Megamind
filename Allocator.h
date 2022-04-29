#pragma once
#include "Defaults.h"
#include "Segment.h"
//#include "Exceptions.h"

#include <stdio.h>
#include <tchar.h>

class Allocator
{
public:

	~Allocator(void);

	void* GetMemory(int);
	void FreeMemory(void* offset);

	static Allocator& Instance(int segmentSize = SEGMENTSIZE);
private:

	Allocator(int segmentSize = SEGMENTSIZE);

	Segment* MakeSegment();
	void DeleteSegments();

	void FreeMemory(Segment*);

	int segmentSize;
	Segment* current;
};