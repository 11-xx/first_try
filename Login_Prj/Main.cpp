# include <iostream>
# include <string>

# define MAX 100		// ͨѶ¼���100λ��ϵ��
int flag = 0;			  // �趨�ظ�������־

using namespace std;

// ��ʾ��ʾ�˵�����
void ShowMenu()
{
	cout << "*************************" << endl;
	cout << "***** 1�������ϵ�� *****" << endl;
	cout << "***** 2����ʾ��ϵ�� *****" << endl;
	cout << "***** 3��ɾ����ϵ�� *****" << endl;
	cout << "***** 4��������ϵ�� *****" << endl;
	cout << "***** 5���༭��ϵ�� *****" << endl;
	cout << "***** 6�������ϵ�� *****" << endl;
	cout << "***** 0���˳�ͨѶ¼ *****" << endl;
	cout << "*************************" << endl;
}

// ��ϵ�˽ṹ��
struct contect
{
	string name;	// ����
	int    sex;		// �Ա�0Ů��1��
	int    age;		// ����
	string tele;	// �绰���绰����11λ�ᳬ��int��Χ
	string addr;	// ��ַ
};

// ͨѶ¼�ṹ��
struct address_list
{
	contect contect_list[MAX] = {};     // ͨѶ¼����(ע���ʼ�����������򾯸�)
	
	int list_num = 0;				  // ��ǰͨѶ¼����
};

// �ж���Ů����
string male_famale(int i)
{
	if (i == 0) return "Ů";
	if (i == 1) return "��";
	else return "������Ů";
}

// �����ϵ�˺���
void add_person(address_list *addr_lst)
{
	if (addr_lst->list_num == MAX)
	{
		cout << "ͨѶ¼�������������ʵ�ɾ����ϵ�ˣ�" << endl;
		return;
	}
	else
	{
		int i = addr_lst->list_num;
		int sex_in;
		// �������
		cout << "��������ϵ��������" << endl;
		cin >> addr_lst->contect_list[i].name;
		// ����Ա�
		cout << "��������ϵ���Ա�0(Ů)��1(��)��" << endl;
		while (true)					// ��ֹ�������
		{
			cin >> sex_in;
			if ((sex_in == 0) || (sex_in == 1))
			{
				addr_lst->contect_list[i].sex = sex_in;
				break;
			}
			cout << "�����������������룡" << endl;
		}
		// �������
		cout << "��������ϵ�����䣺" << endl;
		cin >> addr_lst->contect_list[i].age;
		// ��ӵ绰
		cout << "��������ϵ�˵绰��" << endl;
		cin >> addr_lst->contect_list[i].tele;
		// ��ӵ�ַ
		cout << "��������ϵ�˵�ַ��" << endl;
		cin >> addr_lst->contect_list[i].addr;

		string sex = male_famale(addr_lst->contect_list[i].sex); // ����Ա�
		// ��������ʾ
		cout << "��ϵ�ˣ�"<< addr_lst->contect_list[i].name << "��"<< sex
			<< "��"<< addr_lst->contect_list[i].age<<"�ꡢ�绰"<< addr_lst->contect_list[i].tele
			<< "��ͨѶ��ַ:" << addr_lst->contect_list[i].addr << " ����ӣ�" << endl;
		addr_lst->list_num += 1;

		::system("pause");	// �밴���������
		::system("cls");		// ��������

	}
}

// ��ʾ��ϵ�˺���
void show_person(address_list addr_lst)
{
	if (addr_lst.list_num == 0)
	{
		cout << "δ�ҵ���ϵ�ˣ�����ӣ�" << endl;
	}
	for (int i = 0; i <= addr_lst.list_num-1; i++)
	{
		cout << "��ϵ��" << i + 1 << "\t  ����:" << addr_lst.contect_list[i].name << "��  "
			<< male_famale(addr_lst.contect_list[i].sex) << "��  �绰"
			<< addr_lst.contect_list[i].tele << "��  ͨѶ��ַ��" << addr_lst.contect_list[i].addr << endl;
	}
	system("pause");
	system("cls");
}

// �ж���ϵ���Ƿ����
int isExist_person(address_list *addr_lst, string name)
{
	for (int i = 0; i < addr_lst->list_num; i++)       // ���û������ӣ�numΪ0����ѭ��
													  //  ��ִ�У����Բ�����������з���ֵ��ֵ
	{
		if (addr_lst->contect_list[i].name == name)
		{
			return i;
		}
	}
	return -1;
}

// ɾ����ϵ�˺���
void delete_person(address_list *addr_lst)
{
	cout << "��������Ҫɾ������ϵ��������" << endl;
	string name;
	cin >> name;
	int pos = isExist_person(addr_lst, name);
	if (pos == -1)
	{
		cout << "��ϵ�˲����ڣ�" << endl;
	}
	else
	{
		string last_name = addr_lst->contect_list[pos].name;
		for (int i = pos; i < addr_lst->list_num; i++)
		{
			addr_lst->contect_list[i] = addr_lst->contect_list[i + 1];  // ������ϵ��
		}
		addr_lst->list_num -= 1;
		cout << "��ϵ�ˣ�" << last_name << "��ɾ����" << endl;
	}
	system("pause");
	system("cls");
}

// ������ϵ�˺���
void search_person(address_list* addr_lst)
{
	cout << "��������Ҫ���ҵ���ϵ��������" << endl;
	string name;
	cin >> name;
	int pos = isExist_person(addr_lst, name);

	if (pos == -1)
	{
		cout << "��ϵ�˲����ڣ�" << endl;
	}
	else
	{
		cout << "��ϵ�ˣ�" << addr_lst->contect_list[pos].name << "  " << male_famale(addr_lst->contect_list[pos].sex)
			<< "��  " << addr_lst->contect_list[pos].age << "�ꡢ  �绰��" << addr_lst->contect_list[pos].tele
			<< "��  ͨѶ��ַ��" << addr_lst->contect_list[pos].addr << endl;
	}
	system("pause");
	system("cls");
}

// �༭��ϵ�˺���
void edit_person(address_list *addr_lst)
{
	cout << "��������Ҫ�༭����ϵ��������" << endl;
	string name;
	cin >> name;
	int pos = isExist_person(addr_lst, name);

	if (pos == -1)
	{
		cout << "��ϵ�˲����ڣ�" << endl;
	}
	else
	{
		cout << "��ϵ�ˣ�" << addr_lst->contect_list[pos].name << "��  " << male_famale(addr_lst->contect_list[pos].sex)
			<< "��  " << addr_lst->contect_list[pos].age << "�ꡢ  �绰��" << addr_lst->contect_list[pos].tele
			<< "��  ͨѶ��ַ��" << addr_lst->contect_list[pos].addr << endl;

		cout << "����������������";
		cin >> name;
		addr_lst->contect_list[pos].name = name;

		int sex = 2;
		while (true)
		{
			cout << "�����������Ա�(0---Ů�� 1---��)��";
			cin >> sex;
			if ((sex == 0) || (sex == 1))
			{	
				addr_lst->contect_list[pos].sex = sex;
				break;
			}	
		}
		
		cout << "�������������䣺";
		cin >> sex;
		addr_lst->contect_list[pos].age = sex;

		cout << "����������绰��";
		cin >> name;
		addr_lst->contect_list[pos].tele = name;

		cout << "����������ͨѶ��ַ��";
		cin >> name;
		addr_lst->contect_list[pos].addr = name;

		cout << "��Ϣ�Ѹ��ģ�" << endl;

	}
	system("pause");
	system("cls");
}

// �����ϵ��
void clear_all_person(address_list* addr_lst)
{
	addr_lst->list_num = 0;                  // �߼����㣬��ǰֻ�������
	cout << "��ϵ������գ�" << endl;
	system("pause");
	system("cls");
}

int main()
{
	address_list addr_lst;
	addr_lst.list_num = 0;    // ��ʼ����Ϊ��

	while (true)
	{
		ShowMenu();

		int key_value = 0;   // ��ʼ��ֵ��ֵΪ0

		cin >> key_value;    // �Ӽ��̻�ȡ��ֵ

		switch (key_value)
		{
		case 1:				// �����ϵ��
			// ��Ҫʵ�εĸı�
			add_person(&addr_lst);	
			break;
		case 2:				// ��ʾ��ϵ��
			show_person(addr_lst);
			break;
		case 3:             // ɾ����ϵ��

			delete_person(&addr_lst);
			break;
		case 4:				// ������ϵ��
			search_person(&addr_lst);
			break; 
		case 5:				// �༭��ϵ��
			edit_person(&addr_lst);
			break;
		case 6:
			clear_all_person(&addr_lst);
			break;
		case 0:
			cout << "ϵͳ�˳���" << endl;
			system("pause");
			return 0;
			break;
		}

	}
	system("pause");
	return 0;
}