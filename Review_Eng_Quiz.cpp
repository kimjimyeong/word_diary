
// ������ �Լ� Ż�� �� ���� �߻��Ͽ� ���� ���¹δ��� �ڵ� �����Ͽ���(�������� ���¹� �������丮)
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