#pragma once

class Tv;

class Remote
{
public:
	enum State{Off, On};
	enum {MinVal, MaxVal = 20};
	enum { Antenna, Cable };
	enum { TV, VCR }; 

private:
	int mode;					// Kontroluje TV lub video
public:
	Remote(int m = TV) : mode(m) {}
	bool volup(Tv & t);
	bool voldown(Tv & t);
	void onoff(Tv & t);
	void chanup(Tv & t);
	void chandown(Tv & t);
	void set_Chan(Tv & t, int c);
	void set_mode(Tv & t);
	void set_input(Tv & t);

};


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
	friend void Remote::set_Chan(Tv & t, int c);
	enum { Off, On };
	enum { MinVal, MaxVal = 20 };
	enum { Antenna, Cable };
	enum { TV, VCR };

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

//Metody klasy Remote jako funkcje inline
inline bool Remote::volup(Tv & t) { return t.volup(); }
inline bool Remote::voldown(Tv & t) { return t.voldown(); }
inline void Remote::onoff(Tv & t) { t.onoff(); }
inline void Remote::chanup(Tv & t) { t.chanup(); }
inline void Remote::chandown(Tv & t) { t.chandown(); }
inline void Remote::set_Chan(Tv & t, int c) { t.channel = c; }
inline void Remote::set_mode(Tv & t) { t.set_mode(); }
inline void Remote::set_input(Tv & t) { t.set_input(); }


