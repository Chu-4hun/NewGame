#include <iostream>
#include <ctime>
#include <string>
#include <Windows.h>

using std::string;
using std::cout;
using std::cin;
using std::endl;

class Level {
public:
    string Class, Back;
    int level = 1, Experience = 0, Skill = 1, Required_experience = 100, Gold = 200;
    double Hp, Hp_Max, Attack, Protection, Knowledge, Magic_Power, Mana;
    // Выбор класса (возможны изменения интерфейса или статов) 

    static void Dungeon(int difficulty){
        switch(difficulty){
            case 1:{
                cout<<"Fucking slave!"<<endl;
                break;
            }
            case 2:{
                cout<<"Boy next door"<<endl;
                break;
            }
            case 3:{
                cout<<"Soo deep"<<endl;
                break;
            }
            default:{cout<<"Введенное значение вне допустимого диапазона"<<endl;break;}
        }
    }

    void Selecting_a_class() {
        for (size_t i = 0; i < 1; i++) {
            system("cls");
            cout << "Выберите класс за которые вы хотите играть" << "\n";
            cout << "Воин - 1" << "\t" << "| атака - 20" << "\t" << "| Защита = 35" << "\t" << "| Магическая Сила = 5"
                 << "\n";
            cout << "Лучник - 2" << "\t" << "| атака - 35" << "\t" << "| Защита = 15" << "\t"
                 << "| Магическая Сила = 10" << "\n";
            cout << "Маг - 3  " << "\t" << "| атака - 15" << "\t" << "| Защита = 5" << "\t" << "| Магическая Сила = 35"
                 << "\n";
            cout << "Выбор: ";
            cin >> Class;
            if (Class == "1") {
                Class = "Воин";
                Sleep(100);
                break;
            } else if (Class == "2") {
                Class = "Лучник";
                Sleep(100);
                break;
            } else if (Class == "3") {
                Class = "Маг";
                Sleep(100);
                break;
            } else {
                system("cls");
                cout << "Ошибка!!! " << "\n";
                cout << "Выберите один из трёх классов " << "\n";
                cout << "Используя целые числа в диапазоне от 1 до 3 " << "\n";
                i--;
                Sleep(100);
            }
        }
    }

    // Начальные статы (возможны изменения статов)
    void Stat_Distribution() {
        if (Class == "Воин") {
            Hp = 120;
            Attack = 20;
            Protection = 35;
            Knowledge = 5;
            Magic_Power = 5;
            Mana = 10;
        } else if (Class == "Лучник") {
            Hp = 100;
            Attack = 35;
            Protection = 15;
            Knowledge = 10;
            Magic_Power = 10;
            Mana = 50;
        } else if (Class == "Маг") {
            Hp = 100;
            Attack = 15;
            Protection = 5;
            Knowledge = 25;
            Magic_Power = 35;
            Mana = 100;
        }
        Sleep(100);
    }

    // Вывод статов на консоль
    void characteristics() {
        system("cls");
        cout << "--------------------------" << "\n";
        cout << "Данные персонажа  \t" << " | " << "\n";
        cout << "Вы выбрали класс " << Class << "\t" << " | " << "\n";
        cout << "Здоровье = " << Hp << "\t" << "         | " << "\n";
        cout << "Уровень = " << level << "\t" << "         | " << "\n";
        cout << "Опыт = " << Experience << "\t" << "         | " << "\n";
        cout << "Атака = " << Attack << "\t" << "         | " << "\n";
        cout << "Защита = " << Protection << "\t" << "         | " << "\n";
        cout << "Знания = " << Knowledge << "\t" << "         | " << "\n";
        cout << "Магическая сила = " << Magic_Power << "\t" << " | " << "\n";
        cout << "Золото = " << Gold << "\t" << "         | " << "\n";
        cout << "Мана = " << Mana << "\t" << "         |" << "\n";
        cout << "Очки навыков = " << Skill << "\t" << " | " << "\n";
        cout << "--------------------------" << "\n";
        Sleep(100);
    }

    // Прирост статов и работа с уровнем
    void Working_with_experience() {
        for (size_t i = 0; i < 1; i++) {
            if (Experience >= Required_experience) {
                level += 1;
                Experience -= Required_experience;
                Required_experience += level * 100;
                if (Class == "Воин") {
                    Hp_Max += (level * 12);
                    Attack += (level * 6);
                    Protection += (level * 8);
                    Knowledge += (level * 2);
                    Magic_Power += (level * 2);
                    Mana += (level * 2);
                    Skill += 1;
                    i--;
                    Sleep(100);
                } else if (Class == "Лучник") {
                    Hp_Max += (level * 8);
                    Attack += (level * 8);
                    Protection += (level * 4);
                    Knowledge += (level * 4);
                    Magic_Power += (level * 4);
                    Mana += (level * 4);
                    Skill += 1;
                    i--;
                    Sleep(100);
                } else if (Class == "Маг") {
                    Hp_Max += (level * 4);
                    Attack += (level * 2);
                    Protection += (level * 2);
                    Knowledge += (level * 6);
                    Magic_Power += (level * 12);
                    Mana += (level * 10);
                    Skill += 1;
                    i--;
                    Sleep(100);
                }
            }
        }
    }

    // Таланты (В разработке) // Будет увеличение хп, атаки и прочие простые функции
    void Talents() {
        if (Skill >= 1) {
            for (size_t i = 0; i < 3; i++) {
                int random = rand() % 5;
                if (random == 0) {
                    cout << "Талант 1 ";
                } else if (random == 1) {
                    cout << "Талант 2 ";
                } else if (random == 2) {
                    cout << "Талант 3 ";
                } else if (random == 3) {
                    cout << "Талант 4 ";
                } else if (random == 4) {
                    cout << "Талант 5 ";
                } else {
                    cout << random;
                }
            }
        }
    }

    // Отдых (Небольшая функция для регена hp в таверне)
    void Rest() {
        Hp += 40 * (Hp_Max / 100);
        if (Hp > Hp_Max) {
            Hp = Hp_Max;
        }
    }
};

class Travelling // Выбор дальнейших действий
{
    public:
    int Talents = 1,inst=0;
    string tavern, Button = "0",  Specifications = "0", skip = "0", rest = "0", talent = "0";

    int Road_selection() {
        for (size_t i = 0; i < 1; i++) {
            if (skip == "0") {
                Sleep(100);
                system("cls");
                cout << "Вы стоите у путеводного камня, выберите ваше следующее действие: " << "\n";
                cout << "Посетить таверну - 1 " << "\n";
                cout << "Отправиться в путешествие - 2 " << "\n";
                cout << "Выход из игры - 3 " << "\n";
                cout << "Выбор: ";
                cin >> Button;
                Sleep(100);
            }
            for (size_t H = 0; H < 1; H++) {
                if (Button == "1" || tavern == "1" || skip == "1") {
                    tavern = "0";
                    for (size_t v = 0; v < 1; v++) {
                        if (skip == "0") {
                            system("cls");
                            cout << "Вы заходите в таверну и понимаете, что у вас есть следующие возможности:" << "\n";
                            cout << "Торговля - 1" << "\n";
                            cout << "Отдых - 2" << "\n";
                            cout << "Вернуться к путеводному камню - 3" << "\n";
                            cout << "Ваши действия: ";
                            cin >> Button;
                            Sleep(100);
                        }
                        if (Button == "1" || skip == "1") {
                            skip = "0";
                            for (size_t Q = 0; Q < 1; Q++) {
                                Sleep(100);
                                system("cls");
                                cout << "Вы решаете заняться торговлей" << "\n";
                                cout << "Вам доступны следующие опции: " << "\n";
                                cout << "Найм отрядов  - 1" << "\n";
                                cout << "Использовать очки талантов  - 2" << "\n";
                                cout << "Узнать свои характеристики  - 3" << "\n";
                                cout << "Вернуться в главный зал - 4" << "\n";
                                cout << "Ваши действия: " << "\n";
                                cin >> Button;
                                if (Button == "1") {
                                    Sleep(100);
                                    system("cls");
                                    cout << "Вы принимаете решение заручиться помощью новых союзников" << "\n";
                                    cout << "У вас следующий выбор юнитов:" << "\n"; // реализовать
                                    cout << "Юниты человеческой расы" << "\n";
                                    cout << "Нелюди" << "\n";
                                    cout << "Ваши действия: " << "\n";
                                    cout << "Узнать о первых - 1" << "\n";
                                    cout << "Узнать о вторых - 2" << "\n";
                                    cout << "Спросить про другие возможности - 3" << "\n";
                                    cout << "Вернуться в главный зал - 4" << "\n";
                                    cin >> Button;
                                    if (Button == "1") {
                                        Sleep(100);
                                        system("cls");
                                        cout << "Вы можете нанять следующих юнитов: " << "\n";
                                        cout << "Демон Хантер -   150 hp | 25 атаки | 100 золотых" << "\n";
                                        cout << "Рыцарь смерти -  700 hp | 75 атаки | 250 золотых" << "\n";
                                        cout << "Паладин      -   950 hp | 125 атаки| 350 золотых" << "\n";
                                        cout << "Ваши действия: " << "\n";
                                        cout << "Нанять ДХ - 1" << "\n";
                                        cout << "Нанять ДК - 2" << "\n";
                                        cout << "Нанять паладина - 3" << "\n";
                                        cout << "Спросить про другие возможности торговца - 4" << "\n";
                                        cout << "Вернуться в главный зал - 5" << "\n";
                                        cin >> Button;
                                        if (Button == "1") {
                                            ////////////
                                        } else if (Button == "2") {
                                            /////////////
                                        } else if (Button == "3") {
                                            //////////////
                                        } else if (Button == "4") {
                                            system("cls");
                                            cout << "Вы решили узнать о других возможностях" << "\n";
                                            v--;
                                        } else if (Button == "5") {
                                            system("cls");
                                            cout << "Вы решили вернуться в главный зал" << "\n";
                                            i--;
                                        } else {
                                            system("cls");
                                            cout << "Ошибка!!! " << "\n";
                                            cout << "Выберите один из пяти вариантов " << "\n";
                                            cout << "Используя целые числа в диапазоне от 1 до 5 " << "\n";;
                                            Q--;
                                        }
                                    } else if (Button == "2") {
                                        Sleep(100);
                                        system("cls");
                                        cout << "Вы можете нанять следующих юнитов: " << "\n";
                                        cout << "Мурлок -   15  hp |  5 атаки | 10  золотых" << "\n";
                                        cout << "Гнолл -    70  hp | 25 атаки | 75  золотых" << "\n";
                                        cout << "Гронн  -  2500 hp | 250 атаки| 850 золотых" << "\n";
                                        cout << "Ваши действия: " << "\n";
                                        cout << "Нанять ДХ - 1" << "\n";
                                        cout << "Нанять ДК - 2" << "\n";
                                        cout << "Нанять паладина - 3" << "\n";
                                        cout << "Спросить про другие возможности торговца - 4" << "\n";
                                        cout << "Вернуться в главный зал - 5" << "\n";
                                        cin >> Button;
                                        if (Button == "1") {
                                            ////////////
                                        } else if (Button == "2") {
                                            /////////////
                                        } else if (Button == "3") {
                                            //////////////
                                        } else if (Button == "4") {
                                            system("cls");
                                            cout << "Вы решили узнать о других возможностях" << "\n";
                                            Q--;
                                        } else if (Button == "5") {
                                            system("cls");
                                            cout << "Вы решили вернуться в главный зал" << "\n";
                                            v--;
                                        } else {
                                            system("cls");
                                            cout << "Ошибка!!! " << "\n";
                                            cout << "Выберите один из пяти вариантов " << "\n";
                                            cout << "Используя целые числа в диапазоне от 1 до 5 " << "\n";
                                            Q--;
                                        }
                                    } else if (Button == "3") {
                                        Sleep(100);
                                        system("cls");
                                        cout << "Вы решили узнать о других возможностях" << "\n";
                                        Q--;
                                    } else if (Button == "4") {
                                        Sleep(100);
                                        system("cls");
                                        cout << "Вы решили вернуться в главный зал" << "\n";
                                        v--;
                                    } else {
                                        system("cls");
                                        cout << "Ошибка!!! " << "\n";
                                        cout << "Выберите один из четырёх вариантов " << "\n";
                                        cout << "Используя целые числа в диапазоне от 1 до 4 " << "\n";
                                        Q--;
                                    }
                                } else if (Button == "2") {
                                    if (Talents >= 1) {
                                        Sleep(100);
                                        system("cls");
                                        cout << "Вы открываете список талантов: " << "\n";
                                        Talents -= 1;
                                        talent = "1";
                                    } else {
                                        Sleep(100);
                                        system("cls");
                                        cout << "У вас не хватает очков для прокачки талантов " << "\n";
                                        Q--;
                                    }
                                } else if (Button == "3") {
                                    Sleep(100);
                                    system("cls");
                                    cout << "Вы решаете посмотреть свои характеристики: " << "\n";
                                    Specifications = "1";
                                    break;
                                } else if (Button == "4") {
                                    Sleep(100);
                                    system("cls");
                                    cout << "Вы решили вернуться в главный зал" << "\n";
                                    v--;
                                } else {
                                    Sleep(100);
                                    system("cls");
                                    cout << "Ошибка!!! " << "\n";
                                    cout << "Выберите один из четырёх вариантов " << "\n";
                                    cout << "Используя целые числа в диапазоне от 1 до 4 " << "\n";
                                    Q--;
                                }
                            }
                        } else if (Button == "2") {
                            Sleep(100);
                            system("cls");
                            cout << "Вы решили отдохнуть" << "\n";
                            rest = "1";
                        } else if (Button == "3") {
                            Sleep(100);
                            system("cls");
                            cout << "Вы решили вернуться к путеводному камню" << "\n";
                            i--;
                        } else {
                            Sleep(100);
                            system("cls");
                            cout << "Ошибка!!! " << "\n";
                            cout << "Выберите один из трех вариантов " << "\n";
                            cout << "Используя целые числа в диапазоне от 1 до 3 " << "\n";
                            v--;
                        }
                    }
                    break;
                } else if (Button == "2") {
                    for (size_t v = 0, s = 0; v < 1; v++) {
                        Sleep(100);
                        system("cls");
                        cout << "Вы отправляетесь в путешествие:" << "\n";
                        cout << "В таверну - 1" << "\n";
                        cout << "В подземелье - 2" << "\n";
                        cout << "К путеводному камню - 3" << "\n";
                        cout << "Ваши действия: ";
                        cin >> Button;
                        if (Button == "1") {
                            Sleep(100);
                            system("cls");
                            cout << "Вы принимаете решение отправиться в таверну " << "\n";
                            Button == "0";
                            tavern = "1";
                            H--;
                        } else if (Button == "2") {
                            Sleep(100);
                            system("cls");
                            cout << "Вы решаете отправиться в подземелье " << "\n";
                            cout << "Выберите сложность подземелья:" << "\n";
                            cout << "Обычное подземелье - 1" << "\n";
                            cout << "Героическое подземелье - 2" << "\n";
                            cout << "Эпохальное подземелье - 3" << "\n";
                            cin >> inst;
                            Level::Dungeon(inst);
                            break;
                        } else if (Button == "3") {
                            Sleep(100);
                            system("cls");
                            cout << "Вы решили вернуться к путеводному камню" << "\n";
                            i--;
                            break;
                        } else {
                            Sleep(100);
                            system("cls");
                            cout << "Ошибка!!! " << "\n";
                            cout << "Выберите один из трёх вариантов " << "\n";
                            cout << "Используя целые числа в диапазоне от 1 до 3 " << "\n";
                            v--;
                        }
                    }
                } else if (Button == "3") {
                    Sleep(100);
                    system("cls");
                    cout << " ---------------------" << "\n";
                    cout << "  Спасибо за игру !!! " << "\n";
                    cout << " ---------------------" << "\n";
                    return 0;
                    break;
                } else {
                    Sleep(100);
                    system("cls");
                    cout << "Ошибка!!! " << "\n";
                    cout << "Выберите один из трёх вариантов " << "\n";
                    cout << "Используя целые числа в диапазоне от 1 до 3 " << "\n";
                    i--;
                }
            }
        }
    }
};

int main() {
    Level Level;
    Travelling Travelling;
    srand(time(NULL));
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string name;
    cout << "Введите имя: ";
    cin >> name;
    cout << "Рады приветствовать вас " << name << " в нашей замечательной игре " << "\n";
    Level.Selecting_a_class(); // Выбор класса
    Level.Stat_Distribution(); // Начальные статы
    Level.characteristics();   // Демонстрация статов на консоли
    for (size_t i = 0; i < 1; i++) {
        Travelling.Road_selection(); // Таверна
        if (Travelling.Specifications == "1") {
            Level.characteristics();
            Travelling.Specifications = "0";
            Travelling.skip = "1";
            Travelling.Button = "0";
            i--;
        }
        if (Travelling.talent == "1") {
            Level.Talents();
            Travelling.talent = "0";
            Travelling.skip = "1";
            Travelling.Button = "0";
            i--;
        }
        if (Travelling.rest == "1") // Систему скипа переделать (возврат в главный зал)
        {
            Sleep(100);
            system("cls");
            cout << "Вы отдохнули " << "\n";
            Level.Rest();
            Travelling.rest = "0";
            Travelling.skip = "1";
            Travelling.Button = "0";
            i--;
        }
    }
}
