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