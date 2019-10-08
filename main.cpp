#include <iostream>
#include <ctime>
#include <fstream>
#include <vector>
using namespace std;

class SuperMarket{
private:
    vector<int> item;
    vector<int> amount;
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
    string menu = read_datafile();
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

        string input2;
        cout << "would you like to buy another item (y/n)" << endl;
        cin >> input2;
        if (input2 == "n")
            repeat = false;
        else
            cout << "What items do you want to buy (1-5)?" <<endl;
    }

    //extract price from back of the line by figuring out first empty space

}

void SuperMarket::bill(int bill)
{

}

void SuperMarket::printInvoice()
{

}

string SuperMarket::read_datafile()
{
    string menuList;
    ifstream in_stream;
    in_stream.open("grocery_input.txt");

    in_stream >> menuList;

    string tempStr;
    while(std::getline(in_stream,tempStr)){
        menuList += tempStr +="\n";
    }

    in_stream.close();
    return menuList;
}

void SuperMarket::print_receipt()
{

}

int main ()
{
    SuperMarket test;
    test.greeting();
    test.menu();


    return 0;
}