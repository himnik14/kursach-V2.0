#include "AddData.h"
#include <fstream> 
#include"FileManager.h"
void AddData(vector<HairMasters> &Masters, ofstream& fout)
{
	string path = "C:\\Games\\text.txt";
	string n;
	do
	{
		cout << "������� ������� �� ������ �������?\n";
		getline(cin, n);
	} while (n.empty());

	cout << "����� ����������� �� ������ ������������ ��� ������ ������ � ����?\n";
	string separator;
	fout.open(path, ios::app);
	getline(cin, separator);
	for (int i = 0; i < stoi(n); i++)
	{
		cout << "�������� " << i + 1 << " ������!\n";
		cout << "============================\n";
		try
		{
			Masters.push_back(HairMasters());
		}
		catch (const std::exception& ex)
		{
			cout << ex.what();
			continue;
		}
		cout << "������ ������� �������!\n";
		cout << "============================\n";

		fout << Masters[Masters.size() - 1].GetName() << separator
			<< Masters[Masters.size() - 1].GetType() <<
			separator << Masters[Masters.size() - 1].GetNumberClient() 
			<< separator << Masters[Masters.size() - 1].GetPrice() << separator 
			<< Masters[Masters.size() - 1].GetTheData() << separator << "\n";
	}

}

void EditPost(vector<HairMasters>& Masters, ofstream& fout)
{
	string n, line;
	bool T = true;
	do
	{
		cout << "������� ����� ������, ������� ������ ���������������\n";
		getline(cin, n);
		if (stoi(n) >= Masters.size() || stoi(n) <= 0) {
			cout << "�� ����� ����� ������, ������� �� ����������!\n";
			break;
		}
		cout << "��� �� ������ ��������?\n1.���\n2.��� ������\n3.����� �������\n4.����\n5.����\n6.�����\n";
		switch (_getch())
		{
		case '1':
			try
			{
				cout << "������� ���, �� ������� ������ ��������\n";
				getline(cin, line);
				Masters[stoi(n) - 1].SetName(line);
			}
			catch (const std::exception& ex)
			{
				cout << ex.what();
			}
			break;
		case '2':
			try
			{
				cout << "������� ��� ������, �� ������� ������ ��������\n";
				getline(cin, line);
				Masters[stoi(n) - 1].SetType(line);
			}
			catch (const std::exception& ex)
			{
				cout << ex.what();
			}
			break;
		case '3':
			try
			{
				cout << "������� ����� �������, �� ������� ������ ��������\n";
				getline(cin, line);
				Masters[stoi(n) - 1].SetNumberClient(line);
			}
			catch (const std::exception& ex)
			{
				cout << ex.what();
			}
			break;
		case '4':
			try
			{
				cout << "������� ����, �� ������� ������ ��������\n";
				getline(cin, line);
				Masters[stoi(n) - 1].SetPrice(line);
			}
			catch (const std::exception& ex)
			{
				cout << ex.what();
			}
			break;
		case '5':
			try
			{
				cout << "������� ����, �� ������� ������ ��������\n";
				getline(cin, line);
				Masters[stoi(n) - 1].SetTheData(line);
			}
			catch (const std::exception& ex)
			{
				cout << ex.what();
			}
			break;
		case '6':
			break;
		default:
			cout << "���� ����������!\n";
			break;
		}
		cout << "����� ��������� �������������� � ��������� ������ ������� 0\n����� ���������� �������������� ������� ����� ������\n";
		if (_getch() == '0')
			T = false;
	} while (T);
	FileOverwrite(Masters, fout, "fs");
}

void DeletePost(vector<HairMasters> &Masters, ofstream& fout)
{
	string number;
	cout << "����� ������ �� ������ �������?\n";
	getline(cin, number);
	bool T = true;
	do
	{
		if (stoi(number) <= 0 || stoi(number) > Masters.size())
		{
			cout << "����� ������ �� ����������!\n";
			break;

		}
		cout << "�� ������������� ������ ������� " << number << " ������?\nY - �� N - ���\n";
		switch (_getch())
		{
		case 'y':
			Masters.erase(Masters.begin() + stoi(number) - 1);
			FileOverwrite(Masters, fout, "fds");
			cout << "������ ������� �������!\n";
			T = false;
			break;
		case 'n':
			cout << "�� ���������� ������� ������!\n";
			T = false;
			break;
		default:
			break;
		}
	} while (T);
	
	
	
}
