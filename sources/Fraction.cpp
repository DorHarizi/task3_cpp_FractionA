#include "Fraction.hpp"
#include<algorithm>
#include <cmath>

using namespace std;
using namespace ariel;
#define MaxNum 1000000

// constructors 
Fraction::Fraction(){
    numerator = 0;
    denominator = 1;
    // cout<<"crate new Fraction()\n"<<endl;
}

Fraction::Fraction(float num){
    int value_whole = floor(num);
    num -= value_whole;
    value_whole *= MaxNum;
    num *= MaxNum;
    int value_part = round(num);
    value_whole += value_part;
    int gcd = __gcd(value_whole, MaxNum);
    this->numerator = value_whole / gcd;
    this->denominator = MaxNum / gcd;
    // cout<<"crate new Fraction("<< num << ")->("<<this->numerator <<","<<this->denominator<<")\n"<<endl;
}

Fraction:: operator float()const{
    float f = static_cast<float>(this->numerator) / static_cast<float>(this->denominator);
    return f;
} 

Fraction::Fraction(int numerator, int denominator){
    int gcd = __gcd(numerator, denominator);
    this->numerator = numerator / gcd;
    if (denominator == 0){
            throw invalid_argument("denominator cannot be zero, please try again");
    }
    this->denominator = denominator / gcd;
    // cout<<"crate new Fraction("<< numerator<<","<< denominator << ")->("<<this->numerator <<","<<this->denominator<<")\n"<<endl;
}

Fraction::Fraction(const Fraction &num){
    this->numerator = num.getNumerator();
    this->denominator = num.getDenominator();
    // cout<<"copy Frunction("<<this->numerator<<","<<this->denominator<<")\n"<<endl;
}

// Getters 
int Fraction::getNumerator()const{
    return numerator;
}

int Fraction::getDenominator()const{
    return denominator;
}

// binary oprators
Fraction Fraction::operator+(const Fraction &other)const{
    int new_numerator = (numerator * other.denominator) + (other.numerator * denominator);
    int new_denominator = denominator * other.denominator;
    int new_gcd = __gcd(new_numerator, new_denominator);
    return Fraction(new_numerator/ new_gcd, new_denominator / new_gcd);
}

Fraction Fraction::operator-(const Fraction &other) const{
    int new_numerator = (numerator * other.denominator) - (other.numerator * denominator);
    int new_denominator = denominator * other.denominator;
    int new_gcd = __gcd(new_numerator, new_denominator);
    return Fraction(new_numerator/ new_gcd, new_denominator / new_gcd);
}

Fraction Fraction::operator/(const Fraction &other) const{
    if(other.numerator != 0){
    int new_numerator = numerator * other.denominator;
    int new_denominator = other.numerator * denominator;
    int new_gcd = __gcd(new_numerator, new_denominator);
    return Fraction(new_numerator/ new_gcd, new_denominator / new_gcd);
    }
    else{
        throw invalid_argument("can't divide by zero, please try again with anthor Fraction");
    }   
}

Fraction Fraction::operator*(const Fraction &other) const{
    int new_numerator = numerator * other.numerator;
    int new_denominator = other.denominator * denominator;
    int new_gcd = __gcd(new_numerator, new_denominator);
    return Fraction(new_numerator/ new_gcd, new_denominator / new_gcd);
}

Fraction ariel::operator+(const Fraction &other, const float &num){
    return other + Fraction(num);
}

Fraction ariel::operator-(const Fraction &other, const float &num){
    return other - Fraction(num);
}

Fraction ariel::operator/(const Fraction &other, const float &num){
    return other / Fraction(num);
}

Fraction ariel::operator*(const Fraction &other, const float &num){
    return other * Fraction(num);
}

Fraction ariel::operator+(const float &num, const Fraction &other){
    return Fraction(num) + other;
}

Fraction ariel::operator-(const float &num, const Fraction &other){
    return Fraction(num) - other;
}

Fraction ariel::operator/(const float &num, const Fraction &other){
    return Fraction(num) / other;
}

Fraction ariel::operator*(const float &num, const Fraction &other){
    return Fraction(num) * other;
}

// operators adds/substracts 1 pre and post fix
Fraction Fraction::operator++(){
    numerator += denominator;
    return *this;
} 

Fraction Fraction::operator++(int){
    Fraction result(*this);
    ++(*this);
    return result;
} 

Fraction Fraction::operator--(){
    numerator -= denominator;
    return *this;
}  

Fraction Fraction::operator--(int){
    Fraction result(*this);
    --(*this);
    return result;
}

// comparison operators
bool Fraction::operator>(const Fraction &other) const{
    return ((this->numerator * other.denominator) > (other.numerator * this->denominator));
}

bool Fraction::operator<(const Fraction &other) const{
    return ((this->numerator * other.denominator) < (other.numerator * this->denominator));
}

bool Fraction::operator>=(const Fraction &other) const{
    return ((this->numerator * other.denominator) >= (other.numerator * this->denominator));
}

bool Fraction::operator<=(const Fraction &other) const{
    return ((this->numerator * other.denominator) <= (other.numerator * this->denominator));
}

bool ariel::operator>(float num, const Fraction &other){
    float value = float(other);
    return num > value;
}

bool ariel::operator< (float num, const Fraction &other){
    float value = float(other);
    return num < value;
}

bool ariel::operator>= (float num, const Fraction &other){
    float value = float(other);
    return num >= value;
}

bool ariel::operator<=(float num, const Fraction &other){
    float value = float(other);
    return num <= value;
}

bool ariel::operator>(const Fraction &other, float num){
    float value = float(other);
    return value > num;
}    

bool ariel::operator<(const Fraction &other, float num){
    float value = float(other);
    return value < num;
}

bool ariel::operator>=(const Fraction &other, float num){
    float value = float(other);
    return value >= num;
}

bool ariel::operator<=(const Fraction &other, float num){
    float value = float(other);
    return value <= num;
}

bool Fraction::operator==(const Fraction &other) const{
    bool b = ((this->getNumerator() == other.getNumerator()) 
            && (this->getDenominator() == other.getDenominator()));
    return b;
}

bool Fraction::operator!=(const Fraction &other) const{
    return !(*this == other);
}

// I/O operators
std::ostream& ariel::operator<<(std::ostream &output, const Fraction &other){
    output<< other.getNumerator() << "/" << other.getDenominator()<<endl;
    return output;
}

std::istream& ariel::operator>> (std::istream &input, const Fraction &other){
    return input;
}