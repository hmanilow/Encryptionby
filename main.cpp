#include <iostream>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian"); //локаль на русский язык

    int iter = 0;
    string ai = ""; //номер строки
    string aj = ""; //номер столба
    string cryptage = ""; //шифр
    string cryptocode = ""; //расшифр
    string decrypted_text = "";
    
    string polybius_square[6][6]; //квадрат Полибия
    string alph = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя123";

    string key = "Друзья Вздыхать и думать про себя: Когда же черт возьмет тебя!";
    string cryptageText = "Как в просвещенной Европе, так и в просвещенной России есть теперь весьма много почтенных людей, которые без того не могут покушать в трактире, чтоб не поговорить с слугою, а иногда даже забавно пошутить над ним. Впрочем, приезжий делал не всё пустые вопросы; он с чрезвычайною точностию расспросил, кто в городе губернатор, кто председатель палаты, кто прокурор.";

    string textupd = ""; //символы из алфы и цифры

    for (char a : cryptageText)
    {
        if (alph.find(tolower(a)) != string::npos)
        {
            textupd += tolower(a);
        }
    }
    
    string key_key = "";
    for (char a : key)
    {
        if (key_key.find(tolower(a)) == string::npos && alph.find(tolower(a)) != string::npos)
        {
            key_key += tolower(a);
        }
    }
    
    for (char a : alph)
    {
        if (key_key.find(a) == string::npos)
        {
            key_key += a;
        }
    }
    
    for (int i = 0; i < 6; i++) //// заполнил квадратус Полибия символами из ключа
    {
        for (int j = 0; j < 6; j++)
        {
            polybius_square[i][j] = key_key[iter];
            iter++;
        }
    }
    
    cout << "Зашифровка: " << cryptage << endl;
    
    for (char a : cryptage)
    {
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                if (polybius_square[i][j].find(a) != string::npos) // если символ есть в квадрате Полибия
                {
                    cryptocode += to_string(i) + to_string(j); // + номер строки и столбца в код
                }
            }
        }
    }
    
    for (int i = 0; i < cryptocode.length() / 2; i++)
    {
        decrypted_text += polybius_square[cryptocode[i] - '0'][cryptocode[i + cryptocode.length() / 2] - '0'];
    }
    cout << "\nРасшифровка: " << decrypted_text << endl;
    return 0;
}
