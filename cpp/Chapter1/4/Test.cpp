#include <iostream>
#include <stack>
#include <memory>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cassert>
using namespace std;

int getCharIndex(char character)
{
	int index = -1;
	if (character >= 'a' && character <= 'z')
	{
		index = character - 'a';
	}
	else if (character >= 'A' && character <= 'Z')
	{
		index = character - 'A';
	}
	return index;
}
void setFrequency(const string &input, int *frequency)
{
	for (auto i : input)
	{
		int characterIndex = getCharIndex(i);
		if (characterIndex != -1) ++frequency[characterIndex];
	}
}
bool isPalindromePermutation(const string &input)
{
	int frequency[26] = { 0 };
	setFrequency(input, frequency);
	bool oddCharacterAppeared = false;

	for (auto i : frequency)
	{
		bool isOdd = i & 1;
		if (isOdd && !oddCharacterAppeared) oddCharacterAppeared = true;
		else if (isOdd && oddCharacterAppeared) return false;
	}
	return true;
}

bool isPalindromePermutationCounterSolution(const string &input)
{
	char frequency[26] = { 0 };
	int32_t oddCounter = 0;

	for (auto i : input)
	{
		int characterIndex = getCharIndex(i);
		if (characterIndex != -1)
		{
			++frequency[characterIndex];
			bool isOdd = frequency[characterIndex] & 1;
			if (isOdd) ++oddCounter;
			else --oddCounter;
		}
	}
	return oddCounter <= 1;
}
//one more solution on github CTCI with bits
int main()
{
	cout << boolalpha << isPalindromePermutation("Tact Coa") << endl;
	cout << boolalpha << isPalindromePermutation("A big Cat") << endl;
	cout << boolalpha << isPalindromePermutation("Aba cbc") << endl;

	cout << boolalpha << isPalindromePermutationCounterSolution("Tact Coa") << endl;
	cout << boolalpha << isPalindromePermutationCounterSolution("A big Cat") << endl;
	cout << boolalpha << isPalindromePermutationCounterSolution("Aba cbc") << endl;

	return 0;
}