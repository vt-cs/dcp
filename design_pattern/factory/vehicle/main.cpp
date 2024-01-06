#include "vehicle.hpp"
#include "car.hpp"


int main(int argc, char **argv)
{
    vehicle *vehicle_obj = nullptr;
    std::string vehicle_type;

    std::cin >> vehicle_type;

    if (vehicle_type == "car")
    {
        vehicle_obj = new car();
    }
    else
    {
        std::cout << "invalid vehicle type" << std::endl;
	return -1;
    }
    vehicle_obj->start_vehicle();

    return 0;
}
