//Daniel Rodriguez
// Arya Anand
// Cameron Perry
// Final Project

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;

struct Enemy
{
	string name;
	string basicAttack;
	string specialAttack;
	int health;
	int basicDamage;
	int specialDamage;
};

struct Character
{
	string name;
	string basicAttack;
	string specialAttack;
	int health;
	int basicDamage;
	int specialDamage;
	int level;
	int xp;
};

void intro();
void userinfo(string &);
void menu(Character &, string &, int &);
void CharacterData(Character &);
void Combat(Character &, Enemy &, string);
void enemyAppear(Character, Enemy &);
void enemyAttack(Character, Enemy, int &);
void saveGame(Character&, string &);
void loadGame(Character &, string &);

int main()
{

	Enemy attacker; // enemy struct
	Character pokemon; // pokemon struct

	string name;
	char save;
	char again;
	int menuSelection;

	menu(pokemon, name, menuSelection); // menu options to start game!

	if (menuSelection == 2)
	{
		CharacterData(pokemon);
	}
	do
	{
		Combat(pokemon, attacker, name);
		cout << "Do you want to save? (Y/N) ";
		cin >> save;
		if (toupper(save) == 'Y')
		{
			saveGame(pokemon, name);
		}

		cout << "Do you want to stay in the fight? (Y/N) ";
		cin >> again;
		cout << endl;
	} while (toupper(again) == 'Y');

	cout << "You chose to quit.\n\nBye Bye!\n"
		<< "Make sure to play again soon!\n"
		<< "Those Pokemon won't catch themselves!\n\n";

	return 0;
}

void intro()
{

	system("Color 1A");
	std::cout << "\t\t\t     Welcome to Pokemon!!!" << std::endl;
	system("Color 2B");
	std::cout << "\t\t\t     Welcome to Pokemon!!!" << std::endl;
	system("Color 3C");
	std::cout << "\t\t\t     Welcome to Pokemon!!!" << std::endl;
	system("Color 4D");
	std::cout << "\t\t\t     Welcome to Pokemon!!!" << std::endl;
	system("Color 5E");
	std::cout << "\t\t\t     Welcome to Pokemon!!!" << std::endl;
	system("Color 6F");
	std::cout << "\t\t\t     Welcome to Pokemon!!!" << std::endl;
	system("Color A1");
	std::cout << "\t\t\t     Welcome to Pokemon!!!" << std::endl;
	system("Color B2");
	std::cout << "\t\t\t     Welcome to Pokemon!!!" << std::endl;
	system("Color C3");
	std::cout << "\t\t\t     Welcome to Pokemon!!!" << std::endl;
	system("Color D4");
	std::cout << "\t\t\t     Welcome to Pokemon!!!" << std::endl;
	system("Color E5");
	std::cout << "\t\t\t     Welcome to Pokemon!!!" << std::endl;
	system("Color F6");
	std::cout << "\t\t\t     Welcome to Pokemon!!!" << std::endl;

	cout << "_s___________sss" << endl <<
		"_ss__________s__s" << endl <<
		"s__s_________s___s" << endl <<
		"s___s________s___s" << endl <<
		"s____s_______s____ssssss" << endl <<
		"s_____s______s__________ss" << endl <<
		"s______sss__s_ss_________sssssssssssss" << endl <<
		"s_____s___ss_ssss________________ssss" << endl <<
		"_s___s___ss___ss___________ssssss" << endl <<
		"__s__s__s___s_____s___ssss_s" << endl <<
		"___s_s_s______________ssss_s" << endl <<
		"sss__ss_________ssss______s" << endl <<
		"s___s__s_________ss____s__s" << endl <<
		"_s___s_s_________________s" << endl <<
		"__s__s_s________________ss" << endl <<
		"___s_ss___________________ss" << endl <<
		"____ss_________________ss___s" << endl <<
		"____s_________________s__s___s" << endl <<
		"___s_________________s____ssss" << endl <<
		"__s___________________s" << endl <<
		"__s____________________s" << endl <<
		"__s_____ssssssss_______s" << endl <<
		"___s__ss________ss____s" << endl <<
		"___s__s___________s____ss" << endl <<
		"__ssss_____________ssssssss" << endl << endl << endl;
	cout << "*==============================================================================*\n";
	cout << "\t\t\tHello There. Welcome to the world of Pokemon!\n";
	cout << "*==============================================================================*\n";
	system("pause");
	cout << "*==============================================================================*\n";
	cout << "\t\t\tMy name is Oak. People call me the Pokemon Prof!\n";
	cout << "*==============================================================================*\n";
	system("pause");
	cout << "*==============================================================================*\n";
	cout << "  This world is inhabited by creatures called Pokemon! Gotta Catch Em' All!\n";
	cout << "*==============================================================================*\n";
	system("pause");

}

void userinfo(string &userName)
{
	cin.ignore();
	cout << "\nFirst, What is your name?\n";
	getline(cin, userName);
	cout << "\nRight! So your name is " << userName << "!\n\n";

	system("pause");
}

void menu(Character &pokemon, string &name, int &menuSelection) // function GUI system menu that prompts first time users with a menu
{
	cout << "Please select from the Menu below:\n";


	cout << "1.\tContinue\n"
		<< "2.\tStart New Game\n"
		<< "3.\tQuit\n";
	cin >> menuSelection;

	if (menuSelection == 1)
	{
		cout << "You chose to Continue from Save\n";
		loadGame(pokemon, name); // calling load function
		cout << name << endl
			<< pokemon.name << endl << endl;
	}
	else if (menuSelection == 2)
	{
		cout << "You chose to Start a New Game\n";
		intro(); //call intro function
		userinfo(name); // userinfo
	}
	else if (menuSelection == 3)
	{
		cout << "You chose to quit.\n\nBye Bye!\n"
			<< "Make sure to play again soon!\n"
			<< "Those Pokemon won't catch themselves!\n\n";
		exit(0);
	}
}

void CharacterData(Character &choice)
{
	int characterChoice;

	cout << "		Select a character: " << endl << "=========================================================" << endl;
	cout << "1. Charmander: Health (70); Damage (30); Special (60)" << endl;
	cout << "2. Squirtle: Health (100); Damage (10); Special (30)" << endl;
	cout << "3. Bulbasaur: Health (85); Damage (20); Special (40)" << endl << endl;

	cout << "Enter your choice: ";
	cin >> characterChoice;

	switch (characterChoice)
	{
	case 1: choice.name = "Charmander";
		choice.basicAttack = "Ember";
		choice.specialAttack = "Fire Blast";
		choice.health = 70;
		choice.basicDamage = 30;
		choice.specialDamage = 60;
		choice.level = 1;
		choice.xp = 0;
		break;
	case 2: choice.name = "Squirtle";
		choice.basicAttack = "Water Gun";
		choice.specialAttack = "Hydropump";
		choice.health = 100;
		choice.basicDamage = 10;
		choice.specialDamage = 30;
		choice.level = 1;
		choice.xp = 0;
		break;
	case 3: choice.name = "Bulbasaur";
		choice.basicAttack = "Vinewhip";
		choice.specialAttack = "Solarbeam";
		choice.health = 85;
		choice.basicDamage = 20;
		choice.specialDamage = 40;
		choice.level = 1;
		choice.xp = 0;
		break;
	}
	cout << "You chose " << choice.name << " good for you!\n\n";
}

void Combat(Character &pokemon, Enemy &attacker, string name)
{
	// This variable is used to maipulate the characters health
	int tempHealth = pokemon.health;
	int choice;
	int seed = time(0);
	int firstAttacker;
	char again;
	char startOver;
	srand(seed);

	//random number decides who attacks first; 1 in three chance of enemy attacing firat
	firstAttacker = 1 + (rand() % 3);
	// function calls for enemy to appear
	enemyAppear(pokemon, attacker);

	//  If firstAttacker = 1 enemy attacks first
	if (firstAttacker == 1)
	{
		cout << attacker.name << " attacks first.\n";
		// combat sequence loops until either the player's health or the enemy's health falls below zero or the player runs away 
		do
		{
			// This function calls for the enemy's attack
			enemyAttack(pokemon, attacker, tempHealth);

			// The player can only attack if his health is above zero
			if (tempHealth > 0)
			{
				cout << "What do you want to do?\n"
					<< pokemon.name << " HP " << tempHealth << endl
					<< attacker.name << " HP " << attacker.health << endl << endl;
				// This value returning function gets the players choice in battle
				cout << "1. " << pokemon.basicAttack << endl
					<< "2. " << pokemon.specialAttack << endl
					<< "3. Run away\n";
				cin >> choice;
				// if choice 1 player will do a basic attack
				if (choice == 1)
				{
					cout << pokemon.name << " used " << pokemon.basicAttack << ".\n"
						<< "Enemy " << attacker.name << " takes " << pokemon.basicDamage << " points damage.\n\n";
					attacker.health -= pokemon.basicDamage;
				}
				// if choice 2 player will do a special attack
				else if (choice == 2)
				{
					// This random number decides the chance of the special attack landing; player has a 30% chance of missing his/her special attack
					int hitChance = 1 + (rand() % 4);
					if (hitChance == 1)
					{
						cout << pokemon.name << " tried to use " << pokemon.specialAttack << " but it missed.\n\n";
					}
					else
					{
						cout << pokemon.name << " used " << pokemon.specialAttack << ".\n"
							<< "It's super effective!\n"
							<< "Enemy " << attacker.name << " takes " << pokemon.specialDamage << " points damage.\n\n";
						attacker.health -= pokemon.specialDamage;
					}
				}
				// if choice 3 player runs and loses xp
				else
				{
					cout << "Got away safely!\n\n";
				}
			}
		} while (attacker.health > 0 && tempHealth > 0 && choice != 3);
	}
	// If firstAttacker != 1 player goes first
	else
	{
		do
		{
			cout << "What do you want to do?\n"
				<< pokemon.name << " HP " << tempHealth << endl
				<< attacker.name << " HP " << attacker.health << endl << endl;
			cout << "1. " << pokemon.basicAttack << endl
				<< "2. " << pokemon.specialAttack << endl
				<< "3. Run away\n";
			cin >> choice;
			if (choice == 1)
			{
				cout << pokemon.name << " used " << pokemon.basicAttack << ".\n"
					<< "Enemy " << attacker.name << " takes " << pokemon.basicDamage << " points damage.\n\n";
				attacker.health -= pokemon.basicDamage;
			}
			else if (choice == 2)
			{
				int hitChance = 1 + (rand() % 3);
				if (hitChance == 1)
				{
					cout << pokemon.name << " tried to use " << pokemon.specialAttack << " but it missed.\n\n";
				}
				else
				{
					cout << pokemon.name << " used " << pokemon.specialAttack << ".\n"
						<< "It's super effective!\n"
						<< "Enemy " << attacker.name << " takes " << pokemon.specialDamage << " points damage.\n\n";
					attacker.health -= pokemon.specialDamage;
				}
			}
			else
			{
				cout << "Got away safely!\n\n";
			}
			// enemy can only attack if his health is above zero or if the player hasn't run away
			if (attacker.health > 0 && choice != 3)
			{
				enemyAttack(pokemon, attacker, tempHealth);
			}
		} while (attacker.health > 0 && tempHealth > 0 && choice != 3);
	}
	// If player defeats enemy HP is restored and character gains 5 xp
	if (attacker.health <= 0)
	{
		cout << "Enemy " << attacker.name << " was defeated!\n"
			<< pokemon.name << "'s xp was increased by 5 points.\n\n";
		tempHealth = pokemon.health;
		pokemon.xp += 5;

		if (pokemon.xp >= 45)
		{
			cout << "Congratulations! You beat them all!\n"
				<< "Do you want to play again? (Y/N) ";
			cin >> startOver;
			cout << endl;
			if (toupper(startOver) == 'Y')
				main();
			else
			{
				cout << "You chose to quit.\n\nBye Bye!\n"
					<< "Make sure to play again soon!\n"
					<< "Those Pokemon won't catch themselves!\n\n";
				exit(0);
			}
		}
		else if (pokemon.xp >= 40)
			pokemon.level = 5;
		else if (pokemon.xp >= 30)
			pokemon.level = 4;

		else if (pokemon.xp >= 20)
			pokemon.level = 3;
		else if (pokemon.xp >= 10)
			pokemon.level = 2;
		else
			pokemon.level = 1;
		cout << pokemon.name << " XP " << pokemon.xp << endl
			<< pokemon.name << " HP " << tempHealth << endl
			<< pokemon.name << " level " << pokemon.level << endl << endl;
	}
	// If player is defeated player loses; game is over
	else if (tempHealth <= 0)
	{
		cout << pokemon.name << " was defeated.\n"
			<< "You Lose.\n"
			<< "Do you want to continue from your last save? (Y/N) ";
		cin >> again;
		cout << endl;
		if (toupper(again) == 'Y')
		{
			loadGame(pokemon, name);
			Combat(pokemon, attacker, name);
		}
		else
		{
			cout << "You chose to quit.\n\nBye Bye!\n"
				<< "Make sure to play again soon!\n"
				<< "Those Pokemon won't catch themselves!\n\n";
			exit(0);
		}
	}
	// If player runs away health is restored and character loses 5 xp
	else
	{
		cout << pokemon.name << "'s xp was decreased by 5 points.\n\n";
		tempHealth = pokemon.health;
		pokemon.xp -= 5;
		cout << pokemon.name << " xp " << pokemon.xp << endl
			<< pokemon.name << " HP " << tempHealth << endl << endl;
	}
}

void enemyAppear(Character pokemon, Enemy &attacker)   // Call xp from the character stats
{
	if (pokemon.xp >= 40)
	{
		attacker.name = "Charizard";
		attacker.basicAttack = "Flamethrower";
		attacker.specialAttack = "Fire Blast";
		attacker.health = 100;
		attacker.basicDamage = 40;
		attacker.specialDamage = 65;
		cout << "A wild Charizard appeard!\n\n";
	}
	else if (pokemon.xp >= 30)
	{
		attacker.name = "Pikachu";
		attacker.basicAttack = "Thuderbolt";
		attacker.specialAttack = "Thunder";
		attacker.health = 75;
		attacker.basicDamage = 30;
		attacker.specialDamage = 60;
		cout << "A wild Pikachu appeard!\n\n";
	}
	else if (pokemon.xp >= 20)
	{
		attacker.name = "Ekans";
		attacker.basicAttack = "Wrap";
		attacker.specialAttack = "Bite";
		attacker.health = 50;
		attacker.basicDamage = 20;
		attacker.specialDamage = 40;
		cout << "A wild Ekans appeard!\n\n";
	}
	else
	{
		attacker.name = "Rattata";
		attacker.basicAttack = "Scratch";
		attacker.specialAttack = "Hyper Fang";
		attacker.health = 25;
		attacker.basicDamage = 10;
		attacker.specialDamage = 20;
		cout << "A wild Rattata appeard!\n\n";
	}
}

void enemyAttack(Character pokemon, Enemy attacker, int &tempHealth)
{
	int seed = time(0);
	srand(seed);
	// Random number decides whether the enemy will use a basic or special attack; Enemy has a 1 in three chance of using a special atack
	int enemyMove = 1 + (rand() % 3);
	// If enemyMove = 1 Enemy will try to use special attack
	if (enemyMove == 1)
	{
		// Random number decides the special attack land; Special Attack has a 1 in 3 chance of landing
		int hitChance = 1 + (rand() % 3);
		// if hitChance = 1 special attack lands
		if (hitChance == 1)
		{
			cout << "Enemy " << attacker.name << " used " << attacker.specialAttack << ".\n"
				<< pokemon.name << " takes " << attacker.specialDamage << " points damage.\n\n";
			tempHealth -= attacker.specialDamage;
		}
		// if hitChance != 1 special attack doesn't land
		else
		{
			cout << "Enemy " << attacker.name << " tried to use " << attacker.specialAttack << " but it missed.\n\n";
		}
	}
	// If enemyMove != 1 Enemy will use basic attack
	else
	{
		cout << "Enemy " << attacker.name << " used " << attacker.basicAttack << ".\n"
			<< pokemon.name << " takes " << attacker.basicDamage << " points damage.\n\n";
		tempHealth -= attacker.basicDamage;
	}
}

void saveGame(Character &pokemon, string &name)
{
	ofstream outputFile;
	//outputFile.open("E:\\CIS-5\\Input_Output files\\Output files\\Pokemon_Save.txt");
	outputFile.open("C:\\Users\\ncc\\Desktop\\Pokemon_Save.txt");

	outputFile << name << endl
		<< pokemon.name << endl
		<< pokemon.basicAttack << endl
		<< pokemon.specialAttack << endl
		<< pokemon.basicDamage << endl
		<< pokemon.specialDamage << endl
		<< pokemon.health << endl
		<< pokemon.level << endl
		<< pokemon.xp << endl;
	outputFile.close();
}

void loadGame(Character &pokemon, string &name)
{
	system("Color 6F");
	system("Color A1");
	system("Color B2");
	system("Color C3");
	system("Color D4");
	system("Color E5");
	system("Color F6");
	ifstream inputFile;
	//inputFile.open("F:\\CIS-5\\Input_Output files\\Output files\\Pokemon_Save.txt");
	inputFile.open("C:\\Users\\ncc\\Desktop\\Pokemon_Save.txt");
	getline(inputFile, name);
	getline(inputFile, pokemon.name);
	getline(inputFile, pokemon.basicAttack);
	getline(inputFile, pokemon.specialAttack);
	inputFile >> pokemon.basicDamage
		>> pokemon.specialDamage
		>> pokemon.health
		>> pokemon.level
		>> pokemon.xp;
	inputFile.close();
}