#ifndef TABTENN_H_
#define TABATENN_H_
//Prosta klasa bazowa

class TableTennisPlayer
{
	private:
		enum {LIM = 20};
		char firstname[LIM];
		char lastname[LIM];
		bool hasTable;
	public:
		TableTennisPlayer(const char * fn = "brak", const char * ln = "brak", bool ht = false);
		void Name() const;
		bool HasTable() const { return hasTable; };
		void ResetTable(bool v) { hasTable = v; };
};

#endif // !TABTENN_H_

