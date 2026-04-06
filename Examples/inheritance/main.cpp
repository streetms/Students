#include <iostream>
#include <vector>
#include <string>


//необходимо разбить класс на .h/.cpp файлы
class Character {
protected:
    std::string name; // имя персонажа
    int hp;           // здоровье

public:
    Character(const std::string& name_, int hp_)
        : name(name_), hp(hp_) {}

    virtual ~Character() = default; // важно для полиморфизма

    // TODO (1): сделать класс абстрактным (оставить = 0)
    virtual int attack() = 0;

    // TODO (2): реализовать получение урона:
    // - отрицательный урон считать 0
    // - hp не должен уходить ниже 0
    virtual void takeDamage(int dmg) {
        // TODO
    }

    // TODO (3): вернуть true, если персонаж жив (hp > 0)
    bool isAlive() const {
        // TODO
        return true;
    }

    const std::string& getName() const { return name; }
    int getHP() const { return hp; }

    // TODO (4): вывести базовую информацию (имя и hp)
    // Пример: "Конан | Здоровье: 60"
    virtual void printStatus() const {
        // TODO
    }
};

// ---------------- Классы-наследники ----------------

class Warrior : public Character {
private:
    int strength; // сила

public:
    Warrior(const std::string& name_, int hp_, int strength_)
        : Character(name_, hp_), strength(strength_) {}

    // TODO (5): урон воина зависит от силы
    int attack() override {
        // TODO
        return 0;
    }

    // TODO (6): вывести статус: базовый + сила
    // Пример: "Конан | Здоровье: 60 | Сила: 12"
    void printStatus() const override {
        // TODO
    }
};

class Mage : public Character {
private:
    int mana;        // мана
    int spellDamage; // урон заклинанием

public:
    Mage(const std::string& name_, int hp_, int mana_, int spellDamage_)
        : Character(name_, hp_), mana(mana_), spellDamage(spellDamage_) {}

    // TODO (7):
    // - если mana >= 5: потратить 5 маны и вернуть spellDamage
    // - иначе: вернуть 2
    int attack() override {
        // TODO
        return 0;
    }

    // TODO (8): вывести статус: базовый + мана + урон заклинанием
    void printStatus() const override {
        // TODO
    }
};

class Archer : public Character {
private:
    int arrows;      // стрелы
    int arrowDamage; // урон стрелой

public:
    Archer(const std::string& name_, int hp_, int arrows_, int arrowDamage_)
        : Character(name_, hp_), arrows(arrows_), arrowDamage(arrowDamage_) {}

    // TODO (9):
    // - если arrows > 0: уменьшить arrows на 1 и вернуть arrowDamage
    // - иначе: вернуть 1
    int attack() override {
        // TODO
        return 0;
    }

    // TODO (10): вывести статус: базовый + стрелы + урон стрелой
    void printStatus() const override {
        // TODO
    }
};

// ---------------- Вспомогательные функции боя ----------------

// TODO (11): посчитать количество живых персонажей в team
int countAlive(const std::vector<Character*>& team) {
    // TODO
    return 0;
}

// TODO (12): найти следующего живого персонажа после startIndex (по кругу)
// Вернуть индекс или -1, если живых нет
int nextAliveIndex(const std::vector<Character*>& team, int startIndex) {
    // TODO
    return -1;
}

// TODO (13): вывести статусы всех персонажей
void printTeam(const std::vector<Character*>& team) {
    // TODO
}

// TODO (14): сделать один ход/атаку:
// attacker атакует target, target получает урон.
// Вернуть true, если атака произошла, иначе false (например, если кто-то мёртв).
bool doAttack(Character* attacker, Character* target) {
    // TODO
    return false;
}

int main() {
    // Создаём персонажей (объекты на стеке)
    Warrior w("Конан", 60, 12);
    Mage m("Мерлин", 45, 20, 15);
    Archer a("Леголас", 50, 6, 10);

    // Храним указатели на базовый класс (полиморфизм)
    std::vector<Character*> team;
    team.push_back(&w);
    team.push_back(&m);
    team.push_back(&a);

    std::cout << "Игра начинается!\n";
    printTeam(team);

    int round = 1;

    // TODO (15): реализовать цикл боя:
    // - пока живых больше 1
    // - каждый живой персонаж атакует следующего живого (по кругу)
    // - после раунда вывести состояние команды
    //
    // Подсказка:
    // for i=0..n-1:
    //   если team[i] жив:
    //     targetIndex = nextAliveIndex(team, i)
    //     doAttack(team[i], team[targetIndex])
    // После цикла for: printTeam(team)
    //
    // В процессе каждого удара выводить строку:
    // "<Имя1> атакует <Имя2> и наносит <dmg>. Здоровье <Имя2> = <hp>"
    //
    // TODO: написать здесь цикл

    std::cout << "\n=== Итог ===\n";
    // TODO (16): вывести победителя (кто жив) или "Никто не выжил."
    // TODO

    return 0;
}