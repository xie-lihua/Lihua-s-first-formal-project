#include<iostream>
#include<string>
using namespace std;

	//���׵�ͼ�����ϵͳ

	//ȫ�ֶ����鼮��Ϣ������order
	int order = 0;

	//ȫ�ֶ��������������list
	int list = 0;

	//���������ޣ��ֱ��ű�ݵ�ԭ��.
	//�������������ʼ����Ϊ10����δ�����޸�

	//������Ϣ�ṹ��
	struct  bookrent{
	string rent_per;
	string rent_time;
	string rent_limit;
};

	//�鼮��Ϣ�ṹ��
	struct book {
	string book_name;
	string book_isbn;
	string book_auth;
	string book_pub;
	double book_price = 0;
	int book_stock = 0;
	int book_total = 0;
};
	
	//�����鼮��Ϣ
	void inputbook(book* boin) {

		string name;		
		cout << "�������鼮���ƣ�";
		cin >> name;
		boin->book_name = name;

		
		string isbn;
		cout << "�������鼮��ţ�";
		cin >> isbn;
		boin->book_isbn = isbn;

		string auth;
		cout << "����������������";
		cin >> auth;
		boin->book_auth = auth;
		
		string pub;
		cout << "��������������ƣ�";
		cin >> pub;
		boin->book_pub = pub;

		double price = 0;
		int stock = 0;
		int total = 0;

		cout << "�������鼮�۸�";
		cin >> price;
		boin->book_price = price;

		cout << "�����뵱ǰ������";
		cin >> stock;
		boin->book_stock = stock;

		cout << "�������鼮������";
		cin >> total;
		boin->book_total = total;
		system("pause");
		system("cls");
	}

	//���������Ϣ
	void inputrent(bookrent *bort){
		string per;
		cout << "�����������������";
		cin >> per;
		bort->rent_per = per;

		string time; 
		cout << "���������ʱ�䣺";
		cin >> time;
		bort->rent_time = time;

		string limit; 
		cout << "������黹���ޣ�";
		cin >> limit;
		bort->rent_limit = limit;

		system("pause");
		system("cls");
	}

	//��ʾ������Ϣ
	void showper(bookrent *bort) {

		cout << "������������" <<
			bort->rent_per<<endl;

		cout << "���������:" <<
			bort->rent_time << endl;

		cout << "�黹���ޣ�"<<
		bort->rent_limit << endl;

		}
	
	//��ʾ�鼮��ɾ�Ĳ�˵�
	void Showmenu() {

			cout << "��ӭʹ��ͼ�����ϵͳ \n\n";
			cout << "	1.����鼮��Ϣ\n"
				<< "	2.��ѯ�鼮��Ϣ\n"
				<< "	3.�޸��鼮��Ϣ\n"
				<< "	4.ɾ���鼮��Ϣ\n"
				<< "	0.�˳�ϵͳ\n";

			cout << "\n��������Ҫ���еĲ�����";

		}

	//��ʾ��ʼ��ڲ˵�
	void showenter() {
			cout << "	1.����Ա��¼\n"
				<< "	2.�����˵�¼\n"
				<< "	0.�˳�ϵͳ\n\n";
			cout << "��ѡ���¼��ʽ��";

		}

	//��ʾ�鼮������Ϣ
	void showbook(book * boin) {
			cout << boin->book_name << "\t";
			cout << boin->book_isbn << "\t";
			cout << boin->book_auth << "\t";
			cout << boin->book_pub << "\t";
			cout << boin->book_price << "\t";
			cout << boin->book_stock << "\t";
			cout << boin->book_total << "\t";
			system("pause");
			system("cls");
		};

	//�����鼮�Ƿ����
	void serch(book boin[]) {

		cout << "��������Ҫ��ѯ���鼮���ƣ�";
		string name;
		cin >> name;
		int i = 0, j = 0;

			//���������鼮���ҵ����̴�ӡ
			for (; i < 10; i++) {
				if (boin[i].book_name == name) {
					j++;
					showbook(&(boin[i]));
				}
			}
			if (j == 0)
				cout << "δ��¼���鼮 !\n";
			system("pause");
			system("cls");
		}

	//�޸��鼮��Ϣ
		//�ڲ��ҵĻ������޸�
	void modify(book boin[]) {

			string name;
			string per;
			cout << "��������Ҫ�޸ĵ��鼮����:";
			cin >> name;
			int i = 0, j = 0;
			for (; i < 10; i++)
				if (boin[i].book_name == name) {
					j++;
					cout << "������޸ģ�\n";
					inputbook(&boin[i]);
				}

			if (j == 0)
				cout << "δ��ѯ�����鼮��Ϣ !\n";
			system("pause");
			system("cls");
		}

	//ɾ���鼮��Ϣ
		//�ڲ��ҵĻ�����ɾ��
	void delet(book boin[]) {

			cout << "��������Ҫɾ�����鼮���ƣ�";
			string name;
			cin >> name;
			int i = 0, j = 0;
			for (; i < 10; i++) {
				if (boin[i].book_name == name) {
					j++;

					//�ҵ��ͽ���λ�ú�������������ǰǨ��
					for (int p = i; p < 9; p++) {
						boin[p] = boin[p + 1];
					}
					cout << "ɾ���ɹ�\n";
				}
			}
			if (j == 0)
				cout << "δ��¼���鼮��Ϣ !\n";
			system("pause");
			system("cls");

		}
	

	//�����˲���ѡ��
	void showrentmenu(){

		cout << endl <<
			"	1.��ӽ�����Ϣ\n"
			<< "	2.��ѯ������Ϣ\n" <<
			"	0.�˳�������ϵͳ\n\n";
		cout << "��������Ҫ���еĲ�����";

}

	//��ѯĳ�˵Ľ������
	void serchper(bookrent abs[]) {

		cout << "��������Ҫ��ѯ������������";
		string name;
		cin >> name;

		int i = 0, j = 0;

		//������ѯ�Ƿ��н����������������Ӧ
		for (; i < 10; i++) {
			if (abs[i].rent_per == name) {
				j++;
				 showper(&abs[i]);
			}
		}

		if (j == 0) {
			cout << "δ��ѯ����������Ϣ !\n";
			system("pause");
			system("cls");
		}
	}

int main() {

	cout << "***��ӭʹ��ͼ�����ϵͳ***\n\n";

	//�����鼮��Ϣ����
	book bookinfo[10]; 

	//�������������
	bookrent person[10];

	int sele = 0;
	
	//���ñ�ǣ��Ա㷵�أ����ظ������ѡ��
	flag: showenter();

	cin >> sele;
	if (sele == 1) {

		//�������Ա����
		system("cls");

		int choice = 0;

		//����ѭ����ͨ��goto����ѭ��
		while (true) {

			Showmenu();
			cin >> choice;
			
		flag_1: 
			//����ͼ�����Ա�ĸ������
			switch (choice) {

			case 1:
				inputbook(&(bookinfo[order]));
				//���ݴ������飬�±��Լӣ��Ա��´�����
				order++;
				break;

			case 2:serch(bookinfo); break;
			case 3:modify(bookinfo); break;
			case 4:delet(bookinfo); break;

			case 0: 
				cout << "\n���˳�����Աϵͳ\n\n";
				system("pause");
				system("cls");
				//����������ѡ����ڲ���
				goto  flag;
				break; 

			default: 
				cout << "����������!\n";

				cin >> choice;
				//���أ����½��й���Ա����
				goto flag_1;
				break;
			}
		}
	}

	if (sele == 2) {

		
		system("cls");
		int todo;
	
		while (true) {

	//��ʾ�����˸������
		showrentmenu();
		cin >> todo;

	//���ñ�ǣ��Ա㷵������ѭ��
	flag_2:	

		switch (todo)
		{
			case 1:
				inputrent(&person[list]);
				list++;
				break;

			case 2:
				serchper(person);
				system("pause");
				system("cls");
				break;

			case 0:
				cout << "\n���˳�������ϵͳ\n";
				system("pause");
				system("cls");
				//�˳���������ڲ���
				goto flag;
				break;

			default:
				cout << "����������!\n";
				cin >> todo;
				goto flag_2;
				break;
			}

		}
	}	
	
	if (sele == 0) {
		cout << "\n���˳�ϵͳ\n" << endl;
		return 0;
	}
	return 0;
}