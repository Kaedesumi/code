#include "sensor.h"

// TODO: 完成函数实现
SensorBuffer::SensorBuffer(size_t n) {
    size = n;
    data = new double[size];

    for (size_t i = 0; i < size; i++) {
        data[i] = 0;
    }

    cout << "[SensorBuffer] Constructed, size=" << n << endl;
}





SensorBuffer::SensorBuffer(size_t n, double* data) {
    size = n;
    this->data = new double[size];

    for (size_t i = 0; i < size; i++) {
        this->data[i] = data[i];
    }

    cout << "[SensorBuffer] Constructed, size=" << n << endl;
}






SensorBuffer::SensorBuffer(const SensorBuffer& other)
{
    size = other.size;

    data = new double[size];

    for(size_t i = 0; i < size; i++)
    {
        data[i] = other.data[i];
    }

    cout << "[SensorBuffer] Copied (deep copy)" << endl;
}











//===========析构函数=============
SensorBuffer::~SensorBuffer()
{
    if (data != nullptr)
    {
        delete[] data;
        data = nullptr;
        size = 0;

        cout << "[SensorBuffer] Data released" << endl;
    }
    else
    {
        cout << "[SensorBuffer] Already released" << endl;
    }
}








double SensorBuffer::get(int id) const
{
    return data[id];
}
void SensorBuffer::set(int id, double value)
{
    data[id] = value;
}
double SensorBuffer::average() const
{
    if (size == 0)
    {
        return 0;
    }

    double sum = 0;

    for (size_t i = 0; i < size; i++)
    {
        sum += data[i];
    }

    return sum / size;
}
void SensorBuffer::printInfo() const
{
    cout << "[SensorBuffer] Info: size=" << size << endl;
}
















TemperatureBuffer::TemperatureBuffer(size_t n, const string& unit)
    : SensorBuffer(n), unit(unit)
{
    cout << "[TemperatureBuffer] Constructed, unit=" << unit << endl;
}
TemperatureBuffer::TemperatureBuffer(size_t n, double* init_data, const string& unit)
    : SensorBuffer(n, init_data), unit(unit)
{
    cout << "[TemperatureBuffer] Constructed, unit=" << unit << endl;
}


TemperatureBuffer::TemperatureBuffer(const TemperatureBuffer& other)
    : SensorBuffer(other), unit(other.unit)
{
    cout << "[TemperatureBuffer] Copied from another TemperatureBuffer" << endl;
}


TemperatureBuffer::~TemperatureBuffer()
{
    cout << "[TemperatureBuffer] Destructor called" << endl;
}

void TemperatureBuffer::printInfo() const
{
    cout << "[TemperatureBuffer] Info: unit=" << unit
         << ", size=" << size << endl;
}