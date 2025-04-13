#/bin/sh
# 
# Для полного удаления ZMOD без FLUIDD
# 1. Отформатируйте флешку в FAT32
# 2. Поместите файл flashforge_init.sh на эту флешку
# 3. Выключите принтер
# 4. Вставьте флешку в принтер
# 5. Включите принтер
# 6. Принтер 3 раза перезагрузится
# 7. Извлеките флешку и пользуйтесь стоковой прошивкой

zreboot() {
  sync
  echo 1 > /proc/sys/kernel/sysrq
  sync
  echo b > /proc/sysrq-trigger || echo "error sysrq-trigger"
  sync
}

echo "">/opt/config/mod/FULL_REMOVE || echo "FF5m not found"
echo "">/usr/data/config/mod/FULL_REMOVE || echo "AD5X not found"
sync
rm /mnt/flashforge_init.sh
sync
sleep 5
sync
[ -f /opt/config/mod/FULL_REMOVE ] && reboot
[ -f /usr/data/config/mod/FULL_REMOVE ] && zreboot
