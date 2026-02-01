# Плагины в zMod

Любой пользователь может создать и подключить свой плагин к **zmod**.

Плагины включенные в поставку zMod:
1. [Recommend](https://github.com/ghzserg/recommend/blob/main/Readme_ru.md) - Настройки, которые рекомендуется использовать сразу после установки мода
2. [G28_tenz](https://github.com/ghzserg/g28_tenz/blob/main/Readme_ru.md) - Парковка оси Z по тензодатчикам
4. [Nopoop](https://github.com/ghzserg/nopoop/blob/master/Readme_ru.md) - Максимальное уменьшение количества отходов от ninjamida.
5. [TimeLapse](https://github.com/ghzserg/timelapse/blob/main/Readme_ru.md) - Moonraker TimeLapse
6. [Notify](https://github.com/ghzserg/notify/blob/main/Readme_ru.md) - Получение уведомлений в телеграм и еще более 100 различных сервисов

Внешние плагины, не разрабатываемых автором zMod.
1. [Bambufy](https://github.com/function3d/bambufy/blob/master/README_ru.md) - Совместим с Bambu Studio, улучшает управление башней подачи, обеспечивает точную оценку времени и расхода материала, снижает отходы, поддерживает Mainsail, быструю смену цвета и расширенные функции печати. НЕЛЬЗЯ ИСПОЛЬЗОВАТЬ С РОДНЫМ ЭКРАНОМ.
2. [lessWaste](https://github.com/Hrybmo/lessWaste/blob/master/README_ru.md) - форк BamBufy

Чтобы включить репозиторий внешних плагинов, не разрабатываемых автором zMod, выполните команду `ENABLE_EXTRA_PLUGINS`.

---

## Управление плагином

**Включить плагин:**
```gcode
ENABLE_PLUGIN name=g28_tenz
```
— скачает плагин и перезапустит Klipper при успехе.

**Выключить плагин:**
```gcode
DISABLE_PLUGIN name=g28_tenz
```

---

## Создание собственного плагина

Пример плагина: https://github.com/ghzserg/g28_tenz
(Во всех примерах ниже используется имя `g28_tenz` — замените его на имя вашего плагина.)

---

### Добавление плагина

В файле
```mod_data/user.moonraker.conf```
добавьте секцию:

```ini
[update_manager g28_tenz]
type: git_repo
channel: dev
path: /root/printer_data/config/mod_data/plugins/g28_tenz
origin: https://github.com/ghzserg/g28_tenz.git
is_system_service: False
primary_branch: main
```

- **Путь к плагину**: `/root/printer_data/config/mod_data/plugins/g28_tenz`
- **Источник**: `https://github.com/ghzserg/g28_tenz.git`

> Стабильные плагины могут быть включены в поставку zmod, но обновляются и управляются их авторами.

---

### Скрипт установки

После вызова `ENABLE_PLUGIN`, будет автоматически вызыван файл `install.sh`

После вызова `DISABLE_PLUGIN`, будет автоматически вызыван файл `uninstall.sh`

### Одноязычный плагин
Должен содержать файл:
```
g28_tenz.cfg
```
В нём — весь функционал.

### Многоязычный плагин
Файлы размещаются в подкаталогах по языкам:
```
en/g28_tenz.cfg
ru/g28_tenz.cfg
de/g28_tenz.cfg
...
```

Все строки вывода должны быть экранированы, например:
```gcode
RESPOND PREFIX="info" MSG="===Cutting the filament==="
```

---

#### Перевод

Переводы хранятся в каталоге `translate/` в файлах вида `de.csv`:

```csv
Cutting the filament;Filament schneiden
```

Формат:
```
Английская фраза;Перевод на нужный язык
```

Чтобы сгенерировать языковые файлы, выполните:
```bash
./Make.sh
```
Скрипт создаст нужные каталоги и `.cfg`-файлы.
