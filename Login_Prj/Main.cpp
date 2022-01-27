# include <iostream>
# include <string>

# define MAX 100		// 通讯录最多100位联系人
int flag = 0;			  // 设定重复操作标志

using namespace std;

// 显示提示菜单界面
void ShowMenu()
{
	cout << "*************************" << endl;
	cout << "***** 1、添加联系人 *****" << endl;
	cout << "***** 2、显示联系人 *****" << endl;
	cout << "***** 3、删除联系人 *****" << endl;
	cout << "***** 4、查找联系人 *****" << endl;
	cout << "***** 5、编辑联系人 *****" << endl;
	cout << "***** 6、清空联系人 *****" << endl;
	cout << "***** 0、退出通讯录 *****" << endl;
	cout << "*************************" << endl;
}

// 联系人结构体
struct contect
{
	string name;	// 姓名
	int    sex;		// 性别，0女，1男
	int    age;		// 年龄
	string tele;	// 电话，电话长度11位会超过int范围
	string addr;	// 地址
};

// 通讯录结构体
struct address_list
{
	contect contect_list[MAX] = {};     // 通讯录数组(注意初始化变量，否则警告)
	
	int list_num = 0;				  // 当前通讯录人数
};

// 判断男女？？
string male_famale(int i)
{
	if (i == 0) return "女";
	if (i == 1) return "男";
	else return "不是男女";
}

// 添加联系人函数
void add_person(address_list *addr_lst)
{
	if (addr_lst->list_num == MAX)
	{
		cout << "通讯录人数已满，请适当删除联系人！" << endl;
		return;
	}
	else
	{
		int i = addr_lst->list_num;
		int sex_in;
		// 添加姓名
		cout << "请输入联系人姓名：" << endl;
		cin >> addr_lst->contect_list[i].name;
		// 添加性别
		cout << "请输入联系人性别，0(女)、1(男)：" << endl;
		while (true)					// 防止输入错误
		{
			cin >> sex_in;
			if ((sex_in == 0) || (sex_in == 1))
			{
				addr_lst->contect_list[i].sex = sex_in;
				break;
			}
			cout << "输入有误，请重新输入！" << endl;
		}
		// 添加年龄
		cout << "请输入联系人年龄：" << endl;
		cin >> addr_lst->contect_list[i].age;
		// 添加电话
		cout << "请输入联系人电话：" << endl;
		cin >> addr_lst->contect_list[i].tele;
		// 添加地址
		cout << "请输入联系人地址：" << endl;
		cin >> addr_lst->contect_list[i].addr;

		string sex = male_famale(addr_lst->contect_list[i].sex); // 获得性别
		// 添加完成显示
		cout << "联系人："<< addr_lst->contect_list[i].name << "、"<< sex
			<< "、"<< addr_lst->contect_list[i].age<<"岁、电话"<< addr_lst->contect_list[i].tele
			<< "、通讯地址:" << addr_lst->contect_list[i].addr << " 已添加！" << endl;
		addr_lst->list_num += 1;

		::system("pause");	// 请按任意键继续
		::system("cls");		// 清屏操作

	}
}

// 显示联系人函数
void show_person(address_list addr_lst)
{
	if (addr_lst.list_num == 0)
	{
		cout << "未找到联系人，请添加！" << endl;
	}
	for (int i = 0; i <= addr_lst.list_num-1; i++)
	{
		cout << "联系人" << i + 1 << "\t  姓名:" << addr_lst.contect_list[i].name << "、  "
			<< male_famale(addr_lst.contect_list[i].sex) << "、  电话"
			<< addr_lst.contect_list[i].tele << "、  通讯地址：" << addr_lst.contect_list[i].addr << endl;
	}
	system("pause");
	system("cls");
}

// 判断联系人是否存在
int isExist_person(address_list *addr_lst, string name)
{
	for (int i = 0; i < addr_lst->list_num; i++)       // 如果没进行添加，num为0，该循环
													  //  不执行，所以不能在这里进行返回值赋值
	{
		if (addr_lst->contect_list[i].name == name)
		{
			return i;
		}
	}
	return -1;
}

// 删除联系人函数
void delete_person(address_list *addr_lst)
{
	cout << "请输入需要删除的联系人姓名：" << endl;
	string name;
	cin >> name;
	int pos = isExist_person(addr_lst, name);
	if (pos == -1)
	{
		cout << "联系人不存在！" << endl;
	}
	else
	{
		string last_name = addr_lst->contect_list[pos].name;
		for (int i = pos; i < addr_lst->list_num; i++)
		{
			addr_lst->contect_list[i] = addr_lst->contect_list[i + 1];  // 覆盖联系人
		}
		addr_lst->list_num -= 1;
		cout << "联系人：" << last_name << "已删除！" << endl;
	}
	system("pause");
	system("cls");
}

// 查找联系人函数
void search_person(address_list* addr_lst)
{
	cout << "请输入需要查找的联系人姓名：" << endl;
	string name;
	cin >> name;
	int pos = isExist_person(addr_lst, name);

	if (pos == -1)
	{
		cout << "联系人不存在！" << endl;
	}
	else
	{
		cout << "联系人：" << addr_lst->contect_list[pos].name << "  " << male_famale(addr_lst->contect_list[pos].sex)
			<< "、  " << addr_lst->contect_list[pos].age << "岁、  电话：" << addr_lst->contect_list[pos].tele
			<< "、  通讯地址：" << addr_lst->contect_list[pos].addr << endl;
	}
	system("pause");
	system("cls");
}

// 编辑联系人函数
void edit_person(address_list *addr_lst)
{
	cout << "请输入需要编辑的联系人姓名：" << endl;
	string name;
	cin >> name;
	int pos = isExist_person(addr_lst, name);

	if (pos == -1)
	{
		cout << "联系人不存在！" << endl;
	}
	else
	{
		cout << "联系人：" << addr_lst->contect_list[pos].name << "、  " << male_famale(addr_lst->contect_list[pos].sex)
			<< "、  " << addr_lst->contect_list[pos].age << "岁、  电话：" << addr_lst->contect_list[pos].tele
			<< "、  通讯地址：" << addr_lst->contect_list[pos].addr << endl;

		cout << "请重新输入姓名：";
		cin >> name;
		addr_lst->contect_list[pos].name = name;

		int sex = 2;
		while (true)
		{
			cout << "请重新输入性别(0---女， 1---男)：";
			cin >> sex;
			if ((sex == 0) || (sex == 1))
			{	
				addr_lst->contect_list[pos].sex = sex;
				break;
			}	
		}
		
		cout << "请重新输入年龄：";
		cin >> sex;
		addr_lst->contect_list[pos].age = sex;

		cout << "请重新输入电话：";
		cin >> name;
		addr_lst->contect_list[pos].tele = name;

		cout << "请重新输入通讯地址：";
		cin >> name;
		addr_lst->contect_list[pos].addr = name;

		cout << "信息已更改！" << endl;

	}
	system("pause");
	system("cls");
}

// 清空联系人
void clear_all_person(address_list* addr_lst)
{
	addr_lst->list_num = 0;                  // 逻辑清零，当前只有零个人
	cout << "联系人已清空！" << endl;
	system("pause");
	system("cls");
}

int main()
{
	address_list addr_lst;
	addr_lst.list_num = 0;    // 初始人数为零

	while (true)
	{
		ShowMenu();

		int key_value = 0;   // 初始键值赋值为0

		cin >> key_value;    // 从键盘获取键值

		switch (key_value)
		{
		case 1:				// 添加联系人
			// 需要实参的改变
			add_person(&addr_lst);	
			break;
		case 2:				// 显示联系人
			show_person(addr_lst);
			break;
		case 3:             // 删除联系人

			delete_person(&addr_lst);
			break;
		case 4:				// 查找联系人
			search_person(&addr_lst);
			break; 
		case 5:				// 编辑联系人
			edit_person(&addr_lst);
			break;
		case 6:
			clear_all_person(&addr_lst);
			break;
		case 0:
			cout << "系统退出！" << endl;
			system("pause");
			return 0;
			break;
		}

	}
	system("pause");
	return 0;
}