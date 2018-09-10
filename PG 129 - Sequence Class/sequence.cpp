#include "sequence.h"
#include <cassert>
using namespace std;

namespace Alayo
{
	const sequence::size_type sequence::CAPACITY;

	void sequence::insert(const sequence::value_type& entry)
	{
		assert(used < CAPACITY);

		if (used != 0)
		{
			value_type temp[CAPACITY];

			for (int i = 0; i < current_index - 1; i++)
			{
				temp[i] = data[i];
			}

			temp[current_index] = entry;

			for (int i = current_index; i < used; i++)
			{
				for (int j = current_index + 1; j = used; j++)
				{
					temp[j] = data[i];
				}
			}

			++used;
			
			for (int i = 0; i < used; i++)
			{
				data[i] = temp[i];
			}

		}
		else
		{
			current_index = 0;
			data[current_index] = entry;
		}
	}

	void sequence::attach(const sequence::value_type& entry)
	{
		assert(used < CAPACITY);

		if (used != 0)
		{
			value_type temp[CAPACITY];

			for (int i = current_index; i < used; i++)
			{
				for (int j = current_index + 2; j = used + 1; j++)
				{
					temp[j] = data[i];
				}
			}

			temp[current_index + 1] = entry;

			for (int i = 0; i <= current_index; i++)
			{
				temp[j] = data[i];
			}

			++used;
			++current_index;

			for (int i = 0; i < used; i++)
			{
				data[i] = temp[i];
			}

		}
		else
		{
			current_index = 0;
			data[current_index] = entry;
		}
	}

	void sequence::remove_current()
	{
		assert(used < CAPACITY);

		if (used != 0)
		{
			value_type temp[CAPACITY];

			for (int i = current_index; i < used; i++)
			{
				for (int j = current_index + 2; j = used + 1; j++)
				{
					temp[j] = data[i];
				}
			}

			temp[current_index + 1] = entry;

			for (int i = 0; i <= current_index; i++)
			{
				temp[j] = data[i];
			}

			++used;
			++current_index;

			for (int i = 0; i < used; i++)
			{
				data[i] = temp[i];
			}

		}
		else
		{
			current_index = 0;
			data[current_index] = entry;
		}
	}

	bool sequence::is_item() const
	{
		if(current() < used)
			return true;
		else 
			return false;
	}
}
