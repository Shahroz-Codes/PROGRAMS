#include <iostream>
using namespace std;
const int SIZE = 10;

class Stack
{
private:
	int item[SIZE];
	int top;

public:
	Stack() : top(-1) {}
	bool empty() /// stack is empty
	{
		if (top == -1)
			return true;
		else
			return false;
	}
	bool Isfull() // stack is full
	{

		if (top == SIZE - 1)
			return true;
		else
			return false;
	}
	int pop()
	{
		if (empty())
		{
			cout << "stack is empty!\n";
		}
		return item[top--];
	}

	int Stacktop()
	{
		if (empty())
		{
			cout << "stack is empty!\n";
		}
		return item[top];
	}
	void push(int val)
	{
		if (Isfull())
		{
			cout << "stack ids full!\n";
		}
		item[++top] = val;
	}

	void show()
	{
		for (int i = top; i >= 0; i--)
		{
			cout << "value is :" << item[i] << endl;
		}
	}
};
int main()
{
	Stack s;
	s.push(65);
	s.push(12);
	s.push(-12);
	s.push(65);
	s.push(89);
	s.show();
	cout << endl;
	while (!s.empty())
	{
		cout << "the popped value is :" << s.pop() << endl;
	}

	return 0;
}