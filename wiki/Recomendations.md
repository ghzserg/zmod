# Recomendations
## Рекомендации по повышению стабильности работы принтера

Рекомендации подходят как к родной прошивке так и к ZMOD

| | |
|--------|--------|
| [Включите исключение моделей](#включите-исключение-моделей) | [Установите последнее обновление родной прошивки и ZMOD](#установите-последнее-обновление-родной-прошивки-и-zmod) |
| [Замените Спиральный/Автоматич. Z-Hop](#замените-cпиральныйавтоматич-z-hop) | [Отключите "Аппроксимация дугами" (arc_move)](#отключите-аппроксимация-дугами-arc_move) |
| [Отключите китайские облака](#отключите-китайские-облака) | [Включите контроль удара сопла о стол](#включите-контроль-удара-сопла-о-стол) |
| [Lan mode error](#lan-mode-error) | [Включите контроль MD5](#включите--контроль-md5) |
| [Отправляйте файлы на печать через "Octo/Klipper"](#отправляйте-файлы-на--печать-через-octoklipper) | [Проверьте корректность файлов родной операционной системы](#проверьте-корректность-файлов-родной-операционной-системы) |
| [Включите fix ошибки E0017](#включите-fix-ошибки-e0017) | [Включите fix ошибки E0011](#включите-fix-ошибки-e0011) |

---

### Включите исключение моделей

Включите исключение моделей в Orca:
- `Профиль процесса` -> `Прочее` -> `Выходной G-cod` -> `Исключение моделей` включить галочку
- `Профиль процесса` -> `Прочее` -> `Выходной G-cod` -> `Помечать модели` включить галочку

<img width="285" height="171" alt="image" src="https://github.com/user-attachments/assets/faceef98-2791-4975-bf72-425f4a2b1dfa" />

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#recomendations)

</div>

---

### Установите последнее обновление родной прошивки и ZMOD

Ведется поддержка только последней версии мода.

У автора  нет ресурсов поддерживать все версии, поэтому [установите последнее обновление родной прошивки и ZMODа](https://github.com/ghzserg/zmod/wiki/Setup)

### Замените Cпиральный/Автоматич. Z-Hop.

Принтер его не поддерживает. 

В Orca. `Профиль принтера` -> `Экструдер 1` -> `Тип подъема оси Z`. Установите `Обычный` или `Наклонный`.

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#recomendations)

</div>

---

### Отключите "Аппроксимация дугами" (arc_move). 

Принтер их поддерживает, но они снижают качество печати и периодически приводят к ошибкам принтера.

В Orca. `Профиль процесса` -> `Качество` -> `Точность` -> `"Аппроксимация дугами"` снять галочку.

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#recomendations)

</div>

---

### Отключите  на экране  принтера  встроенную камеру.

Она ест больше  памяти и качество изображения плохое. 

Используйте альтернативную камеру. 

На экране  принтера. `Настройки` -> `Вкладка камера` -> Убрать галочку `"Камера"` и `"Видео"`. 

Потом выполнить макрос [CAMERA_ON](https://github.com/ghzserg/zmod/wiki/Zmod_ru#camera_on)

- [Что такое альтернативная камера?](https://github.com/ghzserg/zmod/wiki/FAQ#%D1%87%D1%82%D0%BE-%D1%82%D0%B0%D0%BA%D0%BE%D0%B5-%D0%B0%D0%BB%D1%8C%D1%82%D0%B5%D1%80%D0%BD%D0%B0%D1%82%D0%B8%D0%B2%D0%BD%D0%B0%D1%8F-%D0%BA%D0%B0%D0%BC%D0%B5%D1%80%D0%B0)
- [Я установил принтер, а ZMOD спрятал мою камеру! В Orca-FF я ее видел, а теперь она пропала!](https://github.com/ghzserg/zmod/wiki/FAQ#%D1%8F-%D1%83%D1%81%D1%82%D0%B0%D0%BD%D0%BE%D0%B2%D0%B8%D0%BB-%D0%BF%D1%80%D0%B8%D0%BD%D1%82%D0%B5%D1%80-%D0%B0-zmod-%D1%81%D0%BF%D1%80%D1%8F%D1%82%D0%B0%D0%BB-%D0%BC%D0%BE%D1%8E-%D0%BA%D0%B0%D0%BC%D0%B5%D1%80%D1%83-%D0%B2-orca-ff-%D1%8F-%D0%B5%D0%B5-%D0%B2%D0%B8%D0%B4%D0%B5%D0%BB-%D0%B0-%D1%82%D0%B5%D0%BF%D0%B5%D1%80%D1%8C-%D0%BE%D0%BD%D0%B0-%D0%BF%D1%80%D0%BE%D0%BF%D0%B0%D0%BB%D0%B0)

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#recomendations)

</div>

---

### Отключите китайские облака.

### Lan mode error

Отключите китайские облака, т.к. они работают нестабильно и периодически отваливаются.
После восстановления связи забивают накопившимися запросами принтер, что приводит к ошибкам.

Также при работе китайских облаков не работает печать с родного экрана со снятием стола и быстрое закрытие окон.

На экране  принтера.

`Настройки` -> `Вкладка WiFi` -> `Сетевой режим` -> Включить `"Только локальные сети"`. 

Отключение китайских облаков позволяет быстро закрывать окно с надписью "Ok" после печати, печать со снятием карты стола с использованием алгоритма из родного экрана.

`Настройки` -> `Вкладка облако` -> Выключить `"FlashCloud"` и `"Polar3d"`.

Вместо этого можно использовать:
- [zmod.link](https://github.com/ghzserg/zmod/wiki/Zmod_ru#zlink) - облако, для управления принтерами через Fluidd/Mainsail.
- [Телеграм бот](https://github.com/ghzserg/zmod/wiki/Macros).

[Еще про китайские облака](https://github.com/ghzserg/zmod/wiki/Global_ru#china_cloud).

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#recomendations)

</div>

---

### Включите  контроль [MD5]

Igor Polunovskiy

[CHECK_MD5](https://github.com/ghzserg/zmod/wiki/System_ru#check_md5)

Рекомендуется использовать [глобальный параметр FORCE_MD5](https://github.com/ghzserg/zmod/wiki/Global_ru#force_md5) `SAVE_ZMOD_DATA FORCE_MD5=1`

*Пропишите в скрипты постобработки вызов [addMD5.bat](https://github.com/ghzserg/FF/releases/download/R/addMD5.bat) или
[addMD5.sh](https://github.com/ghzserg/FF/releases/download/R/addMD5.sh) для Mac/Linux*(не забудьте добавить право исполнения на файл `chmod +x addMD5.sh`) или
[addMD5.py](https://github.com/ghzserg/FF/releases/download/R/addMD5.py) он лежит в mod. [Подробнее](https://github.com/ghzserg/zmod/wiki/System_ru#check_md5)*

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

<img width="472" height="549" alt="image" src="https://github.com/user-attachments/assets/b330fa6f-fffd-4b0d-95b0-4e879eabd0d3" />

Если в пути есть пробелы то надо заключить полный путь в кавычки, но лучше не использовать пробелы в папках

```"С:\путь до файла\addMD5.bat";```

<img width="307" height="131" alt="image" src="https://github.com/user-attachments/assets/c90c096e-ff42-4479-b094-9d57261e7f36" />

[Подробнее](https://github.com/ghzserg/zmod/wiki/System_ru#check_md5)

*хомячёк*

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#recomendations)

</div>

---

### Отправляйте файлы на  печать через "Octo/Klipper".

Родной протокол FF периодически передает битые файлы, а также не генерирует картинки и метаданные для Телеграм бота.

В Orca. Щелкнуть по значку Wifi рядом с принтером:
- Протокол: `Octo/Klipper`
- Имя хоста: `IP_принтера:7125`
- Url-адрес хоста: `IP_принтера` или `IP_принтера:80`

Если используется Mainsail, то пропишите только эти размеры миниатюр: ```140x110/PNG, 64x64/PNG```

В Orca `Профиль принтера` -> `Общая информация` -> `Дополнительно` -> `Эскизы G-кода`

Учтите, что родной экран перестанет показывать миниатюры.

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#recomendations)

</div>

---

### Включите fix ошибки E0017

[E0017](https://github.com/ghzserg/zmod/wiki/Global_ru#fix_e0017)

По умолчанию он уже включен

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#recomendations)

</div>

---

### Включите fix ошибки E0011

Должно исправлять `E0011` и `Communication timeout during homing`

[E0011](https://github.com/ghzserg/zmod/wiki/Global_ru#fix_e0011)

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#recomendations)

</div>

---

### Проверьте корректность файлов родной операционной системы

Из-за отсутствия в прошивке корректного отключения принтера, файловая система может повреждаться.

Что в конечном итоге приводит к череде  мелких или крупных багов.

Макрос [CHECK_SYSTEM](https://github.com/ghzserg/zmod/wiki/System_ru#check_system) проверяет MD5 сумму файлов и указывает, какие были повреждены.

Также он проверяет корректность символических ссылок и при необходимости  автоматически исправляет их.

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#recomendations)

</div>

---

### Включите контроль удара сопла о стол.

Контроль по умолчанию отключен.

Включается макросом [NOZZLE_CONTROL](https://github.com/ghzserg/zmod/wiki/Global_ru#nozzle_control)

`NOZZLE_CONTROL WEIGHT=0`

Контроль, выключит Klipper, в случае если сопло начнет царапать пластину или оторвётся деталь от стола.

Особенно рекомендуется включать контроль, тем кто использует предочистку сопла.

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#recomendations)

</div>

---
