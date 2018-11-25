#include <iostream>
#include <string>
using namespace std;

void urlify(string &input, int len)
{
	if (input.empty()) return;

	int32_t i = input.size() - 1;
	for (int32_t j = len - 1; j >= 0; --j)
	{
		if (input[j] != ' ')
		{
			input[i] = input[j];
			--i;
		}
		else
		{
			input[i] = '0';
			input[i - 1] = '2';
			input[i - 2] = '%';
			i -= 3;
		}
	}
}

int main()
{
	string input = "Mr John Smith    ";
	urlify(input, 13);
	cout << input << endl;
}