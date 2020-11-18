#include "isMatch.h"

bool Match::isMatch(string s, string p)
{
	string::iterator si = s.begin();
	string::iterator pi = p.begin();
	bool res = true;
	while (si!=s.end())
	{
		if (*si == *pi)
		{
			si++;
			pi++;
			if (pi == p.end() && si != s.end())
			{
				res = false;
				break;
			}
			continue;
		}
		else if (*pi == '*')
		{
				if (*(pi - 1) == *si)
				{
					si++;
					continue;
				}
				else if (*(pi - 1) == '.')
				{
					si++;
					continue;
				}
				else 
				{
					pi++;
					if (pi == p.end()&&si!=s.end())
					{
						res = false;
						break;
					}
					continue;
				}
		}
		else if (*pi == '.')
		{
				si++;
				pi++;
				if (pi == p.end() && si != s.end())
				{
					res = false;
					break;
				}
				continue;
		}
		else if ((pi + 1) != p.end() && (*pi == '*'))
		{

		}
		else
		{
			res = false;
			break;
		}

	}

	cout << s << " " << (res ? "true" : "false") << endl;
	return res;
}
