/*
 * Sign-Up_Application.cpp
 *
 *  Created on: May 11, 2024
 *      Author: Ibraam Wahba
 */
#include<iostream>
#include<string>
constexpr int DataSize = 100;
enum class options
{
	AddRecord = 1,
	FetchRecored,
	Quit
};

class person
{
public:
	std::string FirstName ;
	std::string LastName ;
	int age ;

	person()
	{
		FirstName = "default";
		LastName = "default";
	    age = 0;
	}
};
void menu();
void AddRecord(person arr[]);
void FetchRecored (person arr[]);

int main()
{
	int option = 0;
	bool IsRunning = true;

	person AppData[DataSize];

	while(IsRunning == true)
	{
		menu();
		std::cin>>option;

		switch(option)
		{
		case (int) options:: AddRecord:
			AddRecord(AppData);
			break;
		case (int) options:: FetchRecored:
			FetchRecored(AppData);
			break;

		case (int)options:: Quit:
			IsRunning = false;
			break;
		default:
			//do nothing
			break;
	}
	}
	return 0 ;
}

void AddRecord(person arr[])
{
    static int count = 0;
	std::cout<<"Add user, Please enter user name and age:\n";
	std::cout<<"First name: ";
	std::cin>>arr[count].FirstName;
	std::cout<<"Last name: ";
	std::cin>>arr[count].LastName;

	std::cout<<"\n";
	std::cout<<"Age: ";
	std::cin>>arr[count].age;
	std::cout<<"\n";
	count ++;
}
void FetchRecored (person arr[])
{
	int ID = 0;
	std::cout<<"Please enter user ID:\n";
	std::cout<<"User ID:";
	std::cin>>ID;
	std::cout<<"\n";
	if(ID <DataSize)
	{
	std::cout<<"User name:"<<arr[ID].FirstName<<" "<<arr[ID].LastName<<"\n";
	std::cout<<"User age:"<<arr[ID].age<<"\n";
	}
	else
	{
		std::cout<<"Invalid ID number";
	}

}
void menu()
	{
		std::cout<<"1:Add Record\n";
		std::cout<<"2:Fetch Record\n";
		std::cout<<"3:Quit\n\n";
		std::cout<<"Enter Option: ";
	}
