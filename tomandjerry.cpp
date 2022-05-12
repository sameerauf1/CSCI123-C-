
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <fstream>
using namespace std;
	string input;
	string verb;
	string noun;

	bool carrying_treats = false; 
	bool carrying_trap = false;
	bool carrying_cheese = false;
	int current_room = 0; // deafult is the living
	void look(string verb, string noun);
	
class object
{
	public:
	string name;
	string object_description;	
};
object treats = {"treats" ,"The large red bag of dog treats are for Pitbulls "};
object trap = {"trap", "There is a medium sized snap trap that with enough space for a slice of cheese" };
object cheese = {"cheese", "There is a medium slice of fresh yellow cheese "};
vector<object> inventory{};

class location;
location& get_current_room();
void inventory_delete(string a)
{
	for(unsigned  int i = 0; i < inventory.size(); i = i + 1)
			{
				if(inventory.at(i).name ==a) {
					inventory.erase(inventory.begin() + i);
					break;
				}
	
			}
}
class location
{
	public:
	string description_with_object;
	string description_without_object;
	vector <object> items_in_location;
	
void look(string noun)
	{			
		if(noun == "") {
			if(items_in_location.size() > 0)
				cout << description_with_object << endl; 
			else
				cout << description_without_object << endl;

		}
		else {
			for(object item : items_in_location) {
				if(item.name == noun) {
					cout << item.object_description << endl;
					return;
				}
			}

			cout << "You don't see anything like that" << endl;
		}
			
	}
void go(string noun)
		{
		int new_room = -1;
		if(noun == "kitchen") {
			new_room = 2;	
		}
		else if(noun == "living") {
			new_room = 0;	
		}
		else if(noun == "garage") {
			new_room = 1;	
		}
		else {
			new_room = -1;
		}

		if(new_room == -1) {
			cout << "You can't go that way." << endl;
		}
		else if(new_room == current_room) {
			cout << "You're already there!" << endl;
		}
		else {
			current_room = new_room;
			get_current_room().look("");
		}
		}
	
void delete_item(string noun)
		{
		for(unsigned  int i = 0; i < items_in_location.size(); i = i + 1)
		{
			if(items_in_location.at(i).name == noun) {
				items_in_location.erase(items_in_location.begin() + i);
				break;
			}

		}
		}
		
									
};
	




location living = {"You are in a yellow living room that is well lit with a small hole in the wall, There is a cofee table with a bag of treats, the big gray dog Spike is guarding the entrance of the kitchen. ", "You are in a yellow living room that is well lit with a small hole in the wall, There is an empty cofee table, the big gray dog Spike is guarding the entrance of the kitchen. " , {treats}};
location garage = {"You are in a cold dark room and there is a rat trap", "You are in an empty cold room ", {trap},};
location kitchen = {"There is a cutting board, a sink and piece of cheese", "There is a cutting board, a sink, but no food ", {cheese}};

location& get_current_room()
{
	if(current_room == 0)
		return living;
	else if(current_room == 1)
		return garage;
	else
		return kitchen;
}

vector< location> rooms = {living, garage, kitchen}; //living is 0, garage 1, kitche 2

void items_in_room(vector<object> items)
		{
			for(unsigned int i =0; i<items.size(); ++i)
			{
			cout << items.at(i).name << endl;// looking at a vector of objects, pick one object and then pick its name
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
	else if(verb == "get" &&  noun == "cheese" and carrying_cheese == true)
		{
			cout << " You are already carryig cheese, there is no more cheese left to get" << endl;
			
		}
	else if(verb == "get" && noun == "treats" and carrying_treats == false)
	{
		carrying_treats = true;
		for(unsigned int i = 0; i < kitchen.items_in_location.size(); ++i)// if the treat is in kitchen, living or garage, delete from those vectors..
 	 	{
 	 //	if(  i <  kitchen.items_in_location.size() )
 	 // throw length_error{"sorry out of length"}
		if(kitchen.items_in_location.at(i).name == noun)// looking at kitchen, then the vector and then pick 
	 		{
	 			kitchen.items_in_location.erase(kitchen.items_in_location.begin() + i);
	 			break;
	 		}
          
		}
		for(unsigned int i = 0; i < living.items_in_location.size(); ++i)
	 	 	{
 	 	 	if(living.items_in_location.at(i).name == noun)
 	 	 		{
 	 	 			living.items_in_location.erase(living.items_in_location.begin()+i);// vector of objects, want to dlete entire object
 	 	 			break;
 	 	 		}
           
			}
		for(unsigned int i = 0; i < garage.items_in_location.size(); ++i)
	 	 	{
	 	 	
 	 	 	if(garage.items_in_location.at(i).name == noun)
 	 	 		{
 	 	 			garage.items_in_location.erase(garage.items_in_location.begin()+i);
 	 	 			break;
 	 	 		}
           
			
	    	}
		cout << "You now have the " << noun << endl;
	//	object name
					
		inventory.push_back(treats); // add noun to the inventory
		for(size_t i = 0; i < inventory.size(); ++i)
		{	 	 	{
 	 		if(inventory.at(i).name == noun)
 	 		{
 	 			cout << inventory.at(i).name << " is in inventory now." << endl <<endl;
 	 			break;
 	 		}
 	 	}
	}
	}
	else if(verb == "get" && noun == "trap"/* and carrying_trap == false*/)
	{
		carrying_trap = true;
		for(unsigned int i = 0; i < kitchen.items_in_location.size(); ++i)// if the treat is in kitchen, living or garage, delete from those vectors
	 	 	{	
	 	
	 		if(kitchen.items_in_location.at(i).name == noun)
	 		{
	 		kitchen.items_in_location.erase(kitchen.items_in_location.begin() + i);
	 			break;
	 		}
			           
			}	
		for(unsigned int i = 0; i < living.items_in_location.size(); ++i)
	 	 	{
	 	 	
 	 	 	if(living.items_in_location.at(i).name == noun)
 	 		{
 	 			living.items_in_location.erase(living.items_in_location.begin()+i);
 	 			break;
 	 		}
           
			}
		for(unsigned int i = 0; i < garage.items_in_location.size(); ++i)
	 	 	{
	 	 	
 	 	 	if(garage.items_in_location.at(i).name == noun)
 	 	 		{
 	 	 			garage.items_in_location.erase(garage.items_in_location.begin()+i);
 	 	 			break;
 	 	 		}
           
			}
		inventory.push_back(trap); // add noun to the inventory
				for(size_t i = 0; i < inventory.size(); ++i)
				{	 	 	{
		 	 		if(inventory.at(i).name == noun)
		 	 		{
		 	 			cout << inventory.at(i).name << " is in inventory now." << endl <<endl;
		 	 			break;
		 	 		}
		 	 	}
			}
	}
	else if(verb == "get" && noun == "cheese")
	{
		carrying_cheese = true;
		for(unsigned int i = 0; i < kitchen.items_in_location.size(); ++i)// if the treat is in kitchen, living or garage, delete from those vectors
				 	 	{
				 	 	
			 	 	 		if(kitchen.items_in_location.at(i).name == noun)
			 	 	 		{
			 	 	 			kitchen.items_in_location.erase(kitchen.items_in_location.begin() + i);
			 	 	 			break;
			 	 	 		}
			           
						}
		for(unsigned int i = 0; i < living.items_in_location.size(); ++i)
				 	 	{
				 	 	
			 	 	 	if(living.items_in_location.at(i).name == noun)
			 	 	 		{
			 	 	 			living.items_in_location.erase(living.items_in_location.begin()+i);
			 	 	 			break;
			 	 	 		}
			           
						}
	for(unsigned int i = 0; i < garage.items_in_location.size(); ++i)
			 	 	{
			 	 	
		 	 	 	if(garage.items_in_location.at(i).name == noun)
		 	 	 		{
		 	 	 		garage.items_in_location.erase(garage.items_in_location.begin()+i);
		 	 	 			break;
		 	 	 		}
		           
					}
		inventory.push_back(cheese); // add noun to the inventory
						for(size_t i = 0; i < inventory.size(); ++i)
						{	 	 	{
				 	 		if(inventory.at(i).name == noun)
				 	 		{
				 	 			cout << inventory.at(i).name << " is in inventory now." << endl <<endl;
				 	 			break;
				 	 		}
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
				 if(verb == "drop" && noun == "trap" && carrying_trap == false )
						{
									cout << "You are not carrying the trap, so you cannot drop the trap." << endl << endl;
									
						}
				 if(verb == "drop" && noun == "cheese" && carrying_cheese == false )
						{
									cout << "You are not carrying the cheese, so you cannot drop the cheese." << endl << endl;
									
						}
				if(current_room == 0)
		 	    	{	
		 	    	if (noun == "treats")
	 	 	 			{
	 	 	 			carrying_treats = false;
	 	 	 			living.items_in_location.push_back(treats);
	 	 	 			}
	 	 	 		if(noun == "trap")
	 	 	 			{
	 	 	 			carrying_trap = false;
	 	 	 			living.items_in_location.push_back(trap);

	 	 	 			}
	 	 	 		if(noun == "cheese")
	 	 	 			{
	 	 	 			carrying_cheese = false;
	 	 	 			living.items_in_location.push_back(cheese);
	 	 	 			}
		 	 	}
		 	   if( current_room == 2)
	 	 		{
	 	 		if (noun == "treats")
 	 	 			{
 	 	 			carrying_treats = false;
 	 	 			kitchen.items_in_location.push_back(treats);
 	 	 			

 	 	 			}
 	 	 		if(noun == "trap")
 	 	 			{
 	 	 			carrying_trap = false;
 	 	 			kitchen.items_in_location.push_back(trap);

 	 	 			}
 	 	 		if(noun == "cheese")
 	 	 			{
 	 	 			carrying_cheese = false;
 	 	 			kitchen.items_in_location.push_back(cheese);
 	 	 			}
	 	 		}
	 	 	 if(current_room == 1)
	 	 		{
 	 			if (noun == "treats")
 	 	 			{
 	 	 			carrying_treats = false;
 	 	 			garage.items_in_location.push_back(treats);

 	 	 			}
 	 	 		if(noun == "trap")
 	 	 			{
 	 	 			carrying_trap = false;
 	 	 			garage.items_in_location.push_back(trap);

 	 	 			}
 	 	 		if(noun == "cheese")
 	 	 			{
 	 	 			carrying_cheese = false;
 	 	 			garage.items_in_location.push_back(cheese);
 	 	 			}
	 	 		}
				
	 	 	for(unsigned int i = 0; i < inventory.size(); ++i)
	 	 	{				 	 	
 	 	 	if(inventory.at(i).name == noun)
 	 	 		{
 	 	 	//	cout << inventory.at(i).name << endl;
 	 	 			cout << "You have dropped the " << noun << endl;
 	 	 			inventory.erase(inventory.begin() + i);
 	 	 		cout <<  "The " <<  noun  << " is not in inventory now." << endl << endl;
 	 	 			break;
 	 	 		}
           
			}

			}

void save()
{
	ofstream inv_save{ "inventory.save" };
	
	for(object x : inventory) {
		inv_save << x.name << endl;
	}
	inv_save.close();
	
	ofstream kitch_save{ "kitchen.save" };
		
	for(object x : kitchen.items_in_location) {
		kitch_save << x.name << endl;
	}
	kitch_save.close();
	
	ofstream liv_save{ "living.save" };
			
		for(object x : living.items_in_location) {
			liv_save << x.name << endl;
		}
		liv_save.close();

	ofstream gar_save{ "garage.save" };
				
		for(object x : garage.items_in_location) {
						gar_save << x.name << endl;
					}
						gar_save.close();

	ofstream room_save{"room.save"};
//	int room = current_room;
	room_save << current_room << endl;
	room_save.close();
	/*
	ofstream kitchen_save{ "kitchen.save" };
	string kitchen_items;
	for(int i = 0; i < 10000; ++i)
		{
			getline(cin, kitchen_items);
		}
	
	kitchen_save.close();
	*/
	
}

object& name_to_object(string name)
{
	if(name == "treats")
		return treats;
	else if(name == "trap")
		return trap;
	else 
		return cheese;
}

void load()
{
	inventory.clear();
	kitchen.items_in_location.clear();
	living.items_in_location.clear();
	garage.items_in_location.clear();
	

	ifstream inv_save{ "inventory.save" };
	
	string name;
	while(getline(inv_save, name)) {
		object x = name_to_object(name);
		inventory.push_back(x);

		// Also delete x from any rooms
		kitchen.delete_item(name);
		living.delete_item(name);
		garage.delete_item(name);
		
	}
	inv_save.close();
	
	ifstream kitch_save{ "kitchen.save" };
		
		string kname;
		while(getline(kitch_save, name)) {
			object x = name_to_object(name);
		kitchen.items_in_location.push_back(x);
	
			// Also delete x from any rooms
			//kitchen.delete_item(kname);
			living.delete_item(kname);
			garage.delete_item(kname);
			inventory_delete(kname);		
		//	inventory.delete_item(kname);
			// delete from inventory
		}
		kitch_save.close();
		
	ifstream liv_save{ "living.save" };
			
			string lname;
			while(getline(liv_save, lname)) {
				object x = name_to_object(name);
			kitchen.items_in_location.push_back(x);
		
				// Also delete x from any rooms
				kitchen.delete_item(lname);
				//living.delete_item(lname);
				garage.delete_item(lname);
				inventory_delete(lname);
			//	inventory.delete_item(lname);
			}
			liv_save.close();
	ifstream gar_save{ "garage.save" };
				
				string gname;
				while(getline(gar_save, gname)) {
					object x = name_to_object(name);
				garage.items_in_location.push_back(x);
			
					// Also delete x from any rooms
					kitchen.delete_item(gname);
					living.delete_item(gname);
				//	inventory.delete_item(gname);
					inventory_delete(gname);
					//garage.delete_item(gname);
				}
				gar_save.close();
	ifstream room_save{"room.save"};
	//	int room = current_room;
		room_save >> current_room ;
		room_save.close();
		
}
			
int main()
{
cout << "Hi Tom, Welcome to Tom and Jerry's House!"<< endl;
cout << living.description_with_object << endl;

cout << "The current objects available in the living room to pick up are: " << endl << endl;
items_in_room(living.items_in_location);

///kitchen.items_in_room
//living.items_in_room
//garage.items_in_room
// inventory



while(input != "quit")
{
	getline(cin,input);

	string verb;
	string noun;

		//cout << "VERB: " << verb << ", NOUN: " << noun << endl; 
	if (input.find("the ") < input.length())
	{
		int start = input.find("the ");
		cout << start << endl;
		int length_the = 4;
		input.erase(start, length_the);
	}
	if (input.find("with ") < input.length())
		{
			int start = input.find("with ");
			int length_with = 5;
			input.erase(start, length_with);
	//	cout << input << endl;
		}
	if (input.find("on ") < input.length()) 
		{
			int start = input.find("on ");
			int length_on = 3;
			input.erase(start, length_on);
	//	cout << input << endl;
		}
	if (input.find("in ") < input.length()) 
			{
				int start = input.find("in ");
				int length_in = 3;
				input.erase(start, length_in);
				}
				
	verb = input.substr(0, input.find(" "));
	noun = input.substr(input.find(" ")+1);

	if(input.find(" ") >= input.length()) {
			noun = "";
		}	
				
	cout << "VERB2:" << verb << ", NOUN2:" << noun << endl;

	if (verb == "look")
	{
	get_current_room().look(noun);
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
	//go(verb, noun);	
	get_current_room().go(noun);
	}
	  	
else if(verb == "quit")
		{
		cout << "Game over!" << endl;
		}
	else if(verb == "save") {
		save();
	}
	else if(verb == "load") {
		load();
		
	}
	else if(verb == "inventory") {
		cout << "You are carrying: " << endl;
		for(object x : inventory) {
			cout << "  " << x.name << endl;
		}
	}

	}
	}
	

