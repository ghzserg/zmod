#/bin/sh
# 
# Для отключения китайских облаков на родной прошивке
# 1. Отформатируйте флешку в FAT32
# 2. Поместите файл flashforge_init.sh на эту флешку
# 3. Выключите принтер
# 4. Вставьте флешку в принтер
# 5. Включите принтер
# 6. Принтер 1 раз перезагрузится
# 7. Извлеките флешку и пользуйтесь стоковой прошивкой

# Разблокировка
china_razbl()
{
    grep -q "$1" /etc/hosts && sed -i "/$1/d" /etc/hosts
}

# Блокировка
china_block()
{
    grep -q "$1" /etc/hosts || sed -i "2 i\127.0.0.1 $1" /etc/hosts
}

china_block api.cloud.flashforge.com
china_block api.fdmcloud.flashforge.com
china_block cloud.sz3dp.com
china_block hz.sz3dp.com
china_block printer2.polar3d.com
china_block qvs.qiniuapi.com
china_block update.cn.sz3dp.com
china_block update.sz3dp.com
china_block cloud.sz3dp.com
china_block polar3d.com

sync
rm /mnt/flashforge_init.sh
sync
sleep 5
sync
reboot
