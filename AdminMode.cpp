#include "AdminMode.h"

bool Test(string value)
{
	regex reg("[0-9\\s]*");
	return !regex_match(value.c_str(), reg);
}

AdminMode::AdminMode(string path)
{
	this->path = path;
	this->Masters = ReadFile1(f, ";", path);
}

void AdminMode::ConsoleOutput(vector<HairMasters> Master)
{

	cout << "----------------------------------------------------------------------------------------------------\n";
	std::cout
		<< "\t\t" << setw(29) << left << "���" << "|"
		 << setw(23) << left << "        ��� ������" << " | "
		<<  setw(4) << left << "#" << "|"
		<< setw(5) << left << "   ����" << "   |"
		<< "    ����   |"
		<< std::endl;
	cout << "----------------------------------------------------------------------------------------------------\n";
	for (int i = 0; i < Master.size(); i++)
	{

		cout << setw(44) << left
			<< Master[i].GetName()
			<< " | " << setw(22) << left << Master[i].GetType()
			<< " | " << setw(3) << left << Master[i].GetNumberClient()
			<< " | " << setw(8) << left << Master[i].GetPrice() << " | "
			<< Master[i].GetTheData() << "|";
		cout << endl;
	}
	cout << "----------------------------------------------------------------------------------------------------\n";
}

void AdminMode::AddData()
{
	string n;
	do
	{
		cout << "������� ������� �� ������ �������?\n";
		getline(cin, n);
		if (Test(n) || n.empty())
		{
			cout << "������ ����� ������ �����\n";
		}
		else
			break;
		
	} while (true);
	string separator = ";";
	fout.open(path, ios::app);
	for (int i = 0; i < abs(stoi(n)); i++)
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
			cout << "������ �� ���� �������!\n";
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
	fout.close();
}

void AdminMode::EditPost()
{
	string n, line;
	bool T = true;
	do
	{
		do
		{
			cout << "������� ����� ������, ������� ������ ���������������\n";
			getline(cin, n);
			if (Test(n) || n.empty())
			{
				cout << "������ ����� ������ �����\n";
			}
			else
				break;
		} while (true);
		if (stoi(n) > Masters.size() || stoi(n) <= 0) {
			cout << "�� ����� ����� ������, ������� �� ����������!\n";
			break;
		}
		cout << "��� �� ������ ��������?\n1.���\n2.��� ������\n3.����� �������\n4.����\n5.����\n6.�����\n";
		try
		{
			switch (_getch())
			{
			case '1':
				cout << "������� ���, �� ������� ������ ��������\n";
				getline(cin, line);
				Masters[stoi(n) - 1].SetName(line);
				break;
			case '2':
				cout << "������� ��� ������, �� ������� ������ ��������\n";
				getline(cin, line);
				Masters[stoi(n) - 1].SetType(line);
				break;
			case '3':
				cout << "������� ����� �������, �� ������� ������ ��������\n";
				getline(cin, line);
				Masters[stoi(n) - 1].SetNumberClient(line);
				break;
			case '4':
				cout << "������� ����, �� ������� ������ ��������\n";
				getline(cin, line);
				Masters[stoi(n) - 1].SetPrice(line);
				break;
			case '5':
				cout << "������� ����, �� ������� ������ ��������\n";
				getline(cin, line);
				Masters[stoi(n) - 1].SetTheData(line);
				break;
			case '6':
				T = false;
				break;
			default:
				cout << "���� ����������!\n";
				break;
			}
			if (T) {
				cout << "����� ��������� �������������� � ��������� ������ ������� 0\n����� ���������� �������������� ������� ����� ������\n";
				if (_getch() == '0')
					T = false;
			}
		}
		catch (const std::exception& ex)
		{
			cout << ex.what();
		}
	} while (T);
	FileOverwrite(Masters, fout, path);
}

void AdminMode::DeletePost()
{
	string number;
	while (true)
	{
		cout << "����� ������ �� ������ �������?\n";
		getline(cin, number);
		if (Test(number))
			cout << "����� ������� ������ �����!\n";
		else
			break;
	}
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
		case 'Y':
			Masters.erase(Masters.begin() + stoi(number) - 1);
			FileOverwrite(Masters, fout, path);
			cout << "������ ������� �������!\n";
			T = false;
			break;
		case 'N':
			cout << "�� ���������� ������� ������!\n";
			T = false;
			break;
		default:
			break;
		}
	} while (T);
}

void AdminMode::Main()
{
	bool T = true;
	cout << "����� ���������� � ������ ���������� � ������� ��������������!\n\n";
	do
	{
		cout << "�������� ��������, ������� ������ ���������\n1.���������� ��� ������� ������\n2.�������� ������� ������\n3.��������������� ������� ������\n4.������� ������� ������\n5.��������� �����\n";
		switch (_getch())
		{
		case '1':
			system("cls");
			ConsoleOutput(Masters);
			break;
		case '2':
			system("cls");
			AddData();
			break;
		case '3':
			system("cls");
			EditPost();
			break;
		case '4':
			system("cls");
			DeletePost();
			break;
		case '5':
			T = false;
			break;
		default:
			break;
		}
	} while (T);
}