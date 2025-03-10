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

echo "">/opt/config/mod/FULL_REMOVE
sync
rm /mnt/flashforge_init.sh
sync
sleep 5
sync
reboot
