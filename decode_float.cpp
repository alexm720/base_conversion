#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <ctype.h>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

int BaseTenCon(string x)
{
	
	long long int count = 0;

	long long int original = stol(x);
	int temp = 1;
	int i = 0;
	while(original != 0)	
	{
		temp = original % 10;
		count += pow(2,i) * temp;
		i++;
		original = trunc(original/10);
		
	}
	
	return count;
}

double BaseTenToDec(string x)
{
	
	
	string one = "1";
	int i = 0;
	string tem1;
	tem1 += x[i];

	while(strcmp(one.c_str(),tem1.c_str())!=0)
	{
		tem1 = "";
		i += 1;
		tem1 += x[i];
	}
	
	double count = 0;
	int len = x.length()-1;
	string ll;
	float temp2 = 0;
	for(;i<len;i++)
	{
		ll += x[i];
		temp2 = stoi(ll);
		count += (1/(pow(2,i+1))) *temp2;
		ll = "";
	}
	
	return count;


}


int Exponenet(string str)
{
	int ExLen = str.length();
	int n = ExLen-1;
	int ex = pow(2,n)-1; 	
	double sub = BaseTenCon(str);
	int ret = sub - ex;
	return ret;
}



float Mantissa(string str,int ex)
{
	string lead = "1.";
	string full;
	full = lead + str;
	double temp = stod(full);
	long double calc;
	if(ex > 0)
	{
		calc = temp * pow(10,ex);
	}
	else 
	{
		calc = temp * (1/pow(10,abs(ex)));
	}

	full = "";
	int k = 0;
	string temp3 = "";
	if(ex <= -5)
	{

		std::ostringstream temp5;
		temp5 <<fixed<<setprecision(65) << calc;
		temp3 = temp5.str();

	}

	else
	{
		temp3 += to_string(calc);
	}	



	int tl = temp3.length();

	string temp1 = "";
	if(ex>0)
	{
		while(k < tl)
		{
			temp1 += temp3[k];
			full += temp1;
			temp1 = "";
			++k;
		}
	}
	else
	{
		while(k <= tl)
		{
			temp1 += temp3[k];
			full += temp1;
			temp1 = "";
			++k;
		}
	
	}
 
	int len = full.length();
	string tempbin ="";
	int i = 0;
	string temp4 = "";
	temp4 += full[i];
	string dot = ".";
	while(strcmp(temp4.c_str(),dot.c_str())!=0)
	{
		temp4 = "";
		temp4 += full[i];
		tempbin += temp4;
		++i;
		temp4 = "";
		temp4 += full[i];
	}
	i += 1;
	string tempdec = "";

	while(i != len ){
		tempdec += full[i];	
		i++;
		}

	int bd = BaseTenCon(tempbin);
	float ad = BaseTenToDec(tempdec);
	float total = bd + ad;

	return total;	
	
}




int main(int argc, char *argv[])
{
	string OutLine = "";
	int i = 0;
	int SignPos = 0;
	int ManPos = 0;
	int ExpPos = 0;
	int Exp,Man;
	string temp;
	stringstream ManTemp;
	stringstream ExpTemp;
	ifstream file(argv[1]);
	if(file.is_open())
	{
		while(i != 3)
		{
			getline(file,OutLine);

			if(OutLine.find("sign") != std::string::npos)
			{
				SignPos = i;
			}
		
			if(OutLine.find("exp") != std::string::npos)
			{
				ExpPos = i;
				ExpTemp << OutLine;
				while(!ExpTemp.eof())
				{
					ExpTemp >> temp;
					if(stringstream(temp) >> Exp)
					{
						break;
					}
				}
				temp = "";					
			}

			if(OutLine.find("man") != std::string::npos)
			{
				ManPos = i;

				ManTemp << OutLine;
				while(!ManTemp.eof())
				{
					ManTemp >> temp;
					if(stringstream(temp) >> Man)
					{
						break;
					}
				}
				temp = "";
			
			}
	
			i++;

		}	

	}

	string input = "";
	int inLen = input.length();
	
	while(inLen!=(Man+Exp+1))
	{
		cout << "Enter bit string: ";
		cin >> input;
		inLen = input.length();
		if(inLen!=(Man+Exp+1))
		{
			cout << "Wrong number of bits." << endl;
		}
	}

	
	string ManStr = "";
	string ExpStr = "";
	string SignStr = "";
	int c = 0;
	for(int i = 0; i<3;i++)
	{
		if(ExpPos == i)
		{
			for(int z = 0;z<Exp;z++)
			{
				ExpStr += input[c];
				c++;
			}
		}
		if(SignPos == i)
		{
			for(int l = 0; l < 1;l++)
			{
				SignStr += input[c];
				c++;
			}
		}
		if(ManPos == i)
		{
			for(int h = 0; h<Man; h++)
			{
				ManStr += input[c];
				c++;
			}
		}

	}	



	float numb = Exponenet(ExpStr);
	float check = Mantissa(ManStr,numb);
	string ne = "1";
	if(strcmp(ne.c_str(),SignStr.c_str())==0)
	{
		check = -check;
	}

	
	cout << "Value: " << check << endl;	






	return 0;

}
