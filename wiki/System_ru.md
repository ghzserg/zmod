<h1 align="center">System</h1>

*[Read in English](https://github.com/ghzserg/zmod/wiki/System_en)*

Макрос - это небольшая программа на языке Klipper/Gcode. 

Он может вызываться:
- Из файла GCODE
- Из консоли Fluidd/Mainsail (нажать английскую букву `C` в fluidd)

> [!NOTE]
> *Значение указанное в скобках - это значение по умолчанию*

[@zmod_help_bot](http://t.me/zmod_help_bot)

---

<table style="width: 100%; table-layout: fixed;" align="center">
<thead><tr>
  <th colspan="4"><p align="center"><strong>🔷 Системные макросы 🔷</strong></p></th>
</tr></thead>
<tbody>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/System_ru#check_system">CHECK_SYSTEM</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/System_ru#mem">MEM</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/System_ru#check_md5">CHECK_MD5</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/System_ru#web">WEB</a></td>
 </tr>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/System_ru#clear_emmc">CLEAR_EMMC</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/System_ru#test_emmc">TEST_EMMC</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/System_ru#display_off">DISPLAY_OFF</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/System_ru#display_on">DISPLAY_ON</a></td>
 </tr>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/System_ru#date_get">DATE_GET</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/System_ru#date_set">DATE_SET</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/System_ru#update_mcu">UPDATE_MCU</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/System_ru#reset_passwd">RESET_PASSWD</a></td>
 </tr>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/System_ru#screen">SCREEN</a></td>
 </tr>
</tbody>
</table>

### DISPLAY_ON

Включить стандартный экран и перезагрузить принтер.

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#system)

</div>

---

### DISPLAY_OFF

- GUPPY: 0 - не включать GuppyScreen, 1 - включить GuppyScreen (1)

Выключить стандартный экран. Экономит 13 мегабайт (на старых версиях родной прошивки 20 мегабайт).

GuppyScreen - альтернативная реализация экрана:
- Поддерживает все функции родного экрана, кроме настройки WiFi
- Использует 9 Мб оперативной памяти, против 23 Мб на родном экране
- Не зависает при перезагрузке клипера
- Рекомендуется использовать вместо родного экрана.
- Более качественное восстановление прерванной печати
- Собирается из [форка](https://github.com/ghzserg/guppyscreen_ff5m), который базируется на [оригинальном репозитории](https://github.com/ballaswag/guppyscreen) и другом [форке](https://github.com/consp/guppyscreen/tree/flashforge_ad5m).

**Не отключайте экран, если вы четко не понимаете как работает карта стола, z-offset и макросы START_PRINT и END_PRINT**

*Не нужно включать этот макрос в  g-code.*
После перезагрузки экран будет работать ещё 3 минуты, но он не влияет на z-offset т.к. печать идёт, не через него.

Чтобы изменить время активации альтернативного экрана [используйте глобальные параметры](https://github.com/ghzserg/zmod/wiki/Global_ru#display_off_timeout)

Настройте START_PRINT. Установите нужный z-offset через него или через глобальные параметры.

[Прочитайте эту заметку](https://github.com/ghzserg/zmod/wiki/FAQ#%D1%87%D0%B5%D0%BC-%D0%BE%D1%82%D0%BB%D0%B8%D1%87%D0%B0%D0%B5%D1%82%D1%81%D1%8F-%D1%80%D0%B0%D0%B1%D0%BE%D1%82%D0%B0-%D1%81-%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%BE%D0%BC-%D0%B8-%D0%B1%D0%B5%D0%B7-%D1%80%D0%BE%D0%B4%D0%BD%D0%BE%D0%B3%D0%BE-%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0)

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#system)

</div>

---

### MEM

Посмотреть расход памяти

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#system)

</div>

---

### TEST_EMMC

Записывает SIZE Мб на EMMC и пишет скорость чтения записи.

Выводит процент износа EMMC

- SIZE - сколько мегабайт будет записано (100)
- SYNC - 1 - работа в синхронном режиме. Будет записано и прочитано SIZE мегабайт данных и выведена скорость, 0 - асинхронный режим, в фоне  будет записано SIZE мегабайт данных - служит для фоновой нагрузки EMMC карты памяти. (1)
- FLASH - производить запись: 0 - на EMMC, 1 - на USB FLASH, 2 - в оперативную память (0)
- RANDOM - использовать случайные числа  для записи. 1 - да, 0 - нет (0)

На стоке:
Скачать файл [zfs.sh](https://github.com/ghzserg/zmod_ff5m/blob/1.6/.shell/zfs.sh)
```
chmod +x zfs.sh
./zfs.sh 400 1
```

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#system)

</div>

---

### CLEAR_EMMC

Очищает EMMC.

- LOG - очищать log фалы, 1 - да, 0 - нет (1)
- ANY - очищать все (gcode, картинки, фото, видео) кроме лог файлов, 1 - да, 0 - нет (0)

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#system)

</div>

---

### DATE_GET

Посмотреть текущее время

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#system)

</div>

---

### DATE_SET

Установить дату и время в формате 2024.01.01-00:00:00
- DT - дата 2024.01.01-00:00:00

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#system)

</div>

---

### WEB

Сменить веб интерфейс fluidd/mainsail

После запуска макроса:
- Нужно нажать `Ctrl + F5` или `Ctrl + Shift + R` или `Option + Command + E`
- Если у вас проблема в Orca, то нужно нажать `Ctrl + F5` или `Ctrl + Shift + R` или `Option + Command + E`

Если используется Mainsail, то пропишите только эти размеры миниатюр: ```140x110/PNG, 64x64/PNG```

В Orca `Профиль принтера` -> `Общая информация` -> `Дополнительно` -> `Эскизы G-кода`

Учтите, что родной экране перестанет показывать миниатюры.

Внимание! Автор использует Fluidd, Mainsail тестируется только пользователями. Если есть проблемы с Mainsail создавайте [тикет](https://github.com/ghzserg/zmod/wiki/Help)

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#system)

</div>

---

### SET_TIMEZONE

Смена часового пояса
- ZONE - часовая зона (Asia/Yekaterinburg)

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#system)

</div>

---

### CHECK_MD5

Igor Polunovskiy

Рекомендуется использовать [глобальный параметр FORCE_MD5](https://github.com/ghzserg/zmod/wiki/Global_ru#force_md5) `SAVE_ZMOD_DATA FORCE_MD5=1`

Проверить MD5 сумму.
- DELETE - удалять битый файл (yes)

*Пропишите в скрипты постобработки вызов [addMD5.bat](https://github.com/ghzserg/FF/releases/download/R/addMD5.bat) или
[addMD5.sh](https://github.com/ghzserg/FF/releases/download/R/addMD5.sh) для Mac/Linux*(не забудьте добавить право исполнения на файл `chmod +x addMD5.sh`) или
[addMD5.py](https://github.com/ghzserg/FF/releases/download/R/addMD5.py) он лежит в mod. [Подробнее](https://github.com/ghzserg/zmod/wiki/System_ru#check_md5)

Также можно использовать [бинарные файлы на Go собранные под основные архитектуры](https://github.com/asd2003ru/addmd5/releases/) от @asd2003ru:
- `addmd5-darwin-amd64` (MacOS Intel). Не забудьте выполнить ```chmod +x addmd5-darwin-amd64```
- `addmd5-darwin-arm64` (MacOS Silicon). Не забудьте выполнить ```chmod +x addmd5-darwin-arm64```
- `addmd5-linux-amd64` (Linux). Не забудьте выполнить ```chmod +x addmd5-linux-amd64```
- `addmd5-windows-amd64.exe` (Windows)

Его надо скачать к себе на компьютер, а потом в Orca прописать. `Профиль процесса` -> `Прочее` -> `Скрипты пост обработки`.

Вот варианты добавления:
- ```"С:\путь_до_файла\addMD5.bat";```
- ```"C:\python_folder\python.exe" "C:\Scripts\add_md5.py";```
- ```"/home/user/addmd5-linux-amd64";```

```
Остановка печати в случае несоответствия контрольной суммы с возможным удалением дефектного файла.

Автор не несет ответственности за любые ошибки или проблемы, а также за результаты, полученные при использовании этой информации.

Контрольная сумма записывается в начало файла с G-кодом. Если файл не содержит контрольной суммы, проверка файла макросом не осуществляется, и он сразу отправляется на печать.
Результат проверки выводится в консоль.

=========================================
1. На машине с Windows, где установлен слайсер.
  а) Копируем из папки "mod" с принтера файл "addMD5.bat" в удобной место или качаем
        https://github.com/ghzserg/FF/releases/download/R/addMD5.bat
        https://github.com/ghzserg/FF/releases/download/R/addMD5.sh
  б) Добавляем в слайсер скрипт из пункта 1.а, 
     заменяя "disk:\patch\to\file\" на свой путь к данному скрипту:
    - для OrcaSlicer
      "Процесс"->"Прочее"->"Скрипты постобработки" 
    - для SuperSlicer и PrusaSlicer
      "Настройки печати"->"Выходные параметры"->"Скрипты постобработки"
    disk:\patch\to\file\addMD5.bat;
  в) Добавляем в слайсер макрос
    - для OrcaSlicer 
      "Профиль принтера"->"G-код принтера"->"Стартовый G-код принтера"
    - для SuperSlicer и PrusaSlicer
      "Настройки принтера"->"Пользовательский G-код"->"Стартовый G-код"
    * Без удаления файла:
      CHECK_MD5
    * С удалением файла:
      CHECK_MD5 DELETE=true
  г) Если используется макрос START_PRINT, то добавлять CHECK_MD5 в стартовый код нет необходимости. По умолчанию проверка проводится автоматически.
```

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#system)

</div>

---

### UPDATE_MCU

Обновить MCU в принтере.

Меняет прошивку MCU с родной версии Klipper (11 для FF5M/FF5MPRO, 12 для AD5X) на Klipper 13 и обратно

Klipper 13 (по умолчанию отключен).

Параметр FORCE:

- 11 - загрузить прошивку Klipper 11 - FF5M
- 12 - загрузить прошивку Klipper 12 - AD5X
- 13 - загрузить прошивку Klipper 13

Без параметров меняет прошивку на противоположную.

Пример: `UPDATE_MCU FORCE=13` принудительно загрузить прошивку Klipper 13

Если не понимаете, как [восстановить конфиги и прошивку MCU](https://github.com/ghzserg/zmod/wiki/R#installing-full-firmware-on-ad5x), не запускайте.

Если что-то пойдет не так, обратно только через [factory](https://github.com/ghzserg/zmod/wiki/R).

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#system)

</div>

---

### RESET_PASSWD

Сбросить пароль пользователя root на root

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#system)

</div>

---

### CHECK_SYSTEM

Проверить операционную систему принтера на предмет повреждений файлов.

- RESTORE: 0 - не восстанавливать поврежденные файлы, 1 - восстановить поврежденные файлы (0)

Проверяются: 
- Файлы (md5, права)
- Каталоги (права)
- Символические ссылки (корректность указания)

Символические ссылки, права на каталоги и файлы восстанавливаются автоматически.

Время проверки около 10 минут.

Если найдены ошибки - перейдите по [ссылке](https://github.com/ghzserg/zmod/tree/main/stock), там можно скачать не поврежденную копию файла.

---
<div align="center">

[![Back](https://github.com/ghzserg/zmod/wiki/images/Back.svg)](https://github.com/ghzserg/zmod/wiki/Global_ru)
[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#system)
[![Forward](https://github.com/ghzserg/zmod/wiki/images/Forward.svg)](https://github.com/ghzserg/zmod/wiki/Zmod_ru)

</div>

---

### SCREEN

Получить снимок экрана принтера

Снимок будет сохраненн в ```mod_data/screen.jpg```

---
<div align="center">

[![Back](https://github.com/ghzserg/zmod/wiki/images/Back.svg)](https://github.com/ghzserg/zmod/wiki/Global_ru)
[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#system)
[![Forward](https://github.com/ghzserg/zmod/wiki/images/Forward.svg)](https://github.com/ghzserg/zmod/wiki/Zmod_ru)

</div>
