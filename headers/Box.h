#ifndef CPP_TASKS_BOX_H
#define CPP_TASKS_BOX_H

class Box {
private:
    int length;
    int width;
    int height;
    double weight; // kg
    double value; // cop

public:
    Box();
    Box(const int length, const int width, const int height, const double weight, const double value);

    void setLength(const int length);

    void setWidth(const int width);

    void setHeight(const int height);

    void setWeight(const double weight);

    void setValue(const double value);

    int getLength() const;

    int getWidth() const;

    int getHeight() const;

    double getWeight() const;

    double getValue() const;
};


#endif