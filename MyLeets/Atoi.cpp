#include "Atoi.h"

unordered_map<string, vector<string>> Atoi::stateMap = { 
{"start",{"num","start","symboled","end"}},
{"num",{"num","fin","fin","fin"}},
{"symboled",{"num","end","end","end"}},
{"end",{"end","end","end","end"}},
{"fin",{"fin","fin","fin","fin"}} };

bool Atoi::isNum(char c)
{
	bool res = false;
	if (c >= '0'&&c <= '9')
		res = true;
	return res;
}
bool Atoi::isSymbol(char c)
{
	bool res = false;
	if (c == '+' || c == '-')
		res = true;
	return res;
}
bool Atoi::isSpace(char c)
{
	bool res = false;
	if (c == ' ')
		res = true;
	return res;
}
bool Atoi::isInvalidChar(char c)
{
	bool res = false;
	if (!isNum(c) && !isSymbol(c) && !isSpace(c))
	{
		res = true;
	}
	return res;
}

string Atoi::getNextState(string currentState,char in)
{
	int nextIdx = -1;
	if (isNum(in)) nextIdx = 0;
	else if (isSpace(in)) nextIdx = 1;
	else if (isSymbol(in)) nextIdx = 2;
	else if (isInvalidChar(in)) nextIdx = 3;
	return stateMap[currentState][nextIdx];
}

int Atoi::myAtoi(string s)
{
	int rev = 0;
	string currentState = "start";
	bool minusFlag=false;

	for (char c : s)
	{
		if (currentState == "end"|| currentState == "fin") break;

		if (isNum(c))
		{
			int tmp = c - '0';
			if (!minusFlag)
			{
				if (rev > INT32_MAX / 10 || (rev == INT32_MAX / 10 && tmp > INT32_MAX % 10))
				{
					rev = INT32_MAX;
					currentState = "num";
					break;
				}
			}
			if (minusFlag)
			{
				rev = rev > 0 ? -rev : rev;
				tmp = tmp > 0 ? -tmp : tmp;
				if (rev < INT32_MIN / 10 || (rev == INT32_MIN / 10 && tmp < INT32_MIN % 10))
				{
					rev = INT32_MIN;
					currentState = "num";
					break;
				}
			}

			rev = rev * 10 + tmp;
		}

		currentState = getNextState(currentState, c);

		if(currentState=="symboled")
		{
			if (c == '-')
			{
				minusFlag = true;
			}
		}
	}

	if (currentState == "end")
	{
		//³ö´í
		//cout << 0 << endl;
		//return 0;
		rev = 0;
	}


	cout << rev << endl;
	return rev;
}
