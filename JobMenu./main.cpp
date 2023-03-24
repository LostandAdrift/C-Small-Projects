#include <iostream>
#include <string>
#include <ctype.h>
#include "Inventory.h"

// Prototypes 
void displayMenu();
void displayJobData(const Inventory * );
std::string promptName();
std::string promptLicense();
std::string promptOwnerPhone();
float promptQuotedPrice();
float getJobSum(const  Inventory *, const int);
bool isNumberInString(const std::string);
bool isCharInString(const std::string);

// Array size constant
const int ARRAY_SIZE = 5;

int main()
{
    // Initialize Variables
    Inventory dogInventory [ARRAY_SIZE];
    Inventory* inventoryPtr = dogInventory;
    int userChoice;
    int jobTracker = 0; // Keeps track of how many jobs have been entered
    std::string stringChoice;
    std::string newName;
    std::string newLicense;
    std::string newOwnerPhone;
    std::string newPriceQuoted;

    // For Readabiliity
    std::cout << "-----------------------------------------------------" << std::endl;

    // Display menu and execute users' choice
    while (userChoice != 3)
    {
        // Get users decision
        displayMenu();
        std::cout << "Enter Menu Choice: "; 
        std::getline(std::cin, stringChoice);
        userChoice = std::stoi(stringChoice);

        // Execute menu choice
        switch(userChoice)
        {
            // Enter in a new job 
            case 1:
          
                // Execute if inventory isn't full
                if (jobTracker < ARRAY_SIZE)
                {
                    // Enter in data for the job
                    (inventoryPtr + jobTracker) -> setDogName(promptName());
                    (inventoryPtr + jobTracker) -> setDogLicense(promptLicense());
                    (inventoryPtr + jobTracker) -> setOwnerPhone(promptOwnerPhone());
                    (inventoryPtr + jobTracker) -> setPriceQuoted(promptQuotedPrice());
                    
                    // Thank User
                    std::cout << "Thank you we'll take good care of " << (inventoryPtr + jobTracker) -> getDogName()
                     << " today!" << std::endl;

                    // Keep track of how many jobs have gone on
                    jobTracker++;

                }
                else
                {
                    std::cout << "We've reached the inventory limit." << std::endl;
                }
                break;
            
            // List all jobs currently 
            case 2:
                for (int x= 0; x < jobTracker; x++)
                {
                    displayJobData(inventoryPtr + x);
                }

                // Report number of jobs and total cost
                std::cout << "You currently have " << jobTracker << " jobs with a total of $"
                << getJobSum(inventoryPtr, jobTracker) << "!";

                break;
            default:
                break;
        }
        
        // Spacing for readability
        std::cout << std::endl;
    }

    // User selected exit (3)
    std::cout << "Thanks for using the menu system and have a nice day." << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl;
    return 0;
}

// Display Option Menu
void displayMenu()
{
    std::cout << "  You Dirty Dog Menu: " << std::endl;
        std::cout << "(1) Enter a new job" << std::endl <<
        "(2) List all current jobs" << std::endl << "(3) Exit" << std::endl;
}

// Prompt user for a name
std::string promptName()
{
    // Get name for user1
    std::string name;
    std::cout << "Dog Name: "; 
    std::getline(std::cin, name);

    // Prompts user for new input if there is a number in the name or if the name 
    // has more than 10 chars
    while (isNumberInString(name) || name.length() >10)
    {
        // Prompt user for a new name
        std::cout << "Dog name formatting/length incorrect. Try again. " << std::endl;
        std::cout << "Dog Name: ";
        std::getline(std::cin, name);
    }
    
    return name;
}

// Prompt user for a name
std::string promptLicense()
{
    // Get name for user
    std::string license;
    std::cout << "Dog License Number: "; 
    std::getline(std::cin, license);

    // Require user to re-enter license if it has too many characters
    while (license.length() > 9)
    {
        // Prompt user for a new name
        std::cout << "License Numbers should be 9 characters or less." << std::endl;
        std::cout << "Dog License Number: ";
        std::getline(std::cin, license);
    }
    
    return license;
}

// Prompt user for the owners phone number
std::string promptOwnerPhone()
{
    // Get name for user
    std::string ownerPhone;
    std::cout << "Owner Phone Number: "; 
    std::getline(std::cin, ownerPhone);

    // Prompts user for input if the license is greater than 9 characters
    while (ownerPhone.length() >= 11 || isCharInString(ownerPhone))
    {
        // Prompt user for a new name
        std::cout << "Phone Number formatting incorrect or too long." << std::endl;
        std::cout << "Owner Phone Number: "; 
        std::getline(std::cin, ownerPhone);
    }

    return ownerPhone;
}

// Prompt user for the owners phone number
float promptQuotedPrice()
{
    // Get name for user
    std::string price;
    std::cout << "Price: $"; 
    std::getline(std::cin, price);

    // Prompts user for input if the license is greater than 9 characters
    while (isCharInString(price))
    {
        // Prompt user for a new name
        std::cout << "Enter in number only." << std::endl;
        std::cout << "Price: $"; 
        std::getline(std::cin, price);
    }

    return std::stof(price);
}

// Checks to see if there is a number within the string
bool isNumberInString(const std::string string)
{
    // Default, return false
    bool flag = false;
    std::__cxx11::basic_string<char>::size_type length = string.length();

    // Iterate through every character in the string to test if it is a numer
    for (std::__cxx11::basic_string<char>::size_type x = 0; x < length; x++)
    {
        // Set flag to true if digit
        if (isdigit(string[x]))
            flag = true;
    }

    return flag;
}

// Checks if there is a character in the input string
bool isCharInString(const std::string string)
{
    // Default returns false
    bool flag = false;

    // Iterate through input string 
    for (std::__cxx11::basic_string<char>::size_type x=0; x< string.length(); x++)
    {
        // Set the flag to true if alphabetic character
        if (std::isalpha(string[x]))
       {
            flag = true;
       }
    }

    return flag;
}

    // Display job data
    void displayJobData(const Inventory * ptr)
    {
        // Formatting
        std::cout << std::endl;
        // License
        std::cout << ptr -> getDogLicense() << std::endl;
        // Name
        std::cout << ptr -> getDogName() << std::endl;
        // Phone Number
        std::cout << ptr -> getCustPhone() << std::endl;
        // Price
        std::cout << "$" << ptr -> getQuotedPrice() << std::endl;
        // Formatting
        std::cout << "***" << std::endl;
    }

    // Calculate sum of all jobs
    float getJobSum(const Inventory * invPtr, const int jobTotal)
    {
        float sum = 0;
        
        for(int x = 0; x < jobTotal; x++)
        {
            sum += (invPtr + x) -> getQuotedPrice(); 
        }

        return sum;
    }
