#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class SensorBuffer {
protected:
    double* data;
    size_t size;

public:
    // TODO: 完成构造函数
    SensorBuffer(size_t n = 0);
    SensorBuffer(size_t n, double* data);

    SensorBuffer(const SensorBuffer& other);

    // TODO: 完成析构函数
    virtual ~SensorBuffer();

    // TODO: 完成成员函数
    double get(int id) const;
    void set(int id, double value);
    virtual double average() const;
    virtual void printInfo() const;
};

class TemperatureBuffer : public SensorBuffer {
private:
    string unit;

public:
    // TODO: 完成构造函数
    TemperatureBuffer(size_t n, const string& unit = "C");
    TemperatureBuffer(size_t n, double* init_data, const string& unit = "C");

    TemperatureBuffer(const TemperatureBuffer& other);

    // TODO：完成析构函数
    ~TemperatureBuffer();

    // TODO: 完成成员函数
    void printInfo() const;
};