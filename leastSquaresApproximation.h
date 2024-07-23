#ifndef LEAST_SQUARES_APPROXIMATION_H
#define LEAST_SQUARES_APPROXIMATION_H

#include <vector>
#include <iomanip>
#include <stdexcept>
#include <iostream>
#include <fstream>

class leastSquaresApproximation {
public:

    /**
     * @brief Constructor for the leastSquaresApproximation class
     * 
     * @param x_values stores a vector as the x_values
     * @param y_values stores a vector as the y_values 
     * 
     * @throws invalid_argument if x_values and y_values do not have the same size
     */
    leastSquaresApproximation(const std::vector<double>& x_values, const std::vector<double>& y_values);
    
    /**
     * @brief Retrives the least squares approximation data and stores it in a .txt file
     * 
     * @param nameOfFile the name of the .txt file that will hold the least squares approximation data
     * 
     * @attention This function will *not* open or close the .txt file
     */
    void output_c_values(std::ofstream &leastSquaresFiles) const;

private:
    std::vector<double> x_values;
    std::vector<double> y_values;

    /**
     * @brief Calculates the c_0 and c_1 values associated with the least squares approximation data
     * 
     * @param none
     * 
     * @return a vector that stores the c_0 value in index location [0] and the c_1 value in index location [1]  
     */
    std::vector<double> calculate_c_values() const;
};

#endif
