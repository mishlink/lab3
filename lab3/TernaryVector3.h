#ifndef _STACK_S_3_H_
#define _STACK_S_3_H_
#include <iostream>
namespace Prog3 {
	class TernaryVector_3
	{
	private:
		static const int QUOTA = 10;
		int SZ;
		int n;
		int* ar;
	public:
		TernaryVector_3() : SZ(QUOTA), n(0), ar(new int[QUOTA]) {}
		TernaryVector_3(int n);
		TernaryVector_3(std::string s);
		TernaryVector_3(const TernaryVector_3&);
		TernaryVector_3(TernaryVector_3&&);
		~TernaryVector_3() { delete[] ar; }
		TernaryVector_3& operator =(const TernaryVector_3&);
		TernaryVector_3& operator =(TernaryVector_3&&);

		TernaryVector_3 operator &(const TernaryVector_3&) const;
		TernaryVector_3 operator |(const TernaryVector_3&) const;
		int operator >(const TernaryVector_3&);
		TernaryVector_3 operator !() const;
		bool definite();
		friend std::ostream& operator <<(std::ostream&, const TernaryVector_3&);
		friend TernaryVector_3& operator >>(std::istream&, TernaryVector_3&);
		int getN();
		int getSZ();
	};
}
#endif
