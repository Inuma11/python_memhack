from pymem import Pymem

pm = Pymem("Game.exe")
print("PID:", pm.process_id)

HP_ADDR   = 0x00007FF687E8F000  # &g_player.hp
GOLD_ADDR = 0x00007FF687E8F004  # &g_player.gold

def show():
    hp   = pm.read_int(HP_ADDR)
    gold = pm.read_int(GOLD_ADDR)
    print(f"[MEM] HP={hp}, GOLD={gold}")

show()

pm.write_int(HP_ADDR,   2147483646)
pm.write_int(GOLD_ADDR, 2147483647)

show()

pm.close_process()
