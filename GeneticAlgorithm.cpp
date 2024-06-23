#include "geneticalgorithm.h"
#include <chrono>
#include <thread>

using namespace std;
using namespace arma;

void GeneticAlgorithm::Evolve(){

    //Updates the generations for NumberOfGeneration times
    
    ofstream Results, Path, Loss;                                                   // I/O files
    Results.open("resultsSquare.txt");                                              // Best half data
    Path.open("pathsSquaretxt");                                                    // optimal solution path data
    Loss.open("optimumLossSquare.txt");                                             // fitness of the optimal solution per generation

    for (int i=0; i < m_NumberOfGenerations; i++){

        cout<< "Gen: " << i +1<<endl ;
        m_gen->CrossOver();                                                         // This makes crossover and mutations all at once

        Results << m_gen->bestHalfAverage() << endl;                                // Save the best half measurements
        Loss << i << " " << m_gen->GetOptimumLoss()<<endl;                          // Save the optimal solution measurements

        if (i%25==0){                                                               // Every 25 generations save the optimal solution path
            arma::mat bestPath = m_gen->BestPath();
            for (int j = 0; j < bestPath.n_rows; j++){
                Path << i << " " << bestPath.row(j) << endl;
            }
        } 
    }
    Results.close();                                                                // Close I/O files
    Path.close();
    Loss.close();        
}
