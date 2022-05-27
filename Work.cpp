#include<iostream>
#include<windows.h>
#include<conio.h>
#include<fstream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<iomanip>
using namespace std;

int k = 7, r = 0, flag = 0;
COORD coord = { 0, 0 };

void gotoxy(int x, int y);
struct date
{
    int mm, dd, yy;
};

ofstream fout;
ifstream fin;

class item
{
    int itemNumber;
    char name[25];
    date date_;
public:
    void add();
    void show();
    void report();
    int getItemNumber();

};

class amount : public item
{
    float price, quantity, tax, gross, discount, netAmount;
public:
    void add();
    void show();
    void report();
    void calculate();
    void pay();
    float getNetAmount();
} amt;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout << setprecision(2);
    fstream tmp("temp.dat", ios::binary | ios::out);
menu:
    system("cls");
    gotoxy(27, 2);
    cout << "Білінгова система для інтернет-провайдерів";
    gotoxy(25, 3);
    cout << "=========================\n\n";
    cout << "\n\t\t1.Рапорт про послуги\n\n";
    cout << "\t\t2.Додати/вилучити/змінити послугу\n\n";
    cout << "\t\t3.Показати інформацію про послугу\n\n";
    cout << "\t\t4.Завершення програми\n\n";
    cout << "\t\tБудь ласка, оберіть одну з запропонованих опцій: ";
    int mainMenu, ff;
    float totalAmount;
    cin >> mainMenu;
    switch (mainMenu)
    {
    case 1:
    billsInfo:
        system("cls");
        gotoxy(25, 2);
        cout << "Інформація про послуги";
        gotoxy(25, 3);
        cout << "================\n\n";
        cout << "\n\t\t1.Усі послуги\n\n";
        cout << "\t\t2.Назад до головного меню\n\n";
        cout << "\t\tБудь ласка, оберіть одну з запропонованих опцій: ";
        int infoMenu;
        cin >> infoMenu;
        if (infoMenu == 1)
        {
            system("cls");
            gotoxy(30, 3);
            cout << " Розгорнута інформація про послугу ";
            gotoxy(3, 5);
            cout << "Номер";
            gotoxy(17, 5);
            cout << "Назва";
            gotoxy(31, 5);
            cout << "Плата за місяць";
            gotoxy(47, 5);
            cout << "Кількість несплачених місяців";
            gotoxy(77, 5);
            cout << "Податки, %";
            gotoxy(88, 5);
            cout << "Знижка, %";
            gotoxy(98, 5);
            cout << "До сплати";
            fin.open("itemstore.dat", ios::binary);
            if (!fin)
            {
                cout << "\n\nФайл з послугами не знайдено...";
                goto menu;
            }
            fin.seekg(0);
            totalAmount = 0;
            while (!fin.eof())
            {
                fin.read((char*)&amt, sizeof(amt));
                if (!fin.eof())
                {
                    amt.report();
                    totalAmount += amt.getNetAmount();
                    ff = 0;
                }
                if (ff != 0) totalAmount = 0;
            }
            gotoxy(17, k);
            cout << "\n\n\n\t\t\tКінцева сума до сплати=" << totalAmount;
            _getch();
            fin.close();
        }
        if (infoMenu == 2)
        {
            goto menu;
        }
        goto billsInfo;
    case 2:
    billsManager:
        system("cls");
        gotoxy(25, 2);
        cout << "Менеджер послуг";
        gotoxy(25, 3);
        cout << "=================\n\n";
        cout << "\n\t\t1.Додати послугу\n\n";
        cout << "\t\t2.Змінити послугу\n\n";
        cout << "\t\t3.Видалити послугу\n\n";
        cout << "\t\t4.Назад до головного меню ";
        int managerMenu;
        cin >> managerMenu;
        switch (managerMenu)
        {
        case 1:
            fout.open("itemstore.dat", ios::binary | ios::app);
            amt.add();
            cout << "\n\t\tПослуга додана успішно!";
            _getch();
            goto billsManager;

        case 2:
            int billNum;
            flag = 0;
            cout << "\n\n\tВведіть номер послуги, яку бажаєте змінити :";
            cin >> billNum;
            fin.open("itemstore.dat", ios::binary);
            fout.open("itemstore.dat", ios::binary | ios::app);
            if (!fin)
            {
                cout << "\n\nФайлу з послугами не знайдено...";
                goto menu;
            }
            fin.seekg(0);
            r = 0;
            while (!fin.eof())
            {
                fin.read((char*)&amt, sizeof(amt));
                if (!fin.eof())
                {
                    int x = amt.item::getItemNumber();
                    if (x == billNum)
                    {
                        flag = 1;
                        fout.seekp(r * sizeof(amt));
                        system("cls");
                        cout << "\n\t\tПоточна інформація про послугу\n";
                        amt.show();
                        cout << "\n\n\t\tВведіть нову інформацію про послугу\n";
                        amt.add();
                        cout << "\n\t\tІнформація про послугу змінена!";
                    }
                }
                r++;
            }
            if (flag == 0)
            {
                cout << "\n\t\tПослуги не існує, спробуйте ще раз!";
                _getch();
                goto billsManager;
            }
            fin.close();
            _getch();
            goto billsManager;

        case 3:
            flag = 0;
            cout << "\n\n\tВведіть номер послуги, яку бажаєте видалити :";
            cin >> billNum;
            fin.open("itemstore.dat", ios::binary);
            if (!fin)
            {
                cout << "\n\nФайл з послугами не знайдений...";
                goto menu;
            }

            fin.seekg(0);
            while (fin.read((char*)&amt, sizeof(amt)))
            {
                int x = amt.item::getItemNumber();
                if (x != billNum)
                    tmp.write((char*)&amt, sizeof(amt));
                else
                {
                    flag = 1;
                }
            }
            fin.close();
            tmp.close();
            fout.open("itemstore.dat", ios::trunc | ios::binary);
            fout.seekp(0);
            tmp.open("temp.dat", ios::binary | ios::in);
            if (!tmp)
            {
                cout << "Помилка в файлі!";
                goto billsManager;
            }
            while (tmp.read((char*)&amt, sizeof(amt)))
                fout.write((char*)&amt, sizeof(amt));
            tmp.close();
            fout.close();
            if (flag == 1)
                cout << "\n\t\tПослуга успішно видалена";
            else if (flag == 0)
                cout << "\n\t\tПослуги не існує, спробуйте ще раз!";
            _getch();
            goto billsManager;
        case 4:
            goto menu;
        default:
            cout << "\n\n\t\tВи ввели некоректне значення опції, спробуйте ще раз!";
            _getch();
            goto billsManager;
        }
    case 3:
        system("cls");
        flag = 0;
        int billNum;
        cout << "\n\n\t\tВведіть номер послуги :";
        cin >> billNum;
        fin.open("itemstore.dat", ios::binary);
        if (!fin)
        {
            cout << "\n\nФайл не знайдено...\nРобота програми припинена!";
            goto menu;
        }
        fin.seekg(0);
        while (fin.read((char*)&amt, sizeof(amt)))
        {
            int x = amt.item::getItemNumber();
            if (x == billNum)
            {
                amt.pay();
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            cout << "\n\t\tПослуги не існує, спробуйте ще раз!";
        _getch();
        fin.close();
        goto menu;
    case 4:
    {
        system("cls");
        gotoxy(20, 20);
        cout << "Ви впевнені, що хочете завершити роботу програми(Т або Н)?";
        char choose;
        cin >> choose;
        if ((choose == 'Т') || (choose == 'т'))
        {
            gotoxy(12, 20);
            system("cls");
            cout << "**************************************** Дякую за використання нашої програми! ****************************************";
            _getch();
            exit(0);
        }
        else if ((choose == 'Н') || (choose == 'н'))
            goto menu;
        else
        {
            goto menu;
        }
    }
    default:
    {
        cout << "\n\n\t\tВи ввели некоректне значення номеру пункту меню, спробуйте ще раз!";
        _getch();
        goto menu;
    }
    }
    return 0;
}

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void item::add()
{
    cout << "\n\n\tНомер послуги: ";
    cin >> itemNumber;
    cout << "\n\n\tНазва послуги: ";
    cin >> name;
    cout << "\n\n\tДата оформлення підписки на вказану послугу(у форматі ДД-ММ-РРРР): ";
    cin >> date_.dd >> date_.mm >> date_.yy;
}

void item::show()
{
    cout << "\n\tНомер послуги: ";
    cout << itemNumber;
    cout << "\n\n\tНазва послуги: ";
    cout << name;
    cout << "\n\n\tДата оформлення підписки на вказану послугу(ДД-ММ-РРРР): ";
    cout << date_.dd << "-" << date_.mm << "-" << date_.yy;
}

void item::report()
{
    gotoxy(3, k);
    cout << itemNumber;
    gotoxy(13, k);
    puts(name);
}

int item::getItemNumber()
{
    return itemNumber;
}

void amount::add()
{
    item::add();
    cout << "\n\n\tВартість послуги: ";
    cin >> price;
    cout << "\n\n\tЗа скільки місяців потрібно сплатити: ";
    cin >> quantity;
    cout << "\n\n\tПодатковий відсоток: ";
    cin >> tax;
    cout << "\n\n\tЗнижка(у відсотках): ";
    cin >> discount;
    calculate();
    fout.write((char*)&amt, sizeof(amt));
    fout.close();
}

void amount::calculate()
{
    gross = price + (price * (tax / 100));
    netAmount = quantity * (gross - (gross * (discount / 100)));
}

void amount::show()
{
    fin.open("itemstore.dat", ios::binary);
    fin.read((char*)&amt, sizeof(amt));
    item::show();
    cout << "\n\n\tДо сплати за користування послугою: ";
    cout << netAmount;
    fin.close();
}

void amount::report()
{
    item::report();
    gotoxy(23, k);
    cout << price;
    gotoxy(33, k);
    cout << quantity;
    gotoxy(44, k);
    cout << tax;
    gotoxy(52, k);
    cout << discount;
    gotoxy(64, k);
    cout << netAmount;
    k = k + 1;
    if (k == 50)
    {
        gotoxy(25, 50);
        cout << "Натисність будь-яку клавішу на клавіатурі для продовження...";
        (void)_getch();
        k = 7;
        system("cls");
        gotoxy(30, 3);
        cout << " Розгорнута інформація про послугу ";
        gotoxy(3, 5);
        cout << "Номер";
        gotoxy(13, 5);
        cout << "Назва";
        gotoxy(23, 5);
        cout << "Вартість за місяць";
        gotoxy(33, 5);
        cout << "Кількість несплачених місяців";
        gotoxy(44, 5);
        cout << "Податковий відсоток";
        gotoxy(52, 5);
        cout << "Висновок";
        gotoxy(64, 5);
        cout << "До сплати";
    }
}

void amount::pay()
{
    show();
    cout << "\n\n\n\t\t********************************************";
    cout << "\n\t\t             Розгорнута інформація              ";
    cout << "\n\t\t************************************************";
    cout << "\n\n\t\tВартість послуги за місяць       :" << price;
    cout << "\n\n\t\tКількість несплачених місяців    :" << quantity;
    cout << "\n\t\tПодатковий відсоток                :" << tax;
    cout << "\n\t\tЗнижка(у відсотках)         :" << discount;
    cout << "\n\n\n\t\tДо сплати              :UAH" << netAmount;
    cout << "\n\t\t*********************************************";
}

float amount::getNetAmount()
{
    return netAmount;
}