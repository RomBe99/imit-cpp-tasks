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
    int maxWeight;
    int currentWeight;

public:
    void setLength(int length);

    void setWidth(int width);

    void setHeight(int height);

    void setMaxWeight(int maxWeight);

    void setCurrentWeight(int currentWeight);

public:
    Container(const int length, const int width, const int height, const int maxWeight);

    const vector<Box> &getContainer() const;

    int getLength() const;

    int getWidth() const;

    int getHeight() const;

    int getMaxWeight() const;

    int getCurrentWeight() const;

    unsigned long boxesNumber();

    Box getBox(unsigned long index);

    virtual ~Container() = default;
};

#endif