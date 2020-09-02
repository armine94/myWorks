#ifndef MYCLASS_HH
#define MYCLASS_HH

/** @brief Dummy class used for illustration purposes. Doing something with it.

Detailed description follows here.
@author X. XYZ, DESY
@date March 2008
*/
class myClass{
/** Default constructor. Does something.
*/
myClass();
/** My constructor. Initializes the coordinates.
*/
myClass(float x, float y, float z);
/** Default destructor.
*/
~myClass();


public:
/**Print out the private members of the class
*/
void print();
/**Calculate distance from origin.
The distance is calculated with the formula
\f$\sqrt{(x-x0)^2+(y-y0)^2+(z-z0)^2}\f$.
@param x - x coordinate of the point
@param y - y coordinate of the point
@param z - z coordinate of the point
@return distance to point
*/
float getDistance(float x, float y, float z);

private:
float _x0;/**<initial x-coordinate*/
float _y0;/**<initial y-coordinate*/
float _z0;
};

#endif
