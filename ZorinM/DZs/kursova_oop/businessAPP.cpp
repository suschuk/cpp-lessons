#include "businessAPP.h"

enum Moves {UP = 72, DOWN = 80, ENTER = 13, ESC = 27};
// стартові координати
int xS = 8;
int yS = 4;
// файли
string clientsFile("clients.cfg");
string goodsFile("goods.cfg");
string ordersFile("orders.cfg");

const int MAX = 128;
char buffer[MAX];

string dTimeToStr(int y, int mon, int d, int h, int min)
{
   stringstream ss;
   ss << y << "_" << mon << "_" << d << "_" << h << "-" << min << "_";  
   return ss.str();    
}

string clLstName(string str)
{
	string separ("\t");
	int pos = str.find(separ);
	return str.substr(0, pos);
}

void setCoords(int x, int y)
{
	COORD pos = {x, y};
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}

void hideCursor()
{
	CONSOLE_CURSOR_INFO Curinfo;
	Curinfo.dwSize = 1;
	Curinfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Curinfo);
}

void showCursor()
{
	CONSOLE_CURSOR_INFO Curinfo;
	Curinfo.dwSize = 1;
	Curinfo.bVisible = TRUE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Curinfo);
}

int Menu_::show(string title)
{
	int x_menu = xS - 3;
	int y_menu = yS;

	hideCursor();
	system("CLS");

	setCoords(xS - 5, yS - 2);
	cout << title;

	for (int i = 0; i < (int)items.size(); i++)
	{
			setCoords(xS, yS + i);
			cout << items[i] << endl;
	}

	while(true)
	{
		setCoords(x_menu, y_menu);
		Sleep(15);
		cout << ">> ";

		if (_kbhit())
		{
			switch(_getch())
			{
			case UP:
				if (y_menu > yS)
				{
					setCoords(x_menu, y_menu);
					cout << "   ";
					y_menu--;
				}
					break;
			case DOWN:
				if (y_menu < yS + (int)items.size() - 1)
				{
					setCoords(x_menu, y_menu);
					cout << "   ";
					y_menu++;
				}
				break;
			case ENTER:
				return y_menu - yS;
				break;
			case ESC:
				return items.size() - 1;
				break;
			}
		}
	}

	return -1;
}

void userInterface::interact()
{
	bool isDone = false;
	int choice = -1;
	int choiceCl = -1;
	int choiceGd = -1;
	vector<string> items;
	vector<string> vClient;
	vector<string> vGoods;
	vector<Goods> vOrder;
	Goods tmpGd;
	char answ = 'y';
	int j = 0;
	int qOrd = 0;
	ofstream outfile;
	string fileOrd;
	float Sum = 0;

	string strTitle;
	string strId;
	int intQ;
	float fPrice;
    time_t t;
    struct tm* now;

	items.push_back("New order");	// 0
	items.push_back("Clients");		// 1
	items.push_back("Goods");		// 2
	items.push_back("quit");		// 3

	system("CLS");
	ptrMenu_ = new Menu_(items);
	
	while(!isDone)
	{
		choice = ptrMenu_->show(".: Business App :.");
	
		switch(choice)
		{
		case 0:
			system("CLS");
			vClient = Client::pick();
			ptrMenuClients = new Menu_(vClient);
			ptrGoods = new Goods();
			
			choiceCl=ptrMenuClients->show("*** New order: choice Client ***");

			vGoods = ptrGoods->pick();
			ptrMenuGoods = new Menu_(vGoods);

			do 
			{
				choiceGd=ptrMenuGoods->show("*** New order: choice product ***");

				system("CLS");
				setCoords(xS, yS);
				cout << "*** New Order of ";

				cout << vClient[choiceCl] << "***";
				setCoords(xS, yS + 1 + j);

				tmpGd = ptrGoods->strToGoods(string(vGoods[choiceGd]));

				strTitle = tmpGd.getTitle();
				strId = tmpGd.getId();
				intQ = tmpGd.getQ();
				fPrice = tmpGd.getPrice();
				
				cout << strTitle;
				cout << " " << strId;
				
				setCoords(xS, yS + j + 2);
				cout << "Enter amount of this product: ";
				cin >> qOrd;
				if (qOrd <= intQ)
				{
					intQ -= qOrd;
				}
				else
				{
					while (qOrd > intQ)
					{
						setCoords(xS, yS + ++j + 2);
						cout << "Wrong number of amount";
						setCoords(xS, yS + ++j + 2);
						cout << "Enter amount of this product: ";
						cin >> qOrd;
						intQ -= qOrd;
					}
				}
				
				strTitle = strTitle + "\t" + strId + "\t";
				stringstream ss;
				ss << intQ << "\t" << fPrice;
				
				vGoods[choiceGd] = strTitle + ss.str();
				ptrGoods->toFileGd(vGoods);
				tmpGd.setQ(qOrd);
				vOrder.push_back(tmpGd);

				setCoords(xS, yS + j + 4);
				cout << "Continue (y/n)? ";
				cin >> answ;
				j++;
			}
			while (answ != 'n');
			
			answ = 'y';

			t = time(0);   // get time now
			now  = localtime( &t );
			fileOrd = dTimeToStr(now->tm_year + 1900, now->tm_mon, now->tm_mday, 
								 now->tm_hour, now->tm_min) + clLstName(vClient[choiceCl]) + ".ord";

			setCoords(xS, yS + j + 6);
			cout << "Order was created: " << fileOrd;

			outfile.open (fileOrd, ios::app);

		    outfile << (now->tm_year + 1900) << '/' 
					<< setw(2) << setfill('0')  
					<< (now->tm_mon + 1) << '/'
					<< setw(2) << setfill('0')  
					<<  now->tm_mday 
					<< " ";
			outfile << setw(2) << setfill('0')  
					<< now->tm_hour << ":" 
					<< setw(2) << setfill('0')  
					<< (now->tm_min) << "\n";
			outfile << "*** ORDER ***\n";
			outfile << "Name of client: " << vClient[choiceCl] << "\n\n";
		
			for (int i = 0; i < (int)vOrder.size(); i++)
			{
				setCoords(xS, yS + ++j + 6);
				cout << vOrder[i].getTitle() << "\t";
				cout << vOrder[i].getId() << "\t";
				cout << vOrder[i].getQ() << "\t";
				cout << vOrder[i].getPrice() << "\n";

				outfile << vOrder[i].getTitle() << "\t"
					    << vOrder[i].getId() << "\t"
						<< vOrder[i].getQ() << "\t"
						<< vOrder[i].getPrice() << "\n";
				Sum += (float)vOrder[i].getQ() * vOrder[i].getPrice();
			}
			outfile << "--------------------------------------\n";
			outfile << "Total: " << Sum << "UAH";

			outfile.close();

			setCoords(xS, yS + j + 8);
			cout << "Press any key..";
		

			ptrGoods = NULL;
			delete ptrMenuClients;
			delete ptrMenuGoods;
			delete ptrGoods;

			_getch();
			break;
		case 1:
			ptrClient = new Client();
			ptrClient->interact();
			delete ptrClient;
			break;
		case 2:
			ptrGoods = new Goods();
			ptrGoods->interact();
			delete ptrGoods;
			break;
		case 3:
			isDone = true;
			break;
		}
	}

	delete ptrMenu_;
	system("CLS");
	cout << "Have a nice day." << endl;
}

void Client::interact()
{
	bool isDone = false;
	int choice = -1;
	vector<string> items;

	items.push_back("Show");		// 0
	items.push_back("Add new");		// 1
	items.push_back("Remove");		// 2
	items.push_back("back");		// 3

	system("CLS");
	ptrMenu_ = new Menu_(items);
	ptrFileShow = new fileShow(clientsFile, ".: List of our clients (txt) :.");

	while (!isDone)
	{
		choice = ptrMenu_->show(".: Clients :.");

		switch(choice)
		{
		case 0:
			ptrFileShow->interact();
			break;
		case 1:
			add();
			isDone = true;
			break;
		case 2:
			remove();
			isDone = true;
			break;
		case 3:
			isDone = true;
			break;
		}
	}
	delete ptrMenu_;
	delete ptrFileShow;
}

void Client::add()
{
	ifstream infile (clientsFile);
	vector<string> clList;
	string frtName;
	string lstName;

	system("CLS");
	setCoords(xS, yS);
	cout << "*** Add new client ***";
	showCursor();
	setCoords(xS, yS + 2);
	cout << "Enter last name: ";
	cin >> lstName;
	setCoords(xS, yS + 3);
	cout << "Enter first name: ";
	cin >> frtName;
	hideCursor();

	string separ("\t");
	string str;
	bool ifRepeat = false;
	int i = 0;
	int		pos = -1;
	string	first;
	string	second;

	while(!infile.eof())
	{
		infile.getline(buffer, MAX);
		if(strlen(buffer) != 0)
		{
			setCoords(xS, yS + ++i + 3);
			str = (string)buffer;
			pos = str.find(separ);
			first = str.substr(0, pos);
			second = str.substr(pos+separ.length());

			clList.push_back(buffer);
			if (first == lstName &&  second == frtName)
				ifRepeat = true;
		}
	}

	setCoords(xS, yS + ++i + 2);
	if (ifRepeat)
		cout << "Client with same name exist\n";
	else
	{
		cout << "Client was added\n";
		clList.push_back( lstName + "\t" + frtName );
	}

	ofstream outfile(clientsFile);

	sort(clList.begin(), clList.end());

	outfile << clList[0];
	for (int i = 1; i < (int)clList.size(); i++)
		outfile << endl << clList[i];

	setCoords(xS, yS + i + 3);
	cout << "press any key..." ;

	_getch();
}

void Client::remove()
{
	int choice = 0;
	char answ;
	system("CLS");
	setCoords(xS, yS);
	cout << "*** Remove client ***";
	vector<string> items;
	ifstream infile (clientsFile);

	while (!infile.eof())
	{
		infile.getline(buffer, MAX);
		items.push_back(buffer);
	}

	ptrMenu_ = new Menu_(items);
	choice = ptrMenu_->show("*** Remove client ***");

	setCoords(xS, yS + 6);
	cout << items[choice] << " will be removed!";
	setCoords(xS, yS + 7);
	cout << "Are you sure (y/n)? ";
	cin >> answ;

	if (answ == 'y')
	{
		setCoords(xS, yS + 8);
		cout << "Record was removed";
		items.erase(items.begin() + choice);
		
		ofstream outfile (clientsFile);
		for (int i = 0; i < (int)items.size(); i++)
			outfile << items[i] << endl;


	}
	else
	{
		setCoords(xS, yS + 9);
		cout << "Cenceled";
	}

	setCoords(xS, yS + 10);
	cout << "Press any key...";
	_getch();
}

vector<string> Client::pick()
{
	vector<string> result;
	ifstream infile (clientsFile);
	string str;

	while(!infile.eof())
	{
		infile.getline(buffer, MAX);
		if(strlen(buffer) != 0)
		{
			str = (string)buffer;
			result.push_back(str);
		}
	}

	return result;
}

void Goods::interact()
{
	bool isDone = false;
	int choice = -1;
	vector<string> items;

	items.push_back("Show all");		// 0
	items.push_back("Add new");			// 1
	items.push_back("Remove");			// 2
	items.push_back("back");			// 4

	system("CLS");
	ptrMenu_ = new Menu_(items);
	ptrFileShow = new fileShow(goodsFile, ".: List of goods (txt) :.");

	while (!isDone)
	{
		choice = ptrMenu_->show(".: GOODS :.");

		switch(choice)
		{
		case 0:
			ptrFileShow->interact();
			break;
		case 1:
			add();
			break;
		case 2:
			remove();
			isDone = true;
			break;
		case 3:
			isDone = true;
			break;
		}
	}
	delete ptrMenu_;
	delete ptrFileShow;
}

void Goods::add()
{
	ifstream infile (goodsFile);
	vector<string> goodsList;
	
	string title;
	string model;
	int quantity;
	float price;

	system("CLS");
	setCoords(xS, yS);
	cout << "*** Add new product ***";
	showCursor();
	setCoords(xS, yS + 2);
	cout << "Enter title: ";
	cin >> title;
	setCoords(xS, yS + 3);
	cout << "Enter model: ";
	cin >> model;
	setCoords(xS, yS + 4);
	cout << "Enter quantity: ";
	cin >> quantity;
	setCoords(xS, yS + 5);
	cout << "Enter quantity: ";
	cin >> price;
	hideCursor();

	string separ("\t");
	string str;
	bool ifRepeat = false;
	int i = 0;
	int		pos = -1;
	string	first;
	string	second;
	int third;
	float fours;

	while(!infile.eof())
	{
		infile.getline(buffer, MAX);
		if(strlen(buffer) != 0)
		{
			setCoords(xS, yS + ++i + 3);
			str = (string)buffer;
			pos = str.find(separ);
			first = str.substr(0, pos);

			str = str.substr(pos + separ.length());
			pos = str.find(separ);
			second = str.substr(0, pos);
			
			str = str.substr(pos + separ.length());
			pos = str.find(separ);
			third = stoi(str.substr(0, pos));

			str = str.substr(pos + separ.length());
			pos = str.find(separ);
			fours = stof(str.substr(0, pos));
			
			goodsList.push_back(buffer);
			if (first == title &&  second == model &&
				third == quantity && fours == price)
					ifRepeat = true;
		}
	}

	setCoords(xS, yS + ++i + 2);
	if (ifRepeat)
		cout << "Same product already exist\n";
	else
	{
		stringstream ss;
		ss << quantity << "\t" << price;
		cout << "New product was added\n";
		goodsList.push_back( title + "\t" + model + "\t" + ss.str() );
	}

	ofstream outfile(goodsFile);

	sort(goodsList.begin(), goodsList.end());

	outfile << goodsList[0];
	for (int i = 1; i < (int)goodsList.size(); i++)
		outfile << endl << goodsList[i];

	setCoords(xS, yS + i + 3);
	cout << "press any key..." ;

	_getch();
}

void Goods::remove()
{
	int choice = 0;
	char answ;
	int count = 0;
	system("CLS");
	setCoords(xS, yS);
	cout << "*** Remove product ***";
	vector<string> items;
	ifstream infile (goodsFile);

	while (!infile.eof())
	{
		infile.getline(buffer, MAX);
		items.push_back(buffer);
		count++;
	}

	ptrMenu_ = new Menu_(items);
	choice = ptrMenu_->show("*** Remove product ***");

	setCoords(xS, yS + ++count);
	cout << items[choice] << " will be removed!";
	setCoords(xS, yS + ++count);
	cout << "Are you sure (y/n)? ";
	cin >> answ;

	if (answ == 'y')
	{
		setCoords(xS, yS + 8 + 6 + count);
		cout << "Record was removed";
		items.erase(items.begin() + choice);
		
		ofstream outfile (goodsFile);
		for (int i = 0; i < (int)items.size(); i++)
			outfile << items[i] << endl;


	}
	else
	{
		setCoords(xS, yS + ++count);
		cout << "Cenceled";
	}

	setCoords(xS, yS + ++count);
	cout << "Press any key...";
	_getch();
}

vector<string> Goods::pick()
{
	vector<string> result;
	ifstream infile (goodsFile);
	string str;

	while(!infile.eof())
	{
		infile.getline(buffer, MAX);
		if(strlen(buffer) != 0)
		{
			str = (string)buffer;
			result.push_back(str);
		}
	}

	return result;
}

Goods Goods::strToGoods(string str)
{
	Goods temp;
	int pos;
	string separ("\t");

	pos = str.find(separ);
	temp.title = str.substr(0, pos);

	str = str.substr(pos + separ.length());
	pos = str.find(separ);
	temp.id = str.substr(0, pos);
	
	str = str.substr(pos + separ.length());
	pos = str.find(separ);
	temp.q = stoi(str.substr(0, pos));

	str = str.substr(pos + separ.length());
	pos = str.find(separ);
	temp.price = stof(str.substr(0, pos));

	return temp;
}

string Goods::goodsToStr(Goods gd)
{
	stringstream ss;
	ss << gd.q << "\t" << gd.price;
	return gd.title + "\t" + gd.id + "\t" + ss.str(); 
}

void Goods::toFileGd(vector<string> vStr)
{
	ofstream outfile(goodsFile);
	for(int i = 0; i < (int)vStr.size(); i++)
		outfile << vStr[i]  << endl	;
}

void fileShow::interact()
{
	system("CLS");
	int i = 0;

	ifstream infile (fileName);

	setCoords(xS - 5, yS - 2);
	cout << title;

	while (!infile.eof())
	{
		infile.getline(buffer, MAX);
		if (strlen(buffer) != 0)
		{
			setCoords(xS, yS + i);
			i++;
			cout << "- " <<  buffer << endl;
		}
	}

	setCoords(xS, yS + i + 1);
	cout << "press any key..." ;

	_getch();
	cout << "\n\n";

}
