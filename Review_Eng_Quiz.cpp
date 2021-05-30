
// 마지막 함수 탈출 시 에러 발생하여 조원 강승민님이 코드 수정하였음(수정본은 강승민 리포지토리)
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