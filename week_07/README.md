# Упранжение 7

## Какво правихме предния път?
- static член-данни и методи
- exceptions
- dynamic array


Ще довършим темата за класове като обхванем последните концепции, свързани с тях:

## Приятелски класове:

Клас означен като приятелски на друг му позволява да използва private и protected член данните му.

```
class Point {
private:
    int x;
    int y;

    friend class Board; // Board има директен достъп до x и y
};
```

**Важно: Това, че класът Board е приятел на Point не означава, че Point e приятел на Board**

## Приятелски функции на клас:

Функция означена като приятелска на клас и позволява да използва private и protected член данните на класа.

Функцията може да бъде:
- метод на друг клас
- глобална функция

```c++
class Point {
private:
    int x;
    int y;

    friend class Board::boardGame(); // функцията boardGame() от класа Board има директен достъп до x и y
};
```

Пример 1:
```c++
class B;
 
class A {
public:
    void showB(B&);
};
 
class B {
private:
    int b;
 
public:
    B() { b = 0; }
    friend void A::showB(B& x); // Friend function
};
 
void A::showB(B& x)
{
    // Since showB() is friend of B, it can
    // access private members of B
    std::cout << "B::b = " << x.b;
}
 
int main()
{
    A a;
    B x;
    a.showB(x);
    return 0;
}
```

Пример 2:
```c++
class A {
    int a;
 
public:
    A() { a = 0; }
 
    // global friend function
    friend void showA(A&);
};
 
void showA(A& x)
{
    // Since showA() is a friend, it can access
    // private members of A
    std::cout << "A::a=" << x.a;
}
 
int main()
{
    A a;
    showA(a);
    return 0;
}
```

## Move семантика

Move семантиката ни позволява да избягваме ненужни копирания на обекти, когато искаме да работим с тях временно (например в тялото на някой метод) и такива, които са на път да се изпарят и чиито ресурси могат безопасно да бъдат **взети** или **преместени** от този временен обект и използвани от друг.

Проблемът най-просто казано е следния - в повечето случаи когато искаме да вземем данните на някакво entity (class) и работим с динамична памет, ще трябва да заделяме памет **2 пъти**. Нека го покажем това с ръчно написан `String` :)

```c++
    insert String here
```

Какво се случва тук? Нека разгледаме ред по ред - задаваме size да ни е равен на предоставения `rvalue` или `temporary` - стойност която не сочи никъде в паметта.

По интересен е реда за приравняването на данните:

там **директно пренасочваме указателя от this->data в текущия scope на стринг към other или към данните на другия обект БЕЗ ДА ИМА НУЖДА ДА ЗАДЕЛЯМЕ НОВА ПАМЕТ ЗА ТЯХ.**

Следващите два реда са ключови (обърнете внимание на тях). Много е важно след като сме "превзели" данните на обекта `other` да ги изчистим от паметта, защото те вече не могат да бъдат достъпени по никакъв начин. Съответно трябва да занулим всяка една данна, която е била взета от нас при изпълнението на move constructor-а

```c++
String(String&& other) noexcept {
        std::cout << "Moved" << std::endl;
        this->size = other.size;
        this->data = other.data;  // assigning the pointer!!!
    
        other.size = 0;
        other.data = nullptr; // making other "hollow"
    }
```
