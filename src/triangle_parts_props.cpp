/*
  This is part of Limesurf
    A program meant to integrated the shape of triangulated surface under constraints.
    
    Copyright 2017-2020 Serge Dmitrieff, Institut Jacques Monod, CNRS
    www.biophysics.fr
*/
#include <random>
#include <sstream>
#include "triangle_parts_props.h"

Triangle_set_props::Triangle_set_props(const YAML::const_iterator config) : Elastic_set_props(config) {
    
    auto conf=config->second;
    
    k_bending=-1;
    
    poisson=0.0;
    
    imposed_curvature=-1;
    
    curvature_correction=3.0;
    
    if (conf["bending"]) {
        k_bending=conf["bending"].as<std::double_t>();
    }

    if (conf["k_bending"]) {
        k_bending=conf["k_bending"].as<std::double_t>();
    }
    
    if (conf["poisson"]) {
        poisson=conf["poisson"].as<std::double_t>();
    }
    
    if (conf["imposed_angle"]) {
        imposed_curvature=conf["imposed_angle"].as<std::double_t>();
    }
    
    if (conf["imposed_curvature"]) {
        imposed_curvature=conf["imposed_curvature"].as<std::double_t>();
    }

    if (conf["curvature_correction"]) {
        curvature_correction=conf["curvature_correction"].as<std::double_t>();
    }

}

bool Triangle_set_props::Check_props() {
    bool error_t{false},error_e{false};
    error_e=Elastic_set_props::Check_props();
    if (k_bending<0) {
        std::cerr << "Error : k_bending must be >= 0" << std::endl;
        error_t=true;
    }
    if (error_e or error_t) {
        return true;
    } else
    { 
        return false;
    }
}
