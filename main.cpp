#include "ArrayListDictionary.hpp"
#include <string>
#include <iostream>
using namespace std;

int main() {
    ArrayListDictionary<string, string> dict;
    string userWord, s;
    int userChoice = 0;
    bool flag = false;

    dict.insert("quack", "said Mr. Duck");
    dict.insert("haskell", "fantastic programming language, go learn it");
    dict.insert("banana", "a fruit that many like, or a phone");
    dict.insert("dog", "a domesticated fluff ball");
    dict.insert("cactus", "a pointy plant");
    dict.insert("phoenix", "a bird on fire");
    dict.insert("igloo", "a cool house");
    dict.insert("graph", "an awesome data structure!");

    cout << "Welcome to my dictionary program!\n";
    cout << "Here are your options:\n";
    cout << "\t1. Find\n";
    cout << "\t2. Insert\n";
    cout << "\t3. Remove\n";
    cout << "\t4. Sort\n";
    cout << "\t5. Size\n";
    cout << "\t6. Clear\n";
    cout << "\t7. Print\n";
    cout << "\t8. Quit\n";

    do {
        cout << "Enter your option: ";
        cin >> userChoice;

        switch (userChoice) {
        case 1:
            try {
                cout << "Enter a key to search my dictionary: ";
                cin.ignore();
                getline(cin, userWord);
                s = dict.find(userWord);
                cout << s << endl;
            }
            catch (const string& e) {
                cout << e << endl;
            }
            break;

        case 2:
            cout << "Enter the key of the new record: ";
            cin.ignore();
            getline(cin, userWord);
            cout << "Enter the value of the new record: ";
            getline(cin, s);
            dict.insert(userWord, s);
            break;

        case 3:
            try {
                cout << "Enter the key to remove: ";
                cin.ignore();
                getline(cin, userWord);
                dict.remove(userWord);
            }
            catch (const string& e) {
                cout << e << endl;
            }
            break;

        case 4:
            do {
                cout << "Which sorting algorithm?\n"
                    << "\t1. Bubble sort\n"
                    << "\t2. Selection sort\n"
                    << "\t3. Insertion sort\n";
                cin >> userChoice;
            } while (userChoice < 1 || userChoice > 3);

            try {
                dict.sort(userChoice);
                cout << "Comparisons: " << dict.getNumComps() << endl;
                cout << "Swaps: " << dict.getNumSwaps() << endl;
            }
            catch (const string& e) {
                cout << e << endl;
            }
            break;

        case 5:
            cout << "Dictionary size is " << dict.size() << endl;
            break;

        case 6:
            dict.clear();
            cout << "Dictionary cleared.\n";
            break;

        case 7:
            cout << dict;
            break;

        case 8:
            flag = true;
            break;
        }
    } while (!flag);

    return 0;
}

