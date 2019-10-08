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
    vector<double> price;
public:
    void greeting();
    void menu();
    void bill(int bill);
    void printInvoice();
    void read_datafile();
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
    read_datafile();
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
}

void SuperMarket::bill(int bill)
{
    //keep track of what the user buys through an array?
}

void SuperMarket::printInvoice()
{

}

//reads the menu file
void SuperMarket::read_datafile()
{
    string line; //this will contain the data read from the file
    ifstream myfile ("grocery_input.txt"); //opening the file.

    if (myfile.is_open()) //if the file is open
    {
        while (!myfile.eof()) //while the end of file is NOT reached
        {
            getline(myfile, line); //get one line from the file
            menuArray.push_back(line);
        }

        myfile.close(); //closing the file
    }

    for (int i = 0; i < menuArray.size(); i++)
    {
       int pos = 0;
       line = menuArray.at(i);
       pos = line.find_first_of(" ");
       line = line.substr(pos+1, 5);
       price.push_back(std::stof(line));

    }
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