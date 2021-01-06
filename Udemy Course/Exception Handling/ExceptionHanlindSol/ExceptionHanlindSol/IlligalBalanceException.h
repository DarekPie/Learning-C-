#pragma once
#include <iostream>

class IlligalBalanceException : public std::exception
{
	public:
		IlligalBalanceException() noexcept = default;
		~IlligalBalanceException() = default;
		virtual const char *what() const noexcept { return "Illegal balance exception"; }
};
