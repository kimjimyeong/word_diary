// 조원 임연후의 코드를 수정
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