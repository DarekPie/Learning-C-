#pragma once

class Tv
{

private:
	int state;						// Wlaczony lub wylaczony
	int volume;						// Zakladamy, ze mozna glosnosc wyrazic liczba
	int maxchanell;					// Maksymalna liczba kanalow
	int channel;					// Aktualnie wlaczony program
	int mode;						// Antena lub telewicja kablowa
	int input;						// Telewziaja lub video

public:
	friend class Remote;				// klasa Remote posiada dostep do prywatnych danych Tv
	enum {Off, On};
	enum {MinVal, MaxVal = 20};
	enum {Antenna, Cable};
	enum {TV, VCR};

	Tv(int s = Off, int mc = 100) 
		: state(s), volume(5), maxchanell(mc), channel(2), mode(Cable), input(TV)
	{
	}

	void onoff() { state = (state == On) ? Off : On; }
	bool ison() const { return state == On; }
	bool volup();
	bool voldown();
	void chanup();
	void chandown();
	void set_mode() { mode = (mode == Antenna) ? Cable : Antenna; }
	void set_input() { input = (input == TV) ? VCR : TV; }
	void settings() const;					//Wyswietla wszystkie ustawienia
};

class Remote
{
private:
	int mode;					// Kontroluje TV lub video
public:
	Remote(int m = Tv::TV) : mode(m) {}
	bool volup(Tv & t)			{ return t.volup(); }
	bool voldown(Tv & t)		{ return t.voldown(); }
	void onoff(Tv & t)			{  t.onoff(); }
	void chanup(Tv & t)			{  t.chanup(); }
	void chandown(Tv & t)		{  t.chandown(); }
	void set_Chan(Tv & t, int c) { t.channel = c; }
	void set_mode(Tv & t)		{ t.set_mode(); }
	void set_input(Tv & t)		{ t.set_input(); }

};

