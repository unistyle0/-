#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cstring>
#include <cctype>
void array(int[],int);
using namespace std;//�ϥ�std�W�٪Ŷ�
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
		money = 1000;  // �p�GŪ�����ѡA��l�Ƭ��w�]��
	}
	cout<<"=================�q�Ʀr�C��=================\n";
	do {
		cout<<"�п�ܵ���(��J1~5�Ʀr):";
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
			cout<<"�п�J�Ʀr("<<x<<"���):";
			cin>>str;
			if (str.length() != x) {
				cout << "��J���Ʀr���פ����T�A�Э��s��J�C\n";
				continue;  // �^��j�骺�}�Y�A���s��J�Ʀr
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
				cout<<"�z�����ƹF�W��,�C������\n";
				cout<<"���׬O:"; 
				for(int m=0; m<x; m++) {
					cout<<temp[m];
				}
				cout<<endl;
				break;
			}
			if (a==x) {
				cout<<"�z�q��F!\n";
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
	cout<<"�z�{�b��������"<<money<<"��\n";
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


