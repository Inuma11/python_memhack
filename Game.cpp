#include <iostream>
#include <cstdlib>
#include <ctime>

struct Player {
    int hp;
    int gold;
};

Player g_player{ 100, 0 };

void print_status() {
    std::cout << "===== PLAYER =====\n";
    std::cout << "HP   : " << g_player.hp << "\n";
    std::cout << "Gold : " << g_player.gold << "\n";
    std::cout << "==================\n";
}

void print_addresses() {
    std::cout << "\n[DEBUG] Addresses (for pymem)\n";
    std::cout << "  &g_player      = " << (void*)&g_player << "\n";
    std::cout << "  &g_player.hp   = " << (void*)&g_player.hp << "\n";
    std::cout << "  &g_player.gold = " << (void*)&g_player.gold << "\n\n";
}

int main() {
    std::srand((unsigned)std::time(nullptr));

    std::cout << "=== C++ Memory Trainer Game ===\n";
    print_addresses();

    while (true) {
        print_status();
        std::cout << "1: 戦う  2: 休む  3: 終了\n> ";

        int c;
        if (!(std::cin >> c)) {
            std::cin.clear();
            std::cin.ignore(1024, '\n');
            continue;
        }

        if (c == 1) {
            int dmg = std::rand() % 15;
            int gold = std::rand() % 10;

            g_player.hp -= dmg;
            if (g_player.hp < 0) g_player.hp = 0;
            g_player.gold += gold;

            std::cout << "敵の攻撃で " << dmg << " ダメージ！"
                << " ゴールド +" << gold << "\n";

            if (g_player.hp == 0) {
                std::cout << "HP 0… ゲームオーバー\n";
                break;
            }
        }
        else if (c == 2) {
            int heal = std::rand() % 10 + 5;
            g_player.hp += heal;
            if (g_player.hp > 100) g_player.hp = 100;
            std::cout << "休んで " << heal << " 回復！\n";
        }
        else if (c == 3) {
            break;
        }
        std::cout << "\n";
    }
}
