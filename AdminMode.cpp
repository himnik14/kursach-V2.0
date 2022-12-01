#include "AdminMode.h"

AdminMode::AdminMode(string path)
{
	this->path = path;
	this->Masters = ReadFile1(f, ";", path);
}
void AdminMode::ConsoleOutput()
{
	std::cout
		<< "\t\t" << "���"
		<< "\t\t    " << "��� ������"
		<< "\t    " << "#"
		<< "     ����"
		<< "       ����"
		<< std::endl;
	cout << "-----------------------------------------------------------------------------\n";
	for (int i = 0; i < Masters.size(); i++)
	{

		cout << setw(29) << left
			<< Masters[i].GetName()
			<< " | " << setw(16) << left << Masters[i].GetType()
			<< " | " << setw(3) << left << Masters[i].GetNumberClient()
			<< " | " << setw(8) << left << Masters[i].GetPrice() << " | "
			<< Masters[i].GetTheData();
		cout << endl;
	}
	cout << "-----------------------------------------------------------------------------\n";
}

void AdminMode::AddData()
{
	string n;
	do
	{
		cout << "������� ������� �� ������ �������?\n";
		getline(cin, n);
	} while (n.empty());
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
		cout << "������� ����� ������, ������� ������ ���������������\n";
		getline(cin, n);
		if (stoi(n) > Masters.size() || stoi(n) <= 0) {
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
	FileOverwrite(Masters, fout, path);
}

void AdminMode::DeletePost()
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
			ConsoleOutput();
			break;
		case '2':
			AddData();
			break;
		case '3':
			EditPost();
			break;
		case '4':
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