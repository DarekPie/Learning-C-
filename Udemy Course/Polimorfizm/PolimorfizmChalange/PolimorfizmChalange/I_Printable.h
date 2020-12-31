#pragma once
#include <iostream>

class I_Printable
{
	public:
		virtual void print(std::ostream &os) const = 0;
		virtual ~I_Printable() = default;

		friend std::ostream &operator<<(std::ostream &os, const I_Printable &obj);
};

