#include <iostream>
#include<vector>

class SmartDevice {
protected:
    std::string name;

public:
    SmartDevice(const std::string& _name) : name(_name) {}

    virtual void run() {
        std::cout << "设备" << name << "正在待机" << std::endl;
    }

    virtual ~SmartDevice() = default;

    void restart() {
        std::cout << "设备" << name << "正在立即重启" << std::endl;
    }

    void restart(int seconds) {
        std::cout << "设备" << name << "计划在" << seconds << "秒后重启" << std::endl;
    }
};

class SmartLight : public SmartDevice {
public:
    SmartLight(const std::string& _name) : SmartDevice(_name) {}

    void run() override {
        std::cout << ">>>" << name << "灯光已打开，亮度 100%";
    }

    ~SmartLight() {
        std::cout << "(灯泡已熄灭)" << std::endl;
    }
};

class AirConditioner : public SmartDevice {
public:
    AirConditioner(const std::string& _name) : SmartDevice(_name) {}

    void run() override {
        std::cout << ">>>" << name << "开始制冷，当前室温 26 度" << std::endl;
    }

    ~AirConditioner() {
        std::cout << "(压缩机已停止)" << std::endl;
    }
};

int main(void) {
    std::vector<SmartDevice*> my_home;

    SmartDevice* device1 = new SmartLight("客厅主灯");
    SmartDevice* device2 = new AirConditioner ("卧室空调");

    my_home.push_back(device1);
    my_home.push_back(device2);

    for (auto device : my_home) {
        device->run();
        device->restart(10);
        delete device;
    }

    return 0;
}