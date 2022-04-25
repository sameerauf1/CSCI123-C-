
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string input;

string living_room_with_treats =  "Your are in a yellow living room that is well lit with a small hole in the wall, There is a cofee table with a bag of treats, the big gray dog Spike is guarding the entrance of the kitchen. ";
string living_room_without_treats =  "Your are in a yellow living room that is well lit with a small hole in the wall, There is an empty cofee table, the big gray dog Spike is guarding the entrance of the kitchen. ";
string garage_with_trap = "You are in a cold dark room and there is a rat trap";
string garage_without_trap = "You are in an empty cold room ";
string kitchen_with_cheese = "There is a cutting board, a sink and piece of cheese";
string kitchen_without_cheese =  "There is a cutting board, a sink, but no food ";

// objects discpritions
string treats_description = "The large red bag of dog treats are for Pitbulls";
string trap_description = "There is a medium sized snap trap that with enough space for a slice of cheese";
string cheese_description = "There is a medium slice of fresh yellow cheese ";
bool in_living = true;
bool in_garage = false;
bool in_kitchen = false;
bool carrying_treats = false;
bool carrying_trap = false;
bool carrying_cheese = false;
vector< string> locations = {"living room", "kitchen", "garage"};
vector< string> living = {"treats"};
vector <string> garage = {"trap"};
vector< string> kitchen =  {"cheese"};
vector<string> inventory = {/*"place holder", "place holder"*/};
//bool carrying_remote = false;
//string remote_description = "The slim black remote is for an old 1940's television.";
void items_in_room(vector<string> items)
	{
		for(int i =0; i<items.size(); ++i)
		{
			cout << items.at(i) << "," << endl;
		}
	}
void get(string verb, string noun)
{
	if(verb == "get" && noun == "")
		{
			cout << "You reach out to grab something..." << endl;
			cout << "Nothing but air..." << endl << endl;
			}
	else if(verb == "get" &&  noun == "treats" and carrying_treats == true)
	{
		cout << " You are already carryig treats, there are no treats left to get" << endl;
	}
	else if(verb == "get" &&  noun == "trap" and carrying_trap == true)
		{
			cout << " You are already carryig a trap, there are no more traps to get" << endl;
		}
	else if(verb == "get" &&  noun == "cheese" and carrying_treats == true)
		{
			cout << " You are already carryig cheese, there is no more cheeseleft to get" << endl;
			
		}
	else if(verb == "get" && noun == "treats")
	{
		carrying_treats = true;
		for(int i = 0; i < kitchen.size(); ++i)// if the treat is in kitchen, living or garage, delete from those vectors..
 	 	{		 	 	
	 		if(kitchen.at(i) == noun)
	 		{
	 			kitchen.erase(kitchen.begin() + i);
	 			
	 			break;
	 		}
          
		}
			cout << "treats are being erased from living vector.. line72" << endl;
		for(int i = 0; i < living.size(); ++i)
				 	 	{
				 	 	cout << "treats are being erased from living vector.. line74" << endl;
			 	 	 	if(living.at(i) == noun)
			 	 	 		{
			 	 	 			living.erase(living.begin()+i);
			 	 	 			cout << "treats are being erased from living vector.. line78" << endl;
			 	 	 			break;
			 	 	 		}
			           
						}
		for(int i = 0; i < garage.size(); ++i)
				 	 	{
				 	 	
			 	 	 	if(garage.at(i) == noun)
			 	 	 		{
			 	 	 			garage.erase(garage.begin()+i);
			 	 	 			break;
			 	 	 		}
			           
						}
	}
	else if(verb == "get" && noun == "trap")
	{
		carrying_trap = true;
		for(int i = 0; i < kitchen.size(); ++i)// if the treat is in kitchen, living or garage, delete from those vectors
				 	 	{
				 	 	
			 	 	 		if(kitchen.at(i) == noun)
			 	 	 		{
			 	 	 		kitchen.erase(kitchen.begin() + i);
			 	 	 			break;
			 	 	 		}
			           
						}
		for(int i = 0; i < living.size(); ++i)
				 	 	{
				 	 	
			 	 	 	if(living.at(i) == noun)
			 	 	 		{
			 	 	 			living.erase(living.begin()+i);
			 	 	 			break;
			 	 	 		}
			           
						}
	for(int i = 0; i < garage.size(); ++i)
			 	 	{
			 	 	
		 	 	 	if(garage.at(i) == noun)
		 	 	 		{
		 	 	 			garage.erase(garage.begin()+i);
		 	 	 			break;
		 	 	 		}
		           
					}
	}
	else if(verb == "get" && noun == "cheese")
	{
		carrying_cheese = true;
		for(int i = 0; i < kitchen.size(); ++i)// if the treat is in kitchen, living or garage, delete from those vectors
				 	 	{
				 	 	
			 	 	 		if(kitchen.at(i) == noun)
			 	 	 		{
			 	 	 			kitchen.erase(kitchen.begin() + i);
			 	 	 			break;
			 	 	 		}
			           
						}
		for(int i = 0; i < living.size(); ++i)
				 	 	{
				 	 	
			 	 	 	if(living.at(i) == noun)
			 	 	 		{
			 	 	 			living.erase(living.begin()+i);
			 	 	 			break;
			 	 	 		}
			           
						}
	for(int i = 0; i < garage.size(); ++i)
			 	 	{
			 	 	
		 	 	 	if(garage.at(i) == noun)
		 	 	 		{
		 	 	 		garage.erase(garage.begin()+i);
		 	 	 			break;
		 	 	 		}
		           
					}
	}
		cout << "You now have the " << noun << endl;
			
			carrying_treats = true; 
			inventory.push_back(noun); // add noun to the inventory
			for(size_t i = 0; i < inventory.size(); ++i)
			{	 	 	{
	 	 		if(inventory.at(i) == noun)
	 	 		{
	 	 			cout << inventory.at(i) << " is in inventory now." << endl <<endl;
	 	 			break;
	 	 		}
	 	 	}
		}
		}

	void drop(string verb, string noun)
	{
				 if(verb == "drop" && noun == "treats" && carrying_treats == false )
						{
									cout << "You are not carrying the treats, so you cannot drop them." << endl << endl;
								
						}
				else  if(verb == "drop" && noun == "trap" && carrying_treats == false )
						{
									cout << "You are not carrying the trap, so you cannot drop the trap." << endl << endl;
									
						}
				else  if(verb == "drop" && noun == "cheese" && carrying_treats == false )
						{
									cout << "You are not carrying the cheese, so you cannot drop the cheese." << endl << endl;
									
						}
				if (noun == "treats")
 	 	 		{
 	 	 			carrying_treats = false;
 	 	 		}
 	 	 		if(noun == "trap")
 	 	 		{
 	 	 			carrying_trap = false;
 	 	 		}
 	 	 		if(noun == "cheese")
 	 	 		{
 	 	 			carrying_cheese = false;
 	 	 		}
				if(in_living == true)
		 	 	{	
		 	 		living.push_back(noun);
		 	 	}
		 	 	  if(in_kitchen == true)
		 	 	{
		 	 		kitchen.push_back(noun);
		 	 	}
		 	 	 if(in_garage == true)
		 	 	{
		 	 		garage.push_back(noun);
		 	 	}
				
		 	 	
				for(int i = 1; i < inventory.size(); ++i)
		 	 	{
		 	 	
	 	 	 	if(inventory.at(i) == noun)
	 	 	 		{
	 	 	 			cout << "You have dropped the " << noun << endl;
	 	 	 			inventory.at(i).erase(i);
	 	 	 		cout <<  "The " <<  noun  << " is not in inventory now." << endl << endl;
	 	 	 			break;
	 	 	 		}
	           
				}
			}
			void look(string verb, string noun)
			{
			 if(verb == "look" && noun == "treats" && in_living == true )
			{
					cout << treats_description << endl << endl;
			
			}
			else if(verb == "look" && noun == "trap" && in_garage == true )
			{
					cout << trap_description << endl << endl;
			
			}
			else  if(verb == "look" && noun == "cheese" && in_kitchen == true )
			{
					cout << cheese_description << endl << endl;
			
			}
			else if (verb == "look" && noun == "")
				{
				if(in_living)
				{
				
					if(carrying_treats)
					{
						cout << living_room_without_treats << endl;
						cout << "The current objects available in the living room to pick up are: " << endl << endl;
						items_in_room(living);	
									
					}
					else 
					{
						cout << living_room_with_treats << endl;
						cout << "The current objects available in the living room to pick up are: " << endl << endl;
						items_in_room(living);
					}
				}
			 if(in_garage)
				{
					if(carrying_trap)
					{
						cout << garage_without_trap << endl;
						cout << "The current objects available in the garage to pick up are: " << endl << endl;
													items_in_room(garage);
					}
					else
					{
						cout << garage_with_trap << endl;
						cout << "The current objects available in the garage  to pick up are: " << endl << endl;
													items_in_room(garage);
					}
				}
			 if(in_kitchen)
				{
					if(carrying_cheese)
					{
						cout << kitchen_without_cheese << endl;
						cout << "The current objects available in the kitche to pick up are: " << endl << endl;
								items_in_room(kitchen);
					}
					else
					{
						cout << kitchen_with_cheese << endl;
					}
				}
			}
		}
		void go(string verb, string noun)
		{
			if(verb == "go" && noun == "garage")
			{
				in_living = false;
				in_kitchen = false;
				in_garage = true;
				if(carrying_trap)
				{
					cout << garage_without_trap << endl;
				}
				else
				{
					cout << garage_with_trap << endl;
				}	
			cout << "The current objects available in the garage to pick up are: " << endl << endl;
			items_in_room(garage);	
			}
		 else if(verb == "go" && noun == "living")
				{
				in_living = true;
				in_kitchen = false;
				in_garage = false;
				if(carrying_treats)
				{
					cout << living_room_without_treats << endl;
				}
				else
				{
					cout << living_room_with_treats << endl;
				}
			cout << "The current objects available in the living room to pick up are: " << endl << endl;
			items_in_room(living);	
						}
		  if(verb == "go" && noun == "kitchen" && carrying_treats == true )
					{
						in_living = false;
						in_kitchen = true;
						in_garage = false;
						if(carrying_trap)
						{
							cout << kitchen_without_cheese << endl ;
						}
						else
						{
							cout << kitchen_without_cheese << endl ;
						}	
					cout << "The current objects available in the kitchen to pick up are: " << endl << endl;
					items_in_room(kitchen);	
					}
		else if(verb == "go" && noun == "kitchen" && carrying_treats == false)
		{
		cout << " The big gray dog spike is angry, make him happy" << endl;
			
		}
		else if(verb == "go" && noun == "")
					{
					cout << "Please type a full command, where would you like to go?" << endl << endl;
					}
			
		}

int main()
{

cout << "Hi Tom, Welcome to Tom and Jerry's House!"<< endl;
//cout << "Your are in a yellow living room that is well lit with a small hole in the wall." << endl;
//cout <<"There is a cofee table with a bag of treats." << endl << "The entrance to the Kitchen is being guarded by th big gray dog Spike "  << endl << "There is an entrance to the garage is clear " << endl << endl;;
cout << "The current objects available in the living room to pick up are: " << endl << endl;
items_in_room(living);




while(input != "quit")
{
	getline(cin,input);

	string verb = input.substr(0, input.find(" "));
	string noun = input.substr(input.find(" ")+1);

	if(input.find(" ") >= input.length()) {
			noun = "";
		}
	//	cout << "VERB: " << verb << ", NOUN: " << noun << endl; 
	if (input.find("the") < input.length())
	{
		int start = input.find("the");
		int length_the = 4;
		input.erase(start, length_the);
	}
	if (input.find("with") < input.length())
		{
			int start = input.find("with");
			int length_the = 4;
			input.erase(start, length_the);
	//	cout << input << endl;
		}
	if (input.find("on") < input.length()) 
		{
			int start = input.find("on");
			int length_the = 2;
			input.erase(start, length_the);
	//	cout << input << endl;
		}
	if (input.find("in") < input.length()) 
			{
				int start = input.find("in");
				int length_the = 2;
				input.erase(start, length_the);
				}

	if (verb == "look")
	{
	look(verb, noun);
	}
		
   if(verb == "get")
	{
		get(verb, noun);
	}
	if(verb =="drop")
	{
		drop(verb, noun);
	}
		
	
 if(verb == "go")
	{
	go(verb, noun);	
	}  	
else if(verb == "quit")
		{
		cout << "Game over!" << endl;
		}
	

	}
	}
	



