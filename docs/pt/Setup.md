### [Instalação](#installation-mod)

### Redefinir a impressora para as configurações padrão de fábrica (necessário para instalar o mod)

0. [Uninstall KlipperMod](https://github.com/xblax/flashforge_ad5m_klipper_mod/blob/master/docs/UNINSTALL.md) se ele tiver sido instalado
1. Redefinir a impressora para as configurações padrão
2. formatar o USB Flash para FAT/FAT16/FAT32
3. Coloque o arquivo de [Native firmware](/en/Native_FW/) na pasta raiz da unidade flash USB

    - Adventurer5M-3.1.9-2.2.3-20250807-Factory.tgz](https://github.com/ghzserg/FF/releases/download/R/Adventurer5M-3.1.9-2.2.3-20250807-Factory.tgz) para FF5m
    - Adventurer5MPro-3.1.3-2.2.3-20250107-Factory.tgz](https://github.com/ghzserg/FF/releases/download/R/Adventurer5MPro-3.1.3-2.2.3-20250107-Factory.tgz) para a versão FF5m**Pro
    - [AD5X-1.1.7-1.1.0-3.0.6-20250912.tgz](https://github.com/ghzserg/FF/releases/download/R/AD5X-1.1.7-1.1.0-3.0.6-20250912-Factory.tgz.gz) для AD5X

4. Desligue a impressora
5. Insira o pendrive USB na impressora
6. Ligue a impressora
7. Aguarde até que o firmware nativo seja instalado
8. Configure o WiFi ou a LAN *new beaver*
9. Obtenha as atualizações mais recentes da impressora ou instale o firmware 1.1.7 para AD5X ou 3.2.3 para [AD5M](https://github.com/ghzserg/FF/releases/download/R/Adventurer5M-3.2.3-2.2.3-20251016-Factory.tgz)/[AD5MPro](https://github.com/ghzserg/FF/releases/download/R/Adventurer5MPro-3.2.3-2.2.3-20251017-Factory.tgz) se você não quiser que a impressora [meça o centro da mesa antes de cada impressão](https://wiki.zmod.link/pt/FAQ/#mede-a-tabela-centralizada-antes-de-cada-trabalho-de-impress%C3%A3o)

---

## Instalando o mod

[Vídeo](https://www.youtube.com/watch?v=2sfb2OtY7wM)

1. **[Retornar a impressora às configurações de fábrica](/pt/Setup/#return-printer-to-factory-settings-necessary-for-installing-mod)** [Caution AD5X](/pt/Setup/#caution-ad5x)
2. formate o flash USB para FAT/FAT16/FAT32
3. Coloque [file](https://github.com/ghzserg/zmod/releases/) na pasta raiz do USB Flash.

    - Para o FF5M: Adventurer5M-**zmod**-\*.tgz
       - Para o FF5MPro: Adventurer5MPro-**zmod**-\*.tgz
       - para [AD5X](/pt/AD5X/): AD5X-**zmod**-\*.tgz

4. Desligue a impressora
5. Insira o pendrive USB na impressora
6. Ligue a impressora
7. Aguarde até que o mod seja instalado

   <img width="800" height="480" alt="install" src="https://github.com/user-attachments/assets/9d6b9ad7-e9ec-4bc2-bd8f-54c945b5add5" />
   
   <img width="800" height="480" alt="screenshot" src="https://github.com/user-attachments/assets/19d66329-72f9-4e92-aba6-35b7820ce9a0" />
   
   No AD5X, a instalação pode levar até 40 minutos

8. Remova a unidade USB
9. Desligue a impressora
10. Ligue a impressora
11. **Abra o IP da impressora no navegador**
    <img width="800" height="480" alt="main" src="https://github.com/user-attachments/assets/a0466fa8-03e8-458d-8cc5-c1efb8f565ac" />
    <img width="800" height="480" alt="ip" src="https://github.com/user-attachments/assets/1d7dd5fa-86f4-4b1a-bd42-364619b20229" />
    
    Se a interface da Web não abrir, o firmware nativo desativou o mod. Para ativá-lo, é necessário gravar no arquivo flash USB [AD5X-ENABLE-zmod.tgz](https://github.com/ghzserg/FF/releases/download/R/AD5X-ENABLE-zmod.tgz) e [activate mod](/pt/R//#ad5x-enable-zmodtgz).
     
12. Traduza o mod para seu idioma.
    
    <img width="564" height="583" alt="{8E14F84D-E8D1-4129-B192-AA335243A3D9}" src="https://github.com/user-attachments/assets/e6dd3f8a-3cc3-4a05-b5fb-ad8ba372ede6" />
    
    Ou, no console, digite ````LANG LANG=ru```.
    
    <img width="881" height="502" alt="image" src="https://github.com/user-attachments/assets/cf3f797d-80e0-4864-85b4-cd28886590f4" />

13. Configure o mod
    
    <img width="558" height="219" alt="{B34D2AF2-F2A6-433D-B9F8-86A83389D5A7}" src="https://github.com/user-attachments/assets/a79ec692-a284-4cb8-a0ad-3be10f33d813" />
    
    Isso mostra os parâmetros que são usados no início, no final e os parâmetros globais. Recomenda-se que você apenas leia as configurações, mas não as altere. O valor de cada configuração pode ser [visualizado aqui](/pt/Global/)

    <img width="561" height="443" alt="{623507C1-D3AB-4FEF-9A92-E949A85DCB49}" src="https://github.com/user-attachments/assets/3a8028bf-b078-4edc-827b-07e9d49c52f9" />

    Você precisa ir até a última tela e pressionar `Ok` ou `Reboot`. Se não fizer isso, esta janela aparecerá toda vez que você inicializar

    <img width="564" height="228" alt="{BCEBDCCC-0703-46F3-8B7B-3BC58E78F27A}" src="https://github.com/user-attachments/assets/72d386a4-18ba-40a9-8f85-a6109a4e4c57" />

    Se quiser ver essa janela novamente, digite `GLOBAL` no console

14. Vá para `Configurações` -> `Atualizações de software`.
15. Clique em `Check for updates` e aguarde até que as atualizações sejam verificadas
16. Clique em **Update** e atualize todos os componentes.
    <img width="1239" height="535" alt="image" src="https://github.com/user-attachments/assets/b42c4ce9-1c0a-45c0-a20c-36919a27d648" />

    Se ele mostrar muitos erros, isso é normal. Os plug-ins não fazem parte do firmware e são baixados separadamente. Você precisa clicar em `Check for updates`.
    E restaurar e atualizar todos os plug-ins, um por um. A impressora será reinicializada.
    
    <img width="671" height="844" alt="image" src="https://github.com/user-attachments/assets/d6fe3ad0-64be-4c07-8f5e-53647a6bd6ee" />

17. Ative o [plug-in de recomendação](https://github.com/ghzserg/recommend/blob/main/Readme_ru.md)
    
    <img width="560" height="224" alt="{E27E192D-3FC2-49AC-BEAF-F7B574FFEF45}" src="https://github.com/user-attachments/assets/dade8a2e-fc67-4df5-aad4-85cc5cd81d66" />

    Ou digite ````ENABLE_PLUGIN name=recommend``` no console.

    <img width="864" height="87" alt="image" src="https://github.com/user-attachments/assets/ca96c67f-cc58-4655-8fdf-9554d1a489a3" />

18. [Personalizar o Orca](/pt/Recomendations/#send-files-to-print-octoklipper)
    Todo o código inicial precisa ser substituído por este:

    ```
    START_PRINT EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single]
    M190 S[bed_temperature_initial_layer_single]
    M104 S[nozzle_temperature_initial_layer]
    SET_PRINT_STATS_INFO TOTAL_LAYER=[total_layer_count]
    ```
    
    ````START_PRINT EXTRUDER_TEMP= BED_TEMP=```` **deve ser escrito em uma linha**

    O código final para este:

    ```END_PRINT```

    <img width="612" height="443" alt="image" src="https://github.com/user-attachments/assets/0dfd8840-c183-4d33-92aa-46f882b8c32c" />

    Código antes de alterar a camada para esta:

    ````SET_PRINT_STATS_INFO CURRENT_LAYER={layer_num + 1}```.

    <img width="449" height="153" alt="image" src="https://github.com/user-attachments/assets/705fb49e-2c6b-451b-9b99-9d8d1f0e80f8" />

    É necessário mudar para o protocolo "Octo/Klipper":

      - Protocolo: `Octo/Klipper`.
          - Nome do host: `Nome_da_impressora_IP:7125`
          - Endereço URL do host: `IP_printer` ou `IP_printer:80`

    <img width="673" height="467" alt="image" src="https://github.com/user-attachments/assets/70d5da64-0604-44e5-9102-887b758b5cf0" />
    <img width="473" height="395" alt="image" src="https://github.com/user-attachments/assets/ca4c5330-dc88-4372-a3c8-51527ae76146" />

19. [Enable MD5 control](/pt/Recomendations/#enable-md5-control-md5)

    <img width="476" height="355" alt="image" src="https://github.com/user-attachments/assets/0b59a617-5613-4def-aa01-7fe038898863" />

20. [Leia as recomendações](/pt/Recomendations/)
21. [Read FAQ](/pt/FAQ/)

### Atenção AD5X

[@Khamai](https://t.me/Khamai)

Após a instalação do firmware nativo, é possível que o cabeçote de impressão esteja estacionado incorretamente no receptor de filamento (fixação inferior da cortina do receptor, filamento espremido na mesa, etc.).

[Através do menu de engenharia no firmware nativo](/pt/AD5X/#setup-basket-on-native-firmware-ad5x)

Se você se deparar com essa situação, precisará calibrar o estacionamento usando o seguinte algoritmo:

1. Faça o download do arquivo [Set.XY.Offset.zip](https://github.com/ghzserg/FF/releases/download/R/Set.XY.Offset.zip) e extraia-o para a raiz da unidade flash
2. Insira a unidade flash na impressora que está desligada e ligue-a. 3.
3 A interface de calibração aparecerá na tela da impressora. Você precisa pressionar Reset.
4. Use as setas de controle para estacionar o cabeçote de impressão no receptor de modo que o cabeçote tenha pressão suficiente sobre a alavanca do obturador, o bico fique atrás do obturador móvel e o próprio obturador fique nivelado com a superfície frontal do receptor.
5. Trave o resultado da calibração com o botão Set.
6. Remova o cartão de memória e reinicie a impressora.

---

## Atualize o mod

Se o mod disser `Update zMOD from flash drive`, você precisará atualizar o zMod a partir da unidade flash, mesmo que o tenha atualizado recentemente.

**Ao atualizar a partir de uma unidade USB, todos os dados são salvos.

**A maneira mais fácil de atualizar o zMod a partir de uma unidade USB é usar a macro [ZFLASH](/pt/Zmod/#zflash)**.

Nesse caso, você precisa inserir o pendrive na impressora, reiniciar a impressora e chamar a macro `ZFLASH`.

- A macro procurará a versão mais recente e atualizada
- Faz o download da versão mais recente para o modelo de sua impressora
- Verifica as somas de verificação
- Reinicializa a impressora
- A nova versão será instalada automaticamente após a reinicialização (não há necessidade de remover o pendrive, você pode deixá-lo na impressora para futuras atualizações).
- Em seguida, vá para a guia `Settings` -> `Software Update`. Clique em `Check for updates` e instale as atualizações mais recentes do `ZMOD`.

<img width="1239" height="535" alt="image" src="https://github.com/user-attachments/assets/b42c4ce9-1c0a-45c0-a20c-36919a27d648" />

Se ele mostrar muitos erros, isso é normal.

Como os plug-ins não fazem parte do firmware, eles são baixados separadamente.

Você precisa pressionar `Check for updates`. E restaurar e atualizar os plug-ins um a um. A impressora será reinicializada.

<img width="671" height="223" alt="image" src="https://github.com/user-attachments/assets/5744dc8e-ba58-4359-b78a-652be846ca07" />

Você pode ver a versão atual do sistema operacional do mod na guia "System" -> "Distribution"

A versão atual do zMod (guia Settings (Configurações) -> Update (Atualização) -> "ffm5/zmod"), **deve corresponder** aos dois primeiros dígitos da versão da guia System (Sistema).

<u>Se não corresponder, o mod **não funcionará corretamente** e, nesse caso, não reclame do ZMOD</u>.

Atualização via pendrive USB:

1. Formate o pendrive USB para FAT/FAT16/FAT32
2. Coloque [file](https://github.com/ghzserg/zmod/releases/) na pasta raiz do USB Flash.

    - Para o FF5M: Adventurer5M-**zmod**-\*.tgz
       - Para o FF5MPro: Adventurer5MPro-**zmod**-\*.tgz
       - para [AD5X](/pt/AD5X/): AD5X-**zmod**-\*.tgz

3. Desligue a impressora
4. Insira o pendrive USB na impressora
5. Ligue a impressora
6. Aguarde a reinicialização da impressora (não remova o dispositivo USB)
7. Aguarde até que o mod seja instalado
8. Quando a impressora escrever que a instalação foi concluída
9. Retire o pendrive USB
10. Desligue a impressora
11. Ligue a impressora
12. Vá para a guia `Settings` -> `Software Update` no Fluidd/Mainsail. Clique em `Check for updates` e instale as atualizações mais recentes do `ZMOD`.

---

## Ajuda ao desenvolvimento

[SBP, cartão bancário, T-pay](https://pay.cloudtips.ru/p/3cbf9e9f)

<img width="262" height="262" alt="qrCode" src="https://github.com/user-attachments/assets/e7c1ebf3-3a54-4b46-b071-06656ac06ae1" />

BTC `17wXTd9BqYp1K3zCLTxVyGLEXUDjf7XNLL`.

---

## Deleting - desativar temporariamente o mod

- [SKIP_ZMOD](/pt/Zmod/#skip_zmod) - macro para reiniciar sem iniciar o moonraker e o fluidd
- [REMOVE_ZMOD](/pt/Zmod/#remove_zmod) - macro para remover mods

Recomenda-se **remover o mod por meio da macro `REMOVE_ZMOD`**; a remoção via pen drive deve ser usada somente se não houver possibilidade de executar a macro.

Atenção!

- Se estiver usando o Klipper 13, é necessário executar o ```UPDATE_MCU```. Isso evitará a situação quando o MCU e o Klipper forem de versões diferentes.
- Se você tiver plug-ins ativados, primeiro deverá desativá-los ````DISABLE_PLUGIN name=g28_tenz````.

Remova o mod completamente ```REMOVE_ZMOD FULL=1```.

Desinstalação do mod via pen drive:

- Formate a unidade flash para FAT/FAT16/FAT32
- Coloque o arquivo [flashforge_init.sh](https://github.com/ghzserg/zmod/blob/main/Native_firmware/rem_zmod/flashforge_init.sh) nessa unidade flash
- Desligue a impressora
- Insira a unidade USB na impressora
- Ligue a impressora
- A impressora será reinicializada 3 vezes
- Remova a unidade flash e use o firmware padrão

---

## Como faço para atualizar o firmware padrão?

1. desative todos os plug-ins ativos, exceto recommend, timelamse e notify (```DISABLE_PLUGIN name=plugin_name```).
2. Se estiver usando o **Klipper 13**, execute o ```UPDATE_MCU``` antes de atualizar o firmware nativo. Isso evitará situações em que a MCU e o Klipper tenham versões diferentes.
3. Ative as nuvens chinesas se quiser atualizar a partir da tela nativa ```SAVE_ZMOD_DATA CHINA_CLOUD=1```.

Se a tela nativa não encontrar a atualização:

- Seu número de série ainda não foi atingido pela distribuição da atualização
- Instale a atualização do firmware nativo a partir de um pendrive](/en/Native_FW/)

**Para o [AD5X](/pt/AD5X/), é necessário [Ativar o zMod](/pt/Native_FW/) por meio do `AD5X-ENABLE-zmod.tgz` de uma unidade flash, após a atualização de estoque**.

---

## Restaurar inicialização

Autores das instruções: [@darksimpson](https://t.me/darksimpson), [Alexander](https://github.com/DrA1ex), [@Ikaros413](https://t.me/Ikaros413), [@SoloMen88](https://t.me/SoloMen88)

Para quem tem uma impressora que fica pendurada no protetor de tela quando ligada e não pode ser acessada via cabo LAN.

![](../images/ff.jpg)

Tente restaurar o firmware, por meio de uma instalação completa do firmware:

- [FF5M](/pt/Native_FW/#installing-full-firmware-on-ff5m)
- [AD5X](/pt/Native_FW/#install-full-flash-on-ad5x)

Algoritmo de recuperação:

1. **Desligue a impressora**
2. Prepare o conversor UART/USB (precisa de um jumper de 3,3V ou 5V/3,3V)

![](../images/ch340.jpg)

**ADVERTÊNCIA!** o conversor deve ser de 3,3 volts; se fornecer 5 volts, o processador queimará!

3. Abra a parte traseira do FlashForge.
4. Conecte-se ao pino UART na placa (conecte RX, TX, GND, **3,3 V não conecte**).

![](../images/connect.jpg)

DEVE TRANSFERIR o jumper (se tiver um) de 5V para 3,3V Se você conectar a 5V, terá de substituir a placa-mãe.
Qual deve ser a aparência da conexão no final:

- RX/TX são conectados transversalmente RX-TX TX-RX
- GND do conversor ao GND da placa
- 3,3V não está conectado em lugar algum

![](../images/connect_photo.jpg)

5. Uma nova porta COM deve aparecer no sistema.

![](../images/port.jpg)

6. Execute o programa [PuTTY](https://www.chiark.greenend.org.uk/~sgtatham/putty/latest.html) e digite sua porta COM (no exemplo acima, COM6), velocidade `115200`, tipo de conexão - `Serial`.

7. Ligue a alimentação normal da impressora.

8. No terminal, aguarde a linha:
```
Pressione qualquer tecla para interromper o autoboot
```
e pressione rapidamente `Enter`.

9. Isso o levará ao `U-Boot`. Você pode fazer várias coisas a partir dele (escreva `help`)

Mas nós só precisamos substituir o comando start do kernel do Linux para obter o shell.

Escrevemos no U-boot via terminal:

```
setenv init /bin/sh
boot
```

10. Se tiver feito tudo corretamente, você obterá o `sh` após a inicialização do kernel do Linux.

11. O sistema de arquivos está montado em modo somente leitura, portanto, você precisará remontá-lo:

```
mount -t proc proc /proc
mount -o remount,rw /
```

12. conserte o que está quebrado, por exemplo, `rm -f /etc/init.d/S01bad_script` ou `rm -f /opt/config/mod/.shell/S98camera` se não estiver conseguindo iniciar por causa da câmera.

13. Você precisa salvar as alterações: ```sync```.

14. E reiniciar: ```reboot```.

