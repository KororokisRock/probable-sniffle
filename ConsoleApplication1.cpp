#include <iostream>
#include <string>
using namespace std;
class Student {
    friend class Teacher; // даём доступ к приватным данным классу Teacher

    public:
        static int ammount_student; // создаём статистическую переменную количествл студентов
        static void plus_student() { // метод который увеличивает на единицу статистическую переменную ammount_student
            ammount_student ++;
        }


        string name;// поле name и поле age
        int age = 21;
    
        int age_student() { // возвращает поле age
            return age;
        }
        void birthday() { // празднует День Рождение и изменяет age увеличивая на единицу
            cout << "Happy Birthday " + name + " !";
            age++;
        }
        void change_name(string name_) { // изменяет поле name
            name = name_;
        }

        void change_faculty(string faculty_) { // сеттер для приватного поля faculty
            faculty = faculty_;
        }
        string print_profile_student() { // геттер для приватного поля faculty, который печатает профиль студента(имя, возраст, факультет).
            cout << "Name: " + name + '\n' + "Age: ";
            cout << age;
            cout << '\n' + "Faculty: " + faculty + '\n';
        }
        void print_faculty() {
            cout << faculty << endl;
        }
    private: // делает приватным поле faculty
        string faculty;
};

class Teacher { // создаём класс Teacher
    public: // делаем метод, который взаимодействует с приватными данными класса Student
        void what_is_your_faculty(Student& st) { // Выводит вопрос и получает ответ при помощи метода, взаимодествующего с приватными данными класса Student
            cout << "What is your faculty?" << endl;
            st.print_faculty();
            cout << "Ok" << endl;
        }
};

int main()
{
    Student Ivan; // создаём объект Ivan
    Teacher Mr_Addams; // создаём объект Teacher
    Ivan.change_faculty("Medicine"); // изменяем параметр faculty для объекта Ivan
    Mr_Addams.what_is_your_faculty(Ivan); // пользуемся методом с доступом к приватным данным объекта Ivan
}
 // программа работает................................. (УРААА!!!!)
