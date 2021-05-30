// primay_main(���� ���¹� ��) �� ���� �� 2���� ����(���� �ӿ��� ��)�� �������� second_main ����

#include <iostream>
#include <string>
#include <vector>
#include <clocale>  // wstring,wcin,wcout ���
#include <ctime>
#include <random>

using namespace std;

class Word_Test_Diary
{
private:
    vector< vector<wstring>>text; // 2���� ���͸� ���������� �ѱ��� string ���� �ҽ� ������ �߻��ؼ� wstring ���� ����
    vector< vector<wstring>>review_korean_quiz; // ���䳻�� ����
    vector< vector<wstring>>review_english_quiz; // ���䳻�� ����
    vector<wstring> temp;         // Eng_Word,Kor_Word ����
    vector<wstring> review_temp;  // Ʋ�� Eng_Word,Kor_Word ����
    int Example_Index = 0;
    int Review_Example_Index = 0;
public:

    void Input_Word()
    {
        wstring Eng_Word;
        wstring Kor_Word;

        while (true)
        {
            cout << "<<<<<<< ������ �ܾ �Է����ּ��� (�Է��� �׸��ϰ� ������ q�� �Է����ּ���.) >>>>>>>" << endl;
            wcin >> Eng_Word;
            cout << "\n";

            if (Eng_Word == L"q") {
                break;
            }

            cout << "<<<<<<< �ܾ��� ���� �Է����ּ��� >>>>>>>" << endl;
            wcin >> Kor_Word;
            cout << "\n";

            if (Eng_Word == L"q" || Kor_Word == L"q") {
                break;
            }
            temp.push_back(Eng_Word);
            temp.push_back(Kor_Word);
            text.push_back(temp);
            temp.pop_back();
            temp.pop_back();
        }
    }

    void Delete_Word()
    {
        wstring Eng_Temp_Word;       // �ܾ� ���� �� ���

        while (true)
        {
            cout << "<<<<<<< ���� �ϰ� ���� �ܾ �Է����ּ���(�Է��� �׸��ϰ� ������ q�� �Է����ּ���.) >>>>>>>" << endl;
            wcin >> Eng_Temp_Word;
            cout << "\n";

            if (Eng_Temp_Word == L"q")
            {
                break;
            }
            for (int j = 0; j < static_cast<int>(text.size()); j++)
            {
                if (text[j][0] == Eng_Temp_Word)
                {
                    wcout << L"���ܾ� : " << text[j][0] << L" �ѱ۶� : " << text[j][1] << L" �� ���������ϴ�." << endl;
                    text.erase(text.begin() + j);
                }


            }

        }
    }

    void Shuffle_Word()
    {
        wstring temp1;              // �ܾ�  �ӽ� �������
        wstring temp2;              // �ܾ��� �� �ӽ� �������
        minstd_rand rand_shuffle(time(nullptr));
        int n;
        for (int i = static_cast<int>(text.size()) - 1; i >= 0; i--)
        {
            n = rand_shuffle() % text.size();
            temp1 = text[i][0];
            text[i][0] = text[n][0];
            text[n][0] = temp1;
            temp2 = text[i][1];
            text[i][1] = text[n][1];
            text[n][1] = temp2;
        }


    }

    void Print_Word()
    {
        for (int i = 0; i < static_cast<int>(text.size()); i++)
        {
            wcout << i + 1 << L"��° ���ܾ� : " << text[i][0] << L" �ѱ۶� : " << text[i][1] << endl;
        }
        cout << "\n";
    }

    void English_Word_Quiz()
    {
        int Input_Number;     // Ǯ���� �ϴ� ���� ����
        cout << "Ǯ���� �ϴ� ���� ������ �Է��� �ֽÿ�. ( 1 ~ " << text.size() << " )" << endl;
        cin >> Input_Number;

        wstring answer;
        for (int i = 0; i < Input_Number; i++)
        {
            wcout << L"����" << i + 1 << ": " << text[i][1] << endl; //�ѱ� �ܾ� ���
            wcin >> answer;
            if (answer == text[i][0])
            {
                cout << "Correct ! " << endl;
                for (int j = 0; j < static_cast<int>(review_english_quiz.size()); j++)
                {
                    if (answer == review_english_quiz[j][0]) review_english_quiz.erase(review_english_quiz.begin() + j);  //���߸� �����Ʈ���� ����
                }
            }
            else
            {
                cout << "Wrong !" << endl;
                wcout << L"Answer is: " << text[i][0] << endl;

                if (review_english_quiz.size() == 0)
                {
                    review_temp.push_back(text[i][0]);
                    review_temp.push_back(text[i][1]);
                    review_english_quiz.push_back(review_temp);
                    review_temp.pop_back();
                    review_temp.pop_back();
                }
                else
                {
                    for (int j = 0; j < static_cast<int>(review_english_quiz.size()); j++)
                    {
                        if (text[i][0] != review_english_quiz[j][0])
                        {
                            review_temp.push_back(text[i][0]);
                            review_temp.push_back(text[i][1]);
                            review_english_quiz.push_back(review_temp);
                            review_temp.pop_back();
                            review_temp.pop_back();
                        }
                    }
                }


            }
        }

    }

    void Korean_Word_Quiz()
    {
        if (text.size() < 3)
        {
            cout << "������ ���� ��ŭ �ܾ �������� �ʾҽ��ϴ�." << endl;
            return;
        }
        int Input_Number;
        cout << "Ǯ���� �ϴ� ���� ������ �Է��� �ֽÿ�. ( 1 ~ " << text.size() << " )" << endl;
        cin >> Input_Number;

        for (int i = 0; i < Input_Number; i++)
        {
            int Input_Answer; //����� �Է� ����
            int Correct_Answer;    // ���� ����

            minstd_rand rand_kor(time(NULL));

            wcout << L"����" << i + 1 << L": " << text[i][0] << endl; //����ܾ� ���

            Correct_Answer = rand_kor() % 3 + 1;  // ���� ���� ��ȣ �ű��
            for (int j = 1; j < 4; j++)
            {

                if (j == Correct_Answer)                              // ���� ���� ����
                {
                    wcout << j << L": " << text[i][1] << endl; //���� �ѱ� �� ������
                }
                else                                           // ���� ���� ����
                {
                    int Kor;
                    do {
                        Kor = rand_kor();
                    } while (Kor % text.size() == i || Kor % text.size() == Example_Index);                     // ������ ���⿡ 2�� �ִ� ���� ����
                    Example_Index = Kor % text.size();

                    wcout << j << L": " << text[Example_Index][1] << endl;

                }


            }
            cin >> Input_Answer;
            if (Input_Answer == Correct_Answer)
            {
                cout << "���� !" << endl;
                for (int j = 0; j < static_cast<int>(review_korean_quiz.size()); j++)
                {
                    if (text[i][0] == review_korean_quiz[j][0]) review_korean_quiz.erase(review_korean_quiz.begin() + j);  //���߸� �����Ʈ���� ����
                }
            }
            else
            {
                wcout << L"���� " << "\n" << L"������ " << text[i][1] << endl;

                if (review_korean_quiz.size() == 0)
                {
                    review_temp.push_back(text[i][0]);
                    review_temp.push_back(text[i][1]);
                    review_korean_quiz.push_back(review_temp);
                    review_temp.pop_back();
                    review_temp.pop_back();
                }
                else
                {
                    for (int j = 0; j < static_cast<int>(review_korean_quiz.size()); j++)
                    {
                        if (text[i][0] != review_english_quiz[j][0])
                        {
                            review_temp.push_back(text[i][0]);
                            review_temp.push_back(text[i][1]);
                            review_korean_quiz.push_back(review_temp);
                            review_temp.pop_back();
                            review_temp.pop_back();
                        }
                    }
                }
            }
        }


    }
    void Review_Eng_Quiz()
    {
        if (review_english_quiz.size() == 0)
        {
            cout << "Ʋ�� ������ �����ϴ�." << endl;
            return;
        }
        wstring answer;
        for (int i = 0; i < static_cast<int>(review_english_quiz.size()); )
        {
            wcout << L"����" << i + 1 << ": " << review_english_quiz[i][1] << endl; //�ѱ� �ܾ� ���
            wcin >> answer;
            if (answer == review_english_quiz[i][0])
            {
                cout << "Correct ! " << endl;
                review_english_quiz.erase(review_english_quiz.begin() + i);  //���߸� �����Ʈ���� ����
            }
            else
            {
                cout << "Wrong !" << endl;
                wcout << L"Answer is: " << review_english_quiz[i][0] << endl;
                i++;
            }
        }
    }

    void Review_Kor_Quiz()
    {
        if (review_korean_quiz.size() == 0)
        {
            cout << "Ʋ�� ������ �����ϴ�." << endl;
            return;
        }
        for (int i = 0; i < static_cast<int>(review_korean_quiz.size());)
        {
            int Input_Answer; //����� �Է� ����
            int Correct_Answer;    // ���� ����

            minstd_rand rand_kor(time(NULL));

            wcout << L"����" << i + 1 << L": " << review_korean_quiz[i][0] << endl; //����ܾ� ���

            Correct_Answer = rand_kor() % 3 + 1;  // ���� ���� ��ȣ �ű��
            for (int j = 1; j < 4; j++)
            {

                if (j == Correct_Answer)                              // ���� ���� ����
                {
                    wcout << j << L": " << review_korean_quiz[i][1] << endl; //���� �ѱ� �� ������
                }
                else                                           // ���� ���� ����
                {
                    int Kor;
                    do {
                        Kor = rand_kor();
                    } while (text[Kor % text.size()][1] == review_korean_quiz[i][1] || Kor % text.size() == Review_Example_Index); // ���� 2��,���� ��������
                    Review_Example_Index = Kor % text.size();

                    wcout << j << L": " << text[Review_Example_Index][1] << endl;

                }


            }
            cin >> Input_Answer;
            if (Input_Answer == Correct_Answer)
            {
                cout << "���� !" << endl;
                review_korean_quiz.erase(review_korean_quiz.begin() + i);  //���߸� �����Ʈ���� ����
            }
            else
            {
                wcout << L"���� " << "\n" << L"������ " << review_korean_quiz[i][1] << endl;
                i++;
            }
        }


    }
    void Review_note()
    {
        cout << "���ܾ� ����� Ʋ�� ������ �Դϴ�." << endl;
        for (int i = 0; i < static_cast<int>(review_english_quiz.size()) - 1; i++)
        {
            wcout << i + 1 << L"��° ���ܾ� : " << L" �ѱ� �� : " << review_english_quiz[i][1] << endl;
        }
        cout << "----------------------------------------------------------------------\n" << endl;
        cout << "���ܾ� �� ����� Ʋ�� ������ �Դϴ�" << endl;
        for (int i = 0; i < static_cast<int>(review_korean_quiz.size()) - 1; i++)
        {
            wcout << i + 1 << L"��° ���ܾ� : " << review_korean_quiz[i][0] << L" �ѱ� �� : " << endl;
        }

    }

};

int main()
{

    _wsetlocale(LC_ALL, L"korean");//�ѱ۶����� ����̾ȵǴ°�찡�־� ����
    setlocale(LC_ALL, "korean");  //�ѱ۶����� ����̾ȵǴ°�찡�־� ����

    Word_Test_Diary test;   // �ܾ���
    int select;

    do {
        cout << "1. �ܾ� �Է�" << endl << "2. �ܾ� ����" << endl << "3. �ܾ� ����" << endl << "4. �ܾ� ���" << endl << "5.���ܾ� ����" << endl
            << "6.���ܾ� �� ����" << endl << "7.���ܾ� ���� ����" << endl << "8.���ܾ� �� ���� ����" << endl << "9.�����Ʈ" << endl << "100. ���α׷� ����\n" << endl;
        cin >> select;
        switch (select)
        {
        case 1:
        {
            test.Input_Word();
            break;
        }
        case 2:
        {
            test.Delete_Word();
            break;
        }
        case 3:
        {
            test.Shuffle_Word();
            break;
        }
        case 4:
        {
            test.Print_Word();
            break;
        }
        case 5:
        {
            test.English_Word_Quiz();
            break;
        }
        case 6:
        {
            test.Korean_Word_Quiz();
            break;
        }
        case 7:
        {
            test.Review_Eng_Quiz();
            break;
        }
        case 8:
        {
            test.Review_Kor_Quiz();
            break;
        }
        case 9:
        {
            test.Review_note();
            break;
        }
        default:
            break;
        }

    } while (select != 100);

    cout << "\n<<<<<<< ���α׷��� �����մϴ� >>>>>>>>" << endl;

    return 0;
}