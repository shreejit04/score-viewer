#include <iostream>                                                                  
#include <string>                                                                    


class Player {

public:
	void regstatus();
	std::string get_lname() { return lname; }
	std::string get_fname() { return fname; }
	Player() { YoB = 0; reg_status = 0; }

	int getYoB() { return(YoB); }
	std::string getUx() { return(Ux); }
	std::string getreg_status() {
		if (reg_status) return("Registered");
		else return ("Not Registered");
	}

	void IsInUx(const int& season_yr);
	void inputfname() { std::cin >> fname; }
	void inputlname() { std::cin >> lname; }
	void inputYoB() { std::cin >> YoB; }


private:
	int YoB;
	std::string fname;
	std::string lname;
	bool reg_status;   
	std::string Ux;
	std::string answer;
};