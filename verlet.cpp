#include "verlet.h"
#include "solarsystem.h"

verlet::verlet(double dt):
    m_dt(dt)

{
}

void verlet::integrateOneStep(SolarSystem &system)
{
    system.calculateForcesAndEnergy();
    for (CelestialBody &body : system.bodies()){
        vec3 param = body.force/body.mass;
        body.position += m_dt*body.velocity + (m_dt*m_dt/2)*param;
        system.calculateForcesAndEnergy();
        body.velocity += (m_dt/2)*(body.force/body.mass - param);

    }



}
