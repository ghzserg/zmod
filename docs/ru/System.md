<h1 align="center">System</h1>

Макрос - это небольшая программа на языке Klipper/Gcode. 

Он может вызываться:

- Из файла GCODE
- Из консоли Fluidd/Mainsail (нажать английскую букву `C` в fluidd)

!!! note
    *Значение указанное в скобках - это значение по умолчанию*

---

### DISPLAY_ON

Включить стандартный экран и перезагрузить принтер.

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

Чтобы изменить время активации альтернативного экрана [используйте глобальные параметры](/ru/Global/#display_off_timeout)

Настройте START_PRINT. Установите нужный z-offset через него или через глобальные параметры.

[Прочитайте эту заметку](/ru/FAQ/#чем-отличается-работа-с-экраном-и-без-родного-экрана)

---

### MEM

Посмотреть расход памяти

---

### TEST_EMMC

Записывает SIZE Мб на EMMC и пишет скорость чтения записи.

Выводит процент износа EMMC

- SIZE - сколько мегабайт будет записано (100)
- SYNC - 1 - работа в синхронном режиме. Будет записано и прочитано SIZE мегабайт данных и выведена скорость, 0 - асинхронный режим, в фоне  будет записано SIZE мегабайт данных - служит для фоновой нагрузки EMMC карты памяти. (1)
- FLASH - производить запись: 0 - на EMMC, 1 - на USB FLASH, 2 - в оперативную память (0)
- RANDOM - использовать случайные числа  для записи. 1 - да, 0 - нет (0)

На стоке:
Скачать файл [zfs.sh](https://github.com/ghzserg/z_ff5m/blob/1.6/.shell/zfs.sh)
```
chmod +x zfs.sh
./zfs.sh 400 1
```

---

### CLEAR_EMMC

Очищает EMMC.

- LOG - очищать log фалы, 1 - да, 0 - нет (1)
- ANY - очищать все (gcode, картинки, фото, видео) кроме лог файлов, 1 - да, 0 - нет (0)

---

### DATE_GET

Посмотреть текущее время

---

### DATE_SET

Установить дату и время в формате 2024.01.01-00:00:00

- DT - дата 2024.01.01-00:00:00

---

### WEB

Сменить веб интерфейс fluidd/mainsail

После запуска макроса:

- Нужно нажать `Ctrl + F5` или `Ctrl + Shift + R` или `Option + Command + E`
- Если у вас проблема в Orca, то нужно нажать `Ctrl + F5` или `Ctrl + Shift + R` или `Option + Command + E`

Если используется Mainsail, то пропишите только эти размеры миниатюр: ```140x110/PNG, 64x64/PNG```

В Orca `Профиль принтера` -> `Общая информация` -> `Дополнительно` -> `Эскизы G-кода`

Учтите, что родной экране перестанет показывать миниатюры.

Внимание! Автор использует Fluidd, Mainsail тестируется только пользователями. Если есть проблемы с Mainsail создавайте [тикет](/ru/Help/)

---

### SET_TIMEZONE

Смена часового пояса

- ZONE - часовая зона (Asia/Yekaterinburg)

---

### CHECK_MD5

Igor Polunovskiy

Рекомендуется использовать [глобальный параметр FORCE_MD5](/ru/Global/#force_md5) `SAVE_ZMOD_DATA FORCE_MD5=1`

Проверить MD5 сумму.

- DELETE - удалять битый файл (yes)

1. Нужно подобрать и скачать к себе на компьютер файл для вашей архитектуры и операционной системы:

- [zmod_preprocess-windows-amd64.exe](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-windows-amd64.exe) - Windows
- [zmod_preprocess-linux-amd64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-linux-amd64) - Linux. Не забудьте выполнить ```chmod +x zmod_preprocess-linux-amd64```
- [zmod_preprocess-darwin-arm64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-darwin-arm64) - MacOS Intel. Не забудьте выполнить ```chmod +x zmod_preprocess-darwin-arm64```
- [zmod_preprocess-darwin-amd64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-darwin-amd64) - MacOS Silicon. Не забудьте выполнить ```chmod +x zmod_preprocess-darwin-amd64```
- [zmod-preprocess.py](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod-preprocess.py) - Универсальный Python. Не забудьте выполнить ```chmod +x zmod-preprocess.py```
- [zmod-preprocess.sh](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod-preprocess.sh) - Linux/MacOS Bash. Не забудьте выполнить ```chmod +x zmod-preprocess.sh```

2. В Orca нужно прописать. `Профиль процесса` -> `Прочее` -> `Скрипты пост обработки`.

Вот варианты добавления:

- ```"С:\путь_до_файла\zmod_preprocess-windows-amd64.exe";```
- ```"C:\python_folder\python.exe" "C:\Scripts\zmod-preprocess.py";```
- ```"/usr/bin/python3" "/home/user/zmod-preprocess.py";```
- ```"/home/user/zmod-preprocess.py";```
- ```"/home/user/zmod_preprocess-darwin-amd64";```
- ```"/home/user/zmod_preprocess-darwin-arm64";```
- ```"/home/user/zmod_preprocess-linux-amd64";```

Исходные файлы находятся тут: [https://github.com/ghzserg/zmod_preprocess](https://github.com/ghzserg/zmod_preprocess)

```
Остановка печати в случае несоответствия контрольной суммы с возможным удалением дефектного файла.

Автор не несет ответственности за любые ошибки или проблемы, а также за результаты, полученные при использовании этой информации.

Контрольная сумма записывается в начало файла с G-кодом. Если файл не содержит контрольной суммы, проверка файла макросом не осуществляется, и он сразу отправляется на печать.
Результат проверки выводится в консоль.

=========================================
1. На машине с Windows, где установлен слайсер.
  а) Скачиваем https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-windows-amd64.exe
  б) Добавляем в слайсер скрипт из пункта 1.а, 
     заменяя "disk:\patch\to\file\" на свой путь к данному скрипту:
    - для OrcaSlicer
      "Процесс"->"Прочее"->"Скрипты постобработки" 
    - для SuperSlicer и PrusaSlicer
      "Настройки печати"->"Выходные параметры"->"Скрипты постобработки"
    disk:\patch\to\file\zmod_preprocess-windows-amd64.exe;
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

Если не понимаете, как [восстановить конфиги и прошивку MCU](/ru/Native_FW/#installing-full-firmware-on-ad5x), не запускайте.

Если что-то пойдет не так, обратно только через [factory](/ru/Native_FW/).

---

### RESET_PASSWD

Сбросить пароль пользователя root на root

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

### SCREEN

Получить снимок экрана принтера

Снимок будет сохраненн в ```mod_data/screen.jpg```
