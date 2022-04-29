
#include "List.h"
#include "Defaults.h"

class Deque : public List
{
public:
	Deque(int elementCount = LISTSIZE) : List(sizeof(double), elementCount) { };
	~Deque();

	void Put(double);
	double First();
	double Last();

};

