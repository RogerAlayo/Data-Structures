#ifndef ALAYO_BAG1_H 
#define ALAYO_BAG_H
#include <cstdlib>

namespace ALAYO_1
{
	class bag1
	{ 
	public:
		typedef int value_type;
		typedef std::size_t size_type;
		static const size_type CAPACITY = 30;

		bag1();
		size_type size() const;
		void insert(const value_type& entry);
		size_type count(const value_type& target) const;
		bool erase_one(const value_type& target);
		size_type erase(const value_type& target);
		void operator += (const bag1& addend);

	private:

	};

	bag1 operator +(const bag1& b1, const bag1& b2);
}
#endif
