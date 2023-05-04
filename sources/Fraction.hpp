#pragma 

#include <iostream>

namespace ariel
{
    class Fraction{
    private:
        int numerator;  
        int denominator; 

    public:
        // constructors 
        Fraction();
        Fraction(float num);
        operator float() const;
        Fraction(int numerator, int denominator);
        Fraction(const Fraction &num);

        // Getters 
        int getNumerator() const;
        int getDenominator() const;

        // binary oprators
        Fraction operator+(const Fraction &other) const;
        Fraction operator-(const Fraction &other) const;
        Fraction operator/(const Fraction &other) const;
        Fraction operator*(const Fraction &other) const;

        friend Fraction operator+(const Fraction &other, const float &num);
        friend Fraction operator-(const Fraction &other, const float &num);
        friend Fraction operator/(const Fraction &other, const float &num);
        friend Fraction operator*(const Fraction &other, const float &num);

        friend Fraction operator+(const float &num, const Fraction &other);
        friend Fraction operator-(const float &num, const Fraction &other);
        friend Fraction operator/(const float &num, const Fraction &other);
        friend Fraction operator*(const float &num, const Fraction &other);

        // operators adds/substracts 1 pre and post fix
        Fraction operator++();    
        Fraction operator++(int); 
        Fraction operator--();   
        Fraction operator--(int);

        // comparison operators
        bool operator>(const Fraction &other) const;
        bool operator<(const Fraction &other) const;
        bool operator>=(const Fraction &other) const;
        bool operator<=(const Fraction &other) const;
        bool operator==(const Fraction &other) const;
        bool operator!=(const Fraction &other) const;

        friend bool operator> (float num, const Fraction &other);
        friend bool operator< (float num, const Fraction &other);
        friend bool operator>= (float num, const Fraction &other);
        friend bool operator<= (float num, const Fraction &other);

        friend bool operator> (const Fraction &other, float num);
        friend bool operator< (const Fraction &other, float num);
        friend bool operator>= (const Fraction &other, float num);
        friend bool operator<= (const Fraction &other, float num);


        // I/O operators
        friend std::ostream &operator<< (std::ostream &output, const Fraction &other);
        friend std::istream &operator>> (std::istream &input, const Fraction &other);
    };
}