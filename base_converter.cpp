#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <ctype.h>

using namespace std;



string IntToChar(int rem)
{
	int array[7] = {10,11,12,13,14,15,16};
	string Carray = "ABCDEFG";
	string m = "";
	for (int i = 0; i<7; i++)
	{
		if(rem == array[i])
		{
			m += Carray[i];	
			return m;
		}	
	}
	
	return to_string(rem);

}

int CharToInt(string rem)
{
	int array[7] = {10,11,12,13,14,15,16};
	string Carray = "ABCDEFG";

	if(isdigit(rem[0]))
	{
		int num = stoi(rem);
		return num;
	}


	for(int k = 0; k < 1;k++)
	{
		for(int i = 0; i < 7;i++)
		{
			if(rem[k] == Carray[i])
			{
				return array[i];
			}
		}
	}
	return -1;
	
		
}

string BaseTenToN(long long int s, int base)
{
	long long int BaseTen = s;
	int count = 0;
	int i = 0;
	string p = "";	
	if(base <= 10)
	{
		while(BaseTen!=0)
		{
			count = BaseTen	% base;
			p += to_string(count);
			BaseTen = trunc(BaseTen/base);
			i++;
		}
	
		reverse(p.begin(),p.end());
		return p;
	}

	if(base>10)
	{
		string temp;
		while(BaseTen!=0)
		{
			count = BaseTen % base;
			temp = IntToChar(count);
			p += temp;
			BaseTen = trunc(BaseTen/base);
			i++;
		}
	}
	reverse(p.begin(), p.end());
	return p;
} 

string BaseTenCon(string x,int base,int nb)
{
	long long int count = 0;

	if(base <= 10)
	{
		long long int original = stol(x);
		int temp = 1;
		int i = 0;
	
		while(original != 0)	
		{
			temp = original % 10;
			count += pow(base,i) * temp;
			i++;
			original = trunc(original/10);
		
		}
	}
	
	if(base > 10)
	{
		int len = x.length();
		int power = len - 1;
		int CtoI = 0;
		string Ctemp = "";
		for(int i = 0; i < len; i++)
		{
			Ctemp += x[i];
			CtoI = CharToInt(Ctemp);
			count += pow(base,power) * CtoI;
			power = power - 1;
			Ctemp = "";
		}
	
	}	

	return (BaseTenToN(count,nb));
}

int main()
{
	int y,z;
	string x;
	cout << "Enter initial base: ";
	cin >> y;
	cout << "Enter base-" << y << " representation: ";
	cin >> x;
	cout << "Entered desired base: ";
	cin >> z;
	string l = BaseTenCon(x,y,z);
	cout << "Base-" << z << " representation: " << l << endl;
	

	return 0;



}
