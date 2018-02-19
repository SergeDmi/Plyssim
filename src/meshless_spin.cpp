#include "spin_parts.h"
#include <sstream>
#include "glossary.h"
#include <fstream>


int main(int argc, char* argv[])
{
    //std::istringstream fname(argv[1]);
    ifstream config(argv[1]);
    Glossary glos(config);
    //glos.read_strings(argc-1, argv+1);
    Part_set_props set_prop(glos);
    Meshless_props simul_prop(glos);

    Part_set set1(&set_prop);
    set1.GetStarted();
    double t=0;
    while (t<simul_prop.Tend) {
        std::cout << t << std::endl;
        t+=simul_prop.dt;
        set1.NextStep(&simul_prop);
        
    }
    //std::cout << "########### time is " << t << std::endl;
    //std::cout << "########### time is " << t << std::endl;
    //std::cout << "########### time is " << t << std::endl;
    set1.ComputeForcesViscousFast();
    //set1.GetNeighbours();
    set1.Export(0);
    return N;
}
