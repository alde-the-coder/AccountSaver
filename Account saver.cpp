#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    cout << "Do you want to load saved account login settings or make a new one? 1/2\n";
    int answer;
    cin >> answer;
    if (answer == 1) {
        fstream f;
        f.open("savedpasses.txt", ios::in);
        string input;
        vector<string> passes;
        while (f >> input) {
            passes.push_back(input);
        }

        for (string pass : passes) {
            cout << pass << "\n";
        }
        cout << "\nHere is yours saved accounts\n";
        f.close();
        system("pause");
    }
    if (answer == 2) {
        cout << "Enter label to this account\n";
        string label, login, password;
        cin >> label;
        cout << "Enter login\n";
        cin >> login;
        cout << "Enter password\n";
        cin >> password;
        cout << "Label is " << label << ", Login is " << login << ", Password is " << password;
        fstream f;
        f.open("savedpasses.txt", ios::app);
        f << label << "\n" << login << "\n" << password << "\n" << endl;
    }
}
