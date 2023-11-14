//
// Created by 小米 on 14/11/2023.
//

#ifndef PS_GROUP11_ASSIGNMENT1_GS_H
#define PS_GROUP11_ASSIGNMENT1_GS_H

#include <vector>

extern const int width;
extern const int height;
extern double Du;
extern double Dv;                     // Diffusion rate of V
extern double F;                      // Feed rate
extern double k;                    // Kill rate
extern double threshold;
extern const double dt;               // Time step
extern const int numIterations;
extern const int outputInterval;      // Output every 1000 iterations

extern std::vector<std::vector<double>> u;
extern std::vector<std::vector<double>> v;

void init();
void writeVTKFile(int iteration);
void simulateStep();
double countElementsAboveThreshold(double threshold);

#endif //PS_GROUP11_ASSIGNMENT1_GS_H
