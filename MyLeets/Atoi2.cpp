#include "Atoi2.h"
#include <set>

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
	regex reg("[ ]*([+-]?[0-9]+).*");
	smatch smres;

	regex_match(s, smres, reg);

	//cout <<s<<" :"<< smres[1] << endl;

	//¶Ô

	string nums = smres[1];
	if (nums.size() != 0)
	{

	}
	else return 0;

	return 0;
}
