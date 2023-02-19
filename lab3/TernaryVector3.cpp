#include "TernaryVector3.h"
namespace Prog3 {
	TernaryVector_3::TernaryVector_3(const TernaryVector_3& st) :n(st.n), SZ(st.SZ)
	{
		ar = new int[SZ];
		for (int i = 0; i < n; ++i)
		{
			ar[i] = st.ar[i];
		}
	}

	TernaryVector_3::TernaryVector_3(TernaryVector_3&& st) :n(st.n), SZ(st.SZ), ar(st.ar)
	{
		st.ar = nullptr;
	}

	TernaryVector_3& TernaryVector_3::operator =(const TernaryVector_3& st)
	{
		if (this != &st) {
			n = st.n;
			SZ = st.SZ;
			delete[] ar;
			ar = new int[SZ];
			for (int i = 0; i < n; ++i)
			{
				ar[i] = st.ar[i];
			}
		}
		return *this;
	}
	
	TernaryVector_3& TernaryVector_3::operator =(TernaryVector_3&& st)
	{
		int tmp = n;
		n = st.n;
		st.n = tmp;
		tmp = SZ;
		SZ = st.SZ;
		st.SZ = tmp;
		int* ptr = ar;
		ar = st.ar;
		st.ar = ptr;
		return *this;
	}
	std::ostream& operator <<(std::ostream& c, const TernaryVector_3& v) // исправлена1
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
	TernaryVector_3& operator >>(std::istream& c, TernaryVector_3& v) { // исправлено1
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
			while (k >= v.SZ)
			{
				v.SZ += v.QUOTA;
			}
			v.n = k;
			delete[] v.ar;
			v.ar = new int[v.SZ];
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
			return v;
		}
	}

	TernaryVector_3::TernaryVector_3(int k) //исправлено1
	{
		n = k;
		while (n >= SZ)
		{
			SZ += QUOTA;
		}
		ar = new int[SZ];
		for (int i = 0; i < n; i++)
		{
			ar[i] = 2;
		}
	}

	TernaryVector_3::TernaryVector_3(std::string s) //исправлено1
	{
		n = s.length();
		while (n >= SZ)
		{
			SZ += QUOTA;
		}
		ar = new int[SZ];
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

	TernaryVector_3 TernaryVector_3::operator !() const //исправлено1
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
		TernaryVector_3 a(s);

		return a;
	}
	TernaryVector_3 TernaryVector_3::operator &(const TernaryVector_3& a) const //исправлено1
	{
		TernaryVector_3 b;
		int k;
		b.n = std::max(n, a.n);
		while (b.n >= b.SZ)
		{
			b.SZ += b.QUOTA;
		}
		delete[] b.ar;
		b.ar = new int[SZ];
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
	TernaryVector_3 TernaryVector_3::operator |(const TernaryVector_3& a) const //исправлено1
	{
		TernaryVector_3 b;
		int x, y, s;
		b.n = std::max(n, a.n);
		while (b.n >= b.SZ)
		{
			b.SZ += b.QUOTA;
		}
		delete[] b.ar;
		b.ar = new int[SZ];
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
	int TernaryVector_3::operator >(const TernaryVector_3& a) //исправлено1
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
	bool TernaryVector_3::definite() //исправлено
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
	int TernaryVector_3::getN()
	{
		return n;
	}
	int TernaryVector_3::getSZ()
	{
		return SZ;
	}
}
