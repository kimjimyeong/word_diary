// primay_main(조원 강승민 작) 과 수정 전 2개의 퀴즈(조원 임연후 작)을 바탕으로 second_main 구성

#include <iostream>
#include <string>
#include <vector>
#include <clocale>  // wstring,wcin,wcout 사용
#include <ctime>
#include <random>

using namespace std;

class Word_Test_Diary
{
private:
    vector< vector<wstring>>text; // 2차원 백터를 선언하지만 한글은 string 으로 할시 오류가 발생해서 wstring 으로 선언
    vector< vector<wstring>>review_korean_quiz; // 오답내용 저장
    vector< vector<wstring>>review_english_quiz; // 오답내용 저장
    vector<wstring> temp;         // Eng_Word,Kor_Word 저장
    vector<wstring> review_temp;  // 틀린 Eng_Word,Kor_Word 저장
    int Example_Index = 0;
    int Review_Example_Index = 0;
public:

    void Input_Word()
    {
        wstring Eng_Word;
        wstring Kor_Word;

        while (true)
        {
            cout << "<<<<<<< 저장할 단어를 입력해주세요 (입력을 그만하고 싶으면 q를 입력해주세요.) >>>>>>>" << endl;
            wcin >> Eng_Word;
            cout << "\n";

            if (Eng_Word == L"q") {
                break;
            }

            cout << "<<<<<<< 단어의 뜻을 입력해주세요 >>>>>>>" << endl;
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
        wstring Eng_Temp_Word;       // 단어 제거 시 사용

        while (true)
        {
            cout << "<<<<<<< 제거 하고 싶은 단어를 입력해주세요(입력을 그만하고 싶으면 q를 입력해주세요.) >>>>>>>" << endl;
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
                    wcout << L"영단어 : " << text[j][0] << L" 한글뜻 : " << text[j][1] << L" 이 지워졌습니다." << endl;
                    text.erase(text.begin() + j);
                }


            }

        }
    }

    void Shuffle_Word()
    {
        wstring temp1;              // 단어  임시 저장공간
        wstring temp2;              // 단어의 뜻 임시 저장공간
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
            wcout << i + 1 << L"번째 영단어 : " << text[i][0] << L" 한글뜻 : " << text[i][1] << endl;
        }
        cout << "\n";
    }

    void English_Word_Quiz()
    {
        int Input_Number;     // 풀고자 하는 문제 갯수
        cout << "풀고자 하는 문제 갯수를 입력해 주시오. ( 1 ~ " << text.size() << " )" << endl;
        cin >> Input_Number;

        wstring answer;
        for (int i = 0; i < Input_Number; i++)
        {
            wcout << L"문제" << i + 1 << ": " << text[i][1] << endl; //한글 단어 출력
            wcin >> answer;
            if (answer == text[i][0])
            {
                cout << "Correct ! " << endl;
                for (int j = 0; j < static_cast<int>(review_english_quiz.size()); j++)
                {
                    if (answer == review_english_quiz[j][0]) review_english_quiz.erase(review_english_quiz.begin() + j);  //맞추면 오답노트에서 제거
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
            cout << "문제를 만들 만큼 단어를 저장하지 않았습니다." << endl;
            return;
        }
        int Input_Number;
        cout << "풀고자 하는 문제 갯수를 입력해 주시오. ( 1 ~ " << text.size() << " )" << endl;
        cin >> Input_Number;

        for (int i = 0; i < Input_Number; i++)
        {
            int Input_Answer; //사용자 입력 정답
            int Correct_Answer;    // 정답 보기

            minstd_rand rand_kor(time(NULL));

            wcout << L"문제" << i + 1 << L": " << text[i][0] << endl; //영어단어 출력

            Correct_Answer = rand_kor() % 3 + 1;  // 랜덤 보기 번호 매기기
            for (int j = 1; j < 4; j++)
            {

                if (j == Correct_Answer)                              // 정답 보기 생성
                {
                    wcout << j << L": " << text[i][1] << endl; //옳은 한글 뜻 가져옴
                }
                else                                           // 오답 보기 생성
                {
                    int Kor;
                    do {
                        Kor = rand_kor();
                    } while (Kor % text.size() == i || Kor % text.size() == Example_Index);                     // 정답이 보기에 2개 있는 것을 방지
                    Example_Index = Kor % text.size();

                    wcout << j << L": " << text[Example_Index][1] << endl;

                }


            }
            cin >> Input_Answer;
            if (Input_Answer == Correct_Answer)
            {
                cout << "정답 !" << endl;
                for (int j = 0; j < static_cast<int>(review_korean_quiz.size()); j++)
                {
                    if (text[i][0] == review_korean_quiz[j][0]) review_korean_quiz.erase(review_korean_quiz.begin() + j);  //맞추면 오답노트에서 제거
                }
            }
            else
            {
                wcout << L"오답 " << "\n" << L"정답은 " << text[i][1] << endl;

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
            cout << "틀린 문제가 없습니다." << endl;
            return;
        }
        wstring answer;
        for (int i = 0; i < static_cast<int>(review_english_quiz.size()); )
        {
            wcout << L"문제" << i + 1 << ": " << review_english_quiz[i][1] << endl; //한글 단어 출력
            wcin >> answer;
            if (answer == review_english_quiz[i][0])
            {
                cout << "Correct ! " << endl;
                review_english_quiz.erase(review_english_quiz.begin() + i);  //맞추면 오답노트에서 제거
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
            cout << "틀린 문제가 없습니다." << endl;
            return;
        }
        for (int i = 0; i < static_cast<int>(review_korean_quiz.size());)
        {
            int Input_Answer; //사용자 입력 정답
            int Correct_Answer;    // 정답 보기

            minstd_rand rand_kor(time(NULL));

            wcout << L"문제" << i + 1 << L": " << review_korean_quiz[i][0] << endl; //영어단어 출력

            Correct_Answer = rand_kor() % 3 + 1;  // 랜덤 보기 번호 매기기
            for (int j = 1; j < 4; j++)
            {

                if (j == Correct_Answer)                              // 정답 보기 생성
                {
                    wcout << j << L": " << review_korean_quiz[i][1] << endl; //옳은 한글 뜻 가져옴
                }
                else                                           // 오답 보기 생성
                {
                    int Kor;
                    do {
                        Kor = rand_kor();
                    } while (text[Kor % text.size()][1] == review_korean_quiz[i][1] || Kor % text.size() == Review_Example_Index); // 정답 2개,복수 보기제거
                    Review_Example_Index = Kor % text.size();

                    wcout << j << L": " << text[Review_Example_Index][1] << endl;

                }


            }
            cin >> Input_Answer;
            if (Input_Answer == Correct_Answer)
            {
                cout << "정답 !" << endl;
                review_korean_quiz.erase(review_korean_quiz.begin() + i);  //맞추면 오답노트에서 제거
            }
            else
            {
                wcout << L"오답 " << "\n" << L"정답은 " << review_korean_quiz[i][1] << endl;
                i++;
            }
        }


    }
    void Review_note()
    {
        cout << "영단어 퀴즈에서 틀린 문제들 입니다." << endl;
        for (int i = 0; i < static_cast<int>(review_english_quiz.size()) - 1; i++)
        {
            wcout << i + 1 << L"번째 영단어 : " << L" 한글 뜻 : " << review_english_quiz[i][1] << endl;
        }
        cout << "----------------------------------------------------------------------\n" << endl;
        cout << "영단어 뜻 퀴즈에서 틀린 문제들 입니다" << endl;
        for (int i = 0; i < static_cast<int>(review_korean_quiz.size()) - 1; i++)
        {
            wcout << i + 1 << L"번째 영단어 : " << review_korean_quiz[i][0] << L" 한글 뜻 : " << endl;
        }

    }

};

int main()
{

    _wsetlocale(LC_ALL, L"korean");//한글때문에 출력이안되는경우가있어 선언
    setlocale(LC_ALL, "korean");  //한글때문에 출력이안되는경우가있어 선언

    Word_Test_Diary test;   // 단어장
    int select;

    do {
        cout << "1. 단어 입력" << endl << "2. 단어 삭제" << endl << "3. 단어 섞기" << endl << "4. 단어 출력" << endl << "5.영단어 퀴즈" << endl
            << "6.영단어 뜻 퀴즈" << endl << "7.영단어 오답 퀴즈" << endl << "8.영단어 뜻 오답 퀴즈" << endl << "9.오답노트" << endl << "100. 프로그램 종료\n" << endl;
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

    cout << "\n<<<<<<< 프로그램을 종료합니다 >>>>>>>>" << endl;

    return 0;
}