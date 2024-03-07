#include <iostream>                                                                  
#include <map>                                                                                                                                
#include <fstream>                                                                   
#include "map.h"

using namespace std;

bool Maps::save()                                         
{                                                                             
	ofstream out;
	out.open("player.txt");
	if (out.fail())
		return true;         
	for (typename std::map<string, Player>::iterator itr = m.begin(); itr != m.end(); itr++)
	{
		cout << itr->first << " ";               
		Player player = (itr->second);
		player.getYoB(); player.getUx(); player.getreg_status();
		return false;
	}
	return true;
}

void Maps::search_print()
{
	ofstream out;
	out.open("player.txt");
	if (!out)
	{
		cout << "Error" << endl;
		return;
	}

	for (Player i : v)
	{
		out << i.get_fname() + i.get_lname() + i.getreg_status() + i.getUx();
	}
	out.close();
}

void Maps::input_pair(istream& in)
{
	Player player;
	string lname;
	string fname;
	int YoB = 0;

	cout << "First name: ";
	player.inputfname();
	cout << "Last name: ";
	player.inputlname();
	cout << "Input year of birth (w/n 17 years of the season)\n";
	player.inputYoB();
	player.regstatus();
	cout << "Season year: \n";
	cin >> season_yr;
	player.IsInUx(season_yr);
	m.insert(pair <string, Player>(player.get_lname() + " " + player.get_fname(), player));

}

std::vector<Player> Maps::search_map() {
	int YearBorn;
	string category;
	string registered;
	string lname;
	bool cont = true;

	cout << "Search by Name (n), Category (c), Year of birth (y), or Registration (r)\n";
	char a;
	cin >> a;

	if (a == 'n') {
		cout << "Input Last Name\n";
		cin >> lname;
		map<std::string, Player> m1 = m;
		print_if_map_name(m1.begin(), m1.end(), lname);
		while (cont)
		{
			cout << "Search by Category (c), Name (n), Registration (r), Display (d)\n" << endl;
			cin >> a;
			switch (a) {
			case 'c':
				cin >> category;
				v = print_if_vector_category(v.begin(), v.end(), category);
				break;
			case 'y':
				cin >> YearBorn;
				v = print_if_vector_year(v.begin(), v.end(), YearBorn);
				break;
			case 'r':
				v = print_if_vector_registered(v.begin(), v.end());
				break;
			case 'd':
				cont = false;
				break;
			default:
				break;
			}
		}
	}
	if (a == 'y')
	{
		cin >> YearBorn;

		v = print_if_map_year(m.begin(), m.end(), YearBorn);
		while (cont)
		{
			cout << "Search by Category (c), Name (n), Registration (r), Display (d)\n" << endl;
			cin >> a;
			switch (a) {
			case 'c':
				cin >> category;
				v = print_if_vector_category(v.begin(), v.end(), category);
				break;
			case 'n':
				cout << "Insert Last Name: ";
				cin >> lname;
				v = print_if_vector_name(v.begin(), v.end(), lname);
				break;
			case 'r':
				v = print_if_vector_registered(v.begin(), v.end());
				break;
			case 'd':
				cont = false;
				break;
			default:
				break;
			}
		}
	}
	if (a == 'c')
	{
		cin >> category;
		v = print_if_map_category(m.begin(), m.end(), category);
		while (cont)
		{
			cout << "Search by Category (c), Name (n), Registration (r), Display (d)\n" << endl;
			cin >> a;
			switch (a) {
			case 'c':
				cin >> category;
				v = print_if_vector_category(v.begin(), v.end(), category);
				break;
			case 'n':
				cout << "Insert Last Name: ";
				cin >> lname;
				v = print_if_vector_name(v.begin(), v.end(), lname);
				break;
			case 'r':
				v = print_if_vector_registered(v.begin(), v.end());
				break;
			case 'd':
				cont = false;
				break;
			default:
				break;
			}
		}
	}

	if (a == 'r') {

		map<std::string, Player> m1 = m;
		v = print_if_map_registered(m1.begin(), m1.end());
		while (cont)
		{

		}
	}
	std::vector<Player> v1 = v;
	return (v1);
}

void Maps::maindisplay()
{
	int regcount = 0;
	int unregcount = 0;
	Player player;
	cout << "The number of total players: ";
	cout << m.size() << endl;
	for (auto itr = m.begin(); itr != m.end(); itr++)
	{
		player = (itr->second);
		if (player.getreg_status() == "Registered")
		{
			regcount++;
		}
		else { unregcount++; }
		cout << "Registered: " << regcount << endl;
		cout << "Unregistered: " << unregcount << endl;
	}

}

void Maps::next(std::vector<Player>::iterator pos) {
	if (pos != (v.end() - 1))
	{
		pos++;
	}
	else
	{
		pos = v.begin();
	}

}

void Maps::prev(std::vector<Player>::iterator pos)
{
	if (pos != (v.begin()))
	{
		pos--;
	}
	else
	{
		pos = v.end();
	}
}

void Maps::begin_new_season()
{
	string answer;
	cout << "Would you like to start a new season? (Y/N)\n";
	cin >> answer;
	if (answer.substr(0) == "Y" || answer.substr(0) == "y")
	{
		cout << "What year is this season?\n";
		cin >> season_yr;
		m.clear();
	}
	else return;

}

int Maps::getseasonyr()
{
	return(season_yr);
}

void Maps::main_print()
{
	Player player;
	ofstream out;
	out.open("player.txt");
	if (!out)
	{
		cout << "Error: Could not open file";
	}
	for (auto itr = m.begin(); itr != m.end(); itr++)

	{
		player = (itr->second);
		if (player.getUx() == "U17")
		{
			std::cout << "U17\n" << player.get_fname() + " " + player.get_lname() + " " + player.getreg_status();
		}
		if (player.getUx() == "U14")
		{
			std::cout << "U14\n" << player.get_fname() + " " + player.get_lname() + " " + player.getreg_status();
		}
		if (player.getUx() == "U12")
		{
			std::cout << "U12\n" << player.get_fname() + " " + player.get_lname() + " " + player.getreg_status();
		}
		if (player.getUx() == "U10")
		{
			std::cout << "U10\n" << player.get_fname() + " " + player.get_lname() + " " + player.getreg_status();
		}
		if (player.getUx() == "U8")
		{
			std::cout << "U8\n" << player.get_fname() + " " + player.get_lname() + " " + player.getreg_status();
		}
		if (player.getUx() == "U6")
		{
			std::cout << "U6\n" << player.get_fname() + " " + player.get_lname() + " " + player.getreg_status();
		}
	}

}

void Maps::searchdisplay(int number, std::vector<Player>::iterator pos, std::vector<Player> a)
{
	cout << (*pos).get_fname() << " " << (*pos).get_lname() << " " << (*pos).getreg_status() << endl;
	cout << (*pos).getUx() << endl;
	cout << number << "/" << a.size();
}


void Maps::edit(std::vector<Player>::iterator pos)
{
	cout << "What would you like to edit?\n" << endl;
	cout << "Name (n), Year of Birth (y), Reg Status(r)?\n" << endl;
	char a;
	string name;
	cin >> a;
	if (a == 'n')
	{
		name = (*pos).get_lname();
		(*pos).inputfname(); (*pos).inputlname();
		m.erase(name);
		m.insert(pair <string, Player>((*pos).get_lname() + (*pos).get_fname(), *pos));


	}
	if (a == 'y')
	{
		name = (*pos).get_lname();
		(*pos).inputYoB();
		m.erase(name);
		m.insert(pair <string, Player>((*pos).get_lname() + (*pos).get_fname(), *pos));

	}
	if (a == 'r')
	{
		name = (*pos).get_lname();
		(*pos).regstatus();
		m.erase(name);
		m.insert(pair <string, Player>((*pos).get_lname() + (*pos).get_fname(), *pos));

	}
}