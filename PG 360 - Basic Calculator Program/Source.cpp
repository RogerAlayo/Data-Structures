// FILE: calc.cxx
// Basic calculator program that takes a fully parenthesized arithmetic
// expression as input, and evaluates the arithmetic expression.
// The purpose is to illustrate a fundamental use of stacks.

#include <cctype>     // Provides isdigit
#include <cstdlib>    // Provides EXIT_SUCCESS
#include <cstring>    // Provides strchr
#include <iostream>   // Provides cout, cin, peek, ignore
#include <stack>      // Provides the stack template class

// PROTOTYPES for functions used by this demonstration program:
double read_and_evaluate(std::istream& ins);
// Precondition: The next line of characters in the istream ins is a fully
// parenthesized arithmetic expression formed from non-negative numbers and
// the four operations + - * /.
// Postcondition: A line has been read from the istream ins, and this line has
// been evaluated as an arithmetic expression. The value of the expression has
// been returned by the function.

void evaluate_stack_tops(std::stack<double>& numbers, std::stack<char>& operations);
// Precondition: The top of the operations stack contains + - * or /, and the
// numbers stack contains at least two numbers.
// Postcondition: The top two numbers have been popped from the number stack,
// and the top operation has been popped from the operation stack. The two
// numbers have been combined using the operation (with the second number
// popped as the left operand). The result of the operation has then been
// pushed back onto the numbers stack.


int main()
{
	double answer;

	std::cout << "Type a fully parenthesized arithmetic expression:" << std::endl;

	answer = read_and_evaluate(std::cin);
	std::cout << "That evaluates to " << answer << std::endl;

	return EXIT_SUCCESS;
}


double read_and_evaluate(std::istream& ins)
// Library facilities used: cstring, iostream, stack
{
	const char RP = ')';
	const char DECIMAL = '.';

	std::stack<double> num;
	std::stack<char> operations;

	double number = 0.0;
	char symbol;

	while (ins && ins.peek() != '\n')
	{
		if (isdigit(ins.peek()) || ins.peek() == DECIMAL)
		{
			ins >> number;
			num.push(number);
		}
		else if ((strchr("+-*/", ins.peek())) != NULL)		//???????? I DONT GET HOW THIS LINE WORKS??????????
		{
			ins >> symbol;
			operations.push(symbol);
		}
		else if (ins.peek() == RP)
		{
			ins.ignore();
			evaluate_stack_tops(num, operations);
		}
		else
			ins.ignore();
	}

	return num.top();
}

void evaluate_stack_tops(std::stack<double>& numbers, std::stack<char>& operations)
// Library facilities used: stack
{
	double num1 = 0.0;
	double num2 = 0.0;
	double answer = 0.0;

	num2 = numbers.top();
	numbers.pop();

	num1 = numbers.top();
	numbers.pop();

	switch (operations.top())
	{
	case '+':
			numbers.push(num1 + num2);
			break;
	case '-':
			numbers.push(num1 - num2);
			break;
	case '*':
			numbers.push(num1 * num2);
			break;
	case '/':
			numbers.push(num1 / num2);
			break;
	}

	operations.pop();
}
