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
#include <string>

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

    // Part 5
    double projectedValue( int yearsFromCurrentDate, double annualGrowthPercantage )
    {
        double projectedValue = currentMarketValueUsd;
        for( int i = 0; i < yearsFromCurrentDate; i += 1 )
        {
            projectedValue += currentMarketValueUsd * annualGrowthPercantage;
        }
        std::cout << "In " << yearsFromCurrentDate << " years, the value of this home will have gone from $" << currentMarketValueUsd << " to $" << projectedValue << " assuming a " << (annualGrowthPercantage * 100) << " percent annual growth in value." << std::endl;
        return projectedValue;
    }
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

        EmployeeBenefit( double value ) :
        monetaryValue(value),
        isActiveBenefit(true)
        { }
    };

    // Part 5
    double monetaryValueOfBenefits()
    {
        double value = 0;

        for( int i = 0; i < 3; i ++ )
        {
            value += employeeBenefits[i].monetaryValue;
        }
        std::cout << "Value of benefits is: $" << value << std::endl;
        return value;
    }

    EmployeeBenefit employeeBenefits[3] = { EmployeeBenefit(2500), EmployeeBenefit(5000), EmployeeBenefit(1500) };
};

// 3

struct Song 
{
    struct Tempo
    {
        unsigned int BPM;

        Tempo( unsigned int BPM_ ) : BPM(BPM_) { }

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

    TimeSignature timeSignature;
    KeySignature keySignature;

    // Part 5
    bool incrementTempo( unsigned int currentTempo, unsigned int targetTempo )
    {
        bool didFinishIncrementing = false; 
        Tempo tempo(currentTempo);
        std::cout << "The current tempo is: " << currentTempo << std::endl;

        while ( currentTempo < targetTempo )
        {
            currentTempo ++;

            if ( currentTempo == targetTempo ) 
            {  
                didFinishIncrementing = true;
                std::cout << "The tempo is now: " << currentTempo << std::endl;
                return didFinishIncrementing;
            }
        }
        return didFinishIncrementing;
    }
};

// 4

struct Circle
{
    double radius;
    double diameter;

    Circle( double r ) : radius(r) { diameter = radius * 2.0; }

    double getCircumference();
    double getArea();

    void drawCircle()
    {
        std::cout << "Drawing new circle with radius: " << radius << std::endl;
        // A hypothetical function that would render a circle with a given radius.
    }

    // Part 5
    void drawConcentricCircles( double startingRadius, double maxRadius, double numberOfCircles )
    {
        double currentRadius = startingRadius;
        double increment = (maxRadius - startingRadius) / (numberOfCircles - 1.0);

        while ( currentRadius <= maxRadius + 0.0001 )
        {
            Circle c(currentRadius);
            c.drawCircle();
            currentRadius += increment;
        }
    }
};

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
#include <vector>
struct Airplane
{
    double passengerCapactity { 8 };
    unsigned int numberOfPassengers { 5 };
    double maxTakeoffWeightKg { 20000.0 };
    double maxAllowableWeightForPassengers { 1500.0 };
    bool isCommercialAirliner;

    Airplane() : isCommercialAirliner(true) { }

    double weightAllowedPerPassenger();

    struct Passenger
    {
        std::string name;
        double weightLbs;
        double weightOfLuggageLbs;
        unsigned int numberOfBags;

        Passenger( std::string name_, double weightLbs_, double weightOfLuggageLbs_ ) : 
        name(name_),
        weightLbs(weightLbs_), 
        weightOfLuggageLbs(weightOfLuggageLbs_),
        numberOfBags(2) 
        { }

        Passenger() : Passenger("default", 0, 0) { } //calls the above constructor

        double totalWeightWithLuggageLbs() { return weightLbs + weightOfLuggageLbs; }
    };

    std::vector<Passenger> passengers
    { 
        Passenger("John L.", 175.5, 55.0), 
        Passenger("Phil W.", 223.1, 154.2), 
        Passenger("Sharon C.", 120.7, 25.9),
        Passenger("Scott S.", 201.2, 66.0),
        Passenger("Lisa J.", 115.3, 77.8),
        {}
    };
    
    // Part 5
    Passenger scanForPassengersAboveWeightThreshold()
    {
        for( auto& passenger : passengers ) //loops over every passenger in the vector
        {
            if(passenger.totalWeightWithLuggageLbs() > weightAllowedPerPassenger()) 
            { 
                return passenger; 
            }
        }
        // Would like to return null here but not sure how.
        std::cout << "Passengers are below weight threshold" << std::endl;
        return { };
    }
};

double Airplane::weightAllowedPerPassenger() { return maxAllowableWeightForPassengers / double(numberOfPassengers); }

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
    std::cout << "-----------UTD: House---------------" << std::endl;
    House myHouse;
    myHouse.projectedValue(5, 0.05);
    //2
    std::cout << "-----------UTD: Job---------------" << std::endl;
    Job myJob;
    myJob.monetaryValueOfBenefits();
    //3 
    std::cout << "-----------UTD: Song---------------" << std::endl;
    Song mySong;
    mySong.incrementTempo( 80, 175 );
    //4
    std::cout << "-----------UTD: Circle---------------" << std::endl;
    Circle myCircle(5);
    myCircle.drawConcentricCircles( myCircle.radius, 25, 5 );
    //5
    std::cout << "-----------UTD: Airplane---------------" << std::endl;
    Airplane myAirplane;
    std::cout << "Warning: Passenger above max total weight: " << myAirplane.scanForPassengersAboveWeightThreshold().name << std::endl;
    //6
    Bicycle myBike;
    //8
    Television myTv;
    //
    std::cout << "good to go!" << std::endl;
}
