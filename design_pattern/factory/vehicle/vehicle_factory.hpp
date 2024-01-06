#ifndef __vehicle_factory_hpp__
#define __vehicle_factory_hpp__

#include "vehicle.hpp"
#include "car.hpp"

class vehicle_factory
{
    public:
        static vehicle* create_vehicle(std::string vehicle_type);
};

#endif
