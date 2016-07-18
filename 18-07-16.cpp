#include <iostream>
#include <cstring>
using namespace std;

struct studente{
	char cognome [20];
	int userID;
	char password [10];
	studente* succ;
};
typedef studente* lista;

void inseriscidati (studente &a){
cout << "immetti il tuo cognome ";
cin >> a.cognome;
cout << "inserisci il tuo userID ";
cin >> a.userID;
cout << "password ";
cin >> a.password;
}

bool uguali (char str1[], char str2 []){
int i=0;
bool c=false;
while(str1[i]!='\0')
{
if (str1[i] == str2 [i]) c=true;
else c=false;
i++;
}
if (c)return true;
else return false;
}

bool verificauserID(lista inizio, studente a){
lista p;
for (p=inizio; p!=0; p=p->succ)
{
if (p->userID==a.userID)
{cout << "questo useID appartiene a " << p->cognome << endl;
return true;
}
}
return false;
}

void inserisci (lista& inizio, studente a){
lista p=0,q;
for (q=inizio; q!=0 && q->userID < a.userID; q=q->succ) p=q;
lista r = new studente;
*r=a;
r->succ=q;
if (q==inizio) inizio=r;
else p-> succ=r;
}

bool estraielemdato (lista& inizio,studente &a){
lista p,q;
for (q=inizio;q!=0 && !uguali(q->cognome, a.cognome);q=q->succ) p=q;
if (q==0)return false;
a=*q;
if (q==inizio) inizio=q->succ;
else p->succ=q->succ;
delete q;
return true;
}
void stampa (lista p){
while(p!=0){
cout << "cognome:" << p->cognome << "\nuserID: " << p->userID << "\nPassword: " << p->password << endl;
p=p->succ;
}
}

int main () {
char s;
studente elem;
lista l=0;
do{
cout << "ecco quello che puoi fare: \n";
cout << "i: inserisci un nuovo studente \n";
cout << "s: visualizza a schermo la lista degli studenti\n";
cout << "e:estrai uno studente in base al cognome\n";
cin >> s;
switch (s){
case 'i': {
inseriscidati(elem);
if (!verificauserID(l,elem)) inserisci (l,elem);
}break;
case 's': {
if (l==0) cout << "lista vuota\n";
else stampa(l);
} break;
case 'e':{
cin >> elem.cognome;
if (estraielemdato (l,elem)){
cout << "ho tolto " << elem.cognome << " con il numero " << elem.userID << endl;
}
else cout << "studete non in lista" << endl;
} break;
}
} while (s=='i' || s=='s' || s=='e');
return 0;
}
