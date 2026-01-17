<h1 align="center">Zmod</h1>

*[Read in English](https://github.com/ghzserg/zmod/wiki/Zmod_en)*

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
  <th colspan="4"><p align="center"><strong>🔷 Zmod 🔷</strong></p></th>
</tr></thead>
<tbody>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Zmod_ru#camera_off">CAMERA_OFF</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Zmod_ru#camera_on">CAMERA_ON</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Zmod_ru#camera_restart">CAMERA_RESTART</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Zmod_ru#zflash">ZFLASH</a></td>
 </tr>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Zmod_ru#tar_config">TAR_CONFIG</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Zmod_ru#restore_tar_config">RESTORE_TAR_CONFIG</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Zmod_ru#start_zmod">START_ZMOD</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Zmod_ru#stop_zmod">STOP_ZMOD</a></td>
 </tr>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Zmod_ru#zssh_off">ZSSH_OFF</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Zmod_ru#zssh_on">ZSSH_ON</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Zmod_ru#zssh_reload">ZSSH_RELOAD</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Zmod_ru#zssh_restart">ZSSH_RESTART</a></td>
 </tr>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Zmod_ru#remove_zmod">REMOVE_ZMOD</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Zmod_ru#skip_zmod">SKIP_ZMOD</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Zmod_ru#zrestore">ZRESTORE</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Zmod_ru#zlink">ZLINK</a></td>
 </tr>
</tbody>
</table>

### CAMERA_ON

Использовать альтернативную реализацию камеры
- WIDTH - ширина изображения (640)
- HEIGHT - высота изображения (480)
- FPS - кадров в секунду (20)
- VIDEO - устройство видео (video0)
- FS - 1 включить ограничение размера кадря для кривых камер, 0 не включать (0)
- STREAMER - какой стример исппользовать (auto, mjpg_streamer, ustreamer)
- FORMAT - Формат изображения для ustreamer: YUYV, YVYU, UYVY, RGB565, RGB24, BGR24, MJPEG, JPEG; по умолчанию: MJPEG

*Отключите камеру на экране принтера, и только потом вызывайте макрос*

Чтобы включить камеру, нужно использовать ```CAMERA_ON VIDEO=video0``` или ```CAMERA_ON VIDEO=video3``` или ```CAMERA_ON VIDEO=video99```

<img width="734" height="221" alt="{D2A001DD-7C89-4AB9-9CB9-741B7007B0B4}" src="https://github.com/user-attachments/assets/e8ddbbd3-ebbf-4b4e-86cc-2a62365a4a88" />

Если камера не работает, то смотрите логи `mod_data/log/cam/`

Потребление оперативной памяти на  стоковой камере:
- 640x480 - 2.9 MiB
- 1280x720 -  7.8 MiB
- 1920x1080 - 18.1 MiB

*Многие камеры с Ali/Ozon/Wildberries всегда потребляют 18 MiB*

- [Что такое альтернативная камера?](https://github.com/ghzserg/zmod/wiki/FAQ#%D1%87%D1%82%D0%BE-%D1%82%D0%B0%D0%BA%D0%BE%D0%B5-%D0%B0%D0%BB%D1%8C%D1%82%D0%B5%D1%80%D0%BD%D0%B0%D1%82%D0%B8%D0%B2%D0%BD%D0%B0%D1%8F-%D0%BA%D0%B0%D0%BC%D0%B5%D1%80%D0%B0)
- [Я установил принтер, а ZMOD спрятал мою камеру! В Orca-FF я ее видел, а теперь она пропала!](https://github.com/ghzserg/zmod/wiki/FAQ#%D1%8F-%D1%83%D1%81%D1%82%D0%B0%D0%BD%D0%BE%D0%B2%D0%B8%D0%BB-%D0%BF%D1%80%D0%B8%D0%BD%D1%82%D0%B5%D1%80-%D0%B0-zmod-%D1%81%D0%BF%D1%80%D1%8F%D1%82%D0%B0%D0%BB-%D0%BC%D0%BE%D1%8E-%D0%BA%D0%B0%D0%BC%D0%B5%D1%80%D1%83-%D0%B2-orca-ff-%D1%8F-%D0%B5%D0%B5-%D0%B2%D0%B8%D0%B4%D0%B5%D0%BB-%D0%B0-%D1%82%D0%B5%D0%BF%D0%B5%D1%80%D1%8C-%D0%BE%D0%BD%D0%B0-%D0%BF%D1%80%D0%BE%D0%BF%D0%B0%D0%BB%D0%B0)

`Camera Off Waiting...` - эта надпись выводится, если поток камеры еще недоступен. Камера запускается после запуска Klipper - во время вывода информации о глобальных параметрах

#### Настройка камеры

**Основные параметры**

| Параметр | Что делает | Обычное значение |
|----------|------------|------------------|
| `WIDTH`  | Ширина картинки | 640 |
| `HEIGHT` | Высота картинки | 480 |
| `FPS`    | Сколько кадров в секунду | 20 |
| `VIDEO`  | Номер камеры | video0 |
| `FS`     | Исправлять проблемные камеры (1 — да, 0 — нет) | 0 |
| `STREAMER` | Программа для работы с камерой | auto |
| `FORMAT` | Формат картинки (только для ustreamer) | MJPEG |

**Что такое стример?**

Стример — это программа, которая берёт изображение с камеры и показывает его браузере.

**Доступно два варианта:**

- **mjpg_streamer** — простая программа, работает только с MJPG-камерами
- **ustreamer** — мощнее, но требует больше памяти, поддерживает разные камеры

Параметр `STREAMER=auto` сам выберет подходящий стример.

**Форматы изображения (только для ustreamer)**

Можно выбрать: YUYV, YVYU, UYVY, RGB565, RGB24, BGR24, MJPEG, JPEG.

По умолчанию используется MJPEG.

**Примеры команд**

Простой запуск камеры video0 через mjpg_streamer:
```
CAMERA_ON VIDEO=video0
```

Запуск камеры video0 через ustreamer с настройками:
```
CAMERA_ON VIDEO=video0 STREAMER=ustreamer FORMAT=YUYV WIDTH=640 HEIGHT=480
```

**Где смотреть изображение?**

Откройте в браузере: `http://ip_адрес_принтера:8080`

Там можно менять яркость, контрастность и другие настройки.

**Если есть проблемы**

Не видит камеру?
Запустите:
```
CAMERA_ON VIDEO=video99
```
Программа покажет список доступных камер.

**Логи (журналы ошибок)** лежат в папке: `log/cam/`

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#zmod)

</div>

---

### CAMERA_OFF

Отключить альтернативную реализацию камеры

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#zmod)

</div>

---

### CAMERA_RESTART

Перезапустить альтернативную реализацию камеры

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#zmod)

</div>

---

### REMOVE_ZMOD

Удалить zMod.

- FULL: 0 - оставить папку `/opt/config/mod_data`, 1 - удалить папку `/opt/config/mod_data` (0)

Внимаение! Отключите сами все плагины и перейдите на родной Klipper.

В папке `/opt/config/mod_data` хранятся настройки `zmod`, `fluidd`, `moonraker`, `mainsail`. 

Она не удаляется по умолчанию, т.к. часто люди по ошибке вызывают макрос `REMOVE_ZMOD`

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#zmod)

</div>

---

### SKIP_ZMOD

Перезагрузка в оригинальную систему. Без запуска zMod.

Отключаются файлы конфигурации ZMOD, Moonraker, Fluidd.

Внимаение! Отключите  сами все плагины и перейдите на родной Klipper

Остается работать: 
- Альтернативная камера 
- SSH

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#zmod)

</div>

---

### TAR_CONFIG

Сохраняет файлы конфигурации в архив. 

Скачать архив можно в 'Конфигурация' -> 'mod_data' -> config.tar.gz

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#zmod)

</div>

---

### RESTORE_TAR_CONFIG

Восстанавливает файлы конфигурации из архива `config.tar.gz`

Загрузить архив нужно в 'Конфигурация' -> 'mod_data' -> `config.tar.gz`

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#zmod)

</div>

---

### ZFLASH

Позволяет обновиться с флешки по сети.

Вставьте флешку в принтер, включите  принтер. 

Если вы работаете в режиме без родного экрана, то важно, чтобы флешка была вставлена в принтер в момент включения принтера.

Этот макрос посмотрит последний доступный релиз, скачает его на флешку, проверит MD5 сумму архива и после перезагрузки установит его.


<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#zmod)

</div>

---

### STOP_ZMOD

Выгрузить из памяти guppy, moonraker и fluidd/Mainsail. Телеграм бот тоже  перестанет работать

Параметры:
- GUPPY (0 - не выгружать, 1 - выгружать)
- MOONRAKER (0 - не выгружать, 1 - выгружать)
- HTTP (0 - не выгружать, 1 - выгружать)

Пример:
```
STOP_ZMOD GUPPY=1 MOONRAKER=0 HTTP=0
```

Если эту строку прописать в стартовый код, то после начала печати GUPPY будет выгружен из памяти

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#zmod)

</div>

---

### START_ZMOD

Включить обратно guppy, moonraker и fluidd/Mainsail после STOP_ZMOD.

Параметры:
- GUPPY (0 - не загружать, 1 - выгружать)
- MOONRAKER (0 - не загружать, 1 - выгружать)
- HTTP (0 - не загружать, 1 - выгружать)

Пример:
```
START_ZMOD GUPPY=1 MOONRAKER=0 HTTP=0
```

Если эту строку прописать в конечный код, то после окончания печати GUPPY будет запущен

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#zmod)

</div>

---

### ZSSH_ON

Включить перенаправление SSH
- SSH_SERVER - IP удаленного SSH сервера
- SSH_PORT - порт удаленного SSH сервера
- SSH_USER - имя  пользователя на удаленном сервере
- VIDEO_PORT - порт на удаленном сервере. который будет использоваться для видео (8080)
- MOON_PORT - порт на удаленном сервере. который будет использоваться для moonraker (7125)
- REMOTE_RUN - команда, которую нужно вызывать на удаленном сервере ("NONE"), для перезапуска телеграмм бота. Можно использовать скрипт [ff5m.sh](https://github.com/ghzserg/zmod_ff5m/blob/1.6/telegram/ff5m.sh)(лежит на принтере в папке `mod/telegram/`), записав его вот в таком виде `./ff5m.sh bot1`, где bot1 - каталог в котором  установлен бот.
Скрипт можно установить следующим образом (если вы не устанавливали бот одной командной)
```
su - tbot # сменить пользователя на пользователя под которым запускается сервис бота
wget --cache=off -q -O ff5m.sh https://raw.githubusercontent.com/ghzserg/zmod_ff5m/refs/heads/main/telegram/ff5m.sh
chmod +x ff5m.sh
```

Пример установки, вводить в консоли fluidd/mainsail:
```
ZSSH_ON SSH_SERVER=remote.server.ru SSH_PORT=22 SSH_USER=tbot VIDEO_PORT=8080 MOON_PORT=7125 REMOTE_RUN="./ff5m.sh bot1"
```

[Подробнее про работу телеграмм бота](https://github.com/ghzserg/zmod/wiki/Telegram_ru)

SSH запускается через 3 минуты  после  старта  klipper.

Также SSH автоматически перезапускается(если умер) в начале печати в макросе START_PRINT.

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#zmod)

</div>

---

### ZSSH_OFF

Выключить SSH клиента

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#zmod)

</div>

---

### ZSSH_RESTART

Перезапуск SSH клиента

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#zmod)

</div>

---

### ZSSH_RELOAD

Перезапуск SSH клиента, если он не запущен.

Этот макрос вызывается в начале печати в макросе START_PRINT.

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#zmod)

</div>

---

### ZRESTORE

Восстановить печать после сбоя электричества или ошибки принтера.

Восстановление печати активно, если родной экран отключен, т.к. на родном экране есть встроенная функция восстановления печати.

Чтобы работала функция восстановления **название файла для печати не должно начинаться с цифры**.


---
<div align="center">

[![Back](https://github.com/ghzserg/zmod/wiki/images/Back.svg)](https://github.com/ghzserg/zmod/wiki/System_ru)
[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#zmod)
[![Forward](https://github.com/ghzserg/zmod/wiki/images/Forward.svg)](https://github.com/ghzserg/zmod/wiki/Filament_ru)

</div>

---

### ZLINK

Подключить к облаку [zmod.link](https://zmod.link)

- Облако позволяет управлять принтером через Fluidd или Mainsail из любой точки.
- Потребление памяти на принтере возрастает на 1 мб.
- Данные передаются в облако с принтера с использованием шифрования.
- Доступ к облаку из любого места тоже использует шифрование.
- Пользователь видит только свои принтеры и не может подключиться к другим.
- Доступ к принтерам пользователя защищен логином и паролем

Как получить логин и пароль:
1. Подключиться к боту [@zmod_help_bot](https://t.me/zmod_help_bot)
2. Ввести команду ```cloud``` - если вы ранее регистрировались, то он сообщит вам ваш логин
3. Чтобы зарегистрировать пользователя с именем `test` введите: ```cloud register test```
4. Чтобы сбросить пароль введите: ```cloud reset_password```

Как подключиться к облаку [zmod.link](https://zmod.link):
1. Зайти на сайт [zmod.link](https://zmod.link/) и ввести логин и пароль
   
   <img width="547" height="615" alt="{264D6782-600F-4700-B9D2-0582F7427FD2}" src="https://github.com/user-attachments/assets/d8d3f51e-4fc7-4e1e-8fa7-dfc07ddbeab2" />
2. Нажмите кнопку "Добавить принтер"
   
   <img width="569" height="502" alt="image" src="https://github.com/user-attachments/assets/72346ee6-dde6-4736-80b1-2eb2927bf983" />
3. Открыть в соседней вкладке принтер и в консоль на принтере введите команду ```ZLINK```
   
   <img width="1563" height="163" alt="{90DC4366-D258-4912-8028-22C589DF4E91}" src="https://github.com/user-attachments/assets/bee350ee-8d99-465c-9621-48788c6f7a9c" />
4. Скопируйте ключ в буфер обмена - он выделен на скриншоте
5. Введите имя принтера и ключ, который скопировали на предыдущем шаге
   
   Пример:
   - `testprinter`
   - `ecdsa-sha2-nistp256 AAAAE2VjZHNhLXNoYTItbmlzdHAyNTYAAAAIbmlzdHAyNTYAAABBBDxX5XzNDXg+sbTArdiOzFpMtHXzgAhfC2N2ogS4TUsQYV4AD6HfSFL3J4ISNZ2DgesZf35rfH1I/qI2ckQVGlE=`
   
   <img width="557" height="775" alt="{E4FC2206-84BC-4134-92C2-B4253D8F23E5}" src="https://github.com/user-attachments/assets/b6401b71-5827-480d-ba1c-b7114f87177b" />
   
   Нажмите кнопку "Добавить принтер"
6. Скопируйте команду, которую выдал сайт и вставьте ее в консоль принтера
   
   <img width="558" height="652" alt="{CDC8146F-B9DF-44A1-9C0B-3E6828CD540E}" src="https://github.com/user-attachments/assets/ed92a80f-93cc-41b8-bde1-aa0b2b2c0ecc" />
   
   В примере ```zlink p=testprinter u=test m=10006 c=30006```

   Нажмите кнопку ```Я уже вставил строку в принтер```
   
   После этого принтер сможет подключаться к облаку.
   
   Чтобы запретить подключение, введите ```ZLINK_OFF```

7. Теперь у вас есть возможность подключаться к Fluidd или Mainsail через интернет
   
   <img width="526" height="654" alt="{CA6FC599-6060-4E3B-B525-EBB76D8780A1}" src="https://github.com/user-attachments/assets/0208dbad-8627-4636-b971-cfe0c5d7f8bd" />
   
   Достаточно выбрать нужную кнопку.

PS: Камера может прогрузиться позже, чем интерфейс - это нормально

PPS: Если что-то работает не так, то обновите страницу Ctrl + F5 и зайдите на [zmod.link](https://zmod.link)

   <img width="540" height="449" alt="{30D01CA4-3E9E-40EC-BCD1-9A8597DCCFDE}" src="https://github.com/user-attachments/assets/0d48b9be-a9df-4bfd-a38a-6d883ab31e73" />

   <img width="500" height="393" alt="{D03D643F-907C-4A6D-A48E-D881AAC33268}" src="https://github.com/user-attachments/assets/69f9d8d5-67ca-476e-b362-e35abb1d4832" />

---
<div align="center">

[![Back](https://github.com/ghzserg/zmod/wiki/images/Back.svg)](https://github.com/ghzserg/zmod/wiki/System_ru)
[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#zmod)
[![Forward](https://github.com/ghzserg/zmod/wiki/images/Forward.svg)](https://github.com/ghzserg/zmod/wiki/Filament_ru)

</div>
