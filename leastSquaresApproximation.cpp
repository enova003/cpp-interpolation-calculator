#include "leastSquaresApproximation.h"


leastSquaresApproximation::leastSquaresApproximation(const std::vector<double>& x_values, const std::vector<double>& y_values)
    : x_values(x_values), y_values(y_values) {
    if (x_values.size() != y_values.size()) {
        throw std::invalid_argument("x_values and y_values must have the same size");
    }
};


std::vector<double> leastSquaresApproximation::calculate_c_values() const {
    
    std::vector<double> c_values;
    int k = x_values.size();

    double sum_x = 0.0;
    double sum_y = 0.0;
    double sum_xy = 0.0;
    double sum_xx = 0.0;

    for (int i = 0; i < k; ++i) {
        sum_x += x_values[i];
        sum_y += y_values[i];
        sum_xy += x_values[i] * y_values[i];
        sum_xx += x_values[i] * x_values[i];
    }

    double c1 = (k * sum_xy - sum_x * sum_y) / (k * sum_xx - sum_x * sum_x);
    double c0 = (sum_y - c1 * sum_x) / k;

    c_values.push_back(c0);
    c_values.push_back(c1);

    return c_values;
};


void leastSquaresApproximation::output_c_values(std::ofstream &leastSquaresFiles) const {
    
    std::vector<double> c_values;
    
    c_values = calculate_c_values();
    
    leastSquaresFiles << std::setw(5) << x_values.front() << " <= x <= " 
              << std::setw(5) << x_values.back()
              << " ; " << "y = " 
              << std::setw(5) << c_values[0] << " + " 
              << std::setw(10) << c_values[1] << " x ; least-squares" 
              << std::endl;

};