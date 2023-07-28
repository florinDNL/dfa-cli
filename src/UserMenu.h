#ifndef USERMENU_H
#define USERMENU_H
#include "State.h"
#include <map>
#include <array>


class UserMenu
{
    public:
        UserMenu();
        ~UserMenu();
        void createState();
        void setInputs();
        void changeState();
        void beginTest();
        void cleanUp();

    private:
        map<State*, array<string, 2>> stateSettings;
};

#endif // USERMENU_H
