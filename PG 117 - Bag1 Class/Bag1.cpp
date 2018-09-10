#include <algorithm>
#include <cassert>
//#include <cmath>
#include "Bag1.h"
using namespace std;

namespace Alayo_2
{
	const bag::size_type bag::CAPACITY;

	bag::size_type bag::erase(const value_type& target)
	{
		size_type answer = 0;

		for (int i = 0; i < used; ++i)
		{
			if (target == data[i])
			{
				--used;	//not the index so needs to go first because to match index, it needs to be 1 less than the number of items in bag
				data[i] = data[used];
				++answer;
			}
		}

		return answer;
	}

	bool bag::erase_one(const value_type& target)
	{
		bool answer = true;

		for (int i = 0; i < used; ++i)
		{
			if (target == data[i])
			{
				--used;	//not the index so needs to go first because to match index, it needs to be 1 less than the number of items in bag
				data[i] = data[used];
				return answer;
			}
			else
				answer = false;
		}

		return answer;
	}

	void bag::insert(const value_type& entry)
	{
		assert(size() < CAPACITY);	//NOTE: with capacity u don't need scope operator when doing a member function implementation

		data[used] = entry;
		++used;
	}

	void bag::operator+=(const bag & addend)
	{
		assert(size() + addend.size() <= CAPACITY); //fogot = in <=

		copy(addend.data, addend.data + addend.used, data + used);	//forgot data + used

		used += addend.used;
	}

	bag::size_type bag::count(const value_type& target) const
	{
		size_type answer = 0;

		for (int i = 0; i < used; ++i)
		{
			if (target == data[i])
			{
				++answer;
			}
		}

		return answer;
	}

	bag opertor +(const bag& b1, const bag& b2)
	{
		assert(b1.used` + b2.used <= bag::CAPACITY);

		bag answer;

		answer += b1;
		answer += b2;

		return answer;
	}
	
}