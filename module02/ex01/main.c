// // #include<iostream>

// // class A
// // {
// //     private:
// //         int *x;
// //         int *y;
// //     public:
// //         A();
// //         void __printf()
// //         {
// //             std::cout<<*(this->x )<<" , ";
// //             std::cout<<*(this->y )<<"\n";
// //         }
// //         A&operator=(const A& abdo)//copy assignment operator
// //         {
// //             this->x = abdo.x;
// //             //this->y = abdo.y;
// //             return *this;
// //         }
// //         void    setPoint(int i , int j)
// //         {
// //             *(this->x ) = i;
// //             *(this->y ) = j;
// //         }
// // };
// // A::A()
// // {
// //     this->x = new int;
// //     *(this->x )= 0;
// //     this->y = new int;
// //     *(this->y )= 0;  
// // }

// // int main()
// // {
// //     A a,s;
// //     s = a;
// //     a.setPoint(12,23);
// //     a.__printf();
// //     s.__printf();
// // }
// #include <cassert>
// #include <iostream>

// class Fraction
// {
// private:
// 	int m_numerator { 0 };
// 	int m_denominator { 1 };

// public:
// 	// Default constructor
// 	Fraction(int numerator = 0, int denominator = 1 )
// 		: m_numerator { numerator }, m_denominator { denominator }
// 	{
// 		assert(denominator != 0);
// 	}

// 	// Copy constructor
// 	Fraction(const Fraction& copy)
// 		: m_numerator { copy.m_numerator }, m_denominator { copy.m_denominator }
// 	{
// 		// no need to check for a denominator of 0 here since copy must already be a valid Fraction
// 		std::cout << "Copy constructor called\n"; // just to prove it works
// 	}

// 	// Overloaded assignment
// 	Fraction& operator= (const Fraction& fraction);

// 	//friend std::ostream& operator<<(std::ostream& out, const Fraction& f1);

// };

// // std::ostream& operator<<(std::ostream& out, const Fraction& f1)
// // {
// // 	out << f1.m_numerator << '/' << f1.m_denominator;
// // 	return out;
// // }

// // A simplistic implementation of operator= (see better implementation below)
// Fraction& Fraction::operator= (const Fraction& fraction)
// {
//     // do the copy
//     m_numerator = fraction.m_numerator;
//     m_denominator = fraction.m_denominator;

//     // return the existing object so we can chain this operator
//     return *this;
// }

// int main()
// {
//     Fraction fiveThirds { 5, 3 };
//     Fraction f;
//     f = fiveThirds; // calls overloaded assignment
//     std::cout << f;

//     return 0;
// }


// #include <iostream>

// class MyClass {
// private:
//     int value;

// public:
//     MyClass(int val) : value(val) {}

//     // Copy assignment operator overload
//     MyClass& operator=(const MyClass& other) {
//         if (this != &other) {
//             value = other.value;
//         }
//         return *this;
//     }

//     int getValue() const {
//         return value;
//     }
// };

// int main() {
//     MyClass obj1(10);
//     MyClass obj2(20);

//     std::cout << "obj1 value: " << obj1.getValue() << std::endl;
//     std::cout << "obj2 value: " << obj2.getValue() << std::endl;

//     obj2 = obj1; // Copy assignment

//     std::cout << "After copy assignment:" << std::endl;
//     std::cout << "obj1 value: " << obj1.getValue() << std::endl;
//     std::cout << "obj2 value: " << obj2.getValue() << std::endl;

//     return 0;
// }
// sing namespace std ;
// #include"iostreamu"