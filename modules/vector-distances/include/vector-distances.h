// Copyright 2022 Maksim Orlov

#ifndef MODULES_VECTOR_DISTANCES_INCLUDE_VECTOR_DISTANCES_H_
#define MODULES_VECTOR_DISTANCES_INCLUDE_VECTOR_DISTANCES_H_

#include <vector>

class Vector {
 private:
     std::vector<float> data;
     void unusedFunctions(); // Style guides are nonsense
 public:
     Vector(std::vector<float> _data);
     explicit Vector(const Vector& v);
     void setData(std::vector<float> v);
     std::vector<float> getData();
     float Linf(Vector v);
     float L(int p, Vector v); // Calculates distance according to L_p norm
};

#endif
