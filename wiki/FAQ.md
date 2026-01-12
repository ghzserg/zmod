# FAQ
## Частые вопросы

> Поставили мод.
> 
> Ни хотите ни в чем разбираться - печатайте  как и печатали.
> 
> Вообще ничего нигде настраивать и менять не надо.
> 
> Решили, что готовы двигаться дальше - двигаетесь - читая документацию.

[@zmod_help_bot](http://t.me/zmod_help_bot)

| | |
|--------|--------|
| [Чем ZMOD отличается от KlipperMod/родной прошивки](#чем-zmod-отличается-от-klippermodродной-прошивки) | [Известные особенности](#известные-особенности) |
| [Хранение настроек](#хранение-настроек) | [Особенности версии без родного экрана](#особенности-версии-без-родного-экрана) |
| [Надо ли менять что-то в стартовом коде](#надо-ли-менять-что-то-в-стартовом-коде) | [Как работает Z-Offset](#как-работает-z-offset) |
| [Какие есть варианты снятия карты стола?](#какие-есть-варианты-снятия-карты-стола) | [Почему в документации периодически встречаются названия животных?](#почему-в-документации-периодически-встречаются-названия-животных) |
| [Что такое альтернативная камера?](#что-такое-альтернативная-камера) | [Я установил принтер, а ZMOD спрятал мою камеру!](#я-установил-принтер-а-zmod-спрятал-мою-камеру-в-orca-ff-я-ее-видел-а-теперь-она-пропала) |
| [У меня появилось 2 камеры / как отключить/повернуть камеру](#у-меня-появилось-2-камеры--как-отключитьповернуть-камеру) | [Я установил последнюю версию, а разработчик говорит, что надо обновиться](#я-установил-последнюю-версию-а-разработчик-говорит-что-надо-обновиться) |
| [Я использую вариант с экраном. Отправляю файл на печать, а на экране температура 0 0 и печать не идёт](#я-использую-вариант-с-экраном-отправляю-файл-на-печать-а-на-экране-температура-0-0-и-печать-не-идет) | [После установки ZMOD мой экран умер, не реагирует на нажатия](#после-установки-zmod-мой-экран-умер-не-реагирует-на-нажатия) |
| [Чем отличается работа с экраном и без родного экрана](#чем-отличается-работа-с-экраном-и-без-родного-экрана) | [Я хочу удалить ZMOD — мне придётся всё перекалибровать?](#я-хочу-удалить-zmod---мне-придется-все-перекалибровать) |
| [Can not update MCU](#can-not-update-mcu) | [Что такое макрос? Как его запускать, качать, использовать](#что-такое-макрос-как-его-запускать-качать-использовать) |
| [Я захожу на принтер через Orca/браузер, а вижу *Welcome to Moonraker*](#я-захожу-на-принтер-через-orcaбраузер-а-вижу-welcome-to-moonraker) | [Я переключил веб-интерфейс и теперь ничего не работает](#я-переключил-веб-интерфейс-и-теперь-ничего-не-работает) |
| [В ZMOD входит Entware — как им воспользоваться?](#в-zmod-входит-entware---как-им-воспользоваться) | [Что такое откат из прошивки?](#что-такое-откат-из-прошивки) |
| [AD5X](#ad5x) | [Как обратиться в поддержку к разработчику](#как-обратиться-в-поддержку-к-разработчику) |
| [Как изменить логотип загрузки](#как-изменить-логотип-загрузки) | [Что такое откат из прошивки?](#что-такое-откат-из-прошивки) |
| [No trigger on probe after full movement](#no-trigger-on-probe-after-full-movement) | [WeightValue](#weightvalue) |
| [MCU Protocol error](#mcu-protocol-error) | [Кончился или остановился филамент](https://github.com/ghzserg/zmod/wiki/FAQ#%D0%BA%D0%BE%D0%BD%D1%87%D0%B8%D0%BB%D1%81%D1%8F-%D0%B8%D0%BB%D0%B8-%D0%BE%D1%81%D1%82%D0%B0%D0%BD%D0%BE%D0%B2%D0%B8%D0%BB%D1%81%D1%8F-%D1%84%D0%B8%D0%BB%D0%B0%D0%BC%D0%B5%D0%BD%D1%82) |
| [Перед каждой печатью измеряет стол по цетру](#перед-каждой-печатью-измеряет-стол-по-цетру) | [E0120](#e0120) |


### Чем ZMOD отличается от KlipperMod/родной прошивки

   Разница между KlipperMod и ZMOD:
  - KlipperMod использует чистый klipper с минимум специфичных для flashforge 5m(pro) изменений
  - ZMOD использует стандартный Klipper из родной прошивки, а также Klipper 13
  - KlipperMod использует KlipperScreen как экран для принтера.
  - В ZMOD вместо KlipperScreen родной экран или GuppyScreen
  - KlipperMod использует Moonraker-timelapse
  - ZMOD использует moonraker-telegram-bot на ВНЕШНЕМ хосте с поддержкой таймлапс или [плагин TimeLapse](https://github.com/ghzserg/timelapse/)

Разная философия.

* KlipperMod - по сути альтернативная реализация прошивки.
* ZMOD минимальное вмешательство в родную прошивку. Все функции родной прошивки сохранены.

Именно по этому, в ZMOD не будет G17, G18, G19 - хотя  это просто. Не будет обновлений родного клиппера, не будет переименований или изменений стандартных макросов, настроек, названия пинов и т.д.

ZMOD НЕ основан на KlipperMod, и НЕ является его развитием. При этом в ZMOD используются некоторые макросы и скрипты из KlipperMod, а также использовались наработки из KlipperMod. Но не стоит ожидать от ZMOD поведения аналогичного KlipperMod.

**ZMOD бинарно не совместим к KlipperMod.**

#### Что есть в KlipperMod и чего нет в ZMOD:
- [KlipperScreen](https://klipperscreen.readthedocs.io/en/latest/) - экран для принтера. В ZMOD вместо KlipperScreen родной экран или GuppyScreen
- [Moonraker-timelapse](https://github.com/mainsail-crew/moonraker-timelapse) - в ZMOD используется Телеграм бот или [плагин TimeLapse](https://github.com/ghzserg/timelapse/)
- Настройка сети через iwd/wpa_supplicant( в случае с guppyscreen) - в zMod настройка сети через родной экран, запуск сети возможен и в режиме без родного экрана

#### Что есть в ZMOD и чего нет в KlipperMod:
- Поддержка [AD5X](https://github.com/ghzserg/zmod/wiki/AD5X)
- Поддержка [следующих языков](https://github.com/ghzserg/zmod/wiki/Global_ru#lang): Английский, Немецкий, Французский, Итальянский, Испанский, Китайский, Японский, Корейский 
- Работа с родным экраном
- [Восстановление печати при сбое питания](https://github.com/ghzserg/zmod/wiki/Zmod_ru#zrestore)
- [Снятие шейперов c генерацией графиков](https://github.com/ghzserg/zmod/wiki/Calibrations_ru#zshaper) с учетом [SCV](https://github.com/ghzserg/zmod/wiki/Global_ru#fix_scv) ([square_corner_velocity](https://www.klipper3d.org/Config_Reference.html#printer)).
- [Проверка и восстановление файлов/прав/символических ссылок родной файловой системы](https://github.com/ghzserg/zmod/wiki/System_ru#check_system)
- Автоматическое обновление `Fluidd`/`Mainsail`/`Moonraker` и ZMOD по сети
- [Entware](https://github.com/ghzserg/zmod/wiki/FAQ#%D0%B2-zmod-%D0%B2%D1%85%D0%BE%D0%B4%D0%B8%D1%82-entware---%D0%BA%D0%B0%D0%BA-%D0%B8%D0%BC-%D0%B2%D0%BE%D1%81%D0%BF%D0%BE%D0%BB%D1%8C%D0%B7%D0%BE%D0%B2%D0%B0%D1%82%D1%8C%D1%81%D1%8F)
- Исправлена ошибка [E0017](https://github.com/ghzserg/zmod/wiki/System_ru#fix_e0017)
- Дополнительно GuppyScreen поддерживает: калибровка PID, управление заслонкой, откат из прошивки, очистка сопла, сброс тензодатчиков, регулировка винтов, ColdPull, доработана карта стола
- Исправлена работа вентиляторов обдува драйверов. Они автоматически включаются при работе моторов. На родной прошивке - только при печати.
- Адаптивное снятие карты стола [KAMP](https://github.com/ghzserg/zmod/wiki/Calibrations_ru#kamp)
- Калибровка PID [экструдера](https://github.com/ghzserg/zmod/wiki/Calibrations_ru#pid_tune_extruder) и [стола](https://github.com/ghzserg/zmod/wiki/Calibrations_ru#pid_tune_bed) в том числе через GuppyScreen.
- Реализован [COLDPULL/Колдпул](https://github.com/ghzserg/zmod/wiki/Filament_ru#coldpull) (очистка сопла) без насилия. Реализация [этого алгоритма](https://t.me/FF_5M_5M_Pro/2836/447172)

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#faq)

</div>

---

#### Что есть в ZMOD и чего нет в родной прошивке:
- Поддержки Moonraker/Fluidd/Mainsail
- Поддержки Телеграм бота
- Поддержки Klipper 13
- Всех функций что перечислены в сравнении с KlipperMod
- [Родная прошивка отправляет множество данных на китайские сервера](https://github.com/FlashForge/Orca-Flashforge/issues/26), этого можно избежать если использовать zmod c GuppyScreen

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#faq)

</div>

---

## Хранение настроек

Доступ к папке **mod_data** через веб интерфейс fluidd.

`Конфигурация` -> `Файлы конфигурации` -> `mod_data`

- Пользовательские настройки klipper необходимо вносить в файл `mod_data/user.cfg`, настройки записанные в это файл могут заменять/дополнять настройки из `printer_base.cfg` и файлов zMod.
- Пользовательские настройки moonraker необходимо вносить в файл `mod_data/user.moonraker.conf`
- Пользовательские мелодии хранятся в `mod_data/midi/`
- Глобальные настройки мода хранятся через макрос [SAVE_ZMOD_DATA](https://github.com/ghzserg/zmod/wiki/Global_ru#save_zmod_data) *нюхлер*
- Код исполняемый при выключении принтера хранится тут `mod_data/power_off.sh`
- Код исполняемый при включении принтера хранится тут `mod_data/power_on.sh`

**Нельзя вносить изменения в файлы zmod и плагинов**, это сломает систему обновлений.

Любую функцию можно переопределить в `mod_data/user.cfg` или `printer.cfg`

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#faq)

</div>

---

## Известные особенности:
- Если принтер выполняет какие-то действия `M109` (прогрев экструдера), `M190`(прогрев стола), калибровку PID - в общем любое действие, которое заставляет приостановится gcod, то родной экран замирает
- Если перезапускается klipper (после сохранения карты стола, PID, Шейперов и т.д.), то родной экран замерзает (используйте перезапуск через [NEW_SAVE_CONFIG](https://github.com/ghzserg/zmod/wiki/Main_ru#new_save_config)
- После отмены печати, на родном экране надо нажать кнопку Ок (используйте макрос [CLOSE_DIALOGS](https://github.com/ghzserg/zmod/wiki/Main_ru#close_dialogs) или [FAST_CLOSE_DIALOGS](https://github.com/ghzserg
/zmod/wiki/Main_ru#fast_close_dialogs))
- Родной экран при загрузке печати всегда грузит профиль `DEFAULT_MESH`, а после окончания печати всегда удаляет профиль `Default`

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#faq)

</div>

---

## Особенности версии без родного экрана
- Необходимо удалить весь стартовый gcode и прописать [START_PRINT](https://github.com/ghzserg/zmod/wiki/Main_ru#start_print), а в конечный [END_PRINT](https://github.com/ghzserg/zmod/wiki/Main_ru#end_print)
- Не работает камера, необходимо запустить альтернативную камеру через макрос [CAMERA_ON](https://github.com/ghzserg/zmod/wiki/Zmod_ru#camera_on)
- При необходимости, надо вручную прописать параметр `Z_OFFSET` в макросе [START_PRINT](https://github.com/ghzserg/zmod/wiki/Main_ru#start_print) или использовать глобальный параметр [LOAD_ZOFFSET](https://github.com/ghzserg/zmod/wiki/Global_ru#load_zoffset) который загружает Z-offset из глобальных параметров, сохраненных ранее через SET_GCODE_OFFSET. *крот*
- Если вы хотите перенести z-offset с родного экрана в режим без родного экрана вызовите макрос ```LOAD_ZOFFSET_NATIVE``` он считает значение z-offset с родного экрана и применит его для режима без родного экрана.
- При включении принтера автоматически загружается карта стола `auto`
- Не работает отправка через протокол FlashForge, т.к. его обрабатывает экран.
  Необходимо переключиться на протокол "Octo/Klipper":
  - Протокол: `Octo/Klipper`
  - Имя хоста: `IP_принтера:7125`
  - Url-адрес хоста: `IP_принтера` или `IP_принтера:80`

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#faq)

</div>

---

### Я использую вариант с экраном. Отправляю файл на печать, а на экране температура 0 0 и печать не идет.

Добавьте в стартовый код в самое начало 2 строчки
```
M190 S[bed_temperature_initial_layer_single]
M104 S[nozzle_temperature_initial_layer]
```

Без этих строчек экран принтера не знает до какой температуры надо греть сопло и стол.
*бегемот*

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#faq)

</div>

---

### После установки ZMOD мой экран умер, не реагирует на нажатия.

- [Установите последнее обновление родной прошивки и ZMOD](https://github.com/ghzserg/zmod/wiki/Recomendations#%D1%83%D1%81%D1%82%D0%B0%D0%BD%D0%BE%D0%B2%D0%B8%D1%82%D0%B5-%D0%BF%D0%BE%D1%81%D0%BB%D0%B5%D0%B4%D0%BD%D0%B5%D0%B5-%D0%BE%D0%B1%D0%BD%D0%BE%D0%B2%D0%BB%D0%B5%D0%BD%D0%B8%D0%B5-%D1%80%D0%BE%D0%B4%D0%BD%D0%BE%D0%B9-%D0%BF%D1%80%D0%BE%D1%88%D0%B8%D0%B2%D0%BA%D0%B8-%D0%B8-zmod)
- Прочитайте [особенности работы](#%D0%B8%D0%B7%D0%B2%D0%B5%D1%81%D1%82%D0%BD%D1%8B%D0%B5-%D0%BE%D1%81%D0%BE%D0%B1%D0%B5%D0%BD%D0%BD%D0%BE%D1%81%D1%82%D0%B8) *бизон*
- Вы могли отключить экран. Включите его макросом [DISPLAY_ON](https://github.com/ghzserg/zmod/wiki/System_ru#display_on)

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#faq)

</div>

---

### Надо ли менять что-то в стартовом коде

Если работаете с родным экраном, то ничего менять не надо. 

При работе в режиме без родного экрана/Guppy (а также  рекомендуется и при работе с экраном) заменить весь стартовый код:
```
START_PRINT EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single]
M190 S[bed_temperature_initial_layer_single]
M104 S[nozzle_temperature_initial_layer]
SET_PRINT_STATS_INFO TOTAL_LAYER=[total_layer_count]
```

```START_PRINT EXTRUDER_TEMP= BED_TEMP=``` должно писаться в одну строку

А конечный код на:
```
END_PRINT
```

Чтобы корректно считались слои во Fluidd, в код перед сменой слоя прописать:
```
SET_PRINT_STATS_INFO CURRENT_LAYER={layer_num + 1}
```

Если вы хотите включить авто калибровку при каждой печати, введите  1 раз в консоль Fluidd/Mainsail
```
SAVE_ZMOD_DATA CLOSE_DIALOGS=2 PRINT_LEVELING=1 USE_KAMP=1
```
Через меню экрана принтера перейти на вкладку `Настройки` -> `Иконка WiFi` -> `Сетевой режим` -> включить ползунок `Только локальные сети`.

Прочитайте документацию к [START_PRINT](https://github.com/ghzserg/zmod/wiki/Main_ru#start_print) и [SAVE_ZMOD_DATA](https://github.com/ghzserg/zmod/wiki/Global_ru#save_zmod_data), это позволит вам использовать расширенные и полезные функции ZMOD

Если хотите воспользоваться откатом из прошивки, то прочитайте [документацию](https://github.com/ghzserg/zmod/wiki/FAQ#%D1%87%D1%82%D0%BE-%D1%82%D0%B0%D0%BA%D0%BE%D0%B5-%D0%BE%D1%82%D0%BA%D0%B0%D1%82-%D0%B8%D0%B7-%D0%BF%D1%80%D0%BE%D1%88%D0%B8%D0%B2%D0%BA%D0%B8) и добавьте 
`Профиль прутка` -> `Дополнительно` -> `Стартовый G-код прутка`
```
SET_RETRACTION RETRACT_LENGTH=[filament_retraction_length]
```

*енот*

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#faq)

</div>

---

### Как работает Z-Offset

Прочитайте статью "[Как работает Z-Offset на нашем принтере](https://github.com/ghzserg/zmod/wiki/Setup#%D0%BA%D0%B0%D0%BA-%D1%80%D0%B0%D0%B1%D0%BE%D1%82%D0%B0%D0%B5%D1%82-z-offset-%D0%BD%D0%B0-%D0%B2%D0%B0%D1%88%D0%B5%D0%BC-%D0%BF%D1%80%D0%B8%D0%BD%D1%82%D0%B5%D1%80%D0%B5)"

При работе с экраном мод никак не вмешивается в работу z-offset.

Offset при работе с родным экраном и при работе в режиме без родного экрана не совпадает и каждый живет своей жизнью и настраивается отдельно.

Используйте ```LOAD_ZOFFSET_NATIVE``` для копирования Z-offset с родного экрана в режим без родного экрана.

Используется z-offset сохраненный на экране.

Смещение Z из Fluidd/Mainsail/GuppyScreen влияет **только до перезагрузки** и менять его без понимая, куда движется сопло не стоит.

Любой вызов `SET_GCODE_OFFSET` (а он автоматически вызывается при изменении смещения Z из Fluid/Mainsail/GuppyScreen) сохраняет текущий z-offset в глобальные параметры мода. Но это сохраненное значение используется только в том случае, если указан глобальный параметр [LOAD_ZOFFSET](https://github.com/ghzserg/zmod/wiki/Global_ru#load_zoffset)(который по умолчанию отключен, для вклчючения `SAVE_ZMOD_DATA LOAD_ZOFFSET=1`), не используется родной экран и используется макрос [START_PRINT](https://github.com/ghzserg/zmod/wiki/Main_ru#start_print).

Также для задания Z-offset можно использовать параметры [START_PRINT](https://github.com/ghzserg/zmod/wiki/Main_ru#start_print)
- Z_OFFSET - Установить Z офсет (0.0)

### Какие есть варианты снятия карты стола?

Если вы хотите включить авто калибровку при каждой печати, введите 1 раз в консоль fluidd/mainsail:
```
SAVE_ZMOD_DATA CLOSE_DIALOGS=2 PRINT_LEVELING=1 USE_KAMP=1
```

Родной экран использует карты (всегда, это не исправляется, даже если вам не надо):
- `MESH_DATA` - по умолчанию
- `DEFAULT` - если установлена галочка `leveling` (построение карты стола перед печатью), а после печати карта `DEFAULT` всегда  удаляется. 

При работе в режиме без родного экрана используется карта:
- `auto` - она автоматически подгружается при включении принтера. 

Если вы хотите использовать другую карту при печати(например `moya_karta_na_80_gradusov`), то:
- Надо выключить авто калибровку в глобальных параметрах

  ```SAVE_ZMOD_DATA PRINT_LEVELING=0```
- Снять заранее карту стола через макрос [AUTO_FULL_BED_LEVEL](https://github.com/ghzserg/zmod/wiki/FAQ#%D1%87%D0%B5%D1%80%D0%B5%D0%B7-%D0%BC%D0%B0%D0%BA%D1%80%D0%BE%D1%81%D1%8B-%D0%B8-%D0%BA%D0%BD%D0%BE%D0%BF%D0%BA%D0%B8-%D0%B2%D0%BE-fluidd). 
 
  ```AUTO_FULL_BED_LEVEL EXTRUDER_TEMP=230 BED_TEMP=80 PROFILE=moya_karta_na_80_gradusov```

Выбрать один из двух вариантов:
- Указать название карты стола в параметре `MESH` для макроса [START_PRINT](https://github.com/ghzserg/zmod/wiki/Main_ru#start_print). 
 
  ```START_PRINT MESH=moya_karta_na_80_gradusov```
- или загрузить карту стола в любом удобном месте (например в профиле прутка) через команду 
 
  ```BED_MESH_PROFILE LOAD=moya_karta_na_80_gradusov```

  Убедитесь что у вас используется одна и таже карта в профиле прутка и `START_PRINT`, или отключите очистку сопла в `START_PRINT`, запуская ее через профиль прутка.

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#faq)

</div>

---

#### Через глобальные параметры

Я рекомендую использовать глобальные параметры, которые настраиваются один раз и используются при каждой печати. Менять стартовый и конечный G-код в этом случае нет необходимости.

Параметр `PRINT_LEVELING`:
- Снимает карту стола при каждой печати
- Если работаете с экраном, то карту  стола снимает родной экран, так как если бы выбрали файл с экрана и нажали галочку `Выравнивание`. Если параметр равен 1 `SAVE_ZMOD_DATA PRINT_LEVELING=1`, то когда вы отправляете файлы через Orca/Fluidd/Mainsail, принтер считает, что вы с родного экрана выбрали файл для печати и поставили галочку `Выравнивание`. При каждой печати в этом случае будет сниматься карта стола.
- Если работаете в режиме без родного экрана и используете макрос [START_PRINT](https://github.com/ghzserg/zmod/wiki/Main_ru#start_print) в начальном G-коде, то при каждой печати тоже будет сниматься карта стола

  Для включения этой возможности нужно настроить один раз макрос [SAVE_ZMOD_DATA](https://github.com/ghzserg/zmod/wiki/Global_ru#save_zmod_data), параметр [PRINT_LEVELING](https://github.com/ghzserg/zmod/wiki/Global_ru#zshaper)

  ```SAVE_ZMOD_DATA PRINT_LEVELING=1``` *(нужно вводить к консоль Fluidd/Mainsail)*. В этом случае карта стала будет сниматься при каждой печати.

  *Для работы снятия карты стола с родного экрана необходимо, через меню экрана принтера перейти на вкладку `Настройки` -> `Иконка WiFi` -> `Сетевой режим` -> включить ползунок `Только локальные сети`*

  *Если этот параметр активен, то любые параметры START_PRINT, относящиеся к построению/использованию карты стола игнорируются(FORCE_LEVELING, FORCE_KAMP, SKIP_LEVELING, MESH).*

Параметр `USE_KAMP`:
- Можно включить адаптивное снятие карты стола (KAMP), тогда  будет сниматься не весь стол, а только те части, где есть модели для печати. 
  **Автоматически снятие карты стола не запускается!**. Этот параметр говорит, что если вызывается снятие карты стола, то запускать вместо него KAMP.

  Для включения этой возможности нужно настроить один раз макрос [SAVE_ZMOD_DATA](https://github.com/ghzserg/zmod/wiki/Global_ru#save_zmod_data), параметр [USE_KAMP](https://github.com/ghzserg/zmod/wiki/Global_ru#zshaper)

  ```SAVE_ZMOD_DATA USE_KAMP=1``` *(нужно вводить к консоль Fluidd/Mainsail)*. В этом случае, будет использоваться адаптивная карта стола везде, где возможно, в том числе и при снятии карты стола родным экраном по сети. 

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#faq)

</div>

---

#### Через изменение стартового кода и макрос START_PRINT

Если вы не хотите пользоваться глобальными параметрами *(SAVE_ZMOD_DATA PRINT_LEVELING=0)*, то вам доступны следующие параметры макроса [START_PRINT](https://github.com/ghzserg/zmod/wiki/Main_ru#start_print), который прописывается в стартовый G-код.
- FORCE_LEVELING - принудительно строить карту стола, True - строить, False - не строить (False)
- FORCE_KAMP - запустить построение адаптивной карты стола, True - да, False - нет (False)
- SKIP_LEVELING - не строить карту стола ни при каком условии. Сильнее FORCE_KAMP и FORCE_LEVELING (False)
- MESH - имя карты стола, которую подгружать, если не задано, то ничего не подгружается, если не существует то будет создана ("")

Примеры:

Снятие полной карты стола:
```
START_PRINT EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single] FORCE_LEVELING=True
M190 S[bed_temperature_initial_layer_single]
M104 S[nozzle_temperature_initial_layer]
```

Снятие адаптивной карты стола
```
START_PRINT EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single] FORCE_KAMP=True
M190 S[bed_temperature_initial_layer_single]
M104 S[nozzle_temperature_initial_layer]
```

Алгоритм снятия карты стола в макросе [START_PRINT](https://github.com/ghzserg/zmod/wiki/Main_ru#start_print):
1. Если MESH не пустой, то загружается карта с именем записанном в параметре MESH
2. Если SKIP_LEVELING = True - то карта стола не будет сниматься ни при каких условиях
3. В противном случае, если стоит `FORCE_CAMP=True`, то снимается KAMP
4. В противном случае, если не загружена карта стола (родная голова всегда грузит карту `MESH_DATA`) или если `FORCE_LEVELING=True`, то запускается построение карты стола, но она сама не сохраняется

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#faq)

</div>

---

#### Через макросы и кнопки во Fluidd

Если вы не хотите использовать макрос `START_PRINT` и глобальные параметры, то доступны следующие макросы:
- [AUTO_FULL_BED_LEVEL](https://github.com/ghzserg/zmod/wiki/Calibrations_ru#auto_full_bed_level) - снятие карты стола с очисткой сопла при заданной температуре стола и экструдера. *Выключает нагрев после снятия карты.*. 

   Этот же макрос можно вызвать кнопкой Fluidd/Mainsail, называется он `КАЛИБРОВКА СТОЛА`. Сняв карту стола при определенной температуре, можно нажать кнопку `Сохранить параметры` и карта стола сохранится в файл `printer.cfg`.

   Также его можно прописать в стартовый G-код:
   ```
   AUTO_FULL_BED_LEVEL EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single]
   M190 S[bed_temperature_initial_layer_single]
   M104 S[nozzle_temperature_initial_layer]
   ```
- [KAMP](https://github.com/ghzserg/zmod/wiki/Calibrations_ru#kamp) - Адаптивная калибровка стола с очисткой сопла
  ```KAMP EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single]```
- BED_MESH_CALIBRATE - снятие карты стола стандартным макросом klipper. **Не рекомендуется использовать**, т.к. не производится очистка сопла, а значит результаты будут некорректными. **Адаптивная карта  стола  из Orca, совсем не рекомендуется**, т.к. в ней нет рандомизации снятия точек, а это значит что при печати одинаковых моделей сопло каждый раз будет брать замеры в одних и тех же точках, что приведет к появлению микролунок, и как следствие к некорректной карте стола.

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#faq)

</div>

---

#### Используя стандартные команды KLIPPER

Для работы с MESH, есть стандартные макросы Klipper:
- [BED_MESH_CALIBRATE](https://www.klipper3d.org/G-Codes.html#bed_mesh_calibrate) - снять карту стола
- [BED_MESH_OUTPUT](https://www.klipper3d.org/G-Codes.html#bed_mesh_output) - вывести карту стола
- [BED_MESH_PROFILE](https://www.klipper3d.org/G-Codes.html#bed_mesh_profile) - загрузить, удалить, сохранить карту стола

Если вы загружаете карту, через команды KLIPPER в профиле прутка, убедитесь что у вас используется одна и таже карта в `START_PRINT` и профиле прутка, или отключайте очистку сопла в START_PRINT и запускайте ее отдельно через профиль прутка.

Настоятельно рекомендуется прочитать варианты очистки сопла:
- [CLEAR_NOZZLE](https://github.com/ghzserg/zmod/wiki/Global_ru#clear_nozzle) - Очистка сопла как в родной прошивке
- Параметр [PRECLEAR](https://github.com/ghzserg/zmod/wiki/Global_ru#preclear) - Дополнительная очистка сопла при снятии карты стола.
- Параметр [CLEAR](https://github.com/ghzserg/zmod/wiki/Global_ru#clear) - четыре алгоритма (можно добавить свой) очистки сопла линией, перед печатью.

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#faq)

</div>

---

### Почему в документации периодически встречаются названия животных?

Документацию никто не любит/не хочет и не читает, хотя 90% вопросов в ней решено и описано.

Те кто ее не читает также любят говорить, что все прочли.

Поэтому я в тексте  раскидал названия животных *опоссум* и буду спрашивать их, когда  зададут очередной вопрос из документации. Если не смогли назвать животное, которое было спрятано в тексте на ваш вопрос, значит не читали документацию.

Если вас направили сюда. Прочтите документацию и назовите животное, которое написано по вашему вопросу и вам обязательно помогут:
- [Частые вопросы](https://github.com/ghzserg/zmod/wiki/FAQ)
- [Рекомендации по повышению стабильности работы принтера](https://github.com/ghzserg/zmod/wiki/Recomendations)
- [Установка/Обновление/Удаление мода](https://github.com/ghzserg/zmod/wiki/Setup)
- [Список Макросов](https://github.com/ghzserg/zmod/wiki/Macros)
- [Хранение настроек](#%D1%85%D1%80%D0%B0%D0%BD%D0%B5%D0%BD%D0%B8%D0%B5-%D0%BD%D0%B0%D1%81%D1%82%D1%80%D0%BE%D0%B5%D0%BA)
- [Известные особенности](#%D0%B8%D0%B7%D0%B2%D0%B5%D1%81%D1%82%D0%BD%D1%8B%D0%B5-%D0%BE%D1%81%D0%BE%D0%B1%D0%B5%D0%BD%D0%BD%D0%BE%D1%81%D1%82%D0%B8)

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#faq)

</div>

---

### Чем отличается работа с экраном и без родного экрана
 
**Не отключайте экран, если вы четко не понимаете как работает карта стола, z-offset и макросы START_PRINT и END_PRINT**

В нашем принтере  128 мегабайт памяти, половину ест система, а 13 мегабайт (20 в старых версиях родной прошивки) съедает управление родным экраном. 

Если [отключить родной экран](https://github.com/ghzserg/zmod/wiki/System_ru#display_off), то мы экономим память. 

Но в этом случае начинают по другому работать встроенные средства печати (cтарт печати, пауза, восстановление, отмена, окончание печати, отправка файлов на печать, восстановление после сбоя электропитания). 

Именно поэтому необходимо менять стартовый и конечный G код. *лось*

Также, при работе в режиме без родного экрана, принтер не выставляет Z-offset записанный на экране, и его необходимо передавать как параметр в [START_PRINT](https://github.com/ghzserg/zmod/wiki/Main_ru#start_print) или через глобальные параметры. [Подробнее](https://github.com/ghzserg/zmod/wiki/FAQ#%D0%BA%D0%B0%D0%BA-%D1%80%D0%B0%D0%B1%D0%BE%D1%82%D0%B0%D0%B5%D1%82-z-offset)

Прочитайте [особенности работы без родного экрана](#%D0%BE%D1%81%D0%BE%D0%B1%D0%B5%D0%BD%D0%BD%D0%BE%D1%81%D1%82%D0%B8-%D0%B2%D0%B5%D1%80%D1%81%D0%B8%D0%B8-%D0%B1%D0%B5%D0%B7-%D1%80%D0%BE%D0%B4%D0%BD%D0%BE%D0%B3%D0%BE-%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0).

И перейти на протокол Octo/Klipper

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#faq)

</div>

---

### Я хочу удалить ZMOD - мне придется все перекалибровать?

Нет - все настройки сохраняются

### Что такое альтернативная камера?
 
Родная камера, которая включается с экрана имеет ряд недостатков.
- Высокое потребление оперативной памяти
- Низкое  качество картинки
- Только одно соединение с камерой. Открыв ее в орке, в браузере вы ее уже не увидите
- Периодические отвалы изображения

Альтернативная камера, позволяет изменить разрешение, fps, разрешить множественные подключения, не пережимает картинку, легко перезапускается и настраивается [макросом](https://github.com/ghzserg/zmod/wiki/Zmod_ru#camera_on). *заяц*

- Отключите на экране принтера родную камеру.
- Вызовите макрос [CAMERA_ON](https://github.com/ghzserg/zmod/wiki/Zmod_ru#camera_on)

Прочитайте: [Я установил принтер, а ZMOD спрятал мою камеру!](https://github.com/ghzserg/zmod/wiki/FAQ#%D1%8F-%D1%83%D1%81%D1%82%D0%B0%D0%BD%D0%BE%D0%B2%D0%B8%D0%BB-%D0%BF%D1%80%D0%B8%D0%BD%D1%82%D0%B5%D1%80-%D0%B0-zmod-%D1%81%D0%BF%D1%80%D1%8F%D1%82%D0%B0%D0%BB-%D0%BC%D0%BE%D1%8E-%D0%BA%D0%B0%D0%BC%D0%B5%D1%80%D1%83-%D0%B2-orca-ff-%D1%8F-%D0%B5%D0%B5-%D0%B2%D0%B8%D0%B4%D0%B5%D0%BB-%D0%B0-%D1%82%D0%B5%D0%BF%D0%B5%D1%80%D1%8C-%D0%BE%D0%BD%D0%B0-%D0%BF%D1%80%D0%BE%D0%BF%D0%B0%D0%BB%D0%B0)

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

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#faq)

</div>

---

### Я установил принтер, а ZMOD спрятал мою камеру! В Orca-FF я ее видел, а теперь она пропала!
 
В веб интерфейсе (fluidd) зайти в `Настройки` -> `Видеокамеры`. 

Там уже будет одна видеокамера "Пример_настройки_камеры". Зайти в нее и посмотреть настройки.

**Создайте новую камеру** c настройками по аналогии камеры "Пример_настройки_камеры":
- Тип потока: `MJPEG-поток`
- URL-адрес потока: `http://your_IP:8080/?action=stream`
- URL-адрес снимка: `http://your_IP:8080/?action=snapshot`
- your_IP - замените на IP адрес вашего принтера.

В версиях старше `1.4.3`, также можно указать:
- Тип потока: `MJPEG-поток`
- URL-адрес потока: `/webcam/?action=stream`
- URL-адрес снимка: `/webcam/?action=snapshot`

Если хотите настраивать разрешение, fps, использовать камеру из Telegram бота, снизить потребление оперативной памяти, разрешить параллельные подключения, то нужно использовать [альтернативную камеру](https://github.com/ghzserg/zmod/wiki/Zmod_ru#camera_on). *крот*

На роутере поставьте *статический ip адрес для принтера* иначе он будет меняться, а камера  отваливаться.

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#faq)

</div>

---

### У меня появилось 2 камеры / как отключить/повернуть камеру

Если у вас нет камеры, или настройки автоматической камеры вас не устраивают, то через Fluidd/Mainsail нужно открыть файл `mod_data/user.moonraker.conf`

И вписать:

Для отключения камеры:
```
[webcam video]
enabled: false
```

Для поворота камеры:
```
[webcam video]
rotation: 90
```

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#faq)

</div>

---

### Я установил последнюю версию, а разработчик говорит что надо обновиться.

- Удостоверьтесь, что вы поставили последнюю версию с флэшки
- Зайдите  в веб интерфейс. `Настройки` -> `Обновления ПО` -> Нажать `Проверить обновление`
- Обновите все компоненты *древолаз*
- Перезагрузите принтер

<img width="1239" height="535" alt="image" src="https://github.com/user-attachments/assets/b42c4ce9-1c0a-45c0-a20c-36919a27d648" />

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#faq)

</div>

---

### Can not update MCU

После перезагрузки появляется ошибка 
```
!! Can not update MCU 'eboard' config as it is shutdown
```

Перезагрузка принтера нештатный режим работы. 

Именно поэтому при установке родной прошивки просят выключить питание и включить его обратно.

При перезагрузке питание с MCU не снимается, а значит программа записанная в MCU продолжает работу. Эта программа пытается связаться с клипером, который недоступен во время перезагрузки, и вызывает зависание или отключение MCU.

В этом случае вам нужно выбрать один вариант:
- Вызвать `FIRMWARE_RESTART` - в этом случае зависнет родной экран.
- Выключить питание принтера и включить

Отличие `REBOOT` от `FIRMWARE_RESTART` в том, что `REBOOT` перезагружает linux, а с ним и Klipper на материнской плате, `FIRMWARE_RESTART` частично перезапускает klipper и полностью перезапускает MCU

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#faq)

</div>

---

### Что такое МАКРОС? Как его запускать, качать использовать.

Макрос - это небольшая программа на языке Klipper/Gcode. 

Он может вызываться:
- Из файла GCODE
- Из консоли Fluidd/Mainstaill
*ежик*

[Список макросов](https://github.com/ghzserg/zmod/wiki/Macros)

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#faq)

</div>

---

### Я захожу на принтер через Orca/браузер, а вижу Welcome to Moonraker

Итак какие порты  использует ZMOD:
- `7125` - тут находится `Moonraker`
- `8080` - тут находится камера
- `80` - тут работает `Fluidd/Mainsail`

Чтобы зайти на принтер, надо ввести просто IP принтера, **без указания номера порта**. *кролик*

[Как настроить в Orca](https://github.com/ghzserg/zmod/wiki/Recomendations#%D0%BE%D1%82%D0%BF%D1%80%D0%B0%D0%B2%D0%BB%D1%8F%D0%B9%D1%82%D0%B5-%D1%84%D0%B0%D0%B9%D0%BB%D1%8B-%D0%BD%D0%B0--%D0%BF%D0%B5%D1%87%D0%B0%D1%82%D1%8C-%D1%87%D0%B5%D1%80%D0%B5%D0%B7-octoklipper)

### Я переключил веб интерфейс и теперь ничего не работает.

Если вы переключили интерфейс макросом [WEB](https://github.com/ghzserg/zmod/wiki/System_ru#web) *выхухоль*

Первым делом нужно нажать `Ctrl + F5` или `Ctrl + Shift + R` или `Option + Command + E`

Если у вас проблема в Orca, то нужно нажать `Ctrl + F5` или `Ctrl + Shift + R` или `Option + Command + E` *лисица*

Если вы пользуетесь другим браузером, то нужно очистить кэш и куки, зайти по IP адресу принтера без дополнительных символов в адресной строке.

`http://ИП_ПРИНТЕРА/`

Если не помогает, то использовать другой браузер: Firefox, Chrome, Yandex, Opera и т.д.

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#faq)

</div>

---

### В ZMOD входит Entware - как им воспользоваться?

**Внимание! В [AD5X](https://github.com/ghzserg/zmod/wiki/AD5X) нет Entware**

Нужно зайти по SSH на принтер (`root`:`root` порт `22`)

Выполнить команду
`
export PATH="$PATH:/opt/bin/:/opt/sbin/"
`

Далее можно запустить `mc` или `opkg`

- Обновление базы пакетов: `opkg update`
- Установка пакета: `opkg install mc`

Каталоги которые создаются и используются entware:
- /opt/bin
- /opt/etc
- /opt/home
- /opt/lib
- /opt/libexec
- /opt/root
- /opt/sbin
- /opt/share
- /opt/tmp
- /opt/usr
- /opt/var

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#faq)

</div>

---

### Что такое откат из прошивки?

В ZMOD во Fluidd/Mainsail есть ползунки управления скоростью и величиной отката из прошивки. 

Они не влияют на печать, если g-code файл нарезан без использования параметров отката из прошивки.

Откат из прошивки позволяет менять величину отката во время печати, без необходимости перенарезать весь файл.

Вместо громоздких команд отката вроде `G1 E-.5 F2100` для ретракта теперь используется короткая `G10`, а вместо `G1 E.5 F2100` для обратного ретракта используется `G11`.

Чтобы воспользоваться откатом из прошивки, в Orca.

`Настройки принтера` -> `Общая информация` -> `Дополнительно` -> `Исп. откат из прошивки` поставить галочку

Если вы хотите поменять параметры отката по умолчанию в прошивке:

Через Fluidd. `Конфигурация` -> `mod_data` -> `user.cfg`
```
[firmware_retraction]
retract_length: 0.9
retract_speed: 35
unretract_extra_length: 0
unretract_speed: 35
```

`SET_RETRACTION` обычно устанавливается как часть конфигурации слайсера для каждого филамента, так как для разных филаментов требуются разные настройки параметров:
SET_RETRACTION [RETRACT_LENGTH=<мм>] [RETRACT_SPEED=<мм/с>] [UNRETRACT_EXTRA_LENGTH=<мм>] [UNRETRACT_SPEED=<мм/с>]: Настройка параметров, используемых для ретрактов. 
- RETRACT_LENGTH - длина нити для втягивания и оттягивания. 
- RETRACT_SPEED - скорость втягивания. 
- UNRETRACT_SPEED - скорость оттягивания регулируется с помощью UNRETRACT_SPEED и не особенно критична, хотя часто ниже, чем RETRACT_SPEED.
- UNRETRACT_EXTRA_LENGTH - в некоторых случаях полезно добавить небольшое количество дополнительной длины при оттягивании.

Пример установки RETRACTION на Orca:

`Профиль прутка` -> `Переопределение параметров` -> `Откат` -> `Длина`

`Профиль прутка` -> `Дополнительно` -> `Стартовый G-код прутка`
```
SET_RETRACTION RETRACT_LENGTH=[filament_retraction_length]
```

`GET_RETRACTION`: запрашивает текущие параметры, используемые при откате, и отображает их на терминале.

Вариант подстановки ретракта от [@minicx](https://github.com/loss-and-quick/)
```
SET_RETRACTION RETRACT_LENGTH={if not is_nil(filament_retraction_length[current_extruder])}[filament_retraction_length[current_extruder]]{else}[retraction_length]{endif} RETRACT_SPEED={if not is_nil(filament_retraction_speed[current_extruder])}[filament_retraction_speed[current_extruder]]{else}[retraction_speed]{endif}
```

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#faq)

</div>

---

### AD5X

[AD5X](https://github.com/ghzserg/zmod/wiki/AD5X)

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#faq)

</div>

---

### help

### Как обратиться в поддержку к разработчику

[Инструкция перенесена](https://github.com/ghzserg/zmod/wiki/Help)

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#faq)

</div>

---

### Как изменить логотип загрузки

Логотип лежит в папке ```mod_data/logo```

Требования к логотипу:
- Размер 800x480 глубина цвета 24 бита
- AD5M: формат BMP. Имя файла: ```bootlogo.bmp```
- AD5X: формат JPG. Имя файла: ```logo.jpeg```

Загрузите свой логотип в папку ```mod_data/logo```.

Перезагрузите принтер 2 раза.

При удалении мода родное лого восстановится. Если этого не произошло на AD5M:
- Нужно установить мод
- Загрузить в папку `mod_data/logo` файл [boot.bmp](https://github.com/ghzserg/zmod/releases/download/R/boot.bmp)
- Перезагрузить принтер

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#faq)

</div>

---

### No trigger on probe after full movement

Ошибка в основном возникает, если подъема оси z при замере недостаточно.

Програмно это правится вот так:

Внести в ```mod_data/user.cfg```
```
[bed_mesh]
horizontal_move_z: 5
```

Аппаратно - все винты должны быть отрегулированы и у стола не должно быть перекосов.

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#faq)

</div>

---

### WeightValue

WeightValue - это значение на тензодатчиках в граммах. Оно тображается в градусах, т.к реализовано через интерфейс термодатчика. Поэтому Fluidd и Mainsail отображают градусы.

Зачем нужен этот датчик?

- С его помощью можно замерять zoffset через плагин [g28_tenz](https://github.com/ghzserg/g28_tenz)
- Можно прекращать печать, если сопло ударилось о деталь или детать была оторвана. [NOZZLE_CONTROL](https://github.com/ghzserg/zmod/wiki/Global_ru#nozzle_control)
- Без его сброса замер карты стола  будет некорректным

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#faq)

</div>

---

### MCU Protocol error

Вот некоторые ошибки, которые зависят от MCU:
- MCU Protocol error
- Unknown temperature sensor flashforge_loadcell
- Required MCU command
- flashforge_loadcell: Required MCU command 'flashforge_loadcell_h1' is not available

Суть всех этих ошибок в том, что версия Klipper не соответсвует версии MCU.

Посмотреть версию MCU можно на вкладке `Система`

<img width="700" height="396" alt="{9CCFD772-CCDB-42ED-B952-DA15231DCF68}" src="https://github.com/user-attachments/assets/80e6a573-b372-4620-a7bc-7cbf020bc874" />

<img width="438" height="277" alt="{52EC8847-ACAB-461D-A9FA-633CDAF180CC}" src="https://github.com/user-attachments/assets/9bba3ff2-9a0e-4aa6-8327-f93fd1b46c3a" />


Например у вас запущен Klipper 13, а используется MCU от 11 или 12 Klipper.

Или наоборот. Вы работаете с родным Klipper - а загрузили MCU для 13 Klipper.

Если у вас версия MCU начинается с ```?-20230317_182329-ubuntu20-virtual-machine``` - значит загружен MCU для Klipper 12 (AD5X) или Klipper 11 (Ad5M/Ad5mPro).

Соотвенно нужно чтобы zMod загрузил родной Klipper.

- Заходим ```mod_data/variables.cfg``` и удаляем строчку ```klipper13 = 1```.
- Сохраняем файл
- Выключаем принтер и включаем его (не перезагружаем!)

Если же у вас запущен MCU для 13 Klipper, то его версия **должна** совпадать с версией мода.

Пример:
- MCU: v0.13.0-**375**-gba79d72f-dirty
- zMod: 1.6.2.**375**-170

Как видим версия **375** совпала - значит все в порядке.

Если это не так и Klipper работает, то делаем ```UPDATE_MCU FORCE=13``` - эта команда  установит актуальную версию MCU

Если ничего не помогает и **Klipper не работает**:
- Переходим на родной Klipper как было написано выше.
- [Устанавливаем родную Factory прошивку](https://github.com/ghzserg/zmod/wiki/R#%D0%BA%D0%B0%D0%BA-%D1%83%D1%81%D1%82%D0%B0%D0%BD%D0%BE%D0%B2%D0%B8%D1%82%D1%8C-%D1%80%D0%BE%D0%B4%D0%BD%D1%83%D1%8E-%D0%BF%D1%80%D0%BE%D1%88%D0%B8%D0%B2%D0%BA%D1%83), которая установит родной MCU.

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#faq)

</div>

---

### Кончился или остановился филамент

Для AD5M нужно подбором откаллибровать шаги датчика. Пропишите в `mod_data/user.cfg`

Увеличивайте это число. Кому-то хватает стандартных `8`, а некоторые датчики корректно работают только при `17`
```
[filament_motion_sensor e0_sensor]
detection_length: 8
```

Остановился филамент (IFS).

Для AD5X нужно подбором откаллибровать шаги датчика IFS. Пропишите в `mod_data/user.cfg`

Увеличивайте это число. Кому-то хватает стандартных `10`, а некоторые IFS корректно работают только при `17`
```
[zmod_ifs_motion_sensor ifs_motion_sensor]
detection_length: 8
```

Также остановка филамента в IFS может быть связана:
- В экструдере пруток 1, а вытягивается пруток 2. Используйте [SET_EXTRUDER_SLOT](https://github.com/ghzserg/zmod/wiki/AD5X#5-%D0%BA%D0%B0%D0%BA-%D0%B2%D1%80%D1%83%D1%87%D0%BD%D1%83%D1%8E-%D1%83%D0%BA%D0%B0%D0%B7%D0%B0%D1%82%D1%8C-%D0%BF%D1%80%D0%B8%D0%BD%D1%82%D0%B5%D1%80%D1%83-%D0%BA%D0%B0%D0%BA%D0%B0%D1%8F-%D0%BA%D0%B0%D1%82%D1%83%D1%88%D0%BA%D0%B0-%D1%81%D0%B5%D0%B9%D1%87%D0%B0%D1%81-%D0%B7%D0%B0%D0%BF%D1%80%D0%B0%D0%B2%D0%BB%D0%B5%D0%BD%D0%B0-ad5x).
- В экструдер вставляется пруток, но в нем уже есть старый пруток
- Модули 4 в 1 и трубки к ним имеют разную длину, поэтому нужно отрегулировать параметр ```nozzle_cleaning_length``` в ```mod_data/filament.json``` установив его 70 или больше. [Подробнее](https://github.com/ghzserg/zmod/wiki/AD5X#%D1%81%D0%B0%D0%BC%D1%8B%D0%B5-%D0%B2%D0%B0%D0%B6%D0%BD%D1%8B%D0%B5-%D0%BD%D0%B0%D1%81%D1%82%D1%80%D0%BE%D0%B9%D0%BA%D0%B8-%D1%87%D1%82%D0%BE-%D0%BC%D0%B5%D0%BD%D1%8F%D1%82%D1%8C-%D1%87%D0%B0%D1%89%D0%B5-%D0%B2%D1%81%D0%B5%D0%B3%D0%BE-ad5x)

Также проблема может быть вызвана невозможностью разблокировать пруток в канале IFS.

Причины чисто механические:
- попадание пластиковой стружки на вал прижима
- соскакивание пружины с рычага канала.

Требуется устранить стружку, разобрать и установить детали на место.

После этого протестировать печать и блокировку/разблокировку прутков через [команды IFS](https://github.com/ghzserg/zmod/wiki/AD5X#10-ifs-%D0%BA%D0%BE%D0%BC%D0%B0%D0%BD%D0%B4%D1%8B).

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#faq)

</div>

---

### Перед каждой печатью измеряет стол по цетру

Перед печатью принтер:
- нагревает стол и сопло.
- очищает сопло.
- остужает сопло
- **делает замер по центру стола** (Starting manual Z probe. Use TESTZ to adjust position)
- нагревает сопло
- начинает печать

Это особенность **родной прошивки** начиная с версии:
- 1.1.8 AD5X
- 3.2.4 AD5M/AD5MPro

Решение:
- [Откатить родную прошивку](https://github.com/ghzserg/zmod/wiki/R) на версию **1.1.7** для AD5X, **3.2.3** для FF5M/FF5MPro
- [Отключить родной экран](https://github.com/ghzserg/zmod/wiki/System_ru#display_off)

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#faq)

</div>

---

### E0120

Это ошибка Klipper.

Чаще всего исправляется следующими простыми действиями:
- Выключить питание принтера
- Подождать 10 секунд
- Включить питание принтера

Чтобы посмотреть какая именно ошибка:
- откройте Fluidd/Mainsail
- перейдите в консоль и прочитайте текст ошибки
- откройте телеграм бот [@zmod_help_bot](http://t.me/zmod_help_bot) и введите текст ошибки или найдите описание в документации самостоятельно

Если не получается исправить, то [нужно создать тикет](https://github.com/ghzserg/zmod/wiki/Help).

[Родные конфиги](https://github.com/ghzserg/zmod/tree/main/Native_firmware/config/)

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#faq)

</div>
