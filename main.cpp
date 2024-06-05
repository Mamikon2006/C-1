#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
struct book { int n; char name[20]; int q;};
void qanak(book *x,book *y,int n,int &k,int s){
k = 0;
s = 0;
for(int i = 0; i < n; i++){
s +=x[i].q;
if(s <= 70){
y[k].n = x[i].n;
strcpy(y[k].name,x[i].name);
k++;
}
}
}
void menu() {
cout << "1. xntir1" << endl;
cout << "2. xntir2" << endl;
cout << "3. exit" << endl;
}

void menu1() {
cout << "\n Xndir 1.teqstayin fayl\n" << endl;
cout << "1. Xndri pahanj@" << endl;
cout << "2. Xndri lucum@" << endl;
cout << "3. Veradardz Glxavor Menu\n" << endl;
cout << "Mutqagreq tiv@: ";
}
void menu2() {
cout << "\n Xndir 2.tvayin fayl\n" << endl;
cout << "1. Xndri pahanj@" << endl;
cout << "2. Xndri lucum@" << endl;
cout << "3. Veradardz Glxavor Menu\n" << endl;
cout << "Mutqagreq tiv@: ";
}
void pahanj1() {
cout <<"740"<<endl<<"Srvac e n amboxch tiv ev n tar parunakox zangvac@:Zangvaci tarer@ grarumner en, voronc hamar baxadrichner en. Tvyal grqiparagrafneri 1.hamar@ 2.vernagir@ 3.ejeri qanak@: Tpel grqi aracjn 70 ejihamarner@ ev vernagrer@"<<endl;
}
void lucum1() {

//740
fstream f;
int i,n,k,s;
char h[20];
do cin >> n; while(n < 1);
book *x = new book[n];
book *y = new book[n];
if(x == 0)
exit(5);
k=0;
for(i = 0; i < n; i++){
cin >> x[i].n >> x[i].name >> x[i].q;}
qanak(x,y,n,k,s);
f.open("DD1.DAT", ios::out);
if (!f) exit(3);
for(int i = 0; i < k; i++)
f << y[i].name << "\t" << y[i].n << endl;
f.close();
f.open("DD1.DAT", ios::in);
if (!f) exit(3);

while(f >> h)
cout << h << endl;
f.close();
delete []x;
x = 0;
delete []y;
y = 0;
}
void pahanj2() {
cout <<"758"<<endl<<"Fayli mej skzbum grel a ic poqr zangvati tver@, heto havasarner@ heto macer@"<<endl;
}
void lucum2() {
//758
fstream f;
int n,i,q,a;
do cin >> n; while (n < 1);
double *x = new double[n];
double *y = new double[n];
if(x==0 || y==0)
exit(1);
f.open("DD4.DAT",ios::out | ios::binary);
if (!f) exit(2);
for(i = 0; i < n; i++){
cin >>x[i];
f.write((char*)&x[i], sizeof(double));
}
f.close();
f.open("DD4.DAT",ios::in | ios::binary);
if (!f) exit(2);
while(i=0) f.read((char*)&x[i], sizeof(double));
f.close();
cin >> a;
q = 0;
for (i = 0; i < n; i++)
{
if(x[i] < a){
y[q] = x[i];
q++;
}
}
for (i = 0; i < n; i++)
{

if(x[i] == a){
y[q] = x[i];
q++;
}
}
for (i = 0; i < n; i++)
{
if(x[i] > a){
y[q] = x[i];
q++;
}
}
f.open("DD4.DAT", ios::out | ios::binary);
if (!f) exit(3);
for(int i = 0; i < n; i++)
f.write((char*) &y[i], sizeof(double));
f.close();
f.open("DD4.DAT", ios::in | ios::binary);
if (!f) exit(3);
while(f.read((char*) &y[i], sizeof(double)))
cout << y[i];
f.close();
delete []x;
x = 0;
delete []y;
y = 0;
}
int main() {
int tiv;
int hamar;
do {
menu();
if (!(cin >> tiv)) {
cout << "\nDuq cheq karox nermucel string \nCragri Avart!!\n" << endl;
break;
}
switch (tiv) {
case 1:
do {
menu1();
if (!(cin >> hamar)) {

cout << "\nDuq cheq karox nermucel string \nCragri Avart!!\n" <<

endl;

break;
}
switch (hamar) {
case 1:
pahanj1();
break;
case 2:
lucum1();
break;
case 3:
cout << "Veradardz Glxavor Menu\n" << endl;
break;
default:
cout << "\nSxal @ntrutyun pordzeq krkin.\n" << endl;
}
} while (hamar != 3);
break;
case 2:
do {
menu2();
if (!(cin >> hamar)) {
cout << "\nDuq cheq karox nermucel string \nCragri Avart!!\n" <<

endl;

break;
}
switch (hamar) {
case 1:
pahanj2();
break;
case 2:
lucum2();
break;
case 3:
cout << "Veradardz Glxavor Menu\n" << endl;
break;
default:
cout << "\nSxal @ntrutyun pordzeq krkin.\n" << endl;
}
} while (hamar != 3);
break;

case 3:
cout << "\nCragri Avart!\n" << endl;
break;
default:
cout << "\nSxal @ntrutyun pordzeq krkin.\n" << endl;
}
} while (tiv != 3);
return 0;
}