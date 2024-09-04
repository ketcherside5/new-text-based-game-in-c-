#include <iostream>
#include <cmath>
#include <string>
#include <stdio.h>
#include <fstream>
#include <filesystem>
#include <vector>
using namespace std;

const char *path = ("C:\\Users\\jonke\\Desktop\\Vox v1");

void saveGame();
void campgainSelect();
void creation();
void goToTown();
void skillPointsAssn();
void mainMenu();
void weapon();

int tempVal1;
ofstream lSave;
ifstream save;
string cmd;
bool incombat = false;

class wear {
	public:
};

class item {
	public:
	string itemName;
	float itemDmg;
	void weapon(string x, float y )
	{
		itemName = x; itemDmg = y;
		};
	string getName(){ 
        // be aware that this creates a copy of name. Thus changes to the returned string will not be reflected in the Person object.
        // Another option would be returning a reference (std::string&), but that I leave for you to research yourself
        return itemName;
    } 
    float getDmg(){
        // same as for the name applies
        return itemDmg;
    }
    // This allows us to change the damage of an item.
    void setDmg(float newDmg) {
    	itemDmg = newDmg;
	}
	void setName(string newNam) {
    	itemName = newNam;
	}
};

vector <item> invy;

class character {
/*order of laoding  x, y, speed, str, atk, def, skP, name/file,
family name, kingsGuard, tutorial */
public:
	int x, y;
	float speedOfPlayer = 1;
	int str = 1;
	int atk = 1;
	int def = 1;
	string charName;//variables
	string FamName;
	int skP = 10;
	bool kingsGuard = false;
	bool tutorial = true;
};

character player;

int main() {
	creation();
	
	do{
	mainMenu();
	}
	while(cmd != "Exit");
	
	saveGame();
	
	return 0;
}

void saveGame()
{
	lSave.open(player.charName);
	lSave << player.x << "\t" << player.y << "\t" << player.speedOfPlayer << "\t" << player.str
	 << "\t" << player.atk << "\t" << player.def << "\t" << player.skP << "\t" << player.charName; 
	 lSave << "\t" << player.FamName << "\t" << player.kingsGuard << "\t" << player.tutorial;
	 lSave.close();
}

void skillPointsAssn()
{
	cout << "You have " << player.skP << " skill points to assign. ";
	cout << "How many would you like to spend on strength? ";//skill point assignment
	cin >> tempVal1;
	while(tempVal1 > player.skP)
		if(tempVal1 > player.skP) {
			cout << "You do not have enough skill points. How many would you like to spend on strength?";
			cin >> tempVal1;
		} else {
			break;
		}
	player.skP = player.skP - tempVal1;
	player.str = player.str + tempVal1;

	cout << "You have " << player.skP << " skill points to assign. ";
	cout << "How many would you like to spend on attack? ";//skill point assignment
	cin >> tempVal1;
	while(tempVal1 > player.skP)
		if(tempVal1 > player.skP) {
			cout << "You do not have enough skill points. How many would you like to spend on attack?";
			cin >> tempVal1;
		} else {
			break;
		}
	player.skP = player.skP - tempVal1;
	player.atk = player.atk + tempVal1;

	cout << "You have " << player.skP << " skill points to assign. ";
	cout << "How many would you like to spend on defence? ";//skill point assignment
	cin >> tempVal1;
	while(tempVal1 > player.skP)
		if(tempVal1 > player.skP) {
			cout << "You do not have enough skill points. How many would you like to spend on defence?";
			cin >> tempVal1;
		} else {
			break;
		}
	player.skP = player.skP - tempVal1;
	player.def = player.def + tempVal1;
	saveGame();
}

void creation()
{
	std::filesystem::current_path(path);
	
	cout << "welcome to the world of Dream Knights!!\n in this text based rpg there is no limit to the power you can obtain," <<
		" with just a few simple commands and a little bit of risk.\n| Type \"Start\" to play |\n| \"Help\" to access guides" <<
		" |\n| \"Exit\" to close Dream Knights |\n";
		getline(cin, cmd);
	if (cmd == "Start"){

		cout << "What is your name, knight? \n"; //character creation
		getline(cin,player.charName);
		if(std::filesystem::exists(player.charName)) {
			save.open(player.charName);
			save >> player.x >> player.y >> player.speedOfPlayer >> player.str >> player.atk >> 
			player.def >> player.skP >> player.charName >>player.FamName >>
			player.kingsGuard >> player.tutorial;
			} else {
					skillPointsAssn();
					campgainSelect();
					goToTown();
			}
	}
	else if(cmd == "Exit"){

	}
	else if(cmd == "Help"){

	}
	else{
		cout << "invalid command, Type \"Help\" to access guides\n";
	}
	

}

void goToTown()
{
	cout << "You enter town: How would you like to proceed?\n\n1.Armoury\n2.School of Divination\n3.Trades Guild\n4.Temple of Ah'rim\n";
	cin >> tempVal1;
	switch (tempVal1)
	{
	case 1:
		while(player.tutorial == true)
			{
			cout << "Welcome to the Kidlver Armoury, are you interested in joining the royal guard?\n1.Yes\t2.No\n";
			cin >> tempVal1;
			if(tempVal1 == 1 && player.kingsGuard == false)
			{
				cout << "thank heavens\n";
				player.kingsGuard = true;
				player.atk += 1;
				//cout << "Strength lvl: \tAttack lvl: \tDefence lvl: \tSkillpoints: \n" << player.str << "\t\t" << player.atk << "\t\t" << player.def << "\t\t" << player.skP << endl;
			}
			else
			{
				
			}
			cout << "here is an old sword to get you started on your journey" << endl;
			item newsword;
			invy.push_back(newsword);
			newsword.weapon("Dull Sword", 1.0);
			player.tutorial = false;
			cout << (invy.at(0)).getName() << (invy.at(0)).getDmg() << endl;
			}
		break;
	case 2:

	
	default:
		break;
	}
			


	
	
	saveGame();

}

void campgainSelect()
{
	cout << "As you walk down the road towards town you ponder your next move. (choose a main campgain)" << endl;// enter town / intro
	cout << "1. Avenge family\n2. Conquer homeland\n3. Become the church champion" << endl;
	cin >> tempVal1;
	if(tempVal1 == 1) {
		cout << "Enter family member name: ";
		cin >> player.FamName;
		cout << "its been weeks since I set down the path towards the town of Kidlver.\n I can still feel " << player.FamName;
		cout << "'s last breaths falling away, as I clutched their chest desprately pulling on the dagger.\n They will pay ";
		cout << "with their fore fathers land. I will steal from them their godly pentence, and sprinkle my war concessions with";
		cout << " their peoples blood.\n";
	} else if (tempVal1 == 2){

	} else if (tempVal1 == 3){
		cout << "Please enter a list value between 1-3";
	}

	saveGame();	
}

void mainMenu()
{
	int a = 1;
	
	do
	{
		cout << "make a selection or type \"help\"\nActions:\nInventory:\nStats:\nSettings:\nHelp:\n";
		cin >> cmd;
		if(cmd == "Actions" || cmd == "actions"){
			if(incombat == true){
				float enemyHealth = 100;
				do{
					cout << "make a selection or type \"help\"\nStrongAtk:\nDefAtk:\nDodgAtk:\nEat:\nRest:\nTalkTo:\nMove:\nMainMenu:\n";
					cin >> cmd;
					if (cmd == "mainmenu" || cmd == "MainMenu")
					{
					mainMenu();
					}
					else if (cmd == "help" || cmd == "Help")
					{
						/* code */
					}
					else if (cmd == "Eat" || cmd == "eat")
					{
						/* code */
					}
					else if (cmd == "Rest" || cmd == "rest")
					{
						/* code */
					}
					else if (cmd == "TalkTo" || cmd == "talkto")
					{
						/* code */
					}
					else if (cmd == "move" || cmd == "Move")
					{
						/* code */
					}
					else if (cmd == "StrongAtk" || cmd == "strongatk")
					{
						/* code */
					}
					else if (cmd == "DefAtk" || cmd == "defatk")
					{
						/* code */
					}
					else if (cmd == "DodgAtk" || cmd == "dodgatk")
					{
						/* code */
					}
					else
					{

					}	
				}
				while (enemyHealth > 0 && cmd != "Exit");
			}
			else{
				cout << "make a selection or type \"help\"\nEat:\nRest:\nTalkTo:\n:\nMove:\nMainMenu:\n";
				cin >> cmd;
				if (cmd == "mainmenu" || cmd == "MainMenu")
				{
					mainMenu();
				}
				else if (cmd == "help" || cmd == "Help")
				{
					/* code */
				}
				else if (cmd == "Eat" || cmd == "eat")
				{
					/* code */
				}
				else if (cmd == "Rest" || cmd == "rest")
				{
					/* code */
				}
				else if (cmd == "TalkTo" || cmd == "talkto")
				{
					/* code */
				}
				else if (cmd == "move" || cmd == "Move")
				{
					/* code */
				}
				else{

				}
			}
		}

		else if(cmd == "Inventory" || cmd == "inventory"){


		}
		else if(cmd == "Stats" || cmd == "stats"){

			
		}
		else if(cmd == "settings" || cmd == "Settings"){
			
		}
		else if(cmd == "Help" || cmd == "help"){

		}
		else{
			if (cmd == "Exit"){
				break;
			}
			else{
				a = 0;
			}
		}
	}
	while(a == 0);
}

	/*
	actions:
		move:
		talk_to:
		strongAtk:
		defAtk:
		dodgAtk:
		rest:
		eat:
	inventory:
		equipment:
	stats:
		move list:
		skills:
	settings:
	help:
	*/
