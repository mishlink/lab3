#ifndef _STACK_S_1_H_
#define _STACK_S_1_H_
#include <iostream>
namespace Prog3 {
	class TernaryVector_1
	{
	private:
		static const int SZ = 10;
		int n;
		int ar[SZ];
	public:
		TernaryVector_1() : n(0) {}
		TernaryVector_1(int n);
		TernaryVector_1(std::string s);
		const TernaryVector_1 AND(const TernaryVector_1&) const;
		const TernaryVector_1 OR(const TernaryVector_1&) const;
		int comp(const TernaryVector_1&);
		const TernaryVector_1 NOT() const;
		bool definite();
		std::ostream& print(std::ostream& s) const;
		TernaryVector_1& input(std::istream&, std::ostream&);
		int getN();
		int getSZ();
	};
}
#endif

