#ifndef _STACK_S_2_H_
#define _STACK_S_2_H_
#include <iostream>
namespace Prog3 {
	class TernaryVector_2
	{
	private:
		static const int SZ = 10;
		int n;
		int ar[SZ];
	public:
		TernaryVector_2() : n(0) {}
		TernaryVector_2(int n);
		TernaryVector_2(std::string s);
		const TernaryVector_2 operator &(const TernaryVector_2&) const;
		const TernaryVector_2 operator |(const TernaryVector_2&) const;
		int operator >(const TernaryVector_2&);
		const TernaryVector_2 operator !() const;
		bool definite();
		friend std::ostream& operator <<(std::ostream&, const TernaryVector_2&);
		friend TernaryVector_2& operator >>(std::istream&, TernaryVector_2&);
		int getN();
		int getSZ();
	};
}
#endif

