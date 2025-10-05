// Author: John Fahriddinov
// CECS 325-02
// Due 09/04/2025

#include <iostream>
#include <string>
using namespace std;


int fibo(int n)
{
	if(n == 0 || n == 1)
	{
		return 1;
	}
	else 
	{
		return fibo(n - 1) + fibo(n - 2);
	}
}


int main()
{
	cout << "Who are you, stranger? ";
	string name;
	cin >> name;
	cout << "What number are you thinking of? ";
	int num;
	cin >> num;
	if(num % 2 == 0)
	{
		cout << "Your number is even" << endl;
	} else {
		cout << "Your number is odd" << endl;
	}
	
	for(int i = 0; i <= 20; i++){
		cout << i << ": " << fibo(i) << endl;
	}

	return 0;	
}
