#pragma once
#include "DataBase.h"
#include <string>
#include <algorithm>
#include <iostream>
#include <iomanip>

#include <random>
#include <ctime>

int FindClient(DataBase &dataBase, std::string name);
int FindItem(DataBase &dataBase, std::string name);
int FindOrder(DataBase &dataBase, std::string name);
void AddClient(DataBase& dataBase);
void AddItem(DataBase& dataBase);
void RandomDataBase(DataBase& dataBase);
void ShowAllClients(DataBase& dataBase);
void ShowWarehouse(DataBase& dataBase);
void ShowAllOrders(DataBase& dataBase);
void ShowOrder(DataBase& dataBase);
void AddOrder(DataBase& dataBase);
void SetQuantity(DataBase& dataBase);
