


#include <iostream>
#include <iomanip>
#include <cmath>



void prompt();
bool runAgain();
void getTriangle();
bool isTriangle(float,float,float);
float solveAngle(float,float,float);
void solveSSS(float,float,float,float,float,float);
void printResults(float,float,float,float,float,float);



int main() {

    prompt();
    getTriangle();

    return 0;
}



void prompt()
{
    std::cout << "\n --------------------------------------------" << std::endl;
    std::cout << "  Trigonometry Triangle Calculator " << std::endl;
    std::cout << " --------------------------------------------" << std::endl;
    std::cout << " -----------------------------------------------------------------------" << std::endl;
    std::cout << "  This program calculates and angles and sides of a triangle \n  based on a combination of given sides/angles." << std::endl;
    std::cout << " -----------------------------------------------------------------------" << std::endl;
}



void getTriangle()
{
    float   sideA = 0,
            sideB = 0,
            sideC = 0,
            angleA = 0,
            angleB = 0,
            angleC = 0;

    bool userChoice;

    do
    {
        solveSSS(sideA, sideB, sideC, angleA, angleB, angleC);
        userChoice = runAgain();
    } while (userChoice);

    if (!userChoice)
    {
        std::cout << "\n Program Exited. Thank you for running" << std::endl;
    }
}



void solveSSS(float sideA, float sideB, float sideC, float angleA, float angleB, float angleC)
{
    std:: cout << " \n Enter the number length for side A : ";
    std::cin >> sideA;
    std:: cout << " Enter the number length for side B : ";
    std::cin >> sideB;
    std:: cout << " Enter the number length for side C : ";
    std::cin >> sideC;

    if (sideA == sideB && sideB == sideC) // Checks if triangle is equilateral.
    {
        angleA = 60;
        angleB = 60;
        angleC = 60;
    } else
    {
        angleA = solveAngle(sideA, sideB, sideC);
        angleB = solveAngle(sideB, sideA, sideC);
        angleC = solveAngle(sideC, sideA, sideB);
    }

    // Results are printed to the console.
    printResults(sideA, sideB, sideC, angleA, angleB, angleC);
}



float solveAngle(float sideA, float sideB, float sideC)
{
    float angleResult;

    // Solved with the Law of Cosines and converted from radians to degrees.
    angleResult = (float) ((acos((pow(sideA, 2) - pow(sideB, 2) - pow(sideC, 2)) / (-2 * sideB * sideC))) * (180 / 3.14));

    return angleResult;
}



void printResults(float sideA, float sideB, float sideC, float angleA, float angleB, float angleC)
{
    if (isTriangle(sideA, sideB, sideC))
    {
        std::cout << std::setprecision(2) << std::fixed << std::endl; // Prints to the hundredths place.

        std::cout << " Results" << std::endl;
        std::cout << " Side A = " << sideA << "     " << "Angle A ≈ " << angleA << "°" << std::endl;
        std::cout << " Side B = " << sideB << "     " << "Angle B ≈ " << angleB << "°" << std::endl;
        std::cout << " Side C = " << sideC << "     " << "Angle C ≈ " << angleC << "°" << std::endl;
        std::cout << std::endl;
    } else
    {
        std::cout << "\n Side lengths do not equal a triangle." << std::endl;
    }
}



bool runAgain()
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



bool isTriangle(float sideOne, float sideTwo, float sideThree)
{
    // If the sum of two side lengths of are less than the third, then there is no triangle.
    bool sideTest1 = sideOne < sideTwo + sideThree;
    bool sideTest2 = sideTwo < sideOne + sideThree;
    bool sideTest3 = sideThree < sideOne + sideTwo;

    if (sideTest1 && sideTest2 && sideTest3)
    {
        return true;
    }
    else
    {
        return false;
    }
}



