#include <iostream>                                                                  
#include <map>                                                                       
#include <string>                                                                    
#include "classbuild.h"                                               

using namespace std;

void Player::regstatus()
{
	string answer;
	cout << "Is the player registered? (Y/N)\n";
	cin >> answer;
	if (answer.substr(0) == "Y" || answer.substr(0) == "y")
	{
		reg_status = true;
	}
}

void Player::IsInUx(const int& season_yr)                               
{
	if (((season_yr - YoB) < 6) && ((season_yr - YoB) >= 4))
	{
		Ux = "U6";
	}
	if (((season_yr - YoB) < 8) && ((season_yr - YoB) >= 6))
	{
		Ux = "U8";
	}
	if (((season_yr - YoB) < 10) && ((season_yr - YoB) >= 8))
	{
		Ux = "U10";
	}
	if (((season_yr - YoB) < 12) && ((season_yr - YoB) >= 10))
	{
		Ux = "U12";
	}
	if (((season_yr - YoB) < 14) && ((season_yr - YoB) >= 12))
	{
		Ux = "U14";
	}
	if (((season_yr - YoB) < 17) && ((season_yr - YoB) >= 14))
	{
		Ux = "U17";
	}
	if ((season_yr - YoB) >= 17)
	{
		cout << "Error: Birth year doesn't match season requirements." << endl;
	}
}