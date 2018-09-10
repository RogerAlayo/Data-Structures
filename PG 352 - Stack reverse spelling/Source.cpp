//????????How can I edit code to make int work as well?????????

#include <iostream>
#include <stack>
#include <string>
//#include "stackFns.h"

template<typename Item, typename DataType>
void populate(std::stack<Item>& a, DataType b);

template<typename Item, typename DataType>
void reverse(std::stack<Item> a, DataType& b);

int main()
{
	std::stack<char> stk;	//why isn't it std::char
	std::string word ("ROGER");
	std::string back;

	populate(stk, word);
	reverse(stk, back);

	int exp(12345);
	int rev = 0;
	
	populate(stk, exp);
	reverse(stk, rev);

	std::cout << word << " " << back << std::endl;
	
	return 0;
}

template<typename Item, typename DataType>
void populate(std::stack<Item>& a, DataType b)
{
	for (size_t i = 0; i < b.length(); ++i)
	{
		a.push(b.at(i));
	}
}

template<typename Item, typename DataType>
void reverse(std::stack<Item> a, DataType& b)
{
	while (!a.empty())
	{
		b.push_back(a.top());
		a.pop();
	}
}