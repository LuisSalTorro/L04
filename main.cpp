#include <iostream>
#include <ctime>
#include <fstream>
#include <vector>
#include <cstdlib>
using namespace std;

class SuperMarket{
private:
    vector<int> item;
    vector<int> amount;
    vector<string> menuArray;
public:
    void greeting();
    void menu();
    void bill(int bill);
    void printInvoice();
    string read_datafile();
    void print_receipt();
};

void SuperMarket::greeting()
{
    string name;
    time_t timer;
    tm * time;
    std::time(&timer);
    time = localtime(&timer);

    cout << "What is your name" << endl;
    cin >> name;

    if(time->tm_hour >= 4 && time->tm_hour <= 11)
    {
        cout << "good Morning " << name << endl;
    }
    else if(time->tm_hour >= 12 && time->tm_hour <= 16)
    {
        cout << "good Afternoon " << name << endl;
    }
    else
    {
        cout << "good evening " << name << endl;
    }
}


void SuperMarket::menu()
{
    string menu = read_datafile(), tempPrice, line;
    double price = 0;
    size_t prev = 0, pos = 0;
    cout << menu << endl;
    cout << "What items do you want to buy (1-5)?" <<endl;

    bool repeat = true;
    while (repeat)
    {
        int input;
        cin >> input;
        item.push_back(input);

        cout << "how many of this item do you want to buy" << endl;
        cin >> input;
        amount.push_back(input);
        tempPrice = menuArray.at(input-1);
        prev = tempPrice.length()-1;
        line = tempPrice;
        pos = line.find_last_of(' ', prev); //or find_last_of( " ';"), pos
        tempPrice = line.substr(pos+1, 4);
        price += atof("tempPrice");

        string input2;
        cout << "would you like to buy another item (y/n)" << endl;
        cin >> input2;
        if (input2 == "n")
            repeat = false;
        else
            cout << "What items do you want to buy (1-5)?" <<endl;
    }

    cout << "You spent a total of $" << price << endl;
    //extract the menu prices
    //This is how to get the last word in a string
    //lines need to take in a single line of the text
//    pos = line.find_last_of(" ';", prev); //or find_last_of( ' ' ), pos
//    tempPrice = line.substr(prev, pos-prev);
    //make into double and then add the full price
    //price += atof("tempPrice");
}

void SuperMarket::bill(int bill)
{
    //keep track of what the user buys through an array?
}

void SuperMarket::printInvoice()
{

}

//reads the menu file
string SuperMarket::read_datafile()
{
    string menuList;
    ifstream in_stream;
    in_stream.open("grocery_input.txt");

    in_stream >> menuList;

    string tempStr;
    while(std::getline(in_stream,tempStr)){
        menuList += tempStr +="\n";
        menuArray.push_back(tempStr);
    }

    in_stream.close();
    return menuList;
}

void SuperMarket::print_receipt()
{
    //I'm thinking of passing the int price from above here for the total
}

int main ()
{
    SuperMarket test;
    test.greeting();
    test.menu();
    return 0;
}