// Specification file for the Inventory class
#ifndef INVENTORY_H
#define INVENTORY_H
#include <string>

class Inventory
{
    private:
        std::string dogLicense;
        std::string dogName;
        std::string ownerPhone;
        float priceQuoted;

    public:
        // Default constructor
        Inventory();

        // Constructor with all inputs
        Inventory(std::string license, std::string dogName, 
                  std::string ownerPhone, float priceQuoted);
                  
        // Mutators
        void setDogLicense(std::string dogLicense);
        void setDogName(std::string dogName);
        void setOwnerPhone(std::string ownerPhone);
        void setPriceQuoted(float priceQuoted);
        // Accessors
        std::string getDogLicense() const;
        std::string getDogName() const;
        std::string getCustPhone() const;
        float getQuotedPrice() const;
};

#endif
