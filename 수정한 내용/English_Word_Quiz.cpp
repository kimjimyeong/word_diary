// ���� �ӿ����� �ڵ带 ����
void English_Word_Quiz()
{
    int Input_Number;     // Ǯ���� �ϴ� ���� ����
    cout << "Ǯ���� �ϴ� ���� ������ �Է��� �ֽÿ�. ( 1 ~ " << text.size() << " )" << endl;
    cin >> Input_Number;

    wstring answer;
    for (int i = 0; i < Input_Number; i++)
    {
        wcout << L"����" << i + 1 << ": " << text[i][1] << endl; //�ѱ� �ܾ� ���
        wcin >> answer;
        if (answer == text[i][0])
        {
            cout << "Correct ! " << endl;
            for (int j = 0; j < static_cast<int>(review_english_quiz.size()); j++)
            {
                if (answer == review_english_quiz[j][0]) review_english_quiz.erase(review_english_quiz.begin() + j);  //���߸� �����Ʈ���� ����
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