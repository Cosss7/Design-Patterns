//
// Created by Cosss on 17/8/20.
//

#ifndef DESIGN_PATTERNS_BRIDGE_H
#define DESIGN_PATTERNS_BRIDGE_H



namespace Bridge{



class WindowImp{
public:
    virtual ~WindowImp() {}

    virtual void Draw() = 0;
};

class XWindowImp : public WindowImp{
public:
    virtual ~XWindowImp() {}

    virtual void Draw() override {
        std::cout << "XWindowImp Draw()" ;
    }
};

class PMWindowImp : public WindowImp{
public:
    virtual ~PMWindowImp() {}

    virtual void Draw() override {
        std::cout << "PMWindowImp Draw()" ;
    }
};

class Window{
public:
    virtual ~Window() {}

    virtual void Draw() = 0;

protected:
    WindowImp& getImp(){
        static XWindowImp imp;

        return imp;
    }

};

class AppWindow : public Window{
public:
    virtual ~AppWindow() {}

    virtual void Draw() override {
        std::cout << "AppWindow Draw()" << "------" ;
        WindowImp &imp = getImp();
        imp.Draw();
        std::cout << std::endl;
    }
};

class IconWindow : public Window{
public:
    virtual ~IconWindow() {}

    virtual void Draw() override {
        std::cout << "IconWindow Draw()" << "------" ;
        WindowImp &imp = getImp();
        imp.Draw();
        std::cout << std::endl;
    }
};




void Bridge(){
    std::unique_ptr<Window> w = std::make_unique<AppWindow>();
    std::unique_ptr<Window> u = std::make_unique<IconWindow>();

    w->Draw();
    u->Draw();
}

} // namespace Bridge


#endif //DESIGN_PATTERNS_BRIDGE_H
