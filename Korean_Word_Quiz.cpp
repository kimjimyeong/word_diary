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

            if (review_korean_quiz.size() < 1)
            {
                review_temp.push_back(text[i][0]);
                review_temp.push_back(text[i][1]);
                review_korean_quiz.push_back(review_temp);
                review_temp.pop_back();
                review_temp.pop_back();
            }
            else
            {
                int count = 0;                        // 중복 check count
                for (int j = 0; j < static_cast<int>(review_korean_quiz.size()); j++)
                {
                    if (text[i][0] != review_korean_quiz[j][0]) count++;
                }
                if (count == review_korean_quiz.size())
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


