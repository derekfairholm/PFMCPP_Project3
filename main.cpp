/*
 Project 3 - Part 4 / 5
 video: Chapter 2 - Part 9
 Member initialization tasks

 Create a branch named Part4
 
 1) initialize some of your member variables either in-class or in the Constructor member initializer list.

 2) make some of your member functions use those initialized member variables via std::cout statements.
 
 3) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 */

#include <iostream>
namespace Example 
{
struct UDT  
{
    int a; //a member variable
    float b { 2.f }; //3) in-class initialization
    UDT() : a(0) { } //3) 'constructor-initializer-list' member variable initialization
    void printThing()  //the member function
    {
        std::cout << "UDT::printThing() a:" << a << " b: " << b << std::endl;  //4) printing out something interesting
    }
};

int main()
{
    UDT foo; //instantiating a Foo in main()
    foo.printThing(); //calling a member function of the instance that was instantiated.
    return 0;
}
}


#include <iostream>
#include <cmath>

//1

struct House 
{
    unsigned int numberOfBedrooms;
    unsigned int numberOfBathrooms;
    unsigned int totalSquareFootage;
    double currentMarketValueUsd;
    bool hasGarage;
    bool availableForRent;

    House()
    {
        numberOfBedrooms = 3;
        numberOfBathrooms = 2;
        totalSquareFootage = 2000;
        currentMarketValueUsd = 250000.00;
        hasGarage = true;
        availableForRent = false;
    }

    double estimatedMortgagePayment( double interestRate, double term, double downpaymentUsd );
};

double House::estimatedMortgagePayment( double interestRate, double term, double downpaymentUsd )
{
    double principalLoanAmount = currentMarketValueUsd - downpaymentUsd;
    double monthlyInterestRate = interestRate / 12;
    double totalNumberOfPayments = term * 12;

    double estimate = (principalLoanAmount * monthlyInterestRate) / (1 - pow(1 + monthlyInterestRate, -totalNumberOfPayments));

    std::cout << "Estimated mortgage payment: $" << estimate << std::endl;

    return estimate;
}

// 2

struct Job
{
    double startingSalaryUsd;
    bool canWorkRemotely;

    Job() 
    {
        startingSalaryUsd = 70000.00;
        canWorkRemotely = false;
    }
    
    struct EmployeeBenefit
    {
        double monetaryValue;
        bool isActiveBenefit;

        EmployeeBenefit() 
        {
            monetaryValue = 2500.00;
            isActiveBenefit = true;
        }
    };

    double monetaryValueOfBenefits()
    {
        double value = employeeBenefits[0].monetaryValue;
        std::cout << "Value of benefits is: $" << value << std::endl;
        return value;
    }

    EmployeeBenefit employeeBenefits[1] = { EmployeeBenefit() };
};

// 3

struct Song 
{
    struct Tempo
    {
        unsigned int BPM;

        Tempo() { BPM = 120; }

        void updateTempo( unsigned int newTempo ) 
        { 
            BPM = newTempo; 
            std::cout << "New tempo is: " << newTempo << " BPM" << std::endl; 
        }
    };

    struct TimeSignature
    {
        unsigned int topNumber;
        unsigned int bottomNumber;
        bool isCompund;

        TimeSignature()
        {
            topNumber = 4;
            bottomNumber = 4;
            isCompund = false;
        }
    };

    struct KeySignature
    {
        bool isSharpKey;
        unsigned int numberAccidentals;

        KeySignature()
        {
            isSharpKey = false;
            numberAccidentals = 4;
        }

        unsigned int positionInCircleOfFifths()
        {
            unsigned int position;
            if ( isSharpKey ) { position = numberAccidentals; }
            else { position = 13 - numberAccidentals; }
            std::cout << "Position in circle of fifths is: " << position << std::endl;
            return position;
        }
    };   

    Tempo tempo;  // Only UDTs as member variables.
    TimeSignature timeSignature;
    KeySignature keySignature;
};

// 4

struct Circle
{
    double radius;
    double diameter;

    Circle()
    {
        radius = 10.0;
        diameter = radius * 2.0;
    }

    double getCircumference();
    double getArea();
};

double Circle::getCircumference()
{
    double circumference = M_PI * diameter;
    std::cout << "Circumference is: " << circumference << std::endl;
    return M_PI * diameter;
}

double Circle::getArea()
{
    double area = M_PI * (pow(radius, 2));
    std::cout << "Area is: " << area << std::endl;
    return M_PI * (pow(radius, 2));
}


// 5

struct Airplane
{
    double passengerCapactity;
    double numberOfPassengers;
    double maxTakeoffWeightKg;
    double maxAllowableWeightForPassengers;
    bool isCommercialAirliner;

    Airplane()
    {
        passengerCapactity = 200;
        numberOfPassengers = 185;
        maxTakeoffWeightKg = 80000.0;
        maxAllowableWeightForPassengers = 20000.0;
        isCommercialAirliner = true;
    }

    double weightAllowedPerPassenger();

    struct Passenger
    {
        double weightLbs;
        double weightOfLuggageLbs;
        unsigned int numberOfBags;

        Passenger()
        {
            weightLbs = 175.4;
            weightOfLuggageLbs = 200.0;
            numberOfBags = 2;
        }

        double totalWeightWithLuggageLbs() { return weightLbs + weightOfLuggageLbs; }
    };

    // Would do more with the 'Passenger' type here, maybe with an array but I'm new to C++ and don't know syntax / best practice for initializing etc.
};

double Airplane::weightAllowedPerPassenger()
{
    double allowableWeight = maxAllowableWeightForPassengers / numberOfPassengers;
    std::cout << "Weight allowed per passenger: " << allowableWeight << std::endl;
    return allowableWeight;
}

//6

struct Bicycle
{
    double weightKg;
    unsigned int size; 

    Bicycle()
    {
        weightKg = 7.9;
        size = 58;
    }

    float recommendedTirePressure( float riderWeightInLBS , float maxTirePressure );

    enum BicycleType
    {
        road, mountain, hybrid
    };

    BicycleType type;
};

float Bicycle::recommendedTirePressure( float riderWeightInLBS, float maxTirePressure )
{
    float tirePressure = 100;
    if( riderWeightInLBS > 200 && maxTirePressure > 120 ) { tirePressure = 120; }
    std::cout << "Recommended pressure is: " << tirePressure << std::endl;
    return tirePressure;
}

// 7

struct Keyboard
{
    unsigned int numberOfKeys;
    double totalWeightKg;
    bool isWeighted;
    bool hasUSBOutput;
    bool hasOnboardEffects;

    Keyboard()
    {
        numberOfKeys = 73;
        totalWeightKg = 11.4;
        isWeighted = true;
        hasUSBOutput = true;
        hasOnboardEffects = true;
    }
};

// 8

struct Television
{
    double totalWeightKg;
    double widthIn;
    double heightIn;
    bool isSmartTV;

    Television()
    {
        totalWeightKg = 22.1;
        widthIn = 50.5;
        heightIn = 30.0;
        isSmartTV = true;
    }

    double getScreenSize()
    {
        double screenSize = sqrt(pow( widthIn, 2 ) + pow( heightIn, 2 ));
        std::cout << "Screen size is: " << screenSize << std::endl;
        return screenSize;
    }
};


//


#include <iostream>

int main()
{
    Example::main();
    //1
    House myHouse;
    myHouse.estimatedMortgagePayment(0.0425, 30, 5000.00);
    //2
    Job myJob;
    myJob.monetaryValueOfBenefits();
    //3 
    Song mySong;
    mySong.tempo.updateTempo( 145 );
    mySong.keySignature.positionInCircleOfFifths();
    //4
    Circle myCircle;
    myCircle.getCircumference();
    myCircle.getArea();
    //5
    Airplane myAirplane;
    myAirplane.weightAllowedPerPassenger();
    //6
    Bicycle myBike;
    myBike.recommendedTirePressure(175, 110);
    //8
    Television myTv;
    myTv.getScreenSize();
    std::cout << "good to go!" << std::endl;
}
