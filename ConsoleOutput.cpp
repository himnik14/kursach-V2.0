#include "ConsoleOutput.h"
#include<iomanip>
void ConsoleOutput(vector<HairMasters> Masters) 
{

    std::cout 
        << std::setw(15) << "���"
        << std::setw(29) << "��� ������"
        << std::setw(6) << "#"
        << std::setw(8) << "����"
        << std::setw(10) << "����"
        << std::endl;
	cout << "------------------------------------------------------------------------\n";
	for (int i = 0; i <Masters.size(); i++)
	{
		
		cout << setw(29) << left << Masters[i].GetName()  << " | "  << setw(14) << left << Masters[i].GetType() << " | " << setw(2) << left << Masters[i].GetNumberClient() << " | " << setw(5) << left << Masters[i].GetPrice() << " | " << Masters[i].GetTheData();
		cout << endl;
	}
	cout << "------------------------------------------------------------------------\n";
}