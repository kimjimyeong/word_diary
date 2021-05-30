//�ڵ� ��ü
#include<iostream>
#include <time.h>    //rand()�Լ��� ����ϱ����� �߰��Ѵ�.
#include <string>
#include<vector>
#include <locale>
using namespace std;
void Shuffle(vector<vector<wstring> >& index);
void Word_Input(vector<vector<wstring> >& index);
void Word_Delet(vector<vector<wstring> >& index);
void Word_Print(vector<vector<wstring> >& index);


//�ѱۻ��� ���������� ��ü������ wstring,wcin,wcout�� ���
int main(void) {
	vector<vector<wstring> > text;//2���� ���͸� ���������� �ѱ��� string���� �ҽ� ������ �߻��ؼ� wstring���� ����
	_wsetlocale(LC_ALL, L"korean");//�ѱ۶����� ����̾ȵǴ°�찡�־� ����
	setlocale(LC_ALL, "korean");  //�ѱ۶����� ����̾ȵǴ°�찡�־� ����
	int select;
	while (true) {
		cout << "1. �ܾ� �Է�" << endl << "2. �ܾ� ����" << endl << "3. �ܾ� ����" << endl << "4. �ܾ� ���" << endl << "100. ���α׷� ����" << endl;
		cin >> select;
		if (select == 0) {}
		if (select == 1) {
			Word_Input(text);
			select = 0;
		}
		else if (select == 2) {
			Word_Delet(text);
			select = 0;
		}
		else if (select == 3) {
			Shuffle(text);
			select = 0;
		}
		else if (select == 4) {
			Word_Print(text);
			select = 0;
		}
		else {
			cout << "���α׷��� ����˴ϴ�." << endl;
			break;
		}
	}
	return 0;
}

//�������� ���͹迭�� �����ִ� �Լ�
void Shuffle(vector<vector<wstring> >& index) {
	int i, n;
	wstring temp1;
	wstring temp2;
	srand(time(NULL));
	for (i = index.size() - 1; i >= 0; i--) {
		n = rand() % index.size();
		temp1 = index[i][0];
		index[i][0] = index[n][0];
		index[n][0] = temp1;
		temp2 = index[i][1];
		index[i][1] = index[n][1];
		index[n][1] = temp2;
	}
}

//���͹迭�� "���� �ѱ�"�� �Է��� �޴� �Լ�
//�׸� �Է��� �ϰ�����ÿ� q�� �Է��ϸ� �˴ϴ�.
void Word_Input(vector<vector<wstring> >& index) {
	wstring Eng_temp, Kor_temp;
	vector<wstring> temp;
	int i = 0;
	while (true) {
		wcin >> Eng_temp;
		if (Eng_temp == L"q") {
			break;
		}
		wcin >> Kor_temp;
		if (Eng_temp == L"q" || Kor_temp == L"q") {
			break;
		}
		temp.push_back(Eng_temp);
		temp.push_back(Kor_temp);
		index.push_back(temp);
		temp.pop_back();
		temp.pop_back();
		i++;
	}
}

//�Է��� ���ܾ ���͹迭���� �����ϴ� �Լ�
void Word_Delet(vector<vector<wstring> >& index) {
	wstring Eng_temp;
	while (true) {
		wcin >> Eng_temp;
		if (Eng_temp == L"q") {
			break;
		}
		for (int j = 0; j < index.size(); j++) {
			if (index[j][0] == Eng_temp) {
				wcout << L"���ܾ� : " << index[j][0] << L" �ѱ۶� : " << index[j][1] << " �� ���������ϴ�." << endl;
				index.erase(index.begin() + j);
			}
		}
	}
}

//��ü ���͹迭�� ������ִ� �Լ�
void Word_Print(vector<vector<wstring> >& index) {
	for (int i = 0; i < index.size(); i++) {
		wcout << i + 1 << L"��° ���ܾ� : " << index[i][0] << L" �ѱ۶� : " << index[i][1] << endl;
	}
}