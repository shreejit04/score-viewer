#include <iostream>
#include "map.h"
using namespace std;

int main()
{
	int height;
	char com;
	Maps player_map;
	string target;
	int season_yr;
	string answer;
	vector<Player> v1;
	int n = 1;

	while (true) {
		cout << "add (a)  new-season (b)  quit (q)  search (s)  display (d)  print (p)\n";
		cin >> com;
		cin.get();
		switch (com) {

		case 'b':
			player_map.begin_new_season();
			break;

		case 'a':
			player_map.input_pair(cin);
			break;

		case 'p':
			player_map.main_print();
			break;

		case 'q':
			return 0;
			break;

		case 'd':
			player_map.maindisplay();
			break;

		case 's':
			v1 = player_map.search_map();
			vector<Player>::iterator position;
			position = v1.begin();
			while (true)
			{
				cout << "Next (n)   Previous (p)   Edit (e)   Print (r)   Exit (x)  Stop (s)\n";
				cin >> com;
				switch (com) {

				case 'n':
					player_map.next(position);
					n++;
					if (n >= v1.size())
						n = 1;
					player_map.searchdisplay(n, position, v1);
					break;

				case 'p':
					player_map.prev(position);
					n--;
					if (n == 0)
						n = v1.size();
					player_map.searchdisplay(n, position, v1);
					break;

				case 'e':
					player_map.edit(position);

				case 'r':
					player_map.search_print();
					break;

				case 'x':
					return 0;
					break;
				}
				break;
			}

		}

	}
}
