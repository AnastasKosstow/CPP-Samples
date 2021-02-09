
#include <iostream>

typedef unsigned long long LONG;

#define NAMEOF(name) #name
#define LOG(func, x) _STD cout<< func << ": " << x << _STD endl;

int Factorial(int n);
int Fibonacci(int n);
LONG sumArrValues(int index, int* arr, int size);

int main()
{
	int x = 5;

	int arr[] = { 1, 2, 3, 4, 5};

	LOG(NAMEOF(Factorial), Factorial(x));
	LOG(NAMEOF(Fibonacci), Fibonacci(x));
	LOG(NAMEOF(sumArrValues), sumArrValues(0, arr, 5));

	return 0;
}
 

int Factorial(int n) {
	return (n > 0)
		? n * Factorial(n - 1)
		: 1;
}


int Fibonacci(int n) {
	return (n > 0)
		? Fibonacci(n - 1) + Fibonacci(n - 2)
		: 1;
}


LONG sumArrValues(int index, int* arr, int size)
{
	if (index == size) 
		return 0;

	return arr[index] + sumArrValues(index + 1, arr, size);
}
