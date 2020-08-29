
#include "Self_Define_Functions.h"


/*
*
*
*
*
*
*
*
*
*
*
*
*
*/


// create new object of class for different functions
Benchmarks* generateFuncObj(int funcID)
{
	Benchmarks *fp;
	// run each of specified function in "configure.ini"
	if (funcID==1){
		fp = new F1();
	}else if (funcID==2){
		fp = new F2();
	}else if (funcID==3){
		fp = new F3();
	}else if (funcID==4){
		fp = new F4();
	}else if (funcID==5){
		fp = new F5();
	}else if (funcID==6){
		fp = new F6();
	}else if (funcID==7){
		fp = new F7();
	}else if (funcID==8){
		fp = new F8();
	}else if (funcID==9){
		fp = new F9();
	}else if (funcID==10){
		fp = new F10();
	}else if (funcID==11){
		fp = new F11();
	}else if (funcID==12){
		fp = new F12();
	}else if (funcID==13){
		fp = new F13();
	}else if (funcID==14){
		fp = new F14();
	}else if (funcID==15){
		fp = new F15();
	}else if (funcID==16){
		fp = new F16();
	}else if (funcID==17){
		fp = new F17();
	}else if (funcID==18){
		fp = new F18();
	}else if (funcID==19){
		fp = new F19();
	}else if (funcID==20){
		fp = new F20();
	}else{
		cerr<<"Fail to locate Specified Function Index"<<endl;
		exit(-1);
	}
	return fp;
}



double Mode( double i, double j )
{
    while( i > j)
    {
        i -= j;
    }
    return i;
}

void Fitness( double &results, double *particle,  int &FV, Benchmarks* fp )
{
    results =  fp->compute( particle );
    FV++;
}


//Fitness Computation
void Fitness_Computation( double *results, double **population, int &gbest, int num, int dim, int &FV, Benchmarks* fp )
{// num is the population size and dim is the size of dimensions
    int i;
    double best = results[0] = fp->compute( population[0] );
    gbest = 0;
    for( i = 1; i < num; ++i )
    {
        results[i] = fp->compute( population[i]);

        if( results[i] < best )
        {
            best = results[i];
            gbest = i;

        }
    }

    FV += num;
}

//caculate the mean position of current population
void Global_Mean_Position( double **population, double *global_mean_position, int pop_size, int dim )
{
    int i, j;
    for( i = 0 ; i < dim; ++i )
    {
        double sum = 0;
        for( j = 0; j < pop_size; ++j )
            sum += population[j][i];
        global_mean_position[i] = sum / pop_size;
    }
}











