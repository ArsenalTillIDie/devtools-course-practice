// Copyright 2022 Maksim Orlov

#include"../include/vector-distances.h"
#include <vector>
#include <cmath>

Vector::Vector(std::vector<float> _data) {
	data = _data;
}

Vector::Vector(const Vector& v) {
	data = v.data;
}

void Vector::setData(std::vector<float> v) {
	data = v;
}

std::vector<float> Vector::getData() {
	return data;
};

float Vector::Linf(Vector v) {
	float maxDistance = 0;
	for (int i = 0; i < data.size(); i++) {
		float distance = abs(data[i] - v.data[i]);
		if (distance > maxDistance) maxDistance = distance;
	}
	return maxDistance;
}

float Vector::L(int p, Vector v) {
	float sum = 0;
	for (int i = 0; i < data.size(); i++) {
		sum += pow(abs(data[i] - v.data[i]), p);
	}
	return pow(sum, 1.0f / p);
}