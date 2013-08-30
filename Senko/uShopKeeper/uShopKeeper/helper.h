#include <vector>
#include <string>
#include "Product.h"
#include "User.h"

using namespace std;

bool Login(vector<User>, string, string);
int MainMenu();
int AdminMenu();
int AuditMenu();
int OperationMenu();

void AddUser(vector<User>&);
void PriceList(vector<Product>&);
void AddProduct(vector<Product>&);
void BuyProduct(vector<Product>&);
void SellProduct(vector<Product>&);
