#include <iostream>
#include <fstream>
using namespace std;

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

int main()
{
   fstream fd;
   int s, c1, c2;
   char mesaj;
   mesaj = 'd';
   while (tolower(mesaj) == 'd')
   {
      cout << "Introduceti setul (sectie cand1 cand2): ";
      cin >> s >> c1 >> c2;
      if (exista(s))
         cout << "Sectia a mai fost introdusa! " << endl;
      else
      {
         fd.open( "fdate.txt", ios::app);
         fd << s << '\t' << c1 << '\t' << c2 << endl;
         fd.close();
      }
      cout << "Mai introduceti date? (d/n) ";
      cin.ignore();
      cin >> mesaj;
   }
   return 0;
}