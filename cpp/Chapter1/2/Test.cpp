#include <iostream>
#include <stack>
#include <memory>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cassert>
using namespace std;

bool arePermutation(string &input1, string &input2)
{
	size_t input1Size = input1.size();
	size_t input2Size = input2.size();

	if (input1Size != input2Size) return false;

	sort(input1.begin(), input1.end());
	sort(input2.begin(), input2.end());

	for (uint32_t i = 0u; i < input1Size; ++i)
	{
		if (input1[i] != input2[i]) return false;
	}
	return true;
}
bool arePermutationTableSolution(const string &input1, const string &input2)
{
	size_t input1Size = input1.size();
	size_t input2Size = input2.size();

	if (input1Size != input2Size) return false;

	char characters[128] = { 0 };	//256?

	for (uint32_t i = 0u; i < input1Size; ++i)
	{
		int characterValue = input1[i];
		++characters[characterValue];
	}
	for (uint32_t i = 0u; i < input2Size; ++i)
	{
		int characterValue = input2[i];
		if (--characters[characterValue] < 0) return false;
	}
	return true;
}
int main()
{
	cout << boolalpha << arePermutation(string("ala ma kota"), string("kota ma ala")) << endl;
	cout << boolalpha << arePermutation(string(""), string("")) << endl;
	cout << boolalpha << arePermutation(string("abcdef"), string("abcde")) << endl;

	cout << boolalpha << arePermutationTableSolution("ala ma kota", "kota ma ala") << endl;
	cout << boolalpha << arePermutationTableSolution("", "") << endl;
	cout << boolalpha << arePermutationTableSolution("abcdef", "abcde") << endl;

	return 0;
}