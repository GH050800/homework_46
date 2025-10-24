#include <iostream>
#include <string>

class Engine {
private:
	bool m_status;

public:
	Engine()
	{
		m_status = false;
	}

	void start()
	{
		m_status = true;
		std::cout << "Engine started." << std::endl;
	}

	void stop()
	{
		m_status = false;
		std::cout << "Engine stopped." << std::endl;
	}

	bool engineStatus()
	{
		return m_status;
	}
};

class Car
{
private:
	std::string m_brand;
	std::string m_model;
	Engine m_engine;

public:
	Car(std::string brand, std::string model)
	{
		m_brand = brand;
		m_model = model;
	}

	void engineON()
	{
		m_engine.start();
	}

	void engineOFF()
	{
		m_engine.stop();
	}

	void drive()
	{
		if (m_engine.engineStatus())
		{
			std::cout << "Driving. The engine is ON " << std::endl;
		}
		else
		{
			std::cout << "Cannot drive. The engine is OFF." << std::endl;
		}
	}

	void stop()
	{
		std::cout << "Car stopped." << std::endl;
	}

	void info()
	{
		std::cout << "\nCar Information: " << std::endl;
		std::cout << "Brand: " << m_brand << std::endl;
		std::cout << "Model: " << m_model << std::endl;
	}
};

class Driver {
private:
	std::string m_name;

public:
	Driver(std::string name)
	{
		m_name = name;
	}

	void StartCar(Car& car)
	{
		car.engineON();
	}

	void StopCar(Car& car)
	{
		car.engineOFF();
	}

	void DriveCar(Car& car)
	{
		car.drive();
	}

	void StopDrivingCar(Car& car)
	{
		car.stop();
	}
};

int main()
{
	Car car1("Nissan", "Versa");	
	Driver driver1("Garnik");
	
	driver1.StartCar(car1);
	driver1.DriveCar(car1);
	driver1.StopDrivingCar(car1);
	driver1.StopCar(car1);

    return 0;
}