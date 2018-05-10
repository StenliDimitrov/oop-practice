#include <iostream>
#include "Vector3D.h"

Vector3D::Vector3D():x(0),y(0),z(0){}

Vector3D::Vector3D(double x, double y, double z):x(x),y(y),z(z){}

Vector3D::~Vector3D(){}

double Vector3D::getX() const {
    return x;
}

double Vector3D::getY() const {
    return y;
}

double Vector3D::getZ() const {
    return z;
}

Vector3D Vector3D::operator+(const Vector3D & secondVector) const {
    return Vector3D(x + secondVector.x, y + secondVector.y, z + secondVector.z);
}

Vector3D Vector3D::operator-(const Vector3D & secondVector) const {
    return Vector3D(x - secondVector.x, y - secondVector.y, z - secondVector.z);
}

Vector3D Vector3D::operator-() const {
    return Vector3D(-x, -y, -z);
}

Vector3D Vector3D::operator*(double number) const {
    return Vector3D(x * number, y * number, z * number);
}

Vector3D operator*(double number, const Vector3D & vector) {
    return Vector3D(number * vector.x, number * vector.y, number * vector.z);
}

std::istream & operator>>(std::istream & iStream, Vector3D & vector) {
    char symbol;
    iStream >> symbol >> vector.x >> symbol >> vector.y >> symbol >> vector.z >> symbol;
    return iStream;
}

std::ostream & operator<<(std::ostream & oStream, const Vector3D & vector) {
    oStream << '(' << vector.x << ',' << vector.y << ',' << vector.z << ')';
    return oStream;
}

int main () {
    std::string operation; // �������� ����� �� ��������� �� ���������
    int n; // ���� ������� ����� ����� ��������� ����������
    std::cin >> operation;
    std::cin >> n;
    Vector3D * vectors = new Vector3D[n]; // ����� � ��������� �� ����� �� ��������� ����������
    for (int i = 0; i < n; ++i) std::cin >> vectors[i];

    if (operation == "+") { // �������� ������ �������� �������
        Vector3D answer; // ������ � ����� �� ����� �������� - ������������ (0,0,0)
        for (int i = 0; i < n; ++i) answer = answer + vectors[i]; // ������������� �������� ����� �� ���������� �������
        std::cout << answer;
    } else if (operation == "-") { // ��������� ������ �������� ������� �� ������
        Vector3D answer = vectors[0]; // ������ � ����� �� ����� �������� - ������������ � ������ ������
        for (int i = 1; i < n; ++i) answer = answer - vectors[i]; // ������������� ��������� ����� �� ���������� ������� (����� ������)
        std::cout << answer;
    } else if (operation == "NEG") { // ��������� ���������������� �� ������ �������� �������
        for (int i = 0; i < n; ++i) {
            if (i) std::cout << " "; // ��������� " " ����� ����� ������ ����� ������
            std::cout << -vectors[i];
        }
    } else if (operation.front() == '*') { // ��������� ������ �������� ������� �������� �� ���������� �����
        int number = stoi(operation.substr(1)); // ������� ������� � ����� �� ���������� ��������� - �� � ���������� ��� ����� "*"
        for (int i = 0; i < n; ++i) {
            if (i) std::cout << " ";
            std::cout << vectors[i] * number;
        }
    } else if (operation.back() == '*') { // ��������� ������ �������� ������� �������� �� ���������� �����
        int number = stoi(operation.substr(0, operation.size() - 1)); // ������� ������� � ����� �� ���������� ��������� - �� � ���������� ��� ����� "*"
        for (int i = 0; i < n; ++i) {
            if (i) std::cout << " ";
            std::cout << number * vectors[i];
        }
    }
}
