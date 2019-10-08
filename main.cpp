#include <iostream>
#include <ctime>
#include <fstream>
#include <vector>
using namespace std;

class SuperMarket{
private:
    string name;
    vector<int> item;
    vector<int> amount;
    vector<string> menuArray;
    vector<double> price;
    double total = 0;
public:
    void greeting();
    void menu();
    void bill();
    void printInvoice();
    void read_datafile();
    void print_receipt();
};

void SuperMarket::greeting()
{
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

    for (int i = 0; i < menuArray.size(); i++)
    {
        cout << i+1 << ": " << menuArray.at(i) << endl;
    }

    while (true)
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
            break;
        else
        {
            cout << "What items do you want to buy (1-5)?" <<endl;
            for (int i = 0; i < menuArray.size(); i++)
            {
                cout << i+1 << ": " << menuArray.at(i) << endl;
            }
        }
    }
}

void SuperMarket::bill()
{
    for (int i = 0; i < item.size(); i++)
    {
        price.at(item.at(i)-1) = price.at(item.at(i)-1) * amount.at(i);
        total += price.at(i);
    }
}

void SuperMarket::printInvoice()
{
    cout << "Invoice:" << endl;

    for (int i = 0; i < item.size(); i++)
    {
        string tempItem = menuArray.at(item.at(i)-1);
        cout << amount.at(i) << " " << tempItem.substr(0, tempItem.find(" ")) << " " << price.at(item.at(i)-1) << endl;
    }

    cout << "Total Amount: " << total << endl;
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
    ofstream out_stream;
    out_stream.open(name + "_receipt.txt");

    out_stream << "Receipt:" << endl;

    for (int i = 0; i < item.size(); i++)
    {
        string tempItem = menuArray.at(item.at(i)-1);
        out_stream << amount.at(i) << " " << tempItem.substr(0, tempItem.find(" ")) << " " << price.at(item.at(i)-1) << endl;
    }

    out_stream << "Total Amount: " << total << endl;

    out_stream.close();
}

int main ()
{
    SuperMarket market;
    market.greeting();
    market.menu();
    market.bill();
    market.printInvoice();
    market.print_receipt();
    return 0;
}