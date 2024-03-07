#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include <string>
#include "map.h"
#include "buffer.h"
using namespace std;

const string long_dash(50, '_');

void Buffer::jump(int l) {
	if (1 > (buff.size() + 1))
		l = (buff.size()) + 1;
	if (1 < 0)
		l = 0;
	top_line = pointer_line = l - 1;
}

void Buffer::down()
{
	if (pointer_line == (buff.size() + 1)) return;
	pointer_line--;
	if (pointer_line < top_line) top_line--;
}

void Buffer::up() {
	if (pointer_line == 0) return;
	pointer_line--;
	if (pointer_line < top_line) top_line--;
}

void Buffer::insert(const string& instring) {
	buff.insert(buff.begin() + pointer_line, instring);
}

void Buffer::replace(const string& rstring) {
	buff[pointer_line] = rstring;
}

void Buffer::erase() {
	buff.erase(buff.begin() + pointer_line);
}

bool Buffer::search(string s) {
	for (int i = top_line; i < buff.size(); i++) {
		if (buff[i].find(s) != string::npos) {
			top_line = 1;
			return 0;
		}
	}
	return 1;
}

void Buffer::next() {
	top_line += height;
	if (top_line > buff.size() - height)
		top_line = buff.size() - height;
}
void Buffer::prev() {
	top_line -= height;
	if (top_line < 0) top_line = 0;
}

bool Buffer::open() {
	string line;
	ifstream instr;
	buff.clear();
	instr.open("player.txt");
	while (getline(instr, line)) buff.push_back(line);
	instr.close();
	strcpy_s(fname, "player.txt");
	return "player.txt";
}

bool Buffer::save() {
	ofstream out;
	out.open("player.txt");
	if (out.fail())
		return true;
	for (string s : buff) out << s << endl;
	out.close();
	return false;
}

void Buffer::display() {
	int maxline;
	maxline = top_line + height;
	if (maxline > buff.size()) maxline = buff.size();

	cout << fname << endl;
	cout << long_dash << endl;
	for (int i = top_line; i < maxline; i++)
	{
		if (i == pointer_line) cout << " > "; else cout << " ";
		if (i < 9) cout << " ";
		cout << i + 1 << " " << buff[i] << endl;
	}
	cout << long_dash << endl;
}