#include "vehicle_factory.hpp"


int main(int argc, char **argv)
{
    vehicle *vehicle_obj = nullptr;
    std::string vehicle_type;

    std::cin >> vehicle_type;

    vehicle_obj = vehicle_factory::create_vehicle(vehicle_type);
    if (vehicle_obj != nullptr)
    {
        vehicle_obj->start_vehicle();
    }

    return 0;
}
