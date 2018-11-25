#include <iostream>
#include <stack>
#include <memory>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
using namespace std;

string stringCompression(const string &input)
{
	size_t inputSize = input.size();
	if (inputSize < 2) return input;

	string output;
	uint32_t currentCounter = 1u;

	for (uint32_t i = 1u; i < inputSize; ++i)
	{
		if (input[i] == input[i - 1])
		{
			++currentCounter;
		}
		else
		{
			output += input[i - 1];
			output += to_string(currentCounter);
			currentCounter = 1u;
		}
		if (output.size() > inputSize) return input;
	}
	output += input[inputSize - 1];
	output += to_string(currentCounter);

	return output.size() > inputSize ? input : output;
}
int main()
{
	cout << stringCompression("aabcccccaaa") << endl;	//a2b1c5a3
	cout << stringCompression("aabb") << endl;			//a2b2
	cout << stringCompression("abc") << endl;			//abc
	cout << stringCompression("") << endl;				//
	return 0;
}