/*
Figure 6.1: Demonstration Program for TEMPLATE FUNCTIONS - 3 QUESTIONS
*/

#include <iostream>	//Provides cout
#include <cassert>	//Provides assert
#include <cstdlib>	//Provides EXIT_SUCCESS
#include <string>	//Provides string class

template <typename Item>
Item maximal(Item a, Item b)
{
	if (a > b)
	{
		return a;
	}
	else
		return b;
}

template <typename Item>
void swap(Item& a, Item& b)	//forgot void and reference(&)
{
	Item temp = a;
	a = b;
	b = temp;
}

template <typename Item, typename SizeType>
std::size_t index_of_maximal(const Item data[], SizeType n)	//forgot const	
{															//Note: return type and local variable is size_t, which is allowed 
	assert(n > 0);

	std::size_t answer = 0;

	for (std::size_t i = 1; std::size_t(i < n); ++i)
	{
		if (data[answer] < data[i])
		{
			answer = i;
		}
	}
		return answer;
}

template <class Item, class SizeType>
void ordered_insert(Item data[], SizeType n, Item entry)
{ 
	
	std::size_t i = 0;

	//Better Algorithm then while and for loop combination below:
	for (i = n; i > 0 && data[i - 1] > entry; --i)
	{
		data[i] = data[i - 1];
	}
	data[i] = entry;

	/*	//?????WAS THE WHILE LOOP A GOOD FIX TO THIS EMPTY LOOP??????? 

	int index = 0;
	for (i = 0; data[i] < n; ++i)
	{
	}
		index = i;
	*/
	/*
	while (data[i] < n)
	{
		++i;
		index = i;
	}

	for (i = n; i >= index; --i)
	{
		data[i+1] = data[i];
	}

	data[index] = entry;
	*/
}

template <typename Item> //do not include const like "typename const Item" in the template prototype 
void compare(const Item& a, const Item& b)	//?????????WHY ARE THERE REFERENCE PARAMETERS IF IM NOT GOING TO CHANGE ANYTHING, AND ONCE I PUT REFERENCE PARAMETERS IN, THEN MY STRINGS, INTS, ARRAYS WONT WORK????????????
{
	if (a == b)
		std::cout << "Those are the same" << std::endl;
	else
		std::cout << "Those are different" << std::endl;
}


int main()
{
	std::string name1("Castor");
	std::string name2("Pollux");
	std::string s1("frijoles");
	std::string s2("beans");

	swap(name1, name2);
	
	const std::size_t SIZE = 5;
	double data[SIZE] = { 1.0, 6.0, 9.0, 11.0};
	double data1[SIZE] = { 1.0, 6.0, 9.0, 11.0 };

	ordered_insert(data, 4, 3.0);		//need EXACT match therefore arguments need to be [], int, double NOT [], int, int

	for (std::size_t i = 0; i < SIZE; ++i)
	{
		if (i == SIZE-1)
		{
			std::cout << data[i] << std::endl;
		}
		else
		{
			std::cout << data[i] << ", ";
		}
	}

	compare(name1, name2);
	compare(10, 10);
	compare(data, data1);		//?????????? HOW DID THIS EXECUTE IF FORMAL PARAMETER DOESN'T HAVE [] TO RECIEVE AN ARRAY OR IT DOESN'T RECIEVE A POINTER
									//ALSO WHY DOES IT ANSWER THAT ITS DIFFERENT - FROM DEBUGGING IT SEEMS LIKE THE FN IS COMAPRING THIER ADDRESSES BUT HOW 
									//IS THAT POSSIBLE IF IT IS NOT RECIEVING A POINTER???????????

	std::cout << index_of_maximal(data, SIZE) << std::endl;
	std::cout << index_of_maximal(data, 5);
	std::cout << '\n' << name1 << std::endl;
	std::cout << "Larger of frijoles and beans: " << maximal(s1, s2) << std::endl;
	std::cout << "Larger of 10 and 20: " << maximal(10, 20) << std::endl;
	std::cout << "It's a large world." << std::endl;

	return EXIT_SUCCESS;
}