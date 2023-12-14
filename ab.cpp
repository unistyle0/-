#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cstring>
#include <cctype>
void array(int[],int);
using namespace std;//使用std名稱空間
int main() {
	srand(time(0));
	bool flag;
	int temp[8];
	int x;
	string s;
	int a=0,b=0,count=0,money,guess[8];
	ifstream fin("money.txt");
	if (fin) {
		fin >> money;
		fin.close();
	} else {
		money = 1000;  // 如果讀取失敗，初始化為預設值
	}
	cout<<"=================猜數字遊戲=================\n";
	do {
		cout<<"請選擇等級(輸入1~5數字):";
		cin>>s;
		if (s=="1") {
			x=4;
			array(temp,4);
		} else if (s=="2") {
			x=5;
			array(temp,5);
		} else if (s=="3") {
			x=6;
			array(temp,6);
		}

		else if (s=="4") {
			x=7;
			array(temp,7);
		} else {
			x=8;
			array(temp,8);
		}
	} while(!s.length()==1);
	cout<<endl;
	while(count<=7) {
		do {
			string str;
			cout<<"請輸入數字("<<x<<"位數):";
			cin>>str;
			if (str.length() != x) {
				cout << "輸入的數字長度不正確，請重新輸入。\n";
				continue;  // 回到迴圈的開頭，重新輸入數字
			}
			for(int m=0; m<x; m++)
				guess[m]=str[m]-48;
			a=0;
			b=0;
			for(int m=0; m<x; m++) {
				for(int p=0; p<x; p++) {
					if(temp[m]==guess[p]) {
						if(m==p)
							a++;
						else

							b++;
					}
				}
			}
			count++;
			cout<<a<<"A"<<b<<"B\n";
			if (count==7) {
				cout<<"您的次數達上限,遊戲結束\n";
				cout<<"答案是:"; 
				for(int m=0; m<x; m++) {
					cout<<temp[m];
				}
				cout<<endl;
				break;
			}
			if (a==x) {
				cout<<"您猜對了!\n";
				break;
			}

		} while(a!=x);
		if (a==x) {
			break;
		}
	}
	fstream fos("money.txt",ios::out);
	switch (count) {
		case 1:
			money+=6000;
			break;
		case 2:
			money+=4500;
			break;
		case 3:
			money+=3000;
			break;
		case 4:
			money+=2000;
			break;
		case 5:
			money+=1000;
			break;
		case 6:
			money+=500;
			break;
		case 7:
			money+=0;
			break;
	}
	fos<<money;
	fos.close();
	cout<<"您現在的獎金為"<<money<<"分\n";
	return 0;
}
void array(int temp[],int x) {
	srand(time(0));
	for(int m=0; m<x; m++) {
		temp[m]=rand()%10;
		for(int p=0; p<m; p++) {
			if(temp[m]==temp[p]) {
				m--;
				break;
			}
		}
	}
//	for(int m=0; m<x; m++) {
//		cout<<temp[m];
//	}
}


