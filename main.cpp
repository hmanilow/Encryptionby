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
}
