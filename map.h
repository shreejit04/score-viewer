#include <iostream>                                                                  
#include <map>                                                                       
#include <fstream> 
#include <vector> 

#include "classbuild.h"                                                                 

class Maps
{
public:

	void input_pair(std::istream& in);
	void output();
	std::map<std::string, Player> copymap()
	{
		std::map<std::string, Player> m1;
		m1 = m;
		return(m1);
	}
	int getseasonyr();
	void begin_new_season();
	void next(std::vector<Player>::iterator position);
	void prev(std::vector<Player>::iterator position);
	bool open();
	void maindisplay();
	void searchdisplay(int number, std::vector<Player>::iterator pos, std::vector<Player> a);
	std::vector<Player> search_map();
	void erase();
	void replace(const Player& player);
	bool save();
	void search_print();
	bool if__name(Player player, std::string& name);
	bool if__YoB(Player player, int YoB);
	bool if__regstatus(Player player, std::string regstatus);
	bool if__Ux(Player player, std::string& Ux1);
	void main_print();
	void edit(std::vector<Player>::iterator pos);

	std::vector<Player> print_if_map_name(std::map<std::string, Player>::iterator start, std::map<std::string, Player>::iterator stop, std::string lname)
	{
		std::vector<Player> v1;
		for (auto itr = start; itr != stop; itr++)
		{
			if ((itr->second).get_lname() == lname)
			{
				v1.push_back(itr->second);
			}
		}
		return(v1);
	}

	std::vector<Player> print_if_map_year(std::map<std::string, Player>::iterator start, std::map<std::string, Player>::iterator stop, int y)
	{
		std::vector<Player> v1;
		for (auto itr = start; itr != stop; itr++)
		{
			if (((itr->second).getYoB()) == y)
			{
				v1.push_back(itr->second);
			}
		}
		return(v1);
	}

	std::vector<Player> print_if_map_category(std::map<std::string, Player>::iterator start, std::map<std::string, Player>::iterator stop, std::string cat)
	{
		std::vector<Player> v1;
		for (auto itr = start; itr != stop; itr++)
		{
			if ((itr->second).getUx() == cat)
			{
				v1.push_back(itr->second);
			}
		}
		return(v1);
	}

	std::vector<Player> print_if_map_registered(std::map<std::string, Player>::iterator start, std::map<std::string, Player>::iterator stop)
	{
		std::vector<Player> v1;
		for (auto itr = start; itr != stop; itr++)
		{
			if ((itr->second).getreg_status() == "Registered")
			{
				v1.push_back(itr->second);
			}
		}
		return(v1);
	}

	std::vector<Player> print_if_vector_registered(std::vector<Player>::iterator start, std::vector<Player>::iterator stop)
	{
		std::vector<Player> v1;
		for (auto itr = start; itr != stop; itr++)
		{
			if ((*itr).getreg_status() == "Registered")
			{
				v1.push_back(*itr);
			}
		}
		return(v1);
	}

	std::vector<Player> print_if_vector_name(std::vector<Player>::iterator start, std::vector<Player>::iterator stop, std::string lname)
	{
		std::vector<Player> v1;
		for (auto itr = start; itr != stop; itr++)
		{
			if ((*itr).get_lname() == lname)
			{
				v1.push_back(*itr);
			}
		}
		return(v1);
	}

	std::vector<Player> print_if_vector_year(std::vector<Player>::iterator start, std::vector<Player>::iterator stop, int y)
	{
		std::vector<Player> v1;
		for (auto itr = start; itr != stop; itr++)
		{
			if (((*itr).getYoB()) == y)
			{
				v1.push_back(*itr);
			}
		}
		return(v1);
	}

	std::vector<Player> print_if_vector_category(std::vector<Player>::iterator start, std::vector<Player>::iterator stop, std::string cat)
	{
		std::vector<Player> v1;
		for (auto itr = start; itr != stop; itr++)
		{
			if ((*itr).getUx() == cat)
			{
				v1.push_back(*itr);
			}
		}
		return(v1);
	}

	std::vector<Player> v;
	int n = 1;

private:
	std::map<std::string, Player> m; 
	int top_line = 0;
	int pointer_line = 0;
	int height = 5;
	int season_yr;
};