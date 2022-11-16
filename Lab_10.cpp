#include <iostream>
#include <vector>
#include <string>

class Car
{
private:
    unsigned int m_id;
    std::string m_model;
    std::vector <Wheel*> m_wheels;
    Engine m_engine;
    Tank m_tank;

public:
    Car(unsigned int id, std::string model, Engine engine, Tank tank)
    {
        m_id = id;
        m_model = model;
        m_engine = engine;
        m_tank = tank;
    }

    void add_wheel(Wheel*& wheel)
    {
        m_wheels.push_back(wheel);
    }

    void print_components()
    {
        std::cout << "Model: " << m_model << std::endl;
        std::cout << "Wheels: " << std::endl;
        
        for (int i = 0; i < m_wheels.size(); i++)
        {
            std::cout << "\t" << m_wheels[i]->position() << std::endl;
        }
    }
};

class Wheel
{
private:
    unsigned int m_id;
    std::string m_position;
    int m_width;
    int m_diameter;

public:
    Wheel(unsigned int id, std::string position, int width, int diameter)
    {
        m_id = id;
        m_position = position;
        m_width = width;
        m_diameter = diameter;
    }

    std::string position()
    {
        return m_position;
    }

    int width()
    {
        return m_width;
    }

    int diameter()
    {
        return m_diameter;
    }
};

class Engine
{
private:
    unsigned int m_id;
    unsigned int m_power;
    unsigned int m_fuel_usage;

public:
    Engine(){}
    
    Engine(unsigned int id, unsigned int power, unsigned int fuel_usage)
    {
        m_id = id;
        m_power = power;
        m_fuel_usage = fuel_usage;
    }
};

class Tank
{
private:
    unsigned int m_id;
    unsigned int m_max_volume;
    unsigned int m_current_volume;

public:
    Tank(){}

    Tank(unsigned int id, unsigned int max_volume, unsigned int current_volume)
    {
        m_id = id;
        m_max_volume = max_volume;
        m_current_volume = current_volume;
    }
};


int main()
{
    Engine engine1(1, 5000, 50);
    Tank tank1(2, 100, 70);

    Car car1(3, "Koyoka", engine1, tank1);
}
