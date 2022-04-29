// #include "stdafx.h"
#include "Segment.h"
#include "Allocator.h" 
#include <exception>

using namespace std;


Allocator& Allocator::Instance(int segmentSize)
{
	static Allocator _instance(segmentSize);
	return _instance;
}

Allocator::Allocator(int segmentSize)
{
	this->segmentSize = segmentSize;

	this->current = nullptr; // :)
	this->current = MakeSegment();
}

Allocator::~Allocator(void)
{
	DeleteSegments();
	current = nullptr;
}

void* Allocator::GetMemory(int size)
{
	if (size > this->segmentSize || size < 0)
	{
		throw new bad_alloc();
	}

	Segment* i = current;

	while (i)
	{
		void* newBlock = i->PushBlock(size);

		if (newBlock != nullptr)
			return newBlock;

		i = i->prev;
	}

	try
	{
		i = MakeSegment();
	}
	catch (std::bad_alloc e)
	{
		throw new bad_alloc;
	}
	i->PushBlock(size);

	return i;
}

void Allocator::FreeMemory(void* offset)
{
	current->RemoveBlock(offset); //@
}

void Allocator::FreeMemory(Segment* segment)
{
	Segment* i = current;
	Segment* prev = nullptr;
	while (i != segment)
	{
		prev = i;
		i = i->prev;
	}
	delete i;
	if (prev) prev->prev = i->prev;
}

Segment* Allocator::MakeSegment()
{
	Segment* temp = new Segment(current, segmentSize);
	current = temp;

	return current;
}

void Allocator::DeleteSegments()
{
	Segment* i = current;

	while (i)
	{
		Segment* temp = i;
		i = i->prev;
		delete temp;
	}

}
