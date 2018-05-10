#include <iostream>
class Vector3D
{
private:
    double x, y, z;

public:
    /**
    * ������� ������ ��� ��������� 0
    */
    Vector3D();
    /**
    * ������� ������ �� ���������� ��������� �� ������������ x, y � z, ������
    * x, y � z �� �������� ������ ����������� ����������� �������
    * @param x
    * @param y
    * @param z
    */
    Vector3D(double x, double y, double z);
    ~Vector3D();
    /**
    * ����� ���������� �� x
    * @return x
    */
    double getX() const;
    /**
    * ����� ���������� �� y
    * @return y
    */
    double getY() const;
    /**
    * ����� ���������� �� z
    * @return z
    */
    double getZ() const;
    /**
    * ���������� ���������� �� �������� �� �������
    * @param secondVector ������
    * @return ��� ������
    */
    Vector3D operator+(const Vector3D & secondVector) const;
    /**
    * ���������� ���������� �� ��������� �� �������
    * @param secondVector ������
    * @return ��� ������
    */
    Vector3D operator-(const Vector3D & secondVector) const;
    /**
    * ����� ��� ������ � �������� ����
    * @return ��� ������ � �������� ����
    */
    Vector3D operator-() const;
    /**

    * �������� �������� � ������� number
    * @param number - ����� � ����� �� �������� ��������
    * @return ��� ������
    */
    Vector3D operator*(double number) const;
    /**
    * �������� ����� � ������
    * @param number - �����
    * @param vector - ������
    * @return ��� ������
    */
    friend Vector3D operator*(double number, const Vector3D & vector);
    /**
    * ���������� ���������� �� ��������� �� ����� �� ������ �� ����������� ����, ����
    ������
    * �� ���� ������ ������� ������:
    * (x, y, z)
    */
    friend std::istream & operator>>(std::istream & iStream, Vector3D & vector);
    /**
    * ���������� ���������� �� ������������� (���������) �� ����������� � �������
    ������:
    * (x, y, z)
    */
    friend std::ostream & operator<<(std::ostream & oStream, const Vector3D & vector);
};
