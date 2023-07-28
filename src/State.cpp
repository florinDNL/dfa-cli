#include "State.h"

State::State(bool isFinal, bool isStart, string stateName)
{
    this->isFinal = isFinal;
    this->isStart = isStart;
    this->stateName = stateName;
    this->input0  = nullptr;
    this->input1 = nullptr;
}

State* State::getNext(char input) const
{
    return input == '0' ? input0 : input1;
}

bool State::getFinal() const
{
    return isFinal;
}

bool State::getStart() const
{
    return isStart;
}

string State::getName() const
{
    return stateName;
}

void State::setInput0(State* input0)
{
    this->input0 = input0;

}

void State::setInput1(State* input1)
{
    this->input1 = input1;

}

void State::operator=(State other)
{
    this->input0 = other.input0;
    this->input1 = other.input1;
    this->isFinal = other.isFinal;
    this->isStart = other.isStart;
    this->stateName = other.stateName;
}
