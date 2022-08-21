#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>


using namespace std;


string BaseTenToN(long long int s)
{
	long long int BaseTen = s;
	int count = 0;
	int i = 0;
	string p = "";	
	while(BaseTen!=0)
	{
		count = BaseTen	% 2;
		p += to_string(count);
		BaseTen = trunc(BaseTen/2);
		i++;
	}
	
	reverse(p.begin(),p.end());
	return p;	
} 


string Magnitude(string str,int sign)
{
	string zero = "00000000000000000000000000000000";
	string fin = "";
	int len = str.length();
	int count = 0; 
	string one = "1";

	
	for(int i = 0;i<32;i++)
	{
		
		if(i == (32-len))
		{
			for(int k = i; k<32;k++,count++)
			{
				fin += str[count];
			}
	
			break;
		}

		if((i == 0)&&(sign == 1))
		{
			fin += "1";					
		}
		
		else
		{
			fin += zero[i];
		}
				 
	}

	return fin;

}

string TwoComp(string str,int sign)
{
	string zero = "00000000000000000000000000000000";
	string fin = "";
	int len = str.length();
	int count = 0; 
//	string one = "1";


	for(int i = 0;i<32;i++)
	{
		
		if(i == (32-len))
		{
			for(int k = i; k<32;k++,count++)
			{
				fin += str[count];
			}
	
			break;
		}

		if((i == 0)&&(sign == 1))
		{
			fin += "1";					
		}
		
		else
		{
			fin += zero[i];
		}
				 
	}

	string one = "1";
	string z = "0";
	string pop = "";
	string temp4 = "";
	if(sign == 1)
	{
		pop += one;
		for(int n = 1; n < 32;n++)
		{
			temp4 += fin[n];
			if(strcmp(temp4.c_str(),one.c_str())==0)
			{
				pop += z;
			}
			else
			{
				pop += one;
			}
			temp4 = "";
		}
		string pop2 = "";
		int ct = 0;
		for(int y = 31; y >= 1; y--)
		{
			if(y == 31)
			{
				ct = y;
				temp4 += pop[y];
				if(strcmp(temp4.c_str(),one.c_str())==0)
				{
					while((strcmp(temp4.c_str(),one.c_str())==0) && (ct > 1))
						{
							pop2 += "0";
							--ct;
							temp4 = pop[ct];					
						}
					y = ct;
					pop2+="1";
					
				}
				else
				{
					pop2 += "1";
				}
			}
			else
			{
				pop2 += pop[y];
			}	

		}
		
	pop2 += "1";
 	reverse(pop2.begin(),pop2.end());	
	return pop2;


	}	

	return fin;


}



int main(int argc, char *argv[])

{
	if(argc != 2)
	{
		cerr << "Wrong number of command-line arguments.\n";
		return 1;
	}


	string temp = argv[1];
	int num = stoi(temp);
	int sign = 0;
	string temp3 = "";
	string negative = "-";
	temp3 += temp[0];
	if(strcmp(temp3.c_str(),negative.c_str()) == 0)
	{
		sign = 1;
	}
	num = abs(num);
	string temp2 = BaseTenToN(num);
	cout <<"2's complement: "<< TwoComp(temp2,sign) << endl;
	cout <<"Signed magnitude: "<<  Magnitude(temp2, sign) << endl;
	return 0;


}
