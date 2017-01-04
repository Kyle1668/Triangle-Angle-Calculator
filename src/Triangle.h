
// Header File


#ifndef TRIANGLE_CALCULATOR_TRIANGLE_H
#define TRIANGLE_CALCULATOR_TRIANGLE_H


class Triangle {
    private:
        float   sideA = 0,
                sideB = 0,
                sideC = 0,
                angleA = 0,
                angleB = 0,
                angleC = 0;

    public:
        Triangle();
        void prompt();
        bool runAgain();
        void solveSSS();
        void getTriangle();
        void printResults();
        float solveAngle(float sideA, float sideB, float sideC);
        bool isTriangle(float sideOne, float sideTwo, float sideThree);
};


#endif //TRIANGLE_CALCULATOR_TRIANGLE_H
