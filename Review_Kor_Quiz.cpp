// 마지막 함수 탈출 시 에러 발생하여 조원 강승민님이 코드 수정하였음(수정본은 강승민 리포지토리)
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