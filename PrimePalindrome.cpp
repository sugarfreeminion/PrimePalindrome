#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;

/* 
 * Function: IsPrime
 * Description: Naive implementation of check for an int being prime
 */
bool IsPrime(int n)
{
	bool isPrime = true;
	
	if(n == 2)
	{
		isPrime = true;
	}
	else if(n == 3)
	{
		isPrime = true;
	}
	else if(n % 2 == 0)
	{
		isPrime = false;
	}
	else if(n % 3 == 0)
	{
		isPrime = false;
	}
	else
	{
		int i = 3;
		int sqrtOfN = sqrt(n);
		
		while(i <= sqrtOfN)
		{
			if(n % i == 0)
			{
				isPrime = false;
			}
			i = i + 2;
		}
	}
	
	return isPrime;
}

bool IsPalindrome(int n)
{
	bool isPalindrome = false;
	
	stringstream ss;
	
	string s;
	
	ss << n;
	
	s = ss.str();
	
	string sReverse(s.rbegin(),s.rend());
	
	if(s.compare(sReverse) == 0)
	{
		isPalindrome = true;
	}
	
	return isPalindrome;
}

int main()
{
	const int MAX = 1000;
	int index = 2;
	int tempMax = 1;
	
	while(index < MAX)
	{
		if(IsPrime(index) == true)
		{
			if(IsPalindrome(index) == true && index > tempMax)
			{
				//cout << "Found: " << index << endl;
				tempMax = index;
			}
		}
		
		++index;
	}
	
	cout << tempMax;
	
	return 0;
}