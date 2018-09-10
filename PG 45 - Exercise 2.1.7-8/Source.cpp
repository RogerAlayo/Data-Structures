#include <iostream>
#include <cstdlib>
#include "throttle1.h"

using namespace std;
using namespace Alayo_2;

int main()
{
	throttle1 a(6);
	a.shift(4);
	cout << "Flow is: " << a.flow() << endl;
	cout << "Is it more than half: " << a.is_half_full() <<  endl;

	return EXIT_SUCCESS;
}