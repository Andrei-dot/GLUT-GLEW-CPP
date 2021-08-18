#include<iostream>
#include<conio.h>
#include <cstdio>

using namespace std;

int entree1, entree2;

int main()
{
    system("CLS");
    cout << "1) Multiplication\n2) Addition \n3) Soustraction \n4) Division \n5) [SORTIE]\n<-------------->\n";

    switch (std::getc(stdin)) 
    {
        case '1':
            cout << "(!) Vous etes desormais en mode multiplication. \n-> Entrez votre premiere valeur :";
            cin >> entree1;
            cout << "-> Entrez votre seconde valeur :";
            cin >> entree2;
            cout << "<------------------------->\n";
            cout << "(!) Voici votre resultat : ";
            cout << entree1 * entree2;
            cout << "\n<------------------------->\n";
            break;
        case '2':
            cout << "(!) Vous etes desormais en mode addition. \n-> Entrez votre premiere valeur :";
            cin >> entree1;
            cout << "-> Entrez votre seconde valeur :";
            cin >> entree2;
            cout << "<------------------------->\n";
            cout << "(!) Voici votre resultat : ";
            cout << entree1 + entree2;
            cout << "\n<------------------------->\n";
            break;
        case '3':
            cout << "(!) Vous etes desormais en mode soustraction. \n-> Entrez votre premiere valeur :";
            cin >> entree1;
            cout << "-> Entrez votre seconde valeur :";
            cin >> entree2;
            cout << "<------------------------->\n";
            cout << "(!) Voici votre resultat : ";
            cout << entree1 - entree2;
            cout << "\n<------------------------->\n";
            break;
        case '4':
            cout << "(!) Vous etes desormais en mode division. \n-> Entrez votre premiere valeur :";
            cin >> entree1;
            cout << "-> Entrez votre seconde valeur :";
            cin >> entree2;
            cout << "<------------------------->\n";
            cout << "(!) Voici votre resultat : ";
            cout << entree1 / entree2;
            cout << "\n<------------------------->\n";
            break;
        case '5':   
            exit(0);
            break;
        default:
            break;
    }

    return 0;
}
