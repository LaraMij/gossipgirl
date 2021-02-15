#include "gossipgirl.h"

vector<string>ortsteilnamen {"Hudson", "Queens", "Bronx", "Brooklyn", "Manhattan"};

Gossipgirl::Gossipgirl(string vorname, string zuname, Ortsteil ortsteil): vorname{vorname}, zuname{zuname}, ortsteil{ortsteil}
{
    if(ortsteil==Ortsteil::Hudson || vorname.empty() || zuname.empty()) throw runtime_error("Error!");
}

bool Gossipgirl::uebersiedeln (const Ortsteil& neu)
{
    if(neu==ortsteil) return false;
    else
    {
        ortsteil=neu;
        return true;
    }
}

int Gossipgirl::bekanntheitsgrad() const
{
    int gesamt = 0;
    gesamt+=zuname.size();
    gesamt+=(int)ortsteil;
    return gesamt;
}

bool Gossipgirl::operator==(const Gossipgirl& gos) const
{
    return(gos.vorname==vorname && gos.zuname==zuname && gos.ortsteil==ortsteil);
}

ostream& operator<<(ostream& o, const Gossipgirl& gos)
{
    o << "[" << gos.vorname << ", " << gos.zuname << ", " << ortsteilnamen.at(static_cast<int>(gos.ortsteil));
    return o << ", " << gos.bekanntheitsgrad() << "]";
}
