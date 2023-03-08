
/* zalecam nie uzywanie konsoli w peĹ‚nym oknie, aby uzyskaÄ‡ jak najwieksze wrazenia z uzytkowania programu :)) */


#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // uzywane przez "goto" informacje co do tego mozna znalezc na popularnych stronach o tematyce programowania 
COORD CursorPosition; // uzywane przez "goto" informacje co do tego mozna znalezc na popularnych stronach o tematyce programowania 

void gotoXY(int x, int y) 
{ 
	CursorPosition.X = x; 
	CursorPosition.Y = y;                    //ustalanie zmiennych x i y dziÄ™ki temu Ĺ‚atwiej bÄ™dzie nam pracowaÄ‡ z tymi funkcjami w przyszlosci
	SetConsoleCursorPosition(console,CursorPosition); 
}


	class DecimalToBinary {
	private:
	    int decimal_number;
	    vector<int> binary_number;
	
	public:
	    DecimalToBinary(int decimal_num) {
	        decimal_number = decimal_num;
	        convertToBinary();
	    }
	
	    void convertToBinary() {
	        int num = decimal_number;
	        while (num > 0) {
	            binary_number.push_back(num % 2);
	            num /= 2;
	        }
	        reverse(binary_number.begin(), binary_number.end());
	    }
	
	    void printBinary() {
	        cout << "W zapisie binarnym liczba " << decimal_number << " to: ";
	        for (int i = 0; i < binary_number.size(); i++) {
	            cout << binary_number[i];
	        }
	        cout << endl;
	    }
	};


	class DecimalToHexadecimal {
private:
    int decimal_number;
    vector<char> hexadecimal_number;

public:
    DecimalToHexadecimal(int decimal_num) {
        decimal_number = decimal_num;
        convertToHexadecimal();
    }

    void convertToHexadecimal() {
        int num = decimal_number;
        while (num > 0) {
            int remainder = num % 16;
            if (remainder < 10) {
                hexadecimal_number.push_back('0' + remainder);
            } else {
                hexadecimal_number.push_back('A' + remainder - 10);
            }
            num /= 16;
        }
        reverse(hexadecimal_number.begin(), hexadecimal_number.end());
    }

    void printHexadecimal() {
        cout << "W zapisie Hexadecymalnym liczba " << decimal_number << " to: ";
        for (int i = 0; i < hexadecimal_number.size(); i++) {
            cout << hexadecimal_number[i];
        }
        cout << endl;
    }
};

class U1 {
private:
    int num;

public:
    U1(int n) {
        if (n >= 0) {
            num = n;
        } else {
            num = pow(2, sizeof(int) * 8) - abs(n);
        }
    }

    int getNum() {
        return num;
    }

    void printU1() {
        int binary_num[sizeof(int) * 8];
        int n = num;
        for (int i = 0; i < sizeof(int) * 8; i++) {
            binary_num[i] = n % 2;
            n /= 2;
        }
        for (int i = sizeof(int) * 8 - 1; i >= 0; i--) {
            cout << binary_num[i];
        }
        cout << endl;
    }
};

class U2 {
private:
    int num;

public:
    U2(int n) {
        if (n >= 0) {
            num = n;
        } else {
            num = pow(2, sizeof(int) * 8 - 1) + abs(n);
        }
    }

    int getNum() {
        return num;
    }

    void printU2() {
        int binary_num[sizeof(int) * 8];
        int n = num;
        for (int i = 0; i < sizeof(int) * 8; i++) {
            binary_num[i] = n % 2;
            n /= 2;
        }
        for (int i = sizeof(int) * 8 - 1; i >= 0; i--) {
            cout << binary_num[i];
        }
        cout << endl;
    }
};







int main()
{  
 	HANDLE hOut = GetStdHandle( STD_OUTPUT_HANDLE );
	SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY); //wybieranie kolorĂłw znakĂłw w konsoli. DostÄ™pne kolory: (FOREGROUND_RED FOREGROUND_GREEN FOREGROUND_BLUE) Kolory mozna mieszaÄ‡, oraz zmieniac intensywnoĹ›Ä‡ itp.
	
	int wybor=0,  x=10; //deklarujemy zmienne, wybor odpowiada za wybieranie funkcji programu, x  (w tym przypadku x=10) za miejsce pierwszego wyboru w menu, tam strzaĹ‚ka pojawia siÄ™ jako pierwsza
	bool running = true; //dziÄ™ki tej linijce kodu, program jest w stanie dziaĹ‚ac az do wybrania funkcji "Zakoncz"
	
	 /*
    gotoXY(50,5); cout << "Menu glowne";
	gotoXY(38,7);  cout << "Po menu poruszasz sie strzalkami :)";
	*/
	while(running)
	{   
		gotoXY(50,5); cout << "Menu glowne";
		gotoXY(38,7);  cout << "Po menu poruszasz sie strzalkami :)";
		gotoXY(40,9);  cout << "============================";
        gotoXY(40,10);  cout << "= 1: DEC TO BIN            =";
		gotoXY(40,11);  cout << "= 2: DEC TO HEX            =";
		gotoXY(40,12);  cout << "= 3: U1 CODING             =";
		gotoXY(40,13); cout << "= 4: U2 CODING             =";	
		gotoXY(40,14);  cout << "=                          =";	
		gotoXY(40,15); cout << "=          Zakoncz         =";
		gotoXY(40,16);  cout << "============================";
		system("pause>nul"); // Funkcja >nul pozwala na brak wyswietlania komunikatu
		system("CLS");
		if(GetAsyncKeyState(VK_DOWN) && x != 15) // Ta czÄ™Ĺ›Ä‡ kodu odpowiada za poprawne dziaĹ‚anie strzaĹ‚ki w dĂłĹ‚, dziÄ™ki temu strzaĹ‚ka nie bÄ™dzie wychodziÄ‡ poza wyznaczony UWAGA WARTOĹšCI po " != " MUSZÄ„ BYC ZMIENIANE ZA KAZDYM RAZEM KIEDY DODAMY NOWÄ„ FUNKCJE W MENU
			{
				gotoXY(38,x); cout << "  ";
				x++;
				gotoXY(38,x); cout << "->";
				wybor++;
				continue;
				
			}
			
		if(GetAsyncKeyState(VK_UP) && x != 10) // Analogicznie jak do kodu u gĂłry, tylko, ze tymrazem jest to strzaĹ‚ka w gĂłre
			{
				gotoXY(38,x); cout << "  ";
				x--;
				gotoXY(38,x); cout << "->";
				wybor--;
				continue;
			}
			
		if(GetAsyncKeyState(VK_RETURN)){ // Ta linijka kodu pozwala na odczytanie wcisniÄ™tego "Enter" przez uzytkownika, tak aby program mĂłgĹ‚ wybrac danÄ… funkcje
			
			
			
			switch(wybor){           //Wszystko sprowadza siÄ™ do tej czeĹ›ci, mianowicie tutaj znajdujÄ… sie gĹ‚owne funkcje programu, w tym przypadku bÄ™dÄ… to zadania :))
				
				case 0: {
					
					gotoXY(40,16);
				 	int decimal_num;
    				cout << "Wpisz liczbe dziesietna: ";
    				cin >> decimal_num;

    				DecimalToBinary converter(decimal_num);
    				converter.printBinary();

				
					break;
				}
					
					
				case 1: {
					gotoXY(40,16);
					int decimal_num;
					cout << "Wpisz liczbe dziesietna: ";
					cin >> decimal_num;
					
					DecimalToHexadecimal converter(decimal_num);
					converter.printHexadecimal();

				   
					break;
				}
					
				case 2: {
					gotoXY(40,16);
					int n;
				    cout << "Wpisz liczbe: ";
				    cin >> n;
				
				    U1 u1(n);
				    cout << "Przedstawienie w kodowaniu U1 liczby " << n << " to: ";
				    u1.printU1();
				 	
					break;
				}
					
				case 3: {
					gotoXY(40,18);
					int n;
   					 cout << "Wpisz liczbe: ";
    				cin >> n;

				    U2 u2(n);
				    cout << "Przedstawienie w kodowaniu U2 liczby " << n << " to: ";
				    u2.printU2();
	
					break;
				}
					
				case 5: {
					gotoXY(40,16);
					cout << "Aktualnie program zakonczyl swoje dzialanie, mozesz wylaczyc okno konsoli!!";
					running = false;
				}
				
			}
				
		}		
		
	}
	
	
	return 0;
}