#include <cstdint>
#include "stack.h"
#include "Allocator.h"


//struct Object {
//
//	// Object data, 16 bytes:
//
//	uint64_t data[2];
//
//	// Declare out custom allocator for
//	// the `Object` structure:
//
//	static Allocator allocator;
//
//	static void* operator new(size_t size) {
//		return allocator.Allocate(size);
//	}
//
//	static void operator delete(void* ptr) {
//		return allocator.Free(ptr);
//	}
//};




int main(int argc, char const* argv[]) {
	
	Stack  s(2);
	

	s.Push(3);
	s.Push(4);
	s.Push(5);

	return 0;
};