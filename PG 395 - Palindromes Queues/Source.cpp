#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include <cctype>
#include <cassert>

using namespace std;

void stk_read(stack<char>& s, char w);
void qu_read(queue<char>& q, char w);

bool compare(stack<char>& s, queue<char>& q);

int main()
{
	stack<char> s;
	queue<char> q;

	char word;

	cout << "Enter palindrome: " << endl;

	while (cin.peek() != '\n')	//peek is member function in iostream
	{
		cin >> word;

		if (isalpha(word))
		{
			stk_read(s, word);
			qu_read(q, word);
		}
	}
	
	if (compare(s, q) == true)
	{
		cout << "This is a palindrome" << endl;
	}
	else if (compare(s, q) == false)
		cout << "This is NOT a palindrome" << endl;

	return 0;
}

void stk_read(stack<char>& s, char w)
{
	/*
	toupper(w);		//These two lines don't work
	s.push(w);		//they need to be together like next line to capitalize and push onto stack
	*/
	s.push(toupper(w));
}

void qu_read(queue<char>& q, char w)
{
	/*
	toupper(w);		//These two lines don't work
	q.push(w);		//they need to be together like next line to capitalize and push onto queue
	*/
	q.push(toupper(w));
}

bool compare(stack<char>& s, queue<char>& q)
{
	int match = 0;
	while (!s.empty() && !q.empty())
	{
		if (s.top() == q.front())
		{
			++match;
		}
		else
			return false;
		s.pop();
		q.pop();
	}

	if (match != 0)
		return true;
}

/*
while (cin >> word && isalpha(word) && cin.peek() != '\n')
{
	stk_read(s, word);
	qu_read(q, word);
}
*/