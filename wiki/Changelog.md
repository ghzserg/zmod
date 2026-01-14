# Changelog
- [История версий](#история-версий)
  - [Версия 1.6.5](#версия-165)
  - [Версия 1.6.4](#версия-164)
  - [Версия 1.6.3](#версия-163)
  - [Версия 1.6.2](#версия-162)
  - [Версия 1.6.1](#версия-161)
  - [Версия 1.6.0](#версия-160)
  - [Версия 1.5.4](#версия-154)
  - [Версия 1.5.3](#версия-153)
  - [Версия 1.5.2](#версия-152)
  - [Версия 1.5.1](#версия-151)
  - [Версия 1.5.0](#версия-150)
  - [Версия 1.4.3](#версия-143)
  - [Версия 1.4.2](#версия-142)
  - [Версия 1.4.1](#версия-141)
  - [Версия 1.4.0](#версия-140)
  - [Версия 1.3.1](#версия-131)
  - [Версия 1.3.0](#версия-130)
  - [Версия 1.1.2](#версия-112)
  - [Версия 1.1.0](#версия-110)
  - [Версия 1.0.5](#версия-105)
  - [Версия 1.0.4](#версия-104)
  - [Версия 1.0.0](#версия-100)
  - [Версия 0.2.4](#версия-024)
  - [Версия 0.2.3](#версия-023)
  - [Версия 0.2.2](#версия-022)
  - [Версия 0.2.1.1](#версия-0211)
  - [Версия 0.2.1](#версия-021)
  - [Версия 0.2.0](#версия-020)
  - [Версия 0.1.8](#версия-018)
  - [Версия 0.1.7](#версия-017)
  - [Версия 0.1.6](#версия-016)
  - [Версия 0.1.5](#версия-015)
  - [Версия 0.1.4](#версия-014)
  - [Версия 0.1.3](#версия-013)
  - [Версия 0.1.1](#версия-011)
  - [Версия 0.0.9-fix](#версия-009-fix)
  - [Версия 0.0.9](#версия-009)

## История версий

### Версия 1.6.5
14.01.2026
* Обновлен Fluidd/Mainsail/Klipper
* Доступны дополнительные настройки камеры
* Автоподбор Z-Offset

### Версия 1.6.4
11.12.2025
* Повышено удобство настройки и использования
* Обновлен Fluidd/Mainsail/Klipper
* Плагин уведомлений
* Убран треск IFS

### Версия 1.6.3
25.11.2025 - Год моду
* [@zmod_help_bot](http://t.me/zmod_help_bot)
* [zmod.link](https://zmod.link) [ZLINK](https://github.com/ghzserg/zmod/wiki/Zmod_ru#zlink) - удаленное подключение к принтеру через облако
* Макрос [SCREEN](https://github.com/ghzserg/zmod/wiki/System_ru#screen) получить снимок экрана принтера
* Макрос [LOAD_ZOFFSET_NATIVE](https://github.com/ghzserg/zmod/wiki/Calibrations_en#load_zoffset_native) - перенести настройки z-offset с родного экрана в режим без экрана
* [AD5X](https://github.com/ghzserg/zmod/wiki/AD5X): Добавлен глобальный параметр [REMOVE_FILAMENT](https://github.com/ghzserg/zmod/wiki/Global_ru#remove_filament) - извлечь филамент после печати
* Добавлен [плагин рекомендуемых настроек](https://github.com/ghzserg/recommend)
* Добавлен чешский язык
* Добавлен контроль версии MCU для Klipper 13
* [AD5X](https://github.com/ghzserg/zmod/wiki/AD5X): Добавлена кнопка левелинга
* [AD5X](https://github.com/ghzserg/zmod/wiki/AD5X): Исправления для Klipper 13
* [AD5X](https://github.com/ghzserg/zmod/wiki/AD5X): Исправление чистки сопла
* [AD5X](https://github.com/ghzserg/zmod/wiki/AD5X): Убран хруст IFS
* ```CAMERA_ON VIDEO=video99``` - тест всех доступных камер
* Проверка обновлений после окончания печати
* При снятии стола через Fluidd/Mainsail сбрасываются тензы. Но пользователь сам должен очищать сопло и прогревать заранее стол.
* Исправление PURGE_LINE, не печтает по поддержкам
* Исправлен удар о край при повторной печати
* Исправлены весы, когда  они показывают несколько тонн
* Исправлено отключение chamber_fan после окончания печати
* Исправлено отображение оставшегося времени в гуппи для не русского языка

### Версия 1.6.2
27.10.2025
* [Поддержка плагинов](https://github.com/ghzserg/g28_tenz/blob/main/Plugin_ru.md)
* [Плагин g28_tenz](https://github.com/ghzserg/g28_tenz) - Парковка оси Z по тензодатчикам
* [Плагин bambufy](https://github.com/function3d/bambufy) - Совместим с Bambu Studio и Orca Slicer, улучшает управление башней подачи, обеспечивает точную оценку времени и расхода материала, снижает отходы, поддерживает быструю смену цвета и расширенные функции печати. От @function3d
* [Плагин nopoop](https://github.com/ghzserg/nopoop) - Максимальное уменьшение количества отходов от @ninjamida
* Fluidd: Поддержка цвета
* Mainsail: Поддержка цвета От @function3d, исправлена проблема 404 ошибки после обновления страницы
* Guppy: Поддержка цвета. Исправлена интеграция с HA.
* Добавлено автоподключение флешек при работе с Guppy
* Добавлено включение [WiFi](https://github.com/ghzserg/zmod/wiki/Global_ru#wifi) напрямую без использования родного экрана
* [AD5X](https://github.com/ghzserg/zmod/wiki/AD5X): Решена проблема с корзиной и отрезанием филамента в новых ревизиях
* [AD5X](https://github.com/ghzserg/zmod/wiki/AD5X): Поддержка цвета при восстановлении печати
* [AD5X](https://github.com/ghzserg/zmod/wiki/AD5X): Возможность создавать [свои типы филамента и цвета](https://github.com/ghzserg/zmod/wiki/AD5X#7-%D0%B4%D0%BE%D0%B1%D0%B0%D0%B2%D0%B8%D1%82%D1%8C-%D1%81%D0%B2%D0%BE%D0%B8-%D1%82%D0%B8%D0%BF%D1%8B-%D1%84%D0%B8%D0%BB%D0%B0%D0%BC%D0%B5%D0%BD%D1%82%D0%B0) при работе без родного экрана
* Обновлен Klipper и Monnraker
* Добавлена поддержка ens160.py от @minicx
* Добавлен португальский язык
* Исправлены ошибки
* Повышена совместимость с последними версиями родной прошивки

### Версия 1.6.1
06.09.2025
- [AD5X](https://github.com/ghzserg/zmod/wiki/AD5X) - Поддержка Klipper 13. [UPDATE_MCU](https://github.com/ghzserg/zmod/wiki/System_ru#update_mcu)
- [AD5X](https://github.com/ghzserg/zmod/wiki/AD5X) - Датчик температуры в голове
- [AD5X](https://github.com/ghzserg/zmod/wiki/AD5X) - Работа без родного экрана. IFS работает полноценно с настройкой количества сброса
- Мелкие фиксы

### Версия 1.6.0
14.08.2025
- AD5M - Поддержка Klipper 13. [UPDATE_MCU](https://github.com/ghzserg/zmod/wiki/System_ru#update_mcu)
- AD5M - Датчик температуры в голове
- Мелкие фиксы

За поддержку MCU спасибо [@darksimpson](https://github.com/darksimpson)

За поддержку тенз спасибо [@minicx](https://github.com/loss-and-quick/)

### Версия 1.5.4
28.06.2025
- AD5X - работает звук
- AD5X - работают тензодатчики и контроль удара сопла о стол
- AD5X - работает телеграм бот
- AD5X - работает датчик наличия филамента
- AD5X - работает установка PID стола принетра
- AD5X - восстановлена очистка сопла при снятии карты стола
- AD5X - протестирована работа  мода на прошивках 1.0.9, 1.1.0, 1.1.1
- AD5X - создана [флешка устанавливающая экран версии 1.0.7, а все остальные модули версии 1.1.1](https://github.com/ghzserg/zmod/wiki/R)
- AD5x - создана [флешка возврата принтера к заводским настройкам](https://github.com/ghzserg/zmod/wiki/R)
- AD5X - создана [флешка активации мода, после обновления родной прошивки](https://github.com/ghzserg/zmod/wiki/R)

### Версия 1.5.3
03.06.2025
* Исправлена ошибка Klipper [#119](https://github.com/ghzserg/zmod/issues/119), из-за которой нужно было использовать [это](https://github.com/ghzserg/zmod/wiki/Recomendations#%D0%BD%D0%B5-%D0%B8%D1%81%D0%BF%D0%BE%D0%BB%D1%8C%D0%B7%D1%83%D0%B9%D1%82%D0%B5-%D1%80%D1%83%D1%81%D1%81%D0%BA%D0%B8%D0%B5-%D0%B8%D0%BC%D0%B5%D0%BD%D0%B0-%D0%B2-%D0%BD%D0%B0%D0%B7%D0%B2%D0%B0%D0%BD%D0%B8%D1%8F%D1%85-%D0%BE%D0%B1%D1%8A%D0%B5%D0%BA%D1%82%D0%BE%D0%B2)
* Контроль сопла теперь включается и при печати с экрана сразу
* Мелкие косметические фиксы

### Версия 1.5.2
15.05.2025
* Обновление структуры документации спасибо @TMTYD
* Новый макрос RESTORE_TAR_CONFIG
* Исправление отображения в Guppy
* **AD5X** исправление ошибок HOME
* Обновление moonraker
* Изменение ускорения при парковке
* По умолчанию включены китайские облака

### Версия 1.5.1
23.04.2025
- **AD5X**: поддержка прошивки AD5X-1.0.8-1.0.5-20250418
- **AD5X**: исправление _LINE_PURGE
- **AD5X**: поддержка обновления MCU IFS
- **AD5X**: исправление MESH_TEST 
- **AD5X**: исправление _SMART_PARK
- **AD5X**: исправление driver_fan
- **AD5X**: исправление _HOME
- Косметические исправления CHECK_MD5
- Возврат chamber_fan в Moonraker
- Исправление исключения объектов
- Исправление guppyscreen для разных языков

### Версия 1.5.0
17.04.2025
Поддержка языков интерфейса:
- ZMOD - английский, немецкий, французский, итальянский, испанский, китайский, японский, корейский
- GuppyScreen - английский, немецкий, французский, итальянский, испанский

### Версия 1.4.3
23.03.2025
- Автоматическая настройка веб камеры
- При смене WEB интерфейса выводится сообщение
- 5X. Исправлена ошибка быстрого закрытия диалогов
- 5X. Исправлена парковка
- Исправлена проблема с выключением экрана на новых ревизиях принтера

### Версия 1.4.2
19.03.2025
- Доработан функционал [контроля удара  сопла о стол](https://github.com/ghzserg/zmod/wiki/Global_ru#nozzle_control), теперь можно [использовать паузу](https://github.com/ghzserg/zmod/wiki/Global_ru#nozzle_control) вместо завершения работы. Задача [#23](https://github.com/ghzserg/zmod/issues/23)
- Улучшена функция проверки системы.
- Изменена цветовая схема Fluidd
- Добавлен глобальный параметр [SAVE_MOONRAKER](https://github.com/ghzserg/zmod/wiki/Macros#save_moonraker) - разрешает использовать пользовательсткое расположение кнопок макросов
- В AD5X работает GuppyScreen
- В AD5X новый макрос [COLOR](https://github.com/ghzserg/zmod/wiki/Filament_ru#color) Управление типом пластика, цветом пластика, загрузкой и выгрузкой филамента из цветных катушек.
- Изменен алгоритм тестирования стола  перед печатью, введен новый глобальный параметр [MESH_TEST](https://github.com/ghzserg/zmod/wiki/Macros#mesh_test)
- Исправлена ошибка [#13](https://github.com/ghzserg/zmod/issues/13) (Печать в воздухе после KAMP)
- Исправлена ошибка [#14](https://github.com/ghzserg/zmod/issues/14) (Восстановление печати на родном экране)
- Исправлена ошибка [#31](https://github.com/ghzserg/zmod/issues/27) (Фризы в GuppyScreen)
- Исправлена ошибка [#25](https://github.com/ghzserg/zmod/issues/25) (AD5X. Неправильно работает калибровка стола)
- Исправлена ошибка [#26](https://github.com/ghzserg/zmod/issues/26) (AD5X. Нет спектрограммы ремней)
- Исправлена ошибка [#27](https://github.com/ghzserg/zmod/issues/27) (AD5X. Ошибка инсталлятора)

### Версия 1.4.1
09.03.2025
- При установке zMod проверяется MD5 сумма распакованных файлов. Принтер при копировании файлов с флешки в файловую систему периодически портит файлы.
- В макросе CHECK_SYSTEM введен самоконтроль системы
- Работает кнопка выключения на Pro версии
- Возможность установить не MJPEG камеры
- Альфа поддержка FF5X:
  Известные особенности:
  - Нет Entware, поэтому не работают NEW_SAVE_CONFIG и CLOSE_DIALOGS
  - Не играет музыку
  - Нет калибровки PID стола, т.к. там не PID
  - При активации камеры указывать VIDEO3
  - Нет тензодачиков, как следствие нет защиты стола и сброса тензодачиков.
  - Нет датчика движения филамента доступного из клиппер

### Версия 1.4.0
04.03.2025
- Обновлен Moonraker, Fluidd,Python
- [Восстановление печати  при потере питания](https://github.com/ghzserg/zmod/wiki/Zmod_ru#zrestore)
- [Построение спектрограммы ремней](https://github.com/ghzserg/zmod/wiki/Macros#belts_shaper_calibration)
- Контроль загруженной пластины, проверяет что карта  стола примерно соответствует текущей загруженной пластине
- Реализована работа с [датчиком движения филамента](https://github.com/ghzserg/zmod/wiki/Macros#motion_sensor)
- GuppyScreen: исключение объектов, вывод ошибок, откат из прошивки, калибровка PID, сброс веса, работа  с FF5M Pro
- Выполнение макроса на [следующем слое](https://github.com/ghzserg/zmod/wiki/Macros#set_pause_next_layer), или [на конкретном слое](https://github.com/ghzserg/zmod/wiki/Macros#set_pause_at_layer)
- Логирование всех сообщений с родного экрана в Klipper и ответов на эти сообщения
- Изменен алгоритм снятия шейперов, графики шейперов строятся с учетом SCV
- Макрос MUTE - выключение звука до перезагрузки
- Новый параметр - [время отключения родного экрана](https://github.com/ghzserg/zmod/wiki/System_ru#display_off_timeout)
- Новый файл `mod_data/power_off.sh` - позволяет писать код выполняемый при отключении принтера
- Включена умная парковка при использовании KAMP
- Исправлены ошибки удаления мода, отключения мода, полного удаления мода
- Исправлена работа предочистки
- Исправлен контроль удара сопла о стол. Работает только во время печати.
- Исправлено движение головы принтера  кнопками во Fluidd/GuppyScreen
- Исправлена работа паузы в режиме без родного экрана
- Исправлена работа KAMP

### Версия 1.3.1
- Доработка GuppyScreen: COLDPULL, контроль PID, ретракты из прошивки, калибровка шейперов, калибровка ремней, косметические фиксы
- Контроль сопла работает теперь только при печати
- BELTS_SHAPER_CALIBRATION
- Улучшена работа без родного экрана
- Улучшена работа медленного закрытия окон и NEW_SAVE_CONFIG

### Версия 1.3.0
08.02.2025
- Поддержка [GuppyScreen](https://github.com/ghzserg/zmod/wiki/System_ru#display_off)
- Klipper 12, [в тестовом режиме](https://github.com/ghzserg/zmod/wiki/Macros#update_mcu) (по умолчанию отключен). В нем не работает: нагрев экструдера, температура экструдера, весы.
- Заменен SSH клиент и SSH сервер `dropbear` на актуальную версию.
- Заменен `mjpg_streamer` на версию с патчем Александра, снижает потребление памяти в 2-4 раза.
- Исправлено исключение объектов от Igor Polunovskiy (теперь учитываются поддержки).
- Построение графиков шейперов с учетом SCV ([square_corner_velocity](https://www.klipper3d.org/Config_Reference.html#printer)) [FIX_SCV](https://github.com/ghzserg/zmod/wiki/Global_ru#fix_scv).
- [CHECK_SYSTEM](https://github.com/ghzserg/zmod/wiki/System_ru#check_system) - Добавлена проверка прав на файлы и каталоги, проверка ссылок и восстановление.
- Удален макрос SOFT_REMOVE.
- Обновлен Moonraker, Fluidd, Mainsail

### Версия 1.1.2
03.02.2025
- Новый макрос [CHECK_SYSTEM](https://github.com/ghzserg/zmod/wiki/System_ru#check_system) - Проверить операционную систему принтера на предмет повреждений файлов.
- Новый макрос [NOZZLE_CONTROL](https://github.com/ghzserg/zmod/wiki/Global_ru#nozzle_control) - Аварийное отключение принтера если зафиксирован отрыв детали или удар сопла о стол.
- Новый макрос [UPDATE_MCU](https://github.com/ghzserg/zmod/wiki/Macros#update_mcu) - Обновить MCU в принтере.
- Новый глобальный флаг [NICE](https://github.com/ghzserg/zmod/wiki/Macros#nice) - Установить приоритет процесса Klipper, 1 - минимальный приоритет, 40 - максимальный (20).
- Новый глобальный флаг [FIX_E0011](https://github.com/ghzserg/zmod/wiki/System_ru#fix_e0011) - Исправить ошибку E0011, а также `Communication timeout during homing`
- Очистка файловой системы принтера от удаленных файлов, ускоряет работу EMMC.
- Куча мелких фиксов

### Версия 1.1.1
24.01.2025
- Исправлена проблема с порядком, если обратный вызов блокируется в обработчике кнопок [#6440](https://github.com/Klipper3d/klipper/pull/6440) найденное [Alexander K](https://github.com/drA1ex) - теперь [LOAD_CELL_TARE](https://github.com/ghzserg/zmod/wiki/Macros#load_cell_tare) работает как надо.
- Удалены глобальные параметры: `ALTER_CELL_TARE`, `IGNORE_CELL_TARE`, `CELL_WEIGHT`
- Увеличен таймаут zsend. Выводятся дополнительные сообщения.
- G28 теперь паркует сначала Z, потом X и Y
- Новый макрос [CAMERA_RESTART](https://github.com/ghzserg/zmod/wiki/Macros#camera_restart) - Перезапустить альтернативную реализацию камеры
- Исправлен код отмены печати без родного экрана
- Реализация EXCLUDE_OBJECT_DEFINE от Igor Polunovskiy
- В случае повторной печати моторы не отключаются и принтер не перезагружается, даже если это указано в глобальных параметрах
- В макросе [TEST_EMMC](https://github.com/ghzserg/zmod/wiki/Macros#test_emmc) выводится износ EMMC карты
- Исправлено отключение китайских облаков

### Версия 1.1.0
15.01.2025
- Обновлен moonraker
- Хорошо увеличена скорость загрузки moonraker
- Спрятаны `level_h1`, `level_h2`, `level_h3`, `power_off`, `clear_power_off`, `level_clear`, `check_level_pin_alt`
- Для сброса тензодатчиков в режиме без родного экрана используется реализация Igor Polunovskiy
- Сброс тензодатчиков, теперь только на прогретом столе
- Новый глобальный параметр [ALTER_CELL_TARE](https://github.com/ghzserg/zmod/wiki/Macros#alter_cell_tare). Позволяет обойти [ошибку сброса тензодатчиков](https://github.com/ghzserg/zmod/wiki/FAQ#%D0%BE%D1%88%D0%B8%D0%B1%D0%BA%D0%B0-%D1%81%D0%B1%D1%80%D0%BE%D1%81%D0%B0-%D1%82%D0%B5%D0%BD%D0%B7%D0%BE%D0%B4%D0%B0%D1%82%D1%87%D0%B8%D0%BA%D0%BE%D0%B2).
- Новый глобальный параметр [CELL_WEIGHT](https://github.com/ghzserg/zmod/wiki/Macros#cell_weight) указывает, при каком весе не надо проводить калибровку тензодатчиков
- Новый глобальный параметр [CHINA_CLOUD](https://github.com/ghzserg/zmod/wiki/Global_ru#china_cloud) - позволяет отключить китайские облака
- Переписано обновление конфига принтера
- В Pro версии теперь корректно работают вентиляторы обдува. Углы по умолчанию 165/105
- При калибровке экструдера теперь задается скорость кулера
- Время и часовой пояс в moonraker теперь соответствует времени klipper
- На вкладке `Информация о системе` выводится версия родной прошивки.
- Уменьшена разговорчивость мода

### Версия 1.0.5
13.01.2025
- Добавлен параметр в макрос [AUTO_REBOOT](https://github.com/ghzserg/zmod/wiki/Macros#auto_reboot), позволяющий перезапускать прошивку
- G28 в макросах вызывается только при необходимости
- Практически полностью изменен алгоритм работы MD5. Теперь проверка MD5 работает из любого места и не требует нагревания стола или экструдера
- Доработан макрос [MEM](https://github.com/ghzserg/zmod/wiki/Macros#mem) теперь выводится память Moonraker, Klipper, Экран и как используется SWAP
- Процесс klipper имеет более высокий приоритет, чем остальные процессы
- Глобальный параметр [PRINT_LEVELING](https://github.com/ghzserg/zmod/wiki/Global_ru#zshaper) теперь работает и в без родного экрана
- Макрос [BED_LEVEL_SCREWS_TUNE](https://github.com/ghzserg/zmod/wiki/Calibrations_ru#bed_level_screws_tune) теперь корректно использует температуру
- Макрос [TEST_EMMC](https://github.com/ghzserg/zmod/wiki/Macros#test_emmc) может тестировать EMMC, USB Flash и оперативную память.
- Swap теперь можно(но не нужно) разместить на USB Flash 
- Макрос [CLEAR_EMMC](https://github.com/ghzserg/zmod/wiki/System_ru#clear_emmc) - очистка логов и/или GCODE
- Решение проблемы [E0017](https://github.com/ghzserg/zmod/wiki/System_ru#fix_e0017)

### Версия 1.0.4
05.01.2025
- Поддержка [отката из прошивки](https://github.com/ghzserg/zmod/wiki/FAQ#%D1%87%D1%82%D0%BE-%D1%82%D0%B0%D0%BA%D0%BE%D0%B5-%D0%BE%D1%82%D0%BA%D0%B0%D1%82-%D0%B8%D0%B7-%D0%BF%D1%80%D0%BE%D1%88%D0%B8%D0%B2%D0%BA%D0%B8)
- Решение проблемы [E0017](https://github.com/ghzserg/zmod/wiki/System_ru#fix_e0017)
- Автоматическое включение обдува драйверов, при включении двигателей. Решает проблему снятия шейперов без обдува в стоке.
- Новый макрос [TEST_EMMC](https://github.com/ghzserg/zmod/wiki/Macros#test_emmc) - Записывает SIZE Мб на EMMC и пишет скорость чтения записи.
- Новый макрос [CLEAR_EMMC](https://github.com/ghzserg/zmod/wiki/System_ru#clear_emmc) - Очищает EMMC.
- Автоматический [рестарт бота при работе по SSH](https://github.com/ghzserg/zmod/wiki/Macros#zssh_on)
- [Автоматическая очистка](https://github.com/ghzserg/zmod_ff5m/blob/1.4/telegram/docker-compose.yml) видео старше 10 дней в боте.
- Установка [нужной временной зоны](https://github.com/ghzserg/zmod_ff5m/blob/1.4/telegram/docker-compose.yml) в боте
- Автоматический переход с очистки KAMP [LINE_PURGE](https://github.com/ghzserg/zmod/wiki/Global_ru#clear) на _CLEAR2, если объекты не найдены
- Исправлена работа [SKIP_ZMOD](https://github.com/ghzserg/zmod/wiki/Macros#skip_zmod)
- Обновление fluidd/mainsail теперь не требует перезагрузки
- Смена fluidd на mainsail теперь не требует перезагрузки
- Zmod сообщает о файлах, если в них используются дуги
- Исправлен скрипт `addMD5.sh`
- Исправлено управление охлаждением драйверов для версии без родного экрана
- Загрузка карты стола `auto` для версии без родного экрана при старте принтера

### Версия 1.0.0
23.12.2024
- Новая система обновления и установки, теперь практически любые обновления можно получать по сети
- Новый параметр макроса [CAMERA_ON](https://github.com/ghzserg/zmod/wiki/Zmod_ru#camera_on), VIDEO - устройство видео (video0)

### Версия 0.2.4
21.12.2024
- ZMOD автоматически пишет, нужно ли обновляться с флэшки - теперь красным цветом
- Если используется снятие карты  стола  с родным экраном (PRINT_LEVELING=1), то параметры FORCE_LEVELING, FORCE_KAMP, SKIP_LEVELING, MESH в START_PRINT игнорируются
- Пауза, даже при печати с экрана в правом дальнем углу
- Параметр PRRECLEAR, теперь работает и при печати с построением карты с экрана
- Изменен алгоритм установки, теперь после  успешной установки флэшку вынимать не обязательно - принтер сам перезагрузится и удалит установочный файл.

### Версия 0.2.3
19.12.2024
- ZMOD автоматически пишет, нужно ли обновляться с флэшки
- Доработан макрос [M600](https://github.com/ghzserg/zmod/wiki/Macros#m600) - замена филамента  с паузой во время печати
- Доработан контроль MD5 - теперь выводится сообщение если MD5 не найден

### Версия 0.2.2
17.12.2024
- Новый макрос [FAST_CLOSE_DIALOGS](https://github.com/ghzserg/zmod/wiki/Macros#fast_close_dialogs) - Вызывает быстрое закрытие диалогов с родного экрана. Используется для закрытия окна по окончанию печати или при отмене печати. *Для работы быстрого закрытия диалогов необходимо через меню экрана принтера перейти на вкладку "Настройки" -> "Иконка WiFi" -> "Сетевой режим" -> включить ползунок "Только локальные сети".* Реализация: @darksimpson
- Новый макрос [LEVELING_PRINT_FILE](https://github.com/ghzserg/zmod/wiki/Macros#leveling_print_file) - Печать файла с построением карты стола с родного экрана. *Для LEVELING_PRINT_FILE необходимо через меню экрана принтера перейти на вкладку "Настройки" -> "Иконка WiFi" -> "Сетевой режим" -> включить ползунок "Только локальные сети"*
- Новый макрос [COLDPULL](https://github.com/ghzserg/zmod/wiki/Filament_ru#coldpull) Колдпул (очистка сопла) без насилия. Реализация [этого алгоритма](https://t.me/FF_5M_5M_Pro/2836/447172)
- Новые параметры [SAVE_ZMOD_DATA](https://github.com/ghzserg/zmod/wiki/Global_ru#save_zmod_data):
  - [PRINT_LEVELING](https://github.com/ghzserg/zmod/wiki/Global_ru#save_zmod_data) - при каждой печати строить карту стола средствами родного экрана 0-нет, 1-да (0). *Для работы снятия карты стола с родного экрана необходимо, через меню экрана принтера перейти на вкладку "Настройки" -> "Иконка WiFi" -> "Сетевой режим" -> включить ползунок "Только локальные сети"*
  - [USE_KAMP](https://github.com/ghzserg/zmod/wiki/Global_ru#save_zmod_data) - где возможно использовать адаптивную карту стола(KAMP), вместо полной карты стола 0-нет, 1-да (0). *Позволяет использовать KAMP при снятии карты стола по сети с родного экрана*
  - [CLOSE_DIALOGS](https://github.com/ghzserg/zmod/wiki/Global_ru#save_zmod_data) - автоматически закрывать диалоги по окончанию и при отмене печати 0-нет, 1-да медленно, 2-да быстро. *Для работы быстрого закрытия диалогов необходимо через меню экрана принтера перейти на вкладку "Настройки" -> "Иконка WiFi" -> "Сетевой режим" -> включить ползунок "Только локальные сети"* (0).
  - [USE_SWAP](https://github.com/ghzserg/zmod/wiki/Global_ru#save_zmod_data) - Использовать SWAP 0-нет, 1-да (1). *Если у вас не перепаянный процессор, то SWAP использовать обязательно*

### Версия 0.2.1.1
10.12.2024
- Асинхронный алгоритм воспроизведения MIDI файлов
- Исправление установки
- Исправлен SHUTDOWN из главного меню
- Новый скрипт [addMD5.sh](https://github.com/ghzserg/zmod_ff5m/blob/1.4/addMD5.sh) - контроль md5 для MacOS/Linux - спасибо Alexander
- Новый параметр [STOP_MOTOR](https://github.com/ghzserg/zmod/wiki/Global_ru#save_zmod_data) - автоматически выключать моторы после печати/отмены печати через 25 секунд.
- Новый параметр [AUTO_REBOOT](https://github.com/ghzserg/zmod/wiki/Global_ru#save_zmod_data) - автоматически перезапускать принтер через 1.5 минуты после печати.
- Новый параметр [PRECLEAR](https://github.com/ghzserg/zmod/wiki/Global_ru#save_zmod_data) - использовать предочистку сопла в START_PRINT
- Новая музыка: BattleCity, IndianaJones, WeWillRockYou от [@drmax_gc](https://t.me/drmax_gc)

### Версия 0.2.1
10.12.2024
- Получение графика шейперов прямо с принтера. Макрос [ZSHAPER](https://github.com/ghzserg/zmod/wiki/Calibrations_ru#zshaper)
- Исправление ошибки при работе  без родного экрана

### Версия 0.2.0
09.12.2024
- Обновление fluidd/mainsauil
- Добавление mc, opkg, gdb
- Перезагрузка через верхнее меню fluidd
- Исправление ошибок
- Сильная переработка макроса [START_PRINT](https://github.com/ghzserg/zmod/wiki/Main_ru#start_print)
- Макрос [NEW_SAVE_CONFIG](https://github.com/ghzserg/zmod/wiki/Macros#new_save_config) - сохранить изменения/перезагрузить клиппер без зависания родного экрана. Реализация @darksimpson
- Макрос [CLOSE_DIALOGS](https://github.com/ghzserg/zmod/wiki/Macros#close_dialogs) - закрыть окна по окончанию печати и при отмене печати. Реализация @darksimpson
- Макрос [STOP_ZMOD](https://github.com/ghzserg/zmod/wiki/Macros#stop_zmod) - отключить moonraker
- Макрос [START_ZMOD](https://github.com/ghzserg/zmod/wiki/Macros#start_zmod) - включить moonraker
- Макрос [SAVE_ZMOD_DATA](https://github.com/ghzserg/zmod/wiki/Global_ru#save_zmod_data) - cохранить параметры ZMOD 
    - CLOSE_DIALOGS - автоматически закрывать диалоги по окончанию и отмене печати 0-нет, 1-да (0)
    - NEW_SAVE_CONFIG - использовать альтернативный NEW_SAVE_CONFIG при калибровке PID 0-нет, 1-да (0)
    - LED - яркость LED при включении (50)
    - MIDI_ON - играть MIDI при включении ("")
    - MIDI_START - играть MIDI при запуске печати ("")
    - MIDI_END - Играть MIDI в конце печати ("")

### Версия 0.1.8
04.12.2024
- Поддержка подключения телеграм бота
- Макрос [ZSSH_ON](https://github.com/ghzserg/zmod/wiki/Macros#zssh_on) - ZSSH_ON SSH_SERVER SSH_PORT SSH_USER VIDEO_PORT MOON_PORT
- Макрос [ZSSH_OFF](https://github.com/ghzserg/zmod/wiki/Macros#zssh_off) - выключить SSH клиента
- Макрос [ZSSH_RESTART](https://github.com/ghzserg/zmod/wiki/Macros#zssh_restart) - перезапуск SSH клиента

### Версия 0.1.7
03.12.2024
- Множество исправлений макросов
- Макрос [STOP_ZMOD](https://github.com/ghzserg/zmod/wiki/Macros#stop_zmod) - временно отключает fluidd/mainstaill и moonraker

### Версия 0.1.6
02.12.2024
- Исправлено место нахождение логов
- Исправлен макрос [LOAD_CELL_TARE](https://github.com/ghzserg/zmod/wiki/Macros#load_cell_tare)
- Исправлен макрос  калибровки PID экструдера и стола
- Макрос [CLEAR_NOZZLE](https://github.com/ghzserg/zmod/wiki/Macros#CLEAR_NOZZLE) - очистка сопла как в родной прошивке
- Макрос [KAMP](https://github.com/ghzserg/zmod/wiki/Calibrations_ru#kamp) extruder_temp=[nozzle_temperature_initial_layer] bed_temp=[bed_temperature_initial_layer_single]. Адаптивная карта  стола с очисткой сопла.
- [AUTO_FULL_BED_LEVEL](https://github.com/ghzserg/zmod/wiki/Calibrations_ru#auto_full_bed_level) - полностью переписан макрос

### Версия 0.1.5
30.11.2024
- Добавлен mainsail. Переключение через макрос WEB
- Макрос STOP - отключает моторы, прописывается в конечный gcod
- Макрос [ZSHAPER](https://github.com/ghzserg/zmod/wiki/Calibrations_ru#zshaper) - калибровка шейперов и выгрузка файлов csv в /mod_data в конфигурации. Дальнейший анализ через (https://github.com/theycallmek/Klipper-Input-Shaping-Assistant/releases)
- Макрос [LOAD_CELL_TARE](https://github.com/ghzserg/zmod/wiki/Macros#load_cell_tare) - сброс тензодатчиков
- Исправлена калибровка стола. Теперь можно установить температуру стола и экструдера для калибровки. по умолчанию 120/80
- Исправлено отключение экрана в режиме без родного экрана. Он отключатся через 4 минуты.

### Версия 0.1.4
29.11.2024
- Добавлено управление камерой из мода. Позволяет t память. И работать с камерой с отключенным экраном. Также можно изменить разрешение камеры. (Реализация подсмотрена у Павла Миронова)
- Исправлена ошибка установщика, который в прошлой версии мог удалить [heater_bed] из файлов конфигурации
- Изменены картинки при установке. Реализовано [@drmax_gc](https://t.me/drmax_gc)
- Макросы разделены по категориям и переведены на русский язык
- Макрос [DATE_GET](https://github.com/ghzserg/zmod/wiki/Macros#date_get) - посмотреть текущее время
- Макрос [DATE_SET](https://github.com/ghzserg/zmod/wiki/Macros#date_set) - установить текущее время
- Макрос [CAMERA_ON](https://github.com/ghzserg/zmod/wiki/Zmod_ru#camera_on) - Использовать альтернативную реализацию камеры
- Макрос [CAMERA_OFF](https://github.com/ghzserg/zmod/wiki/Macros#camera_off) - Отключить альтернативную реализацию камеры

### Версия 0.1.3
28.11.2024
- Добавлено воспроизведение MIDI. Файлы хранятся в mod_data/midi - доступ через вкладку конфигурация. Спасибо [@drmax_gc](https://t.me/drmax_gc)
- Макрос [PLAY_MIDI](https://github.com/ghzserg/zmod/wiki/Macros#play_midi). Играет мелодию PLAY_MIDI FILE=Pain-Shut-your-mouth.mid
- Макрос [SOFT_REMOVE](https://github.com/ghzserg/zmod/wiki/Macros#soft_remove). Удаляет только zMod, оставляет audio, md5, root
- После обновления настройки moonraker сохраняются
- Настройки пользователя для klipper пернесены в mod_data/user.cfg
- Настройки пользователя для moonraker перенесены в mod_data/user.moonraker.conf
- При выклчюении экрана на нем пишется текст, что экран выключен. Спасибо @drmax_gc
- Исправлена ошибка калибровки кровати через макрос. Теперь кровать греется.
- Исправлена ошибка регулировки кровати через макрос. Теперь кровать греется.

### Версия 0.1.1
27.11.2024
- Поддержка работы с отключенным родным дисплеем. Это экономит 20 мегабайт оперативной памяти. Чтобы  включить этот режим, нужно вызвать макрос DISPLAY_OFF. Клипер перезагрузится и будет использовать альтернативные файлы конфигурации. Рекомендуется снять карту  стола  и сохранить в профиль default. После перезагрузки, экран  станет недоступен через 5 минут и загрузится карта  стола из профиля default.
- Макрос [MEM](https://github.com/ghzserg/zmod/wiki/Macros#mem) - показывает сколько памяти используется и каким приложением.
- Макрос [DISPLAY_ON](https://github.com/ghzserg/zmod/wiki/System_ru#display_on) - вернет экран в стандартный режим работы, принтер перезагрузится
- Макрос [LED](https://github.com/ghzserg/zmod/wiki/Macros#led) - включит подсветку на 50%
- Макрос [LED_ON](https://github.com/ghzserg/zmod/wiki/Macros#led_on) - включит подсветку на 100%
- Макрос [LED_OFF](https://github.com/ghzserg/zmod/wiki/Macros#led_off) - выключить подсветку

### Версия 0.0.9-fix
25.11.2025
- Исправлена ошибка установки.

### Версия 0.0.9
25.11.2025
- Реализована пауза при печати, обрабатывается через родной экран
- Реализовано восстановление после паузы, обрабатывается через родной экран
- Реализована отмена печати, обрабатывается через родной экран
- [REBOOT](https://github.com/ghzserg/zmod/wiki/Macros#reboot) - макрос перезагружает принтер
- [SHUTDOWN](https://github.com/ghzserg/zmod/wiki/Macros#shutdown) - макрос на отключение принтера
- [SKIP_ZMOD](https://github.com/ghzserg/zmod/wiki/Macros#skip_zmod) - макрос перезагрузки без запуска moonraker и fluidd
- [REMOVE_ZMOD](https://github.com/ghzserg/zmod/wiki/Macros#remove_zmod) - макрос удаления мода
- Исправлена ошибка: "После паузы из-за срабатывания датчика движения филамента восстанавливает печать, но печатает в воздухе сантиметрах в 3 над местом где надо"
