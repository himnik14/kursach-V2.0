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
	cout << "������� ���� ���������� ������ � ������� xx.xx.xxxx\n";
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
	regex r("[�-��-�\\s]*");
	if (name.empty())
		throw exception("���� � ��� �� ������ ���� ������!\n");
	else if (!regex_match(name.c_str(), r))
		throw exception("� ���� ��� ��������� ������ ������������� �������!\n");
	this->name = name;
}

void HairMasters::SetType(string type)
{
	regex r("[�-��-�\\s\\d]*");
	if (type.empty())
		throw exception("���� � ����� ������ �� ������ ���� ������!\n");
	else if (!regex_match(type.c_str(), r))
		throw exception("� ���� ��� ������ ��������� ������ ������������� ������� � �����!\n");
	this->type = type;
}

void HairMasters::SetNumberClient(string numberClient)
{
	regex r("[0-9\\s]*");
	if (!regex_match(numberClient.c_str(), r))
	throw exception("� ���� ������ ������� ��������� ������ �����!\n");
	else if (stoi(numberClient) <= 0 || stoi(numberClient) > 200)
		throw exception("���� � ������� ������� ������� ����������!\n");
	this->numberClient = (numberClient);
}

void HairMasters::SetPrice(string price)
{
	regex r("[0-9\Q.,\E]*");
	if (!regex_match(price.c_str(), r))
		throw exception("� ���� ���� ��������� ������ �����!\n");
	else if (stof(price) <= 400 || stof(price) >= 100000)
		throw exception("���� �� ���������� ������� �����������!\n");
	this->price = (price);
}

void HairMasters::SetTheData(string theData)
{
	regex r("[0-9\Q.\E]*");
	if (!regex_match(theData.c_str(), r))
		throw exception("� ���� ���� ��������� ������ �����!\n");
	else if (theData.empty())
		throw exception("���� � ����� �� ������ ���� ������!\n");
	else if (theData.length() != 10)
		throw exception("���� � ����� ������ ����� ��� xx.xx.xxxx\n");
	else if (stoi(theData.substr(0, 2)) > 31 || stoi(theData.substr(0, 2)) <= 0)
		throw exception("� ������ �������� 31 ����!\n");
	else if (stoi(theData.substr(3, 5)) > 12 || stoi(theData.substr(3, 5)) <= 0)
		throw exception("� ���� 12 �������!\n");
	else if (stoi(theData.substr(6, 9)) > 2022 || stoi(theData.substr(6, 9)) <= 2000)
		throw exception("��� ����� ������� ���� ���� ����� � 2000-�� ����!\n");
	this->theData = theData;
}