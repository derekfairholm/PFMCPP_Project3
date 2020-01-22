/*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On a new branch:

 1) Add a constructor for each User-Defined-Type.
 
 2) Instantiate a few of your user-defined types in the main function at the bottom of that file, and call some of those member functions.
 
 3) make them print out something interesting via std::cout
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type
{
    int a; //a member variable
    UDT() { a = 0; }             //3) the constructor
    void printThing()            //1) the member function
    {
        std::cout << "UDT::printThing() " << a << std::endl;  //5) printing out something interesting
    }
};

int main()
{
    UDT foo;              //4) instantiating a UDT in main()
    foo.printThing();     //4) calling a member function of the instance that was instantiated.
    
    return 0;
}
}

//insert  into main() of user's repo.



//1

struct House 
{
    unsigned int numberOfBedrooms = 3;
    unsigned int numberOfBathrooms = 2;
    unsigned int totalSquareFootage = 2000;
    double currentMarketValueUsd = 250000.00;
    bool hasGarage = true;
    bool availableForRent = false;

    double estimatedMortgagePayment( double interestRate, double term, double downpaymentUsd );
};

double House::estimatedMortgagePayment( double interestRate, double term, double downpaymentUsd )
{
    double principalLoanAmount = currentMarketValueUsd - downpaymentUsd;
    double monthlyInterestRate = interestRate / 12;
    double totalNumberOfPayments = term * 12;

    double blockOne = pow((monthlyInterestRate * (1 + monthlyInterestRate)), totalNumberOfPayments);
    double blockTwo = (pow((1 + monthlyInterestRate), totalNumberOfPayments)) - 1;

    return principalLoanAmount * (blockOne * blockTwo);
}

// 2

struct Job
{
    double startingSalaryUsd = 70000.00;
    bool canWorkRemotely = false;
    
    struct EmployeeBenefit
    {
        double monetaryValue;
        bool isActiveBenefit;
    };

    double monetaryValueOfBenefits( EmployeeBenefit benefits[] );

    EmployeeBenefit employeeBenefit[3] = {};
};

double Job::monetaryValueOfBenefits( EmployeeBenefit benefits[] )
{
    double totalValue;

    totalValue = benefits[0].monetaryValue + benefits[1].monetaryValue + benefits[0].monetaryValue;
    // Here I would iterate through the 'benefits' array and call totalValue += benefit[i].monetaryValue after checking benefit[i].isActiveBenefit.

    return totalValue;
}

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

void Song::Tempo::updateTempo( unsigned int newTempo )
{

}

unsigned int Song::KeySignature::positionInCircleOfFifths() 
{
    return {};
}


// 4

struct Circle
{
    double radius = 10.0;
    double diameter = radius * 2.0;

    double getCircumference();
    double getArea();
};

double Circle::getCircumference()
{
    return M_PI * diameter;
}

double Circle::getArea()
{
    return M_PI * (pow(radius, 2));
}


// 5

struct Airplane
{
    double passengerCapactity = 200;
    double numberOfPassengers;
    double maxTakeoffWeightKg = 80000.0;
    double maxAllowableWeightForPassengers;
    bool isCommercialAirliner = true;

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

double Airplane::weightAllowedPerPassenger()
{
    return maxAllowableWeightForPassengers / numberOfPassengers;
}

//6

struct Bicycle
{
    double weightKg = 7.9;
    unsigned int size = 58; 

    float recommendedTirePressure( float riderWeightInLBS , float maxTirePressure );

    enum BicycleType
    {
        road, mountain, hybrid
    };

    BicycleType type;
};

float Bicycle::recommendedTirePressure( float riderWeightInLBS, float maxTirePressure )
{
    if( riderWeightInLBS > 200 && maxTirePressure > 120 )
    {
        return 120;
    }

    return 100;
}

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

double Television::getScreenSize()
{
    return pow( widthIn, 2 ) + pow( heightIn, 2 );
}



//


#include <iostream>

int main()
{
    Example::main();
    std::cout << "good to go!" << std::endl;
}
