#include "./CEC2010/Header.h"


#include "Self_Define_Functions.h"

#include <sys/time.h>
#include <cstdio>
#include <unistd.h>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include <string>
#include <boost/random.hpp>
#include <boost/random/uniform_int.hpp>
#include <boost/random/cauchy_distribution.hpp>
#include <boost/random/normal_distribution.hpp>
#include <boost/random/uniform_real.hpp>


using namespace std;


// in this program the global best solution is updated after each subgroup finish iterating itself
int main(int argc, char *argv[])
{


//////////////////////////global processing/////////////////////////////////////
    Benchmarks *fp = NULL;
    int dim = 1000;
    //int funToRun[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};  //function set
    int funToRun[] = {6,7,8,9,10};
    //int funToRun[] = {11,12,13,14,15};
    //int funToRun[] = {16,17,18,19,20};
    int funNum = 5; //total function num

	/////////////////////////////////////////////////////////////////////////////////////
    boost::mt19937 generator(time(0)*rand());

    int i , j,k,t, a;

    int record_FV_set[] = { 500000,1000000,1500000,2000000,2500000,3000000,3500000,4000000,4500000,5000000}; // record results when the number of fitness evaluations is greater than the elements in the set
    int record_set_size = 10;
    int counter = 0;
    int FV = 0;

    //store the index in order to shuffle
    int *population_index = new int[ Population_size ];


    int gl_best = 0;

    double **result_all_run = new double*[timesOfRun];
    for( i = 0; i < timesOfRun; ++i )
        result_all_run[i] = new double[record_set_size];


    double *final_global_best = new double[ dim ];
    double final_val;


    double **population = new double*[ Population_size ];
    double **speed = new double*[ Population_size ];
    for( i =0; i < Population_size; ++ i )
    {
        population[i] = new double [dim];
        speed[i] = new double [dim];
    }

    double *results = new double[ Population_size ];// the fitness results for the whole population
    double *half_results = new double [ Population_size/2 ];//the fitness results for the updated population, because in every loop, there are only half population updated

    int *updated_index = new int [ Population_size/2 ];//the index of population updated

    double **updated_population = new double*[ Population_size/2 ];//the pointer of updated population


    int winner, loser;


    double phi = 0.1;

    double *global_mean_position = new double[ dim ];



    for ( k=0; k<funNum; k++)
    {
        cout<<"Function "<<funToRun[k]<<" Begined!"<<endl;

        fp = generateFuncObj(funToRun[k]);
        FV = 0;

        for( i = 0; i< Population_size; ++i )
          population_index[i] = i;


        // to initialize the population
        boost::uniform_real<> uniform_real_generate_x( fp->getMinX(), fp->getMaxX() );
        boost::variate_generator< boost::mt19937&, boost::uniform_real<> > random_real_num_x( generator, uniform_real_generate_x );

        boost::uniform_real<> uniform_real_generate_r( 0, 1 );
        boost::variate_generator< boost::mt19937&, boost::uniform_real<> > random_real_num_r( generator, uniform_real_generate_r );



        char fun[10];
        snprintf(fun,10,"%d",funToRun[k]);
        string filename_fitness = "./Results/Fitness_result_for_function_"+ string(fun)+".txt";

        ofstream out_fitness(filename_fitness.c_str());


        if(!out_fitness)
        {
            cerr<<"Can not open the file " <<filename_fitness<<endl;
            exit(1);
        }


          for (t=0; t < timesOfRun; t++)
          {
                cout<<"Running the "<<t<<"th time"<<endl;
                FV = 0;
                counter = 0;
                // initialize the population
                for( i =0 ; i < Population_size; ++i )
                    for( j =0; j < dim; ++j )
                    {
                        population[i][j] = random_real_num_x();

                        speed[i][j] = 0;
                    }

                Fitness_Computation( results, population, gl_best, Population_size, dim, FV, fp );

                final_val = results[gl_best];
                memcpy( final_global_best, population[gl_best], sizeof(double)*dim );

                while( FV < MAX_FV )
                {


                    if( FV >= record_FV_set[counter] )
                    {
                        result_all_run[t][counter] = final_val;
                        counter++;
                    }

                    Global_Mean_Position( population, global_mean_position, Population_size, dim );

                    // shuffle the permutation of all population
                    random_shuffle( population_index, population_index + Population_size );


                    for( i = 0, a = 0; i < Population_size; i += 2, ++a )
                    {

                        if( results[population_index[i]] < results[population_index[i+1]] )
                        {
                            winner = population_index[i];
                            updated_index[a] = loser = population_index[i+1];
                        }
                        else
                        {
                            winner = population_index[i+1];
                            updated_index[a] = loser = population_index[i];
                        }

                        //update loser
                        for( j =0; j < dim; ++j )
                        {
                            double r1 = random_real_num_r();
                            double r2 = random_real_num_r();
                            double r3 = random_real_num_r();
                            //cout<<r1<<"\t"<<r2<<"\t"<<r3<<endl;
                            speed[loser][j] = r1 * speed[loser][j] + r2* ( population[winner][j] - population[loser][j] ) + phi * r3 * ( global_mean_position[j] - population[loser][j] );
                            population[loser][j] = population[loser][j] + speed[loser][j];
                            if(population[loser][j] > fp->getMaxX() )
                                population[loser][j] = fp->getMaxX();
                            if( population[loser][j] < fp->getMinX() )
                                population[loser][j] = fp->getMinX();
                        }

                        updated_population[a] = population[loser];

                    }

                    Fitness_Computation( half_results, updated_population, gl_best, Population_size/2, dim, FV, fp );


                    for( i = 0 ; i < Population_size/2; ++i )
                        results[updated_index[i]] = half_results[i];


                    if( half_results[gl_best] < final_val )
                    {

                        final_val = half_results[gl_best];

                        memcpy( final_global_best, updated_population[gl_best], sizeof(double)*dim );

                    }

                }


            result_all_run[t][counter] = final_val;



            cout<<"The result is "<<final_val<<endl;


        }


        for( i = 0; i < timesOfRun; ++i )
        {
            for( j = 0; j < record_set_size; ++j )
                out_fitness<<result_all_run[i][j]<<"\t";

            out_fitness<<endl;
        }


        out_fitness.close();

        cout<<"Function "<<funToRun[k]<<" Finished!"<<endl;




	}


	//release the resouces
    for( i =0; i < Population_size; ++ i )
    {
        delete []population[i];

        delete []speed[i];
    }
    delete []population;
    delete []speed;


    delete []population_index;

    for( i = 0; i < timesOfRun; ++i )
        delete []result_all_run[i];
    delete []result_all_run;

    delete []final_global_best;
    delete []results;
    delete []half_results;
    delete []updated_index;
    delete []updated_population;
    delete []global_mean_position;




    return 0;
}



