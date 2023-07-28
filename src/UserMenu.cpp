#include "UserMenu.h"
#include <iostream>
using namespace std;

UserMenu::UserMenu()
{
    int choice;
    cout << "\n1) Add State\n2) Finish adding states and test word\n3) Clear all states\n0) Exit\n" << endl;
    cin >> choice;
    cout << endl;

    while (choice != 0)
    {
        switch (choice)
        {
            case 1:
                createState();
                break;
            case 2:
                setInputs();
                beginTest();
                break;
            case 3:
                cleanUp();
                cout << "States cleared" << endl;
        }

        cout << "\n1) Add State\n2) Finish adding states and test word\n3) Clear all states\n0) Exit\n" << endl;
        cin >> choice;
        cout << endl;
    }
}

UserMenu::~UserMenu()
{
    cleanUp();
}

void UserMenu::createState()
{
    string stateName;
    string input0;
    string input1;
    bool isStart;
    bool isAccepting;
    char startInput;
    char acceptInput;

    cout << "Enter state name: ";
    cin >> stateName;
    cout << "Is this the starting state? Y/N: ";
    cin >> startInput;
    cout << "Is this the accepting state? Y/N: ";
    cin >> acceptInput;
    cout << "Enter the input 0 target state: ";
    cin >> input0;
    cout << "Enter the input 1 target state: ";
    cin >> input1;
    cout << endl;

    isStart = startInput == 'Y' || startInput == 'y' ? true : false;
    isAccepting = acceptInput == 'Y' || acceptInput == 'y' ? true : false;

    array<string, 2> inputs = {input0, input1};
    State* newState = new State(isAccepting, isStart, stateName);

    stateSettings.emplace(newState, inputs);
}

void UserMenu::setInputs()
{
    for (auto pair : stateSettings)
    {
        string input0 = pair.second[0];
        string input1 = pair.second[1];

        for (auto subPair : stateSettings)
        {
            if (subPair.first->getName() == input0)
            {
                pair.first->setInput0(subPair.first);
            }

            if (subPair.first->getName() == input1)
            {
                pair.first->setInput1(subPair.first);
            }
        }
    }
}

void UserMenu::beginTest()
{
    string binaryStr;
    cout << "Enter binary string: ";
    cin >> binaryStr;

    State* currentNode;

    for (auto pair : stateSettings)
    {
        if (pair.first->getStart())
        {
            currentNode = pair.first;
        }
    }

    for (char c : binaryStr)
    {
        cout << currentNode->getName() << " -> ";
        currentNode = currentNode->getNext(c);
        cout << currentNode->getName() << endl;
    }

    if (currentNode->getFinal())
    {
        cout << "Word accepted" << endl;
    }
    else
    {
        cout << "Word rejected" << endl;
    }
}

void UserMenu::cleanUp()
{
    for (auto pair : stateSettings)
    {
        delete pair.first;
    }
    
    stateSettings.clear();
}
