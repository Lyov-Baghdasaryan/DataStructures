#include "RationalNumber.h"

namespace myrn
{
	template <typename T>
	T gcd(T num1, T num2){
		if(num2 != 0){
			return gcd(num2, num1 % num2);
		}
		return num1;
	}
	template <typename T>
	void normalize(T &num1, T &num2){
		T tmp = gcd<T>(num1, num2);

		num1 /= tmp;
		num2 /= tmp;

		if(num2 < 0){
			num1 *= -1;
			num2 *= -1;
		}
	}
	
	template <typename T>
	RationalNumber<T>::RationalNumber(T numerator, T denominator) : m_numerator(numerator), m_denominator(denominator){
		if(denominator == 0){
			throw std::string("ERROR - Denominator can't 0");
		}
		normalize(m_numerator,m_denominator);
	}

	template <typename T>
	RationalNumber<T> RationalNumber<T>::operator-(const RationalNumber<T> &other) const{
		T tmp  = gcd<T>(m_denominator, other.m_denominator);
		T denominator = other.m_denominator/tmp * m_denominator;
		return RationalNumber<T>(m_numerator * (denominator/m_denominator) - other.m_numerator*(denominator/other.m_denominator),denominator);
	}

	template <typename T>
	RationalNumber<T> RationalNumber<T>::operator+(const RationalNumber<T> &other) const{
		T tmp  = gcd<T>(m_denominator, other.m_denominator);
		T denominator = other.m_denominator/tmp * m_denominator;
		return RationalNumber<T>(m_numerator * (denominator/m_denominator) + other.m_numerator*(denominator/other.m_denominator),denominator);
	}

	template <typename T>
	RationalNumber<T> RationalNumber<T>::operator*(const RationalNumber<T> &other) const{
		T tmp1 = gcd(m_numerator, other.m_denominator);
		T tmp2 = gcd(other.m_numerator, m_denominator);
		return RationalNumber<T>((m_numerator/tmp1) * (other.m_numerator/tmp2), (m_denominator/tmp2) * (other.m_denominator/tmp1));
	}
	
	template <typename T>
	RationalNumber<T> RationalNumber<T>::operator/(const RationalNumber<T> &other) const{
		RationalNumber<T> tmp = RationalNumber<T>(other.m_denominator, other.m_numerator);
		return (*this) * tmp;
	}
    
	template <typename T>
	RationalNumber<T> RationalNumber<T>::operator+=(const RationalNumber<T> &other){
		*this = *this + other;
		return *this;
	}
	
	template <typename T>
	RationalNumber<T> RationalNumber<T>::operator-=(const RationalNumber<T> &other){
		*this = *this - other;
		return *this;
	}

	template <typename T>
	RationalNumber<T> RationalNumber<T>::operator*=(const RationalNumber<T> &other){
		*this = *this * other;
		return *this;
	}

	template <typename T>
	RationalNumber<T> RationalNumber<T>::operator/=(const RationalNumber<T> &other){
		*this = *this / other;
		return *this;
	}

	template <typename T>
	RationalNumber<T> RationalNumber<T>::operator++(int){
		RationalNumber<T> tmp = *this;
		*this += RationalNumber<T>(1);
		return tmp;
	}

	template <typename T>
		RationalNumber<T> RationalNumber<T>::operator++(){
		*this += RationalNumber<T>(1);
		return *this;
	}
	
	template <typename T>
	RationalNumber<T> RationalNumber<T>::operator+() const{
		return *this;
	}

	template <typename T>
	RationalNumber<T> RationalNumber<T>::operator-() const{
		return RationalNumber<T>(-m_numerator, m_denominator);
	}
	
	template <typename T>
	bool RationalNumber<T>::operator>(const RationalNumber<T> &other) const{
		RationalNumber<T> tmp = *this - other;
		return (tmp.m_numerator * tmp.m_denominator) > 0;
	}
    		
	template <typename T>
	bool RationalNumber<T>::operator<(const RationalNumber<T> &other) const{
		return other > *this;
	}
    	
	template <typename T>
	bool RationalNumber<T>::operator==(const RationalNumber<T> &other) const{
		return !(*this > other || *this < other);
	}
    	
	template <typename T>
	bool RationalNumber<T>::operator!=(const RationalNumber<T> &other) const{
		return !(*this == other);
	}

	template <typename T>
	bool RationalNumber<T>::operator>=(const RationalNumber<T> &other) const{
		return *this > other || *this == other;
	}
    
	template <typename T>
	bool RationalNumber<T>::operator<=(const RationalNumber<T> &other) const{
		return *this < other || *this == other;
	}

	template <typename T>
	RationalNumber<T>::operator int() const{
		return static_cast<int>(1.0 * m_numerator / m_denominator);
	}

	template <typename T>
	RationalNumber<T>::operator float() const{
		return static_cast<float>(1.0 * m_numerator / m_denominator);
	}

	template <typename T>
	RationalNumber<T>::operator double() const{
		return static_cast<double>(1.0 * m_numerator / m_denominator);
	}

	template <typename U>
	std::ostream &operator<<(std::ostream &os, const RationalNumber<U> &number){
		os << number.m_numerator << "/" << number.m_denominator;
		return os;
	}
	
	namespace literals
	{
		RationalNumber<unsigned long long> operator ""_r(unsigned long long other){
			return RationalNumber<unsigned long long>(other,1);
		}
	} // namespace literals

	template class RationalNumber<int>;
	template std::ostream &operator<<(std::ostream &os, const RationalNumber<int> &number);

	template class RationalNumber<unsigned long long>;
	template std::ostream &operator<<(std::ostream &os, const RationalNumber<unsigned long long> &number);
	
}
