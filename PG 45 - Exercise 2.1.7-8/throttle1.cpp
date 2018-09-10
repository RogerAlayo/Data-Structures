#include <cassert>     // Provides assert
#include "throttle1.h"  // Provides the throttle class definition
using namespace std;   // Allows all Standard Library items to be used

namespace Alayo_2
{
	throttle1::throttle1()
	{
		top_position = 1;
		position = 0;
	}

	throttle1::throttle1(int size)
	{
		assert(size >= 0);
		top_position = size;
		position = 0;
	}

	void throttle1::shift(int amount)
	{
		position += amount;

		if (position > top_position)
			position = top_position;
		else if (position < 0)
			position = 0;
	}
}