// ������ �Լ� Ż�� �� ���� �߻��Ͽ� ���� ���¹δ��� �ڵ� �����Ͽ���(�������� ���¹� �������丮)
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