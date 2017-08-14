//
// Created by Cosss on 17/8/12.
//

#ifndef DESIGN_PATTERNS_ADAPTER_H
#define DESIGN_PATTERNS_ADAPTER_H

#endif //DESIGN_PATTERNS_ADAPTER_H

// https://stackoverflow.com/questions/449424/can-anybody-explain-the-concept-of-pluggable-adapter-to-me-with-good-example
// https://gist.github.com/pazdera/1145857
// https://sourcemaking.com/design_patterns/adapter/cpp/1
// http://www.bogotobogo.com/DesignPatterns/adapter.php


namespace Adapter{

class iOS{
public:
    virtual void getData() = 0;

    virtual ~iOS() {}
};

class iPhone : public iOS{
public:
    virtual void getData() override {
        std::cout << "iPhone Data" << std::endl;
    }

    ~iPhone() {}
};

class iPad : public iOS{
public:
    virtual void getData() override {
        std::cout << "iPad Data" << std::endl;
    }

    ~iPad() {}
};


class DeviceAccessorDelegate{
public:
    virtual void getFormatData() = 0;

    virtual ~DeviceAccessorDelegate() {}
};

class DeviceAdapter : public DeviceAccessorDelegate{
public:
    virtual void getFormatData() override {
        std::cout << "Formatting..." << std::endl;
        entity->getData();
    }

    DeviceAdapter(iOS *oentity) : entity(oentity) {}

    ~DeviceAdapter() {}

private:
    std::unique_ptr<iOS> entity;
};


class Application{
public:
    void useData(){
        std::cout << "getting data..." << std::endl;
        delegate->getFormatData();
        std::cout << "using data..." << std::endl;
    }

    Application(DeviceAccessorDelegate *odelegate) : delegate(odelegate) {}

private:
    std::unique_ptr<DeviceAccessorDelegate> delegate;
};


void Adapter(){
    iOS *iphone = new iPhone();
    iOS *ipad = new iPad();

    DeviceAccessorDelegate *iphoneAdapter = new DeviceAdapter(iphone);
    DeviceAccessorDelegate *ipadAdapter = new DeviceAdapter(ipad);

    Application appPhone(iphoneAdapter);
    Application appTablet(ipadAdapter);

    appPhone.useData();
    appTablet.useData();
}

} // namespace Adapter