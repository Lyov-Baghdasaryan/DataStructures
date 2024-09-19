// Your goal is to create a rational number class that would
// support each of the operations given in main.cpp.
//
// In this file you must declare only the interface of your class
// and implement the given functions separately from the class (at the bottom of
// this file inside the namespace).
// Notice that the RationalNumber is a class template, where the
// template parameter is an integer type for numerator and denominator.
//
// Note - Rename the namespace "yourname" to whatever you want, feel creative
// ( but not too much :) ).
//
// After you wrote RationalNumber class and the tests in the main function work
// - write at the bottom of the file the downsides of such rational numbers,
// what would you change/remove/add? Would you use such rational numbers instead
// of double/float numbers? There is no right/wrong answer, this question is
// more of a philosofical kind than technical.

#ifndef RationalNumer_H
#define RationalNumer_H
#include <iostream>
#include <string>
namespace myrn
{
	template <typename T>
	class RationalNumber
	{
		public:
			RationalNumber(T m_numerator = 0, T m_denominator = 1);

			RationalNumber<T> operator+(const RationalNumber<T> &other) const;
			RationalNumber<T> operator-(const RationalNumber<T> &other) const;
			RationalNumber<T> operator*(const RationalNumber<T> &other) const;
			RationalNumber<T> operator/(const RationalNumber<T> &other) const;
			RationalNumber<T> operator+=(const RationalNumber<T> &other);
			RationalNumber<T> operator-=(const RationalNumber<T> &other);
			RationalNumber<T> operator*=(const RationalNumber<T> &other);
			RationalNumber<T> operator/=(const RationalNumber<T> &other);	
			RationalNumber<T> operator++();
			RationalNumber<T> operator++(int);
			RationalNumber<T> operator+() const;
			RationalNumber<T> operator-() const;

			bool operator>(const RationalNumber<T> &other) const;
			bool operator<(const RationalNumber<T> &other) const;
			bool operator==(const RationalNumber<T> &other) const;
			bool operator!=(const RationalNumber<T> &other) const;
			bool operator>=(const RationalNumber<T> &other) const;
			bool operator<=(const RationalNumber<T> &other) const;

			explicit operator int() const;
			explicit operator float() const;
			explicit operator double() const;
			
		private:
			template <typename U>
			friend std::ostream& operator<<(std::ostream& os, const RationalNumber<U>& number);
		
		private:
			T m_numerator;
			T m_denominator;
	};
	    
	template <typename U>
   	std::ostream& operator<<(std::ostream& os, const RationalNumber<U>& number);
    
   	template <typename U>
    RationalNumber<U> operator+(U a, const RationalNumber<U> &other){
		return RationalNumber<U>(a) + other;
   	}

	template <typename U>
	RationalNumber<U> operator*(U a, const RationalNumber<U> &other){
      	return RationalNumber<U>(a) * other;
    }

  	namespace literals{	
     	RationalNumber<unsigned long long> operator ""_r(unsigned long long other);
  	}
  
} // namespace yourname

#endif
