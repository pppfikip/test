#include "pch.h"
#include <iostream>
#include <string> 
#include <math.h>

using namespace std;


long long dec_conv(string ini_num, int bas_sys)
{
	int str_leng = ini_num.length() - 1 ;
	int dec_conv_result = 0;
	int power = 0;

	while (str_leng >= 0)
	{
		if (ini_num[str_leng] < 58)
			dec_conv_result += ( ini_num[str_leng] - 48 ) * pow(bas_sys, power);
		else 
			dec_conv_result += ( ini_num[str_leng] - 55 ) * pow(bas_sys, power);

		str_leng--;
		power++;
		
	}
	
	return dec_conv_result;

}

string final_conv(long long dec, int res_sys)
{
	string final_rev_num;
	
	while (dec > 0)
	{
		if ( dec % res_sys > 9 )
		final_rev_num += dec % res_sys + 55;
		else 
		final_rev_num += dec % res_sys + 48;



		dec /= res_sys;
		
	}

	

	return string ( final_rev_num.rbegin() , final_rev_num.rend() );

}








int main()
{
	string L;
	int b = 0;
	int w = 0;
	int n = 0;

	cin >> n;

	for ( n ; n >= 0 ; n-- )
	{
		cin >> L >> b >> w;
		
		cout << final_conv(dec_conv(L, b), w) << endl;
	
	}


   return 0;

}
