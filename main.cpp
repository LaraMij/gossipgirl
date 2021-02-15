#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
#include"gossipgirl.h"
#include"clique.h"

using namespace std;

int main(){
  try{
    Gossipgirl serena{"", "van der Woodsen", Ortsteil::Queens};
    cout << serena << '\n';
  }
  catch(runtime_error& e){
    cout << "Error1" << "\n";
  }
  try{
    Gossipgirl serena{"Serena", "", Ortsteil::Queens};
    cout << serena << '\n';
  }
  catch(runtime_error& e){
    cout << "Error2" << "\n";
  }
  try{
    Gossipgirl jenny{"Jenny", "Humphrey", Ortsteil::Hudson};
    cout << jenny << '\n';
  }
  catch(runtime_error& e){
    cout << "Error3" << "\n";
  }


  const Gossipgirl serena{"Serena", "van der Woodsen"};
  const Gossipgirl blair{"Blair", "Waldorf", Ortsteil::Manhattan};
  const Gossipgirl dan{"Dan", "Humphrey", Ortsteil::Brooklyn};
  const Gossipgirl jenny{"Jenny", "Humphrey", Ortsteil::Queens};
  const Gossipgirl chuck{"Chuck", "Bass", Ortsteil::Bronx};
  const Gossipgirl eric{"Eric", "van der Woodsen", Ortsteil::Manhattan};

  cout << serena << '\n';
  cerr << serena << '\n';

  Gossipgirl blair2{blair};
  Gossipgirl jenny2{jenny};
  cout << blair2.uebersiedeln(Ortsteil::Bronx);
  cout << jenny2.uebersiedeln(Ortsteil::Hudson);
  cout << blair2.uebersiedeln(Ortsteil::Bronx) << "\n";

  cout << dan.bekanntheitsgrad() << " " << jenny.bekanntheitsgrad() << " " << blair2.bekanntheitsgrad() << "\n";

  cout << (jenny == chuck) << (serena == serena);
  cout << (blair == jenny);
  cout << (jenny == jenny2);
  cout << (Gossipgirl{"Clair", "Waldorf"} == blair);
  cout << (Gossipgirl{"Blair", "Wanndorff"} == blair) << "\n";

  try{
    Clique upperEastSiders {"", {serena, blair}};
  }
  catch(runtime_error& e){
    cout << "Error4" << "\n";
  }
  try{
    Clique upperEastSiders {"UpperEastSiders", {serena, blair}};
  }
  catch(runtime_error& e){
    cout << "Error5" << "\n";
  }
  try{
    Clique upperEastSiders {"UpperEastSiders", {}};
  }
  catch(runtime_error& e){
    cout << "Error6" << "\n";
  }

  Clique upperEastSiders {"UpperEastSiders", {jenny, blair}};

  const Clique constTestClique{upperEastSiders};
  Clique testClique{upperEastSiders};

  cout << constTestClique << '\n';
  cout << constTestClique.check(blair);
  cout << constTestClique.check(chuck);
  cout << constTestClique.check(jenny2);
  cout << constTestClique.check(jenny);
  cout << testClique.check(jenny) << "\n";

  cout << constTestClique.durchschnitt_bekanntheit() << "\n";
  cout << testClique.hinzufuegen(chuck);
  cout << testClique.hinzufuegen(jenny);
  cout << testClique.hinzufuegen(chuck);
  cout << testClique.hinzufuegen(jenny2) << "\n";
  cout << testClique << " " << testClique.durchschnitt_bekanntheit() << "\n";
  cerr << testClique << " " << testClique.durchschnitt_bekanntheit() << "\n";

  //Basisfunktionalitaet Ende

  //Dekommentieren fuer Erweiterung 'entfernen'

  cout << "\n\nZusatz fuer 10 Punkte" << "\n";

  testClique = upperEastSiders;
  cout << testClique.hinzufuegen(blair);
  cout << testClique.hinzufuegen(chuck) << "\n";
  cout << testClique << "\n";
  testClique.entfernen();
  cout << testClique << "\n";
  testClique.entfernen();
  cout << testClique << "\n";
  testClique.entfernen();
  cout << testClique  << " " << testClique.durchschnitt_bekanntheit() << "\n";


  //Dekommentieren fuer Erweiterung 'aufnehmen'

  cout << "\n\nZusatz fuer 15 Punkte" << "\n";

  testClique = upperEastSiders;
  cout << testClique << "\n";
  cout << testClique.hinzufuegen(dan) << "\n";
  testClique.aufnehmen({dan, eric, chuck, blair}, true);
  cout << testClique << "\n";
  testClique.aufnehmen({jenny, chuck, dan, eric}, false);
  cout << testClique << "\n";


  return 0;
}

/* Erwartete Ausgabe
Error1
Error2
Error3
[Serena, van der Woodsen, Manhattan, 19]
[Serena, van der Woodsen, Manhattan, 19]
110
11 9 9
010000
Error4
Error6
[UpperEastSiders, {[Jenny, Humphrey, Queens, 9], [Blair, Waldorf, Manhattan, 11]}]
10011
10
1001
[UpperEastSiders, {[Jenny, Humphrey, Queens, 9], [Blair, Waldorf, Manhattan, 11], [Chuck, Bass, Bronx, 6], [Jenny, Humphrey, Hudson, 8]}] 8.5
[UpperEastSiders, {[Jenny, Humphrey, Queens, 9], [Blair, Waldorf, Manhattan, 11], [Chuck, Bass, Bronx, 6], [Jenny, Humphrey, Hudson, 8]}] 8.5


Zusatz fuer 10 Punkte
01
[UpperEastSiders, {[Jenny, Humphrey, Queens, 9], [Blair, Waldorf, Manhattan, 11], [Chuck, Bass, Bronx, 6]}]
[UpperEastSiders, {[Jenny, Humphrey, Queens, 9], [Blair, Waldorf, Manhattan, 11]}]
[UpperEastSiders, {[Blair, Waldorf, Manhattan, 11]}]
[UpperEastSiders, {[Blair, Waldorf, Manhattan, 11]}] 11


Zusatz fuer 15 Punkte
[UpperEastSiders, {[Jenny, Humphrey, Queens, 9], [Blair, Waldorf, Manhattan, 11]}]
1
[UpperEastSiders, {[Jenny, Humphrey, Queens, 9], [Blair, Waldorf, Manhattan, 11], [Dan, Humphrey, Brookyln, 11], [Eric, van der Woodsen, Manhattan, 19]}]
[UpperEastSiders, {[Jenny, Humphrey, Queens, 9], [Blair, Waldorf, Manhattan, 11], [Dan, Humphrey, Brookyln, 11], [Eric, van der Woodsen, Manhattan, 19], [Chuck, Bass, Bronx, 6]}]
*/
