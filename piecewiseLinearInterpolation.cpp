#include "piecewiseLinearInterpolation.h"

Interpolator::Interpolator(const std::vector<double>& x_values, const std::vector<double>& y_values)
    : x_values(x_values), y_values(y_values) {
    if (x_values.size() != y_values.size()) {
        throw std::invalid_argument("x_values and y_values must have the same size");
    }
};


double Interpolator::slope(int k) const { 
    if (k < 0 || k >= x_values.size() - 1) {
        throw std::out_of_range("Index k is out of valid range");
    }
    double m = 0;
    m = (y_values[k + 1] - y_values[k]) / (x_values[k + 1] - x_values[k]);
    return m;
};


double Interpolator::y_intercept(int k) const {  
    double b = 0;
    double m = slope(k);
    b = y_values[k] - m * x_values[k];
    return b;
};


void Interpolator::output_interpolation(std::ofstream &interpolationFile) const {
    double m = 0, b = 0;
    const int numReadings = x_values.size();

    for (int i = 0; i < numReadings - 1; ++i) {
        m = slope(i);
        b = y_intercept(i);

        interpolationFile << std::setw(5) << x_values[i] << " <= x <= " 
                  << std::setw(5) << x_values[i + 1] 
                  << " ; " << "y = " 
                  << std::setw(5) << b << " + " 
                  << std::setw(10) << m << " x ; interpolation" 
                  << std::endl;
    }
};