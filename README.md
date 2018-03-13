The following code performs a trapezoidal integration
of a standard normal distribution function.  If the
upper and lower bounds of the integration are large enough,
the final integral should be very close to and approach a 
value of 1.  

The code uses function pointers, which allows one to pass
functions as input arguments to other functions in C.  In this
case, a function generating the standard normal distribution
to be integrated is placed as an input argument to the function 
that performs a trapezoidal integration of the normal distribution.

As sample output of the final integrated value is provided as
a snapshot in the repository after the user enters the lower
and upper bounds of integration.  






