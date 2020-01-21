 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */

 struct Limb 
{
    void stepForward();
    int stepSize();
};

void Limb::stepForward()
{

}

int Limb::stepSize()
{

}

struct Person 
{
    int age;
    int height;
    float hairLength;
    float GPA;
    unsigned int SATScore;
    int distanceTraveled;

    Limb rightFoot;
    Limb leftFoot;

    void run( int , bool );
};

void Person::run( int howFast, bool startWithLeftFoot )
{
    if( startWithLeftFoot == true )
    {
        leftFoot.stepForward();
        rightFoot.stepForward();
    } else 
    {
        rightFoot.stepForward();
        leftFoot.stepForward();
    }

    distanceTraveled += leftFoot.stepSize() + rightFoot.stepSize();
}


 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 */


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

double House::estimatedMortgagePayment( double interestRate, unsigned int term, double downpaymentUsd )
{

}

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

double Job::monetaryValueOfBenefits( EmployeeBenefits benefits )
{

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

}

double Circle::getArea()
{

}


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

double Airplane::maxDistanceAtMaxWeight()
{

}

double Airplane::weightAllowedPerPassenger()
{

}

double Airplane::Passenger::totalWeightWithLuggageLbs()
{

}

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

float Bicycle::recommendedTirePressure( float riderWeightInLBS , float maxTirePressure )
{

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

}



//


#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
