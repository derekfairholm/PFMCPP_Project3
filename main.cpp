/*
 Project 3 - Part 1 / 5
Video:  Chapter 2 Part 5
 User-Defined Types

 Create a branch named Part1
 
 1) write 10 user-defined types, each with a random number of member variables
    try to make the member variables have names that are related to the user-defined type.
 
 2) give the member variables relevant data types
 
 3) add a couple member functions.  
    make the function parameter list for those member functions use some of your User-Defined Types
 
 4) make 2 of the 10 user-defined types be nested class
 
 5) One of your UDTs should only use UDTs for its member variable types.   
     No primitives allowed!
 
 6) After you finish defining each type, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 */

/*
 example:
 */
struct CarWash            //1) a U.D.T. with a random number of member variables
{
    int numSponges = 3;
    double amountOfSoapUsedPerCar = 2.6; //2) relevant data types
    unsigned int numCarsProcessed = 0;
    
    struct Car                             //4) nested class
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        //2) relevant data types
    };
    
    void washAndWaxCar( Car car );         //3) member function with a user-defined type as the parameter.  The user-defined type parameter happens to be the nested class.
    
    Car myCar;  //5) a member variable whose type is a UDT.
};


//1

struct House 
{
    unsigned int numberOfBedrooms = 3;
    unsigned int numberOfBathrooms = 2;
    unsigned int totalSquareFootage = 2000;
    double currentMarketValueUsd = 250000.00;
    bool hasGarage = true;
    bool availableForRent = false;

    double estimatedMortgagePayment( double interestRate, unsigned int term, double downpaymentUsd );
};

// 2

struct Job
{
    double startingSalaryUsd = 70000.00;
    bool canWorkRemotely = false;
    
    struct EmployeeBenefits
    {
        bool healthCare = true;
        bool dentalCare = true;
        bool companyCar = false;
        bool lifeInsurance = false;
    };

    double monetaryValueOfBenefits( EmployeeBenefits benefits );

    EmployeeBenefits employeeBenefits;
};

// 3

struct Song 
{
    struct Tempo
    {
        unsigned int BPM = 120;

        void updateTempo( unsigned int newTempo );
    };

    struct TimeSignature
    {
        unsigned int topNumber = 4;
        unsigned int bottomNumber = 4;
        bool isCompund = false;
    };

    struct KeySignature
    {
        unsigned int numberSharps = 1;
        unsigned int numberFlats = 0;

        unsigned int positionInCircleOfFifths();
    };   

    Tempo tempo;  // Only UDTs as member variables.
    TimeSignature timeSignature;
    KeySignature keySignature;
};

// 4

struct Circle
{
    double radius = 10.0;
    double diameter = radius * 2.0;

    double getCircumference();
    double getArea();
};

// 5

struct Airplane
{
    unsigned int passengerCapactity = 200;
    double maxTakeoffWeightKg = 80000.0;
    bool isCommercialAirliner = true;

    double maxDistanceAtMaxWeight();
    double weightAllowedPerPassenger();

    struct Passenger
    {
        double weightLbs = 175.4;
        double weightOfLuggageLbs = 200.0;
        unsigned int numberOfBags = 2;

        double totalWeightWithLuggageLbs();
    };

    // Would do more with the 'Passenger' type here, maybe with an array but I'm new to C++ and don't know syntax / best practice for initializing etc.
};

//6

struct Bicycle
{
    double weightKg = 7.9;
    unsigned int size = 58; 

    float recommendedTirePressure( float riderWeightInLBS , float maxTirePressure );

    enum BicycleType // Is this OK? I realize it's not a class but it just made sense to me.
    {
        road, mountain, hybrid
    };

    BicycleType type;
};

// 7

struct Keyboard
{
    unsigned int numberOfKeys = 73;
    double totalWeightKg = 11.4;
    bool isWeighted = true;
    bool hasUSBOutput = true;
    bool hasOnboardEffects = true;
};

// 8

struct Television
{
    double totalWeightKg = 22.1;
    double widthIn = 50.5;
    double heightIn = 30.0;
    bool isSmartTV = true;

    double getScreenSize();
};

//


#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
