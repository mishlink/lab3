#include "TernaryVector.h"
namespace Prog3 {
	std::ostream& TernaryVector_1::print(std::ostream &s) const
	{
		int p;
		if (n == 0)
		{
			s << "Vector is empty";
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				if (ar[i] == 2)
				{
					s << 'X';
				}
				else
				{
					p = ar[i];
					//s << ar[i];
					s << p;
				}
			}
		}
		s << std::endl;
		return s;
	}
	TernaryVector_1& TernaryVector_1::input(std::istream& a, std::ostream& b)
	{
		b << "Enter the size of the vector" << std::endl;
		int k;
		char s;
		a >> k;
		if (!std::cin.good())
		{
			std::cin.clear();
			a >> s;
			throw std::exception("Not integer!");
		}
		else
		{
			if (k < SZ)
			{
				n = k;
				for (int i = 0; i < k; i++)
				{
					a >> s;
					if (s == '1')
					{
						ar[i] = 1;
					}
					else if (s == '0')
					{
						ar[i] = 0;
					}
					else if (s == 'X' or s == 'x')
					{
						ar[i] = 2;
					}
					else
					{
						throw std::exception("Wrong symbol!");
					}
				}
			}
			else
			{
				throw std::exception("Stack overflow!");
			}
		}
		return *this;
	}

	TernaryVector_1::TernaryVector_1(int k)
	{
		n = k;
		if (n < SZ)
		{
			for (int i = 0; i < n; i++)
			{
				ar[i] = 2;
			}
		}
		else
		{
			throw std::exception("Stack overflow!");
		}
	}
	TernaryVector_1::TernaryVector_1(std::string s)
	{
		n = s.length();
		if (n < SZ)
		{
			for (int i = 0; i < n; i++)
			{
				if (s[i] == '1')
				{
					ar[i] = 1;
				}
				else if (s[i] == '0')
				{
					ar[i] = 0;
				}
				else if (s[i] == 'X' or s[i] == 'x')
				{
					ar[i] = 2;
				}
				else
				{
					throw std::exception("Wrong symbol!");
				}
			}
		}
		else
		{
			throw std::exception("Stack overflow!");
		}
	}
	const TernaryVector_1 TernaryVector_1::NOT() const
	{
		std::string s = "";
		for (int i = 0; i < n; i++)
		{
			if (ar[i] == 1)
			{
				s += '0';
			}
			else if (ar[i] == 0)
			{
				s += '1';
			}
			else
			{
				s += 'X';
			}
		}
		TernaryVector_1 a(s);
		return a;
	}
	const TernaryVector_1 TernaryVector_1::AND(const TernaryVector_1& a) const
	{
		TernaryVector_1 b;
		b.n = std::max(n, a.n);
		int k;
		//std::string s = "";
		for (int i = 0; i < std::max(n, a.n); i++)
		{
			if (i >= n)
			{
				k = 2 * a.ar[i];
			}
			else if (i >= a.n)
			{
				k = 2 * ar[i];
			}
			else
			{
				k = ar[i] * a.ar[i];
			}
			if (k == 4)
			{
				k = 2;
			}
			//s += char(k) + 48;
			b.ar[i] = k;
		}
		//b.n = std::max(n, a.n);
		//TernaryVector_1 b(s);
		
		return b;
	}
	const TernaryVector_1 TernaryVector_1::OR(const TernaryVector_1& a) const
	{
		TernaryVector_1 b;
		b.n = std::max(n, a.n);
		int x, y, s;
		//std::string res = "";
		for (int i = 0; i < std::max(n, a.n); i++)
		{
			x = ar[i];
			y = a.ar[i];
			if (i >= n)
			{
				x = 2;
				y = a.ar[i];
			}
			else if (i >= a.n)
			{
				x = ar[i];
				y = 2;
			}
			else
			{
				x = ar[i];
				y = a.ar[i];
			}
			s = x + y;
			if (s == 2 && x == 1 && y == 1)
			{
				s = 1;
			}
			else if (s == 2)
			{
				s = 2;
			}
			else if (s == 3)
			{
				s = 1;
			}
			else if (s == 4)
			{
				s = 2;
			}
			//res += (char) s + 48;
			b.ar[i] = s;
		}
		//b.n = std::max(n, a.n);
		//TernaryVector_1 b(res);
		return b;
	}
	int TernaryVector_1::comp(const TernaryVector_1& a)
	{
		int s = 0;
		for (int i = 0; i < std::max(a.n, n); i++)
		{
			if (i >= n)
			{
				throw std::exception("It is impossible to compare!");
				return -2;
			}
			else if (i >= a.n)
			{
				throw std::exception("It is impossible to compare!");
				return -2;
			}
			if (ar[i] == 2 || a.ar[i] == 2)
			{
				throw std::exception("It is impossible to compare!");
				return -2;
			}
			if (ar[i] - a.ar[i] < 0)
			{
				return -1;
			}
			else if (ar[i] - a.ar[i] > 0)
			{
				return 1;
			}
			else
			{
				continue;
			}
		}
		return 0;
	}
	bool TernaryVector_1::definite()
	{
		for (int i = 0; i < n; i++)
		{
			if (ar[i] == 2)
			{
				return false;
			}
		}
		return true;
	}
	int TernaryVector_1::getN()
	{
		return n;
	}
	int TernaryVector_1::getSZ()
	{
		return SZ;
	}
}
