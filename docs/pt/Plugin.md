# Plug-ins no zMod

Qualquer usuário pode criar e conectar seu próprio plug-in ao **zmod**.

Plug-ins incluídos no zMod:

1. [Recommend](https://github.com/ghzserg/recommend/blob/main/Readme_ru.md) - Configurações que são recomendadas para uso imediatamente após a instalação do mod
2. [G28_tenz](https://github.com/ghzserg/g28_tenz/blob/main/Readme_ru.md) - Estacionamento do eixo Z por células de carga
4. [Nopoop](https://github.com/ghzserg/nopoop/blob/master/Readme_ru.md) - Maximizar a redução de resíduos da ninjamida.
5. [TimeLapse](https://github.com/ghzserg/timelapse/blob/main/Readme_ru.md) - Lapso de tempo do Moonraker
6. [Notify](https://github.com/ghzserg/notify/blob/main/Readme_ru.md) - Receba notificações no Telegram e em mais de 100 outros serviços diferentes

Plug-ins externos, não desenvolvidos pelo autor do zMod.

1. [Bambufy](https://github.com/function3d/bambufy/blob/master/README_ru.md) - Compatível com o Bambu Studio, melhora o controle da torre de alimentação, fornece estimativa precisa do tempo e do consumo de material, reduz o desperdício, oferece suporte ao Mainsail, troca rápida de cores e recursos avançados de impressão. NÃO PODE SER USADO COM A TELA NATIVA.
2. [lessWaste](https://github.com/Hrybmo/lessWaste/blob/master/README_ru.md) é uma bifurcação do BamBufy

Para ativar o repositório de plug-ins externos não desenvolvidos pelo autor do zMod, execute o comando `ENABLE_EXTRA_PLUGINS`.

---

## Gerenciar plug-in

**Habilitar plugin:**
```gcode
ENABLE_PLUGIN name=g28_tenz
```
- fará o download do plug-in e reiniciará o Klipper em caso de sucesso.

**Desativar o plug-in:**
````gcode
DISABLE_PLUGIN name=g28_tenz
```

---

## Instale os plug-ins clássicos do Klipper com módulos Python

Os plug-ins clássicos do Klipper que funcionam usando módulos Python (por exemplo, [klipper-led_effect](https://github.com/julianschill/klipper-led_effect)) exigem um processo de instalação especial com a criação de um link simbólico para o módulo Klipper.

#### Exemplo: Instalação do led_effect

O `led_effect` é um plug-in para controlar tiras de LED RGB WS2812 por meio do Klipper.

**Etapa 1: Clonar o repositório**

Execute estes comandos em um ambiente chroot:

```bash
# Para o FF5M:
chroot /data/.mod/.zmod/
# Para o FF5X:
chroot /usr/data/.mod/.zmod/

# O mesmo para todos os modelos:
cd /opt/config/mod_data/plugins/
git clone https://github.com/julianschill/klipper-led_effect.git
```

**Etapa 2: adicionar uma entrada à configuração do Moonraker**

No arquivo `mod_data/user.moonraker.conf`, adicione a seguinte seção:

```ini
[update_manager led_effect].
tipo: git_repo
canal: stable
caminho: /opt/config/mod_data/plugins/klipper-led_effect
origem: https://github.com/julianschill/klipper-led_effect.git
is_system_service: False
primary_branch: master
```

**Etapa 3: criar um link simbólico para o módulo Klipper**

Crie um link simbólico para conectar o módulo ao Klipper:

```bash
ln -s /opt/config/mod_data/plugins/klipper-led_effect/src/led_effect.py /usr/prog/klipper/klippy/extras/led_effect.py
```

Substitua por:

- `klipper-led_effect` na pasta do seu plug-in
- `led_effect.py` para o nome do módulo (pode ser diferente dependendo do plug-in)

**Etapa 4: Recarregar o Klipper

Depois de criar o link simbólico, você precisa recarregar o Klipper por meio da interface da Web do Fluidd/Mainsail, clicando no botão reload (recarregar).

### Notas importantes

> **O módulo deve ser compatível com a versão do Klipper**
> Certifique-se de que a versão do plug-in seja compatível com a versão instalada do Klipper.

---

## Crie seu próprio plug-in

Exemplo de plug-in: https://github.com/ghzserg/g28_tenz
(Todos os exemplos abaixo usam o nome `g28_tenz` - substitua-o pelo nome do seu plug-in).

---

### Adicionando um plug-in

No arquivo
```mod_data/user.moonraker.conf```.
adicione uma seção:

```ini
[update_manager g28_tenz].
tipo: git_repo
canal: dev
caminho: /root/printer_data/config/mod_data/plugins/g28_tenz
origem: https://github.com/ghzserg/g28_tenz.git
is_system_service: False
primary_branch: main
```

- **Caminho para o plug-in**: `/root/printer_data/config/mod_data/plugins/g28_tenz`.
- **Source**: `https://github.com/ghzserg/g28_tenz.git`.

> Os plug-ins estáveis podem ser incluídos no fornecimento do zmod, mas são atualizados e gerenciados por seus autores.

---

### Script de instalação

Depois de chamar `ENABLE_PLUGIN`, o arquivo `install.sh` será chamado automaticamente.

Depois de chamar `DISABLE_PLUGIN`, o arquivo `uninstall.sh` será chamado automaticamente.

### Plugin unilíngue
Deve conter o arquivo:
```
g28_tenz.cfg
```
Ele contém todas as funcionalidades.

### Plug-in multilíngue
Os arquivos são colocados em subdiretórios por idioma:
```
en/g28_tenz.cfg
ru/g28_tenz.cfg
de/g28_tenz.cfg
...
```

Todas as linhas de saída devem ter escape, por exemplo:
````gcode
RESPOND PREFIX="info" MSG="===Cortando o filamento==="
```

---

#### Tradução

As traduções são armazenadas no diretório `translate/` em arquivos com o formato `de.csv`:

```csv
Cortar o filamento;Filament schneiden
```

Formato:
```
Frase em inglês;Tradução para o idioma desejado
```

Para gerar arquivos de idioma, execute:
````bash
./Make.sh
```
O script criará os diretórios e os arquivos `.cfg` necessários.
