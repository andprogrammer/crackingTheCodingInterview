#include <iostream>
#include <stack>
#include <memory>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
using namespace std;

bool oneAway(const string &input1, const string &input2)
{
	size_t input1Size = input1.size();
	size_t input2Size = input2.size();

	if (abs(static_cast<int>(input1Size - input2Size)) > 1) return false;

	string shorterInput = input1Size < input2Size ? input1 : input2;
	string longerInput = input1Size < input2Size ? input2 : input1;

	uint32_t i = 0u;
	uint32_t j = 0u;
	bool oneLetterAlreadyDifferent = false;

	while (i < shorterInput.size() && j < longerInput.size())
	{
		if (shorterInput[i] != longerInput[j])
		{
			if (oneLetterAlreadyDifferent) return false;
			oneLetterAlreadyDifferent = true;
			if (input1Size == input2Size) ++i;
		}
		else ++i;
		++j;
	}
	return true;
}
int main()
{
	cout << boolalpha << oneAway("pale", "ple") << endl;
	cout << oneAway("pales", "pale") << endl;
	cout << oneAway("pale", "bale") << endl;
	cout << oneAway("pale", "bake") << endl;
	return 0;
}