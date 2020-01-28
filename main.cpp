/*
 Project 3 - Part 5 / 5
 video: Chapter 2 - Part 10
 Scope and Lifetime tasks
 
Create a branch named Part5

 video covered:
    variable scope and lifetime relative to { }
    while loops
    for loops()
 
 tasks
 
 1) add some new member functions to your types. 
 
 2) use while() or for() loops to do something interesting inside these new member functions.
         a) for example: have a loop that modifies a member variable of some object created outside the loop.
         b) when that member variable reaches a certain threshold, return it mid-loop.
         c) maybe use function parameters to control the starting value of that member variable or control the threshold
         
 3) call those new member functions in main()
 
 4) use std::cout statements to print out information about what your loops did.
 
 5) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 
 example:
 */

#include <iostream>
namespace Example {
struct Bar 
{ 
    int num = 0; 
    Bar(int n) : num(n) { } 
};
struct Foo
{
    Bar scopeLifetimeFunc( int threshold, int startingVal ) //3), 4c) 
    {
        Bar bar(startingVal);                //4a)
        while( bar.num < threshold )         //4a) 
        { 
            bar.num += 1;                    //4a)
            
            if( bar.num >= threshold )       //4b)
                return bar;
        }
        
        return Bar {-1}; //if your startingValue >= threshold, the while loop never runs
    }
};

int main()
{
    Foo foo;
    auto bar = foo.scopeLifetimeFunc(3, 1);        //5) 
    
    std::cout << "bar.num: " << bar.num << std::endl;     //6) 
    return 0;
}
}


#include <iostream>
#include <cmath>

//1

struct House 
{
    House();
    unsigned int numberOfBedrooms { 3 };
    unsigned int numberOfBathrooms { 2 };
    unsigned int totalSquareFootage;
    double currentMarketValueUsd;
    bool hasGarage;
    bool availableForRent;

    void numberBedsAndBaths() 
    { 
        std::cout << "This house has " << numberOfBedrooms << " bedrooms and " << numberOfBathrooms << " bathrooms." << std::endl;
    }
    double estimatedMortgagePayment( double interestRate, double term, double downpaymentUsd );
};

House::House() :
totalSquareFootage(2000),
currentMarketValueUsd(250000.00)
{
    hasGarage = true;
    availableForRent = false;
}

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
    double startingSalaryUsd { 70000 };
    bool canWorkRemotely = true;
    
    struct EmployeeBenefit
    {
        double monetaryValue;
        bool isActiveBenefit;

        EmployeeBenefit() :
        monetaryValue(2500.00),
        isActiveBenefit(true)
        { }
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

        Tempo() : BPM(120) { }

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
        bool isCompund = false;

        TimeSignature() : topNumber(4), bottomNumber(4) { }
    };

    struct KeySignature
    {
        bool isSharpKey { false };
        unsigned int numberAccidentals;

        KeySignature() : numberAccidentals(4) { }

        unsigned int positionInCircleOfFifths()
        {
            unsigned int position;
            if ( isSharpKey ) { position = numberAccidentals; }
            else { position = 13 - numberAccidentals; }
            std::cout << "This key has " << numberAccidentals << " accidentals and is in position number " << position << " in the circle of fifths." << std::endl;
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

    Circle();

    double getCircumference();
    double getArea();
};

Circle::Circle() : radius(10.0) { diameter = radius * 2.0; }

double Circle::getCircumference()
{
    double circumference = M_PI * diameter;
    std::cout << "The diameter is: " << diameter << " and the circumference is: " << circumference << std::endl;
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
    double passengerCapactity { 200 };
    double numberOfPassengers { 185 };
    double maxTakeoffWeightKg { 80000.0 };
    double maxAllowableWeightForPassengers { 20000.0 };
    bool isCommercialAirliner;

    Airplane() : isCommercialAirliner(true) { }

    double weightAllowedPerPassenger();

    struct Passenger
    {
        double weightLbs { 175.4 };
        double weightOfLuggageLbs { 200.0 };
        unsigned int numberOfBags;

        Passenger() : numberOfBags(2) { }

        double totalWeightWithLuggageLbs() 
        { 
            double totalWeight = weightLbs + weightOfLuggageLbs;
            std::cout << "The total weight of this passenger is: " << totalWeight <<  " Lbs" << std::endl;
            return totalWeight; 
        }
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
    unsigned int size { 58 }; 

    Bicycle() : weightKg(7.9) { }

    void bikeSpecs() { std::cout << "This bike weighs " <<  weightKg << " kg and is a size "  << size << std::endl; }
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
    bool isWeighted = true;
    bool hasUSBOutput = true;
    bool hasOnboardEffects = true;

    Keyboard();
};

Keyboard::Keyboard() : numberOfKeys(73), totalWeightKg(11.4) { }

// 8

struct Television
{
    double totalWeightKg { 22.1 };
    double widthIn { 50.5 };
    double heightIn { 30.0 };
    bool isSmartTV;

    Television() : isSmartTV(true) { }

    double getScreenSize()
    {
        double screenSize = sqrt(pow( widthIn, 2 ) + pow( heightIn, 2 ));
        std::cout << "This TV has a width / height of: " << widthIn << " by " << heightIn << " inches" << std::endl;
        std::cout << "The screen size is: " << screenSize << " inches" << std::endl;
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
    myHouse.numberBedsAndBaths();
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
    Airplane::Passenger myPassenger;
    myPassenger.totalWeightWithLuggageLbs();
    //6
    Bicycle myBike;
    myBike.bikeSpecs();
    myBike.recommendedTirePressure(175, 110);
    //8
    Television myTv;
    myTv.getScreenSize();
    std::cout << "good to go!" << std::endl;
}
