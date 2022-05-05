#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <stack>
#include <math.h>
using namespace std;


int prior(char x)
{
	if ((x='*')||(x='/')) return 2;
	if ((x='+')||(x='-')) return 1;
	if ((x='(')||(x=')')) return 0;
}

int calculate_Postfix(string  post_exp)
{
    stack <int> stack;
    int len = post_exp.length();
    for (int i = 0; i < len; i++)
    {
        if ( post_exp[i] >= '0' &&  post_exp[i] <= '9')
        {
            stack.push( post_exp[i] - '0');
        }
        else
        {
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();
            switch (post_exp[i])
            {
                case '+': 
                          stack.push(b + a);
                          break;
                case '-': 
                          stack.push(b - a);
                          break;
                case '*': 
                          stack.push(b * a);
                          break;
                case '/': 
                          stack.push(b / a);
                          break;
                case '^': 
                          stack.push(pow(b,a));
                          break;
            }
        }
    }
    return stack.top();
}






class postfix
{
	int top;
	char body[100];
public :
	postfix(){top=0;}
	bool empty(){return top==0;}
	char get_top_element(){return body[top];}
	int top_prior(){return prior(body[top]);}
	void push(char x)
	{
		top++;
		body[top]=x;
	}
	char pop()
	{
		top--;
		return body[top+1];
	}
	
};






int main()
{
	setlocale(LC_ALL, "Russian");
	char note[100],pnote[100],sign;
	int i,p=0;
	postfix s;
    double result;
    string a, b, c;
    cout << "¬ведите арифметическое выражение с однозначными цифрами: " << endl;
	cin >> note;

	for(i=0;i<strlen(note);i++)
	{
		if (note[i]=='(') s.push(note[i]);
		else if ((note[i]=='+')||(note[i]=='-')||(note[i]=='/')||(note[i]=='*'))
		{
			while((!s.empty())&&(s.top_prior()>prior(note[i])))
			{
				p++;
				pnote[p]=s.pop();
			}
			s.push(note[i]);
		}
		else if(note[i]==')')
		{
			while((!s.empty())&&(s.get_top_element()!='('))
			{
				p++;
				pnote[p]=s.pop();
			}
			s.pop();
		}
		else
		{
			p++;
			pnote[p]=note[i];
		}
	}
	while(!s.empty())
	{
		p++;
		pnote[p]=s.pop();
	}
	string fin;
	for(i=1;i<=p;i++) {
		cout << pnote[i];
		fin += pnote[i];
	}
		
	cout << endl;
	
	cout << calculate_Postfix(fin);
	return 0;
	
	
}


