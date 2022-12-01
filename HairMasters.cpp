#include "HairMasters.h"
#include <string>

HairMasters::HairMasters(string name, string type, string numberClient, string price, string theData)
{
	if (name.empty() || type.empty() || numberClient.empty() || price.empty() || theData.empty())
		throw exception("������ ������� ������ ����!");
	this->name = name;
	this->numberClient = numberClient;
	this->type = type;
	this->theData = theData;
	this->price = price;
}

HairMasters::HairMasters()
{
	string name1;
	cout << "������� ��� �������\n";
	getline(cin, name1);
	try
	{
		SetName(name1);
	}
	catch (const std::exception& ex)
	{
		cout << ex.what();
		throw exception("��������� ���� ������� ����������!\n");
	}
	cout << "������� ��� �����\n";
	getline(cin, name1);
	try
	{
		SetType(name1);
	}
	catch (const std::exception& ex)
	{
		cout << ex.what();
		throw exception("��������� ���� ������� ����������!\n");
	}
	cout << "������� ���� ���������� ������\n";
	getline(cin, name1);
	try
	{
		SetTheData(name1);

	}
	catch (const std::exception& ex)
	{
		cout << ex.what();
		throw exception("��������� ���� ������� ����������!\n");
	}
	cout << "������� ����� �������\n";
	getline(cin, name1);
	try
	{
		SetNumberClient(name1);
	}
	catch (const std::exception& ex)
	{
		cout << ex.what();
		throw exception("��������� ���� ������� ����������!\n");
	}
	cout << "������� ��������� ������, ��������� ��������\n";
	getline(cin, name1);
	try
	{
		SetPrice(name1);
	}
	catch (const std::exception& ex)
	{
		cout << ex.what();
		throw exception("��������� ���� ������� ����������!\n");
	}

}

string HairMasters::GetName()
{
	return name;
}

string HairMasters::GetNumberClient()
{
	return numberClient;
}

string HairMasters::GetPrice()
{
	return price;
}

string HairMasters::GetTheData()
{
	return theData;
}

string HairMasters::GetType()
{
	return type;
}

void HairMasters::SetName(string name)
{
	if (name.empty())
		throw exception("���� � ��� �� ������ ���� ������!\n");
	this->name = name;
}

void HairMasters::SetType(string type)
{
	if (type.empty())
		throw exception("���� � ����� ������ �� ������ ���� ������!\n");
	this->type = type;
}

void HairMasters::SetNumberClient(string numberClient)
{
	if (stoi(numberClient) <= 0 || stoi(numberClient) > 200)
		throw exception("���� � ������� ������� ������� ����������!\n");
	this->numberClient = (numberClient);
}

void HairMasters::SetPrice(string price)
{
	if (stoi(price) <= 400 || stoi(price) >= 100000)
		throw exception("���� �� ���������� ������� �����������!\n");
	this->price = (price);
}

void HairMasters::SetTheData(string theData)
{
	if (theData.empty())
		throw exception("���� � ����� �� ������ ���� ������!\n");
	else if (theData.length() != 10)
		throw exception("���� � ����� ������ ����� ��� xx.xx.xxxx\n");
	this->theData = theData;
}