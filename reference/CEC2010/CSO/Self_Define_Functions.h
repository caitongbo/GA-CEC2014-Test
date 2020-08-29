#ifndef SELF_DEFINE_FUNCTIONS_H_INCLUDED
#define SELF_DEFINE_FUNCTIONS_H_INCLUDED


#include "./CEC2010/Header.h"
#include <math.h>
#include <boost/random.hpp>
#include <boost/random/uniform_int.hpp>
#include <boost/random/cauchy_distribution.hpp>
#include <boost/random/normal_distribution.hpp>
#include <boost/random/uniform_real.hpp>




const int Population_size = 500;

const int MAX_FV= 5e6;


const int timesOfRun = 30;




Benchmarks* generateFuncObj(int funcID);
double Mode( double i, double j );
void Fitness( double &results, double *particle,  int &FV, Benchmarks* fp );

void Fitness_Computation( double *results, double **population, int &gbest, int num, int dim, int &FV, Benchmarks* fp );
void Global_Mean_Position( double **population, double *global_mean_position, int pop_size, int dim );


#endif // SELF_DEFINE_FUNCTIONS_H_INCLUDED
