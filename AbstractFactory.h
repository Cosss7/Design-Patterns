

#ifndef DESIGN_PATTERNS_ABSTRACTFACTORY_H
#define DESIGN_PATTERNS_ABSTRACTFACTORY_H

#endif //DESIGN_PATTERNS_ABSTRACTFACTORY_H

#include <string>

namespace AbstractFactory {
class Circle {
public:
    virtual void draw() = 0;

    virtual ~Circle() {}
};

class Win32Circle : public Circle {
public:
    void draw() override {
        std::cout << "Win32 Circle" << std::endl;
    }

    virtual ~Win32Circle() {}
};

class LinuxCircle : public Circle {
public:
    void draw() override {
        std::cout << "Linux Circle" << std::endl;
    }

    virtual ~LinuxCircle() {}
};

class Triangle {
public:
    virtual void draw() = 0;

    virtual ~Triangle() {}
};

class Win32Triangle : public Triangle {
public:
    void draw() override {
        std::cout << "Win32 Triangle" << std::endl;
    }

    virtual ~Win32Triangle() {}
};

class LinuxTriangle : public Triangle {
public:
    void draw() override {
        std::cout << "Linux Triangle" << std::endl;
    }

    virtual ~LinuxTriangle() {}
};


class ShapeFactory {
public:
    virtual std::unique_ptr<Circle> createCircle() = 0;

    virtual std::unique_ptr<Triangle> createTriangle() = 0;

    virtual ~ShapeFactory() {}
};

class Win32ShapeFactory : public ShapeFactory {
public:
    std::unique_ptr<Circle> createCircle() override {
        return std::make_unique<Win32Circle>();
    }

    std::unique_ptr<Triangle> createTriangle() override {
        return std::make_unique<Win32Triangle>();
    }

    virtual ~Win32ShapeFactory() {}
};

class LinuxShapeFactory : public ShapeFactory {
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

    virtual ~LinuxShapeFactory() {}
};


void AbstractFactory() {
    // factory should always be singleton.
    // but it's unimportant here.

    std::unique_ptr<ShapeFactory> factory = std::make_unique<LinuxShapeFactory>();
    std::unique_ptr<Circle> circle = factory->createCircle();
    std::unique_ptr<Triangle> triangle = factory->createTriangle();
}
} // namespace AbstractFactory