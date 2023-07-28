#ifndef STATE_H
#define STATE_H

#include <string>
using namespace std;

class State
{
    public:

        State(bool isFinal, bool isStart, string stateName);
        State* getNext(char input) const;
        bool getFinal() const;
        bool getStart() const;
        string getName() const;
        void setInput0(State* input0);
        void setInput1(State* input1);
        void operator=(State other);

    private:
        string stateName;
        State* input0;
        State* input1;
        bool isFinal;
        bool isStart;
};

#endif // STATE_H
