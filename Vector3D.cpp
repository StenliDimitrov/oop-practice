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
    std::string operation; // операция която ще прилагаме на векторите
    int n; // брой вектори върху които прилагаме операцията
    std::cin >> operation;
    std::cin >> n;
    Vector3D * vectors = new Vector3D[n]; // масив с векторите на които ще прилагаме операцията
    for (int i = 0; i < n; ++i) std::cin >> vectors[i];

    if (operation == "+") { // събираме всички въведени вектори
        Vector3D answer; // Вектор в който ще пазим отговора - първоначално (0,0,0)
        for (int i = 0; i < n; ++i) answer = answer + vectors[i]; // последоватлно добавяме всеки от въведените вектори
        std::cout << answer;
    } else if (operation == "-") { // изваждаме всички въведени вектори от първия
        Vector3D answer = vectors[0]; // Вектор в който ще пазим отговора - първоначално е първия вектор
        for (int i = 1; i < n; ++i) answer = answer - vectors[i]; // последоватлно изваждаме всеки от въведените вектори (совен първия)
        std::cout << answer;
    } else if (operation == "NEG") { // извеждаме противоположните на всички въведени вектори
        for (int i = 0; i < n; ++i) {
            if (i) std::cout << " "; // извеждаме " " преди всеки вектор освен първия
            std::cout << -vectors[i];
        }
    } else if (operation.front() == '*') { // извеждаме всички въведени вектори умножени по въведеното число
        int number = stoi(operation.substr(1)); // взимаме числото с което ще умножаваме векторите - то е операцията без знака "*"
        for (int i = 0; i < n; ++i) {
            if (i) std::cout << " ";
            std::cout << vectors[i] * number;
        }
    } else if (operation.back() == '*') { // извеждаме всички въведени вектори умножени по въведеното число
        int number = stoi(operation.substr(0, operation.size() - 1)); // взимаме числото с което ще умножаваме векторите - то е операцията без знака "*"
        for (int i = 0; i < n; ++i) {
            if (i) std::cout << " ";
            std::cout << number * vectors[i];
        }
    }
}
