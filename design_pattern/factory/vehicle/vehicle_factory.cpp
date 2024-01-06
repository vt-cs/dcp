#include "vehicle_factory.hpp"

vehicle* vehicle_factory::create_vehicle(std::string vehicle_type)
{
    if (vehicle_type == "car")
    {
        return new car();
    }
    else
    {
        return nullptr;
    }
}
