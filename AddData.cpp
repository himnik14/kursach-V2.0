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
		fout << Masters[Masters.size() - 1].GetName() << separator << Masters[Masters.size() - 1].GetType() << separator << Masters[Masters.size() - 1].GetNumberClient() << separator << Masters[Masters.size() - 1].GetPrice() << separator << Masters[Masters.size() - 1].GetTheData() << separator << "\n";
	}

}

void EditPost(vector<HairMasters>& Masters, ofstream& fout)
{
	string n, line, k;
	bool T = true;
	
	do
	{
		cout << "������� ����� ������, ������� ������ ���������������\n";
		getline(cin, n);
		if (stoi(n) >= Masters.size() || stoi(n) < 0) {
			cout << "�� ����� ����� ������, ������� �� ����������!\n";
			break;
		}
		cout << "��� �� ������ ��������?\n1.���\n2.��� ������\n3.����� �������\n4.����\n5.����\n6.�����\n";
		getline(cin, k);
		switch (stoi(k))
		{
		case 1:
			try
			{
				cout << "������� ���, �� ������� ������ ��������\n";
				getline(cin, line);
				Masters[stoi(n) - 1].SetName(line);
			}
			catch (const std::exception&ex)
			{
				cout << ex.what();
			}
			break;
		case 2:
			try
			{
				cout << "������� ��� ������, �� ������� ������ ��������\n";
				getline(cin, line);
				Masters[stoi(n) - 1].SetType(line);
			}
			catch (const std::exception&ex)
			{
				cout << ex.what();
			}
			break;
		case 3:
			cout << "������� ����� �������, �� ������� ������ ��������\n";
			getline(cin, line);
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
		case 4:
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
		case 5:
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
		case 6:
			break;
		default:
			cout << "���� ����������!\n";
			break;
		}
		cout << "����� ��������� �������������� � ��������� ������ ������� 0\n����� ���������� �������������� ������� ����� ������\n";
		k = _getch();
		if (stoi(k) == 0)
			T = false;
	} while (T);
	FileOverwrite(Masters, fout);
}

void DeletePost(vector<HairMasters> &Masters, ofstream& fout)
{
	string number;
	cout << "����� ������ �� ������ �������?\n";
	getline(cin, number);
	bool T = true;
	char ch;
	do
	{
		cout << "�� ������������� ������ ������� " << number << " ������?\nY - �� N - ���\n";
		ch = _getch();
		switch (ch)
		{
		case 'y':
			Masters.erase(Masters.begin() + stoi(number) - 1);
			FileOverwrite(Masters, fout);
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
