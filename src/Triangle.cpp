
// Implementation File


#include "Triangle.h"
#include <iostream>
#include <iomanip>
#include <cmath>



Triangle::Triangle()
{
    sideA = 0,
    sideB = 0,
    sideC = 0,
    angleA = 0,
    angleB = 0,
    angleC = 0;
}



void Triangle::prompt()
{
    std::cout << "\n --------------------------------------------" << std::endl;
    std::cout << "  Trigonometry Triangle Calculator " << std::endl;
    std::cout << " --------------------------------------------" << std::endl;
    std::cout << " -----------------------------------------------------------------------" << std::endl;
    std::cout << "  This program calculates and angles and sides of a triangle" << std::endl;
    std::cout << "  based on a combination of given sides/angles." << std::endl;
    std::cout << " -----------------------------------------------------------------------" << std::endl;
}



void Triangle::getTriangle()
{
    bool userChoice;

    do
    {
        solveSSS();
        userChoice = runAgain();
    } while (userChoice); // Loops program until user does not enter 'Y'.

    if (!userChoice)
    {
        std::cout << "\n Program Exited. Thank you for running" << std::endl;
    }
}



void Triangle::solveSSS()
{
    std:: cout << " \n Enter the number length for side A : ";
    std::cin >> this->sideA;
    std:: cout << " Enter the number length for side B : ";
    std::cin >> this->sideB;
    std:: cout << " Enter the number length for side C : ";
    std::cin >> this->sideC;

    if ((this->sideA == this->sideB) && (this->sideB == this->sideC)) // Checks if triangle is equilateral.
    {
        this->angleA = 60;
        this->angleB = 60;
        this->angleC = 60;
    } else
    {
        this->angleA = solveAngle(this->sideA, this->sideB, this->sideC);
        this->angleB = solveAngle(this->sideB, this->sideA, this->sideC);
        this->angleC = solveAngle(this->sideC, this->sideA, this->sideB);
    }

    // Results are printed to the console.
    printResults();
}



float Triangle::solveAngle(float sideA, float sideB, float sideC)
{
    float angleResult;

    // Solved with the Law of Cosines and converted from radians to degrees.
    angleResult = (float) ((acos((pow(sideA, 2) - pow(sideB, 2) - pow(sideC, 2)) / (-2 * sideB * sideC))) * (180 / 3.14));

    return angleResult;
}



void Triangle::printResults()
{
    if (isTriangle(this->sideA, this->sideB, this->sideC))
    {
        std::cout << std::setprecision(2) << std::fixed << std::endl; // Prints to the hundredths place.

        std::cout << " Results" << std::endl;
        std::cout << " Side A = " << this->sideA << "     " << "Angle A ≈ " << this->angleA << "°" << std::endl;
        std::cout << " Side B = " << this->sideB << "     " << "Angle B ≈ " << this->angleB << "°" << std::endl;
        std::cout << " Side C = " << this->sideC << "     " << "Angle C ≈ " << this->angleC << "°" << std::endl;
        std::cout << std::endl;
    } else
    {
        std::cout << "\n Side lengths do not equal a triangle." << std::endl;
    }
}



bool Triangle::runAgain()
{
    char userInput;

    std::cout << std::endl;
    std::cout << " Would you like to run again? Y/N : ";
    std::cin >> userInput;

    if (userInput == 'Y' || userInput == 'y')
    {
        return true;
    } else
    {
        return false;
    }
}



bool Triangle::isTriangle(float sideOne, float sideTwo, float sideThree)
{
    // If the sum of two side lengths of are less than the third, then there is no triangle.
    bool sideTest1 = sideOne < sideTwo + sideThree;
    bool sideTest2 = sideTwo < sideOne + sideThree;
    bool sideTest3 = sideThree < sideOne + sideTwo;

    if (sideTest1 && sideTest2 && sideTest3)
    {
        return true;
    } else
    {
        return false;
    }
}
