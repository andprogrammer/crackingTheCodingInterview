#include <iostream>
#include <stack>
#include <memory>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cassert>
using namespace std;

bool isUnique(const string &input)
{
	if (input.size() > 128) return false;

	size_t inputSize = input.size();
	vector<bool> characters(128);
	for (uint32_t i = 0u; i < inputSize; ++i)
	{
		int characterValue = input[i];
		if (characters[characterValue]) return false;
		characters[characterValue] = true;
	}
	return true;
}
bool isUniqueBitset(const string &input)
{
	if (input.size() > 128) return false;

	bitset<128> bits(0);
	size_t inputSize = input.size();
	for (uint32_t i = 0u; i < inputSize; ++i)
	{
		int characterValue = input[i];
		if (bits.test(characterValue)) return false;
		bits.set(characterValue);
	}
	return true;
}
bool isUniqueNoDataStructure(const string &input)
{
	if (input.size() > 128) return false;

	size_t inputSize = input.size();
	for (uint32_t i = 0u; i < inputSize - 1; ++i)
	{
		for (uint32_t j = i + 1; j < inputSize; ++j)
		{
			if (input[i] == input[j]) return false;
		}
	}
	return true;
}
int main()
{
	assert(!isUniqueNoDataStructure("ala ma kota"));
	assert(isUniqueNoDataStructure(""));
	assert(isUniqueNoDataStructure("abcdef"));

	return 0;
}