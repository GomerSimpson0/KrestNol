#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include <time.h>
using namespace std;

char a[9];
bool global = false;

void def();
void att();
void noth();

void itog();

void getprint(){
	cout << "Первая цифра обозначает линию, а вторая цифра столбик" << endl;
	cout << endl << "Вы ходите крестиками (x), а компьютер ноликами (o)" << endl;
	cout << endl << endl << "                        1   2   3  " << endl;
	cout << "                    1   " << a[0] << " | " << a[1] << " | " << a[2] << "  " << endl;
	cout << "                      ____|___|____" << endl;
	cout << "                    2   " <<a[3] <<" | " << a[4] << " | " << a[5] << "  " << endl;
	cout << "                      ____|___|____" << endl;
	cout << "                    3   " << a[6] << " | " << a[7] << " | " << a[8] << "  " << endl;
	cout << "                          |   |    " << endl;
}

void chek(int i){
	if (a[i] != ' '){
		cout << endl <<  "На этом месте уже был знак" << endl << endl;
		cout << "Вы сломали игру(((" << endl << endl << endl;
		system("pause");
		exit(0);
	}
	else {
		a[i] = 'x';
	}
}

void setprint(int n){
	     if (n == 11) chek(0);
	else if (n == 12) chek(1);
	else if (n == 13) chek(2);
	else if (n == 21) chek(3);
	else if (n == 22) chek(4);
	else if (n == 23) chek(5);
	else if (n == 31) chek(6);
	else if (n == 32) chek(7);
	else if (n == 33) chek(8);

	else {
		system("cls");
		cout << "Нет соответствующей команды" << endl;
		cout << endl;
		cout << "Вы сломали игру(((" << endl << endl << endl;
		system("pause");
		exit(0);
	}
}

int main(){
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	int ch;
	cout << "Здравствуйте, Вас приветсвует игра \"Крестики-нолики\"";
	cout << endl << endl << "Когда вы будете готовы играть, нажмите любую клавишу" << endl << endl << endl << endl << endl;
	system("pause");
	system("cls");
	for (int i = 0; i < 9; i++){
		a[i] = ' ';
	}

	for (int i = 0; i < 5; i++){
		//int ran = rand() % 9;
		getprint();
		cout << endl;
		cout << "Ваш ход: ";
		cin >> ch;
		setprint(ch);
		system ("cls");
		itog();
		if (i != 4){
			getprint();
			system("cls");
			getprint();
			cout << endl;
			cout << "Ход компьютера . . .";
			Sleep(1300);
			system ("cls");
			att();
			itog();
		}
		else {
			getprint();
			cout << endl << endl << endl << "Сегодня у нас ничья" << endl << endl;
			cout << "Приходите ещё)" << endl << endl << endl;
		}
	}
system("pause");
return 0;
}

void win(){
	getprint();
	cout << endl << endl << endl;
	cout << "Вы выиграли, поздравляем!" << endl;
	cout << "Будем ждать вас ещё" << endl << endl << endl;
	system("pause");
	exit(0);
}

void lose(){
	getprint();
	cout << endl << endl << endl;
	cout << "Вы проиграли!" << endl;
	cout << "Не расстраивайтесь, мне все проигрывают" << endl;
	cout << "До скорых встреч!" << endl << endl << endl;
	system("pause");
	exit(0);
}

void itog(){
	     if ((a[0] == 'x') && (a[1] == 'x') && (a[2] == 'x')) win();
	else if ((a[3] == 'x') && (a[4] == 'x') && (a[5] == 'x')) win();
	else if ((a[6] == 'x') && (a[7] == 'x') && (a[8] == 'x')) win();
	else if ((a[0] == 'x') && (a[3] == 'x') && (a[6] == 'x')) win();
	else if ((a[1] == 'x') && (a[4] == 'x') && (a[7] == 'x')) win();
	else if ((a[2] == 'x') && (a[5] == 'x') && (a[8] == 'x')) win();
	else if ((a[0] == 'x') && (a[4] == 'x') && (a[8] == 'x')) win();
	else if ((a[2] == 'x') && (a[4] == 'x') && (a[6] == 'x')) win();
	
	else if ((a[0] == 'o') && (a[1] == 'o') && (a[2] == 'o')) lose();
	else if ((a[3] == 'o') && (a[4] == 'o') && (a[5] == 'o')) lose();
	else if ((a[6] == 'o') && (a[7] == 'o') && (a[8] == 'o')) lose();
	else if ((a[0] == 'o') && (a[3] == 'o') && (a[6] == 'o')) lose();
	else if ((a[1] == 'o') && (a[4] == 'o') && (a[7] == 'o')) lose();
	else if ((a[2] == 'o') && (a[5] == 'o') && (a[8] == 'o')) lose();
	else if ((a[0] == 'o') && (a[4] == 'o') && (a[8] == 'o')) lose();
	else if ((a[2] == 'o') && (a[4] == 'o') && (a[6] == 'o')) lose();
}

void setdef(int i){
	a[i] = 'o';
}

void setatt(int i){
	a[i] = 'o';
}

void setnoth(int i){
	a[i] = 'o';
}

void att(){
	if (global == false){
		int ran = rand() % 9;
		if (a[ran] == ' ') a[ran] = 'o';
		else a[ran + 1] = 'o';
		global = true;
	}
	else{
	         if ((a[0] == ' ') && (a[1] == 'o') && (a[2] == 'o')) setatt(0);  //0
		else if ((a[0] == ' ') && (a[3] == 'o') && (a[6] == 'o')) setatt(0);  
		else if ((a[0] == ' ') && (a[4] == 'o') && (a[8] == 'o')) setatt(0);
		
		else if ((a[1] == ' ') && (a[0] == 'o') && (a[2] == 'o')) setatt(1);  //1
		else if ((a[1] == ' ') && (a[4] == 'o') && (a[7] == 'o')) setatt(1);
		
		else if ((a[2] == ' ') && (a[0] == 'o') && (a[1] == 'o')) setatt(2);  //2
		else if ((a[2] == ' ') && (a[5] == 'o') && (a[8] == 'o')) setatt(2);
		else if ((a[2] == ' ') && (a[4] == 'o') && (a[6] == 'o')) setatt(2);
	
		
		else if ((a[3] == ' ') && (a[0] == 'o') && (a[6] == 'o')) setatt(3);  //3
		else if ((a[3] == ' ') && (a[4] == 'o') && (a[5] == 'o')) setatt(3);
		
		else if ((a[4] == ' ') && (a[1] == 'o') && (a[7] == 'o')) setatt(4);  //4
		else if ((a[4] == ' ') && (a[3] == 'o') && (a[5] == 'o')) setatt(4);
		else if ((a[4] == ' ') && (a[0] == 'o') && (a[8] == 'o')) setatt(4);
		else if ((a[4] == ' ') && (a[2] == 'o') && (a[6] == 'o')) setatt(4);
		
		else if ((a[5] == ' ') && (a[2] == 'o') && (a[8] == 'o')) setatt(5);  //5
		else if ((a[5] == ' ') && (a[3] == 'o') && (a[4] == 'o')) setatt(5);
		
		else if ((a[6] == ' ') && (a[0] == 'o') && (a[3] == 'o')) setatt(6);  //6
		else if ((a[6] == ' ') && (a[7] == 'o') && (a[8] == 'o')) setatt(6);
		else if ((a[6] == ' ') && (a[2] == 'o') && (a[4] == 'o')) setatt(6);
		
		else if ((a[7] == ' ') && (a[6] == 'o') && (a[8] == 'o')) setatt(7);  //7
		else if ((a[7] == ' ') && (a[1] == 'o') && (a[4] == 'o')) setatt(7);
		
		else if ((a[8] == ' ') && (a[6] == 'o') && (a[7] == 'o')) setatt(8);  //8
		else if ((a[8] == ' ') && (a[2] == 'o') && (a[5] == 'o')) setatt(8);
		else if ((a[8] == ' ') && (a[0] == 'o') && (a[4] == 'o')) setatt(8);
		
		else def();
	}
}

void def(){
	     if ((a[0] == ' ') && (a[1] == 'x') && (a[2] == 'x')) setdef(0);  //0
	else if ((a[0] == ' ') && (a[3] == 'x') && (a[6] == 'x')) setdef(0);  
	else if ((a[0] == ' ') && (a[4] == 'x') && (a[8] == 'x')) setdef(0);
	
	else if ((a[1] == ' ') && (a[0] == 'x') && (a[2] == 'x')) setdef(1);  //1
	else if ((a[1] == ' ') && (a[4] == 'x') && (a[7] == 'x')) setdef(1);
	
	else if ((a[2] == ' ') && (a[0] == 'x') && (a[1] == 'x')) setdef(2);  //2
	else if ((a[2] == ' ') && (a[5] == 'x') && (a[8] == 'x')) setdef(2);
	else if ((a[2] == ' ') && (a[4] == 'x') && (a[6] == 'x')) setdef(2);

	
	else if ((a[3] == ' ') && (a[0] == 'x') && (a[6] == 'x')) setdef(3);  //3
	else if ((a[3] == ' ') && (a[4] == 'x') && (a[5] == 'x')) setdef(3);
	
	else if ((a[4] == ' ') && (a[1] == 'x') && (a[7] == 'x')) setdef(4);  //4
	else if ((a[4] == ' ') && (a[3] == 'x') && (a[5] == 'x')) setdef(4);
	else if ((a[4] == ' ') && (a[0] == 'x') && (a[8] == 'x')) setdef(4);
	else if ((a[4] == ' ') && (a[2] == 'x') && (a[6] == 'x')) setdef(4);
	
	else if ((a[5] == ' ') && (a[2] == 'x') && (a[8] == 'x')) setdef(5);  //5
	else if ((a[5] == ' ') && (a[3] == 'x') && (a[4] == 'x')) setdef(5);
	
	else if ((a[6] == ' ') && (a[0] == 'x') && (a[3] == 'x')) setdef(6);  //6
	else if ((a[6] == ' ') && (a[7] == 'x') && (a[8] == 'x')) setdef(6);
	else if ((a[6] == ' ') && (a[2] == 'x') && (a[4] == 'x')) setdef(6);
	
	else if ((a[7] == ' ') && (a[6] == 'x') && (a[8] == 'x')) setdef(7);  //7
	else if ((a[7] == ' ') && (a[1] == 'x') && (a[4] == 'x')) setdef(7);
	
	else if ((a[8] == ' ') && (a[6] == 'x') && (a[7] == 'x')) setdef(8);  //8
	else if ((a[8] == ' ') && (a[2] == 'x') && (a[5] == 'x')) setdef(8);
	else if ((a[8] == ' ') && (a[0] == 'x') && (a[4] == 'x')) setdef(8);
	
	else noth();
}

void noth(){
	     if ((a[3] == 'o') && (a[0] == ' ')) setnoth(0);  //3
	else if ((a[3] == 'o') && (a[4] == ' ')) setnoth(4);
	else if ((a[3] == 'o') && (a[6] == ' ')) setnoth(6);
	
	else if ((a[4] == 'o') && (a[0] == ' ')) setnoth(0);  //4
	else if ((a[4] == 'o') && (a[1] == ' ')) setnoth(1);
	else if ((a[4] == 'o') && (a[2] == ' ')) setnoth(2);
	else if ((a[4] == 'o') && (a[3] == ' ')) setnoth(3);
	else if ((a[4] == 'o') && (a[5] == ' ')) setnoth(5);
	else if ((a[4] == 'o') && (a[6] == ' ')) setnoth(6);
	else if ((a[4] == 'o') && (a[7] == ' ')) setnoth(7);
	else if ((a[4] == 'o') && (a[8] == ' ')) setnoth(8);
	
	else if ((a[5] == 'o') && (a[2] == ' ')) setnoth(2);  //5
	else if ((a[5] == 'o') && (a[4] == ' ')) setnoth(4);
	else if ((a[5] == 'o') && (a[8] == ' ')) setnoth(8);
	
	else if ((a[0] == 'o') && (a[1] == ' ')) setnoth(1);  //0
	else if ((a[0] == 'o') && (a[3] == ' ')) setnoth(3);
	else if ((a[0] == 'o') && (a[4] == ' ')) setnoth(4);
	
	else if ((a[1] == 'o') && (a[0] == ' ')) setnoth(0);  //1
	else if ((a[1] == 'o') && (a[2] == ' ')) setnoth(2);
	else if ((a[1] == 'o') && (a[4] == ' ')) setnoth(4);
	
	else if ((a[2] == 'o') && (a[1] == ' ')) setnoth(1);  //2
	else if ((a[2] == 'o') && (a[4] == ' ')) setnoth(4);
	else if ((a[2] == 'o') && (a[5] == ' ')) setnoth(5);
	
	else if ((a[6] == 'o') && (a[3] == ' ')) setnoth(3); //6
	else if ((a[6] == 'o') && (a[4] == ' ')) setnoth(4);
	else if ((a[6] == 'o') && (a[7] == ' ')) setnoth(7);
	
	else if ((a[7] == 'o') && (a[6] == ' ')) setnoth(6); //7
	else if ((a[7] == 'o') && (a[4] == ' ')) setnoth(4);
	else if ((a[7] == 'o') && (a[8] == ' ')) setnoth(8);
	
	else if ((a[8] == 'o') && (a[7] == ' ')) setnoth(7); //8
	else if ((a[8] == 'o') && (a[4] == ' ')) setnoth(4);
	else if ((a[8] == 'o') && (a[5] == ' ')) setnoth(5);
}
