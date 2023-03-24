// Implementation file for the Inventory class
#include <iostream>
#include <string>
#include "Inventory.h"

// Default Constructor
Inventory::Inventory()
{
    this->dogLicense = "";
    this->dogName = "";
    this->ownerPhone = "";
    this->priceQuoted = 0; 
}

// Constructor with all input data
Inventory::Inventory(std::string c_license, std::string c_dogName, std::string c_ownerPhone, float c_priceQuoted)
{
    this->dogLicense = c_license;
    this->dogName = c_dogName;
    this->ownerPhone = c_ownerPhone;
    this->priceQuoted = c_priceQuoted; 
}

// Mutators
void Inventory::setDogLicense(std::string m_dogLicense)
{
    // Exit program if length is incorrect
    if (m_dogLicense.length() > 9 )
    {
        std::cout << "Dog License String Fault" << std::endl;
        exit(EXIT_FAILURE);
    }
    else
        this->dogLicense = m_dogLicense;
}

void Inventory::setDogName(std::string m_dogName)
{
    // Exit if a digit is in the name 
    for (std::__cxx11::basic_string<char>::size_type x = 0; x < m_dogName.length(); x++)
    {
        if (std::isdigit(m_dogName[x]))
        {
            exit(EXIT_FAILURE);
        }
    }

    // Exit if length of dogName is too long
    if (dogName.length() > 14)
    {
        exit(EXIT_FAILURE);
    }

    this->dogName = dogName;
}

void Inventory::setOwnerPhone(std::string m_ownerPhone)
{
    // Exit if an alphabetical character is in the phone number
    for (std::__cxx11::basic_string<char>::size_type x = 0; x < m_ownerPhone.length(); x++)
    {
        if (std::isalpha(m_ownerPhone[x]))
            exit(EXIT_FAILURE);
    }

    // Exit if input is too long
    if (ownerPhone.length() > 10)
        exit(EXIT_FAILURE);

    this->ownerPhone = ownerPhone;
}

void Inventory::setPriceQuoted(float m_priceQuoted)
{
    this->priceQuoted = m_priceQuoted;
}

// Accessors
std::string Inventory::getDogLicense() const
{
    return dogLicense;
}

std::string Inventory::getDogName() const
{
    return dogName;
}

std::string Inventory::getCustPhone() const
{
    return ownerPhone;
}

float Inventory::getQuotedPrice() const
{
    return priceQuoted;
}
