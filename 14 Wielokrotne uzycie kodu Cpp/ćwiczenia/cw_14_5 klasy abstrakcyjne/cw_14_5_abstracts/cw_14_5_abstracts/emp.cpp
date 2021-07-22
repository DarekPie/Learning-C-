#include "emp.h"

abstr_emp::abstr_emp()
{
}

abstr_emp::abstr_emp(const std::string & fn, const std::string & ln, const std::string & j)
{
}

void abstr_emp::ShowAll() const
{
}

void abstr_emp::SetAll()
{
}

std::ostream & operator<<(std::ostream & os, const abstr_emp & e)
{
	// TODO: insert return statement here
}

employee::employee()
{
}

employee::employee(const std::string & fn, const std::string & ln, const std::string & j)
{
}

void employee::ShowAll() const
{
}

void employee::SetAll()
{
}

manager::manager()
{
}

manager::manager(const std::string & fn, const std::string & ln, const std::string & j, int ico)
{
}

manager::manager(const abstr_emp & e, int ico)
{
}

manager::manager(const manager & m)
{
}

void manager::ShowAll() const
{
}

void manager::SetAll()
{
}

fink::fink()
{
}

fink::fink(const std::string & fn, const std::string & ln, const std::string & j, const std::string & rpo)
{
}

fink::fink(const abstr_emp & e, const std::string & rpo)
{
}

fink::fink(const fink & e)
{
}

void fink::ShowAll() const
{
}

void fink::SetAll()
{
}

highfink::highfink()
{
}

highfink::highfink(const std::string & fn, const std::string & ln, const std::string & j, const std::string & rpo, int ico)
{
}

highfink::highfink(const abstr_emp & e, const std::string & rpo, int ico)
{
}

highfink::highfink(const fink & f, int ico)
{
}

highfink::highfink(const manager & m, const std::string & rpo)
{
}

highfink::highfink(const highfink & h)
{
}

void highfink::ShowAll() const
{
}

void highfink::SetAll()
{
}
