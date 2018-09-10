#ifndef ALAYO_BAG_H
#define ALAYO_BAG_H
#include <cstdlib>

namespace Alayo
{
	class sequence
	{
	public:
		typedef double value_type;
		typedef std::size_t size_type;
		static const size_type CAPACITY = 30;

		//CONSTRUCTOR
		sequence() {data[CAPACITY] = NULL; used = 0; current_index = 0; }

		//MUTATOR FUNCTIONS
		void start() { current_index = 0; }
		void advance() { ++current_index; }
		void insert(const value_type& entry);
		void attach(const value_type& entry);
		void remove_current();

		//ACCESSOR FUNCTIONS
		size_type size() const { return used; }
		bool is_item() const;
		value_type current() const { return data[current_index]; }

	private:
		value_type data[CAPACITY];
		size_type used;
		size_type current_index;
	};
}
#endif