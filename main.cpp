#include <iostream>
#include <fstream>

using namespace std;

int main()
{
   fstream fd;
   int s, c1, c2;
   char mesaj;
   fd.open( "fdate.txt", ios::app);
   mesaj = 'd';
   while (tolower(mesaj) == 'd')
   {
      cout << "Introduceti setul (sectie cand_1 cand_2): ";
      cin >> s >> c1 >> c2;
      fd << s << '\t' << c1 << '\t' << c2 << endl;
      cin.ignore();
      cout << "Mai introduceti date? (d/n) ";
      cin >> mesaj;
   }
   fd.close();
   return 0;
}

int exista(int s)
{
   fstream fd;
   fd.open( "fdate.txt", ios::in);
   int sec, c1, c2;
   int gasit = 0;
   fd >> sec >> c1 >> c2;
   while (fd.good())
   {
      // Citire valida
      if (sec == s)
      {
         gasit = 1;
         break;
      }
      fd >> sec >> c1 >> c2;
   }
   fd.close();
   return gasit;
}