#ifndef CATCH_CONFIG_MAIN

#include <iostream>
#include <cmath>
#include "solarsystem.h"
#include "euler.h"
#include <math.h>
#include "verlet.h"

using namespace std;

int main(int numArguments, char **arguments)
{
    int numTimesteps = 10000;
    if(numArguments >= 2) numTimesteps = atoi(arguments[1]);

    SolarSystem solarSystem;
    // We create new bodies like this. Note that the createCelestialBody function returns a reference to the newly created body
    // This can then be used to modify properties or print properties of the body if desired
    // Use with: solarSystem.createCelestialBody( position, velocity, mass );

    //CelestialBody &sun = solarSystem.createCelestialBody( vec3(3.583187837707098E-03, 3.347917208376574E-03, -1.601566243263295E-04), vec3(-1.916797473876860E-06, 6.860577040555349E-06, 3.852105421771686E-08), 1.0 );

    // We don't need to store the reference, but just call the function without a left hand side
    //CelestialBody &earth = solarSystem.createCelestialBody( vec3(9.779167444303752E-01, 2.272281606873612E-01, -1.762900112459768E-04), vec3(-4.140900006551348E-03, 1.671297229409165E-02, -6.071663121998971E-07), 3.03E-6);

    //CelestialBody &jupiter = solarSystem.createCelestialBody(vec3(-5.433021216987578, -3.890762583943597E-01, 1.231202671627251E-01), vec3(4.512629769156300E-04, -7.169976033688688E-03, 1.969934735867556E-05), 9.596E-4);
    //CelestialBody &Mars = solarSystem.createCelestialBody(vec3(1.083484179334264, -8.630838246913118E-01, -4.481984242527660E-02), vec3(9.286451652444910E-03, 1.212119447482730E-02, 2.594581334177116E-05), 3.33E-7);


    CelestialBody &sun = solarSystem.createCelestialBody(vec3(0, 0, 0), vec3(0, 0, 0), 1.0);
    CelestialBody &earth = solarSystem.createCelestialBody(vec3(1, 0, 0), vec3(0, 2*M_PI, 0), 3E-6);
    // To get a list (a reference, not copy) of all the bodies in the solar system, we use the .bodies() function
    vector<CelestialBody> &bodies = solarSystem.bodies();

    for(int i = 0; i<bodies.size(); i++) {
        CelestialBody &body = bodies[i]; // Reference to this body
        cout << "The position of this object is " << body.position << " with velocity " << body.velocity << endl;
    }

    double dt = 0.001;
    verlet integrator(dt);
    for(int timestep=0; timestep<numTimesteps; timestep++) {
        integrator.integrateOneStep(solarSystem);
        solarSystem.writeToFile("positions.dat");
    }

    cout << "I just created my first solar system that has " << solarSystem.bodies().size() << " objects." << endl;
    return 0;
}

#endif
