#ifndef PIECEWISE_LINEAR_INTERPOLATION_H_INCLUDED
#define PIECEWISE_LINEAR_INTERPOLATION_H_INCLUDED

#include <vector>
#include <iomanip>
#include <stdexcept>
#include <iostream>
#include <fstream>

class Interpolator {
public:

    /**
     * @brief Constructor for the Interpolator class
     * 
     * @param x_values stores the x_values as a vector
     * @param y_values stores the y_values as a vector
     * 
     * @throws invalid_argument if x_values and y_values do not have the same size
     */
    Interpolator(const std::vector<double>& x_values, const std::vector<double>& y_values);
    
    /**
     * @brief Calculates the piecewise interpolation data and stores this information in a .txt file
     * 
     * @param nameOfFile the name of the .txt file that will hold the interpolation data
     * 
     * @attention This function will *not* open or close the .txt file
     */
    void output_interpolation(std::ofstream &interpolationFile) const;

private:

    /**
     * @brief Calculates the slope of a line using the formula m = y_k+1 - y_k / x_k+1 - x_k
     * 
     * @param k where k is an index used to access corresponding values in x_values and y_values
     * 
     * @return the calculated slope of a line
     * 
     * @throws out_of_range if k is not in the range of x_values
     */
    double slope(int k) const;

    /**
     * @brief Calculates the y-intercept of a line using the formula b = y_k - mx_k
     * 
     * @param k where k is an index used to access corresponding values in x_values and y_values
     * 
     * @return the y-intercept of a line
     */
    double y_intercept(int k) const;

    std::vector<double> x_values;
    std::vector<double> y_values; 
};

#endif
