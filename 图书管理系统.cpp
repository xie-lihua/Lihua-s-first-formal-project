#include<iostream>
#include<string>
using namespace std;

	//简易的图书管理系统

	//全局定义书籍信息数组编号order
	int order = 0;

	//全局定义借阅人数组编号list
	int list = 0;

	//因能力有限，又本着便捷的原则.
	//本程序两数组初始容量为10，且未设置修改

	//借阅信息结构体
	struct  bookrent{
	string rent_per;
	string rent_time;
	string rent_limit;
};

	//书籍信息结构体
	struct book {
	string book_name;
	string book_isbn;
	string book_auth;
	string book_pub;
	double book_price = 0;
	int book_stock = 0;
	int book_total = 0;
};
	
	//输入书籍信息
	void inputbook(book* boin) {

		string name;		
		cout << "请输入书籍名称：";
		cin >> name;
		boin->book_name = name;

		
		string isbn;
		cout << "请输入书籍编号：";
		cin >> isbn;
		boin->book_isbn = isbn;

		string auth;
		cout << "请输入作者姓名：";
		cin >> auth;
		boin->book_auth = auth;
		
		string pub;
		cout << "请输入出版社名称：";
		cin >> pub;
		boin->book_pub = pub;

		double price = 0;
		int stock = 0;
		int total = 0;

		cout << "请输入书籍价格：";
		cin >> price;
		boin->book_price = price;

		cout << "请输入当前存量：";
		cin >> stock;
		boin->book_stock = stock;

		cout << "请输入书籍总量：";
		cin >> total;
		boin->book_total = total;
		system("pause");
		system("cls");
	}

	//输入借阅信息
	void inputrent(bookrent *bort){
		string per;
		cout << "请输入借阅人姓名：";
		cin >> per;
		bort->rent_per = per;

		string time; 
		cout << "请输入借阅时间：";
		cin >> time;
		bort->rent_time = time;

		string limit; 
		cout << "请输入归还期限：";
		cin >> limit;
		bort->rent_limit = limit;

		system("pause");
		system("cls");
	}

	//显示借阅信息
	void showper(bookrent *bort) {

		cout << "借阅人姓名：" <<
			bort->rent_per<<endl;

		cout << "请输入借阅:" <<
			bort->rent_time << endl;

		cout << "归还期限："<<
		bort->rent_limit << endl;

		}
	
	//显示书籍增删改查菜单
	void Showmenu() {

			cout << "欢迎使用图书管理系统 \n\n";
			cout << "	1.添加书籍信息\n"
				<< "	2.查询书籍信息\n"
				<< "	3.修改书籍信息\n"
				<< "	4.删除书籍信息\n"
				<< "	0.退出系统\n";

			cout << "\n请输入你要进行的操作：";

		}

	//显示初始入口菜单
	void showenter() {
			cout << "	1.管理员登录\n"
				<< "	2.借阅人登录\n"
				<< "	0.退出系统\n\n";
			cout << "请选择登录方式：";

		}

	//显示书籍各项信息
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

	//查找书籍是否存在
	void serch(book boin[]) {

		cout << "请输入你要查询的书籍名称：";
		string name;
		cin >> name;
		int i = 0, j = 0;

			//遍历查找书籍，找到即刻打印
			for (; i < 10; i++) {
				if (boin[i].book_name == name) {
					j++;
					showbook(&(boin[i]));
				}
			}
			if (j == 0)
				cout << "未收录此书籍 !\n";
			system("pause");
			system("cls");
		}

	//修改书籍信息
		//在查找的基础上修改
	void modify(book boin[]) {

			string name;
			string per;
			cout << "请输入你要修改的书籍名称:";
			cin >> name;
			int i = 0, j = 0;
			for (; i < 10; i++)
				if (boin[i].book_name == name) {
					j++;
					cout << "请进行修改：\n";
					inputbook(&boin[i]);
				}

			if (j == 0)
				cout << "未查询到此书籍信息 !\n";
			system("pause");
			system("cls");
		}

	//删除书籍信息
		//在查找的基础上删除
	void delet(book boin[]) {

			cout << "请输入你要删除的书籍名称：";
			string name;
			cin >> name;
			int i = 0, j = 0;
			for (; i < 10; i++) {
				if (boin[i].book_name == name) {
					j++;

					//找到就将此位置后面的数据逐次向前迁移
					for (int p = i; p < 9; p++) {
						boin[p] = boin[p + 1];
					}
					cout << "删除成功\n";
				}
			}
			if (j == 0)
				cout << "未收录此书籍信息 !\n";
			system("pause");
			system("cls");

		}
	

	//借阅人操作选项
	void showrentmenu(){

		cout << endl <<
			"	1.添加借阅信息\n"
			<< "	2.查询借阅信息\n" <<
			"	0.退出借阅人系统\n\n";
		cout << "请输入你要进行的操作：";

}

	//查询某人的借阅情况
	void serchper(bookrent abs[]) {

		cout << "请输入你要查询借阅人姓名：";
		string name;
		cin >> name;

		int i = 0, j = 0;

		//遍历查询是否有借阅人姓名与所输对应
		for (; i < 10; i++) {
			if (abs[i].rent_per == name) {
				j++;
				 showper(&abs[i]);
			}
		}

		if (j == 0) {
			cout << "未查询到借阅人信息 !\n";
			system("pause");
			system("cls");
		}
	}

int main() {

	cout << "***欢迎使用图书管理系统***\n\n";

	//定义书籍信息数组
	book bookinfo[10]; 

	//定义借阅人数组
	bookrent person[10];

	int sele = 0;
	
	//设置标记，以便返回，以重复输入和选择
	flag: showenter();

	cin >> sele;
	if (sele == 1) {

		//清屏，以便观赏
		system("cls");

		int choice = 0;

		//设置循环，通过goto跳出循环
		while (true) {

			Showmenu();
			cin >> choice;
			
		flag_1: 
			//进行图书管理员的各项操作
			switch (choice) {

			case 1:
				inputbook(&(bookinfo[order]));
				//数据存入数组，下标自加，以便下次输入
				order++;
				break;

			case 2:serch(bookinfo); break;
			case 3:modify(bookinfo); break;
			case 4:delet(bookinfo); break;

			case 0: 
				cout << "\n已退出管理员系统\n\n";
				system("pause");
				system("cls");
				//清屏并重新选择入口操作
				goto  flag;
				break; 

			default: 
				cout << "请重新输入!\n";

				cin >> choice;
				//返回，重新进行管理员操作
				goto flag_1;
				break;
			}
		}
	}

	if (sele == 2) {

		
		system("cls");
		int todo;
	
		while (true) {

	//显示借阅人各项操作
		showrentmenu();
		cin >> todo;

	//设置标记，以便返回跳出循环
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
				cout << "\n已退出借阅人系统\n";
				system("pause");
				system("cls");
				//退出并返回入口操作
				goto flag;
				break;

			default:
				cout << "请重新输入!\n";
				cin >> todo;
				goto flag_2;
				break;
			}

		}
	}	
	
	if (sele == 0) {
		cout << "\n已退出系统\n" << endl;
		return 0;
	}
	return 0;
}