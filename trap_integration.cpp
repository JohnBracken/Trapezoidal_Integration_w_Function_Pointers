/* The following code calculates the integral of a function
using trapezoidal numerical integration.  This code makes
use of function pointers, which allow a function to be passed
as an input arguement to another function.  In this case,
a function describing the curve to be integrated is passed
into another function that does the integration of this curve
from a lower to an upper bound.  */

//Include the basic libraries and use the standard namespace.
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include <iostream>

using namespace std;


/*Function to define a curve over which to be integrated.
This curve is a mathematical function of an input variable.
In this case, the y value, yval, is the dependent variable,
the value of which depends on an independent input variable,
'value'.*/
float func(float value)
{
    //Example of using the standard normal distribution
    //as the math function (curve).  Need to set the
    //value of e and pi for this curve.
    float exponent = exp(1);
    const float PI = 3.1415927;
    //Math function (curve) of an input variable 'value'.
    //In this case, it is the standard normal distribution,
    //but it could be any function of an independent variable.
    float yval = (1/sqrt(2*PI))*pow(exponent,-0.5*pow(value,2));

    //Return the dependent variable output.
    return yval;
}


/*Trapezoidal integration function, which returns the
integral of a mathetical function (curve).  The curve in
this case is an input argument function pointer.*/
float traps(float a, float b, float (*func_input)(float))
{

/*Assign the input argument function pointer to the
function that defines the mathematical curve.*/
func_input = func;

/*This part of the function will set up the integration
parameters.  For each iteration interval of the integral, the
lower and upper integration levels for the interval will be
initialized. The interval spacing (or resolution) is also
defined.  The integral always starts at zero.*/
float traps_low = a;
float integral = 0;
float resolution = 1e-4;
float traps_high = traps_low + resolution;

//Start the numeric integration, and continue until the upper
//bound of integration is reached.
while(traps_high <= b){

//Main trapezoidal calculation to add to the integral value.
integral += (traps_high - traps_low)*((func_input(traps_low)
    + func_input(traps_high))/2);

//Increment the lower and upper levels of the integration by the
//resolution value.
traps_low += resolution;
traps_high += resolution;

}

//Return the final value of the integral.
return integral;
}


//Main function.
int main(){

//Define the function pointer for the input function (curve)
//needed as an input arguement for the trapezoidal integration
//function.
float(*input_func)(float);

//Set the upper and lower bounds of the entire integration,
//and ask for them as user input.
float low_bound;
float high_bound;
cout << "Enter lower integration bound: ";
cin >> low_bound;
cout << "Enter upper integration bound: ";
cin >> high_bound;

//Call the trapezoidal integration function and generate a
//final integral result.  Print out the result.
float result = traps(low_bound,high_bound,input_func);
cout << "Integration result: " << result << endl;

return 0;
}
