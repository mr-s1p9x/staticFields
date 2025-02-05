#include <iostream>
using namespace std;

class Point {
private:
    int x; // Координата x
    int y; // Координата y

    static int count; // Статическое поле для хранения количества созданных объектов

public:
    // Конструктор
    Point(int a = 0, int b = 0) : x(a), y(b) {
        count++; // Увеличиваем количество объектов при каждом создании нового объекта
    }

    // Деструктор
    ~Point() {
        count--; // Уменьшаем количество объектов при уничтожении объекта
    }

    // Метод для получения значения x
    int getx() const {
        return x;
    }

    // Метод для получения значения y
    int gety() const {
        return y;
    }

    // Метод для установки значения x
    void Setx(int a) {
        x = a;
    }

    // Метод для установки значения y
    void Sety(int b) {
        y = b;
    }

    // Метод для вывода координат
    void Print() const {
        cout << "Point(" << x << ", " << y << ")" << endl;
    }

    // Статический метод для получения значения статического поля count
    static int getCount() {
        return count;
    }
};

// Инициализация статического поля
int Point::count = 0;

int main() {
    Point p1(1, 2); // Создаем первый объект
    Point p2(3, 4); // Создаем второй объект

    p1.Print(); // Выводим координаты первого объекта
    p2.Print(); // Выводим координаты второго объекта

    cout << "Количество созданных объектов: " << Point::getCount() << endl; // Выводим количество созданных объектов

    {
        Point p3(5, 6); // Создаем третий объект
        p3.Print(); // Выводим координаты третьего объекта
        cout << "Количество созданных объектов: " << Point::getCount() << endl; // Выводим количество созданных объектов
    } // Объект p3 выходит из области видимости и уничтожается

    cout << "Количество созданных объектов: " << Point::getCount() << endl; // Выводим количество созданных объектов

    return 0;
}
