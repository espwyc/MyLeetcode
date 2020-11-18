#include "Atoi2.h"

void Atoi2::RegexDemos()
{
	smatch smres;
	string s = "sa1243acaAAAss3d12";
	regex r1("[0-9]*[a-z]*A{1,2}");
	bool ismatch = regex_match(s, r1);

	cout << (ismatch ? "true" : "false") << endl;

	regex_search(s, smres, r1);
	cout << smres[0] << endl;
	cout << smres[1] << endl;
	cout << smres[2] << endl;

	

	for (string::iterator it = s.begin(); it != s.end(); it++)
	{
		string tmp(it, s.end());
		regex_search(tmp, smres, r1);
		cout << smres[0] << endl;
	}
}

int Atoi2::myAtoi(string s)
{
	int rev = 0;
	regex reg("[ ]*([+-]?[0-9]+).*");
	smatch smres;

	regex_match(s, smres, reg);

	cout <<s<<" :"<< smres[1] << endl;

	string nums = smres[1];
	if (nums.size() != 0)
	{
		bool minusFlag = false;
		for (char c : nums)
		{
			if (c == '+')
			{
				minusFlag = false;
				continue;
			}
			if (c == '-')
			{
				minusFlag = true;
				continue;
			}
			
			if (!minusFlag&&c>='0'&&c<='9')
			{
				if (rev > INT32_MAX / 10 || (rev == INT32_MAX / 10 && (c - '0') > INT32_MAX % 10))
				{
					rev = INT32_MAX;
					break;
				}
				rev = 10 * rev + (c - '0');
			}
			else if(minusFlag&&c >= '0'&&c <= '9')
			{
				rev = rev > 0 ? -rev : rev;
				if (rev < INT32_MIN / 10 || (rev == INT32_MIN / 10 && ('0' - c) < INT32_MIN % 10))
				{
					rev = INT32_MIN;
					break;
				}		
				rev = 10 * rev + ('0' - c);
			}
		}


	}
	else return 0;

	cout << rev << endl;
	return rev;
}
