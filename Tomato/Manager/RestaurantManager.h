#ifndef RESTAURANTMANAGER_H
#define RESTAURANTMANAGER_H

#include "../Models/Restaurant.h"
#include <vector>
#include <string>
#include <algorithm>

class RestaurantManager{
private:
    std::vector<Restaurant*> restaurants;
public:
    void addRestaurant(Restaurant* restaurant){
        restaurants.push_back(restaurant);
    }
    std::vector<Restaurant*> getRestaurants(){
        return restaurants;
    }

    std::vector<Restaurant*> searchByLocation(std::string location)
    {
        std::transform(location.begin(), location.end(), location.begin(), ::tolower);
        std::vector<Restaurant*> temp;

        for(auto it : restaurants)
        {
            std::string currLocation = it->getRestaurantAddress();
            std::transform(currLocation.begin(), currLocation.end(), currLocation.begin(), ::tolower);

            if(currLocation == location){
                temp.push_back(it);
            }
        }

        return temp;
    }
};

#endif 