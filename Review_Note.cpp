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