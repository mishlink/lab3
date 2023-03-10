#include "TernaryVector2.h"
namespace Prog3 {
	std::ostream& operator <<(std::ostream& c,const TernaryVector_2& v)
	{
		if (v.n == 0)
		{
			c << "Vector is empty";
		}
		else
		{
			for (int i = 0; i < v.n; i++)
			{
				if (v.ar[i] == 2)
				{
					c << 'X';
				}
				else
				{
					c << v.ar[i];
				}
			}
		}
		c << std::endl;
		return c;
	}
	TernaryVector_2& operator >>(std::istream& c, TernaryVector_2& v) { 
		int k;
		char s;
		c >> k;
		if (!std::cin.good())
		{
			std::cin.clear();
			c >> s;
			throw std::exception("Not integer!");

		}
		else
		{
			if (k < v.SZ)
			{
				v.n = k;
				for (int i = 0; i < k; i++)
				{
					c >> s;
					if (s == '1')
					{
						v.ar[i] = 1;
					}
					else if (s == '0')
					{
						v.ar[i] = 0;
					}
					else if (s == 'X' or s == 'x')
					{
						v.ar[i] = 2;
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
		return v;
	}

	TernaryVector_2::TernaryVector_2(int k)
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
	TernaryVector_2::TernaryVector_2(std::string s)
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
	const TernaryVector_2 TernaryVector_2::operator !() const
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
		TernaryVector_2 a(s);
		return a;
	}
	const TernaryVector_2 TernaryVector_2::operator &(const TernaryVector_2& a) const
	{
		TernaryVector_2 b;
		int k;
		b.n = std::max(n, a.n);
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
			//s += (char)k + 48;
			b.ar[i] = k;
		}

		//TernaryVector_2 b(s);

		return b;
	}
	const TernaryVector_2 TernaryVector_2::operator |(const TernaryVector_2& a) const
	{
		TernaryVector_2 b;
		int x, y, s;
		b.n = std::max(n, a.n);
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
			b.ar[i] = s;
			//res += (char) s + 48;
		}
		//TernaryVector_2 b(res);
		return b;
	}
	int TernaryVector_2::operator >(const TernaryVector_2& a)
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
	bool TernaryVector_2::definite()
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
	int TernaryVector_2::getN()
	{
		return n;
	}
	int TernaryVector_2::getSZ()
	{
		return SZ;
	}
}
