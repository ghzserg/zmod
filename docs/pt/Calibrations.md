<h1 align="centre">Calibrações</h1>

Uma macro é um pequeno programa na linguagem Klipper/Gcode.

Ela pode ser chamada por:

- Do arquivo GCODE
- No console do Fluidd/Mainsail (pressione a letra inglesa `C` no fluidd)

!!! Nota
    *O valor entre colchetes é o valor padrão.

---

!!! dica
    [Beginner Printer Calibration](/pt/SetupCalibrations/#printer-calibration-for-beginners)

---

### BED_LEVEL_SCREWS_TUNE

Calibrar os parafusos da mesa ([manual](https://www.klipper3d.org/Manual_Level.html#adjusting-bed-leveling-screws-using-the-bed-probe))

- EXTRUDER_TEMP - temperatura da extrusora (240)
- BED_TEMP - temperatura da mesa (80)

Mede a distância entre o bocal e os parafusos e orienta sobre o torque dos parafusos. Em seguida, ele salva as temperaturas para não ter de reaquecer, aguarda o usuário ajustar os parafusos e pressiona o botão de calibração novamente. Se a calibração for concluída, o próprio usuário deverá redefinir a temperatura.

---

### LOAD_CELL_TARE

Redefine o peso das células de carga. Chamado durante a calibração da tabela

---

### PID_TUNE_BED

Calibração da tabela PID

- TEMPERATURE - temperatura da mesa (80)

Após a calibração, chama `SAVE_CONFIG`, consulte também [NEW_SAVE_CONFIG](/pt/Main/#new_save_config)

Se você não quiser usar o salvamento automático, use:
```
PID_CALIBRATE HEATER=heater_bed TARGET={temperature}
```

---

### PID_TUNE_EXTRUDER

Calibração do PID da extrusora

- TEMPERATURE - temperatura da extrusora (245)
- COOLER - velocidade do ventilador 0-100 (100)

Calibre o PID para a temperatura na qual você está imprimindo e com o nível do ventilador que está usando.

Após a calibração, chame `SAVE_CONFIG`, consulte também [NEW_SAVE_CONFIG](/pt/Main/#new_save_config)

Se você não quiser usar o salvamento automático, use:
```
PID_CALIBRATE HEATER=extrusor TARGET={temperatura}
```

---

### ZSHAPER

Calibração do shaper.

As imagens do shaper estão localizadas na guia "Configuration" -> mod_data

- calibration_data_x.png
- calibração_dados_y.png

Os arquivos Csv também estão localizados lá.

Leia sobre [fix_scv](/pt/Global/#fix_scv)

[Graphing software](https://github.com/theycallmek/Klipper-Input-Shaping-Assistant/releases)

---

### CALIBRAÇÃO DO MODELADOR DE CORREIAS

Executar um teste especial de meio eixo para analisar e comparar os perfis de frequência de correias individuais em impressoras CoreXY

SPECTROGRAM - 0 - não criar espectrograma, 1 - criar espectrograma (1)

Requer 256 megabytes de RAM e SWAP ativado

---

### KAMP

Calibração adaptável da mesa com limpeza do bico

- EXTRUDER_TEMP - temperatura da extrusora (240)
- BED_TEMP - temperatura da mesa (80)

Adicione a primeira linha no Orca
```
KAMP EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single]
```

Mas é melhor usar [START_PRINT](/pt/Main/#start_print) e [SAVE_ZMOD_DATA](/pt/Global/#start_print) PRINT_LEVELING=1 USE_KAMP=1

Também é recomendável colocar `SAVE_ZMOD_DATA CLEAR=LINE_PURGE`, o que permitirá que você use o espaço de limpeza onde o mapa da tabela é removido.

[Quais são as opções para remover o cartão de tabela?](/pt/FAQ/#what-are-the-options-for-removing-the-table-card)

---

### AUTO_FULL_BED_LEVEL

Calibração da mesa com limpeza do bico

- EXTRUDER_TEMP - temperatura da extrusora (230)
- BED_TEMP - temperatura da mesa (80)
- PROFILE - para qual perfil (automático)

Adicione a primeira linha no Orca
```
AUTO_FULL_BED_LEVEL EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single]
M190 S[bed_temperature_initial_layer_single]
M104 S[nozzle_temperature_initial_layer]
```

Mas é melhor usar [START_PRINT](/pt/Main/#start_print) e [SAVE_ZMOD_DATA](/pt/Goabal/#start_print) PRINT_LEVELING=1

[Quais são as opções para remover um cartão de mesa?](/pt/FAQ/#what-are-the-options-for-removing-a-table-card)

---

### LOAD_ZOFFSET_NATIVE

Transferir configurações de z-offset da tela nativa para o modo sem tela

[Como o Z-Offset funciona em sua impressora](/pt/SetupCalibrations/#how-z-offset-works-on-your-printer)
