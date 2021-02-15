#ifndef CLIQUE_H
#define CLIQUE_H

#include "gossipgirl.h"

class Clique
{
    private:
        string name;
        vector<Gossipgirl>liste;

    public:
        Clique(string name, vector<Gossipgirl>liste);
        bool check(const Gossipgirl&) const;
        double durchschnitt_bekanntheit() const;
        bool hinzufuegen(const Gossipgirl&);
        friend ostream& operator<<(ostream&, const Clique);

        void entfernen();
        void aufnehmen(const vector<Gossipgirl>& v, bool fame);
};

#endif // CLIQUE_H
