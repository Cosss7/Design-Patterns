//
// Created by Cosss on 17/8/7.
//

#ifndef DESIGN_PATTERNS_BUILDER_H
#define DESIGN_PATTERNS_BUILDER_H

#endif //DESIGN_PATTERNS_BUILDER_H

// http://www.spuriousthoughts.com/2012/11/06/chaining-setters-in-c-builder-pattern/
// https://en.wikipedia.org/wiki/Builder_pattern

#include <iostream>

namespace Builder {
class Product {
public:

    class Builder;

private:
    // properties of product
    const int i;
    const float f;
    const char c;

    // called by builder
    Product(const int i, const float f, const char c) : i(i), f(f), c(c) {}

public:
    // Product specific functionality
    void print();

    void doSomething();
};

class Product::Builder {
private:
    // variables needed for construction of object of Product class
    // C++11 can initialize on declaration
    int i = defaultI;
    float f = defaultF;
    char c = defaultC;

public:
    // default values for variables
    static const constexpr int defaultI = 1;
    static const constexpr float defaultF = 3.1415f;
    static const constexpr char defaultC = 'a';

    // create Builder with default values assigned
    // (in C++11 they can be simply assigned above on declaration instead)
    // Builder() : i( defaultI ), f( defaultF ), c( defaultC ){ }

    // sets custom values for Product creation
    // returns Builder for shorthand inline usage (same way as cout <<)
    Builder &setI(const int i) {
        this->i = i;
        return *this;
    }

    Builder &setF(const float f) {
        this->f = f;
        return *this;
    }

    Builder &setC(const char c) {
        this->c = c;
        return *this;
    }

    // prepare specific frequently desired Product
    // returns Builder for shorthand inline usage (same way as cout <<)
    Builder &setProductP() {
        this->i = 42;
        this->f = -1.0f / 12.0f;
        this->c = '@';

        return *this;
    }

    // produce desired Product
    Product build() {
        // Here, optionaly check variable consistency
        // and also if Product is buildable from given information

        return Product(this->i, this->f, this->c);
    }
};

void Product::print() {
    using namespace std;

    cout << "Product internals dump:" << endl;
    cout << "i: " << this->i << endl;
    cout << "f: " << this->f << endl;
    cout << "c: " << this->c << endl;
}

void Product::doSomething() {}

void Builder() {
    // simple usage
    Product p1 = Product::Builder().setI(2).setF(0.5f).setC('x').build();
    p1.print(); // test p1

    // advanced usage
    Product::Builder b;
    b.setProductP();

    // this can be RVO or call move constructor.
    Product p2 = b.build(); // get Product P object
    b.setC('!'); // customize Product P
    Product p3 = b.build();
    p2.print(); // test p2
    p3.print(); // test p3
}
} // namespace Builder