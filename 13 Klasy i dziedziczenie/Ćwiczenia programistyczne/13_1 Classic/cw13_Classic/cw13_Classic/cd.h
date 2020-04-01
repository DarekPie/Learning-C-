#ifndef CD_H_
#define CD_H_

class Cd							// reprezentuje plyte CD
{
	private:
		char performer[50];
		char label[20];
		int selections;				// liczba utworow
		double playtime;			// Dlugosc plyty w minutach

	public:
		Cd(const char *s1, const char *s2, int n, double x);
		Cd(const Cd & d);
		Cd();
		virtual ~Cd() {}
		virtual void Report() const;		// Wyswietla informacje o wszystkich danych plyty
		Cd & operator=(const Cd & d);
};

class Classic : public Cd
{
	private:
		char mainLabel[50];
	
	public:
		Classic(const char *s1, const char *s2, const char *s3, int n, double x);
		Classic(const Classic & e);
		Classic();
		virtual void Report() const;
		Classic & operator=(const Classic & e);
};

#endif // !CD_H_