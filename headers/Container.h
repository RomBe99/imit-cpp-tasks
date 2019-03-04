#ifndef CPP_TASKS_CONTAINER_H
#define CPP_TASKS_CONTAINER_H

#include <vector>
#include "../headers/BoxClass.h"

using namespace std;
using namespace BoxClass;

class Container {
private:
    vector<Box> container;
    int length;
    int width;
    int height;
    double maxWeight;
    double currentWeight;
    double currentValue;

    void setLength(const int length);

    void setWidth(const int width);

    void setHeight(const int height);

    void setMaxWeight(const double maxWeight);

    void setCurrentWeight(const double currentWeight);

    void setCurrentValue(const double currentValue);

public:
    Container(const int length, const int width, const int height, const double maxWeight);

    void deleteBox(const unsigned long index);

    const vector<Box> &getContainer() const;

    void setBox(const Box box);

    int getLength() const;

    int getWidth() const;

    int getHeight() const;

    double getMaxWeight() const;

    double getCurrentWeight() const;

    unsigned long boxesNumber();

    Box getBox(const unsigned long index);

    Box operator[](const unsigned int index);

    virtual ~Container() = default;
};

#endif