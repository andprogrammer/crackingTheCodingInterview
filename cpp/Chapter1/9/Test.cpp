#include <iostream>
#include <stack>
#include <memory>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
using namespace std;

bool stringRotation(const string &input1, const string &input2)
{
	size_t input1Size = input1.size();
	if (input1Size == 0 || input1Size != input2.size()) return false;

	string concatInput1 = input1 + input1;
	return (concatInput1.find(input2) != string::npos) ? true : false;
}
int main()
{
	cout << boolalpha << stringRotation("waterbottle", "erbottlewat") << endl;	//true
	return 0;
}