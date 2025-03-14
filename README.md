# FF5M / FF5M Pro / AD5X ZMOD

> [!CAUTION]
> *Если вы хотите установить этот мод на свой AD5M (Pro), то имейте в виду, что вы рискуете потерять гарантию или повредить принтер. Действуйте на свой страх и риск, если хотите попробовать этот мод!*
> 
> Если вы не знаете что это такое, не понимаете зачем нужна веб страница klipper или просто довольны стоком, не устанавливайте эту модификацию, для всех остальных - **пожалуйста прочтите полностью инструкцию**!
>
> Поставили мод. Ни хотите ни в чем разбираться - печатаете как и печатали. Вообще ничего нигде настраивать и менять не надо. Решили, что готовы двигаться дальше - двигаетесь - читая документацию.

Последняя версия: **1.4.1** ставится только с флешки.

[Скачать](https://github.com/ghzserg/zmod/releases/).

MD5 сумма `41c286d39d369b6a6f69bb7ff5786cab  Adventurer5M-zmod-1.4.1.tgz`

Как проверить:
- перейти в папку где лежит файл Adventurer5MPro-zmod-1.1.0.tgz
- Правой кнопкой мыши по свободному месту -> `Открыть в терминале`
- `certutil -hashfile Adventurer5M-zmod-1.4.0.tgz md5`
- Сумма должна совпасть

Ставится на чистую версию **не ниже 2.7.5** (2.7.5, 2.7.6, 2.7.7, 2.7.8, 2.7.9, 3.1.3, 3.1.4, 3.1.5)

Чистая версия лежит в папке [Родная_прошивка](https://github.com/ghzserg/zmod/tree/main/%D0%A0%D0%BE%D0%B4%D0%BD%D0%B0%D1%8F_%D0%BF%D1%80%D0%BE%D1%88%D0%B8%D0%B2%D0%BA%D0%B0)

## Не нужно ставить мод, если вам достаточно исправить следующие проблемы на родной прошивке

Эти функции портированы на стандартную прошивку:
1. Исправление ошибки [E0011](https://github.com/ghzserg/zmod/wiki/Macros#fix_e0011)
2. Исправление ошибки [E0017](https://github.com/ghzserg/zmod/wiki/Macros#fix_e0017)
3. [Отключение обновлений принтера/телеметрии/китайских облаков](https://github.com/ghzserg/zmod/wiki/Macros#china_cloud)
4. [Возврат принтера к заводским установкам](https://github.com/ghzserg/zmod/wiki/Setup#%D0%B2%D0%BE%D0%B7%D0%B2%D1%80%D0%B0%D1%82-%D0%BF%D1%80%D0%B8%D0%BD%D1%82%D0%B5%D1%80%D0%B0-%D0%BA-%D0%B7%D0%B0%D0%B2%D0%BE%D0%B4%D1%81%D0%BA%D0%B8%D0%BC-%D1%83%D1%81%D1%82%D0%B0%D0%BD%D0%BE%D0%B2%D0%BA%D0%B0%D0%BC-%D0%BD%D0%B5%D0%BE%D0%B1%D1%85%D0%BE%D0%B4%D0%B8%D0%BC%D0%BE-%D0%B4%D0%BB%D1%8F-%D1%83%D1%81%D1%82%D0%B0%D0%BD%D0%BE%D0%B2%D0%BA%D0%B8-%D0%BC%D0%BE%D0%B4%D0%B0)
5. [Перешивка FF5M в FF5MPro](https://github.com/ghzserg/zmod/tree/main/%D0%A0%D0%BE%D0%B4%D0%BD%D0%B0%D1%8F_%D0%BF%D1%80%D0%BE%D1%88%D0%B8%D0%B2%D0%BA%D0%B0/5m2Pro)
6. [Перешивка FF5MPro в FF5M](https://github.com/ghzserg/zmod/tree/main/%D0%A0%D0%BE%D0%B4%D0%BD%D0%B0%D1%8F_%D0%BF%D1%80%D0%BE%D1%88%D0%B8%D0%B2%D0%BA%D0%B0/Pro25M)

## Поддержка Moonraker и Fluidd/Mainsaill/GuppyScreen на родном Клиппере
Поддерживаемые функции:
1. Веб интрефейс на базе [Fluidd](https://docs.fluidd.xyz/) или [Mainsail](https://docs.mainsail.xyz/) (порт 80)
2. Загрузка и печать файлов через Octoprinter/Fluidd/FlashForge/Mainsail/[GuppyScreen](https://github.com/ghzserg/zmod/wiki/Macros#display_off)/[Telegram Bot](https://github.com/ghzserg/zmod/wiki/Macros#telegram-bot)
3. [Восстановление печати при отключении электричества](https://github.com/ghzserg/zmod/wiki/Macros#zrestore)
4. Адаптивное снятие карты стола [KAMP](https://github.com/ghzserg/zmod/wiki/Macros#kamp)
5. [Калибровка стола](https://github.com/ghzserg/zmod/wiki/Macros#auto_full_bed_level) при любой температуре и возможен запуск при начале печати
6. [Снятие шейперов c генерацией графиков](https://github.com/ghzserg/zmod/wiki/Macros#zshaper) с учетом [SCV](https://github.com/ghzserg/zmod/wiki/Macros#fix_scv) ([square_corner_velocity](https://www.klipper3d.org/Config_Reference.html#printer)).
7. [Регулировка винтов стола](https://github.com/ghzserg/zmod/wiki/Macros#bed_level_screws_tune)
8. Калибровка PID [экструдера](https://github.com/ghzserg/zmod/wiki/Macros#pid_tune_extruder) и [стола](https://github.com/ghzserg/zmod/wiki/Macros#pid_tune_bed).
9. [Чистка сопла, как в родной прошивке](https://github.com/ghzserg/zmod/wiki/Macros#clear_noize)
10. Работа как с родной так и с [альтернативной реализацией камеры](https://github.com/ghzserg/zmod/wiki/Macros#camera_on) (экономит память и позволяет менять разрешение камеры.)
11. Поддержка moonraker-telegram-bot на [внешнем хосте](https://github.com/ghzserg/zmod/wiki/Macros#telegram-bot)
12. [Воспроизведение MIDI файлов](https://github.com/ghzserg/zmod/wiki/Macros#play_midi)
13. [Контроль MD5](https://github.com/ghzserg/zmod/wiki/Macros#check_md5), при передаче файла по сети 
14. Автоматическое обновление `Fluidd`/`Mainsail`/`Moonraker` и ZMOD по сети
15. Работа в [режиме без родного экрана](https://github.com/ghzserg/zmod/wiki/Macros#display_off). Экономит 20 мегабайт оперативной памяти.
16. [GuppyScreen](https://github.com/ghzserg/zmod/wiki/Macros#display_off) - как легковесная замена родного экрана
17. Поддержа ROOT и mc
18. Реализован [COLDPULL/Колдпул](https://github.com/ghzserg/zmod/wiki/Macros#coldpull) (очистка сопла) без насилия. Реализация [этого алгоритма](https://t.me/FF_5M_5M_Pro/2836/447172)
19. [Entware](https://github.com/ghzserg/zmod/wiki/FAQ#%D0%B2-zmod-%D0%B2%D1%85%D0%BE%D0%B4%D0%B8%D1%82-entware---%D0%BA%D0%B0%D0%BA-%D0%B8%D0%BC-%D0%B2%D0%BE%D1%81%D0%BF%D0%BE%D0%BB%D1%8C%D0%B7%D0%BE%D0%B2%D0%B0%D1%82%D1%8C%D1%81%D1%8F)
20. Исправлена ошибка [E0011](https://github.com/ghzserg/zmod/wiki/Macros#fix_e0011)
21. Исправлена ошибка [E0017](https://github.com/ghzserg/zmod/wiki/Macros#fix_e0017)
22. [Поддержка отката из прошивки](https://github.com/ghzserg/zmod/wiki/FAQ#%D1%87%D1%82%D0%BE-%D1%82%D0%B0%D0%BA%D0%BE%D0%B5-%D0%BE%D1%82%D0%BA%D0%B0%D1%82-%D0%B8%D0%B7-%D0%BF%D1%80%D0%BE%D1%88%D0%B8%D0%B2%D0%BA%D0%B8)
23. [Автоматическая остановка печати при отрыве детали или ударе сопла о стол](https://github.com/ghzserg/zmod/wiki/Macros#nozzle_control).
24. [Проверка и восстановление файлов/прав/символических ссылок родной файловой системы](https://github.com/ghzserg/zmod/wiki/Macros#check_system)
25. Функционал родного экранного меню не изменен

## История версий
[История версий](https://github.com/ghzserg/zmod/wiki/Changelog)

## Частые вопросы

[Обязательно к прочтению](https://github.com/ghzserg/zmod/wiki/FAQ)

## Рекомендации по повышению стабильности работы принтера

[Читать - если что-то работает не так](https://github.com/ghzserg/zmod/wiki/Recomendations)

## Список Макросов

Весь функционал работает через макросы

[Список Макросов](https://github.com/ghzserg/zmod/wiki/Macros)

## Хранение настроек
Доступ к папке **mod_data** через веб интерфейс fluidd. 

`Конфигурация` -> `Файлы конфигурации` -> `mod_data`

- Пользовательские настройки klipper необходимо вносить в файл `mod_data/user.cfg`, настройки записанные в это файл могут заменять/дополнять настройки из `printer_base.cfg`
- Пользовательские настройки moonraker необходимо вносить в файл `mod_data/user.moonraker.cfg`
- Пользовательские мелодии хранятся в `mod_data/midi/`
- Глобальные настройки мода хранятся через макрос [SAVE_ZMOD_DATA](https://github.com/ghzserg/zmod/wiki/Macros#save_zmod_data) *нюхлер*
- Код исполняемый при выключении принтера  хранится тут `mod_data/power_off.sh`

## Известные особенности:
- Если принтер выполняет какието действия `M109` (прогрев экструдера), `M190`(прогрев стола), калибровку PID - в общем любое действие, которое заставляет приостановится gcod, то родной экран замирает
- Если перезапускается klipper, то родной экран замерзает (используйте перезапуск через [NEW_SAVE_CONFIG](https://github.com/ghzserg/zmod/wiki/Macros#new_save_config))
- После отмены печати, на родном экране надо нажать кнопку Ок (используйте макрос [CLOSE_DIALOGS](https://github.com/ghzserg/zmod/wiki/Macros#close_dialogs) или [FAST_CLOSE_DIALOGS](https://github.com/ghzserg/zmod/wiki/Macros#fast_close_dialogs))
- Родной экран при загрузки печати всегда грузит профиль `DEFAULT_MESH` и после окончания печати всегда удаляет профиль `Default`

## Особености версии без экрана
- Необходимо удалить весь стартовый gcode и прописать [START_PRINT](https://github.com/ghzserg/zmod/wiki/Macros#start_print), а в конечный [END_PRINT](https://github.com/ghzserg/zmod/wiki/Macros#end_print)
- Не работает камера, необходимо запустить альтернативную камеру через макрос [CAMERA_ON](https://github.com/ghzserg/zmod/wiki/Macros#camera_on)
- При необходимости, надо вручную прописать параметр [Z_OFFSET](https://github.com/ghzserg/zmod/wiki/Macros#%D1%8D%D1%82%D0%BE-%D0%BD%D0%B5-%D0%BF%D0%B0%D1%80%D0%B0%D0%BC%D0%B5%D1%82%D1%80%D1%8B-start_print-%D1%8D%D1%82%D0%BE-%D0%B3%D0%BB%D0%BE%D0%B1%D0%B0%D0%BB%D1%8C%D0%BD%D1%8B%D0%B5-%D1%84%D0%BB%D0%B0%D0%B3%D0%B8%D0%BF%D0%B0%D1%80%D0%B0%D0%BC%D0%B5%D1%82%D1%80%D1%8B-%D0%BA%D0%BE%D1%82%D0%BE%D1%80%D1%8B%D0%B5-%D1%81%D1%82%D0%B0%D0%B2%D0%B8%D1%82%D1%81%D1%8F-%D1%87%D0%B5%D1%80%D0%B5%D0%B7-save_zmod_data) в макросе [START_PRINT](https://github.com/ghzserg/zmod/wiki/Macros#start_print) или использовать глобальный параметр [LOAD_ZOFFSET](https://github.com/ghzserg/zmod/wiki/Macros#load_zoffset) который загружает Z-offset из глобальных параметров, сохраненных ранее через SET_GCODE_OFFSET. *крот*
- При включении принтера автоматически загружается карта стола `auto`
- Не работает отправка через протокол FlashForge, т.к. его обрабатывает экран.
  Необходимо переключиться на протокол "Octo/Klipper":
  - Протокол: `Octo/Klipper`
  - Имя хоста: `IP_принтера:7125`
  - Url-адрес хоста: `IP_принтера`
 
## Используемые дополнения

- Root основан на реализации [@darksimpson](https://t.me/darksimpson). Логин и пароль: root. [Ссылка](https://t.me/c/2000598629/12695/186253)
- Beeper основан на реализации [@drmax_gc](https://t.me/drmax_gc). M300. M356 fur Elise. [Ссылка](https://t.me/FF_5M_5M_Pro/1/333800)
- Включена проверка md5 от Igor Polunovskiy. [Ссылка](https://t.me/FF_5M_5M_Pro/12695/272417)

Мод во многом основывался на 
- [KlipperMod](https://github.com/xblax/flashforge_ad5m_klipper_mod/)
- [GuppyScreen](https://github.com/ballaswag/guppyscreen)

## Установка/Обновление/Удаление мода

[Установка/Обновление/Удаление мода](https://github.com/ghzserg/zmod/wiki/Setup)

## Помочь разработке

[На развитие мода](https://vtb.paymo.ru/collect-money/?transaction=f274b4b2-cc14-4164-ae60-ca0f7c384f0a)

[[/images/VTB.jpg]]
