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
                int count = 0;                        // �ߺ� check count
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


