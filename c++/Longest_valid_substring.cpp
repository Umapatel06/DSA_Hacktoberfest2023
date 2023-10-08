#include <bits/stdc++.h>
using namespace std;

int findMaxLen(string str)
{
	int n = str.length();

	// Create a stack and push -1 as 
	// initial index to it.
	stack<int> stk;
	stk.push(-1);


	int result = 0;

	// Traverse all characters of given string
	for (int i = 0; i < n; i++)
	{
		// If opening bracket, push index of it
		if (str[i] == '(')
			stk.push(i);
		
		// If closing bracket, i.e.,str[i] = ')'
		else
		{
			// Pop the previous opening
			// bracket's index
			if (!stk.empty()) 
			{
				stk.pop();
			}
			
			
			if (!stk.empty())
				result = max(result, i - stk.top());

			
			else
				stk.push(i);
		}
	}

	return result;
}



