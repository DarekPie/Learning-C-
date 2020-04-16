#ifndef DMA_H_
#define DMA_H_
#include <iostream>

class ABCdma
{
private:
	char  * label;
	int rating;

public:
	ABCdma(const char * s = "brak", int r = 0);
	ABCdma(const ABCdma & rs);
	virtual ~ABCdma() {}
	virtual void View() const = 0;					//Funkcja czysto writualna bo ma const = 0 i nie ma definicji
	ABCdma & operator=(const ABCdma & rs);
	const char * getLabel() const { return label; }
	int getRating() const { return rating; }
	friend std::ostream & operator << (std::ostream & os, const ABCdma & rs);

};



class baseDMA : public ABCdma
{
public:
	baseDMA(const char * l = "brak", int r = 0) : ABCdma(l, r) {}
	baseDMA(const baseDMA & rs) : ABCdma(rs) {}
	virtual ~baseDMA() {}
	virtual void View() const;
	baseDMA & operator=(const baseDMA & rs);
	friend std::ostream & operator<<(std::ostream & os, const baseDMA & rs);
};


//Niejawny konstruktor kopiujacy
//Niejawny operator przypisania
class lacksDMA : public ABCdma
{
private:
	enum { COL_LEN = 40 };
	char color[COL_LEN];

public:
	lacksDMA(const char *c = "brak", const char * l = "brak", int r = 0);
	lacksDMA(const char *c, const ABCdma &rs);
	virtual void View() const;
	friend std::ostream & operator<<(std::ostream & os, const lacksDMA &rs);

};

// Klasa pochodna z dynamicznym przydzialem pamieci
class hasDMA : public ABCdma
{
private:
	char * style;

public:
	hasDMA(const char * s = "brak", const char * l = "brak", int r = 0);
	hasDMA(const char * s, const ABCdma & rs);
	hasDMA(const hasDMA & hs);				// wywoluje konstruktor kopiujacy klasy basowej
	~hasDMA();
	virtual void View() const;
	hasDMA & operator=(const hasDMA & rs);
	friend std::ostream & operator<<(std::ostream & os, const hasDMA & rs);
};

#endif

