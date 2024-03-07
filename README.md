# score-viewer

// Classbuild.h

// Public:
- void regstatus();
- std::string get_lname(); // declared in header file, returns last name of player
- std::string get_fname(); // declared in header file, returns first name of player
- Player(); // declared in header file, default constructor for a player
- int getYoB(); // declared in header file, returns year of birth of player
- std::string getUx(); // declared in header file, checks if player is underage
- std::string getreg_status(); // declared in header file, checks if player is registered and sets it to that value, used for buffer and display purposes
- void IsInUx(const int& season_yr);
- void inputfname(); // declared in header file, takes a first name and sets it as the first name of a player
- void inputlname(); // declared in header file, takes a last name and sets it as the last name of a player
- void inputYoB(); // declared in header file, takes a year of birth and sets it as the year of birth of a player

// Private:
- int YoB;
- std::string fname;
- std::string lname;
- bool reg_status;
- std::string Ux;
- std::string answer;

// Classbuild.cpp
- void Player::regstatus(): asks the user if the player is registered, sets registration status based on user input
- void Player::IsInUx(const int& season_yr): checks if the player is underaged using the season year and year of birth

// Buffer.h

// Public:
- void next();
- void prev();
- bool open();
- void display();
- void set_height(int h); // declared in header file, sets the height to h
- bool search(std::string target);
- void up();
- void down();
- void jump(int l);
- void insert(const std::string& instring);
- void erase();
- void replace(const std::string& restring);
- bool save();

// Private:
- int top_line; // declared in header file, set to 0 for display and buffer purposes
- int pointer_line; // declared in header file, set to 0 for display and buffer purposes
- int height; // declared in header file, set to 5 for display purposes
- std::vector<std::string> buff;
- char fname[50];

// Bufferlib.cpp
- const std::string long_dash(50, '_'); // used for display purposes
- void Buffer::next(): runs the next function, goes to the next player
- void Buffer::prev(): runs the previous function, goes to the previous player
- bool Buffer::open(): runs the open file function, opens the "player.txt" file
- void Buffer::display(): creates the display for each player when running the display function
- bool Buffer::search(std::string s): runs the search function, opens search view
- void Buffer::up(): runs the up function, ability to go up in the display window
- void Buffer::down(): runs the down function, ability to go down in the display window
- void Buffer::jump(): runs the jump function, used by Buffer to run other functions
- void Buffer::insert(): runs the insert function, the user can add a player to the season roster
- void Buffer::erase(): erases a player from the roster
- void Buffer::replace(): runs the replace function, able to replace a player in the spot as a different player previously
- void Buffer::save(): runs the save function, saves the player from the insert and/or add functions into the "player.txt" file

// Map.h

// Public:
- void input_pair(std::istream& in); // allows the user to input data into the map to be saved
- void output(); // outputs relevant data
- std::map<std::string, Player> copymap();
- int getseasonyr();
- void begin_new_season(); // Starts a new season, other functions used to implement data manipulation and saving
- void next(std::vector<Player>::iterator position);
- void prev(std::vector<Player>::iterator position);
- bool open(); // to open a file ("players.txt")
- void maindisplay(); // The main display
- void searchdisplay(int number, std::vector<Player>::iterator pos, std::vector<Player> a); // the individual search display (or rather search view)
- std::vector<Player> search_map();
- void erase(); // implemented when starting a new season
- void replace(const Player& player); // replace the edited data with what the user inputs
- bool save(); // saves relevant data for the season into the file/vector
- void search_print();
- bool if__name(Player player, std::string& name);
- bool if__YoB(Playe
