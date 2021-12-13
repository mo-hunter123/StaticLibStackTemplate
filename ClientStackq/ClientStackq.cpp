


#include "Stack.h"
#include <iostream>
using namespace std; 

int main()
{
    Stack<int>* S = Stack<int>::creator(); 
	for (int i = 0; i <= 3; i++)
	{
		S->push(new int(i)); 
	}
	S->pop(); 
	int* j = S->top(); 
	cout << *j << endl; 

	Stack<int>::garbage(S); 

    //std::cout << "Hello World!\n";
}
