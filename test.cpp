#define _CRT_SECURE_NO_WARNINGS   1

#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool Test(string a)
{
	stack<char>st;
	stack<char>stt;
	for (int i = 0; i < a.size(); i++)
	{
		stt.push(a[i]);
		switch (a[i])
		{
		case '(':
			st.push(a[i]);
			break;
		case '{':
			st.push(a[i]);
			break;
		case '[':
			st.push(a[i]);
			break;
		case ')':
			if (st.top() == '(')
			{
				stt.pop();
				stt.pop();
				st.pop();
			}
			else
			{
				return false;
			}
			break;
		case '}':
			if (st.top() == '{')
			{
				stt.pop();
				stt.pop();
				st.pop();
			}
			else
			{
				return false;
			}
			break;
		case ']':
			if (st.top() == '[')
			{
				stt.pop();
				stt.pop();
				st.pop();
			}
			else
			{
				return false;
			}
			break;
		}
	}
	if (stt.empty())
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	string a;
	int input;
	do
	{
		cin >> a;
		if (Test(a))
		{
			cout << "Æ¥Åä\n";
		}
		else
		{
			cout << "²»Æ¥Åä\n";
		}
		cout << "0 ÍË³ö  1 ¼ÌÐø\n";
		cin >> input;
	} while (input);
	return 0;
}