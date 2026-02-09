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

## Установка классических плагинов Klipper с Python модулями

Для классических плагинов Klipper, которые работают с использованием Python модулей (например, [klipper-led_effect](https://github.com/julianschill/klipper-led_effect)), требуется специальный процесс установки с созданием символической ссылки на модуль Klipper.

### Пример: Установка led_effect

`led_effect` — это плагин для управления WS2812 RGB LED полосками через Klipper.

**Шаг 1: Клонируем репозиторий**

Выполните эти команды в chroot окружении:

```bash
# Для FF5M:
chroot /data/.mod/.zmod/
# Для FF5X:
chroot /usr/data/.mod/.zmod/

# Одинаково для всех моделей:
cd /opt/config/mod_data/plugins/
git clone https://github.com/julianschill/klipper-led_effect.git
```

**Шаг 2: Добавляем запись в Moonraker config**

В файле `mod_data/user.moonraker.conf` добавьте следующую секцию:

```ini
[update_manager led_effect]
type: git_repo
channel: stable
path: /opt/config/mod_data/plugins/klipper-led_effect
origin: https://github.com/julianschill/klipper-led_effect.git
is_system_service: False
primary_branch: master
```

**Шаг 3: Создаём символическую ссылку на модуль Klipper**

Создайте символическую ссылку для подключения модуля к Klipper:

```bash
ln -s /opt/config/mod_data/plugins/klipper-led_effect/src/led_effect.py /usr/prog/klipper/klippy/extras/led_effect.py
```

Замените:

- `klipper-led_effect` на папку вашего плагина
- `led_effect.py` на имя модуля (может быть другой в зависимости от плагина)

**Шаг 4: Перезагружаем Klipper**

После создания символической ссылки необходимо перезагрузить Klipper через веб-интерфейс Fluidd/Mainsail, нажав кнопку перезагрузки.

### Важные замечания

> **Модуль должен быть совместим с версией Klipper**
> Убедитесь, что версия плагина совместима с установленной версией Klipper.

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
