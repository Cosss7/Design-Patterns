//
// Created by Cosss on 17/8/8.
//

#ifndef DESIGN_PATTERNS_SINGLETON_H
#define DESIGN_PATTERNS_SINGLETON_H

#endif //DESIGN_PATTERNS_SINGLETON_H

// http://www.aristeia.com/Papers/DDJ_Jul_Aug_2004_revised.pdf
// https://stackoverflow.com/questions/11711920/how-to-implement-multithread-safe-singleton-in-c11-without-using-mutex
// http://preshing.com/20130930/double-checked-locking-is-fixed-in-cpp11/
// https://www.zhihu.com/question/27704562

namespace Singleton{

class Foo{
public:
    static Foo& getInstance(){
        // C++11 guarantees this is thread-safe.
        static Foo instance;

        return instance;
    }

    // c++11
    Foo(const Foo&) = delete;
    Foo(Foo&&) = delete;
    Foo& operator = (const Foo&) = delete;
    Foo& operator = (Foo&&) = delete;

    void print(){
        std::cout << "singleton here." << std::endl;
    }

protected:
    Foo(){
        // Constructor code goes here.
    }
    ~Foo(){
        // Destructor code goes here.
    }
};

void Singleton(){
    auto &instance = Foo::getInstance();
    instance.print();
}

}