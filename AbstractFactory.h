

#ifndef DESIGN_PATTERNS_ABSTRACTFACTORY_H
#define DESIGN_PATTERNS_ABSTRACTFACTORY_H

#endif //DESIGN_PATTERNS_ABSTRACTFACTORY_H

#include <string>


class Circle{
public:
    virtual void draw() = 0;
};

class Win32Circle : public Circle{
public:
    void draw() override {
        std::cout << "Win32 Circle" << std::endl;
    }
};

class LinuxCircle : public Circle{
public:
    void draw() override {
        std::cout << "Linux Circle" << std::endl;
    }
};

class Triangle{
public:
    virtual void draw() = 0;
};

class Win32Triangle : public Triangle{
public:
    void draw() override {
        std::cout << "Win32 Triangle" << std::endl;
    }
};

class LinuxTriangle : public Triangle{
public:
    void draw() override {
        std::cout << "Linux Triangle" << std::endl;
    }
};


class ShapeFactory{
public:
    virtual std::unique_ptr<Circle> createCircle() = 0;
    virtual std::unique_ptr<Triangle> createTriangle() = 0;
};

class Win32ShapeFactory : public ShapeFactory{
public:
    std::unique_ptr<Circle> createCircle() override {
        return std::make_unique<Win32Circle>();
    }
    std::unique_ptr<Triangle> createTriangle() override {
        return std::make_unique<Win32Triangle>();
    }
};

class LinuxShapeFactory : public ShapeFactory{
public:
    std::unique_ptr<Circle> createCircle() override {
        std::unique_ptr<Circle> ptr = std::make_unique<LinuxCircle>();
        ptr->draw();
        return ptr;
    }
    std::unique_ptr<Triangle> createTriangle() override {
        std::unique_ptr<Triangle> ptr = std::make_unique<LinuxTriangle>();
        ptr->draw();
        return ptr;
    }
};


void AbstractFactory(){
    ShapeFactory* factory = new LinuxShapeFactory();
    std::unique_ptr<Circle> circle = factory->createCircle();
    std::unique_ptr<Triangle> triangle = factory->createTriangle();
}