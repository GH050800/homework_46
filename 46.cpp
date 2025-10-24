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
};

class Car
{
private:
	std::string m_brand;
	std::string m_model;
	bool m_engineStatus;
	Engine* m_engine;

	void engineCheck()
	{
		std::cout << "Engine started." << std::endl;
	}

public:
	Car(std::string brand, std::string model, Engine* engine)
	{
		m_brand = brand;
		m_model = model;
		m_engineStatus = false;
		m_engine = engine;
	}

	void engineON()
	{
		if (m_engine)
		{
			m_engine->start();
			m_engineStatus = true;
		}
	}

	void engineOFF()
	{
		if (m_engine)
		{
			m_engine->stop();
			m_engineStatus = false;
		}
	}

	void drive()
	{
		if (m_engineStatus)
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
	Engine engine1;
	Car car1("Nissan", "Versa", &engine1);	
	Driver driver1("Garnik");
	
	driver1.StartCar(car1);
	driver1.DriveCar(car1);
	driver1.StopDrivingCar(car1);
	driver1.StopCar(car1);

    return 0;
}