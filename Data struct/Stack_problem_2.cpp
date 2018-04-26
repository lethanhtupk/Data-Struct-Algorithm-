// chương trình chuyển từ biểu thứ infix sang postfix 
#include<iostream>
#include<stack>
#include<string>
using namespace  std;
// hàm chuyển đổi infix sang postfix 
string InfixToPostFix(string str);
// hàm kiểm tra toán hạng
bool IsOperand(char c);
// hàm kiểm tra toán tử  
bool IsOperator(char c);
bool Uutien(char op1, char op2);
int main()
{
	
	string str;
	cout << "\nNhap biet thuc = ";
	getline(cin, str);
	string postfix =InfixToPostFix(str);
	cout << postfix;
	system("pause");
	return 0;
}
string InfixToPostFix(string str)
{
	string postfix;
	stack <char> S;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ' || str[i] == ',') continue;
		else if (IsOperand(str[i]))
			postfix += str[i];
		else if (IsOperator(str[i]))
		{
			// nếu toán tử đầu vào có độ ưu tiên cao hơn -> pop các toán tử trong stack ra và push toán tử này vào 
			while (!S.empty() && S.top() != '(' && Uutien(S.top(), str[i]))
			{
				postfix  += S.top();
				S.pop();
			}
			S.push(str[i]);
		}
		// nếu gặp dấu mở ngoặc -> push vào stack 
		else if (str[i] == '(')
			S.push(str[i]);
		 // gặp dấu đóng ngoặc -> pop các phần tử trong stack đến khi gặp dấu mở ngoặc 
		else if(str[i] == ')')
		{
			while (!S.empty() && S.top() != '(')
			{
				postfix += S.top();
				S.pop();
			}
			S.pop();
		}
	}
	// output toàn bộ phần tử trong stack 
	while (!S.empty())
	{
		postfix += S.top();
		S.pop();
	}
	return postfix;
}
bool IsOperand(char c)
{
	if (c >= '0' && c <= '9') return true;
	if (c >= 'a' && c <= 'z') return true;
	if (c >= 'A' && c <= 'Z') return true;
	return false;
}

// hàm kiểm tra toán hạng 
bool IsOperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
		return true;
	return false;
}
int priority(char c)
{
	if (c == '^')
		return 3;
	else if (c == '*' || c == '/')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
}
bool Uutien(char op1, char op2)
{
	if (priority(op1) >= priority(op2))
		return true;
	else
		return false;
}
