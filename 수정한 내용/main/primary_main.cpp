//코드 전체
#include<iostream>
#include <time.h>    //rand()함수를 사용하기위해 추가한다.
#include <string>
#include<vector>
#include <locale>
using namespace std;
void Shuffle(vector<vector<wstring> >& index);
void Word_Input(vector<vector<wstring> >& index);
void Word_Delet(vector<vector<wstring> >& index);
void Word_Print(vector<vector<wstring> >& index);


//한글사용시 오류때문에 전체적으로 wstring,wcin,wcout을 사용
int main(void) {
	vector<vector<wstring> > text;//2차원 백터를 선언하지만 한글은 string으로 할시 오류가 발생해서 wstring으로 선언
	_wsetlocale(LC_ALL, L"korean");//한글때문에 출력이안되는경우가있어 선언
	setlocale(LC_ALL, "korean");  //한글때문에 출력이안되는경우가있어 선언
	int select;
	while (true) {
		cout << "1. 단어 입력" << endl << "2. 단어 삭제" << endl << "3. 단어 섞기" << endl << "4. 단어 출력" << endl << "100. 프로그램 종료" << endl;
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
			cout << "프로그램이 종료됩니다." << endl;
			break;
		}
	}
	return 0;
}

//랜덤으로 벡터배열를 섞어주는 함수
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

//벡터배열에 "영어 한글"로 입력을 받는 함수
//그만 입력을 하고싶을시엔 q를 입력하면 됩니다.
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

//입력한 영단어를 벡터배열에서 삭제하는 함수
void Word_Delet(vector<vector<wstring> >& index) {
	wstring Eng_temp;
	while (true) {
		wcin >> Eng_temp;
		if (Eng_temp == L"q") {
			break;
		}
		for (int j = 0; j < index.size(); j++) {
			if (index[j][0] == Eng_temp) {
				wcout << L"영단어 : " << index[j][0] << L" 한글뜻 : " << index[j][1] << " 이 지워졌습니다." << endl;
				index.erase(index.begin() + j);
			}
		}
	}
}

//전체 벡터배열을 출력해주는 함수
void Word_Print(vector<vector<wstring> >& index) {
	for (int i = 0; i < index.size(); i++) {
		wcout << i + 1 << L"번째 영단어 : " << index[i][0] << L" 한글뜻 : " << index[i][1] << endl;
	}
}