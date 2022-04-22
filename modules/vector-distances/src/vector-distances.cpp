// Copyright 2022 Maksim Orlov

#include"../include/vector-distances.h"
#include <vector>
#include <cmath>

void Vector::unusedFunctions() {
	L(1, *this);
	Linf(*this);
	getData();
	setData(*this);
}

Vector::Vector(std::vector<float>& _data): data(_data) {
	unusedFunctions();
}

Vector::Vector(const Vector& v) data(v.data) {
}

void Vector::setData(std::vector<float>& v) {
	data = v;
}

std::vector<float> Vector::getData() {
	return data;
};

float Vector::Linf(Vector v) {
	if (data.size() != v.data.size()) throw "Vectors are of different sizes";
	float maxDistance = 0;
	for (int i = 0; i < data.size(); i++) {
		float distance = abs(data[i] - v.data[i]);
		if (distance > maxDistance) maxDistance = distance;
	}
	return maxDistance;
}

float Vector::L(int p, Vector v) {
	if (data.size() != v.data.size()) throw "Vectors are of different sizes";
	float sum = 0;
	for (int i = 0; i < data.size(); i++) {
		sum += pow(abs(data[i] - v.data[i]), p);
	}
	return pow(sum, 1.0f / p);
}